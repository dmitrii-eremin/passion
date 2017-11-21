#ifndef LIBPASSION_INCLUDE_MODULES_PS_EVENT_PS_EVENT_DATA_H_
#define LIBPASSION_INCLUDE_MODULES_PS_EVENT_PS_EVENT_DATA_H_
#include <stdbool.h>

#include "ps_event_type.h"
#include "ps_keycode.h"
#include "ps_scancode.h"

struct ps_event_data {
        enum ps_event_type type;
        struct {
                enum ps_keycode key;
                enum ps_scancode scancode;
                bool is_repeat;
        } key;
};

#endif