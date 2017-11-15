#include "../include/passion.h"

int run_script(int argc, char **argv);

struct ps_passion *passion = NULL;

int main(int argc, char **argv)
{        
        ps_initialize(PS_VERSION_CURRENT, &passion);

        char content[512];
        uint32_t max_size = 512;

        passion->filesystem->read(
                passion->filesystem,
                "example-01/__main__.py", 
                PS_FILESYSTEM_READ_ALL,

                content, &max_size
        );

        run_script(argc, argv);

        ps_deinitialize(passion);
        return 0;
}

int run_script(int argc, char **argv)
{
        const char *usage = 
                "No game to run.\n"
                "Usage: \n"
                "\t" "passion <game-folder> [game-options]\n";

        if (argc < 2) {
                printf(usage);
                return 0;
        }

        char filename[1024];
        strcpy(filename, argv[1]);
        strcat(filename, "/__main__.py");

        uint32_t filesize = 0;
        passion->filesystem->get_size(passion->filesystem,
                filename, &filesize);

        if (filesize == 0) 
                return 0;

        char *content = malloc(filesize + 1);
        passion->filesystem->read(passion->filesystem,
                filename, filesize, content, &filesize);
        content[filesize] = 0;

        Py_SetProgramName(L"passion");
        Py_Initialize();

        PyRun_SimpleString(content);

        Py_FinalizeEx();

        free(content);
        return 0;
}