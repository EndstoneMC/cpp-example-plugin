cmake_minimum_required(VERSION 3.15)

project(endstone_cpp_plugin CXX)

find_package(endstone REQUIRED COMPONENTS)

add_library(${PROJECT_NAME} SHARED src/endstone_cpp_plugin.cpp)
target_include_directories(${PROJECT_NAME} PUBLIC include)
target_link_libraries(${PROJECT_NAME} PRIVATE endstone::headers)

install(TARGETS ${PROJECT_NAME})
