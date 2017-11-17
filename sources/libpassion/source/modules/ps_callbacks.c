#include <stdbool.h>

#include <passion.h>

#include <stdio.h>

enum ps_status process_event(struct ps_passion *this, struct ps_event_data *e)
{
        PS_CHECK(this && e, PS_STATUS_INVALID_ARGUMENT);
        switch (e->type) {
        case PS_EVENT_QUIT:
                break;
        default:
                break;
        }
        return PS_STATUS_SUCCESS;
}

enum ps_status run(struct ps_passion *this)
{
        PS_CHECK(this, PS_STATUS_INVALID_ARGUMENT);

        enum ps_status status = PS_STATUS_SUCCESS;

        ps_time time = { 0 };
        PS_STATUS_ASSERT(ps_timer_get_time(this, &time));
        PS_STATUS_ASSERT(ps_math_set_random_seed(this, (ps_random_seed)time));

        int argc = this->context.startup_args.argc - 1;
        char **argv = argc > 0 ? this->context.startup_args.argv + 1 : NULL;
        status = PS_CALLBACK_RUN(this, load, argc, argv);
        PS_STATUS_ASSERT(status);

        PS_STATUS_ASSERT(ps_timer_step(this));

        double dt = 0.0;
        while (true) {
                PS_STATUS_ASSERT(ps_event_pump(this));
                struct ps_event_data event = { 0 };
                do {
                        PS_STATUS_ASSERT(ps_event_poll(this, &event));
                        if (event.type == PS_EVENT_BREAK_POLLING)
                                break;

                        if (event.type == PS_EVENT_QUIT) {
                                bool prevent = false;
                                status = PS_CALLBACK_RUN(this, 
                                        quit, &prevent);
                                PS_STATUS_ASSERT(status);

                                if (!prevent)
                                        return PS_STATUS_SUCCESS;
                        } else {
                                PS_STATUS_ASSERT(process_event(this, &event));
                        }
                } while (event.type != PS_EVENT_BREAK_POLLING);

                PS_STATUS_ASSERT(ps_timer_step(this));
                PS_STATUS_ASSERT(ps_timer_get_delta(this, &dt));

                status = PS_CALLBACK_RUN(this, update, dt);
                PS_STATUS_ASSERT(status);

                bool active = false;
                PS_STATUS_ASSERT(ps_graphics_is_active(this, &active));
                if (active) {
                        PS_STATUS_ASSERT(ps_graphics_clear(this, NULL));
                        PS_STATUS_ASSERT(ps_graphics_origin(this));

                        status = PS_CALLBACK_RUN(this, draw);
                        PS_STATUS_ASSERT(status);

                        PS_STATUS_ASSERT(ps_graphics_present(this));
                }                

                PS_STATUS_ASSERT(ps_timer_sleep(this, 0.001));
        }

        return PS_STATUS_SUCCESS;
}

enum ps_status draw(struct ps_passion *this)
{
        PS_CHECK(this, PS_STATUS_INVALID_ARGUMENT);

        return PS_STATUS_SUCCESS;
}

enum ps_status load(struct ps_passion *this, int argc, char **argv)
{
        PS_CHECK(this, PS_STATUS_INVALID_ARGUMENT);

        return PS_STATUS_SUCCESS;
}

enum ps_status quit(struct ps_passion *this, bool *prevent)
{
        PS_CHECK(this && prevent, PS_STATUS_INVALID_ARGUMENT);

        *prevent = false;

        return PS_STATUS_SUCCESS;
}

enum ps_status update(struct ps_passion *this, double dt)
{
        PS_CHECK(this, PS_STATUS_INVALID_ARGUMENT);

        return PS_STATUS_SUCCESS;
}

enum ps_status ps_callbacks_initialize(struct ps_passion *this)
{
        PS_CHECK(this, PS_STATUS_INVALID_ARGUMENT);

        PS_CALLBACK_SET(this, run, run);
        PS_CALLBACK_SET(this, draw, draw);
        PS_CALLBACK_SET(this, load, load);
        PS_CALLBACK_SET(this, quit, quit);
        PS_CALLBACK_SET(this, update, update);

        return PS_STATUS_SUCCESS;
}

enum ps_status ps_callbacks_deinitialize(struct ps_passion *this)
{
        if (!this) {
                return PS_STATUS_SUCCESS;
        }
        return PS_STATUS_SUCCESS;
}