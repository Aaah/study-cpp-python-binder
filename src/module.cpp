#include "cpppythonbinder/module.h"
#include "cpppythonbinder/config.h"

Module::Module(Config cfg)
{
    return;
}

int Module::Configure()
{
    return 0;
}

int Module::Configure(Config cfg)
{
    return 0;
}

int Module::Reset()
{
    return 0;
}

int Module::Process()                     
{
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
