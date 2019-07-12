cmake_minimum_required(VERSION 3.4.1)

project(heifsharp LANGUAGES CXX C)

if (TARGET heifpp)
    message("using existing heifpp target")
else()
    add_subdirectory("../../" ${PROJECT_BINARY_DIR}/heif)
endif()

set(api_cpp_path "../../HeifNative/srcs/api-cpp")

file(GLOB EXPORT_SOURCES "*.cpp")

source_group("" FILES ${EXPORT_SOURCES})

add_library( # Sets the name of the library.
           heifsharp
           # Sets the library as a shared library.
           SHARED
           ${EXPORT_SOURCES}
           )

target_link_libraries(heifsharp heifpp)