#ifndef LIBPASSION_INCLUDE_MODULES_GRAPHICS_PS_GRAPHICS_STATE_H_
#define LIBPASSION_INCLUDE_MODULES_GRAPHICS_PS_GRAPHICS_STATE_H_
#include "../utils/ps_api.h"
#include "../utils/ps_status.h"

PS_PUBLIC_API enum ps_status ps_graphics_get_background_color(
        struct ps_passion *this,
        struct ps_color *color
);

PS_PUBLIC_API enum ps_status ps_graphics_get_color(
        struct ps_passion *this,
        struct ps_color *color
);

PS_PUBLIC_API enum ps_status ps_graphics_is_active(
        struct ps_passion *this,
        bool *active
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