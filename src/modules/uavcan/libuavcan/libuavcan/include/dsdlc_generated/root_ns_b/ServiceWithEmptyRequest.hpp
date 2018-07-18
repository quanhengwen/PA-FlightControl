/*
 * UAVCAN data structure definition for libuavcan.
 *
 * Autogenerated, do not edit.
 *
 * Source file: /data/work/workspace/pa/PA-FlightControl/src/modules/uavcan/libuavcan/libuavcan/test/dsdl_test/root_ns_b/ServiceWithEmptyRequest.uavcan
 */

#ifndef ROOT_NS_B_SERVICEWITHEMPTYREQUEST_HPP_INCLUDED
#define ROOT_NS_B_SERVICEWITHEMPTYREQUEST_HPP_INCLUDED

#include <uavcan/build_config.hpp>
#include <uavcan/node/global_data_type_registry.hpp>
#include <uavcan/marshal/types.hpp>

/******************************* Source text **********************************
---
float16[<=9] covariance
******************************************************************************/

/********************* DSDL signature source definition ***********************
root_ns_b.ServiceWithEmptyRequest
---
saturated float16[<=9] covariance
******************************************************************************/

#undef covariance

namespace root_ns_b
{

struct UAVCAN_EXPORT ServiceWithEmptyRequest_
{
    template <int _tmpl>
    struct Request_
    {
        typedef const Request_<_tmpl>& ParameterType;
        typedef Request_<_tmpl>& ReferenceType;

        struct ConstantTypes
        {
        };

        struct FieldTypes
        {
        };

        enum
        {
            MinBitLen
        };

        enum
        {
            MaxBitLen
        };

        // Constants

        // Fields

        Request_()
        {
            ::uavcan::StaticAssert<_tmpl == 0>::check();  // Usage check

    #if UAVCAN_DEBUG
            /*
             * Cross-checking MaxBitLen provided by the DSDL compiler.
             * This check shall never be performed in user code because MaxBitLen value
             * actually depends on the nested types, thus it is not invariant.
             */
            ::uavcan::StaticAssert<0 == MaxBitLen>::check();
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

    };

    template <int _tmpl>
    struct Response_
    {
        typedef const Response_<_tmpl>& ParameterType;
        typedef Response_<_tmpl>& ReferenceType;

        struct ConstantTypes
        {
        };

        struct FieldTypes
        {
            typedef ::uavcan::Array< ::uavcan::FloatSpec< 16, ::uavcan::CastModeSaturate >, ::uavcan::ArrayModeDynamic, 9 > covariance;
        };

        enum
        {
            MinBitLen
                = FieldTypes::covariance::MinBitLen
        };

        enum
        {
            MaxBitLen
                = FieldTypes::covariance::MaxBitLen
        };

        // Constants

        // Fields
        typename ::uavcan::StorageType< typename FieldTypes::covariance >::Type covariance;

        Response_()
            : covariance()
        {
            ::uavcan::StaticAssert<_tmpl == 0>::check();  // Usage check

    #if UAVCAN_DEBUG
            /*
             * Cross-checking MaxBitLen provided by the DSDL compiler.
             * This check shall never be performed in user code because MaxBitLen value
             * actually depends on the nested types, thus it is not invariant.
             */
            ::uavcan::StaticAssert<148 == MaxBitLen>::check();
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

    };

    typedef Request_<0> Request;
    typedef Response_<0> Response;

    /*
     * Static type info
     */
    enum { DataTypeKind = ::uavcan::DataTypeKindService };
    // This type has no default data type ID

    static const char* getDataTypeFullName()
    {
        return "root_ns_b.ServiceWithEmptyRequest";
    }

    static void extendDataTypeSignature(::uavcan::DataTypeSignature& signature)
    {
        signature.extend(getDataTypeSignature());
    }

