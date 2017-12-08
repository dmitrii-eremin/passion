#ifndef LIBPASSION_INCLUDE_MODULES_GRAPHICS_PS_OPENGL_DRIVER_H_
#define LIBPASSION_INCLUDE_MODULES_GRAPHICS_PS_OPENGL_DRIVER_H_
#include "../external/glad/glad/glad.h"

#include "../utils/ps_api.h"
#include "../utils/ps_status.h"

PS_PRIVATE_API enum ps_status ps_ogl_draw_arrays(
        struct ps_passion *this, 
        GLenum mode, GLint first, GLsizei count
);

#endif