#include <libpassion.h>

enum ps_status ps_initialize(ps_version version)
{
        if (version != PS_VERSION_CURRENT)
                return PS_STATUS_INCOMPATIBLE_VERSION;
        return PS_STATUS_SUCCESS;
}

enum ps_status ps_deinitialize()
{
        return PS_STATUS_SUCCESS;
}