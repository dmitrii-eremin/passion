#ifndef LIBPASSION_INCLUDE_MODULES_PS_MATH_H_
#define LIBPASSION_INCLUDE_MODULES_PS_MATH_H_
#include "../utils/ps_api.h"
#include "../utils/ps_status.h"

#include "math/ps_random_seed.h"

struct ps_passion;

struct ps_math {
        ps_random_seed seed;
};

PS_PRIVATE_API enum ps_status ps_math_initialize(
        struct ps_passion *this
);

PS_PRIVATE_API enum ps_status ps_math_deinitialize(
        struct ps_passion *this
);

PS_PUBLIC_API enum ps_status ps_math_set_random_seed(
        struct ps_passion *this,
        ps_random_seed seed
);

#endif