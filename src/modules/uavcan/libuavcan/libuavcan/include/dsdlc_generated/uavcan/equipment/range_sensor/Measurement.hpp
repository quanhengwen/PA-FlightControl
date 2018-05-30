/*
 * UAVCAN data structure definition for libuavcan.
 *
 * Autogenerated, do not edit.
 *
 * Source file: /data/work/workspace/pa/096.PA-FlightControl/src/modules/uavcan/libuavcan/dsdl/uavcan/equipment/range_sensor/1050.Measurement.uavcan
 */

#ifndef UAVCAN_EQUIPMENT_RANGE_SENSOR_MEASUREMENT_HPP_INCLUDED
#define UAVCAN_EQUIPMENT_RANGE_SENSOR_MEASUREMENT_HPP_INCLUDED

#include <uavcan/build_config.hpp>
#include <uavcan/node/global_data_type_registry.hpp>
#include <uavcan/marshal/types.hpp>

#include <uavcan/CoarseOrientation.hpp>
#include <uavcan/Timestamp.hpp>

/******************************* Source text **********************************
#
# Generic narrow-beam range sensor data.
#

uavcan.Timestamp timestamp

uint8 sensor_id

uavcan.CoarseOrientation beam_orientation_in_body_frame

float16 field_of_view                # Radians

uint5 SENSOR_TYPE_UNDEFINED = 0
uint5 SENSOR_TYPE_SONAR     = 1
uint5 SENSOR_TYPE_LIDAR     = 2
uint5 SENSOR_TYPE_RADAR     = 3
uint5 sensor_type

uint3 READING_TYPE_UNDEFINED   = 0   # Range is unknown
uint3 READING_TYPE_VALID_RANGE = 1   # Range field contains valid distance
uint3 READING_TYPE_TOO_CLOSE   = 2   # Range field contains min range for the sensor
uint3 READING_TYPE_TOO_FAR     = 3   # Range field contains max range for the sensor
uint3 reading_type

float16 range                        # Meters
******************************************************************************/

/********************* DSDL signature source definition ***********************
uavcan.equipment.range_sensor.Measurement
uavcan.Timestamp timestamp
saturated uint8 sensor_id
uavcan.CoarseOrientation beam_orientation_in_body_frame
saturated float16 field_of_view
saturated uint5 sensor_type
saturated uint3 reading_type
saturated float16 range
******************************************************************************/

#undef timestamp
#undef sensor_id
#undef beam_orientation_in_body_frame
#undef field_of_view
#undef sensor_type
#undef reading_type
#undef range
#undef SENSOR_TYPE_UNDEFINED
#undef SENSOR_TYPE_SONAR
#undef SENSOR_TYPE_LIDAR
#undef SENSOR_TYPE_RADAR
#undef READING_TYPE_UNDEFINED
#undef READING_TYPE_VALID_RANGE
#undef READING_TYPE_TOO_CLOSE
#undef READING_TYPE_TOO_FAR

namespace uavcan
{
namespace equipment
{
namespace range_sensor
{

template <int _tmpl>
struct UAVCAN_EXPORT Measurement_
{
    typedef const Measurement_<_tmpl>& ParameterType;
    typedef Measurement_<_tmpl>& ReferenceType;

    struct ConstantTypes
    {
        typedef ::uavcan::IntegerSpec< 5, ::uavcan::SignednessUnsigned, ::uavcan::CastModeSaturate > SENSOR_TYPE_UNDEFINED;
        typedef ::uavcan::IntegerSpec< 5, ::uavcan::SignednessUnsigned, ::uavcan::CastModeSaturate > SENSOR_TYPE_SONAR;
        typedef ::uavcan::IntegerSpec< 5, ::uavcan::SignednessUnsigned, ::uavcan::CastModeSaturate > SENSOR_TYPE_LIDAR;
        typedef ::uavcan::IntegerSpec< 5, ::uavcan::SignednessUnsigned, ::uavcan::CastModeSaturate > SENSOR_TYPE_RADAR;
        typedef ::uavcan::IntegerSpec< 3, ::uavcan::SignednessUnsigned, ::uavcan::CastModeSaturate > READING_TYPE_UNDEFINED;
        typedef ::uavcan::IntegerSpec< 3, ::uavcan::SignednessUnsigned, ::uavcan::CastModeSaturate > READING_TYPE_VALID_RANGE;
        typedef ::uavcan::IntegerSpec< 3, ::uavcan::SignednessUnsigned, ::uavcan::CastModeSaturate > READING_TYPE_TOO_CLOSE;
        typedef ::uavcan::IntegerSpec< 3, ::uavcan::SignednessUnsigned, ::uavcan::CastModeSaturate > READING_TYPE_TOO_FAR;
    };

