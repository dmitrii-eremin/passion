#include <SDL_events.h>

#include <passion.h>

enum ps_status convert_event(struct ps_passion *this, 
        SDL_Event *sdl, struct ps_event_data *evt)
{
        PS_CHECK(sdl && evt, PS_STATUS_INVALID_ARGUMENT);
        SDL_BUTTON_LEFT;
        switch (sdl->type) {
        case SDL_QUIT:
                evt->type = PS_EVENT_QUIT;
                break;
        case SDL_WINDOWEVENT:
                switch (sdl->window.event) {
                case SDL_WINDOWEVENT_SHOWN:
                        evt->type = PS_EVENT_VISIBLE;
                        evt->data.visible.is_visible = true;
                        break;
                case SDL_WINDOWEVENT_HIDDEN:
                        evt->type = PS_EVENT_VISIBLE;
                        evt->data.visible.is_visible = false;
                        break;
                case SDL_WINDOWEVENT_SIZE_CHANGED:
                        evt->type = PS_EVENT_RESIZE;
                        evt->data.resize.width = (uint16_t)sdl->window.data1;
                        evt->data.resize.height = (uint16_t)sdl->window.data2;
                        break;
                case SDL_WINDOWEVENT_ENTER:
                        evt->type = PS_EVENT_MOUSEFOCUS;
                        evt->data.mousefocus.is_focused = true;
                        break;
                case SDL_WINDOWEVENT_LEAVE:
                        evt->type = PS_EVENT_MOUSEFOCUS;
                        evt->data.mousefocus.is_focused = false;
                        break;
                case SDL_WINDOWEVENT_FOCUS_GAINED:
                        evt->type = PS_EVENT_FOCUS;
                        evt->data.focus.is_focused = true;
                        break;
                case SDL_WINDOWEVENT_FOCUS_LOST:
                        evt->type = PS_EVENT_FOCUS;
                        evt->data.focus.is_focused = false;
                        break;
                }
                break;
        case SDL_KEYDOWN:
                evt->type = PS_EVENT_KEYPRESSED;
                evt->data.key.key = 
                        (enum ps_keycode)sdl->key.keysym.sym;
                evt->data.key.scancode = 
                        (enum ps_scancode)sdl->key.keysym.scancode;
                evt->data.key.is_repeat = false;
                break;
        case SDL_KEYUP:
                evt->type = PS_EVENT_KEYRELEASED;
                evt->data.key.key = 
                        (enum ps_keycode)sdl->key.keysym.sym;
                evt->data.key.scancode = 
                        (enum ps_scancode)sdl->key.keysym.scancode;
                evt->data.key.is_repeat = false;
                break;
        case SDL_MOUSEBUTTONDOWN:
                evt->type = PS_EVENT_MOUSEPRESSED;
                evt->data.mouse.x = (uint16_t)sdl->button.x;
                evt->data.mouse.y = (uint16_t)sdl->button.y;
                evt->data.mouse.button = 
                        (enum ps_mouse_button)sdl->button.button;
                evt->data.mouse.is_touch = 
                        sdl->button.which == SDL_TOUCH_MOUSEID;
                break;
        case SDL_MOUSEBUTTONUP:
                evt->type = PS_EVENT_MOUSERELEASED;
                evt->data.mouse.x = (uint16_t)sdl->button.x;
                evt->data.mouse.y = (uint16_t)sdl->button.y;
                evt->data.mouse.button = 
                        (enum ps_mouse_button)sdl->button.button;
                evt->data.mouse.is_touch = 
                        sdl->button.which == SDL_TOUCH_MOUSEID;
                break;
        case SDL_MOUSEMOTION:
                evt->type = PS_EVENT_MOUSEMOVED;
                evt->data.mousemoved.x = (int16_t)sdl->motion.x;
                evt->data.mousemoved.y = (int16_t)sdl->motion.y;
                evt->data.mousemoved.dx = (int16_t)sdl->motion.xrel;
                evt->data.mousemoved.dy = (int16_t)sdl->motion.yrel;
                evt->data.mousemoved.is_touch =
                        sdl->button.which == SDL_TOUCH_MOUSEID;
                break;
        case SDL_MOUSEWHEEL:
                evt->type = PS_EVENT_WHEELMOVED;
                evt->data.wheel.dx = (uint16_t)sdl->wheel.x;
                evt->data.wheel.dy = (uint16_t)sdl->wheel.y;
                break;
        case SDL_FINGERDOWN: {
                evt->type = PS_EVENT_TOUCHPRESSED;
                evt->data.touch.id = (int64_t)sdl->tfinger.fingerId;

                uint16_t w = 0;
                uint16_t h = 0;
                PS_STATUS_ASSERT(ps_graphics_get_dimensions(this, &w, &h));

                evt->data.touch.x = (uint16_t)(sdl->tfinger.x * w);
                evt->data.touch.y = (uint16_t)(sdl->tfinger.y * h);
                evt->data.touch.dx = (uint16_t)(sdl->tfinger.dx * w);
                evt->data.touch.dy = (uint16_t)(sdl->tfinger.dy * h);

                evt->data.touch.pressure = (double)sdl->tfinger.pressure;
        }
        break;
        case SDL_FINGERUP: {
                evt->type = PS_EVENT_TOUCHRELEASED;
                evt->data.touch.id = (int64_t)sdl->tfinger.fingerId;

                uint16_t w = 0;
                uint16_t h = 0;
                PS_STATUS_ASSERT(ps_graphics_get_dimensions(this, &w, &h));

                evt->data.touch.x = (uint16_t)(sdl->tfinger.x * w);
                evt->data.touch.y = (uint16_t)(sdl->tfinger.y * h);
                evt->data.touch.dx = (uint16_t)(sdl->tfinger.dx * w);
                evt->data.touch.dy = (uint16_t)(sdl->tfinger.dy * h);

                evt->data.touch.pressure = (double)sdl->tfinger.pressure;
        }
        break;
        case SDL_FINGERMOTION: {
                evt->type = PS_EVENT_TOUCHMOVED;
                evt->data.touch.id = (int64_t)sdl->tfinger.fingerId;

                uint16_t w = 0;
                uint16_t h = 0;
                PS_STATUS_ASSERT(ps_graphics_get_dimensions(this, &w, &h));

                evt->data.touch.x = (uint16_t)(sdl->tfinger.x * w);
                evt->data.touch.y = (uint16_t)(sdl->tfinger.y * h);
                evt->data.touch.dx = (uint16_t)(sdl->tfinger.dx * w);
                evt->data.touch.dy = (uint16_t)(sdl->tfinger.dy * h);

                evt->data.touch.pressure = (double)sdl->tfinger.pressure;
        }
        break;
        default:
                evt->type = PS_EVENT_UNKNOWN;
                break;
        }        

        return PS_STATUS_SUCCESS;
}

