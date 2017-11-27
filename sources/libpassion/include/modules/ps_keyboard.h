#ifndef LIBPASSION_INCLUDE_MODULES_PS_KEYBOARD_H_
#define LIBPASSION_INCLUDE_MODULES_PS_KEYBOARD_H_
#include "../utils/ps_api.h"
#include "../utils/ps_status.h"

#include "keyboard/ps_keycode.h"
#include "keyboard/ps_scancode.h"

struct ps_passion;

struct ps_keyboard {
        bool key_repeat;
};

PS_PRIVATE_API enum ps_status ps_keyboard_initialize(
        struct ps_passion *this
);

PS_PRIVATE_API enum ps_status ps_keyboard_deinitialize(
        struct ps_passion *this
);

PS_PUBLIC_API enum ps_status ps_keyboard_get_key_from_scancode(
        struct ps_passion *this,
        enum ps_scancode scancode,
        enum ps_keycode *keycode
);

PS_PUBLIC_API enum ps_status ps_keyboard_get_scancode_from_key(
        struct ps_passion *this,
        enum ps_keycode keycode,
        enum ps_scancode *scancode
);

PS_PUBLIC_API enum ps_status ps_keyboard_has_key_repeat(
        struct ps_passion *this,
        bool *key_repeat
);

PS_PUBLIC_API enum ps_status ps_keyboard_has_screen_keyboard(
        struct ps_passion *this,
        bool *screen_keyboard
);

PS_PUBLIC_API enum ps_status ps_keyboard_has_text_input(
        struct ps_passion *this,
        bool *text_input
);

PS_PUBLIC_API enum ps_status ps_keyboard_is_down(
        struct ps_passion *this,
        enum ps_keycode key,
        bool *is_down
);

PS_PUBLIC_API enum ps_status ps_keyboard_is_scancode_down(
        struct ps_passion *this,
        enum ps_scancode scancode,
        bool *is_down
);

PS_PUBLIC_API enum ps_status ps_keyboard_set_key_repeat(
        struct ps_passion *this,
        bool key_repeat
);

PS_PUBLIC_API enum ps_status ps_keyboard_set_text_input(
        struct ps_passion *this,
        bool text_input
);

PS_PUBLIC_API enum ps_status ps_keyboard_set_text_input_area(
        struct ps_passion *this,
        bool text_input,
        uint16_t x, uint16_t y, uint16_t w, uint16_t h
);

#endif