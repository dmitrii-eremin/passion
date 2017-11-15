#include <passion.h>

#include <stdlib.h>

#include <modules/filesystem/ps_filesystem_private.h>

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

        PS_STATUS_ASSERT(ps_create_filesystem(&(*object)->filesystem));

        (*object)->get_version = get_version;

        return PS_STATUS_SUCCESS;
}

enum ps_status ps_destroy_passion(struct ps_passion *object)
{
        if (!object) {
                return PS_STATUS_SUCCESS;
        }

        ps_destroy_filesystem(object->filesystem);

        free(object);
        return PS_STATUS_SUCCESS;
}