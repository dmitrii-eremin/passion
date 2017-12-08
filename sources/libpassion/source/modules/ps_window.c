#include <stdlib.h>
#include <string.h>

#include <passion.h>

#include <SDL.h>

static const uint32_t g_max_title_length = 1024;

enum ps_status ps_window_initialize(struct ps_passion *this)
{
        PS_CHECK(this, PS_STATUS_INVALID_ARGUMENT);
        struct ps_window *w = &this->window;

        w->window = NULL;
        w->context = NULL;

        w->title = malloc(1 * sizeof(char));
        strcpy(w->title, "");

        return PS_STATUS_SUCCESS;
}

enum ps_status ps_window_deinitialize(struct ps_passion *this)
{
        if (!this) {
                return PS_STATUS_SUCCESS;
        }
        struct ps_window *w = &this->window;

        free(w->title);

        return PS_STATUS_SUCCESS;
}

enum ps_status ps_window_close(struct ps_passion *this)
{
        PS_CHECK(this, PS_STATUS_INVALID_ARGUMENT);
        struct ps_window *w = &this->window;

        SDL_Window *sdl_window = (SDL_Window*)w->window;
        SDL_GLContext sdl_context = (SDL_GLContext)w->context;

        if (sdl_context) {
                SDL_GL_DeleteContext(sdl_context);
                w->context = NULL;
        }

        if (sdl_window) {
                SDL_DestroyWindow(sdl_window);
                w->window = NULL;

                SDL_FlushEvent(SDL_WINDOWEVENT);
        }

        return PS_STATUS_SUCCESS;
}

enum ps_status ps_window_get_title(struct ps_passion *this,
        char *title, uint32_t count
)
{
        PS_CHECK(this && title && count > 0, 
                PS_STATUS_INVALID_ARGUMENT
        );
        struct ps_window *w = &this->window;

        uint32_t title_length = (uint32_t)strlen(w->title);
        title_length = min(title_length, count - 1);

        memcpy(title, w->title, title_length + 1);
        return PS_STATUS_SUCCESS;
}

enum ps_status ps_window_set_mode(struct ps_passion *this,
        uint16_t width, uint16_t height,
        struct ps_window_attributes *attribs
)
{
        PS_CHECK(this, PS_STATUS_INVALID_ARGUMENT);

        struct ps_window *w = &this->window;

        SDL_Window *sdl_window = (SDL_Window*)w->window;
        SDL_GLContext sdl_context = (SDL_GLContext)w->context;

        struct ps_window_attributes default_attribs = {
                .fullscreen = this->config.window.fullscreen,
                .fullscreen_type = this->config.window.fullscreen_type,
                .display = this->config.window.display,

                .x = this->config.window.x, .y = this->config.window.y,

                .centered = this->config.window.centered,
                .resizable = this->config.window.resizable,
                .borderless = this->config.window.borderless,
                .highdpi = this->config.window.highdpi,
        };
        attribs = attribs ? attribs : &default_attribs;        

        if (sdl_window || sdl_context)
                PS_STATUS_ASSERT(ps_window_close(this));

        Uint32 window_flags = SDL_WINDOW_OPENGL;

        if (attribs->fullscreen) {
                enum ps_fullscreen_type fs_type = attribs->fullscreen_type;

                if (fs_type == PS_FULLSCREEN_TYPE_DESKTOP) {
                        window_flags |= SDL_WINDOW_FULLSCREEN_DESKTOP;
                } else if (fs_type == PS_FULLSCREEN_TYPE_NORMAL) {
                        window_flags |= SDL_WINDOW_FULLSCREEN;
                        SDL_DisplayMode mode = { 0, width, height, 0, 0 };
                        if (!SDL_GetClosestDisplayMode(attribs->display, &mode, &mode)) {
                                if (SDL_GetDisplayMode(attribs->display, 0, &mode) < 0) {
                                        return PS_STATUS_UNKNOWN_ERROR;
                                }
                        }

                        width = mode.w;
                        height = mode.h;
                }
        }

        if (attribs->resizable)
                window_flags |= SDL_WINDOW_RESIZABLE;
        if (attribs->borderless)
                window_flags |= SDL_WINDOW_BORDERLESS;
        if (attribs->highdpi)
                window_flags |= SDL_WINDOW_ALLOW_HIGHDPI;

        int x = attribs->x;
        int y = attribs->y;

        int display = attribs->display;

        if (!attribs->centered && !attribs->fullscreen) {
                SDL_Rect displaybounds = { 0 };
                SDL_GetDisplayBounds(attribs->display, &displaybounds);
                x += displaybounds.x;
                y += displaybounds.y;
        } else {
                if (attribs->centered)
                        x = y = SDL_WINDOWPOS_CENTERED_DISPLAY(display);
                else
                        x = y = SDL_WINDOWPOS_UNDEFINED_DISPLAY(display);
        }

        sdl_window = SDL_CreateWindow(w->title,
                x, y, width, height, window_flags);

        if (!sdl_window)
                return PS_STATUS_FAILED_TO_CREATE_WINDOW;
        
        sdl_context = SDL_GL_CreateContext(sdl_window);
        if (!sdl_context) {
                SDL_DestroyWindow(sdl_window);
                return PS_STATUS_FAILED_TO_CREATE_CONTEXT;
        }        

        w->window = sdl_window;
        w->context = sdl_context;

        return PS_STATUS_SUCCESS;
}

enum ps_status ps_window_set_title(struct ps_passion *this, const char *title)
{
        PS_CHECK(this, PS_STATUS_INVALID_ARGUMENT);
        struct ps_window *w = &this->window;

        SDL_Window *sdl_window = (SDL_Window*)w->window;

        free(w->title);

        if (title) {                
                uint32_t length = (uint32_t)strlen(title) + 1;
                
                if (length > g_max_title_length)
                        length = g_max_title_length;

                if (length > 0) {
                        w->title = malloc(length * sizeof(char));
                        memcpy(w->title, title, length);
                } else {
                        title = NULL;
                }
        }

        if (!title) {
                w->title = malloc(1 * sizeof(char));
                strcpy(w->title, "");
        }

        if (sdl_window)
                SDL_SetWindowTitle(sdl_window, w->title);

        return PS_STATUS_SUCCESS;
}