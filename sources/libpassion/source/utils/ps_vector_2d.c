#include <passion.h>

enum ps_status ps_vector_create(double x, double y, struct ps_vector_2d *vec)
{
        PS_CHECK(vec, PS_STATUS_INVALID_ARGUMENT);

        vec->x = x;
        vec->y = y;

        return PS_STATUS_SUCCESS;
}

enum ps_status ps_vector_cross(
        struct ps_vector_2d *v1, struct ps_vector_2d *v2,
        double *out
)
{
        PS_CHECK(v1 && v2 && out, PS_STATUS_INVALID_ARGUMENT);

        *out = v1->x * v2->y - v1->y * v2->x;

        return PS_STATUS_SUCCESS;
}