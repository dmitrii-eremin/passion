#ifndef LIBPASSION_INCLUDE_UTILS_PS_CONTEXT_H_
#define LIBPASSION_INCLUDE_UTILS_PS_CONTEXT_H_
#include "../ps_config.h"
#include "ps_status.h"

struct ps_context {
        struct {
                int argc;
                char **argv;
        } startup_args;

        enum ps_status (*conf)(struct ps_config *config);
};

#endif