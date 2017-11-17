#ifndef LIBPASSION_INCLUDE_UTILS_PS_STATUS_H_
#define LIBPASSION_INCLUDE_UTILS_PS_STATUS_H_

#define PS_STATUS_SUCCEEDED(S) ((S) == PS_STATUS_SUCCESS)
#define PS_STATUS_FAILED(S) ((S) != PS_STATUS_SUCCESS)

#define PS_STATUS_ASSERT(S) \
        { \
                enum ps_status s = (S); \
                if (PS_STATUS_FAILED(s)) \
                        return s; \
        }

enum ps_status {
        PS_STATUS_UNKNOWN_ERROR = 0xFFFFFFFF,

        PS_STATUS_SUCCESS = 0x00000000,

        PS_STATUS_INCOMPATIBLE_VERSION,
        PS_STATUS_NOT_IMPLEMENTED_YET,

        PS_STATUS_INVALID_ARGUMENT,
        PS_STATUS_IVALID_OBJECT,
        PS_STATUS_NOT_INITIALIZED,

        PS_STATUS_FAILED_TO_OPEN,
        PS_STATUS_FAILED_TO_READ,
        PS_STATUS_FAILED_TO_WRITE,

        PS_STATUS_MAX
};

#endif