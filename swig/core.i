%module core

%include "std_string.i"

// Add necessary symbols to generated header
%{
#define SWIG_FILE_WITH_INIT
#include "cpppythonbinder/core/config.h"
#include "cpppythonbinder/core/parameter.h"
#include "cpppythonbinder/core/module.h"
%}

// Process symbols in header
%include "cpppythonbinder/core/config.h"
%include "cpppythonbinder/core/parameter.h"
%include "cpppythonbinder/core/module.h"