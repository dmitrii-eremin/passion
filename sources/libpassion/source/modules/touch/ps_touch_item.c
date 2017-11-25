#include <stdlib.h>
#include <string.h>

#include <utils/ps_list.h>

#include <modules/touch/ps_touch_item.h>

PS_DECLARE_LIST(
        ps_touch_list,
        ps_touch_item,
        struct ps_touch_data
);