enum ps_status ps_event_initialize(struct ps_passion *this)
{
        PS_CHECK(this, PS_STATUS_INVALID_ARGUMENT);

        this->event.events = NULL;

        return PS_STATUS_SUCCESS;
}

enum ps_status ps_event_deinitialize(struct ps_passion *this)
{
        if (!this) {
                return PS_STATUS_SUCCESS;
        }

        return PS_STATUS_SUCCESS;
}

enum ps_status ps_event_clear(struct ps_passion *this)
{
        PS_CHECK(this, PS_STATUS_INVALID_ARGUMENT);

        SDL_Event sdl_event = { 0 };
        while (SDL_PollEvent(&sdl_event));

        ps_events_list_clear(&this->event.events);

        return PS_STATUS_SUCCESS;
}

enum ps_status ps_event_poll(struct ps_passion *this,
        struct ps_event_data *event
)
{
        PS_CHECK(this && event, PS_STATUS_INVALID_ARGUMENT);

        if (this->event.events) {
                ps_events_list_pop(&this->event.events, event);
        } else {
                event->type = PS_EVENT_BREAK_POLLING;
        }        

        return PS_STATUS_SUCCESS;
}

enum ps_status ps_event_pump(struct ps_passion *this)
{
        PS_CHECK(this, PS_STATUS_INVALID_ARGUMENT);

        SDL_Event sdl_event = { 0 };
        while (SDL_PollEvent(&sdl_event)) {
                struct ps_event_data event = { 0 };
                PS_STATUS_ASSERT(convert_event(this, &sdl_event, &event));
                PS_STATUS_ASSERT(ps_event_push(this, &event));
        }

        return PS_STATUS_SUCCESS;
}

enum ps_status ps_event_push(struct ps_passion *this, 
        struct ps_event_data *event
)
{
        PS_CHECK(this && event, PS_STATUS_INVALID_ARGUMENT);

        ps_events_list_push(&this->event.events, event);
        return PS_STATUS_SUCCESS;
}

enum ps_status ps_event_quit(struct ps_passion *this)
{
        struct ps_event_data evt = {
                .type = PS_EVENT_QUIT
        };

        return ps_event_push(this, &evt);
}

enum ps_status ps_event_wait(struct ps_passion *this,
        struct ps_event_data **event
)
{
        PS_CHECK(this && event, PS_STATUS_INVALID_ARGUMENT);

        SDL_Event sdl_event = { 0 };
        if (SDL_WaitEvent(&sdl_event) != 1) {
                *event = NULL;
                return PS_STATUS_UNKNOWN_ERROR;
        }

        return convert_event(this, &sdl_event, *event);
}