#ifndef LIBPASSION_INCLUDE_MODULES_PS_EVENT_PS_EVENT_DATA_H_
#define LIBPASSION_INCLUDE_MODULES_PS_EVENT_PS_EVENT_DATA_H_
#include <stdbool.h>
#include <stdint.h>

#include "ps_event_type.h"
#include "ps_mouse_button.h"
#include "ps_keycode.h"
#include "ps_scancode.h"

struct ps_event_data {
        enum ps_event_type type;
        struct {
                enum ps_keycode key;
                enum ps_scancode scancode;
                bool is_repeat;
        } key;
        struct {
                uint16_t x;
                uint16_t y;
                enum ps_mouse_button button;
                bool is_touch;
        } mouse;
};

#endif