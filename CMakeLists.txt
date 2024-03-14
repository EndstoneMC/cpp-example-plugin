cmake_minimum_required(VERSION 3.15)

project(endstone_example_plugin CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


# ===============
# Compiler Check
# ===============
if (WIN32)
    if (NOT MSVC)
        message(FATAL_ERROR "MSVC is required on Windows.")
    endif ()
    add_compile_definitions(_ITERATOR_DEBUG_LEVEL=0)
elseif (UNIX)
    if (NOT CMAKE_CXX_COMPILER_ID MATCHES "Clang")
        message(FATAL_ERROR "Clang is required on Linux.")
    endif ()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -stdlib=libc++")
    link_libraries("-static-libgcc -static-libstdc++")
    link_libraries(libc++.a)
    link_libraries(libc++abi.a)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIC")
else ()
    message(FATAL_ERROR "${CMAKE_SYSTEM_NAME} (${CMAKE_SYSTEM_PROCESSOR}) is not supported")
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


# ===============
# Endstone API
# ===============
FetchContent_Declare(
        endstone
        GIT_REPOSITORY https://github.com/EndstoneMC/endstone.git
        GIT_TAG main # or set to a specific version tag
)
FetchContent_GetProperties(endstone)
if (NOT endstone_POPULATED)
    FetchContent_Populate(endstone)
endif ()
add_library(endstone_headers INTERFACE)
add_library(endstone::headers ALIAS endstone_headers)
target_include_directories(endstone_headers INTERFACE ${endstone_SOURCE_DIR}/include)
target_link_libraries(endstone_headers INTERFACE fmt::fmt)


# ===============
# Build
# ===============
add_library(${PROJECT_NAME} SHARED src/example_plugin.cpp)
target_include_directories(${PROJECT_NAME} PUBLIC include)
target_link_libraries(${PROJECT_NAME} PRIVATE endstone::headers)

# ===============
# Install
# ===============
install(TARGETS ${PROJECT_NAME})
