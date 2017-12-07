#ifndef LIBPASSION_INCLUDE_MODULES_GRAPHICS_PS_DISPLAY_STATE_H_
#define LIBPASSION_INCLUDE_MODULES_GRAPHICS_PS_DISPLAY_STATE_H_
#include <stdbool.h>

#include "ps_line_join.h"
#include "ps_line_style.h"
#include "ps_color.h"

#include "../utils/ps_api.h"
#include "../utils/ps_list.h"
#include "../utils/ps_status.h"

struct ps_display_state {
        enum ps_line_join line_join;
        enum ps_line_style line_style;

        double point_size;
        double line_width;

        bool wireframe;

        struct ps_color background_color;
        struct ps_color foreground_color;
};

PS_DEFINE_LIST(ps_display_state_list, ps_display_state_item, 
        struct ps_display_state, PS_PRIVATE_API);

#endif