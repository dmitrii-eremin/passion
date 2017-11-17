#ifndef LIBPASSION_INCLUDE_MODULES_PS_EVENT_H_
#define LIBPASSION_INCLUDE_MODULES_PS_EVENT_H_
#include "../utils/ps_api.h"
#include "../utils/ps_status.h"

#include "event/ps_event_data.h"

struct ps_passion;

struct ps_event {
        void *stub;
};

PS_PRIVATE_API enum ps_status ps_event_initialize(
        struct ps_passion *this
);

PS_PRIVATE_API enum ps_status ps_event_deinitialize(
        struct ps_passion *this
);

PS_PUBLIC_API enum ps_status ps_event_pump(
        struct ps_passion *this
);

PS_PUBLIC_API enum ps_status ps_event_poll(
        struct ps_passion *this,
        struct ps_event_data **event
);

#endif