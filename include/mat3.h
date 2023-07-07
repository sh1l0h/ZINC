#ifndef ZINC_MAT3_H
#define ZINC_MAT3_H

#include "types.h"
#include "vec3.h"

#define ZINC_MAT3_ZERO {{0.0f, 0.0f, 0.0f}, {0.0f, 0.0f, 0.0f}, {0.0f, 0.0f, 0.0f}}

#define ZINC_MAT3_EYE {{1.0f, 0.0f, 0.0f}, {0.0f, 1.0f, 0.0f}, {0.0f, 0.0f, 1.0f}}

typedef f32 Mat3[3][3];

/**
 * @brief Sets all elements of the 3x3 matrix to zero.
 *
 * @param mat The 3x3 matrix to be zeroed.
 */
void zinc_mat3_zero(Mat3 mat);

/**
 * @brief Sets the 3x3 matrix as an identity matrix.
 *
 * @param mat The 3x3 matrix to be set as an identity matrix.
 */
void zinc_mat3_eye(Mat3 mat);

/**
 * @brief Scales a 3x3 matrix by a scalar value.
 *
 * @param mat The 3x3 matrix to be scaled.
 * @param c The scalar value to scale the matrix by.
 */
void zinc_mat3_scale(Mat3 mat, f32 c);

/**
 * @brief Copies the values of one 3x3 matrix to another.
 *
 * @param src The source matrix to copy values from.
 * @param dest The destination matrix to copy values to.
 */
void zinc_mat3_copy(const Mat3 src, Mat3 dest);

/**
 * @brief Adds two 3x3 matrices element-wise and stores the result in a destination matrix.
 *
 * @param a The first matrix to add.
 * @param b The second matrix to add.
 * @param dest The matrix to store the addition result.
 */
void zinc_mat3_add(const Mat3 a, const Mat3 b, Mat3 dest);

/**
 * @brief Subtracts one 3x3 matrix from another element-wise and stores the result in a destination matrix.
 *
 * @param a The matrix to subtract from.
 * @param b The matrix to subtract.
 * @param dest The matrix to store the subtraction result.
 */
void zinc_mat3_sub(const Mat3 a, const Mat3 b, Mat3 dest);

/**
 * @brief Multiplies two 3x3 matrices and stores the result in a destination matrix.
 *
 * @param a The first matrix to multiply.
 * @param b The second matrix to multiply.
 * @param dest The matrix to store the multiplication result.
 */
void zinc_mat3_mul(const Mat3 a, const Mat3 b, Mat3 dest);

/**
 * @brief Multiplies a 3x3 matrix by a 3D vector and stores the result in a destination vector.
 *
 * This function performs a matrix-vector multiplication, where the 3x3 matrix is multiplied by the 3D vector.
 * The resulting vector is stored in the destination vector.
 *
 * @param mat The 3x3 matrix to multiply with the vector.
 * @param vec The 3D vector to be multiplied with the matrix.
 * @param dest The vector to store the multiplication result.
 */
void zinc_mat3_mulv(const Mat3 mat, const Vec3 *vec, Vec3 *dest);

/**
 * @brief Transposes a 3x3 matrix and stores the result in a destination matrix.
 *
 * @param mat The matrix to transpose.
 * @param dest The matrix to store the transposed result.
 */
void zinc_mat3_transpose_to(const Mat3 mat, Mat3 dest);

/**
 * @brief Transposes a 3x3 matrix in-place.
 *
 * @param mat The matrix to transpose.
 */
void zinc_mat3_transpose(Mat3 mat);

/**
 * @brief Calculates the determinant of a 3x3 matrix.
 *
 * @param mat The matrix to calculate the determinant of.
 * @return The determinant of the matrix.
 */
f32 zinc_mat3_determinant(const Mat3 mat);

/**
 * @brief Calculates the trace of a 3x3 matrix.
 *
 * @param mat The matrix to calculate the trace of.
 * @return The trace of the matrix.
 */
f32 zinc_mat3_trace(const Mat3 mat);

#endif
