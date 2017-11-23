#include <ps_config.h>

#include <string.h>

enum ps_status ps_create_default_config(struct ps_config *conf)
{
        PS_CHECK(conf, PS_STATUS_INVALID_ARGUMENT);

        struct ps_config deflt = {
                .window = {
                        .width = 800,
                        .height = 600,

                        .fullscreen = false,
                        .fullscreen_type = PS_FULLSCREEN_TYPE_DESKTOP,

                        .display = 0,

                        .x = 0, .y = 0,

                        .centered = true,
                        .resizable = false,
                        .borderless = false,
                        .highdpi = false,
                }
        };

        memcpy(conf, &deflt, sizeof(struct ps_config));

        return PS_STATUS_SUCCESS;
}