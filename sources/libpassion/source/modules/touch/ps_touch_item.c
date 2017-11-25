#include <stdlib.h>
#include <string.h>

#include <utils/ps_list.h>

#include <modules/touch/ps_touch_item.h>

PS_DECLARE_LIST(
        ps_touch_list,
        ps_touch_item,
        struct ps_touch_data
);

bool ps_touch_item_comparator(
        struct ps_touch_data *item,
        void *userdata
)
{
        if (!item || !userdata) {
                return false;
        }

        struct ps_touch_data *user_item = (struct ps_touch_data *)userdata;
        return user_item->id == item->id;
}
