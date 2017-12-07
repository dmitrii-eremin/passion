#include <passion.h>

#include <SDL.h>
#include <SDL_opengl.h>

enum ps_status ps_graphics_get_background_color(struct ps_passion *this,
        struct ps_color *color
)
{
        PS_CHECK(this && color, PS_STATUS_INVALID_ARGUMENT);

        struct ps_display_state *state = NULL;
        PS_STATUS_ASSERT(
                ps_display_state_list_get_last(
                        &this->graphics.display_states, &state
                )
        );

        memcpy(color, &state->background_color, sizeof(struct ps_color));

        return PS_STATUS_SUCCESS;
}

enum ps_status ps_graphics_get_color(struct ps_passion *this,
        struct ps_color *color
)
{
        PS_CHECK(this && color, PS_STATUS_INVALID_ARGUMENT);

        struct ps_display_state *state = NULL;
        PS_STATUS_ASSERT(
                ps_display_state_list_get_last(
                        &this->graphics.display_states, &state
                )
        );

        memcpy(color, &state->foreground_color, sizeof(struct ps_color));

        return PS_STATUS_SUCCESS;
}

enum ps_status ps_graphics_get_line_join(struct ps_passion *this,
        enum ps_line_join *line_join
)
{
        PS_CHECK(this && line_join, PS_STATUS_INVALID_ARGUMENT);

        struct ps_display_state *state = NULL;
        PS_STATUS_ASSERT(
                ps_display_state_list_get_last(
                        &this->graphics.display_states, &state
                )
        );

        *line_join = state->line_join;

        return PS_STATUS_SUCCESS;
}

enum ps_status ps_graphics_is_active(struct ps_passion *this, bool *active)
{
        PS_CHECK(this && active, PS_STATUS_INVALID_ARGUMENT);
        *active = true;
        return PS_STATUS_SUCCESS;
}

enum ps_status ps_graphics_set_background_color(struct ps_passion *this,
        double red, double green, double blue, double alpha
)
{
        PS_CHECK(this, PS_STATUS_INVALID_ARGUMENT);

        struct ps_display_state *state = NULL;
        PS_STATUS_ASSERT(
                ps_display_state_list_get_last(
                        &this->graphics.display_states, &state
                )
        );

        state->background_color.red = red;
        state->background_color.green = green;
        state->background_color.blue = blue;
        state->background_color.alpha = alpha;

        return PS_STATUS_SUCCESS;
}

enum ps_status ps_graphics_set_color(struct ps_passion *this,
        double red, double green, double blue, double alpha
)
{
        PS_CHECK(this, PS_STATUS_INVALID_ARGUMENT);

        struct ps_display_state *state = NULL;
        PS_STATUS_ASSERT(
                ps_display_state_list_get_last(
                        &this->graphics.display_states, &state
                )
        );

        state->foreground_color.red = red;
        state->foreground_color.green = green;
        state->foreground_color.blue = blue;
        state->foreground_color.alpha = alpha;

        return PS_STATUS_SUCCESS;
}

enum ps_status ps_graphics_set_line_join(struct ps_passion *this,
        enum ps_line_join line_join
)
{
        PS_CHECK(this, PS_STATUS_INVALID_ARGUMENT);

        struct ps_display_state *state = NULL;
        PS_STATUS_ASSERT(
                ps_display_state_list_get_last(
                        &this->graphics.display_states, &state
                )
        );

        state->line_join = line_join;

        return PS_STATUS_SUCCESS;
}