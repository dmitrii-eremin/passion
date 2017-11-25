#ifndef LIBPASSION_INCLUDE_MODULES_PS_GRAPHICS_H_
#define LIBPASSION_INCLUDE_MODULES_PS_GRAPHICS_H_
#include <stdbool.h>

#include "../utils/ps_api.h"
#include "../utils/ps_status.h"

#include "graphics/ps_color.h"

struct ps_passion;

struct ps_graphics {
        struct ps_color background_color;
        struct ps_color foreground_color;
};

PS_PRIVATE_API enum ps_status ps_graphics_initialize(
        struct ps_passion *this
);

PS_PRIVATE_API enum ps_status ps_graphics_deinitialize(
        struct ps_passion *this
);

PS_PUBLIC_API enum ps_status ps_graphics_clear(
        struct ps_passion *this,
        struct ps_color *color
);

PS_PUBLIC_API enum ps_status ps_graphics_get_background_color(
        struct ps_passion *this,
        struct ps_color *color
);

PS_PUBLIC_API enum ps_status ps_graphics_get_color(
        struct ps_passion *this,
        struct ps_color *color
);

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

PS_PUBLIC_API enum ps_status ps_graphics_is_active(
        struct ps_passion *this,
        bool *active
);

PS_PUBLIC_API enum ps_status ps_graphics_origin(
        struct ps_passion *this
);

PS_PUBLIC_API enum ps_status ps_graphics_present(
        struct ps_passion *this
);

PS_PUBLIC_API enum ps_status ps_graphics_set_background_color(
        struct ps_passion *this,
        double red, double green, double blue, double alpha
);

PS_PUBLIC_API enum ps_status ps_graphics_set_color(
        struct ps_passion *this,
        double red, double green, double blue, double alpha
);


#endif