#ifndef LIBPASSION_INCLUDE_UTILS_PS_VERSION_H_
#define LIBPASSION_INCLUDE_UTILS_PS_VERSION_H_
#include <stdint.h>

typedef uint32_t ps_version;

#define PS_VERSION_CREATE(MJ, MI, PT) (((MJ) << 16) | ((MI) << 8) | (PT))

#define PS_VERSION_MAJOR(V) (((V) >> 16) & 0xFF)
#define PS_VERSION_MINOR(V) (((V) >> 8) & 0xFF)
#define PS_VERSION_PATCH(V) ((V) & 0xFF)

#define PS_VERSION_CURRENT PS_VERSION_CREATE(0, 1, 0)

#endif