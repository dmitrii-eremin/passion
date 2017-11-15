#ifndef LIBPASSION_INCLUDE_MODULES_PS_FILESYSTEM_PS_FILESYSTEM_PRIVATE_H_
#define LIBPASSION_INCLUDE_MODULES_PS_FILESYSTEM_PS_FILESYSTEM_PRIVATE_H_

#include "../ps_filesystem.h"

#include "utils/ps_api.h"
#include "utils/ps_status.h"


PS_PRIVATE_API enum ps_status ps_create_filesystem(
        struct ps_filesystem **object
);

PS_PRIVATE_API enum ps_status ps_destroy_filesystem(
        struct ps_filesystem *object
);

#endif