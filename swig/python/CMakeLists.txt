# Include python
find_package(PythonLibs REQUIRED)
include_directories(${PYTHON_INCLUDE_PATH})

set(CMAKE_SWIG_FLAGS "")

# Define nature of bindings (from cpp to python)
set_source_files_properties(../core.i PROPERTIES CPLUSPLUS ON)
# set_source_files_properties(../module.i PROPERTIES CPLUSPLUS ON)
# set_source_files_properties(../parameter.i PROPERTIES CPLUSPLUS ON)
# set_source_files_properties(../config.i PROPERTIES CPLUSPLUS ON)

set(PYTHON_PROJECT_DIR ${PROJECT_BINARY_DIR}/swig/python/)

# Add swig module
swig_add_library(pydsp
    TYPE MODULE
    LANGUAGE python
    SOURCES ../core.i
    # SOURCES ../module.i ../parameter.i ../config.i
    # OUTFILE_DIR ${PYTHON_PROJECT_DIR}/wrappers
    OUTPUT_DIR ${PYTHON_PROJECT_DIR}/pydsp/
    )

# Define where the .so should be generated
set_target_properties(pydsp PROPERTIES LIBRARY_OUTPUT_DIRECTORY ${PYTHON_PROJECT_DIR}/pydsp/)

# Alternative : tells that the so should be copied somewhere
# set_target_properties(pydsp PROPERTIES INSTALL_RPATH "$ORIGIN:$ORIGIN/../../${PYTHON_PROJECT}/.libs")

# ??
# add_library(${PROJECT_NAMESPACE}::pydsp ALIAS pydsp)

# Include directories to look for headers
target_include_directories(pydsp
  PRIVATE
  ../../include
  ${Python3_INCLUDE_DIRS}
  )

# Contents of target property INCLUDE_DIRECTORIES will be forwarded to SWIG compiler
set_property(TARGET pydsp PROPERTY SWIG_USE_TARGET_INCLUDE_DIRECTORIES ON)

# Link library to the Python package
swig_link_libraries(pydsp 
    cpppythonbinderlib 
    ${PYTHON_LIBRARIES}
    )
    
# Create Python package structure
# file(GENERATE OUTPUT ${PYTHON_PROJECT_DIR}/pydsp/core/__init__.py CONTENT "")
file(GENERATE OUTPUT ${PYTHON_PROJECT_DIR}/pydsp/__init__.py CONTENT "")

# Configure (using cmake variables) setup.py and copy to output directory
set(SETUP_PY_IN ${CMAKE_CURRENT_SOURCE_DIR}/setup.py.in)
set(SETUP_PY_OUT ${PYTHON_PROJECT_DIR}/setup.py)
configure_file(${SETUP_PY_IN} ${SETUP_PY_OUT})

# New build target : Install Python package using generated setup.py
add_custom_target(install-python 
    DEPENDS ${PYTHON_PROJECT_DIR}/pydsp/_pydsp.so 
    COMMAND python ${SETUP_PY_OUT} bdist_wheel
    )
