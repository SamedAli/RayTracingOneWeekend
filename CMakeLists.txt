cmake_minimum_required(VERSION 3.20)
project(RayTracingOneWeekend LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(SOURCES
    src/main.cpp
    src/vec3.cpp
    src/colorUtilities.cpp
    src/ray.cpp
    src/sphere.cpp
    src/hittableObjectsList.cpp
    src/hitpoint.cpp
    src/interval.cpp
    src/camera.cpp
    src/lambertian.cpp
    src/metal.cpp
    src/material.cpp
    src/dielectric.cpp
)

add_executable(${PROJECT_NAME}
    ${SOURCES}
)

target_include_directories(${PROJECT_NAME} PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)
