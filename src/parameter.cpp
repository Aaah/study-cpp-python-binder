#include "cpppythonbinder/parameter.h"

// PARAMETER

DSPParameter::DSPParameter()
{
    return;
}

// append callback to list
int DSPParameter::AddCallback(std::function<int(void)>)
{
    // todo
    return 0;
}

// remove callback from list
int DSPParameter::RemoveCallback(std::function<int(void)>)
{
    // todo
    return 0;
}

// execute the callbacks in the list
int DSPParameter::OnValueChange(void)
{
    // todo
    return 0;
}

ParameterBool::ParameterBool(std::string name, bool defaultv)
{
    // todo
    return;
}

int ParameterBool::SetValue(bool val)
{
    // todo
    return 0;
}

// PARAMETER RANGED

ParameterRanged::ParameterRanged()
{
    return;
}

ParameterRangedFloat::ParameterRangedFloat(std::string name, float minv, float maxv, float resv, float defaultv)
{
    // todo
    return;
}

int ParameterRangedFloat::SetValue(float v)
{
    // todo : boundaries & resolution + callback
    return 0;
}

ParameterRangedInt::ParameterRangedInt(std::string name, int minv, int maxv, int resv, int defaultv)
{
    // todo
    return;
}

int ParameterRangedInt::SetValue(int v)
{
    // todo : boundaries & resolution + callback
    return 0;
}

ParameterRangedString::ParameterRangedString(std::string name, std::string fmt, std::string defaultv)
{
    // todo
    return;
}

int ParameterRangedString::SetValue(std::string v)
{
    // todo : boundaries & resolution + callback
    return 0;
}

// PARAMETER SET

ParameterSet::ParameterSet()
{
    return;
}

ParameterSetFloat::ParameterSetFloat(std::string name, std::vector<float> set, float defaultv)
{
    // todo
    return;
}

int ParameterSetFloat::SetValue(float v)
{
    // todo : boundaries & resolution + callback
    return 0;
}

ParameterSetInt::ParameterSetInt(std::string name, std::vector<int> set, int defaultv)
{
    // todo
    return;
}

int ParameterSetInt::SetValue(int v)
{
    // todo : boundaries & resolution + callback
    return 0;
}

ParameterSetString::ParameterSetString(std::string name, std::vector<std::string> set, std::string defaultv)
{
    // todo
    return;
}

int ParameterSetString::SetValue(std::string v)
{
    // todo : boundaries & resolution + callback
    return 0;
}