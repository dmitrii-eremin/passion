#ifndef LIBPASSION_INCLUDE_MODULES_PS_MATH_H_
#define LIBPASSION_INCLUDE_MODULES_PS_MATH_H_
#include "../utils/ps_api.h"
#include "../utils/ps_status.h"

#include "math/ps_random_generator.h"
#include "math/ps_random_seed.h"

struct ps_passion;

struct ps_math {
        struct ps_random_generator *random;
};

PS_PRIVATE_API enum ps_status ps_math_initialize(
        struct ps_passion *this
);

PS_PRIVATE_API enum ps_status ps_math_deinitialize(
        struct ps_passion *this
);

PS_PUBLIC_API enum ps_status ps_math_gamma_to_linear(
        struct ps_passion *this,
        double cred, double cgreen, double cblue,
        double *lred, double *lgreen, double *lblue
);

PS_PUBLIC_API enum ps_status ps_math_get_random_seed(
        struct ps_passion *this,
        ps_random_seed *seed
);

/*
  Example: 
    ps_math_is_convex(this, count, x1, y1, x2, y2, x3, y3);
    ps_math_is_convex(this, 4, 0.0, 0.0, 50.0, 0.0, 50.0, 50.0);
    Coordinates MUST be exactly double! Even if they ending with '.0'.
 */
PS_PUBLIC_API enum ps_status ps_math_is_convex(
        struct ps_passion *this,
        bool *is_convex,
        uint32_t vertices_count,
        ...
);

PS_PUBLIC_API enum ps_status ps_math_linear_to_gamma(
        struct ps_passion *this,
        double lred, double lgreen, double lblue,
        double *cred, double *cgreen, double *cblue
);

PS_PUBLIC_API enum ps_status ps_math_noise_1d(
        struct ps_passion *this,
        double x,
        double *out
);

PS_PUBLIC_API enum ps_status ps_math_noise_2d(
        struct ps_passion *this,
        double x, double y,
        double *out
);

PS_PUBLIC_API enum ps_status ps_math_noise_3d(
        struct ps_passion *this,
        double x, double y, double z,
        double *out
);

PS_PUBLIC_API enum ps_status ps_math_noise_4d(
        struct ps_passion *this,
        double x, double y, double z, double w,
        double *out
);

PS_PUBLIC_API enum ps_status ps_math_random(
        struct ps_passion *this,
        double *out
);

PS_PUBLIC_API enum ps_status ps_math_random_max(
        struct ps_passion *this,
        double maximum,
        double *out
);

PS_PUBLIC_API enum ps_status ps_math_random_min_max(
        struct ps_passion *this,
        double minimum,
        double maximum,
        double *out
);

PS_PUBLIC_API enum ps_status ps_math_random_normal(
        struct ps_passion *this,
        double stddev,
        double *out
);

PS_PUBLIC_API enum ps_status ps_math_set_random_seed(
        struct ps_passion *this,
        ps_random_seed seed
);

#endif