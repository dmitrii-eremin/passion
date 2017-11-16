#ifndef LIBPASSION_INCLUDE_PASSION_H_
#define LIBPASSION_INCLUDE_PASSION_H_

#include "modules/ps_callbacks.h"
#include "modules/ps_filesystem.h"

#include "utils/ps_api.h"
#include "utils/ps_check.h"
#include "utils/ps_context.h"
#include "utils/ps_status.h"
#include "utils/ps_version.h"

struct ps_passion {
        struct ps_filesystem filesystem;
        struct ps_callbacks callbacks;

        struct ps_context context;

        int ref_count;
};

PS_PUBLIC_API enum ps_status ps_get_version(struct ps_passion *this, 
        ps_version *version
);

#endif