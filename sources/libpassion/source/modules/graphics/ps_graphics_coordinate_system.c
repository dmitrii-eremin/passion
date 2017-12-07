#include <passion.h>

#include <SDL.h>
#include <SDL_opengl.h>

#include "../../../include/modules/graphics/ps_get_display_state.h"

enum ps_status ps_graphics_origin(struct ps_passion *this)
{
        PS_CHECK(this, PS_STATUS_INVALID_ARGUMENT);
        return PS_STATUS_SUCCESS;
}

enum ps_status ps_graphics_pop(struct ps_passion *this)
{
        PS_CHECK(this, PS_STATUS_INVALID_ARGUMENT);

        if (!this->graphics.stack_types || !this->graphics.display_states) {
                return PS_STATUS_INVALID_STACK_SIZE;
        }

        enum ps_stack_type stack_type = PS_STACK_TYPE_TRANSFORM;
        PS_STATUS_ASSERT(
                ps_stack_type_list_pop_back(
                        &this->graphics.stack_types, &stack_type
                )
        );

        if (stack_type == PS_STACK_TYPE_ALL) {
                struct ps_display_state state = { 0 };
                PS_STATUS_ASSERT(
                        ps_display_state_list_pop_back(
                                &this->graphics.display_states, &state
                        )
                );
        }

        return PS_STATUS_SUCCESS;
}

enum ps_status ps_graphics_push(struct ps_passion *this)
{
        return ps_graphics_push_ex(this, PS_STACK_TYPE_TRANSFORM);
}

enum ps_status ps_graphics_push_ex(struct ps_passion *this,
        enum ps_stack_type stack_type
)
{
        PS_CHECK(this, PS_STATUS_INVALID_ARGUMENT);

        if (stack_type == PS_STACK_TYPE_ALL) {
                struct ps_display_state *state = NULL;
                PS_STATUS_ASSERT(
                        ps_display_state_list_get_last(
                                &this->graphics.display_states, &state
                        )
                );
                PS_STATUS_ASSERT(
                        ps_display_state_list_push_back(
                                &this->graphics.display_states, state
                        )
                );
        }

        PS_STATUS_ASSERT(
                ps_stack_type_list_push_back(
                        &this->graphics.stack_types, &stack_type
                )
        );

        return PS_STATUS_SUCCESS;
}