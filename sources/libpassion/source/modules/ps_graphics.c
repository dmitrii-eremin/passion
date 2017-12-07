#include <string.h>

#include <SDL.h>
#include <SDL_opengl.h>

#include <passion.h>

PS_PRIVATE_API enum ps_status ps_get_default_display_state(struct ps_display_state *state)
{
        static const struct ps_display_state default_display_state = {
                .line_join = PS_LINE_JOIN_BEVEL,
                .line_style = PS_LINE_STYLE_SMOOTH,

                .point_size = 1.0,
                .line_width = 1.0,

                .wireframe = false,

                .background_color = {
                        .red = 0.0,.green = 0.0,.blue = 0.0,.alpha = 1.0
                },
                        .foreground_color = {
                        .red = 1.0,.green = 1.0,.blue = 1.0,.alpha = 1.0
                }
        };

        PS_CHECK(state, PS_STATUS_INVALID_ARGUMENT);

        memcpy(state, &default_display_state, sizeof(struct ps_display_state));

        return PS_STATUS_SUCCESS;
}

enum ps_status ps_graphics_initialize(struct ps_passion *this)
{       
        PS_CHECK(this, PS_STATUS_INVALID_ARGUMENT);

        this->graphics.display_states = NULL;        

        struct ps_display_state initial_display_state = { 0 };
        PS_STATUS_ASSERT(ps_get_default_display_state(&initial_display_state));
        ps_display_state_list_push_back(
                &this->graphics.display_states,
                &initial_display_state
        );

        this->graphics.stack_types = NULL;

        return PS_STATUS_SUCCESS;
}

enum ps_status ps_graphics_deinitialize(struct ps_passion *this)
{
        if (!this) {
                return PS_STATUS_SUCCESS;
        }

        ps_display_state_list_clear(&this->graphics.display_states);
        ps_stack_type_list_clear(&this->graphics.stack_types);

        return PS_STATUS_SUCCESS;
}