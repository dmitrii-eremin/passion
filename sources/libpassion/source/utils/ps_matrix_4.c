#include <passion.h>

#include <math.h>

enum ps_status ps_matrix_4_set_identity(struct ps_matrix_4 *this)
{
        PS_CHECK(this, PS_STATUS_INVALID_ARGUMENT);

        memset(&this->data, 0, sizeof(float) * PS_MATRIX_4_SIZE);

        this->data[0] = 1.0f;
        this->data[5] = 1.0f;
        this->data[10] = 1.0f;
        this->data[15] = 1.0f;

        return PS_STATUS_SUCCESS;
}

enum ps_status ps_matrix_4_set_raw_transformation(
        struct ps_matrix_4 *this,
        double t00, double t10, double t01, double t11, double x, double y
)
{
        PS_CHECK(this, PS_STATUS_INVALID_ARGUMENT);

        memset(&this->data, 0, sizeof(float) * PS_MATRIX_4_SIZE);

        this->data[10] = 1.0f;
        this->data[15] = 1.0f;
        this->data[0] = (float)t00;
        this->data[1] = (float)t10;
        this->data[4] = (float)t01;
        this->data[5] = (float)t11;
        this->data[12] = (float)x;
        this->data[13] = (float)y;

        return PS_STATUS_SUCCESS;
}

enum ps_status ps_matrix_4_set_transformation(
        struct ps_matrix_4 *this,
        double x, double y, double angle,
        double sx, double sy, float ox, float oy, double kx, double ky
)
{
        PS_CHECK(this, PS_STATUS_INVALID_ARGUMENT);

        memset(&this->data, 0, sizeof(float) * PS_MATRIX_4_SIZE);

        float c = (float)cos(angle);
        float s = (float)sin(angle);

        this->data[10] = (float)1.0f;
        this->data[15] = (float)1.0f;
        this->data[0] = (float)(c * sx - ky * s * sy);
        this->data[1] = (float)(s * sx + ky * c * sy);
        this->data[4] = (float)(kx * c * sx - s * sy);
        this->data[5] = (float)(kx * s * sx + c * sy);
        this->data[12] = (float)(x - ox * this->data[0] - oy * this->data[4]);
        this->data[13] = (float)(y - ox * this->data[1] - oy * this->data[5]);

        return PS_STATUS_SUCCESS;
}

enum ps_status ps_matrix_4_set_ortho(struct ps_matrix_4 *this,
        double left, double right, double bottom, double top
)
{
        PS_CHECK(this, PS_STATUS_INVALID_ARGUMENT);

        PS_STATUS_ASSERT(ps_matrix_4_set_identity(this));

        this->data[0] = 2.0f / (float)(right - left);
        this->data[5] = 2.0f / (float)(top - bottom);
        this->data[10] = -1.0f;

        this->data[12] = (float)(-(right + left) / (right - left));
        this->data[13] = (float)(-(top + bottom) / (top - bottom));

        return PS_STATUS_SUCCESS;
}

enum ps_status ps_matrix_4_multiply(struct ps_matrix_4 *op1, 
        struct ps_matrix_4 *op2,
        struct ps_matrix_4 *out
)
{
        PS_CHECK(op1 && op2 && out, PS_STATUS_INVALID_ARGUMENT);

        struct ps_matrix_4 a = { 0 };
        memcpy(&a, op1, sizeof(struct ps_matrix_4));

        struct ps_matrix_4 b = { 0 };
        memcpy(&b, op2, sizeof(struct ps_matrix_4));

        out->data[0] = (a.data[0] * b.data[0]) + (a.data[4] * b.data[1]) + (a.data[8] * b.data[2]) + (a.data[12] * b.data[3]);
        out->data[4] = (a.data[0] * b.data[4]) + (a.data[4] * b.data[5]) + (a.data[8] * b.data[6]) + (a.data[12] * b.data[7]);
        out->data[8] = (a.data[0] * b.data[8]) + (a.data[4] * b.data[9]) + (a.data[8] * b.data[10]) + (a.data[12] * b.data[11]);
        out->data[12] = (a.data[0] * b.data[12]) + (a.data[4] * b.data[13]) + (a.data[8] * b.data[14]) + (a.data[12] * b.data[15]);

        out->data[1] = (a.data[1] * b.data[0]) + (a.data[5] * b.data[1]) + (a.data[9] * b.data[2]) + (a.data[13] * b.data[3]);
        out->data[5] = (a.data[1] * b.data[4]) + (a.data[5] * b.data[5]) + (a.data[9] * b.data[6]) + (a.data[13] * b.data[7]);
        out->data[9] = (a.data[1] * b.data[8]) + (a.data[5] * b.data[9]) + (a.data[9] * b.data[10]) + (a.data[13] * b.data[11]);
        out->data[13] = (a.data[1] * b.data[12]) + (a.data[5] * b.data[13]) + (a.data[9] * b.data[14]) + (a.data[13] * b.data[15]);

        out->data[2] = (a.data[2] * b.data[0]) + (a.data[6] * b.data[1]) + (a.data[10] * b.data[2]) + (a.data[14] * b.data[3]);
        out->data[6] = (a.data[2] * b.data[4]) + (a.data[6] * b.data[5]) + (a.data[10] * b.data[6]) + (a.data[14] * b.data[7]);
        out->data[10] = (a.data[2] * b.data[8]) + (a.data[6] * b.data[9]) + (a.data[10] * b.data[10]) + (a.data[14] * b.data[11]);
        out->data[14] = (a.data[2] * b.data[12]) + (a.data[6] * b.data[13]) + (a.data[10] * b.data[14]) + (a.data[14] * b.data[15]);

        out->data[3] = (a.data[3] * b.data[0]) + (a.data[7] * b.data[1]) + (a.data[11] * b.data[2]) + (a.data[15] * b.data[3]);
        out->data[7] = (a.data[3] * b.data[4]) + (a.data[7] * b.data[5]) + (a.data[11] * b.data[6]) + (a.data[15] * b.data[7]);
        out->data[11] = (a.data[3] * b.data[8]) + (a.data[7] * b.data[9]) + (a.data[11] * b.data[10]) + (a.data[15] * b.data[11]);
        out->data[15] = (a.data[3] * b.data[12]) + (a.data[7] * b.data[13]) + (a.data[11] * b.data[14]) + (a.data[15] * b.data[15]);

        return PS_STATUS_SUCCESS;
}

