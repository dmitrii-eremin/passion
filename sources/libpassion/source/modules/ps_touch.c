#include <passion.h>

enum ps_status ps_touch_initialize(struct ps_passion *this)
{
        PS_CHECK(this, PS_STATUS_INVALID_ARGUMENT);

        return PS_STATUS_SUCCESS;
}

enum ps_status ps_touch_deinitialize(struct ps_passion *this)
{
        if (!this) {
                return PS_STATUS_SUCCESS;
        }

        return PS_STATUS_SUCCESS;
}

enum ps_status ps_touch_get_position(struct ps_passion *this,
        ps_touch_id id, uint16_t *x, uint16_t *y
)
{
        PS_CHECK(this && (x || y), PS_STATUS_INVALID_ARGUMENT);
        return PS_STATUS_SUCCESS;
}

enum ps_status ps_touch_get_pressure(struct ps_passion *this,
        ps_touch_id id, ps_touch_pressure *pressure
)
{
        PS_CHECK(this && pressure, PS_STATUS_INVALID_ARGUMENT);
        return PS_STATUS_SUCCESS;
}

enum ps_status ps_touch_get_touches(struct ps_passion *this,
        ps_touch_id *touches, uint32_t *count
)
{
        PS_CHECK(this && touches && count, PS_STATUS_INVALID_ARGUMENT);

        return PS_STATUS_SUCCESS;
}