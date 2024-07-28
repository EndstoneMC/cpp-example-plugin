cmake_minimum_required(VERSION 3.15)

project(cpp_example CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
        endstone
        GIT_REPOSITORY https://github.com/EndstoneMC/endstone.git
        GIT_TAG main # or set to a specific version tag
)
FetchContent_MakeAvailable(endstone)

add_library(${PROJECT_NAME} SHARED src/example_plugin.cpp)
target_include_directories(${PROJECT_NAME} PUBLIC include)
target_link_libraries(${PROJECT_NAME} PRIVATE endstone::headers)
set_target_properties(${PROJECT_NAME} PROPERTIES PREFIX "endstone_")

if (CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    target_compile_options(${PROJECT_NAME} PRIVATE -stdlib=libc++ -fPIC)
    target_link_libraries(${PROJECT_NAME} PRIVATE -static-libgcc -static-libstdc++ libc++.a libc++abi.a)
endif ()