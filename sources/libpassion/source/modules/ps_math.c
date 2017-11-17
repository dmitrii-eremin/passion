#include <passion.h>

enum ps_status ps_math_initialize(struct ps_passion *this)
{
        PS_CHECK(this, PS_STATUS_INVALID_ARGUMENT);
        this->math.seed = 0;
        return PS_STATUS_SUCCESS;
}

enum ps_status ps_math_deinitialize(struct ps_passion *this)
{
        if (!this) {
                return PS_STATUS_SUCCESS;
        }

        return PS_STATUS_SUCCESS;
}

enum ps_status ps_math_set_random_seed(
        struct ps_passion *this,
        ps_random_seed seed
)
{
        PS_CHECK(this, PS_STATUS_INVALID_ARGUMENT);
        this->math.seed = seed;
        return PS_STATUS_SUCCESS;
}