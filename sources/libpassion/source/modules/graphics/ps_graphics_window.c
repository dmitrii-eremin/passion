#include <passion.h>

#include <SDL.h>
#include <SDL_opengl.h>

#include "../../../include/modules/graphics/ps_get_display_state.h"

enum ps_status ps_graphics_get_dimensions(struct ps_passion *this,
        uint16_t *width, uint16_t *height
)
{
        PS_CHECK(this, PS_STATUS_INVALID_ARGUMENT);
        SDL_Window *wnd = (SDL_Window*)this->window.window;
        if (!wnd)
                return PS_STATUS_NOT_INITIALIZED;


        int w = 0;
        int h = 0;
        SDL_GetWindowSize(wnd, &w, &h);

        if (width)
                *width = (uint16_t)w;
        if (height)
                *height = (uint16_t)h;

        return PS_STATUS_SUCCESS;
}

enum ps_status ps_graphics_get_height(struct ps_passion *this,
        uint16_t *height
)
{
        return ps_graphics_get_dimensions(this, NULL, height);
}

enum ps_status ps_graphics_get_width(struct ps_passion *this,
        uint16_t *width
)
{
        return ps_graphics_get_dimensions(this, width, NULL);
}