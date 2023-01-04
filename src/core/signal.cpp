#include "cpppythonbinder/core/signal.h"

DSPSignal::DSPSignal(std::string name, sample_type_t type, int rate, int nchannels, std::vector<int> dims)
{
    // todo
    return;
}

int DSPSignal::Push(void *data, int nels)
{
    // todo
    return 0;
}

int DSPSignal::Pull(void *data, int nels)
{
    // todo
    return 0;
}

int DSPSignal::Dump(std::string fname)
{
    // todo
    return 0;
}

/*
DSPSignal0d::DSPSignal0d(std::string name)
{
    // todo
    return;
}

int DSPSignal0d::AddItem(std::string label, sample_type_t type)
{
    // todo
    return 0;
}

int DSPSignal0d::DeleteItem(std::string label)
{
    // todo
    return 0;
}

DSPSignal1d::DSPSignal1d(std::string name, int rate, int nchannels, int nsamples, sample_type_t type)
{
    // todo
    return;
}

DSPSignal1d::DSPSignal1d(std::string name, int rate, int nchannels, float duration, sample_type_t type)
{
    // todo
    return;
}
*/
