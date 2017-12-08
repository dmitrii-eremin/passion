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

enum ps_status ps_ogl_prepare_draw(struct ps_passion *this)
{
        PS_CHECK(this, PS_STATUS_INVALID_ARGUMENT);

        uint16_t w = 0;
        uint16_t h = 0;
        PS_STATUS_ASSERT(ps_graphics_get_dimensions(this, &w, &h));

        struct ps_matrix_4 ortho = { 0 };
        PS_STATUS_ASSERT(ps_matrix_4_set_ortho(&ortho,
                0.0, (double)w, (double)h, 0.0));

        glMatrixMode(GL_PROJECTION);
        glLoadMatrixf(&ortho.data[0]);
        glMatrixMode(GL_MODELVIEW);

        return PS_STATUS_SUCCESS;
}

enum ps_status ps_ogl_setup_context(struct ps_passion *this)
{
        PS_CHECK(this, PS_STATUS_INVALID_ARGUMENT);

        GLint max_vertex_attribs = 1;
        glGetIntegerv(GL_MAX_VERTEX_ATTRIBS, &max_vertex_attribs);
        this->graphics.state.enabled_attrib_arrays = 
                (uint32_t)(((1ull << (uint32_t)max_vertex_attribs)) - 1);
        PS_STATUS_ASSERT(ps_ogl_use_vertex_attrib_arrays(this, 0));

        return PS_STATUS_SUCCESS;
}

enum ps_status ps_ogl_use_vertex_attrib_arrays(struct ps_passion *this, 
        uint32_t bits
)
{
        PS_CHECK(this, PS_STATUS_INVALID_ARGUMENT);

        uint32_t diff = bits ^ this->graphics.state.enabled_attrib_arrays;

        if (diff == 0) {
                return PS_STATUS_SUCCESS;
        }

        for (uint32_t i = 0; i < 32; i++) {
                uint32_t bit = 1 << i;
                if (diff & bit) {
                        if (bits & bit)
                                glEnableVertexAttribArray(i);
                        else
                                glDisableVertexAttribArray(i);
                }
        }

        this->graphics.state.enabled_attrib_arrays = bits;

        return PS_STATUS_SUCCESS;
}