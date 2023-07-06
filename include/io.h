#ifndef ZINC_IO_H
#define ZINC_IO_H

#include "./vec2.h"
#include "./vec2i.h"
#include "./vec3.h"
#include "./vec3i.h"
#include "./vec4.h"
#include "./vec4i.h"

void zinc_vec2_print(const Vec2 *vec);
void zinc_vec2i_print(const Vec2i *vec);
void zinc_vec3_print(const Vec3 *vec);
void zinc_vec3i_print(const Vec3i *vec);
void zinc_vec4_print(const Vec4 *vec);
void zinc_vec4i_print(const Vec4i *vec);

#include "./mat2.h"
#include "./mat3.h"
#include "./mat4.h"

void zinc_mat2_print(const Mat2 mat);
void zinc_mat3_print(const Mat3 mat);
void zinc_mat4_print(const Mat4 mat);

#endif
