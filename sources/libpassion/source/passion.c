#include <passion.h>

#include <stdlib.h>

enum ps_status ps_get_version(struct ps_passion *this, ps_version *version)
{
        PS_CHECK(this && version, PS_STATUS_INVALID_ARGUMENT);

        *version = PS_VERSION_CURRENT;

        return PS_STATUS_SUCCESS;
}