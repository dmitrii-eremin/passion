#include "../include/passion.h"

enum ps_status conf(struct ps_config *t)
{
        t->window.width = 1280;
        t->window.height = 720;
        t->window.resizable = true;
        return PS_STATUS_SUCCESS;
}

enum ps_status load(struct ps_passion *this, int argc, char **argv)
{
        return PS_STATUS_SUCCESS;
}

enum ps_status keypressed(struct ps_passion *this, enum ps_keycode key,
        enum ps_scancode scancode, bool is_repeat)
{
        bool lshift = false;
        ps_keyboard_is_scancode_down(this, PS_SCANCODE_LSHIFT, &lshift);
        if (scancode == PS_SCANCODE_ESCAPE && lshift) {
                ps_event_quit(this);
        }

        if (scancode == PS_SCANCODE_SPACE) {
                ps_graphics_set_background_color(this, 1, 0, 0, 1);
        }

        return PS_STATUS_SUCCESS;
}

enum ps_status mousereleased(struct ps_passion *this, uint16_t x, uint16_t y,
        enum ps_mouse_button button, bool is_touch)
{
        PS_CHECK(this, PS_STATUS_INVALID_ARGUMENT);

        if (button == PS_MOUSE_BUTTON_RIGHT) {
                ps_event_quit(this);
        }

        return PS_STATUS_SUCCESS;
}

int main(int argc, char **argv)
{        
        struct ps_context ctx = {
                .startup_args = {
                        .argc = argc, .argv = argv
                },
                .conf = conf
        };

        struct ps_passion *passion = NULL;

        ps_create_passion(PS_VERSION_CURRENT, &ctx, &passion);

        PS_CALLBACK_SET(passion, load, load);
        PS_CALLBACK_SET(passion, keypressed, keypressed);
        PS_CALLBACK_SET(passion, mousereleased, mousereleased);

        ps_run(passion);

        ps_release_passion(passion);

        return 0;
}