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

enum ps_status ps_graphics_clear(struct ps_passion *this,
        struct ps_color *color
)
{
        PS_CHECK(this, PS_STATUS_INVALID_ARGUMENT);

        struct ps_color *color_to_use = color ? 
                color : &this->graphics.background_color;

        glClearColor((GLclampf)color_to_use->red, 
                (GLclampf)color_to_use->green,
                (GLclampf)color_to_use->blue, 
                (GLclampf)color_to_use->alpha
        );
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        return PS_STATUS_SUCCESS;
}

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

enum ps_status ps_graphics_is_active(struct ps_passion *this, bool *active)
{
        PS_CHECK(this && active, PS_STATUS_INVALID_ARGUMENT);
        *active = true;
        return PS_STATUS_SUCCESS;
}

enum ps_status ps_graphics_origin(struct ps_passion *this)
{
        PS_CHECK(this, PS_STATUS_INVALID_ARGUMENT);
        return PS_STATUS_SUCCESS;
}

enum ps_status ps_graphics_present(struct ps_passion *this)
{
        PS_CHECK(this, PS_STATUS_INVALID_ARGUMENT);

        bool active = false;
        PS_STATUS_ASSERT(ps_graphics_is_active(this, &active));

        if (active) {
                SDL_Window *sdl_window = this->window.window;
                if (sdl_window)
                        SDL_GL_SwapWindow(sdl_window);
        }

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