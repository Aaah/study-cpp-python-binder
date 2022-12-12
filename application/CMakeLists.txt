# Dependencies

add_executable(cpppythonbinder main.cpp)

target_include_directories(cpppythonbinder PRIVATE 
# ../extern/spdlog/include/
# ../extern/stb/ 
# ../extern/json/include/
# ../extern/fsm
)

target_compile_features(cpppythonbinder PRIVATE cxx_std_17)
target_link_libraries(cpppythonbinder PRIVATE cpppythonbinderlib -lpthread)

# compile options
target_compile_options(cpppythonbinder PRIVATE -std=c++11 -g -Wall -Wformat)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})

install(TARGETS cpppythonbinder
    COMPONENT aaah
)

SET(CPACK_GENERATOR "DEB")
SET(CPACK_DEBIAN_PACKAGE_MAINTAINER "KK") #required
INCLUDE(CPack)