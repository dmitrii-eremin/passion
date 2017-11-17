#include <SDL_events.h>

#include <passion.h>

enum ps_status convert_event(SDL_Event *sdl, struct ps_event_data *evt)
{
        PS_CHECK(sdl && evt, PS_STATUS_INVALID_ARGUMENT);

        switch (sdl->type) {
        case SDL_QUIT:
                evt->type = PS_EVENT_QUIT;
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