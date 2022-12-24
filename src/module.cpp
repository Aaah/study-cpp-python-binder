#include "cpppythonbinder/module.h"
#include "cpppythonbinder/config.h"

// Module::Module(Config cfg)
// {
//     return;
// }

Module::Module(std::string config_path)
{
    fprintf(stdout, "Creating module!\n");
    return;
}

int Module::Configure()
{
    return 0;
}

// int Module::Configure(Config cfg)
// {
//     return 0;
// }

int Module::Reset()
{
    return 0;
}

int Module::Process()
{
    fprintf(stdout, "Now processing!\n");
    return 0;
}

int Module::Process(float *iovec, int len)
{
    return 0;
}

int Module::Process(int *iovec, int len)
{
    return 0;
}
