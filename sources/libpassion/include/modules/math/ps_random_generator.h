#ifndef LIBPASSION_INCLUDE_MODULES_MATH_PS_RANDOM_GENERATOR_H_
#define LIBPASSION_INCLUDE_MODULES_MATH_PS_RANDOM_GENERATOR_H_
#include "ps_random_seed.h"

#include "../utils/ps_api.h"
#include "../utils/ps_status.h"

struct ps_random_generator {
        ps_random_seed seed;
        ps_random_seed rng_state;

        double last_random_normal;
};

PS_PUBLIC_API enum ps_status ps_random_generator_free(
        struct ps_passion *this,
        struct ps_random_generator *gen
);

PS_PUBLIC_API enum ps_status ps_random_generator_new(
        struct ps_passion *this,
        struct ps_random_generator **gen
);

PS_PUBLIC_API enum ps_status ps_random_generator_new_ex(
        struct ps_passion *this,
        struct ps_random_generator **gen,
        ps_random_seed seed
);

PS_PUBLIC_API enum ps_status ps_random_generator_random(
        struct ps_random_generator *this,
        double *out
);

PS_PUBLIC_API enum ps_status ps_random_generator_random_max(
        struct ps_random_generator *this,
        double maximum,
        double *out
);

PS_PUBLIC_API enum ps_status ps_random_generator_random_min_max(
        struct ps_random_generator *this,
        double minimum,
        double maximum,
        double *out
);

PS_PUBLIC_API enum ps_status ps_random_generator_random_normal(
        struct ps_random_generator *this,
        double stddev,
        double *out
);

PS_PUBLIC_API enum ps_status ps_random_generator_set_seed(
        struct ps_random_generator *this,
        ps_random_seed seed
);

PS_PUBLIC_API enum ps_status ps_random_generator_set_state(
        struct ps_random_generator *this,
        const char *state
);

PS_PUBLIC_API enum ps_status ps_random_generator_get_seed(
        struct ps_random_generator *this,
        ps_random_seed *seed
);

PS_PUBLIC_API enum ps_status ps_random_generator_get_state(
        struct ps_random_generator *this,
        char *state, uint32_t count
);

#endif