    struct FieldTypes
    {
        typedef ::uavcan::Timestamp timestamp;
        typedef ::uavcan::IntegerSpec< 8, ::uavcan::SignednessUnsigned, ::uavcan::CastModeSaturate > sensor_id;
        typedef ::uavcan::CoarseOrientation beam_orientation_in_body_frame;
        typedef ::uavcan::FloatSpec< 16, ::uavcan::CastModeSaturate > field_of_view;
        typedef ::uavcan::IntegerSpec< 5, ::uavcan::SignednessUnsigned, ::uavcan::CastModeSaturate > sensor_type;
        typedef ::uavcan::IntegerSpec< 3, ::uavcan::SignednessUnsigned, ::uavcan::CastModeSaturate > reading_type;
        typedef ::uavcan::FloatSpec< 16, ::uavcan::CastModeSaturate > range;
    };

    enum
    {
        MinBitLen
            = FieldTypes::timestamp::MinBitLen
            + FieldTypes::sensor_id::MinBitLen
            + FieldTypes::beam_orientation_in_body_frame::MinBitLen
            + FieldTypes::field_of_view::MinBitLen
            + FieldTypes::sensor_type::MinBitLen
            + FieldTypes::reading_type::MinBitLen
            + FieldTypes::range::MinBitLen
    };

    enum
    {
        MaxBitLen
            = FieldTypes::timestamp::MaxBitLen
            + FieldTypes::sensor_id::MaxBitLen
            + FieldTypes::beam_orientation_in_body_frame::MaxBitLen
            + FieldTypes::field_of_view::MaxBitLen
            + FieldTypes::sensor_type::MaxBitLen
            + FieldTypes::reading_type::MaxBitLen
            + FieldTypes::range::MaxBitLen
    };

    // Constants
    static const typename ::uavcan::StorageType< typename ConstantTypes::SENSOR_TYPE_UNDEFINED >::Type SENSOR_TYPE_UNDEFINED; // 0
    static const typename ::uavcan::StorageType< typename ConstantTypes::SENSOR_TYPE_SONAR >::Type SENSOR_TYPE_SONAR; // 1
    static const typename ::uavcan::StorageType< typename ConstantTypes::SENSOR_TYPE_LIDAR >::Type SENSOR_TYPE_LIDAR; // 2
    static const typename ::uavcan::StorageType< typename ConstantTypes::SENSOR_TYPE_RADAR >::Type SENSOR_TYPE_RADAR; // 3
    static const typename ::uavcan::StorageType< typename ConstantTypes::READING_TYPE_UNDEFINED >::Type READING_TYPE_UNDEFINED; // 0
    static const typename ::uavcan::StorageType< typename ConstantTypes::READING_TYPE_VALID_RANGE >::Type READING_TYPE_VALID_RANGE; // 1
    static const typename ::uavcan::StorageType< typename ConstantTypes::READING_TYPE_TOO_CLOSE >::Type READING_TYPE_TOO_CLOSE; // 2
    static const typename ::uavcan::StorageType< typename ConstantTypes::READING_TYPE_TOO_FAR >::Type READING_TYPE_TOO_FAR; // 3

    // Fields
    typename ::uavcan::StorageType< typename FieldTypes::timestamp >::Type timestamp;
    typename ::uavcan::StorageType< typename FieldTypes::sensor_id >::Type sensor_id;
    typename ::uavcan::StorageType< typename FieldTypes::beam_orientation_in_body_frame >::Type beam_orientation_in_body_frame;
    typename ::uavcan::StorageType< typename FieldTypes::field_of_view >::Type field_of_view;
    typename ::uavcan::StorageType< typename FieldTypes::sensor_type >::Type sensor_type;
    typename ::uavcan::StorageType< typename FieldTypes::reading_type >::Type reading_type;
    typename ::uavcan::StorageType< typename FieldTypes::range >::Type range;

