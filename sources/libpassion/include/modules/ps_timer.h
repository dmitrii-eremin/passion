#ifndef LIBPASSION_INCLUDE_MODULES_PS_TIMER_H_
#define LIBPASSION_INCLUDE_MODULES_PS_TIMER_H_
#include <stdint.h>

#include "../utils/ps_api.h"
#include "../utils/ps_platform.h"
#include "../utils/ps_status.h"

#include "timer/ps_time.h"

struct ps_passion;

struct ps_timer {
        uint32_t fps;
        uint32_t frames;

        ps_time current_time;
        ps_time previous_time;

        ps_time previous_fps_update;
        ps_time fps_update_frequency;

        double average_delta;        
        double current_delta;
};

PS_PRIVATE_API enum ps_status ps_timer_initialize(
        struct ps_passion *this
);

PS_PRIVATE_API enum ps_status ps_timer_deinitialize(
        struct ps_passion *this
);

PS_PRIVATE_API enum ps_status ps_timer_get_timer_period(
        struct ps_passion *this,
        double *period
);

PS_PUBLIC_API enum ps_status ps_timer_get_average_delta(
        struct ps_passion *this,
        double *average_delta
);

PS_PUBLIC_API enum ps_status ps_timer_get_delta(
        struct ps_passion *this,
        double *delta
);

PS_PUBLIC_API enum ps_status ps_timer_get_fps(
        struct ps_passion *this,
        uint32_t *fps
);

PS_PUBLIC_API enum ps_status ps_timer_get_time(
        struct ps_passion *this,
        ps_time *time
);

PS_PUBLIC_API enum ps_status ps_timer_sleep(
        struct ps_passion *this,
        double seconds
);

PS_PUBLIC_API enum ps_status ps_timer_step(
        struct ps_passion *this
);

#endif