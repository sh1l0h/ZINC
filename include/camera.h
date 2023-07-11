#ifndef ZINC_CAMERA_H
#define ZINC_CAMERA_H

#include "./mat4.h"
#include "./vec3.h"

/**
 * @brief Calculates the view matrix for a camera.
 *
 * @param[out] mat The output view matrix.
 * @param[in] pos The position of the camera.
 * @param[in] right The right vector of the camera.
 * @param[in] up The up vector of the camera.
 * @param[in] forward The forward vector of the camera.
 */
void zinc_view_matrix(Mat4 mat, const Vec3 *pos, const Vec3 *right, const Vec3 *up, const Vec3 *forward);

/**
 * @brief Calculates the orthographic projection matrix.
 *
 * @param[out] mat The output projection matrix.
 * @param[in] far The far clipping plane.
 * @param[in] near The near clipping plane.
 * @param[in] top The top coordinate of the clipping box.
 * @param[in] bottom The bottom coordinate of the clipping box.
 * @param[in] right The right coordinate of the clipping box.
 * @param[in] left The left coordinate of the clipping box.
 */
void zinc_orthographic_projection(Mat4 mat, f32 far, f32 near, f32 top, f32 bottom, f32 right, f32 left);

/**
 * @brief Calculates the perspective projection matrix.
 *
 * @param[out] mat The output projection matrix.
 * @param[in] far The far clipping plane.
 * @param[in] near The near clipping plane.
 * @param[in] fov The field of view angle in radians.
 * @param[in] aspect_ratio The aspect ratio of the screen.
 */
void zinc_persective_projection(Mat4 mat, f32 far, f32 near, f32 fov, f32 aspect_ratio);

#endif
