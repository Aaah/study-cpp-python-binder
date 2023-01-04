#ifndef __DSPMODULE_H__
#define __DSPMODULE_H__

#include "parameter.h"
#include "config.h"
#include "signal.h"
#include <string>
#include <vector>

/*

A DSP DSPModule is setup using a DSPConfig.

The DSPConfig contains DSP Parameters.

*/

class DSPModule
{

public:
    DSPModule();                     // default constructor
    DSPModule(DSPConfig cfg);        // from cfg object
    DSPModule(std::string cfg_path); // path to config file

    // configuration
    int Configure();                        // configure using the current cfg
    int Configure(DSPConfig cfg);           // configure from cfg object
    int Configure(std::string path_to_cfg); // configure from file

    // restart (Configure and reset variables)
    int Reset();

    // processing : prototype may change, but all modules need a process method

    // -- internals
    DSPConfig cfg; // configuration object
};

class DSPApplication : public DSPModule
{
public:
    // default constructor
    DSPApplication(DSPConfig cfg);
    DSPApplication(std::string path_to_cfg);

private:
    // input pad / signals
    std::vector<DSPSignal> inputs;

    // output pad / signals
    std::vector<DSPSignal> outputs;

    // todo : MQTT
};
#endif