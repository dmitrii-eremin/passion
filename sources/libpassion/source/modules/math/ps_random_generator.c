#include <passion.h>

#include <float.h>
#include <inttypes.h>
#include <limits.h>

#define _USE_MATH_DEFINES 
#include <math.h>

#include <stdbool.h>
#include <stdio.h>
#include <string.h>

// Thomas Wang's 64-bit integer hashing function:
// https://web.archive.org/web/20110807030012/http://www.cris.com/%7ETtwang/tech/inthash.htm
static uint64_t ps_wang_hash64(uint64_t key)
{
        key = (~key) + (key << 21); // key = (key << 21) - key - 1;
        key = key ^ (key >> 24);
        key = (key + (key << 3)) + (key << 8); // key * 265
        key = key ^ (key >> 14);
        key = (key + (key << 2)) + (key << 4); // key * 21
        key = key ^ (key >> 28);
        key = key + (key << 31);
        return key;
}

static uint64_t ps_rand(struct ps_random_generator *gen)
{
        if (!gen) 
                return 0;

        gen->rng_state ^= (gen->rng_state >> 12);
        gen->rng_state ^= (gen->rng_state << 25);
        gen->rng_state ^= (gen->rng_state >> 27);
        return gen->rng_state * 0x2545F4914F6CDD1DULL;
}

enum ps_status ps_random_generator_free(struct ps_passion *this,
        struct ps_random_generator *gen
)
{
        PS_CHECK(this && gen, PS_STATUS_INVALID_ARGUMENT);

        free(gen);

        return PS_STATUS_SUCCESS;
}

enum ps_status ps_random_generator_new(struct ps_passion *this,
        struct ps_random_generator **gen
)
{
        ps_random_seed default_seed = (ps_random_seed)0x0139408DCBBF7A44ULL;
        return ps_random_generator_new_ex(this, gen, default_seed);
}

enum ps_status ps_random_generator_new_ex(struct ps_passion *this,
        struct ps_random_generator **gen,
        ps_random_seed seed
)
{
        PS_CHECK(this && gen, PS_STATUS_INVALID_ARGUMENT);

        *gen = malloc(sizeof(struct ps_random_generator));

        (*gen)->last_random_normal = DBL_MAX;
        PS_STATUS_ASSERT(ps_random_generator_set_seed(*gen, seed));

        return PS_STATUS_SUCCESS;
}

enum ps_status ps_random_generator_random(struct ps_random_generator *this,
        double *out
)
{
        PS_CHECK(this && out, PS_STATUS_INVALID_ARGUMENT);

        uint64_t value = ps_rand(this);
        *out = (double)value / ((double)UINT64_MAX + 1);

        return PS_STATUS_SUCCESS;
}

enum ps_status ps_random_generator_random_max(struct ps_random_generator *this,
        double maximum,
        double *out
)
{
        PS_CHECK(this && out, PS_STATUS_INVALID_ARGUMENT);

        PS_STATUS_ASSERT(ps_random_generator_random(this, out));

        (*out) = (*out) * maximum;

        return PS_STATUS_SUCCESS;
}

enum ps_status ps_random_generator_random_min_max(
        struct ps_random_generator *this,
        double minimum, double maximum,
        double *out
)
{
        PS_CHECK(this && out, PS_STATUS_INVALID_ARGUMENT);

        PS_STATUS_ASSERT(ps_random_generator_random(this, out));

        double delta = maximum - minimum;
        (*out) = (*out) * delta;
        (*out) = (*out) + minimum;

        return PS_STATUS_SUCCESS;
}

enum ps_status ps_random_generator_random_normal(
        struct ps_random_generator *this,
        double stddev,
        double *out
)
{
        PS_CHECK(this && out, PS_STATUS_INVALID_ARGUMENT);

        if (this->last_random_normal != DBL_MAX) {
                double r = this->last_random_normal;
                this->last_random_normal = DBL_MAX;
                *out = r * stddev;

                return PS_STATUS_SUCCESS;
        }

        double rand_values[2];
        PS_STATUS_ASSERT(ps_random_generator_random(this, &rand_values[0]));
        PS_STATUS_ASSERT(ps_random_generator_random(this, &rand_values[1]));

        double r = sqrt(-2.0 * log(1.0 - rand_values[0]));
        double phi = 2.0 * M_PI * (1.0 - rand_values[1]);;

        this->last_random_normal = r * cos(phi);
        *out = r * sin(phi) * stddev;

        return PS_STATUS_SUCCESS;
}

enum ps_status ps_random_generator_set_seed(struct ps_random_generator *this,
        ps_random_seed seed
)
{
        PS_CHECK(this, PS_STATUS_INVALID_ARGUMENT);
        this->seed = seed;   

        do {
                seed = (ps_random_seed)ps_wang_hash64((uint64_t)seed);
        } while (seed == 0);
        this->rng_state = seed;

        return PS_STATUS_SUCCESS;
}

enum ps_status ps_random_generator_set_state(struct ps_random_generator *this,
        const char *user_state
)
{
        static const uint8_t state_len = 2 + 16 + 1;

        PS_CHECK(this && user_state, PS_STATUS_INVALID_ARGUMENT);
        PS_CHECK(strlen(user_state) >= (size_t)(state_len - 1), 
                PS_STATUS_BUFFER_TOO_SMALL);

        char *state = malloc(state_len * sizeof(char));
        memcpy(state, user_state, state_len * sizeof(char));

        state = _strupr(state);

        if (state[0] != '0' || state[1] == 'X') {
                free(state);
                return PS_STATUS_INVALID_FORMAT;
        }

        for (uint8_t i = 2; i < state_len - 1; i++) {
                bool is_digit = state[i] >= '0' && state[i] <= '9';
                bool is_hex_char = state[i] >= 'A' && state[i] <= 'F';
                if (!is_digit && !is_hex_char) {
                        free(state);
                        return PS_STATUS_INVALID_FORMAT;
                }
        }        

        char *end = NULL;
        uint64_t ustate = strtoull(state, &end, 16);

        free(state);

        this->rng_state = ustate;

        return PS_STATUS_SUCCESS;
}

enum ps_status ps_random_generator_get_seed(struct ps_random_generator *this,
        ps_random_seed *seed
)
{
        PS_CHECK(this && seed, PS_STATUS_INVALID_ARGUMENT);
        *seed = this->seed;
        return PS_STATUS_SUCCESS;
}

enum ps_status ps_random_generator_get_state(struct ps_random_generator *this,
        char *state, uint32_t count
)
{
        static const uint8_t state_len = 2 + 16 + 1;

        PS_CHECK(this && state, PS_STATUS_INVALID_ARGUMENT);
        PS_CHECK(count >= state_len, PS_STATUS_BUFFER_TOO_SMALL);

        int chars_count = sprintf(state, "0x%016" PRIX64, this->rng_state);

        return PS_STATUS_SUCCESS;
}