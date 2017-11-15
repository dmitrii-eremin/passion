#include <libpassion.h>

#include <SDL.h>

#include <passion.h>

enum ps_status ps_initialize(ps_version version, struct ps_passion **passion)
{
        PS_CHECK(passion, PS_STATUS_INVALID_ARGUMENT);

        if (version != PS_VERSION_CURRENT)
                return PS_STATUS_INCOMPATIBLE_VERSION;

        *passion = malloc(sizeof(struct ps_passion));

        return PS_STATUS_SUCCESS;
}

enum ps_status ps_deinitialize(struct ps_passion *passion)
{
        free(passion);
        return PS_STATUS_SUCCESS;
}