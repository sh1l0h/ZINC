#ifndef ZINC_MAT4_H
#define ZINC_MAT4_H

#include "types.h"
#include "vec4.h"

#define ZINC_MAT4_ZERO {{0.0f, 0.0f, 0.0f},	\
						{0.0f, 0.0f, 0.0f},	\
						{0.0f, 0.0f, 0.0f}}

#define ZINC_MAT4_EYE {{1.0f, 0.0f, 0.0f},	\
					   {0.0f, 1.0f, 0.0f},	\
					   {0.0f, 0.0f, 1.0f}}

typedef f32 Mat4[4][4];

/**
 * @brief Sets all elements of the 4x4 matrix to zero.
 *
 * @param mat The 4x4 matrix to be zeroed.
 */
void zinc_mat4_zero(Mat4 mat);

/**
 * @brief Sets the 4x4 matrix as an identity matrix.
 *
 * @param mat The 4x4 matrix to be set as an identity matrix.
 */
void zinc_mat4_eye(Mat4 mat);

/**
 * @brief Scales a 4x4 matrix by a scalar value.
 *
 * @param mat The 4x4 matrix to be scaled.
 * @param c The scalar value to scale the matrix by.
 */
void zinc_mat4_scale(Mat4 mat, f32 c);

/**
 * @brief Copies the values of one 4x4 matrix to another.
 *
 * @param src The source matrix to copy values from.
 * @param dest The destination matrix to copy values to.
 */
void zinc_mat4_copy(const Mat4 src, Mat4 dest);

/**
 * @brief Adds two 4x4 matrices element-wise and stores the result in a destination matrix.
 *
 * @param a The first matrix to add.
 * @param b The second matrix to add.
 * @param dest The matrix to store the addition result.
 */
void zinc_mat4_add(const Mat4 a, const Mat4 b, Mat4 dest);

/**
 * @brief Subtracts one 4x4 matrix from another element-wise and stores the result in a destination matrix.
 *
 * @param a The matrix to subtract from.
 * @param b The matrix to subtract.
 * @param dest The matrix to store the subtraction result.
 */
void zinc_mat4_sub(const Mat4 a, const Mat4 b, Mat4 dest);

/**
 * @brief Multiplies two 4x4 matrices and stores the result in a destination matrix.
 *
 * @param a The first matrix to multiply.
 * @param b The second matrix to multiply.
 * @param dest The matrix to store the multiplication result.
 */
void zinc_mat4_mul(const Mat4 a, const Mat4 b, Mat4 dest);

/**
 * @brief Multiplies a 4x4 matrix by a 4D vector and stores the result in a destination vector.
 *
 * This function performs a matrix-vector multiplication, where the 4x4 matrix is multiplied by the 4D vector.
 * The resulting vector is stored in the destination vector.
 *
 * @param mat The 4x4 matrix to multiply with the vector.
 * @param vec The 4D vector to be multiplied with the matrix.
 * @param dest The vector to store the multiplication result.
 */
void zinc_mat4_mulv(const Mat4 mat, const Vec4 *vec, Vec4 *dest);

/**
 * @brief Transposes a 4x4 matrix and stores the result in a destination matrix.
 *
 * @param mat The matrix to transpose.
 * @param dest The matrix to store the transposed result.
 */
void zinc_mat4_transpose_to(const Mat4 mat, Mat4 dest);

/**
 * @brief Transposes a 4x4 matrix in-place.
 *
 * @param mat The matrix to transpose.
 */
void zinc_mat4_transpose(Mat4 mat);

/**
 * @brief Calculates the determinant of a 4x4 matrix.
 *
 * @param mat The matrix to calculate the determinant of.
 * @return The determinant of the matrix.
 */
f32 zinc_mat4_determinant(const Mat4 mat);

/**
 * @brief Calculates the trace of a 4x4 matrix.
 *
 * @param mat The matrix to calculate the trace of.
 * @return The trace of the matrix.
 */
f32 zinc_mat4_trace(const Mat4 mat);

#endif
