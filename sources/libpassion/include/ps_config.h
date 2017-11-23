#ifndef LIBPASSION_INCLUDE_PS_CONFIG_H_
#define LIBPASSION_INCLUDE_PS_CONFIG_H_
#include <stdbool.h>
#include <stdint.h>

#include "utils/ps_api.h"
#include "utils/ps_check.h"
#include "utils/ps_status.h"

#include "modules/window/ps_fullscreen_type.h"

struct ps_config {
        struct {
                uint16_t width;
                uint16_t height;

                bool fullscreen;
                enum ps_fullscreen_type fullscreen_type;

                int display;

                int x, y;

                bool centered;
                bool resizable;
                bool borderless;
                bool highdpi;
        } window;
};

PS_PRIVATE_API enum ps_status ps_create_default_config(struct ps_config *conf);

#endif