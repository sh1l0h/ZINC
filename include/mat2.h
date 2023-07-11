#ifndef ZINC_MAT2_H
#define ZINC_MAT2_H

#include "types.h"
#include "./vec2.h"

#define ZINC_MAT2_ZERO {{0.0f, 0.0f}, {0.0f, 0.0f}}

#define ZINC_MAT2_EYE {{0.0f, 0.0f}, {0.0f, 0.0f}}

typedef f32 Mat2[2][2];

/**
 * @brief Sets all elements of the 2x2 matrix to zero.
 *
 * @param[in, out] mat The 2x2 matrix to be zeroed.
 */
void zinc_mat2_zero(Mat2 mat);

/**
 * @brief Sets the 2x2 matrix as an identity matrix.
 *
 * @param[in, out] mat The 2x2 matrix to be set as an identity matrix.
 */
void zinc_mat2_eye(Mat2 mat);

/**
 * @brief Scales a 2x2 matrix by a scalar value.
 *
 * @param[in, out] mat The 2x2 matrix to be scaled.
 * @param[in] c The scalar value to scale the matrix by.
 */
void zinc_mat2_scale(Mat2 mat, f32 c);

/**
 * @brief Copies the values of one 2x2 matrix to another.
 *
 * @param[in] src The source matrix to copy values from.
 * @param[out] dest The destination matrix to copy values to.
 */
void zinc_mat2_copy(const Mat2 src, Mat2 dest);

/**
 * @brief Adds two 2x2 matrices element-wise and stores the result in a destination matrix.
 *
 * @param[in] a The first matrix to add.
 * @param[in] b The second matrix to add.
 * @param[out] dest The matrix to store the addition result.
 */
void zinc_mat2_add(const Mat2 a, const Mat2 b, Mat2 dest);

/**
 * @brief Subtracts one 2x2 matrix from another element-wise and stores the result in a destination matrix.
 *
 * @param[in] a The matrix to subtract from.
 * @param[in] b The matrix to subtract.
 * @param[out] dest The matrix to store the subtraction result.
 */
void zinc_mat2_sub(const Mat2 a, const Mat2 b, Mat2 dest);

/**
 * @brief Multiplies two 2x2 matrices and stores the result in a destination matrix.
 *
 * @param[in] a The first matrix to multiply.
 * @param[in] b The second matrix to multiply.
 * @param[out] dest The matrix to store the multiplication result.
 */
void zinc_mat2_mul(const Mat2 a, const Mat2 b, Mat2 dest);

/**
 * @brief Multiplies a 2x2 matrix by a 2D vector and stores the result in a destination vector.
 *
 * This function performs a matrix-vector multiplication, where the 2x2 matrix is multiplied by the 2D vector.
 * The resulting vector is stored in the destination vector.
 *
 * @param[in] mat The 2x2 matrix to multiply with the vector.
 * @param[in] vec The 2D vector to be multiplied with the matrix.
 * @param[out] dest The vector to store the multiplication result.
 */
void zinc_mat2_mulv(const Mat2 mat, const Vec2 *vec, Vec2 *dest);

/**
 * @brief Transposes a 2x2 matrix and stores the result in a destination matrix.
 *
 * @param[in] mat The matrix to transpose.
 * @param[out] dest The matrix to store the transposed result.
 */
void zinc_mat2_transpose_to(const Mat2 mat, Mat2 dest);

/**
 * @brief Transposes a 2x2 matrix in-place.
 *
 * @param[in, out] mat The matrix to transpose.
 */
void zinc_mat2_transpose(Mat2 mat);

/**
 * @brief Calculates the determinant of a 2x2 matrix.
 *
 * @param[in] mat The matrix to calculate the determinant of.
 * @return The determinant of the matrix.
 */
f32 zinc_mat2_determinant(const Mat2 mat);

/**
 * @brief Calculates the trace of a 2x2 matrix.
 *
 * @param[in] mat The matrix to calculate the trace of.
 * @return The trace of the matrix.
 */
f32 zinc_mat2_trace(const Mat2 mat);

#endif
