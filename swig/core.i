%module core

%include "std_string.i"

// Add necessary symbols to generated header
%{
#define SWIG_FILE_WITH_INIT
#include "cpppythonbinder/config.h"
#include "cpppythonbinder/parameter.h"
#include "cpppythonbinder/module.h"
%}

// Process symbols in header
%include "cpppythonbinder/config.h"
%include "cpppythonbinder/parameter.h"
%include "cpppythonbinder/module.h"