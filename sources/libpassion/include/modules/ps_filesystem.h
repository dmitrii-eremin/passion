#ifndef LIBPASSION_INCLUDE_MODULES_PS_FILESYSTEM_H_
#define LIBPASSION_INCLUDE_MODULES_PS_FILESYSTEM_H_
#include <stdint.h>

#include "../utils/ps_api.h"
#include "../utils/ps_status.h"

#include "filesystem/ps_filedecoder.h"
#include "filesystem/ps_filemode.h"

static const uint32_t PS_FILESYSTEM_FULLSIZE = 0x00;

struct ps_passion;

struct ps_filesystem {
        void *stub;
};

PS_PRIVATE_API enum ps_status ps_filesystem_initialize(
        struct ps_passion *this
);

PS_PRIVATE_API enum ps_status ps_filesystem_deinitialize(
        struct ps_passion *this
);

PS_PUBLIC_API enum ps_status ps_filesystem_append(struct ps_passion *this,
        const char *filename, const char *data, uint32_t size
);

PS_PUBLIC_API enum ps_status ps_filesystem_get_size(struct ps_passion *this,
        const char *filename, uint32_t *filesize
);

PS_PUBLIC_API enum ps_status ps_filesystem_read(struct ps_passion *this,
        const char *filename, uint32_t size,
        char *content, uint32_t *read
);

PS_PUBLIC_API enum ps_status ps_filesystem_write(struct ps_passion *this,
        const char *filename, const char *data, uint32_t size
);


#endif