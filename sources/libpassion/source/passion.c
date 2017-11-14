#include <passion.h>

#include <stdlib.h>

enum ps_status get_version(struct ps_passion *this, ps_version *version)
{
        PS_CHECK(this && version, PS_STATUS_INVALID_ARGUMENT);

        *version = PS_VERSION_CURRENT;

        return PS_STATUS_SUCCESS;
}

enum ps_status ps_create_passion(struct ps_passion **object)
{
        PS_CHECK(object, PS_STATUS_INVALID_ARGUMENT);

        *object = malloc(sizeof(struct ps_passion));

        (*object)->get_version = get_version;

        return PS_STATUS_SUCCESS;
}

enum ps_status ps_destroy_passion(struct ps_passion *object)
{
        if (!object) {
                return PS_STATUS_SUCCESS;
        }

        free(object);
        return PS_STATUS_SUCCESS;
}