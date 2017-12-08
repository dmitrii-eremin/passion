#include <stdarg.h>

#include <passion.h>

#include <SDL.h>

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

enum ps_status ps_graphics_points(struct ps_passion *this,
        uint32_t count,
        ...
)
{
        PS_CHECK(this, PS_STATUS_INVALID_ARGUMENT);
        if (count == 0) {
                return PS_STATUS_SUCCESS;
        }
        
        double *coords = malloc(count * 2 * sizeof(double));

        va_list ap;
        va_start(ap, count);
        for (uint32_t i = 0; i < 2 * count; i += 2) {
                coords[i + 0] = va_arg(ap, double);
                coords[i + 1] = va_arg(ap, double);
        }
        va_end(ap);

        glVertexAttribPointer(PS_VERTEX_ATTRIB_POS, 2, 
                GL_DOUBLE, GL_FALSE, 0, coords);

        ps_ogl_draw_arrays(this, GL_POINTS, 0, count);

        free(coords);

        return PS_STATUS_SUCCESS;
}

enum ps_status ps_graphics_present(struct ps_passion *this)
{
        PS_CHECK(this, PS_STATUS_INVALID_ARGUMENT);

        bool active = false;
        PS_STATUS_ASSERT(ps_graphics_is_active(this, &active));

        if (active) {
                SDL_Window *sdl_window = this->window.window;
                if (sdl_window) {
                        SDL_GL_SwapWindow(sdl_window);
                        PS_STATUS_ASSERT(
                                ps_reset_graphics_stats(&this->graphics.stats)
                        );
                }
        }

        return PS_STATUS_SUCCESS;
}