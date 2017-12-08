#ifndef LIBPASSION_INCLUDE_UTILS_PS_MATRIX_3_H_
#define LIBPASSION_INCLUDE_UTILS_PS_MATRIX_3_H_
#include "ps_api.h"
#include "ps_status.h"

#define PS_MATRIX_3_SIZE        9

struct ps_matrix_3 {
        /*
        * | e0 e3 e6 |
        * | e1 e4 e7 |
        * | e2 e5 e8 |
        */
        float data[PS_MATRIX_3_SIZE];
};

PS_PRIVATE_API enum ps_status ps_matrix_3_set_identity(
        struct ps_matrix_3 *this
);

PS_PRIVATE_API enum ps_status ps_matrix_3_set_transformation(
        struct ps_matrix_3 *this,
        double x, double y, double angle,
        double sx, double sy, float ox, float oy, double kx, double ky
);

PS_PRIVATE_API enum ps_status ps_matrix_3_multiply(
        struct ps_matrix_3 *op1, struct ps_matrix_3 *op2,
        struct ps_matrix_3 *out
);

PS_PRIVATE_API enum ps_status ps_matrix_3_transposed_inverse(
        struct ps_matrix_3 *this,
        struct ps_matrix_3 *out
);

#endif