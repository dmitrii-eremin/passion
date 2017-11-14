#ifndef LIBPASSION_INCLUDE_PASSION_PRIVATE_H_
#define LIBPASSION_INCLUDE_PASSION_PRIVATE_H_

#include "passion.h"

#include "utils/ps_api.h"
#include "utils/ps_status.h"


PS_PRIVATE_API enum ps_status ps_create_passion(struct ps_passion **object);
PS_PRIVATE_API enum ps_status ps_destroy_passion(struct ps_passion *object);

#endif