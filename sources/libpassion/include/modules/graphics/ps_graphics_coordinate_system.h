#ifndef LIBPASSION_INCLUDE_MODULES_GRAPHICS_PS_GRAPHICS_COORDINATE_SYSTEM_H_
#define LIBPASSION_INCLUDE_MODULES_GRAPHICS_PS_GRAPHICS_COORDINATE_SYSTEM_H_
#include "../utils/ps_api.h"
#include "../utils/ps_status.h"

#include "ps_stack_type.h"

PS_PUBLIC_API enum ps_status ps_graphics_origin(struct ps_passion *this);

PS_PUBLIC_API enum ps_status ps_graphics_pop(struct ps_passion *this);

PS_PUBLIC_API enum ps_status ps_graphics_push(struct ps_passion *this);

PS_PUBLIC_API enum ps_status ps_graphics_push_ex(
        struct ps_passion *this,
        enum ps_stack_type stack_type
);

#endif