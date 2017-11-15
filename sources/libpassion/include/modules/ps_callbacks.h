#ifndef LIBPASSION_INCLUDE_MODULES_PS_CALLBACKS_H_
#define LIBPASSION_INCLUDE_MODULES_PS_CALLBACKS_H_
#include "../utils/ps_api.h"
#include "../utils/ps_status.h"

struct ps_passion;

struct ps_callbacks {
        enum ps_status (*run)(struct ps_passion *this);
        enum ps_status (*load)(struct ps_passion *this, 
                int argc, char **argv
        );
};

#define PS_SET_CALLBACK(X, M, F) X->callbacks.M = F;
#define PS_CALL_CALLBACK(X, M, A) X->callbacks.M A;

PS_PRIVATE_API enum ps_status ps_callbacks_initialize(
        struct ps_passion *this
);

PS_PRIVATE_API enum ps_status ps_callbacks_deinitialize(
        struct ps_passion *this
);

#endif