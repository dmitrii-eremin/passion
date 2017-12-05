// C Language port of the Noise1234 library.
// Original library developed by Stefan Gustavson [stegu@itn.liu.se]
#include "../include/utils/ps_api.h"
#include "../include/utils/ps_status.h"

PS_PRIVATE_API double ps_perlin_noise_3d(double x, double y, double z);
PS_PRIVATE_API double ps_perlin_noise_4d(double x, double y, 
        double z, double w);