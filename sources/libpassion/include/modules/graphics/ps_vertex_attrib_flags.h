#ifndef LIBPASSION_INCLUDE_MODULES_GRAPHICS_PS_VERTEX_ATTRIB_FLAGS_H_
#define LIBPASSION_INCLUDE_MODULES_GRAPHICS_PS_VERTEX_ATTRIB_FLAGS_H_
#include "ps_vertex_attrib_id.h"

enum ps_vertex_attrib_flags {
        PS_VERTEX_ATTRIBFLAG_POS = 
                1 << PS_VERTEX_ATTRIB_POS,
        PS_VERTEX_ATTRIBFLAG_TEXCOORD = 
                1 << PS_VERTEX_ATTRIB_TEXCOORD,
        PS_VERTEX_ATTRIBFLAG_COLOR = 
                1 << PS_VERTEX_ATTRIB_COLOR,
        PS_VERTEX_ATTRIBFLAG_CONSTANT_COLOR = 
                1 << PS_VERTEX_ATTRIB_CONSTANT_COLOR
};

#endif