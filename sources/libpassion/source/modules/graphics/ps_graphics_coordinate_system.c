#include <passion.h>

#include <SDL.h>
#include <SDL_opengl.h>

#include "../../../include/modules/graphics/ps_get_display_state.h"

enum ps_status ps_graphics_origin(struct ps_passion *this)
{
        PS_CHECK(this, PS_STATUS_INVALID_ARGUMENT);
        return PS_STATUS_SUCCESS;
}