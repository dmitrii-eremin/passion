#include <passion.h>

#include <stdarg.h>

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

enum ps_status ps_math_is_convex(struct ps_passion *this,
        bool *is_convex,
        uint32_t vertices_count,
        ...
)
{
        PS_CHECK(this && is_convex && vertices_count >= 3, 
                PS_STATUS_INVALID_ARGUMENT);

        double *vert_x = malloc(vertices_count * sizeof(double));
        double *vert_y = malloc(vertices_count * sizeof(double));

        va_list ap;
        va_start(ap, vertices_count);

        for (uint32_t i = 0; i < vertices_count; i++) {
                double x = va_arg(ap, double);
                double y = va_arg(ap, double);

                vert_x[i] = x;
                vert_y[i] = y;
        }

        va_end(ap);

        uint32_t i = vertices_count - 2;
        uint32_t j = vertices_count - 1;
        uint32_t k = 0;        

        struct ps_vector_2d p = { 
                .x = vert_x[j] - vert_x[i],
                .y = vert_y[j] - vert_y[i]
        };

        struct ps_vector_2d q = {
                .x = vert_x[k] - vert_x[j],
                .y = vert_y[k] - vert_y[j]
        };

        double winding = 0.0;
        enum ps_status result = ps_vector_cross(&p, &q, &winding);
        if (PS_STATUS_FAILED(result)) {
                free(vert_x);
                free(vert_y);
                return result;
        }

        while (k + 1 < vertices_count) {
                i = j;
                j = k;
                k++;

                p.x = vert_x[j] - vert_x[i];
                p.y = vert_y[j] - vert_y[i];

                q.x = vert_x[k] - vert_x[j];
                q.y = vert_y[k] - vert_y[j];

                double current = 0.0;

                enum ps_status result = ps_vector_cross(&p, &q, &current);
                if (PS_STATUS_FAILED(result)) {
                        free(vert_x);
                        free(vert_y);
                        return result;
                }

                if (current * winding < 0) {
                        free(vert_x);
                        free(vert_y);

                        *is_convex = false;
                        return PS_STATUS_SUCCESS;
                }
        }

        free(vert_x);
        free(vert_y);

        *is_convex = true;
        return PS_STATUS_SUCCESS;
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