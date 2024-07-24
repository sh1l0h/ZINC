cmake_minimum_required(VERSION 3.10)
project(ZINC LANGUAGES C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED TRUE)

set(ZINC_BUILD)
option(ZINC_SHARED "" OFF)

if(ZINC_SHARED)
    set(ZINC_BUILD SHARED)
else()
    set(ZINC_BUILD STATIC)
endif()

add_library(${PROJECT_NAME}
    ${ZINC_BUILD}
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
    src/transformation.c
    src/io.c
    )

target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -Werror -O3)

target_include_directories(ZINC PUBLIC include)
target_link_libraries(${PROJECT_NAME} PUBLIC m)
