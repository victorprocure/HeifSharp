# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.3.2 FATAL_ERROR)

project (HeifSharp LANGUAGES CXX C)

# Include sub-projects.
set(heif_native_src "HeifNative/srcs")
add_subdirectory("${heif_native_src}")

add_subdirectory("HeifSharp.Wrapper/api-csharp")
