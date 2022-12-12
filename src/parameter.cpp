#include "cpppythonbinder/parameter.h"

ParameterFloat::ParameterFloat(std::string name, float minv, float maxv, float resv, float defaultv)
{
    // todo
}

ParameterFloat::ParameterFloat(std::string name, float minv, float maxv, float resv, float defaultv, int (*callback)(void))
{
    // todo
}

float ParameterFloat::SetValue(float v)
{

    // todo : boundaries & resolution + callback
    return v;
}
