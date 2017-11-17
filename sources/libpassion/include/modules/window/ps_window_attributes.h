#ifndef LIBPASSION_INCLUDE_MODULES_WINDOW_PS_WINDOW_ATTRIBUTES_H_
#define LIBPASSION_INCLUDE_MODULES_WINDOW_PS_WINDOW_ATTRIBUTES_H_
#include <stdbool.h>
#include <stdint.h>

#include "ps_fullscreen_type.h"

struct ps_window_attributes {
        bool fullscreen;
        enum ps_fullscreen_type fullscreen_type;

        int display;

        int x, y;

        bool centered;
        bool resizable;
        bool borderless;
        bool highdpi;
};

#endif