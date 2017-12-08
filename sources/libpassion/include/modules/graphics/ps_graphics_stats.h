#ifndef LIBPASSION_INCLUDE_MODULES_GRAPHICS_PS_GRAPHICS_STATS_H_
#define LIBPASSION_INCLUDE_MODULES_GRAPHICS_PS_GRAPHICS_STATS_H_
#include <stdint.h>

#include "../utils/ps_api.h"
#include "../utils/ps_status.h"

struct ps_graphics_stats {
        uint32_t draw_calls;
};

PS_PRIVATE_API enum ps_status ps_reset_graphics_stats(
        struct ps_graphics_stats *stats
);

#endif