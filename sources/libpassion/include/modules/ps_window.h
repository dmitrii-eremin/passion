#ifndef LIBPASSION_INCLUDE_MODULES_PS_WINDOW_H_
#define LIBPASSION_INCLUDE_MODULES_PS_WINDOW_H_
#include <stdint.h>

#include "../utils/ps_api.h"
#include "../utils/ps_status.h"

#include "window/ps_window_attributes.h"

typedef void* ps_window_handle;
typedef void* ps_context_handle;

struct ps_passion;

struct ps_window {        
        ps_window_handle window;
        ps_context_handle context;

        char *title;
};

PS_PRIVATE_API enum ps_status ps_window_initialize(
        struct ps_passion *this
);

PS_PRIVATE_API enum ps_status ps_window_deinitialize(
        struct ps_passion *this
);

PS_PUBLIC_API enum ps_status ps_window_close(struct ps_passion *this);

PS_PUBLIC_API enum ps_status ps_window_get_title(
        struct ps_passion *this,
        char *title, uint32_t count
);

PS_PUBLIC_API enum ps_status ps_window_set_mode(
        struct ps_passion *this,
        uint16_t width, uint16_t height, 
        struct ps_window_attributes *attribs
);

PS_PUBLIC_API enum ps_status ps_window_set_title(
        struct ps_passion *this,
        const char *title
);

#endif