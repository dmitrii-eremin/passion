#ifndef LIBPASSION_INCLUDE_MODULES_PS_MOUSE_H_
#define LIBPASSION_INCLUDE_MODULES_PS_MOUSE_H_
#include "../utils/ps_api.h"
#include "../utils/ps_status.h"

struct ps_passion;

struct ps_mouse {
        void *stub;
};

PS_PRIVATE_API enum ps_status ps_mouse_initialize(
        struct ps_passion *this
);

PS_PRIVATE_API enum ps_status ps_mouse_deinitialize(
        struct ps_passion *this
);

#endif