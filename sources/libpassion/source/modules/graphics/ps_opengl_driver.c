#include <passion.h>

enum ps_status ps_ogl_draw_arrays(struct ps_passion *this,
        GLenum mode, GLint first, GLsizei count
)
{
        PS_CHECK(this, PS_STATUS_INVALID_ARGUMENT);

        glDrawArrays(mode, first, count);

        this->graphics.stats.draw_calls++;

        return PS_STATUS_SUCCESS;
}