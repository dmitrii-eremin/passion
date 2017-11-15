#ifndef LIBPASSION_INCLUDE_LIBPASSION_H_
#define LIBPASSION_INCLUDE_LIBPASSION_H_

#include "passion.h"

#include "utils/ps_api.h"
#include "utils/ps_check.h"
#include "utils/ps_context.h"
#include "utils/ps_status.h"
#include "utils/ps_version.h"


PS_PUBLIC_API enum ps_status ps_initialize(
        ps_version version,
        struct ps_context *context,
        struct ps_passion **passion
);

PS_PUBLIC_API enum ps_status ps_run(struct ps_passion *passion);

PS_PUBLIC_API enum ps_status ps_deinitialize(
        struct ps_passion *passion
);

#endif