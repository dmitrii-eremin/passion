#include <string.h>

#include <SDL.h>
#include <SDL_opengl.h>

#include <passion.h>

enum ps_status ps_graphics_initialize(struct ps_passion *this)
{
        PS_CHECK(this, PS_STATUS_INVALID_ARGUMENT);

        struct ps_color bg_color = {
                .red = 0.0, .green = 0.0, .blue = 0.0, .alpha = 1.0
        };

        struct ps_color fr_color = {
                .red = 1.0,.green = 1.0,.blue = 1.0,.alpha = 1.0
        };

        memcpy(&this->graphics.background_color, 
                &bg_color, sizeof(struct ps_color));
        memcpy(&this->graphics.foreground_color,
                &fr_color, sizeof(struct ps_color));

        return PS_STATUS_SUCCESS;
}

enum ps_status ps_graphics_deinitialize(struct ps_passion *this)
{
        if (!this) {
                return PS_STATUS_SUCCESS;
        }

        return PS_STATUS_SUCCESS;
}