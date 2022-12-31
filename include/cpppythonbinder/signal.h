#ifndef __SIGNAL_H__
#define __SIGNAL_H__

#include "types.h"
#include "parameter.h"
#include <string>
#include <stdint.h>
#include <vector>

// todo : handle internals as parameters to have access to caps?
// todo : count the number of pushes (frames) and dump it as well
// todo : turn Signal into an interface that cannot be used?

class Signal
{
public:
    // default constructor
    Signal(std::string name, sample_type_t type, int rate, std::vector<int> dims);

    // push data to the delayline
    Push(void *data, int nels);

    // pull data from the delayline
    Pull(void *data, int nels);

    // dump to file
    Dump(std::string fname);

    // getters
    std::string GetName() { return this->name; };
    int GetRate() { return this->rate; };
    sample_type_t GetType() { return this->type; };

private:
    std::string name;        // name of the signal
    sample_type_t type;      // sample data type
    int ndims;               // number of dimensions
    int rate;                // sampling rate
    int8_t *circular_buffer; // todo : implement
};

class Signal0d : Signal
{
public:
    // 0d arrays with labels -> tuple (label, value of given type)
    Signal0d(std::string name);

    // add a new item to the list
    int AddItem(std::string label, sample_type_t type);

    // remove a specific item
    int DeleteItem(std::string label);


private:
    // todo : find array type to store the tuple (label, sample_type, value)
};

class Signal1d : Signal
{
public:
    // default constructor (length being defined either in samples or duration sec))
    // note : the default copy constructor can advantageously create quick duplicates 
    Signal1d(std::string name, int rate, int nchannels, int nsamples, sample_type_t type);
    Signal1d(std::string name, int rate, int nchannels, float duration, sample_type_t type);

    // todo : use parameters for the rate and other variables...
    ParameterInt rate; // todo : define in constructor?
    ParameterInt nchannels;
    ParameterInt dtype;

private:
    // default configuration, triggered when a parameter changes
    int Configure();
};

// todo : signal 2 : 1d arrays (time, spectrum...)
// todo : signal 3 : 2d arrays (images with channels)

#endif