/****************************************************************************
 *
 *   Copyright (c) 2012, 2013 PX4 Development Team. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 * 3. Neither the name PX4 nor the names of its contributors may be
 *    used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 ****************************************************************************/

/**
 * @file bl_update.c
 *
 * STM32F4 bootloader update tool.
 */

#include <px4_config.h>
#include <px4_log.h>
#include <px4_module.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

#include <arch/board/board.h>

#include "systemlib/systemlib.h"
#include <nuttx/progmem.h>

#define BL_FILE_SIZE_LIMIT	16384

__EXPORT int bl_update_main(int argc, char *argv[]);

#if defined (CONFIG_STM32_STM32F4XXX)
static int setopt(void);

static void print_usage(const char *reason)
{	
	if (reason)
	{	
		PX4_ERR("%s", reason);
	}

	PRINT_MODULE_DESCRIPTION("Utility to flash the bootloader from a file");

	PRINT_MODULE_USAGE_NAME_SIMPLE("bl_update", "command");
	PRINT_MODULE_USAGE_COMMAND_DESCR("setopt", "Set option bits to unlock the FLASH (only needed if in locked state)");

	PRINT_MODULE_USAGE_COMMAND_DESCR("<file>", "Bootloader bin file");
}

#endif

int bl_update_main(int argc, char *argv[])
{
#if !defined (CONFIG_STM32_STM32F4XXX)
	PX4_ERR("Not supported on this HW");
	return 1;
}
#else

if (argc != 2)
{	
	print_usage("missing firmware filename or command");
	return 1;
}

if (!strcmp(argv[1], "setopt"))
{	
	return setopt();
}

int fd = open(argv[1], O_RDONLY);

if (fd < 0)
{	
	PX4_ERR("open %s failed", argv[1]);
	return 1;
}

struct stat s;

if (stat(argv[1], &s) != 0)
{	
	PX4_ERR("stat %s failed", argv[1]);
	close(fd);
	return 1;
}

/* sanity-check file size */
if (s.st_size > BL_FILE_SIZE_LIMIT)
{	
	PX4_ERR("%s: file too large (limit: %u, actual: %d)", argv[1], BL_FILE_SIZE_LIMIT, s.st_size);
	close(fd);
	return 1;
}

uint8_t *buf = malloc(s.st_size);

if (buf == NULL)
{	
	PX4_ERR("failed to allocate %u bytes for firmware buffer", s.st_size);
	close(fd);
	return 1;
}

if (read(fd, buf, s.st_size) != s.st_size)
{	
	PX4_ERR("firmware read error");
	close(fd);
	free(buf);
	return 1;
}

close(fd);

uint32_t *hdr = (uint32_t *)buf;

if ((hdr[0] < 0x20000000) || /* stack not below RAM */
		(hdr[0] > (0x20000000 + (128 * 1024))) || /* stack not above RAM */
		(hdr[1] < PX4_FLASH_BASE) || /* entrypoint not below flash */
		((hdr[1] - PX4_FLASH_BASE) > BL_FILE_SIZE_LIMIT)) /* entrypoint not outside bootloader */
{	
	free(buf);
	PX4_ERR("not a bootloader image");
	return 1;
}

PX4_INFO("image validated, erasing bootloader...");
usleep(10000);

/* prevent other tasks from running while we do this */
sched_lock();

const size_t page = 0;
uint8_t *base = (uint8_t *) PX4_FLASH_BASE;

ssize_t size = up_progmem_erasepage(page);

if (size != BL_FILE_SIZE_LIMIT)
{	
	PX4_ERR("erase error at 0x%08x", &base[size]);
}

PX4_INFO("flashing...");

/* now program the bootloader - speed is not critical so use x8 mode */

size = up_progmem_write((size_t) base, buf, s.st_size);

if (size != s.st_size)
{	
	PX4_ERR("program error at 0x%0x8", &base[size]);
	goto flash_end;
}

/* re-lock the flash control register */

stm32_flash_lock();

PX4_INFO("verifying...");

/* now run a verify pass */
for (int i = 0; i < s.st_size; i++)
{	
	if (base[i] != buf[i])
	{	
		PX4_WARN("verify failed at %u - retry update, DO NOT reboot", i);
		goto flash_end;
	}
}

PX4_INFO("bootloader update complete");

flash_end:
/* unlock the scheduler */
sched_unlock();

free(buf);
exit(0);
}

static int
setopt(void)
{
volatile uint32_t *optcr = (volatile uint32_t *)0x40023c14;

const uint16_t opt_mask = (3 << 2); /* BOR_LEV bitmask */
const uint16_t opt_bits = (0 << 2); /* BOR = 0, setting for 2.7-3.6V operation */

if ((*optcr & opt_mask) == opt_bits)
{	
	PX4_INFO("option bits are already set as required");
	return 0;
}

/* unlock the control register */
volatile uint32_t *optkeyr = (volatile uint32_t *)0x40023c08;
*optkeyr = 0x08192a3bU;
*optkeyr = 0x4c5d6e7fU;

if (*optcr & 1)
{	
	PX4_ERR("option control register unlock failed");
	return 1;
}

/* program the new option value */
*optcr = (*optcr & ~opt_mask) | opt_bits | (1 << 1);

usleep(1000);

if ((*optcr & opt_mask) == opt_bits)
{	
	PX4_INFO("option bits set");
	return 0;
}

PX4_ERR("option bits setting failed; readback 0x%04x", *optcr);
return 1;
}
#endif // CONFIG_STM32_STM32F4XXX
