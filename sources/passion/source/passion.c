#include "../include/passion.h"

enum ps_status load(struct ps_passion *this, int argc, char **argv)
{
        ps_window_set_title(this, "Passion 0.1.0");
        ps_window_set_mode(this, 1280, 720, NULL);
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

        ps_run(passion);

        ps_release_passion(passion);

        return 0;
}