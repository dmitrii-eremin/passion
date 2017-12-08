#ifndef LIBPASSION_INCLUDE_MODULES_GRAPHICS_PS_OPENGL_DRIVER_H_
#define LIBPASSION_INCLUDE_MODULES_GRAPHICS_PS_OPENGL_DRIVER_H_
#include "../external/glad/glad/glad.h"

#include "../utils/ps_api.h"
#include "../utils/ps_status.h"

PS_PRIVATE_API enum ps_status ps_ogl_draw_arrays(
        struct ps_passion *this,
        GLenum mode, GLint first, GLsizei count
);

PS_PRIVATE_API enum ps_status ps_ogl_prepare_draw(struct ps_passion *this);

PS_PRIVATE_API enum ps_status ps_ogl_setup_context(struct ps_passion *this);

PS_PRIVATE_API enum ps_status ps_ogl_use_vertex_attrib_arrays(
        struct ps_passion *this, uint32_t bits
);

#endif