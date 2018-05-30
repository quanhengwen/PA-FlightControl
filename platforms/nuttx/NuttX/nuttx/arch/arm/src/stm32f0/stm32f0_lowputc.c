/****************************************************************************
 * arch/arm/src/stm32f0/stm32f0_lowputc.c
 *
 *   Copyright (C) 2009, 2012 Gregory Nutt. All rights reserved.
 *   Author: Gregory Nutt <gnutt@nuttx.org>
 *           Alan Carvalho de Assis <acassis@gmail.com>
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
 * 3. Neither the name NuttX nor the names of its contributors may be
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

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <nuttx/config.h>

#include <stdint.h>

#include <arch/board/board.h>

#include "up_internal.h"
#include "up_arch.h"

#include "chip.h"

#include "stm32f0_rcc.h"
#include "stm32f0_gpio.h"
#include "stm32f0_uart.h"

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

/* Select USART parameters for the selected console */

#ifdef HAVE_CONSOLE
#  if defined(CONFIG_USART1_SERIAL_CONSOLE)
#    define STM32F0_CONSOLE_BASE     STM32F0_USART1_BASE
#    define STM32F0_APBCLOCK         STM32F0_PCLK2_FREQUENCY
#    define STM32F0_CONSOLE_BAUD     CONFIG_USART1_BAUD
#    define STM32F0_CONSOLE_BITS     CONFIG_USART1_BITS
#    define STM32F0_CONSOLE_PARITY   CONFIG_USART1_PARITY
#    define STM32F0_CONSOLE_2STOP    CONFIG_USART1_2STOP
#    ifdef CONFIG_USART1_RS485
#      define STM32F0_CONSOLE_RS485_DIR GPIO_USART1_RS485_DIR
#      if (CONFIG_USART1_RS485_DIR_POLARITY == 0)
#        define STM32F0_CONSOLE_RS485_DIR_POLARITY false
#      else
#        define STM32F0_CONSOLE_RS485_DIR_POLARITY true
#      endif
#    endif
#  elif defined(CONFIG_USART2_SERIAL_CONSOLE)
#    define STM32F0_CONSOLE_BASE     STM32F0_USART2_BASE
#    define STM32F0_APBCLOCK         STM32F0_PCLK1_FREQUENCY
#    define STM32F0_CONSOLE_BAUD     CONFIG_USART2_BAUD
#    define STM32F0_CONSOLE_BITS     CONFIG_USART2_BITS
#    define STM32F0_CONSOLE_PARITY   CONFIG_USART2_PARITY
#    define STM32F0_CONSOLE_2STOP    CONFIG_USART2_2STOP
#    ifdef CONFIG_USART2_RS485
#      define STM32F0_CONSOLE_RS485_DIR GPIO_USART2_RS485_DIR
#      if (CONFIG_USART2_RS485_DIR_POLARITY == 0)
#        define STM32F0_CONSOLE_RS485_DIR_POLARITY false
#      else
#        define STM32F0_CONSOLE_RS485_DIR_POLARITY true
#      endif
#    endif
#  elif defined(CONFIG_USART3_SERIAL_CONSOLE)
#    define STM32F0_CONSOLE_BASE     STM32F0_USART3_BASE
#    define STM32F0_APBCLOCK         STM32F0_PCLK1_FREQUENCY
#    define STM32F0_CONSOLE_BAUD     CONFIG_USART3_BAUD
#    define STM32F0_CONSOLE_BITS     CONFIG_USART3_BITS
#    define STM32F0_CONSOLE_PARITY   CONFIG_USART3_PARITY
#    define STM32F0_CONSOLE_2STOP    CONFIG_USART3_2STOP
#    ifdef CONFIG_USART3_RS485
#      define STM32F0_CONSOLE_RS485_DIR GPIO_USART3_RS485_DIR
#      if (CONFIG_USART3_RS485_DIR_POLARITY == 0)
#        define STM32F0_CONSOLE_RS485_DIR_POLARITY false
#      else
#        define STM32F0_CONSOLE_RS485_DIR_POLARITY true
#      endif
#    endif
#  elif defined(CONFIG_USART4_SERIAL_CONSOLE)
#    define STM32F0_CONSOLE_BASE     STM32F0_USART4_BASE
#    define STM32F0_APBCLOCK         STM32F0_PCLK1_FREQUENCY
#    define STM32F0_CONSOLE_BAUD     CONFIG_USART4_BAUD
#    define STM32F0_CONSOLE_BITS     CONFIG_USART4_BITS
#    define STM32F0_CONSOLE_PARITY   CONFIG_USART4_PARITY
#    define STM32F0_CONSOLE_2STOP    CONFIG_USART4_2STOP
#    ifdef CONFIG_USART4_RS485
#      define STM32F0_CONSOLE_RS485_DIR GPIO_USART4_RS485_DIR
#      if (CONFIG_USART4_RS485_DIR_POLARITY == 0)
#        define STM32F0_CONSOLE_RS485_DIR_POLARITY false
#      else
#        define STM32F0_CONSOLE_RS485_DIR_POLARITY true
#      endif
#    endif
#  elif defined(CONFIG_USART5_SERIAL_CONSOLE)
#    define STM32F0_CONSOLE_BASE     STM32F0_USART5_BASE
#    define STM32F0_APBCLOCK         STM32F0_PCLK1_FREQUENCY
#    define STM32F0_CONSOLE_BAUD     CONFIG_USART5_BAUD
#    define STM32F0_CONSOLE_BITS     CONFIG_USART5_BITS
#    define STM32F0_CONSOLE_PARITY   CONFIG_USART5_PARITY
#    define STM32F0_CONSOLE_2STOP    CONFIG_USART5_2STOP
#    ifdef CONFIG_USART5_RS485
#      define STM32F0_CONSOLE_RS485_DIR GPIO_USART5_RS485_DIR
#      if (CONFIG_USART5_RS485_DIR_POLARITY == 0)
#        define STM32F0_CONSOLE_RS485_DIR_POLARITY false
#      else
#        define STM32F0_CONSOLE_RS485_DIR_POLARITY true
#      endif
#    endif
#  endif

  /* CR1 settings */

