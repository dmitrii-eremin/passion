#include "../include/passion.h"

int main(int argc, char **argv)
{
        const char *usage = 
                "No game to run.\n"
                "Usage: \n"
                "\t" "passion <game-folder> [game-options]\n";

        if (argc < 2) {
                printf(usage);
                return 0;
        }

        struct ps_passion *passion = NULL;
        enum ps_status status = ps_initialize(PS_VERSION_CURRENT, &passion);
        if (PS_STATUS_FAILED(status)) {
                return 0;
        }

        char filename[1024];
        strcpy(filename, argv[1]);
        strcat(filename, "/__main__.py");

        long fsize = get_file_size(filename);
        if (fsize <= 0) {
                printf(
                        "Game '%s' or file '__main__.py' doesn't exist.", 
                        filename
                );
                return 0;
        }

        char *content = malloc(fsize + 1);
        read_whole_file(filename, content, fsize);
        content[fsize] = '\0';

        Py_SetProgramName(L"passion");
        Py_Initialize();

        PyRun_SimpleString(content);

        Py_FinalizeEx();

        free(content);

        ps_deinitialize(passion);
        return 0;
}

void read_whole_file(const char *filename, char *content, long maxlen)
{
        FILE *file = fopen(filename, "rb");
        if (!file) 
                return;

        fseek(file, 0, SEEK_END);
        long size = ftell(file);
        fseek(file, 0, SEEK_SET);

        size = min(size, maxlen);
        fread(content, size, 1, file);
        fclose(file);
}

long get_file_size(const char *filename)
{
        FILE *file = fopen(filename, "rb");
        if (!file)
                return 0;

        fseek(file, 0, SEEK_END);
        long size = ftell(file);
        fclose(file);
        return size;
}