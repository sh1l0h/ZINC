#ifndef ZINC_VEC4_H
#define ZINC_VEC4_H

#include "types.h"

#define ZINC_VEC4_ZERO {{0.0f, 0.0f, 0.0f, 0.0f}}
#define ZINC_VEC4_ONE {{1.0f, 1.0f, 1.0f, 1.0f}}

typedef union Vec4 {
	struct {
		f32 x;
		f32 y;
		f32 z;
		f32 w;
	};
	f32 arr[4];
} Vec4;

/**
 * @brief Initializes a Vec4 variable with zero values.
 *
 * @param[in, out] vec Pointer to the Vec4 variable to be initialized.
 */
void zinc_vec4_zero(Vec4 *vec);

/**
 * @brief Initializes a Vec4 variable with values (1.0, 1.0, 1.0, 1.0).
 *
 * @param[in, out] vec Pointer to the Vec4 variable to be initialized.
 */
void zinc_vec4_one(Vec4 *vec);

/**
 * @brief Copies the values from one Vec4 variable to another.
 *
 * @param[in] src Pointer to the source Vec4 variable.
 * @param[out] dest Pointer to the destination Vec4 variable.
 */
void zinc_vec4_copy(const Vec4 *src, Vec4 *dest);

/**
 * @brief Calculates the squared length of a Vec4 variable.
 *
 * @param[in] vec Pointer to the Vec4 variable.
 * @return The squared length of the Vec4.
 */
f32 zinc_vec4_squared_len(const Vec4 *vec);

/**
 * @brief Calculates the length of a Vec4 variable.
 *
 * @param[in] vec Pointer to the Vec4 variable.
 * @return The length of the Vec4.
 */
f32 zinc_vec4_len(const Vec4 *vec);

/**
 * @brief Normalizes a Vec4 variable, making its length 1.
 *
 * @param[in, out] vec Pointer to the Vec4 variable to be normalized.
 */
void zinc_vec4_normalize(Vec4 *vec);

/**
 * @brief Scales a Vec4 variable by a constant factor and stores the result in a destination Vec4 variable.
 *
 * @param[in] vec Pointer to the Vec4 variable to be scaled.
 * @param[in] c The scaling factor.
 * @param[out] dest Pointer to the destination Vec4 variable.
 */
void zinc_vec4_scale(const Vec4 *vec, f32 c, Vec4 *dest);

/**
 * @brief Adds two Vec4 variables and stores the result in a destination Vec4 variable.
 *
 * @param[in] a Pointer to the first Vec4 variable.
 * @param[in] b Pointer to the second Vec4 variable.
 * @param[out] dest Pointer to the destination Vec4 variable.
 */
void zinc_vec4_add(const Vec4 *a, const Vec4 *b, Vec4 *dest);

/**
 * @brief Subtracts one Vec4 variable from another and stores the result in a destination Vec4 variable.
 *
 * @param[in] a Pointer to the Vec4 variable to be subtracted from.
 * @param[in] b Pointer to the Vec4 variable to subtract.
 * @param[out] dest Pointer to the destination Vec4 variable.
 */
void zinc_vec4_sub(const Vec4 *a, const Vec4 *b, Vec4 *dest);

/**
 * @brief Calculates the dot product of two Vec4 variables.
 *
 * @param[in] a Pointer to the first Vec4 variable.
 * @param[in] b Pointer to the second Vec4 variable.
 * @return The dot product of the two Vec4 variables.
 */
f32 zinc_vec4_dot(const Vec4 *a, const Vec4 *b);

#endif
