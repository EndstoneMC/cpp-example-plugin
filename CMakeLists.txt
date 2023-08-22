cmake_minimum_required(VERSION 3.25)

project(cpp_sample_plugin VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)

FetchContent_Declare(
        endstone
        GIT_REPOSITORY https://github.com/EndstoneMC/Endstone.git
        GIT_TAG main
)

FetchContent_MakeAvailable(endstone)

add_library(cpp_sample_plugin SHARED src/sample_plugin.cpp)
target_link_libraries(cpp_sample_plugin endstone::api)
target_include_directories(cpp_sample_plugin PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_compile_definitions(cpp_sample_plugin PRIVATE _ITERATOR_DEBUG_LEVEL=0)

install(TARGETS cpp_sample_plugin
        LIBRARY DESTINATION cpp_sample_plugin
        RUNTIME DESTINATION cpp_sample_plugin)
