#ifndef LIBPASSION_INCLUDE_MODULES_GRAPHICS_PS_GRAPHICS_STATE_H_
#define LIBPASSION_INCLUDE_MODULES_GRAPHICS_PS_GRAPHICS_STATE_H_
#include "../utils/ps_api.h"
#include "../utils/ps_status.h"

#include "graphics/ps_line_join.h"
#include "graphics/ps_line_style.h"

PS_PUBLIC_API enum ps_status ps_graphics_get_background_color(
        struct ps_passion *this,
        struct ps_color *color
);

PS_PUBLIC_API enum ps_status ps_graphics_get_color(
        struct ps_passion *this,
        struct ps_color *color
);

PS_PUBLIC_API enum ps_status ps_graphics_get_line_join(
        struct ps_passion *this,
        enum ps_line_join *line_join
);

PS_PUBLIC_API enum ps_status ps_graphics_get_line_style(
        struct ps_passion *this,
        enum ps_line_style *line_style
);

PS_PUBLIC_API enum ps_status ps_graphics_get_line_width(
        struct ps_passion *this,
        double *line_width
);

PS_PUBLIC_API enum ps_status ps_graphics_get_point_size(
        struct ps_passion *this,
        double *point_size
);

PS_PUBLIC_API enum ps_status ps_graphics_is_active(
        struct ps_passion *this,
        bool *active
);

PS_PUBLIC_API enum ps_status ps_graphics_is_wireframe(
        struct ps_passion *this,
        bool *wireframe
);

PS_PUBLIC_API enum ps_status ps_graphics_set_background_color(
        struct ps_passion *this,
        uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha
);

PS_PUBLIC_API enum ps_status ps_graphics_set_color(
        struct ps_passion *this,
        uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha
);

PS_PUBLIC_API enum ps_status ps_graphics_set_line_join(
        struct ps_passion *this,
        enum ps_line_join join
);

PS_PUBLIC_API enum ps_status ps_graphics_set_line_style(
        struct ps_passion *this,
        enum ps_line_style line_style
);

PS_PUBLIC_API enum ps_status ps_graphics_set_line_width(
        struct ps_passion *this,
        double line_width
);

PS_PUBLIC_API enum ps_status ps_graphics_set_point_size(
        struct ps_passion *this,
        double point_size
);

PS_PUBLIC_API enum ps_status ps_graphics_set_wireframe(
        struct ps_passion *this,
        bool wireframe
);

#endif