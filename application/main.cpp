#include "cpppythonbinder/module.h"
#include "cpppythonbinder/parameter.h"


int main(int argc, char **argv)
{
    // create a module based on this configuration
    Module mod = Module("assets/config.json");
    mod.Process();

}