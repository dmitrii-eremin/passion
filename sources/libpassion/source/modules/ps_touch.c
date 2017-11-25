#include <passion.h>

enum ps_status ps_touch_initialize(struct ps_passion *this)
{
        PS_CHECK(this, PS_STATUS_INVALID_ARGUMENT);

        this->touch.touches = NULL;

        return PS_STATUS_SUCCESS;
}

enum ps_status ps_touch_deinitialize(struct ps_passion *this)
{
        if (!this) {
                return PS_STATUS_SUCCESS;
        }

        ps_touch_list_clear(&this->touch.touches);

        return PS_STATUS_SUCCESS;
}

enum ps_status ps_touch_get_position(struct ps_passion *this,
        ps_touch_id id, uint16_t *x, uint16_t *y
)
{
        PS_CHECK(this && (x || y), PS_STATUS_INVALID_ARGUMENT);

        struct ps_touch_data item_to_find = { .id = id, 0 };
        
        struct ps_touch_data *item = NULL;
        PS_STATUS_ASSERT(ps_touch_list_find(&this->touch.touches, &item,
                &item_to_find, ps_touch_item_comparator));

        if (!item)
                return PS_STATUS_NOT_FOUND;

        if (x)
                *x = item->x;
        if (y)
                *y = item->y;

        return PS_STATUS_SUCCESS;
}

enum ps_status ps_touch_get_pressure(struct ps_passion *this,
        ps_touch_id id, ps_touch_pressure *pressure
)
{
        PS_CHECK(this && pressure, PS_STATUS_INVALID_ARGUMENT);

        struct ps_touch_data item_to_find = { .id = id, 0 };

        struct ps_touch_data *item = NULL;
        PS_STATUS_ASSERT(ps_touch_list_find(&this->touch.touches, &item,
                &item_to_find, ps_touch_item_comparator));

        if (!item)
                return PS_STATUS_NOT_FOUND;

        *pressure = item->pressure;

        return PS_STATUS_SUCCESS;
}

enum ps_status ps_touch_get_touches(struct ps_passion *this,
        ps_touch_id *touches, uint32_t *count
)
{
        PS_CHECK(this && touches && count, PS_STATUS_INVALID_ARGUMENT);

        struct ps_touch_item *head = this->touch.touches;

        uint32_t i = 0;
        while (i < *count && head) {
                touches[i] = head->data.id;

                head = head->next;
                i++;
        }

        *count = i;

        return PS_STATUS_SUCCESS;
}