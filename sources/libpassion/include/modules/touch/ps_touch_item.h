#ifndef LIBPASSION_INCLUDE_MODULES_TOUCH_PS_TOUCH_ITEM_H_
#define LIBPASSION_INCLUDE_MODULES_TOUCH_PS_TOUCH_ITEM_H_
#include "ps_touch_data.h"

#include "../utils/ps_api.h"
#include "../utils/ps_list.h"

PS_DEFINE_LIST(
        ps_touch_list,
        ps_touch_item,
        struct ps_touch_data,
        PS_PRIVATE_API
);

#endif