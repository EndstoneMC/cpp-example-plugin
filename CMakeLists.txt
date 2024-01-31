cmake_minimum_required(VERSION 3.15)

project(endstone_cpp_plugin CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

add_compile_definitions(_ITERATOR_DEBUG_LEVEL=0)


# ===============
# Compiler Check
# ===============
if (WIN32 AND NOT MSVC)
    message(FATAL_ERROR "MSVC is required on Windows")
elseif (UNIX)
    if (NOT CMAKE_CXX_COMPILER_ID MATCHES "Clang")
        message(FATAL_ERROR "Clang is required on Linux")
    endif ()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -stdlib=libc++")
endif ()


# ===============
# Dependencies
# ===============
include(FetchContent)
FetchContent_Declare(
        fmt
        GIT_REPOSITORY https://github.com/fmtlib/fmt.git
        GIT_TAG 10.2.1
)
FetchContent_MakeAvailable(fmt)

FetchContent_Declare(
        endstone
        GIT_REPOSITORY https://github.com/EndstoneMC/endstone.git
        GIT_TAG v1.20.51
)
FetchContent_GetProperties(endstone)
if (NOT endstone_POPULATED)
    FetchContent_Populate(endstone)
endif ()


# ===============
# Build
# ===============
add_library(${PROJECT_NAME} SHARED src/endstone_cpp_plugin.cpp)
target_include_directories(${PROJECT_NAME} PUBLIC include)
target_include_directories(${PROJECT_NAME} PRIVATE ${endstone_SOURCE_DIR}/include)
target_link_libraries(${PROJECT_NAME} PRIVATE fmt::fmt)


# ===============
# Install
# ===============
install(TARGETS ${PROJECT_NAME})
