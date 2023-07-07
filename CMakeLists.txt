cmake_minimum_required(VERSION 3.10)
project(ZINC LANGUAGES C)

add_library(zinc 
    src/vec2.c
    src/vec3.c
    src/vec4.c
    src/vec2i.c
    src/vec3i.c
    src/vec4i.c
    src/mat2.c
    src/mat3.c
    src/mat4.c
    src/camera.c
    src/io.c
    )

target_include_directories(zinc PUBLIC include)
