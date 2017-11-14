#ifndef LIBPASSION_INCLUDE_UTILS_PS_API_H_
#define LIBPASSION_INCLUDE_UTILS_PS_API_H_

#if defined(_WIN32) || defined(__CYGWIN__)
        #if defined(PS_BUILD_LIB)
                #if defined(__GNUC__)
                        #define PS_PUBLIC_API __attribute__ ((dllexport))
                #else
                        #define PS_PUBLIC_API __declspec(dllexport)
                #endif
        #else
                #if defined(__GNUC__)
                        #define PS_PUBLIC_API __attribute__ ((dllimport))
                #else
                        #define PS_PUBLIC_API __declspec(dllimport)
                #endif
        #endif
        #define PS_PRIVATE_API
#else
        #if __GNUC__ >= 4
                #define PS_PUBLIC_API __attribute__ ((visibility ("default")))
                #define PS_PRIVATE_API __attribute__ ((visibility ("hidden")))
        #else
                #define PS_PUBLIC_API
                #define PS_PRIVATE_API
        #endif
#endif

#endif