#  if STM32F0_CONSOLE_BITS == 9
#    define USART_CR1_M0_VALUE USART_CR1_M0
#    define USART_CR1_M1_VALUE 0
#  elif STM32F0_CONSOLE_BITS == 7
#    define USART_CR1_M0_VALUE 0
#    define USART_CR1_M1_VALUE USART_CR1_M1
#  else /* 8 bits */
#    define USART_CR1_M0_VALUE 0
#    define USART_CR1_M1_VALUE 0
#  endif

#  if STM32F0_CONSOLE_PARITY == 1 /* odd parity */
#    define USART_CR1_PARITY_VALUE (USART_CR1_PCE|USART_CR1_PS)
#  elif STM32F0_CONSOLE_PARITY == 2 /* even parity */
#    define USART_CR1_PARITY_VALUE USART_CR1_PCE
#  else /* no parity */
#    define USART_CR1_PARITY_VALUE 0
#  endif

#  define USART_CR1_CLRBITS \
    (USART_CR1_UESM | USART_CR1_RE | USART_CR1_TE | USART_CR1_PS | \
     USART_CR1_PCE | USART_CR1_WAKE | USART_CR1_M0 | USART_CR1_M1 | \
     USART_CR1_MME | USART_CR1_OVER8 | USART_CR1_DEDT_MASK | \
     USART_CR1_DEAT_MASK | USART_CR1_ALLINTS)

#  define USART_CR1_SETBITS (USART_CR1_M0_VALUE|USART_CR1_M1_VALUE|USART_CR1_PARITY_VALUE)

  /* CR2 settings */

#  if STM32F0_CONSOLE_2STOP != 0
#    define USART_CR2_STOP2_VALUE USART_CR2_STOP2
#  else
#    define USART_CR2_STOP2_VALUE 0
#  endif

#  define USART_CR2_CLRBITS \
    (USART_CR2_ADDM7 | USART_CR2_LBDL | USART_CR2_LBDIE | USART_CR2_LBCL | \
     USART_CR2_CPHA | USART_CR2_CPOL | USART_CR2_CLKEN | USART_CR2_STOP_MASK | \
     USART_CR2_LINEN | USART_CR2_SWAP | USART_CR2_RXINV | USART_CR2_TXINV | \
     USART_CR2_DATAINV | USART_CR2_MSBFIRST | USART_CR2_ABREN | \
     USART_CR2_ABRMOD_MASK | USART_CR2_RTOEN | USART_CR2_ADD_MASK)

#  define USART_CR2_SETBITS USART_CR2_STOP2_VALUE

  /* CR3 settings */

