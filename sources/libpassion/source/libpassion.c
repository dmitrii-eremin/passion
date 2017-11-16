#include <libpassion.h>

#include <string.h>

#include <SDL.h>

struct ps_passion *g_passion = NULL;

enum ps_status ps_create_passion(
        ps_version version, struct ps_context *context, 
        struct ps_passion **passion
)
{
        PS_CHECK(passion && context, PS_STATUS_INVALID_ARGUMENT);

        if (version != PS_VERSION_CURRENT)
                return PS_STATUS_INCOMPATIBLE_VERSION;

        enum ps_status status = PS_STATUS_SUCCESS;

        if (!g_passion) {
                g_passion = malloc(sizeof(struct ps_passion));

                g_passion->ref_count = 0;

                memcpy(&g_passion->context, context, sizeof(struct ps_context));

                status = ps_callbacks_initialize(g_passion);
                if (PS_STATUS_FAILED(status)) {
                        free(g_passion);
                        return status;
                }

                status = ps_filesystem_initialize(g_passion);
                if (PS_STATUS_FAILED(status)) {
                        ps_callbacks_deinitialize(g_passion);
                        free(g_passion);
                        return status;
                }
        }

        return ps_get_passion(passion);
}

enum ps_status ps_get_passion(struct ps_passion **passion)
{
        PS_CHECK(passion, PS_STATUS_INVALID_ARGUMENT);

        if (!g_passion) {
                *passion = NULL;
                return PS_STATUS_NOT_INITIALIZED;
        }

        g_passion->ref_count++;
        *passion = g_passion;
        return PS_STATUS_SUCCESS;
}

enum ps_status ps_release_passion(struct ps_passion *passion)
{
        if (!passion) {
                return PS_STATUS_SUCCESS;
        }

        passion->ref_count--;

        if (passion->ref_count == 0) {
                ps_callbacks_deinitialize(passion);
                ps_filesystem_deinitialize(passion);

                free(passion);

                g_passion = NULL;
        }
        return PS_STATUS_SUCCESS;
}

enum ps_status ps_run(struct ps_passion *passion)
{
        PS_CHECK(passion, PS_STATUS_INVALID_ARGUMENT);

        PS_CHECK(passion->callbacks.run, PS_STATUS_IVALID_OBJECT);
        passion->callbacks.run(passion);

        return PS_STATUS_SUCCESS;
}