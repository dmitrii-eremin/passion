#ifndef LIBPASSION_INCLUDE_MODULES_PS_TOUCH_H_
#define LIBPASSION_INCLUDE_MODULES_PS_TOUCH_H_
#include <stdint.h>

#include "../utils/ps_api.h"
#include "../utils/ps_status.h"

#include "touch/ps_touch_data.h"
#include "touch/ps_touch_id.h"
#include "touch/ps_touch_item.h"
#include "touch/ps_touch_pressure.h"

struct ps_touch {
        struct ps_touch_item *touches;
};

PS_PRIVATE_API enum ps_status ps_touch_initialize(
        struct ps_passion *this
);

PS_PRIVATE_API enum ps_status ps_touch_deinitialize(
        struct ps_passion *this
);

PS_PUBLIC_API enum ps_status ps_touch_get_position(
        struct ps_passion *this,
        ps_touch_id id,
        uint16_t *x, uint16_t *y
);

PS_PUBLIC_API enum ps_status ps_touch_get_pressure(
        struct ps_passion *this,
        ps_touch_id id,
        ps_touch_pressure *pressure
);

PS_PUBLIC_API enum ps_status ps_touch_get_touches(
        struct ps_passion *this,
        ps_touch_id *touches,
        uint32_t *count
);

#endif