    Measurement_()
        : timestamp()
        , sensor_id()
        , beam_orientation_in_body_frame()
        , field_of_view()
        , sensor_type()
        , reading_type()
        , range()
    {
        ::uavcan::StaticAssert<_tmpl == 0>::check();  // Usage check

#if UAVCAN_DEBUG
        /*
         * Cross-checking MaxBitLen provided by the DSDL compiler.
         * This check shall never be performed in user code because MaxBitLen value
         * actually depends on the nested types, thus it is not invariant.
         */
        ::uavcan::StaticAssert<120 == MaxBitLen>::check();
#endif
    }

    bool operator==(ParameterType rhs) const;
    bool operator!=(ParameterType rhs) const { return !operator==(rhs); }

    /**
     * This comparison is based on @ref uavcan::areClose(), which ensures proper comparison of
     * floating point fields at any depth.
     */
    bool isClose(ParameterType rhs) const;

    static int encode(ParameterType self, ::uavcan::ScalarCodec& codec,
                      ::uavcan::TailArrayOptimizationMode tao_mode = ::uavcan::TailArrayOptEnabled);

    static int decode(ReferenceType self, ::uavcan::ScalarCodec& codec,
                      ::uavcan::TailArrayOptimizationMode tao_mode = ::uavcan::TailArrayOptEnabled);

    /*
     * Static type info
     */
    enum { DataTypeKind = ::uavcan::DataTypeKindMessage };
    enum { DefaultDataTypeID = 1050 };

    static const char* getDataTypeFullName()
    {
        return "uavcan.equipment.range_sensor.Measurement";
    }

    static void extendDataTypeSignature(::uavcan::DataTypeSignature& signature)
    {
        signature.extend(getDataTypeSignature());
    }

