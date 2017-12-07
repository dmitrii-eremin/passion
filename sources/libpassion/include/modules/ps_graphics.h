#ifndef LIBPASSION_INCLUDE_MODULES_PS_GRAPHICS_H_
#define LIBPASSION_INCLUDE_MODULES_PS_GRAPHICS_H_
#include <stdbool.h>

#include "../utils/ps_api.h"
#include "../utils/ps_status.h"

#include "graphics/ps_display_state.h"
#include "graphics/ps_stack_type_item.h"

#include "graphics/ps_graphics_coordinate_system.h"
#include "graphics/ps_graphics_drawing.h"
#include "graphics/ps_graphics_state.h"
#include "graphics/ps_graphics_system_information.h"
#include "graphics/ps_graphics_window.h"

struct ps_passion;

struct ps_graphics {
        struct ps_display_state_item *display_states;
        struct ps_stack_type_item *stack_types;
};

PS_PRIVATE_API enum ps_status ps_graphics_initialize(
        struct ps_passion *this
);

PS_PRIVATE_API enum ps_status ps_graphics_deinitialize(
        struct ps_passion *this
);

#endif