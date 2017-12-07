#include <passion.h>

#include <SDL.h>
#include <SDL_opengl.h>

#include "../../../include/modules/graphics/ps_get_display_state.h"

enum ps_status ps_graphics_clear(struct ps_passion *this,
        struct ps_color *color
)
{
        PS_CHECK(this, PS_STATUS_INVALID_ARGUMENT);

        PS_GET_DISPLAY_STATE(state);

        struct ps_color *color_to_use = color ?
                color : &state->background_color;

        glClearColor((GLclampf)color_to_use->red,
                (GLclampf)color_to_use->green,
                (GLclampf)color_to_use->blue,
                (GLclampf)color_to_use->alpha
        );
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

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