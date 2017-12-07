#include <passion.h>

#include <SDL.h>
#include <SDL_opengl.h>

enum ps_status ps_graphics_get_background_color(struct ps_passion *this,
        struct ps_color *color
)
{
        PS_CHECK(this && color, PS_STATUS_INVALID_ARGUMENT);

        memcpy(color, &this->graphics.background_color,
                sizeof(struct ps_color));

        return PS_STATUS_SUCCESS;
}

enum ps_status ps_graphics_get_color(struct ps_passion *this,
        struct ps_color *color
)
{
        PS_CHECK(this && color, PS_STATUS_INVALID_ARGUMENT);

        memcpy(color, &this->graphics.foreground_color,
                sizeof(struct ps_color));

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

        struct ps_graphics *g = &this->graphics;
        g->background_color.red = red;
        g->background_color.green = green;
        g->background_color.blue = blue;
        g->background_color.alpha = alpha;

        return PS_STATUS_SUCCESS;
}

enum ps_status ps_graphics_set_color(struct ps_passion *this,
        double red, double green, double blue, double alpha
)
{
        PS_CHECK(this, PS_STATUS_INVALID_ARGUMENT);

        struct ps_graphics *g = &this->graphics;
        g->foreground_color.red = red;
        g->foreground_color.green = green;
        g->foreground_color.blue = blue;
        g->foreground_color.alpha = alpha;

        return PS_STATUS_SUCCESS;
}