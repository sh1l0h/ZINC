#ifndef ZINC_VEC2_H
#define ZINC_VEC2_H

#include "types.h"

#define ZINC_VEC2_ZERO {{0.0f, 0.0f}}
#define ZINC_VEC2_ONE {{1.0f, 1.0f}}

typedef union Vec2 {
	struct {
		f32 x;
		f32 y;
	};
	f32 arr[2];
} Vec2;

/**
 * @brief Initializes a Vec2 variable with zero values.
 *
 * @param vec Pointer to the Vec2 variable to be initialized.
 */
void zinc_vec2_zero(Vec2 *vec);

/**
 * @brief Initializes a Vec2 variable with values (1.0, 1.0).
 *
 * @param vec Pointer to the Vec2 variable to be initialized.
 */
void zinc_vec2_one(Vec2 *vec);

/**
 * @brief Copies the values from one Vec2 variable to another.
 *
 * @param src Pointer to the source Vec2 variable.
 * @param dest Pointer to the destination Vec2 variable.
 */
void zinc_vec2_copy(const Vec2 *src, Vec2 *dest);

/**
 * @brief Calculates the squared length of a Vec2 variable.
 *
 * @param vec Pointer to the Vec2 variable.
 * @return The squared length of the Vec2.
 */
f32 zinc_vec2_squared_len(const Vec2 *vec);

/**
 * @brief Calculates the length of a Vec2 variable.
 *
 * @param vec Pointer to the Vec2 variable.
 * @return The length of the Vec2.
 */
f32 zinc_vec2_len(const Vec2 *vec);

/**
 * @brief Normalizes a Vec2 variable, making its length 1.
 *
 * @param vec Pointer to the Vec2 variable to be normalized.
 */
void zinc_vec2_norm(Vec2 *vec);

/**
 * @brief Scales a Vec2 variable by a constant factor.
 *
 * @param vec Pointer to the Vec2 variable to be scaled.
 * @param c The scaling factor.
 */
void zinc_vec2_scale(Vec2 *vec, f32 c);

/**
 * @brief Adds two Vec2 variables and stores the result in a destination Vec2 variable.
 *
 * @param a Pointer to the first Vec2 variable.
 * @param b Pointer to the second Vec2 variable.
 * @param dest Pointer to the destination Vec2 variable.
 */
void zinc_vec2_add(const Vec2 *a, const Vec2 *b, Vec2 *dest);

/**
 * @brief Subtracts one Vec2 variable from another and stores the result in a destination Vec2 variable.
 *
 * @param a Pointer to the Vec2 variable to be subtracted from.
 * @param b Pointer to the Vec2 variable to subtract.
 * @param dest Pointer to the destination Vec2 variable.
 */
void zinc_vec2_sub(const Vec2 *a, const Vec2 *b, Vec2 *dest);

/**
 * @brief Calculates the dot product of two Vec2 variables.
 *
 * @param a Pointer to the first Vec2 variable.
 * @param b Pointer to the second Vec2 variable.
 * @return The dot product of the two Vec2 variables.
 */
f32 zinc_vec2_dot(const Vec2 *a, const Vec2 *b);

#endif
