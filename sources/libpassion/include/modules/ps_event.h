#ifndef LIBPASSION_INCLUDE_MODULES_PS_EVENT_H_
#define LIBPASSION_INCLUDE_MODULES_PS_EVENT_H_
#include "../utils/ps_api.h"
#include "../utils/ps_status.h"

#include "event/ps_event_data.h"
#include "event/ps_event_item.h"
#include "keyboard/ps_keycode.h"
#include "keyboard/ps_scancode.h"

struct ps_passion;

struct ps_event {
        struct ps_event_item *events;
};

PS_PRIVATE_API enum ps_status ps_event_initialize(
        struct ps_passion *this
);

PS_PRIVATE_API enum ps_status ps_event_deinitialize(
        struct ps_passion *this
);

PS_PUBLIC_API enum ps_status ps_event_clear(
        struct ps_passion *this
);

PS_PUBLIC_API enum ps_status ps_event_poll(
        struct ps_passion *this,
        struct ps_event_data *event
);

PS_PUBLIC_API enum ps_status ps_event_pump(
        struct ps_passion *this
);

PS_PUBLIC_API enum ps_status ps_event_push(
        struct ps_passion *this,
        struct ps_event_data *event
);

PS_PUBLIC_API enum ps_status ps_event_quit(
        struct ps_passion *this
);

PS_PUBLIC_API enum ps_status ps_event_wait(
        struct ps_passion *this,
        struct ps_event_data **event
);

#endif