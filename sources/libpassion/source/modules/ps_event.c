#include <SDL_events.h>

#include <passion.h>

enum ps_status convert_event(SDL_Event *sdl, struct ps_event_data *evt)
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
                        evt->visible.is_visible = true;
                        break;
                case SDL_WINDOWEVENT_HIDDEN:
                        evt->type = PS_EVENT_VISIBLE;
                        evt->visible.is_visible = false;
                        break;
                case SDL_WINDOWEVENT_SIZE_CHANGED:
                        evt->type = PS_EVENT_RESIZE;
                        evt->resize.width = (uint16_t)sdl->window.data1;
                        evt->resize.height = (uint16_t)sdl->window.data2;
                        break;
                case SDL_WINDOWEVENT_ENTER:
                        evt->type = PS_EVENT_MOUSEFOCUS;
                        evt->mousefocus.is_focused = true;
                        break;
                case SDL_WINDOWEVENT_LEAVE:
                        evt->type = PS_EVENT_MOUSEFOCUS;
                        evt->mousefocus.is_focused = false;
                        break;
                case SDL_WINDOWEVENT_FOCUS_GAINED:
                        evt->type = PS_EVENT_FOCUS;
                        evt->focus.is_focused = true;
                        break;
                case SDL_WINDOWEVENT_FOCUS_LOST:
                        evt->type = PS_EVENT_FOCUS;
                        evt->focus.is_focused = false;
                        break;
                }
                break;
        case SDL_KEYDOWN:
                evt->type = PS_EVENT_KEYPRESSED;
                evt->key.key = (enum ps_keycode)sdl->key.keysym.sym;
                evt->key.scancode = (enum ps_scancode)sdl->key.keysym.scancode;
                evt->key.is_repeat = false;
                break;
        case SDL_KEYUP:
                evt->type = PS_EVENT_KEYRELEASED;
                evt->key.key = (enum ps_keycode)sdl->key.keysym.sym;
                evt->key.scancode = (enum ps_scancode)sdl->key.keysym.scancode;
                evt->key.is_repeat = false;
                break;
        case SDL_MOUSEBUTTONDOWN:
                evt->type = PS_EVENT_MOUSEPRESSED;
                evt->mouse.x = (uint16_t)sdl->button.x;
                evt->mouse.y = (uint16_t)sdl->button.y;
                evt->mouse.button = (enum ps_mouse_button)sdl->button.button;
                evt->mouse.is_touch = sdl->button.which == SDL_TOUCH_MOUSEID;
                break;
        case SDL_MOUSEBUTTONUP:
                evt->type = PS_EVENT_MOUSERELEASED;
                evt->mouse.x = (uint16_t)sdl->button.x;
                evt->mouse.y = (uint16_t)sdl->button.y;
                evt->mouse.button = (enum ps_mouse_button)sdl->button.button;
                evt->mouse.is_touch = sdl->button.which == SDL_TOUCH_MOUSEID;
                break;
        case SDL_MOUSEMOTION:
                evt->type = PS_EVENT_MOUSEMOVED;
                evt->mousemoved.x = (int16_t)sdl->motion.x;
                evt->mousemoved.y = (int16_t)sdl->motion.y;
                evt->mousemoved.dx = (int16_t)sdl->motion.xrel;
                evt->mousemoved.dy = (int16_t)sdl->motion.yrel;
                evt->mousemoved.is_touch = 
                        sdl->button.which == SDL_TOUCH_MOUSEID;
                break;
        case SDL_MOUSEWHEEL:
                evt->type = PS_EVENT_WHEELMOVED;
                evt->wheel.dx = (uint16_t)sdl->wheel.x;
                evt->wheel.dy = (uint16_t)sdl->wheel.y;
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
                PS_STATUS_ASSERT(convert_event(&sdl_event, &event));
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

        return convert_event(&sdl_event, *event);
}