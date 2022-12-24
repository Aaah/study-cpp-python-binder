#ifndef __MODULE_H__
#define __MODULE_H__

#include <string>
#include "parameter.h"
#include "config.h"

/*

A DSP Module is setup using a Config.

The Config contains DSP Parameters.

*/

class Module
{

public:
    // Module(Config cfg);           // default constructor
    Module(std::string cfg_path); // path to config file

    // configuration
    int Configure();
    // int Configure(Config cfg);

    // restart (Configure and reset variables)
    int Reset();

    // processing
    int Process();                      // default (no use without input data?)
    int Process(float *iovec, int len); // floating-point implementation
    int Process(int *iovec, int len);   // fixed-point implementation
};

#endif