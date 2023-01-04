set(CPPPYTHONBINDER_LIB cpppythonbinderlib)

# find all headers, optional but make them show up in IDEs
file(GLOB HEADER_LIST CONFIGURE_DEPENDS "${CppPythonBinder_SOURCE_DIR}/include/cpppythonbinder/*.h")

# Dependencies

# Make an automatic library - will be static or dynamic based on user setting
add_library(${CPPPYTHONBINDER_LIB}
module.cpp
parameter.cpp
config.cpp
signal.cpp
${HEADER_LIST})

target_include_directories(${CPPPYTHONBINDER_LIB} PRIVATE 
# ../extern/spdlog/include/
# ../extern/stb/ 
# ../extern/json/include/
# ../extern/fsm
)

# Reach other dependencies using CmakeLists 
# add_subdirectory(../extern/spdlog build_spdlog)
# add_subdirectory(../extern/json build_json)

# target_link_libraries(${CPPPYTHONBINDER_LIB} spdlog nlohmann_json -lpthread ${SDL2_LIBRARIES} ${OPENGL_LIBRARIES})
target_link_libraries(${CPPPYTHONBINDER_LIB} -lpthread)

# We need this directory, and users of our library will need it too
target_include_directories(${CPPPYTHONBINDER_LIB} PUBLIC ../include)

# All users of this library will need at least C++11
target_compile_options(${CPPPYTHONBINDER_LIB} PRIVATE -std=c++11 -g -Wall -Wformat -fPIC)
target_compile_definitions(${CPPPYTHONBINDER_LIB} PRIVATE SPDLOG_COMPILED_LIB)

# IDEs should put the headers in a nice place
source_group(
  TREE "${PROJECT_SOURCE_DIR}/include"
  PREFIX "Header Files"
  FILES ${HEADER_LIST})
