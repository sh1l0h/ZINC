#ifndef ZINC_CAMERA_H
#define ZINC_CAMERA_H

#include "./mat4.h"
#include "./vec3.h"

/**
 * @brief Calculates the view matrix for a camera.
 *
 * @param mat The output view matrix.
 * @param pos The position of the camera.
 * @param right The right vector of the camera.
 * @param up The up vector of the camera.
 * @param forward The forward vector of the camera.
 */
void zinc_view_matrix(Mat4 mat, const Vec3 *pos, const Vec3 *right, const Vec3 *up, const Vec3 *forward);

/**
 * @brief Calculates the orthographic projection matrix.
 *
 * @param mat The output projection matrix.
 * @param far The far clipping plane.
 * @param near The near clipping plane.
 * @param top The top coordinate of the clipping box.
 * @param bottom The bottom coordinate of the clipping box.
 * @param right The right coordinate of the clipping box.
 * @param left The left coordinate of the clipping box.
 */
void zinc_orthographic_projection(Mat4 mat, f32 far, f32 near, f32 top, f32 bottom, f32 right, f32 left);

/**
 * @brief Calculates the perspective projection matrix.
 *
 * @param mat The output projection matrix.
 * @param far The far clipping plane.
 * @param near The near clipping plane.
 * @param fov The field of view angle in radians.
 * @param aspect_ratio The aspect ratio of the screen.
 */
void zinc_persective_projection(Mat4 mat, f32 far, f32 near, f32 fov, f32 aspect_ratio);

#endif