    static ::uavcan::DataTypeSignature getDataTypeSignature();

private:
    ServiceWithEmptyRequest_(); // Don't create objects of this type. Use Request/Response instead.
};

/*
 * Out of line struct method definitions
 */

template <int _tmpl>
bool ServiceWithEmptyRequest_::Request_<_tmpl>::operator==(ParameterType rhs) const
{
    (void)rhs;
    return true;
}

template <int _tmpl>
bool ServiceWithEmptyRequest_::Request_<_tmpl>::isClose(ParameterType rhs) const
{
    (void)rhs;
    return true;
}

template <int _tmpl>
int ServiceWithEmptyRequest_::Request_<_tmpl>::encode(ParameterType self, ::uavcan::ScalarCodec& codec,
    ::uavcan::TailArrayOptimizationMode tao_mode)
{
    (void)self;
    (void)codec;
    (void)tao_mode;
    int res = 1;
    return res;
}

template <int _tmpl>
int ServiceWithEmptyRequest_::Request_<_tmpl>::decode(ReferenceType self, ::uavcan::ScalarCodec& codec,
    ::uavcan::TailArrayOptimizationMode tao_mode)
{
    (void)self;
    (void)codec;
    (void)tao_mode;
    int res = 1;
    return res;
}

template <int _tmpl>
bool ServiceWithEmptyRequest_::Response_<_tmpl>::operator==(ParameterType rhs) const
{
    return
        covariance == rhs.covariance;
}

template <int _tmpl>
bool ServiceWithEmptyRequest_::Response_<_tmpl>::isClose(ParameterType rhs) const
{
    return
        ::uavcan::areClose(covariance, rhs.covariance);
}

template <int _tmpl>
int ServiceWithEmptyRequest_::Response_<_tmpl>::encode(ParameterType self, ::uavcan::ScalarCodec& codec,
    ::uavcan::TailArrayOptimizationMode tao_mode)
{
    (void)self;
    (void)codec;
    (void)tao_mode;
    int res = 1;
    res = FieldTypes::covariance::encode(self.covariance, codec,  tao_mode);
    return res;
}

template <int _tmpl>
int ServiceWithEmptyRequest_::Response_<_tmpl>::decode(ReferenceType self, ::uavcan::ScalarCodec& codec,
    ::uavcan::TailArrayOptimizationMode tao_mode)
{
    (void)self;
    (void)codec;
    (void)tao_mode;
    int res = 1;
    res = FieldTypes::covariance::decode(self.covariance, codec,  tao_mode);
    return res;
}

/*
 * Out of line type method definitions
 */
inline ::uavcan::DataTypeSignature ServiceWithEmptyRequest_::getDataTypeSignature()
{
    ::uavcan::DataTypeSignature signature(0xBDBE625E06ACCC26ULL);

    Response::FieldTypes::covariance::extendDataTypeSignature(signature);

    return signature;
}

/*
 * Out of line constant definitions
 */

/*
 * Final typedef
 */
typedef ServiceWithEmptyRequest_ ServiceWithEmptyRequest;

// No default registration

} // Namespace root_ns_b

/*
 * YAML streamer specialization
 */
namespace uavcan
{

template <>
class UAVCAN_EXPORT YamlStreamer< ::root_ns_b::ServiceWithEmptyRequest::Request >
{
public:
    template <typename Stream>
    static void stream(Stream& s, ::root_ns_b::ServiceWithEmptyRequest::Request::ParameterType obj, const int level);
};

template <typename Stream>
void YamlStreamer< ::root_ns_b::ServiceWithEmptyRequest::Request >::stream(Stream& s, ::root_ns_b::ServiceWithEmptyRequest::Request::ParameterType obj, const int level)
{
    (void)s;
    (void)obj;
    (void)level;
}

template <>
class UAVCAN_EXPORT YamlStreamer< ::root_ns_b::ServiceWithEmptyRequest::Response >
{
public:
    template <typename Stream>
    static void stream(Stream& s, ::root_ns_b::ServiceWithEmptyRequest::Response::ParameterType obj, const int level);
};

template <typename Stream>
void YamlStreamer< ::root_ns_b::ServiceWithEmptyRequest::Response >::stream(Stream& s, ::root_ns_b::ServiceWithEmptyRequest::Response::ParameterType obj, const int level)
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
    s << "covariance: ";
    YamlStreamer< ::root_ns_b::ServiceWithEmptyRequest::Response::FieldTypes::covariance >::stream(s, obj.covariance, level + 1);
}

}

namespace root_ns_b
{

template <typename Stream>
inline Stream& operator<<(Stream& s, ::root_ns_b::ServiceWithEmptyRequest::Request::ParameterType obj)
{
    ::uavcan::YamlStreamer< ::root_ns_b::ServiceWithEmptyRequest::Request >::stream(s, obj, 0);
    return s;
}

template <typename Stream>
inline Stream& operator<<(Stream& s, ::root_ns_b::ServiceWithEmptyRequest::Response::ParameterType obj)
{
    ::uavcan::YamlStreamer< ::root_ns_b::ServiceWithEmptyRequest::Response >::stream(s, obj, 0);
    return s;
}

} // Namespace root_ns_b

#endif // ROOT_NS_B_SERVICEWITHEMPTYREQUEST_HPP_INCLUDED