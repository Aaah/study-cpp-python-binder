#ifndef __CONFIG_H__
#define __CONFIG_H__

#include "parameter.h"

class Config
{

public:
    // default constructor
    Config();

    // add a parameter to the list
    int AddParameter(const Parameter param);

    // remove a parameter by its name
    int RemoveParameter(const std::string);

    // dump the full configuration to a json file
    int Save(void);

    // load the full configuration from a json file
    int Load(const std::string);

private:
};

#endif