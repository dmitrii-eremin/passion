#ifndef LIBPASSION_INCLUDE_MODULES_PS_MOUSE_H_
#define LIBPASSION_INCLUDE_MODULES_PS_MOUSE_H_
#include "../utils/ps_api.h"
#include "../utils/ps_status.h"

struct ps_passion;

struct ps_mouse {
        void *stub;
};

PS_PRIVATE_API enum ps_status ps_mouse_initialize(
        struct ps_passion *this
);

PS_PRIVATE_API enum ps_status ps_mouse_deinitialize(
        struct ps_passion *this
);

PS_PUBLIC_API enum ps_status ps_mouse_get_position(
        struct ps_passion *this,
        uint16_t *x, uint16_t *y
);

PS_PUBLIC_API enum ps_status ps_mouse_get_x(
        struct ps_passion *this,
        uint16_t *x
);

PS_PUBLIC_API enum ps_status ps_mouse_get_y(
        struct ps_passion *this,
        uint16_t *y
);

PS_PUBLIC_API enum ps_status ps_mouse_is_down(
        struct ps_passion *this,
        enum ps_mouse_button button,
        bool *is_down
);

PS_PUBLIC_API enum ps_status ps_mouse_is_grabbed(
        struct ps_passion *this,
        bool *grabbed
);

PS_PUBLIC_API enum ps_status ps_mouse_is_relative_mode(
        struct ps_passion *this,
        bool *relative_mode
);

PS_PUBLIC_API enum ps_status ps_mouse_is_visible(
        struct ps_passion *this,
        bool *visible
);

PS_PUBLIC_API enum ps_status ps_mouse_set_grabbed(
        struct ps_passion *this,
        bool grabbed
);

PS_PUBLIC_API enum ps_status ps_mouse_set_position(
        struct ps_passion *this,
        uint16_t x, uint16_t y
);

PS_PUBLIC_API enum ps_status ps_mouse_set_relative_mode(
        struct ps_passion *this,
        bool relative_mode
);

PS_PUBLIC_API enum ps_status ps_mouse_set_visible(
        struct ps_passion *this,
        bool visible
);

PS_PUBLIC_API enum ps_status ps_mouse_set_x(
        struct ps_passion *this,
        uint16_t x
);

PS_PUBLIC_API enum ps_status ps_mouse_set_y(
        struct ps_passion *this,
        uint16_t y
);

#endif