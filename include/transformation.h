#ifndef ZINC_TRANSFORATION_H
#define ZINC_TRANSFORATION_H

#include "mat4.h"
#include "vec3.h"
/**
 *
 */
void zinc_translate(Mat4 mat, const Vec3 *vec);

void zinc_scale(Mat4 mat, const Vec3 *vec);

void zinc_rotate_x(Mat4 mat, f32 angle);
void zinc_rotate_y(Mat4 mat, f32 angle);
void zinc_rotate_z(Mat4 mat, f32 angle);
void zinc_rotate(Mat4 mat, f32 angle, const Vec3 *axis);

#endif
