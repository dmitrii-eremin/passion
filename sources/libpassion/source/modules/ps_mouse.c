#include <passion.h>

#include <SDL.h>

enum ps_status ps_mouse_initialize(struct ps_passion *this)
{
        PS_CHECK(this, PS_STATUS_INVALID_ARGUMENT);

        this->mouse.stub = NULL;

        return PS_STATUS_SUCCESS;
}

enum ps_status ps_mouse_deinitialize(struct ps_passion *this)
{
        if (!this) {
                return PS_STATUS_SUCCESS;
        }

        return PS_STATUS_SUCCESS;
}

enum ps_status ps_mouse_get_position(struct ps_passion *this,
        uint16_t *x, uint16_t *y
)
{
        PS_CHECK(this && (x || y), PS_STATUS_INVALID_ARGUMENT);

        int int_x = 0;
        int int_y = 0;
        SDL_GetMouseState(&int_x, &int_y);

        if (x)
                *x = (uint16_t)int_x;
        if (y)
                *y = (uint16_t)int_y;

        return PS_STATUS_SUCCESS;
}

enum ps_status ps_mouse_get_x(struct ps_passion *this,
        uint16_t *x
)
{
        PS_CHECK(this && x, PS_STATUS_INVALID_ARGUMENT);

        uint16_t y = 0;
        return ps_mouse_get_position(this, x, &y);
}

enum ps_status ps_mouse_get_y(struct ps_passion *this,
        uint16_t *y
)
{
        PS_CHECK(this && y, PS_STATUS_INVALID_ARGUMENT);

        uint16_t x = 0;
        return ps_mouse_get_position(this, &x, y);
}

enum ps_status ps_mouse_is_down(struct ps_passion *this,
        enum ps_mouse_button button,
        bool *is_down
)
{
        PS_CHECK(this && is_down, PS_STATUS_INVALID_ARGUMENT);

        Uint32 buttonstate = SDL_GetMouseState(NULL, NULL);

        *is_down = (buttonstate && SDL_BUTTON(button)) != 0;

        return PS_STATUS_SUCCESS;
}

enum ps_status ps_mouse_is_grabbed(struct ps_passion *this,
        bool *grabbed
)
{
        PS_CHECK(this && grabbed, PS_STATUS_INVALID_ARGUMENT);

        SDL_Window *handle = (SDL_Window*)this->window.window;
        if (!handle) {
                return PS_STATUS_NOT_INITIALIZED;
        }

        *grabbed = SDL_GetWindowGrab(handle) != SDL_FALSE;

        return PS_STATUS_SUCCESS;
}

enum ps_status ps_mouse_is_relative_mode(struct ps_passion *this,
        bool *relative_mode
)
{
        PS_CHECK(this && relative_mode, PS_STATUS_INVALID_ARGUMENT);

        *relative_mode = SDL_GetRelativeMouseMode() != SDL_FALSE;

        return PS_STATUS_SUCCESS;
}

enum ps_status ps_mouse_is_visible(struct ps_passion *this,
        bool *visible
)
{
        PS_CHECK(this && visible, PS_STATUS_INVALID_ARGUMENT);

        *visible = SDL_ShowCursor(SDL_QUERY) == SDL_ENABLE;

        return PS_STATUS_SUCCESS;
}

enum ps_status ps_mouse_set_grabbed(struct ps_passion *this,
        bool grabbed
)
{
        PS_CHECK(this, PS_STATUS_INVALID_ARGUMENT);

        SDL_Window *handle = (SDL_Window*)this->window.window;
        if (!handle) {
                return PS_STATUS_NOT_INITIALIZED;
        }

        SDL_SetWindowGrab(handle, (SDL_bool)grabbed);

        return PS_STATUS_SUCCESS;
}

enum ps_status ps_mouse_set_position(struct ps_passion *this,
        uint16_t x, uint16_t y
)
{
        PS_CHECK(this, PS_STATUS_INVALID_ARGUMENT);

        SDL_Window *handle = (SDL_Window*)this->window.window;
        if (!handle) {
                return PS_STATUS_NOT_INITIALIZED;
        }

        SDL_WarpMouseInWindow(handle, (int)x, (int)y);
        SDL_PumpEvents();

        return PS_STATUS_SUCCESS;
}

enum ps_status ps_mouse_set_relative_mode(struct ps_passion *this,
        bool relative_mode
)
{
        PS_CHECK(this, PS_STATUS_INVALID_ARGUMENT);

        int ret = 0;
        ret = SDL_SetRelativeMouseMode(relative_mode ? SDL_TRUE : SDL_FALSE);
        if (ret == -1) {
                return PS_STATUS_NOT_SUPPORTED;
        }

        return PS_STATUS_SUCCESS;
}

enum ps_status ps_mouse_set_visible(struct ps_passion *this,
        bool visible
)
{
        PS_CHECK(this, PS_STATUS_INVALID_ARGUMENT);

        SDL_ShowCursor(visible ? SDL_ENABLE : SDL_DISABLE);

        return PS_STATUS_SUCCESS;
}

enum ps_status ps_mouse_set_x(struct ps_passion *this,
        uint16_t x
)
{
        PS_CHECK(this, PS_STATUS_INVALID_ARGUMENT);

        uint16_t current_x = 0;
        uint16_t current_y = 0;

        PS_STATUS_ASSERT(ps_mouse_get_position(this, &current_x, &current_y));
        return ps_mouse_set_position(this, x, current_y);
}

enum ps_status ps_mouse_set_y(struct ps_passion *this,
        uint16_t y
)
{
        PS_CHECK(this, PS_STATUS_INVALID_ARGUMENT);

        uint16_t current_x = 0;
        uint16_t current_y = 0;

        PS_STATUS_ASSERT(ps_mouse_get_position(this, &current_x, &current_y));
        return ps_mouse_set_position(this, current_x, y);
}
