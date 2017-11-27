#include <passion.h>

#include <SDL_mouse.h>

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

        return PS_STATUS_SUCCESS;
}

enum ps_status ps_mouse_get_relative_mode(struct ps_passion *this,
        bool *relative_mode
)
{
        PS_CHECK(this && relative_mode, PS_STATUS_INVALID_ARGUMENT);

        return PS_STATUS_SUCCESS;
}

enum ps_status ps_mouse_get_x(struct ps_passion *this,
        uint16_t *x
)
{
        PS_CHECK(this && x, PS_STATUS_INVALID_ARGUMENT);

        return PS_STATUS_SUCCESS;
}

enum ps_status ps_mouse_get_y(struct ps_passion *this,
        uint16_t *y
)
{
        PS_CHECK(this && y, PS_STATUS_INVALID_ARGUMENT);

        return PS_STATUS_SUCCESS;
}

enum ps_status ps_mouse_is_down(struct ps_passion *this,
        enum ps_mouse_button button
)
{
        PS_CHECK(this, PS_STATUS_INVALID_ARGUMENT);

        return PS_STATUS_SUCCESS;
}

enum ps_status ps_mouse_is_grabbed(struct ps_passion *this,
        bool *grabbed
)
{
        PS_CHECK(this && grabbed, PS_STATUS_INVALID_ARGUMENT);

        return PS_STATUS_SUCCESS;
}

enum ps_status ps_mouse_is_visible(struct ps_passion *this,
        bool *visible
)
{
        PS_CHECK(this && visible, PS_STATUS_INVALID_ARGUMENT);

        return PS_STATUS_SUCCESS;
}

enum ps_status ps_mouse_set_grabbed(struct ps_passion *this,
        bool grabbed
)
{
        PS_CHECK(this, PS_STATUS_INVALID_ARGUMENT);

        return PS_STATUS_SUCCESS;
}

enum ps_status ps_mouse_set_position(struct ps_passion *this,
        uint16_t x, uint16_t y
)
{
        PS_CHECK(this, PS_STATUS_INVALID_ARGUMENT);

        return PS_STATUS_SUCCESS;
}

enum ps_status ps_mouse_set_relative_mode(struct ps_passion *this,
        bool relative_mode
)
{
        PS_CHECK(this, PS_STATUS_INVALID_ARGUMENT);

        return PS_STATUS_SUCCESS;
}

enum ps_status ps_mouse_set_visible(struct ps_passion *this,
        bool visible
)
{
        PS_CHECK(this, PS_STATUS_INVALID_ARGUMENT);

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

        return PS_STATUS_SUCCESS;
}

enum ps_status ps_mouse_set_y(struct ps_passion *this,
        uint16_t y
)
{
        PS_CHECK(this, PS_STATUS_INVALID_ARGUMENT);

        return PS_STATUS_SUCCESS;
}
