#ifndef LIBPASSION_INCLUDE_UTILS_PS_VECTOR_2D_H_
#define LIBPASSION_INCLUDE_UTILS_PS_VECTOR_2D_H_

#include "ps_api.h"
#include "ps_status.h"

struct ps_vector_2d {
        double x;
        double y;
};

PS_PUBLIC_API enum ps_status ps_vector_create(double x, double y, 
        struct ps_vector_2d *vec
);

PS_PUBLIC_API enum ps_status ps_vector_cross(
        struct ps_vector_2d *v1, struct ps_vector_2d *v2,
        double *out
);

#endif