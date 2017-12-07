#ifndef LIBPASSION_INCLUDE_MODULES_GRAPHICS_PS_GRAPHICS_DRAWING_H_
#define LIBPASSION_INCLUDE_MODULES_GRAPHICS_PS_GRAPHICS_DRAWING_H_

#include "../utils/ps_api.h"
#include "../utils/ps_status.h"

#include "ps_color.h"

PS_PUBLIC_API enum ps_status ps_graphics_clear(
        struct ps_passion *this,
        struct ps_color *color
);

PS_PUBLIC_API enum ps_status ps_graphics_present(
        struct ps_passion *this
);

#endif