    static ::uavcan::DataTypeSignature getDataTypeSignature();

};

/*
 * Out of line struct method definitions
 */

template <int _tmpl>
bool Measurement_<_tmpl>::operator==(ParameterType rhs) const
{
    return
        timestamp == rhs.timestamp &&
        sensor_id == rhs.sensor_id &&
        beam_orientation_in_body_frame == rhs.beam_orientation_in_body_frame &&
        field_of_view == rhs.field_of_view &&
        sensor_type == rhs.sensor_type &&
        reading_type == rhs.reading_type &&
        range == rhs.range;
}

template <int _tmpl>
bool Measurement_<_tmpl>::isClose(ParameterType rhs) const
{
    return
        ::uavcan::areClose(timestamp, rhs.timestamp) &&
        ::uavcan::areClose(sensor_id, rhs.sensor_id) &&
        ::uavcan::areClose(beam_orientation_in_body_frame, rhs.beam_orientation_in_body_frame) &&
        ::uavcan::areClose(field_of_view, rhs.field_of_view) &&
        ::uavcan::areClose(sensor_type, rhs.sensor_type) &&
        ::uavcan::areClose(reading_type, rhs.reading_type) &&
        ::uavcan::areClose(range, rhs.range);
}

template <int _tmpl>
int Measurement_<_tmpl>::encode(ParameterType self, ::uavcan::ScalarCodec& codec,
    ::uavcan::TailArrayOptimizationMode tao_mode)
{
    (void)self;
    (void)codec;
    (void)tao_mode;
    int res = 1;
    res = FieldTypes::timestamp::encode(self.timestamp, codec,  ::uavcan::TailArrayOptDisabled);
    if (res <= 0)
    {
        return res;
    }
    res = FieldTypes::sensor_id::encode(self.sensor_id, codec,  ::uavcan::TailArrayOptDisabled);
    if (res <= 0)
    {
        return res;
    }
    res = FieldTypes::beam_orientation_in_body_frame::encode(self.beam_orientation_in_body_frame, codec,  ::uavcan::TailArrayOptDisabled);
    if (res <= 0)
    {
        return res;
    }
    res = FieldTypes::field_of_view::encode(self.field_of_view, codec,  ::uavcan::TailArrayOptDisabled);
    if (res <= 0)
    {
        return res;
    }
    res = FieldTypes::sensor_type::encode(self.sensor_type, codec,  ::uavcan::TailArrayOptDisabled);
    if (res <= 0)
    {
        return res;
    }
    res = FieldTypes::reading_type::encode(self.reading_type, codec,  ::uavcan::TailArrayOptDisabled);
    if (res <= 0)
    {
        return res;
    }
    res = FieldTypes::range::encode(self.range, codec,  tao_mode);
    return res;
}

template <int _tmpl>
int Measurement_<_tmpl>::decode(ReferenceType self, ::uavcan::ScalarCodec& codec,
    ::uavcan::TailArrayOptimizationMode tao_mode)
{
    (void)self;
    (void)codec;
    (void)tao_mode;
    int res = 1;
    res = FieldTypes::timestamp::decode(self.timestamp, codec,  ::uavcan::TailArrayOptDisabled);
    if (res <= 0)
    {
        return res;
    }
    res = FieldTypes::sensor_id::decode(self.sensor_id, codec,  ::uavcan::TailArrayOptDisabled);
    if (res <= 0)
    {
        return res;
    }
    res = FieldTypes::beam_orientation_in_body_frame::decode(self.beam_orientation_in_body_frame, codec,  ::uavcan::TailArrayOptDisabled);
    if (res <= 0)
    {
        return res;
    }
    res = FieldTypes::field_of_view::decode(self.field_of_view, codec,  ::uavcan::TailArrayOptDisabled);
    if (res <= 0)
    {
        return res;
    }
    res = FieldTypes::sensor_type::decode(self.sensor_type, codec,  ::uavcan::TailArrayOptDisabled);
    if (res <= 0)
    {
        return res;
    }
    res = FieldTypes::reading_type::decode(self.reading_type, codec,  ::uavcan::TailArrayOptDisabled);
    if (res <= 0)
    {
        return res;
    }
    res = FieldTypes::range::decode(self.range, codec,  tao_mode);
    return res;
}

/*
 * Out of line type method definitions
 */
template <int _tmpl>
::uavcan::DataTypeSignature Measurement_<_tmpl>::getDataTypeSignature()
{
    ::uavcan::DataTypeSignature signature(0x27B69FF7FBCEC600ULL);

    FieldTypes::timestamp::extendDataTypeSignature(signature);
    FieldTypes::sensor_id::extendDataTypeSignature(signature);
    FieldTypes::beam_orientation_in_body_frame::extendDataTypeSignature(signature);
    FieldTypes::field_of_view::extendDataTypeSignature(signature);
    FieldTypes::sensor_type::extendDataTypeSignature(signature);
    FieldTypes::reading_type::extendDataTypeSignature(signature);
    FieldTypes::range::extendDataTypeSignature(signature);

    return signature;
}

/*
 * Out of line constant definitions
 */

template <int _tmpl>
const typename ::uavcan::StorageType< typename Measurement_<_tmpl>::ConstantTypes::SENSOR_TYPE_UNDEFINED >::Type
    Measurement_<_tmpl>::SENSOR_TYPE_UNDEFINED = 0U; // 0

template <int _tmpl>
const typename ::uavcan::StorageType< typename Measurement_<_tmpl>::ConstantTypes::SENSOR_TYPE_SONAR >::Type
    Measurement_<_tmpl>::SENSOR_TYPE_SONAR = 1U; // 1

template <int _tmpl>
const typename ::uavcan::StorageType< typename Measurement_<_tmpl>::ConstantTypes::SENSOR_TYPE_LIDAR >::Type
    Measurement_<_tmpl>::SENSOR_TYPE_LIDAR = 2U; // 2

template <int _tmpl>
const typename ::uavcan::StorageType< typename Measurement_<_tmpl>::ConstantTypes::SENSOR_TYPE_RADAR >::Type
    Measurement_<_tmpl>::SENSOR_TYPE_RADAR = 3U; // 3

template <int _tmpl>
const typename ::uavcan::StorageType< typename Measurement_<_tmpl>::ConstantTypes::READING_TYPE_UNDEFINED >::Type
    Measurement_<_tmpl>::READING_TYPE_UNDEFINED = 0U; // 0

template <int _tmpl>
const typename ::uavcan::StorageType< typename Measurement_<_tmpl>::ConstantTypes::READING_TYPE_VALID_RANGE >::Type
    Measurement_<_tmpl>::READING_TYPE_VALID_RANGE = 1U; // 1

template <int _tmpl>
const typename ::uavcan::StorageType< typename Measurement_<_tmpl>::ConstantTypes::READING_TYPE_TOO_CLOSE >::Type
    Measurement_<_tmpl>::READING_TYPE_TOO_CLOSE = 2U; // 2

template <int _tmpl>
const typename ::uavcan::StorageType< typename Measurement_<_tmpl>::ConstantTypes::READING_TYPE_TOO_FAR >::Type
    Measurement_<_tmpl>::READING_TYPE_TOO_FAR = 3U; // 3

/*
 * Final typedef
 */
typedef Measurement_<0> Measurement;

namespace
{

const ::uavcan::DefaultDataTypeRegistrator< ::uavcan::equipment::range_sensor::Measurement > _uavcan_gdtr_registrator_Measurement;

}

} // Namespace range_sensor
} // Namespace equipment
} // Namespace uavcan

