# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.3.2 FATAL_ERROR)

project (heif LANGUAGES CXX C)

# Include sub-projects.
add_subdirectory ("src/HeifNative/srcs")
