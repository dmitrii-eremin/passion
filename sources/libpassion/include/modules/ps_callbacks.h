#ifndef LIBPASSION_INCLUDE_MODULES_PS_CALLBACKS_H_
#define LIBPASSION_INCLUDE_MODULES_PS_CALLBACKS_H_
#include <stdbool.h>
#include <stdint.h>

#include "../ps_config.h"
#include "../utils/ps_api.h"
#include "../utils/ps_status.h"

#define PS_CALLBACK_SET(X, M, F) X->callbacks.M = F;
#define PS_CALLBACK_RUN(X, M, ...) X->callbacks.M(X, __VA_ARGS__);

struct ps_passion;

struct ps_callbacks {
        enum ps_status (*run)(struct ps_passion *this);

        enum ps_status (*draw)(struct ps_passion *this);
        enum ps_status (*load)(struct ps_passion *this, 
                int argc, char **argv
        );
        enum ps_status (*quit)(struct ps_passion *this, bool *prevent);

        enum ps_status (*focus)(struct ps_passion *this, bool is_focused);

        enum ps_status (*keypressed)(struct ps_passion *this, 
                enum ps_keycode key, enum ps_scancode scancode, 
                bool is_repeat);

        enum ps_status (*keyreleased)(struct ps_passion *this,
                enum ps_keycode key, enum ps_scancode scancode);

        enum ps_status (*mousefocus)(struct ps_passion *this, bool is_focused);

        enum ps_status (*mousemoved)(struct ps_passion *this,
                int16_t x, int16_t y, 
                int16_t dx, int16_t dy, bool is_touch);

        enum ps_status (*mousepressed)(struct ps_passion *this,
                uint16_t x, uint16_t y, enum ps_mouse_button button, 
                bool is_touch);

        enum ps_status (*mousereleased)(struct ps_passion *this,
                uint16_t x, uint16_t y, enum ps_mouse_button button,
                bool is_touch);

        enum ps_status (*resize)(struct ps_passion *this, 
                uint16_t width, uint16_t height);

        enum ps_status (*update)(struct ps_passion *this, double dt);

        enum ps_status (*visible)(struct ps_passion *this, bool is_visible);

        enum ps_status (*wheelmoved)(struct ps_passion *this,
                uint16_t dx, uint16_t dy);
};

PS_PRIVATE_API enum ps_status ps_callbacks_initialize(
        struct ps_passion *this
);

PS_PRIVATE_API enum ps_status ps_callbacks_deinitialize(
        struct ps_passion *this
);

#endif