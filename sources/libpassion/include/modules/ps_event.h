#ifndef LIBPASSION_INCLUDE_MODULES_PS_EVENT_H_
#define LIBPASSION_INCLUDE_MODULES_PS_EVENT_H_
#include "../utils/ps_api.h"
#include "../utils/ps_status.h"

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

#endif