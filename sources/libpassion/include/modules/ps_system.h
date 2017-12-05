#ifndef LIBPASSION_INCLUDE_MODULES_PS_SYSTEM_H_
#define LIBPASSION_INCLUDE_MODULES_PS_SYSTEM_H_
#include <stdint.h>

#include "../utils/ps_api.h"
#include "../utils/ps_status.h"

#include "system/ps_os.h"
#include "system/ps_power_state.h"

struct ps_system {
        void *stub;
};

PS_PRIVATE_API enum ps_status ps_system_initialize(
        struct ps_passion *this
);

PS_PRIVATE_API enum ps_status ps_system_deinitialize(
        struct ps_passion *this
);

PS_PUBLIC_API enum ps_status ps_system_get_clipboard_text(
        struct ps_passion *this,
        char *text, uint32_t *count
);

PS_PUBLIC_API enum ps_status ps_system_get_os(
        struct ps_passion *this,
        enum ps_os *os
);

PS_PUBLIC_API enum ps_status ps_system_get_power_info(
        struct ps_passion *this,
        enum ps_power_state *state,
        uint64_t *percents,
        uint64_t *seconds
);

PS_PUBLIC_API enum ps_status ps_system_get_processor_count(
        struct ps_passion *this,
        uint16_t *cpu_count
);

PS_PUBLIC_API enum ps_status ps_system_set_clipboard_text(
        struct ps_passion *this,
        const char *text
);

PS_PUBLIC_API enum ps_status ps_system_vibrate(
        struct ps_passion *this,
        double seconds
);

#endif