#include <passion.h>

#include "../../include/external/noise1234/noise1234.h"
#include "../../include/external/noise1234/simplexnoise1234.h"

enum ps_status ps_math_initialize(struct ps_passion *this)
{
        PS_CHECK(this, PS_STATUS_INVALID_ARGUMENT);
        
        PS_STATUS_ASSERT(ps_random_generator_new(this, &this->math.random));

        return PS_STATUS_SUCCESS;
}

enum ps_status ps_math_deinitialize(struct ps_passion *this)
{
        if (!this) {
                return PS_STATUS_SUCCESS;
        }

        PS_STATUS_ASSERT(ps_random_generator_free(this, this->math.random));

        return PS_STATUS_SUCCESS;
}

enum ps_status ps_math_get_random_seed(struct ps_passion *this,
        ps_random_seed *seed
)
{
        PS_CHECK(this && seed, PS_STATUS_INVALID_ARGUMENT);
        return ps_random_generator_get_seed(this->math.random, seed);
}

enum ps_status ps_math_noise_1d(struct ps_passion *this,
        double x,
        double *out
)
{
        PS_CHECK(this && out, PS_STATUS_INVALID_ARGUMENT);

        *out = ps_simplex_noise_1d(x);
        *out = (*out) * 0.5 + 0.5;

        return PS_STATUS_SUCCESS;
}

enum ps_status ps_math_noise_2d(struct ps_passion *this,
        double x, double y,
        double *out
)
{
        PS_CHECK(this && out, PS_STATUS_INVALID_ARGUMENT);

        *out = ps_simplex_noise_2d(x, y);
        *out = (*out) * 0.5 + 0.5;

        return PS_STATUS_SUCCESS;
}

enum ps_status ps_math_noise_3d(struct ps_passion *this,
        double x, double y, double z,
        double *out
)
{
        PS_CHECK(this && out, PS_STATUS_INVALID_ARGUMENT);

        *out = ps_perlin_noise_3d(x, y, z);
        *out = (*out) * 0.5 + 0.5;

        return PS_STATUS_SUCCESS;
}

enum ps_status ps_math_noise_4d(struct ps_passion *this,
        double x, double y, double z, double w,
        double *out
)
{
        PS_CHECK(this && out, PS_STATUS_INVALID_ARGUMENT);

        *out = ps_perlin_noise_4d(x, y, z, w);
        *out = (*out) * 0.5 + 0.5;

        return PS_STATUS_SUCCESS;
}

enum ps_status ps_math_random(struct ps_passion *this, double *out)
{
        PS_CHECK(this && out, PS_STATUS_INVALID_ARGUMENT);
        return ps_random_generator_random(this->math.random, out);
}

enum ps_status ps_math_random_max(struct ps_passion *this, double maximum,
        double *out
)
{
        PS_CHECK(this && out, PS_STATUS_INVALID_ARGUMENT);
        return ps_random_generator_random_max(this->math.random, maximum, out);
}

enum ps_status ps_math_random_min_max(struct ps_passion *this, 
        double minimum, double maximum,
        double *out
)
{
        PS_CHECK(this && out, PS_STATUS_INVALID_ARGUMENT);
        return ps_random_generator_random_min_max(this->math.random, 
                minimum, maximum, out);
}

enum ps_status ps_math_random_normal(struct ps_passion *this,
        double stddev,
        double *out
)
{
        PS_CHECK(this && out, PS_STATUS_INVALID_ARGUMENT);
        return ps_random_generator_random_normal(this->math.random, 
                stddev, out);
}

enum ps_status ps_math_set_random_seed(
        struct ps_passion *this,
        ps_random_seed seed
)
{
        PS_CHECK(this, PS_STATUS_INVALID_ARGUMENT);
        return ps_random_generator_set_seed(this->math.random, seed);
}