#  define USART_CR3_CLRBITS \
    (USART_CR3_EIE | USART_CR3_IREN | USART_CR3_IRLP | USART_CR3_HDSEL | \
     USART_CR3_NACK | USART_CR3_SCEN | USART_CR3_DMAR | USART_CR3_DMAT | \
     USART_CR3_RTSE | USART_CR3_CTSE | USART_CR3_CTSIE | USART_CR3_ONEBIT | \
     USART_CR3_OVRDIS | USART_CR3_DDRE | USART_CR3_DEM | USART_CR3_DEP | \
     USART_CR3_SCARCNT2_MASK | USART_CR3_WUS_MASK | USART_CR3_WUFIE)

#  define USART_CR3_SETBITS 0

#  undef USE_OVER8

  /* Calculate USART BAUD rate divider */

  /* Baud rate for standard USART (SPI mode included):
   *
   * In case of oversampling by 16, the equation is:
   *   baud    = fCK / UARTDIV
   *   UARTDIV = fCK / baud
   *
   * In case of oversampling by 8, the equation is:
   *
   *   baud    = 2 * fCK / UARTDIV
   *   UARTDIV = 2 * fCK / baud
   */

#  define STM32F0_USARTDIV8 \
      (((STM32F0_APBCLOCK << 1) + (STM32F0_CONSOLE_BAUD >> 1)) / STM32F0_CONSOLE_BAUD)
#  define STM32F0_USARTDIV16 \
      ((STM32F0_APBCLOCK + (STM32F0_CONSOLE_BAUD >> 1)) / STM32F0_CONSOLE_BAUD)

   /* Use oversamply by 8 only if the divisor is small.  But what is small? */

#  if STM32F0_USARTDIV8 > 100
#    define STM32F0_BRR_VALUE STM32F0_USARTDIV16
#  else
#    define USE_OVER8 1
#    define STM32F0_BRR_VALUE \
      ((STM32F0_USARTDIV8 & 0xfff0) | ((STM32F0_USARTDIV8 & 0x000f) >> 1))
#  endif

#endif /* HAVE_CONSOLE */

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * Name: up_lowputc
 *
 * Description:
 *   Output one byte on the serial console
 *
 ****************************************************************************/

void up_lowputc(char ch)
{
#ifdef HAVE_CONSOLE
  /* Wait until the TX data register is empty */

  while ((getreg32(STM32F0_CONSOLE_BASE + STM32F0_USART_ISR_OFFSET) & USART_ISR_TXE) == 0);
#ifdef STM32F0_CONSOLE_RS485_DIR
  stm32f0_gpiowrite(STM32F0_CONSOLE_RS485_DIR, STM32F0_CONSOLE_RS485_DIR_POLARITY);
#endif

  /* Then send the character */

  putreg32((uint32_t)ch, STM32F0_CONSOLE_BASE + STM32F0_USART_TDR_OFFSET);

#ifdef STM32F0_CONSOLE_RS485_DIR
  while ((getreg32(STM32F0_CONSOLE_BASE + STM32F0_USART_ISR_OFFSET) & USART_ISR_TC) == 0);
  stm32f0_gpiowrite(STM32F0_CONSOLE_RS485_DIR, !STM32F0_CONSOLE_RS485_DIR_POLARITY);
#endif

#endif /* HAVE_CONSOLE */
}

/****************************************************************************
 * Name: stm32f0_lowsetup
 *
 * Description:
 *   This performs basic initialization of the USART used for the serial
 *   console.  Its purpose is to get the console output availabe as soon
 *   as possible.
 *
 ****************************************************************************/

