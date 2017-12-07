#ifndef LIBPASSION_INCLUDE_MODULES_GRAPHICS_PS_STACK_TYPE_ITEM_H_
#define LIBPASSION_INCLUDE_MODULES_GRAPHICS_PS_STACK_TYPE_ITEM_H_
#include "ps_stack_type.h"

#include "../utils/ps_api.h"
#include "../utils/ps_list.h"
#include "../utils/ps_status.h"

PS_DEFINE_LIST(ps_stack_type_list, ps_stack_type_item, 
        enum ps_stack_type, PS_PRIVATE_API);

#endif