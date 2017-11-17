#include <passion.h>

enum ps_status run(struct ps_passion *this)
{
        int argc = this->context.startup_args.argc - 1;
        char **argv = argc > 0 ? this->context.startup_args.argv + 1 : NULL;
        PS_CALL_CALLBACK(this, load, (this, argc, argv));

        return PS_STATUS_SUCCESS;
}

enum ps_status load(struct ps_passion *this, int argc, char **argv)
{
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