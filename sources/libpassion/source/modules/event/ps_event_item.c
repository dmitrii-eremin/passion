#include <stdlib.h>
#include <string.h>

#include <utils/ps_list.h>

#include <modules/event/ps_event_item.h>

PS_DECLARE_LIST(
        ps_events_list,
        ps_event_item,
        struct ps_event_data
);