#include <passion.h>

enum ps_status ps_mouse_initialize(struct ps_passion *this)
{
        PS_CHECK(this, PS_STATUS_INVALID_ARGUMENT);

        this->mouse.stub = NULL;

        return PS_STATUS_SUCCESS;
}

enum ps_status ps_mouse_deinitialize(struct ps_passion *this)
{
        if (!this) {
                return PS_STATUS_SUCCESS;
        }

        return PS_STATUS_SUCCESS;
}