#ifndef __DSPSIGNAL_H__
#define __DSPSIGNAL_H__

#include "types.h"
#include "parameter.h"
#include "config.h"
#include <string>
#include <stdint.h>
#include <vector>

// todo : handle internals as parameters to have access to caps?
// todo : count the number of pushes (frames) and dump it as well
// todo : state related to real-time? full/...

class DSPSignal
{
public:
    // default constructor
    DSPSignal(std::string name, sample_type_t type, int rate, int nchannels, std::vector<int> dims);

    // push data to the delayline
    int Push(void *data, int nels);

    // pull data from the delayline
    int Pull(void *data, int nels);

    // dump to file ?
    int Dump(std::string fname);

    // -- attributes
    DSPConfig cfg; // capabilities

    // -- getters
    std::string GetName() { return this->name; };
    int GetRate() { return this->rate; };
    sample_type_t GetType() { return this->type; };

private:
    std::string name;        // name of the signal
    sample_type_t type;      // sample data type
    int nchannels;           // number of channels
    int ndims;               // number of dimensions
    int rate;                // sampling rate
    int8_t *circular_buffer; // todo : implement
};

/*
class DSPSignal0d : public DSPSignal
{
public:
    // 0d arrays with labels -> tuple (label, value of given type)
    DSPSignal0d(std::string name);

    // add a new item to the list
    int AddItem(std::string label, sample_type_t type);

    // remove a specific item
    int DeleteItem(std::string label);

private:
    // todo : find array type to store the tuple (label, sample_type, value)
};

class DSPSignal1d : public DSPSignal
{
public:
    // default constructor (length being defined either in samples or duration sec))
    // note : the default copy constructor can advantageously create quick duplicates
    DSPSignal1d(std::string name, int rate, int nchannels, int nsamples, sample_type_t type);
    DSPSignal1d(std::string name, int rate, int nchannels, float duration, sample_type_t type);

    // todo : use parameters for the rate and other variables...
    // ParameterInt rate; // todo : define in constructor?
    // ParameterInt nchannels;
    // ParameterInt dtype;

private:
    // default configuration, triggered when a parameter changes
    // int Configure();
};

// todo : signal 2 : 1d arrays (time, spectrum...)
// todo : signal 3 : 2d arrays (images with channels)

*/

#endif