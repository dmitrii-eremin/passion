#ifndef LIBPASSION_INCLUDE_MODULES_PS_EVENT_PS_EVENT_DATA_H_
#define LIBPASSION_INCLUDE_MODULES_PS_EVENT_PS_EVENT_DATA_H_
#include <stdbool.h>
#include <stdint.h>

#include "../touch/ps_touch_id.h"
#include "../touch/ps_touch_pressure.h"

#include "ps_event_type.h"
#include "ps_mouse_button.h"
#include "ps_keycode.h"
#include "ps_scancode.h"

struct ps_event_data {
        enum ps_event_type type;
        union {
                struct {
                        enum ps_keycode key;
                        enum ps_scancode scancode;
                        bool is_repeat;
                } key;
                struct {
                        uint16_t x;
                        uint16_t y;
                        enum ps_mouse_button button;
                        bool is_touch;
                } mouse;
                struct {
                        int16_t x;
                        int16_t y;
                        int16_t dx;
                        int16_t dy;
                        bool is_touch;
                } mousemoved;
                struct {
                        bool is_focused;
                } mousefocus;
                struct {
                        bool is_visible;
                } visible;
                struct {
                        bool is_focused;
                } focus;
                struct {
                        uint16_t width;
                        uint16_t height;
                } resize;
                struct {
                        uint16_t dx;
                        uint16_t dy;
                } wheel;
                struct {
                        ps_touch_id id;
                        uint16_t x;
                        uint16_t y;
                        uint16_t dx;
                        uint16_t dy;
                        ps_touch_pressure pressure;
                } touch;
        } data;
};

#endif