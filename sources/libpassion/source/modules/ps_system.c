#include <passion.h>

#include <SDL.h>

enum ps_status ps_system_initialize(struct ps_passion *this)
{
        PS_CHECK(this, PS_STATUS_INVALID_ARGUMENT);

        return PS_STATUS_SUCCESS;
}

enum ps_status ps_system_deinitialize(struct ps_passion *this)
{
        if (!this) {
                return PS_STATUS_SUCCESS;
        }

        return PS_STATUS_SUCCESS;
}

enum ps_status ps_system_get_clipboard_text(struct ps_passion *this,
        char *text, uint32_t *count
)
{
        PS_CHECK(this && text && count, PS_STATUS_INVALID_ARGUMENT);

        char *sdl_text = SDL_GetClipboardText();
        uint32_t sdl_len = (uint32_t)strlen(sdl_text);

        if (sdl_len > *count) 
                sdl_len = *count;
        *count = sdl_len;
        
        memcpy(text, sdl_text, sizeof(char) * sdl_len);

        SDL_free(sdl_text);

        return PS_STATUS_SUCCESS;
}

enum ps_status ps_system_get_os(struct ps_passion *this, enum ps_os *os)
{
        PS_CHECK(this && os, PS_STATUS_INVALID_ARGUMENT);

#if defined(PS_PLATFORM_WINDOWS)
        *os = PS_OS_WINDOWS;
#elif defined(PS_PLATFORM_WINDOWS_UWP)
        *os = PS_OS_WINDOWS_UWP;
#elif defined(PS_PLATFORM_LINUX)
        *os = PS_OS_LINUX;
#elif defined(PS_PLATFORM_MACOSX)
        *os = PS_OS_MACOSX;
#elif defined(PS_PLATFORM_IOS)
        *os = PS_OS_IOS;
#elif defined(PS_PLATFORM_ANDROID)
        *os = PS_OS_ANDROID;
#else
        *os = PS_OS_UNKNOWN;
#endif

        return PS_STATUS_SUCCESS;
}

enum ps_status ps_system_get_power_info(
        struct ps_passion *this,
        enum ps_power_state *state,
        uint64_t *percents,
        uint64_t *seconds
)
{
        PS_CHECK(this && state && percents && seconds, 
                PS_STATUS_INVALID_ARGUMENT);

        int sdl_percents = 0;
        int sdl_secs = 0;
        SDL_PowerState sdl_state = SDL_GetPowerInfo(&sdl_secs, &sdl_percents);

        *state = (enum ps_power_state)sdl_state;
        *percents = (uint64_t)sdl_percents;
        *seconds = (uint64_t)sdl_secs;

        return PS_STATUS_SUCCESS;
}

enum ps_status ps_system_get_processor_count(struct ps_passion *this,
        uint16_t *cpu_count
)
{
        PS_CHECK(this && cpu_count, PS_STATUS_INVALID_ARGUMENT);

        *cpu_count = (uint16_t)SDL_GetCPUCount();

        return PS_STATUS_SUCCESS;
}

enum ps_status ps_system_set_clipboard_text(struct ps_passion *this,
        const char *text
)
{
        PS_CHECK(this && text, PS_STATUS_INVALID_ARGUMENT);
        SDL_SetClipboardText(text);
        return PS_STATUS_SUCCESS;
}

enum ps_status ps_system_vibrate(struct ps_passion *this, double seconds)
{
        PS_CHECK(this && seconds >= 0, PS_STATUS_INVALID_ARGUMENT);

        return PS_STATUS_NOT_IMPLEMENTED_YET;
}