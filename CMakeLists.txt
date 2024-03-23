# The following lines of boilerplate have to be in your project's
# CMakeLists in this exact order for cmake to work correctly
cmake_minimum_required(VERSION 3.16)
# set(CMAKE_C_STANDARD 90)

include($ENV{IDF_PATH}/tools/cmake/project.cmake)
project(hello_world)

configure_file(${CMAKE_SOURCE_DIR}/main.lua main.lua)
execute_process(COMMAND bash ${CMAKE_SOURCE_DIR}/prepare.sh)
