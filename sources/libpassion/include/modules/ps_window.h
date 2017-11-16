#ifndef LIBPASSION_INCLUDE_MODULES_PS_WINDOW_H_
#define LIBPASSION_INCLUDE_MODULES_PS_WINDOW_H_
#include "../utils/ps_api.h"
#include "../utils/ps_status.h"

struct ps_passion;

struct ps_window {
        void *stub;
};

PS_PRIVATE_API enum ps_status ps_window_initialize(
        struct ps_passion *this
);

PS_PRIVATE_API enum ps_status ps_window_deinitialize(
        struct ps_passion *this
);

#endif