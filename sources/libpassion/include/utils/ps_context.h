#ifndef LIBPASSION_INCLUDE_UTILS_PS_CONTEXT_H_
#define LIBPASSION_INCLUDE_UTILS_PS_CONTEXT_H_

struct ps_context {
        struct {
                int argc;
                char **argv;
        } startup_args;
};

#endif