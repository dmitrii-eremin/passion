// C Language port of the SimplexNoise1234 library.
// Original library developed by Stefan Gustavson [stegu@itn.liu.se]
#include "../include/utils/ps_api.h"
#include "../include/utils/ps_status.h"

PS_PRIVATE_API double ps_simplex_noise_1d(double x);
PS_PRIVATE_API double ps_simplex_noise_2d(double x, double y);