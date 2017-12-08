#ifndef LIBPASSION_INCLUDE_UTILS_PS_MATRIX_4_H_
#define LIBPASSION_INCLUDE_UTILS_PS_MATRIX_4_H_
#include "ps_api.h"
#include "ps_status.h"

#define PS_MATRIX_4_SIZE        16

struct ps_matrix_4 {
        /*
         * | e0 e4 e8  e12 |
         * | e1 e5 e9  e13 |
         * | e2 e6 e10 e14 |
         * | e3 e7 e11 e15 |
         */
        float data[PS_MATRIX_4_SIZE];
};

PS_PRIVATE_API enum ps_status ps_matrix_4_set_identity(
        struct ps_matrix_4 *this
);

PS_PRIVATE_API enum ps_status ps_matrix_4_set_raw_transformation(
        struct ps_matrix_4 *this,
        double t00, double t10, double t01, double t11, double x, double y
);

PS_PRIVATE_API enum ps_status ps_matrix_4_set_transformation(
        struct ps_matrix_4 *this,
        double x, double y, double angle,
        double sx, double sy, float ox, float oy, double kx, double ky
);

PS_PRIVATE_API enum ps_status ps_matrix_4_set_ortho(
        struct ps_matrix_4 *this,
        double left, double right, double bottom, double top
);

PS_PRIVATE_API enum ps_status ps_matrix_4_multiply(
        struct ps_matrix_4 *op1, struct ps_matrix_4 *op2,
        struct ps_matrix_4 *out
);

PS_PRIVATE_API enum ps_status ps_matrix_4_set_translation(
        struct ps_matrix_4 *this,
        double x, double y
);

PS_PRIVATE_API enum ps_status ps_matrix_4_translate(
        struct ps_matrix_4 *this,
        double x, double y
);

PS_PRIVATE_API enum ps_status ps_matrix_4_set_rotation(
        struct ps_matrix_4 *this,
        double radians
);

PS_PRIVATE_API enum ps_status ps_matrix_4_rotate(
        struct ps_matrix_4 *this,
        double radians
);

PS_PRIVATE_API enum ps_status ps_matrix_4_set_scale(
        struct ps_matrix_4 *this,
        double sx, double sy
);

PS_PRIVATE_API enum ps_status ps_matrix_4_scale(
        struct ps_matrix_4 *this,
        double sx, double sy
);

PS_PRIVATE_API enum ps_status ps_matrix_4_set_shear(
        struct ps_matrix_4 *this,
        double kx, double ky
);

PS_PRIVATE_API enum ps_status ps_matrix_4_shear(
        struct ps_matrix_4 *this,
        double kx, double ky
);

#endif