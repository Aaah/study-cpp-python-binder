# Include python
find_package(PythonLibs REQUIRED)
include_directories(${PYTHON_INCLUDE_PATH})

set(CMAKE_SWIG_FLAGS "")

# Define nature of bindings (from cpp to python)
set_source_files_properties(../module.i PROPERTIES CPLUSPLUS ON)

# Add swig module
swig_add_library(pyDSP
    TYPE MODULE
    LANGUAGE python
    SOURCES ../module.i)

add_library(${PROJECT_NAMESPACE}::pyDSP ALIAS pyDSP)

# todo : replace with variables
swig_link_libraries(pyDSP ${CPPPYTHONBINDER_LIB} ${PYTHON_LIBRARIES})

# Include directories to look for headers
target_include_directories(pyDSP
  PRIVATE
  ../../include
  ${Python3_INCLUDE_DIRS}
  )

set_property(TARGET pyDSP PROPERTY SWIG_USE_TARGET_INCLUDE_DIRECTORIES ON)

# Files to install with Python
set(PYTHON_INSTALL_FILES ${CMAKE_CURRENT_BINARY_DIR}/pyDSP.py ${CMAKE_CURRENT_BINARY_DIR}/_pyDSP.so)

# Configure setup.py and copy to output directory
set(SETUP_PY_IN ${CMAKE_CURRENT_SOURCE_DIR}/setup.py.in)
set(SETUP_PY_OUT ${CMAKE_CURRENT_BINARY_DIR}/setup.py)
configure_file(${SETUP_PY_IN} ${SETUP_PY_OUT})

# Install target using generated setup.py
add_custom_target(install-python 
    DEPENDS _pyDSP.so 
    COMMAND python ${SETUP_PY_OUT} install
    )
