%module pyDSP

// Add necessary symbols to generated header
%{
#include "cpppythonbinder/module.h"
%}

// Process symbols in header
%include "cpppythonbinder/module.h"