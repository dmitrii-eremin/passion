#include <libpassion.h>

#include <string.h>

#include <SDL.h>

enum ps_status ps_initialize(
        ps_version version, struct ps_context *context, 
        struct ps_passion **passion
)
{
        PS_CHECK(passion && context, PS_STATUS_INVALID_ARGUMENT);

        if (version != PS_VERSION_CURRENT)
                return PS_STATUS_INCOMPATIBLE_VERSION;

        enum ps_status status = PS_STATUS_SUCCESS;

        *passion = malloc(sizeof(struct ps_passion));

        memcpy(&(*passion)->context, context, sizeof(struct ps_context));

        status = ps_callbacks_initialize(*passion);
        if (PS_STATUS_FAILED(status)) {
                free(*passion);
                return status;
        }

        status = ps_filesystem_initialize(*passion);
        if (PS_STATUS_FAILED(status)) {
                free(*passion);
                return status;
        }

        return status;
}

enum ps_status ps_run(struct ps_passion *passion)
{
        PS_CHECK(passion, PS_STATUS_INVALID_ARGUMENT);

        PS_CHECK(passion->callbacks.run, PS_STATUS_IVALID_OBJECT);
        passion->callbacks.run(passion);

        return PS_STATUS_SUCCESS;
}

enum ps_status ps_deinitialize(struct ps_passion *passion)
{
        if (!passion) {
                return PS_STATUS_SUCCESS;
        }

        ps_callbacks_deinitialize(passion);
        ps_filesystem_deinitialize(passion);

        free(passion);
        return PS_STATUS_SUCCESS;
}