#include <stdio.h>

#include "../include/passion.h"

int main(int argc, char **argv)
{
        struct ps_passion *passion = NULL;
        enum ps_status status = ps_initialize(PS_VERSION_CURRENT, &passion);
        if (PS_STATUS_FAILED(status)) {
                return 0;
        }

        ps_version version = { 0 };
        passion->get_version(passion, &version);

        printf("Passion version is: %d.%d.%d\n",
                PS_VERSION_MAJOR(version),
                PS_VERSION_MINOR(version),
                PS_VERSION_PATCH(version)
        );

        ps_deinitialize(passion);
        return 0;
}