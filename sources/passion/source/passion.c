#include "../include/passion.h"

enum ps_status load(struct ps_passion *this, int argc, char **argv)
{
        return PS_STATUS_SUCCESS;
}

enum ps_status keypressed(struct ps_passion *this, enum ps_keycode key,
        enum ps_scancode scancode, bool is_repeat)
{
        if (scancode == PS_SCANCODE_ESCAPE) {
                ps_event_quit(this);
        }

        if (scancode == PS_SCANCODE_SPACE) {
                ps_graphics_set_background_color(this, 1, 0, 0, 1);
        }
        return PS_STATUS_SUCCESS;
}

int main(int argc, char **argv)
{        
        struct ps_context ctx = {
                .startup_args = {
                        .argc = argc, .argv = argv
                }
        };

        struct ps_passion *passion = NULL;

        ps_create_passion(PS_VERSION_CURRENT, &ctx, &passion);

        PS_CALLBACK_SET(passion, load, load);
        PS_CALLBACK_SET(passion, keypressed, keypressed);

        ps_run(passion);

        ps_release_passion(passion);

        return 0;
}