enum ps_status ps_matrix_4_set_translation(struct ps_matrix_4 *this,
        double x, double y
)
{
        PS_CHECK(this, PS_STATUS_INVALID_ARGUMENT);

        PS_STATUS_ASSERT(ps_matrix_4_set_identity(this));
        this->data[12] = (float)x;
        this->data[13] = (float)y;

        return PS_STATUS_SUCCESS;
}

enum ps_status ps_matrix_4_translate(struct ps_matrix_4 *this,
        double x, double y
)
{
        PS_CHECK(this, PS_STATUS_INVALID_ARGUMENT);

        struct ps_matrix_4 tmp = { 0 };
        PS_STATUS_ASSERT(ps_matrix_4_set_translation(&tmp, x, y));

        return ps_matrix_4_multiply(this, &tmp, this);
}

enum ps_status ps_matrix_4_set_rotation(struct ps_matrix_4 *this,
        double radians
)
{
        PS_CHECK(this, PS_STATUS_INVALID_ARGUMENT);

        PS_STATUS_ASSERT(ps_matrix_4_set_identity(this));

        double c = cos(radians);
        double s = sin(radians);

        this->data[0] = (float)c;
        this->data[4] = (float)-s;
        this->data[1] = (float)s;
        this->data[5] = (float)c;

        return PS_STATUS_SUCCESS;
}

enum ps_status ps_matrix_4_rotate(struct ps_matrix_4 *this,
        double radians
)
{
        PS_CHECK(this, PS_STATUS_INVALID_ARGUMENT);

        struct ps_matrix_4 tmp = { 0 };
        PS_STATUS_ASSERT(ps_matrix_4_set_rotation(&tmp, radians));

        return ps_matrix_4_multiply(this, &tmp, this);
}

enum ps_status ps_matrix_4_set_scale(struct ps_matrix_4 *this,
        double sx, double sy
)
{
        PS_CHECK(this, PS_STATUS_INVALID_ARGUMENT);

        PS_STATUS_ASSERT(ps_matrix_4_set_identity(this));

        this->data[0] = (float)sx;
        this->data[5] = (float)sy;

        return PS_STATUS_SUCCESS;
}

enum ps_status ps_matrix_4_scale(struct ps_matrix_4 *this,
        double sx, double sy
)
{
        PS_CHECK(this, PS_STATUS_INVALID_ARGUMENT);

        struct ps_matrix_4 tmp = { 0 };
        PS_STATUS_ASSERT(ps_matrix_4_set_scale(&tmp, sx, sy));

        return ps_matrix_4_multiply(this, &tmp, this);
}

enum ps_status ps_matrix_4_set_shear(struct ps_matrix_4 *this,
        double kx, double ky
)
{
        PS_CHECK(this, PS_STATUS_INVALID_ARGUMENT);

        PS_STATUS_ASSERT(ps_matrix_4_set_identity(this));

        this->data[1] = (float)kx;
        this->data[4] = (float)ky;

        return PS_STATUS_SUCCESS;
}

enum ps_status ps_matrix_4_shear(struct ps_matrix_4 *this,
        double kx, double ky
)
{
        PS_CHECK(this, PS_STATUS_INVALID_ARGUMENT);

        struct ps_matrix_4 tmp = { 0 };
        PS_STATUS_ASSERT(ps_matrix_4_set_shear(&tmp, kx, ky));

        return ps_matrix_4_multiply(this, &tmp, this);
}