void stm32f0_lowsetup(void)
{
#if defined(HAVE_USART)
#if defined(HAVE_CONSOLE) && !defined(CONFIG_SUPPRESS_UART_CONFIG)
  uint32_t cr;
#endif

  /* Setup clocking and GPIO pins for all configured USARTs */

#ifdef CONFIG_STM32F0_USART1
  /* Enable USART APB2 clock */

  modifyreg32(STM32F0_RCC_APB2ENR, 0, RCC_APB2ENR_USART1EN);

  /* Configure RX/TX pins */

  stm32f0_configgpio(GPIO_USART1_TX);
  stm32f0_configgpio(GPIO_USART1_RX);

#ifdef CONFIG_USART1_RS485
  stm32f0_configgpio(GPIO_USART1_RS485_DIR);
  stm32f0_gpiowrite(GPIO_USART1_RS485_DIR, !CONFIG_USART1_RS485_DIR_POLARITY);
#endif
#endif

#ifdef CONFIG_STM32F0_USART2
  /* Enable USART APB1 clock */

  modifyreg32(STM32F0_RCC_APB1ENR, 0, RCC_APB1ENR_USART2EN);

  /* Configure RX/TX pins */

  stm32f0_configgpio(GPIO_USART2_TX);
  stm32f0_configgpio(GPIO_USART2_RX);

#ifdef CONFIG_USART2_RS485
  stm32f0_configgpio(GPIO_USART2_RS485_DIR);
  stm32f0_gpiowrite(GPIO_USART2_RS485_DIR, !CONFIG_USART2_RS485_DIR_POLARITY);
#endif
#endif

#ifdef CONFIG_STM32F0_USART3
  /* Enable USART APB1 clock */

  modifyreg32(STM32F0_RCC_APB1ENR, 0, RCC_APB1ENR_USART3EN);

  /* Configure RX/TX pins */

  stm32f0_configgpio(GPIO_USART3_TX);
  stm32f0_configgpio(GPIO_USART3_RX);

#ifdef CONFIG_USART3_RS485
  stm32f0_configgpio(GPIO_USART3_RS485_DIR);
  stm32f0_gpiowrite(GPIO_USART3_RS485_DIR, !CONFIG_USART3_RS485_DIR_POLARITY);
#endif
#endif

#ifdef CONFIG_STM32F0_USART4
  /* Enable USART APB1 clock */

  modifyreg32(STM32F0_RCC_APB1ENR, 0, RCC_APB1ENR_USART4EN);

  /* Configure RX/TX pins */

  stm32f0_configgpio(GPIO_USART4_TX);
  stm32f0_configgpio(GPIO_USART4_RX);

#ifdef CONFIG_USART4_RS485
  stm32f0_configgpio(GPIO_USART4_RS485_DIR);
  stm32f0_gpiowrite(GPIO_USART4_RS485_DIR, !CONFIG_USART4_RS485_DIR_POLARITY);
#endif
#endif

#ifdef CONFIG_STM32F0_USART5
  /* Enable USART APB1 clock */

  modifyreg32(STM32F0_RCC_APB1ENR, 0, RCC_APB1ENR_USART5EN);

  /* Configure RX/TX pins */

  stm32f0_configgpio(GPIO_USART5_TX);
  stm32f0_configgpio(GPIO_USART5_RX);

#ifdef CONFIG_USART5_RS485
  stm32f0_configgpio(GPIO_USART5_RS485_DIR);
  stm32f0_gpiowrite(GPIO_USART5_RS485_DIR, !CONFIG_USART5_RS485_DIR_POLARITY);
#endif
#endif

  /* Enable and configure the selected console device */

#if defined(HAVE_CONSOLE) && !defined(CONFIG_SUPPRESS_UART_CONFIG)
  /* Configure CR2 */

  cr  = getreg32(STM32F0_CONSOLE_BASE + STM32F0_USART_CR2_OFFSET);
  cr &= ~USART_CR2_CLRBITS;
  cr |= USART_CR2_SETBITS;
  putreg32(cr, STM32F0_CONSOLE_BASE + STM32F0_USART_CR2_OFFSET);

  /* Configure CR1 */

  cr  = getreg32(STM32F0_CONSOLE_BASE + STM32F0_USART_CR1_OFFSET);
  cr &= ~USART_CR1_CLRBITS;
  cr |= USART_CR1_SETBITS;
  putreg32(cr, STM32F0_CONSOLE_BASE + STM32F0_USART_CR1_OFFSET);

  /* Configure CR3 */

  cr  = getreg32(STM32F0_CONSOLE_BASE + STM32F0_USART_CR3_OFFSET);
  cr &= ~USART_CR3_CLRBITS;
  cr |= USART_CR3_SETBITS;
  putreg32(cr, STM32F0_CONSOLE_BASE + STM32F0_USART_CR3_OFFSET);

  /* Configure the USART Baud Rate */

  putreg32(STM32F0_BRR_VALUE, STM32F0_CONSOLE_BASE + STM32F0_USART_BRR_OFFSET);

  /* Select oversampling by 8 */

  cr  = getreg32(STM32F0_CONSOLE_BASE + STM32F0_USART_CR1_OFFSET);
#ifdef USE_OVER8
  cr |= USART_CR1_OVER8;
  putreg32(cr, STM32F0_CONSOLE_BASE + STM32F0_USART_CR1_OFFSET);
#endif

  /* Enable Rx, Tx, and the USART */

  cr |= (USART_CR1_UE | USART_CR1_TE | USART_CR1_RE);
  putreg32(cr, STM32F0_CONSOLE_BASE + STM32F0_USART_CR1_OFFSET);

#endif /* HAVE_CONSOLE && !CONFIG_SUPPRESS_UART_CONFIG */
#endif /* HAVE_USART */
}
