#include <stdbool.h>

#include <passion.h>

#include <stdio.h>

enum ps_status run(struct ps_passion *this)
{
        PS_CHECK(this, PS_STATUS_INVALID_ARGUMENT);

        enum ps_status status = PS_STATUS_SUCCESS;

        ps_time time = { 0 };
        PS_STATUS_ASSERT(ps_timer_get_time(this, &time));
        PS_STATUS_ASSERT(ps_math_set_random_seed(this, (ps_random_seed)time));

        int argc = this->context.startup_args.argc - 1;
        char **argv = argc > 0 ? this->context.startup_args.argv + 1 : NULL;
        status = PS_CALL_CALLBACK(this, load, argc, argv);
        PS_STATUS_ASSERT(status);

        PS_STATUS_ASSERT(ps_timer_step(this));

        double dt = 0.0;
        while (true) {
                PS_STATUS_ASSERT(ps_timer_step(this));
                PS_STATUS_ASSERT(ps_timer_get_delta(this, &dt));

                status = PS_CALL_CALLBACK(this, update, dt);
                PS_STATUS_ASSERT(status);

                bool active = false;
                PS_STATUS_ASSERT(ps_graphics_is_active(this, &active));
                if (active) {
                        PS_STATUS_ASSERT(ps_graphics_clear(this, NULL));
                        PS_STATUS_ASSERT(ps_graphics_origin(this));

                        status = PS_CALL_CALLBACK(this, draw);
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

enum ps_status update(struct ps_passion *this, double dt)
{
        PS_CHECK(this, PS_STATUS_INVALID_ARGUMENT);

        return PS_STATUS_SUCCESS;
}

enum ps_status ps_callbacks_initialize(struct ps_passion *this)
{
        PS_CHECK(this, PS_STATUS_INVALID_ARGUMENT);

        PS_SET_CALLBACK(this, run, run);
        PS_SET_CALLBACK(this, draw, draw);
        PS_SET_CALLBACK(this, load, load);
        PS_SET_CALLBACK(this, update, update);

        return PS_STATUS_SUCCESS;
}

enum ps_status ps_callbacks_deinitialize(struct ps_passion *this)
{
        if (!this) {
                return PS_STATUS_SUCCESS;
        }
        return PS_STATUS_SUCCESS;
}