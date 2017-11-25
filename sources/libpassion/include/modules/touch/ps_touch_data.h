#ifndef LIBPASSION_INCLUDE_MODULES_TOUCH_PS_TOUCH_DATA_H_
#define LIBPASSION_INCLUDE_MODULES_TOUCH_PS_TOUCH_DATA_H_
#include <stdint.h>

#include "ps_touch_id.h"
#include "ps_touch_pressure.h"

struct ps_touch_data {
        ps_touch_id id;

        uint16_t x;
        uint16_t y;
        ps_touch_pressure pressure;
};

#endif