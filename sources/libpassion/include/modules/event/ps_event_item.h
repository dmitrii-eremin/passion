#ifndef LIBPASSION_INCLUDE_MODULES_PS_EVENT_PS_EVENT_ITEM_H_
#define LIBPASSION_INCLUDE_MODULES_PS_EVENT_PS_EVENT_ITEM_H_
#include "ps_event_data.h"

#include "../utils/ps_api.h"
#include "../utils/ps_status.h"

struct ps_event_item {
        struct ps_event_data data;
        struct ps_event_item *next;
};

PS_PRIVATE_API enum ps_status ps_events_list_clear(
        struct ps_event_item **list
);

PS_PRIVATE_API enum ps_status ps_events_list_push(
        struct ps_event_item **list,
        struct ps_event_data *event
);

PS_PRIVATE_API enum ps_status ps_events_list_pop(
        struct ps_event_item **list,
        struct ps_event_data *event        
);

#endif