#include <passion.h>

#include <SDL.h>

#include "../../../include/modules/graphics/ps_get_display_state.h"

enum ps_status ps_graphics_get_background_color(struct ps_passion *this,
        struct ps_color *color
)
{
        PS_CHECK(this && color, PS_STATUS_INVALID_ARGUMENT);

        PS_GET_DISPLAY_STATE(state);

        memcpy(color, &state->background_color, sizeof(struct ps_color));

        return PS_STATUS_SUCCESS;
}

enum ps_status ps_graphics_get_color(struct ps_passion *this,
        struct ps_color *color
)
{
        PS_CHECK(this && color, PS_STATUS_INVALID_ARGUMENT);

        PS_GET_DISPLAY_STATE(state);

        memcpy(color, &state->foreground_color, sizeof(struct ps_color));

        return PS_STATUS_SUCCESS;
}

enum ps_status ps_graphics_get_line_join(struct ps_passion *this,
        enum ps_line_join *line_join
)
{
        PS_CHECK(this && line_join, PS_STATUS_INVALID_ARGUMENT);

        PS_GET_DISPLAY_STATE(state);

        *line_join = state->line_join;

        return PS_STATUS_SUCCESS;
}

enum ps_status ps_graphics_get_line_style(struct ps_passion *this,
        enum ps_line_style *line_style
)
{
        PS_CHECK(this && line_style, PS_STATUS_INVALID_ARGUMENT);

        PS_GET_DISPLAY_STATE(state);
        
        *line_style = state->line_style;

        return PS_STATUS_SUCCESS;
}

enum ps_status ps_graphics_get_line_width(struct ps_passion *this,
        double *line_width
)
{
        PS_CHECK(this && line_width, PS_STATUS_INVALID_ARGUMENT);

        PS_GET_DISPLAY_STATE(state);

        *line_width = state->line_width;

        return PS_STATUS_SUCCESS;
}

enum ps_status ps_graphics_get_point_size(struct ps_passion *this,
        double *point_size
)
{
        PS_CHECK(this && point_size, PS_STATUS_INVALID_ARGUMENT);

        PS_GET_DISPLAY_STATE(state);

        *point_size = state->point_size;

        return PS_STATUS_SUCCESS;
}

enum ps_status ps_graphics_is_active(struct ps_passion *this, bool *active)
{
        PS_CHECK(this && active, PS_STATUS_INVALID_ARGUMENT);
        *active = true;
        return PS_STATUS_SUCCESS;
}

enum ps_status ps_graphics_is_wireframe(struct ps_passion *this,
        bool *wireframe
)
{
        PS_CHECK(this && wireframe, PS_STATUS_INVALID_ARGUMENT);
        
        PS_GET_DISPLAY_STATE(state);

        *wireframe = state->wireframe;

        return PS_STATUS_SUCCESS;
}

enum ps_status ps_graphics_set_background_color(struct ps_passion *this,
        uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha
)
{
        PS_CHECK(this, PS_STATUS_INVALID_ARGUMENT);

        PS_GET_DISPLAY_STATE(state);

        state->background_color.red = red;
        state->background_color.green = green;
        state->background_color.blue = blue;
        state->background_color.alpha = alpha;

        return PS_STATUS_SUCCESS;
}

enum ps_status ps_graphics_set_color(struct ps_passion *this,
        uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha
)
{
        PS_CHECK(this, PS_STATUS_INVALID_ARGUMENT);

        PS_GET_DISPLAY_STATE(state);

        state->foreground_color.red = red;
        state->foreground_color.green = green;
        state->foreground_color.blue = blue;
        state->foreground_color.alpha = alpha;

        glVertexAttrib4d(PS_VERTEX_ATTRIB_CONSTANT_COLOR, 
                red, green, blue, alpha);

        return PS_STATUS_SUCCESS;
}

enum ps_status ps_graphics_set_line_join(struct ps_passion *this,
        enum ps_line_join line_join
)
{
        PS_CHECK(this, PS_STATUS_INVALID_ARGUMENT);

        PS_GET_DISPLAY_STATE(state);

        state->line_join = line_join;

        return PS_STATUS_SUCCESS;
}

enum ps_status ps_graphics_set_line_style(struct ps_passion *this,
        enum ps_line_style line_style
)
{
        PS_CHECK(this, PS_STATUS_INVALID_ARGUMENT);

        PS_GET_DISPLAY_STATE(state);

        state->line_style = line_style;

        return PS_STATUS_SUCCESS;
}

enum ps_status ps_graphics_set_line_width(struct ps_passion *this,
        double line_width
)
{
        PS_CHECK(this, PS_STATUS_INVALID_ARGUMENT);

        PS_GET_DISPLAY_STATE(state);

        state->line_width = line_width;

        return PS_STATUS_SUCCESS;
}

enum ps_status ps_graphics_set_point_size(struct ps_passion *this,
        double point_size
)
{
        PS_CHECK(this, PS_STATUS_INVALID_ARGUMENT);

        PS_GET_DISPLAY_STATE(state);

        state->point_size = point_size;
        glPointSize((GLfloat)point_size);

        return PS_STATUS_SUCCESS;
}

enum ps_status ps_graphics_set_wireframe(struct ps_passion *this,
        bool wireframe
)
{
        PS_CHECK(this, PS_STATUS_INVALID_ARGUMENT);

        PS_GET_DISPLAY_STATE(state);

        state->wireframe = wireframe;

        return PS_STATUS_SUCCESS;
}