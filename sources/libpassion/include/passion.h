#ifndef LIBPASSION_INCLUDE_PASSION_H_
#define LIBPASSION_INCLUDE_PASSION_H_

#include "modules/ps_filesystem.h"

#include "utils/ps_api.h"
#include "utils/ps_check.h"
#include "utils/ps_status.h"
#include "utils/ps_version.h"

struct ps_passion {
        struct ps_filesystem *filesystem;

        enum ps_status(*get_version)(
                struct ps_passion *this, ps_version *version
        );
};

#endif