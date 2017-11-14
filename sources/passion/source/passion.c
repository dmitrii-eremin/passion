#include "../include/passion.h"

int main(int argc, char **argv)
{
        enum ps_status status = ps_initialize(PS_VERSION_CURRENT);
        if (PS_STATUS_FAILED(status)) {
                return 0;
        }

        ps_deinitialize();
        return 0;
}