#ifndef __PARAMETER_H__
#define __PARAMETER_H__

#include <string>

class Parameter
{
    // todo : factorize between int, bool, float, strings, choice...
};

class ParameterFloat : public Parameter
{

public:
    // default constructor
    // todo : callback configure from module (via config?)
    ParameterFloat(std::string name,       // name of the parameter
                   float minv,             // minimum value
                   float maxv,             // maximum value
                   float resv,             // resolution
                   float defaultv,         // default value
                   int (*callback)(void)); // callback to Configure() or Restart() of the parent module

    ParameterFloat(std::string name, // name of the parameter
                   float minv,       // minimum value
                   float maxv,       // maximum value
                   float resv,       // resolution
                   float defaultv);  // default value

    // getter
    float GetValue(void) { return this->value; };

    // setter
    float SetValue(float v);

    // todo : caps
    // todo : other getters
    // todo : reset

private:
    std::string name;
    float value;
    float minv;
    float stepv;
    float resv;
    float defaultv;
    int (*callback)(void);
};

#endif