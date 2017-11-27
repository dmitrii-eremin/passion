#include <passion.h>

#include <SDL.h>

enum ps_status ps_keyboard_initialize(struct ps_passion *this)
{
        PS_CHECK(this, PS_STATUS_INVALID_ARGUMENT);

        this->keyboard.key_repeat = false;

        return PS_STATUS_SUCCESS;
}

enum ps_status ps_keyboard_deinitialize(struct ps_passion *this)
{
        if (!this) {
                return PS_STATUS_SUCCESS;
        }

        return PS_STATUS_SUCCESS;
}

enum ps_status ps_keyboard_get_key_from_scancode(struct ps_passion *this,
        enum ps_scancode scancode, enum ps_keycode *keycode
)
{
        PS_CHECK(this && keycode, PS_STATUS_INVALID_ARGUMENT);

        SDL_Scancode sdl_scancode = (SDL_Scancode)scancode;
        SDL_Keycode sdl_keycode = SDL_GetKeyFromScancode(sdl_scancode);
        *keycode = (enum ps_keycode)sdl_keycode;

        return PS_STATUS_SUCCESS;
}


enum ps_status ps_keyboard_get_scancode_from_key(struct ps_passion *this,
        enum ps_keycode keycode, enum ps_scancode *scancode
)
{
        PS_CHECK(this && scancode, PS_STATUS_INVALID_ARGUMENT);

        SDL_Keycode sdl_keycode = (SDL_Keycode)keycode;
        SDL_Scancode sdl_scancode = SDL_GetScancodeFromKey(sdl_keycode);
        *scancode = (enum ps_scancode)sdl_scancode;

        return PS_STATUS_SUCCESS;
}

enum ps_status ps_keyboard_has_key_repeat(struct ps_passion *this,
        bool *key_repeat
)
{
        PS_CHECK(this && key_repeat, PS_STATUS_INVALID_ARGUMENT);

        *key_repeat = this->keyboard.key_repeat;

        return PS_STATUS_SUCCESS;
}

enum ps_status ps_keyboard_has_screen_keyboard(struct ps_passion *this,
        bool *screen_keyboard
)
{
        PS_CHECK(this && screen_keyboard, PS_STATUS_INVALID_ARGUMENT);

        *screen_keyboard = SDL_HasScreenKeyboardSupport() != SDL_FALSE;

        return PS_STATUS_SUCCESS;
}

enum ps_status ps_keyboard_has_text_input(struct ps_passion *this,
        bool *text_input
)
{
        PS_CHECK(this && text_input, PS_STATUS_INVALID_ARGUMENT);

        *text_input = SDL_IsTextInputActive() != SDL_FALSE;

        return PS_STATUS_SUCCESS;
}

enum ps_status ps_keyboard_is_down(struct ps_passion *this,
        enum ps_keycode key,
        bool *is_down
)
{
        PS_CHECK(this && is_down, PS_STATUS_INVALID_ARGUMENT);

        enum ps_scancode scancode;
        PS_STATUS_ASSERT(
                ps_keyboard_get_scancode_from_key(
                        this, key, &scancode
                )
        );

        return ps_keyboard_is_scancode_down(this, scancode, is_down);
}

enum ps_status ps_keyboard_is_scancode_down(struct ps_passion *this,
        enum ps_scancode scancode,
        bool *is_down
)
{
        PS_CHECK(this && is_down, PS_STATUS_INVALID_ARGUMENT);

        const Uint8 *state = SDL_GetKeyboardState(NULL);

        *is_down = state[(Uint8)scancode] != 0;

        return PS_STATUS_SUCCESS;
}

enum ps_status ps_keyboard_set_key_repeat(struct ps_passion *this,
        bool key_repeat
)
{
        PS_CHECK(this, PS_STATUS_INVALID_ARGUMENT);

        this->keyboard.key_repeat = key_repeat;

        return PS_STATUS_SUCCESS;
}

enum ps_status ps_keyboard_set_text_input(struct ps_passion *this,
        bool text_input
)
{
        PS_CHECK(this, PS_STATUS_INVALID_ARGUMENT);

        if (text_input)
                SDL_StartTextInput();
        else
                SDL_StopTextInput();

        return PS_STATUS_SUCCESS;
}

enum ps_status ps_keyboard_set_text_input_area(struct ps_passion *this,
        bool text_input,
        uint16_t x, uint16_t y, uint16_t w, uint16_t h
)
{
        PS_CHECK(this, PS_STATUS_INVALID_ARGUMENT);

        SDL_Rect rect = {
                .x = (int)x,
                .y = (int)y,
                .w = (int)w,
                .h = (int)h
        };

        SDL_SetTextInputRect(&rect);

        return ps_keyboard_set_text_input(this, text_input);
}