#ifndef LIBPASSION_INCLUDE_MODULES_GRAPHICS_PS_COLOR_H_
#define LIBPASSION_INCLUDE_MODULES_GRAPHICS_PS_COLOR_H_
#include <stdint.h>

struct ps_color {
        uint8_t red;
        uint8_t green;
        uint8_t blue;
        uint8_t alpha;
};

#endif