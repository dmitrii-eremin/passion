#ifndef LIBPASSION_INCLUDE_MODULES_GRAPHICS_PS_GRAPHICS_WINDOW_H_
#define LIBPASSION_INCLUDE_MODULES_GRAPHICS_PS_GRAPHICS_WINDOW_H_
#include "../utils/ps_api.h"
#include "../utils/ps_status.h"

PS_PUBLIC_API enum ps_status ps_graphics_get_dimensions(
        struct ps_passion *this,
        uint16_t *width,
        uint16_t *height
);

PS_PUBLIC_API enum ps_status ps_graphics_get_height(
        struct ps_passion *this,
        uint16_t *height
);

PS_PUBLIC_API enum ps_status ps_graphics_get_width(
        struct ps_passion *this,
        uint16_t *width
);

#endif