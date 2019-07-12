cmake_minimum_required(VERSION 3.4.1)

project(HeifNativeWrapper LANGUAGES CXX C)

set(api_cpp_path "../../HeifNative/srcs/api-cpp")

include_directories("${api_cpp_path}")

file(GLOB EXPORT_SOURCES "*.cpp")

source_group("" FILES ${EXPORT_SOURCES})

add_library( # Sets the name of the library.
           HeifNativeWrapper
           # Sets the library as a shared library.
           SHARED
           ${EXPORT_SOURCES}
           )

target_link_libraries(HeifNativeWrapper heifpp)