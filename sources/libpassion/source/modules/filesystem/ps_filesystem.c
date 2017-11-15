#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <modules/filesystem/ps_filesystem_private.h>
#include <passion.h>

enum ps_status append(struct ps_filesystem *this,
        const char *filename, const char *data, uint32_t size
)
{
        PS_CHECK(this && filename && data, PS_STATUS_INVALID_ARGUMENT);

        FILE *file = fopen(filename, "ab");
        if (!file) {
                return PS_STATUS_FAILED_TO_OPEN;
        }

        if (size == PS_FILESYSTEM_FULLSIZE)
                size = strlen(data);

        fwrite(data, size, 1, file);
        fclose(file);

        return PS_STATUS_SUCCESS;
}

enum ps_status get_size(struct ps_filesystem *this,
        const char *filename, uint32_t *filesize
)
{
        PS_CHECK(this && filename && filesize, PS_STATUS_INVALID_ARGUMENT);

        FILE *file = fopen(filename, "rb");
        if (!file) {
                return PS_STATUS_FAILED_TO_OPEN;
        }

        fseek(file, 0, SEEK_END);
        *filesize = (uint32_t)ftell(file);
        fclose(file);

        return PS_STATUS_SUCCESS;
}

enum ps_status read(struct ps_filesystem *this,
        const char *filename, uint32_t size, 
        char *content, uint32_t *read
)
{
        PS_CHECK(this && filename && content, PS_STATUS_INVALID_ARGUMENT);

        FILE *file = fopen(filename, "rb");
        if (!file) {
                return PS_STATUS_FAILED_TO_OPEN;
        }

        if (size == PS_FILESYSTEM_FULLSIZE) {
                PS_CHECK(read, PS_STATUS_INVALID_ARGUMENT);

                PS_STATUS_ASSERT(
                        this->get_size(this, filename, &size)
                );

                size = min(size, *read);
        }

        fread(content, size, 1, file);
        fclose(file);

        if (read)
                *read = size;

        return PS_STATUS_SUCCESS;
}

enum ps_status write(struct ps_filesystem *this,
        const char *filename, const char *data, uint32_t size
)
{
        PS_CHECK(this && filename && data, PS_STATUS_INVALID_ARGUMENT);

        FILE *file = fopen(filename, "wb");
        if (!file) {
                return PS_STATUS_FAILED_TO_OPEN;
        }

        if (size == PS_FILESYSTEM_FULLSIZE)
                size = strlen(data);

        fwrite(data, size, 1, file);
        fclose(file);

        return PS_STATUS_SUCCESS;
}

enum ps_status ps_create_filesystem(struct ps_filesystem **object)
{
        PS_CHECK(object, PS_STATUS_INVALID_ARGUMENT);

        *object = malloc(sizeof(struct ps_filesystem));

        (*object)->append = append;
        (*object)->get_size = get_size;
        (*object)->read = read;
        (*object)->write = write;

        return PS_STATUS_SUCCESS;
}

enum ps_status ps_destroy_filesystem(struct ps_filesystem *object)
{
        if (!object) {
                return PS_STATUS_SUCCESS;
        }

        free(object);
        return PS_STATUS_SUCCESS;
}