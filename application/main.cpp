#include "cpppythonbinder/module.h"
#include "cpppythonbinder/parameter.h"


int main(int argc, char **argv)
{
    // create a configuration
    Config cfg;
    cfg.AddParameter(ParameterFloat("param1", 0.0, 1.0, 0.001, 0.0));

    // create a module based on this configuration
    Module mod = Module(cfg);
    mod.Process();

    // todo : process with debug information ("signals")
}