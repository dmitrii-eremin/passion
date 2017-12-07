#ifndef LIBPASSION_INCLUDE_MODULES_GRAPHICS_PS_GET_DISPLAY_STATE_H_
#define LIBPASSION_INCLUDE_MODULES_GRAPHICS_PS_GET_DISPLAY_STATE_H_

#define PS_GET_DISPLAY_STATE(NAME) \
        struct ps_display_state *NAME = NULL; \
        PS_STATUS_ASSERT( \
                ps_display_state_list_get_last( \
                        &this->graphics.display_states, &NAME \
                ) \
        ); \

#endif