#ifndef LIBPASSION_INCLUDE_MODULES_PS_EVENT_PS_EVENT_ITEM_H_
#define LIBPASSION_INCLUDE_MODULES_PS_EVENT_PS_EVENT_ITEM_H_
#include "ps_event_data.h"

#include "../utils/ps_api.h"
#include "../utils/ps_list.h"

PS_DEFINE_LIST(
        ps_events_list, 
        ps_event_item, 
        struct ps_event_data, 
        PS_PRIVATE_API
);

#endif