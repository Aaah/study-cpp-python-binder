#include "cpppythonbinder/core/module.h"
#include "cpppythonbinder/core/config.h"

DSPModule::DSPModule()
{
    return;
}

DSPModule::DSPModule(DSPConfig cfg)
{
    return;
}

DSPModule::DSPModule(std::string config_path)
{
    fprintf(stdout, "Creating module!\n");
    return;
}

int DSPModule::Configure()
{
    return 0;
}

int DSPModule::Configure(DSPConfig cfg)
{
    return 0;
}

int DSPModule::Configure(std::string config_path)
{
    return 0;
}

int DSPModule::Reset()
{
    return 0;
}

DSPApplication::DSPApplication(DSPConfig cfg)
{
    return;
}

DSPApplication::DSPApplication(std::string config_path)
{
    return;
}
