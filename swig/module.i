%module pyDSP

%include "std_string.i"

// Add necessary symbols to generated header
%{
#define SWIG_FILE_WITH_INIT
#include "cpppythonbinder/module.h"
#include "cpppythonbinder/config.h"
#include "cpppythonbinder/parameter.h"
%}

// Process symbols in header
%include "cpppythonbinder/module.h"
#include "cpppythonbinder/config.h"
#include "cpppythonbinder/parameter.h"