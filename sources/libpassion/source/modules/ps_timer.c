#include <string.h>

#include <passion.h>

#if defined(PS_PLATFORM_WINDOWS)
#include <windows.h>
#elif defined(PS_PLATFORM_MACOSX) || defined(PS_PLATFORM_IOS)
#include <mach/mach_time.h>
#include <sys/time.h>
#elif defined(PS_PLATFORM_LINUX)
#include <unistd.h>
#include <time.h>
#include <sys/time.h>
#endif

#include <SDL_timer.h>

enum ps_status ps_timer_initialize(struct ps_passion *this)
{
        PS_CHECK(this, PS_STATUS_INVALID_ARGUMENT);

        this->timer.fps = 0;
        this->timer.frames = 0;

        this->timer.current_time = 0.0;
        this->timer.previous_time = 0.0;

        this->timer.previous_fps_update = 0.0;
        this->timer.fps_update_frequency = 1.0;

        this->timer.average_delta = 0.0;
        this->timer.current_delta = 0.0;

        PS_STATUS_ASSERT(ps_timer_get_time(this, &this->timer.current_time));
        this->timer.previous_fps_update = this->timer.current_time;

        return PS_STATUS_SUCCESS;
}

enum ps_status ps_timer_deinitialize(struct ps_passion *this)
{
        if (!this) {
                return PS_STATUS_SUCCESS;
        }

        return PS_STATUS_SUCCESS;
}

enum ps_status ps_timer_get_timer_period(struct ps_passion *this,
        double *period
)
{
        PS_CHECK(this && period, PS_STATUS_INVALID_ARGUMENT);

#if defined(PS_PLATFORM_MACOSX) || defined(PS_PLATFORM_IOS)
        mach_timebase_info_data_t info;
        mach_timebase_info(&info);
        *period = (double)info.numer / (double)info.denom / 1000000000.0;
#elif defined(PS_PLATFORM_WINDOWS)
        LARGE_INTEGER temp;
        if (QueryPerformanceFrequency(&temp) != 0 && temp.QuadPart != 0)
                *period = 1.0 / (double)temp.QuadPart;
#endif
        return PS_STATUS_SUCCESS;
}

enum ps_status ps_timer_get_average_delta(struct ps_passion *this,
        double *average_delta
)
{
        PS_CHECK(this && average_delta, PS_STATUS_INVALID_ARGUMENT);
        *average_delta = this->timer.average_delta;
        return PS_STATUS_SUCCESS;
}

enum ps_status ps_timer_get_delta(struct ps_passion *this, double *delta)
{
        PS_CHECK(this && delta, PS_STATUS_INVALID_ARGUMENT);
        *delta = this->timer.current_delta;
        return PS_STATUS_SUCCESS;
}

enum ps_status ps_timer_get_fps(struct ps_passion *this, uint32_t *fps)
{
        PS_CHECK(this && fps, PS_STATUS_INVALID_ARGUMENT);
        *fps = this->timer.fps;
        return PS_STATUS_SUCCESS;
}

enum ps_status ps_timer_get_time(struct ps_passion *this, ps_time *time)
{
        PS_CHECK(this && time, PS_STATUS_INVALID_ARGUMENT);

        double period = 0.0;
        PS_STATUS_ASSERT(ps_timer_get_timer_period(this, &period));

#if defined(PS_PLATFORM_LINUX)
        double mt;
#if _POSIX_TIMERS > 0 && defined(_POSIX_MONOTONIC_CLOCK) \
&& (defined(CLOCK_MONOTONIC_RAW) || defined(CLOCK_MONOTONIC))
        timespec t;
#ifdef CLOCK_MONOTONIC_RAW
        clockid_t clk_id = CLOCK_MONOTONIC_RAW;
#else
        clockid_t clk_id = CLOCK_MONOTONIC;
#endif
        if (clock_gettime(clk_id, &t) == 0)
                mt = (double)t.tv_sec + (double)t.tv_nsec / 1000000000.0;
        else
#endif
                mt = getTimeOfDay();
        *time = mt;

#elif defined(PS_PLATFORM_MACOSX) || defined(PS_PLATFORM_IOS)
        *time = (double)mach_absolute_time() * timerPeriod;

#elif defined(PS_PLATFORM_WINDOWS)
        LARGE_INTEGER microTime;
        QueryPerformanceCounter(&microTime);
        *time = (ps_time)microTime.QuadPart * period;
#endif

        return PS_STATUS_SUCCESS;
}

enum ps_status ps_timer_sleep(struct ps_passion *this, double seconds)
{
        PS_CHECK(this, PS_STATUS_INVALID_ARGUMENT);

        SDL_Delay((Uint32)(seconds * 1000.0));
        return PS_STATUS_SUCCESS;
}

enum ps_status ps_timer_step(struct ps_passion *this)
{
        PS_CHECK(this, PS_STATUS_INVALID_ARGUMENT);

        struct ps_timer *t = &this->timer;

        t->frames++;

        this->timer.previous_time = t->current_time;
        PS_STATUS_ASSERT(ps_timer_get_time(this, &t->current_time));

        t->current_delta = t->current_time - t->previous_time;

        double time_since_last = t->current_time - t->previous_fps_update;

        if (time_since_last > t->fps_update_frequency)
        {
                t->fps = (uint32_t)(t->frames / time_since_last + 0.5);
                t->average_delta = time_since_last / t->frames;
                t->previous_fps_update = t->current_time;
                t->frames = 0;
        }

        return PS_STATUS_SUCCESS;
}