/*
 * YAML streamer specialization
 */
namespace uavcan
{

template <>
class UAVCAN_EXPORT YamlStreamer< ::uavcan::equipment::range_sensor::Measurement >
{
public:
    template <typename Stream>
    static void stream(Stream& s, ::uavcan::equipment::range_sensor::Measurement::ParameterType obj, const int level);
};

template <typename Stream>
void YamlStreamer< ::uavcan::equipment::range_sensor::Measurement >::stream(Stream& s, ::uavcan::equipment::range_sensor::Measurement::ParameterType obj, const int level)
{
    (void)s;
    (void)obj;
    (void)level;
    if (level > 0)
    {
        s << '\n';
        for (int pos = 0; pos < level; pos++)
        {
            s << "  ";
        }
    }
    s << "timestamp: ";
    YamlStreamer< ::uavcan::equipment::range_sensor::Measurement::FieldTypes::timestamp >::stream(s, obj.timestamp, level + 1);
    s << '\n';
    for (int pos = 0; pos < level; pos++)
    {
        s << "  ";
    }
    s << "sensor_id: ";
    YamlStreamer< ::uavcan::equipment::range_sensor::Measurement::FieldTypes::sensor_id >::stream(s, obj.sensor_id, level + 1);
    s << '\n';
    for (int pos = 0; pos < level; pos++)
    {
        s << "  ";
    }
    s << "beam_orientation_in_body_frame: ";
    YamlStreamer< ::uavcan::equipment::range_sensor::Measurement::FieldTypes::beam_orientation_in_body_frame >::stream(s, obj.beam_orientation_in_body_frame, level + 1);
    s << '\n';
    for (int pos = 0; pos < level; pos++)
    {
        s << "  ";
    }
    s << "field_of_view: ";
    YamlStreamer< ::uavcan::equipment::range_sensor::Measurement::FieldTypes::field_of_view >::stream(s, obj.field_of_view, level + 1);
    s << '\n';
    for (int pos = 0; pos < level; pos++)
    {
        s << "  ";
    }
    s << "sensor_type: ";
    YamlStreamer< ::uavcan::equipment::range_sensor::Measurement::FieldTypes::sensor_type >::stream(s, obj.sensor_type, level + 1);
    s << '\n';
    for (int pos = 0; pos < level; pos++)
    {
        s << "  ";
    }
    s << "reading_type: ";
    YamlStreamer< ::uavcan::equipment::range_sensor::Measurement::FieldTypes::reading_type >::stream(s, obj.reading_type, level + 1);
    s << '\n';
    for (int pos = 0; pos < level; pos++)
    {
        s << "  ";
    }
    s << "range: ";
    YamlStreamer< ::uavcan::equipment::range_sensor::Measurement::FieldTypes::range >::stream(s, obj.range, level + 1);
}

}

namespace uavcan
{
namespace equipment
{
namespace range_sensor
{

template <typename Stream>
inline Stream& operator<<(Stream& s, ::uavcan::equipment::range_sensor::Measurement::ParameterType obj)
{
    ::uavcan::YamlStreamer< ::uavcan::equipment::range_sensor::Measurement >::stream(s, obj, 0);
    return s;
}

} // Namespace range_sensor
} // Namespace equipment
} // Namespace uavcan

#endif // UAVCAN_EQUIPMENT_RANGE_SENSOR_MEASUREMENT_HPP_INCLUDED