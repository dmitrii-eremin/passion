#include <stdbool.h>

#include <passion.h>

#include <stdio.h>

enum ps_status run(struct ps_passion *this)
{
        PS_CHECK(this, PS_STATUS_INVALID_ARGUMENT);

        ps_time time = { 0 };
        PS_STATUS_ASSERT(ps_timer_get_time(this, &time));
        PS_STATUS_ASSERT(ps_math_set_random_seed(this, (ps_random_seed)time));

        int argc = this->context.startup_args.argc - 1;
        char **argv = argc > 0 ? this->context.startup_args.argv + 1 : NULL;
        PS_CALL_CALLBACK(this, load, (this, argc, argv));

        PS_STATUS_ASSERT(ps_timer_step(this));

        double dt = 0.0;
        while (true) {
                PS_STATUS_ASSERT(ps_timer_step(this));
                PS_STATUS_ASSERT(ps_timer_get_delta(this, &dt));

                PS_STATUS_ASSERT(ps_timer_sleep(this, 0.001));
        }

        return PS_STATUS_SUCCESS;
}

enum ps_status load(struct ps_passion *this, int argc, char **argv)
{
        PS_CHECK(this, PS_STATUS_INVALID_ARGUMENT);

        return PS_STATUS_SUCCESS;
}

enum ps_status ps_callbacks_initialize(struct ps_passion *this)
{
        PS_CHECK(this, PS_STATUS_INVALID_ARGUMENT);

        PS_SET_CALLBACK(this, run, run);
        PS_SET_CALLBACK(this, load, load);

        return PS_STATUS_SUCCESS;
}

enum ps_status ps_callbacks_deinitialize(struct ps_passion *this)
{
        if (!this) {
                return PS_STATUS_SUCCESS;
        }
        return PS_STATUS_SUCCESS;
}