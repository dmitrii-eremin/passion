#include <passion.h>

#include <math.h>

enum ps_status ps_matrix_3_set_identity(struct ps_matrix_3 *this)
{
        PS_CHECK(this, PS_STATUS_INVALID_ARGUMENT);

        memset(&this->data, 0, sizeof(float) * PS_MATRIX_3_SIZE);

        this->data[0] = 1.0f;
        this->data[4] = 1.0f;
        this->data[8] = 1.0f;

        return PS_STATUS_SUCCESS;
}

enum ps_status ps_matrix_3_set_transformation(
        struct ps_matrix_3 *this,
        double x, double y, double angle,
        double sx, double sy, float ox, float oy, double kx, double ky
)
{
        PS_CHECK(this, PS_STATUS_INVALID_ARGUMENT);

        memset(&this->data, 0, sizeof(float) * PS_MATRIX_4_SIZE);

        float c = (float)cos(angle);
        float s = (float)sin(angle);

        this->data[0] = (float)(c * sx - ky * s * sy);
        this->data[1] = (float)(s * sx + ky * c * sy);
        this->data[3] = (float)(kx * c * sx - s * sy);
        this->data[4] = (float)(kx * s * sx + c * sy);
        this->data[6] = (float)(x - ox * this->data[0] - oy * this->data[3]);
        this->data[7] = (float)(y - ox * this->data[1] - oy * this->data[4]);

        this->data[2] = 0.0f;
        this->data[5] = 0.0f;
        this->data[8] = 1.0f;

        return PS_STATUS_SUCCESS;
}

enum ps_status ps_matrix_3_multiply(struct ps_matrix_3 *op1,
        struct ps_matrix_3 *op2,
        struct ps_matrix_3 *out
)
{
        PS_CHECK(op1 && op2 && out, PS_STATUS_INVALID_ARGUMENT);

        struct ps_matrix_3 a = { 0 };
        memcpy(&a, op1, sizeof(struct ps_matrix_3));

        struct ps_matrix_3 b = { 0 };
        memcpy(&b, op2, sizeof(struct ps_matrix_3));

        out->data[0] = (a.data[0] * b.data[0]) + (a.data[3] * b.data[1]) + (a.data[6] * b.data[2]);
        out->data[3] = (a.data[0] * b.data[3]) + (a.data[3] * b.data[4]) + (a.data[6] * b.data[5]);
        out->data[6] = (a.data[0] * b.data[6]) + (a.data[3] * b.data[7]) + (a.data[6] * b.data[8]);

        out->data[1] = (a.data[1] * b.data[0]) + (a.data[4] * b.data[1]) + (a.data[7] * b.data[2]);
        out->data[4] = (a.data[1] * b.data[3]) + (a.data[4] * b.data[4]) + (a.data[7] * b.data[5]);
        out->data[7] = (a.data[1] * b.data[6]) + (a.data[4] * b.data[7]) + (a.data[7] * b.data[8]);

        out->data[2] = (a.data[2] * b.data[0]) + (a.data[5] * b.data[1]) + (a.data[8] * b.data[2]);
        out->data[5] = (a.data[2] * b.data[3]) + (a.data[5] * b.data[4]) + (a.data[8] * b.data[5]);
        out->data[8] = (a.data[2] * b.data[6]) + (a.data[5] * b.data[7]) + (a.data[8] * b.data[8]);

        return PS_STATUS_SUCCESS;
}

enum ps_status ps_matrix_3_transposed_inverse(struct ps_matrix_3 *this,
        struct ps_matrix_3 *out
)
{
        PS_CHECK(this && out, PS_STATUS_INVALID_ARGUMENT);

        struct ps_matrix_3 tmp = { 0 };
        memcpy(&tmp, this, sizeof(struct ps_matrix_3));

        float det = tmp.data[0] * 
                (tmp.data[4] * tmp.data[8] - tmp.data[7] * tmp.data[5])
                - tmp.data[1] * 
                (tmp.data[3] * tmp.data[8] - tmp.data[5] * tmp.data[6])
                + tmp.data[2] * 
                (tmp.data[3] * tmp.data[7] - tmp.data[4] * tmp.data[6]);

        float invdet = 1.0f / det;

        out->data[0] =  invdet * (tmp.data[4] * tmp.data[8] - tmp.data[7] * tmp.data[5]);
        out->data[3] = -invdet * (tmp.data[1] * tmp.data[8] - tmp.data[2] * tmp.data[7]);
        out->data[6] =  invdet * (tmp.data[1] * tmp.data[5] - tmp.data[2] * tmp.data[4]);
        out->data[1] = -invdet * (tmp.data[3] * tmp.data[8] - tmp.data[5] * tmp.data[6]);
        out->data[4] =  invdet * (tmp.data[0] * tmp.data[8] - tmp.data[2] * tmp.data[6]);
        out->data[7] = -invdet * (tmp.data[0] * tmp.data[5] - tmp.data[3] * tmp.data[2]);
        out->data[2] =  invdet * (tmp.data[3] * tmp.data[7] - tmp.data[6] * tmp.data[4]);
        out->data[5] = -invdet * (tmp.data[0] * tmp.data[7] - tmp.data[6] * tmp.data[1]);
        out->data[8] =  invdet * (tmp.data[0] * tmp.data[4] - tmp.data[3] * tmp.data[1]);

        return PS_STATUS_SUCCESS;
}