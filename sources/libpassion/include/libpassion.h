#ifndef LIBPASSION_INCLUDE_LIBPASSION_H_
#define LIBPASSION_INCLUDE_LIBPASSION_H_

#include "utils/ps_api.h"
#include "utils/ps_status.h"
#include "utils/ps_version.h"


#define PS_VERSION_CURRENT PS_VERSION_CREATE(0, 1, 0)


PS_PUBLIC_API enum ps_status ps_initialize(
        ps_version version
);

PS_PUBLIC_API enum ps_status ps_deinitialize();

#endif