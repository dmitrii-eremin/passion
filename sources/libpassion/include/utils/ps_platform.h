#ifndef LIBPASSION_INCLUDE_UTILS_PS_PLATFORM_H_
#define LIBPASSION_INCLUDE_UTILS_PS_PLATFORM_H_

#if defined(WIN32) || defined(_WIN32)
        #define PS_PLATFORM_WINDOWS 1
                #if defined(_MSC_VER) && (_MSC_VER >= 1700) && !_USING_V110_SDK71_
                        #include <winapifamily.h>
                        #if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP) && !WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
                                #define PS_PLATFORM_WINDOWS_UWP 1
                                #define PS_PLATFORM_NO_MODPLUG 1
                                #define PS_PLATFORM_NOMPG123 1
                        #endif
                #endif
#endif

#if defined(linux) || defined(__linux) || defined(__linux__)
        #define PS_PLATFORM_LINUX 1
#endif

#if defined(__ANDROID__)
        #define PS_PLATFORM_ANDROID 1
#endif

#if defined(__APPLE__)
        #include <TargetConditionals.h>
        #if TARGET_OS_IPHONE
                #define PS_PLATFORM_IOS 1
        #elif TARGET_OS_MAC
                #define PS_PLATFORM_MACOSX 1
        #endif
#endif

#if defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__)
        #define PS_PLATFORM_LINUX 1
#endif

#endif