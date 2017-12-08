#include <passion.h>

enum ps_status ps_reset_graphics_stats(struct ps_graphics_stats *stats)
{
        PS_CHECK(stats, PS_STATUS_INVALID_ARGUMENT);

        stats->draw_calls = 0;

        return PS_STATUS_SUCCESS;
}