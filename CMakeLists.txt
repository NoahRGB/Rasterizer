cmake_minimum_required(VERSION 3.10)

project(experiments)

# include_directories(${./include})

# target_include_directories(experiments PUBLIC "${./include}")

set(TARGET_H img.h colour.h vec3.h)
set(TARGET_SRC main.cpp img.cpp)

add_executable(main main.cpp img.cpp)
