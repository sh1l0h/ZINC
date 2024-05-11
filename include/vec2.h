#ifndef ZINC_VEC2_H
#define ZINC_VEC2_H

#include "types.h"

#define ZINC_VEC2_ZERO_INIT {{0.0f, 0.0f}}
#define ZINC_VEC2_ONE_INIT  {{1.0f, 1.0f}}
#define ZINC_VEC2_ZERO ((Vec2) ZINC_VEC2_ZERO_INIT)
#define ZINC_VEC2_ONE  ((Vec2) ZINC_VEC2_ONE_INIT)

#define ZINC_VEC2_INIT(_x, _y) {{(_x), (_y)}}
#define ZINC_VEC2(_x, _y) ((Vec2) ZINC_VEC2_INIT((_x), (_y)))

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
 * @param[in, out] vec Pointer to the Vec2 variable to be initialized.
 */
void zinc_vec2_zero(Vec2 *vec);

/**
 * @brief Initializes a Vec2 variable with values (1.0, 1.0).
 *
 * @param[in, out] vec Pointer to the Vec2 variable to be initialized.
 */
void zinc_vec2_one(Vec2 *vec);

/**
 * @brief Copies the values from one Vec2 variable to another.
 *
 * @param[in] src Pointer to the source Vec2 variable.
 * @param[out] dest Pointer to the destination Vec2 variable.
 */
void zinc_vec2_copy(const Vec2 *src, Vec2 *dest);

/**
 * @brief Calculates the squared length of a Vec2 variable.
 *
 * @param[in] vec Pointer to the Vec2 variable.
 * @return The squared length of the Vec2.
 */
f32 zinc_vec2_squared_len(const Vec2 *vec);

/**
 * @brief Calculates the length of a Vec2 variable.
 *
 * @param[in] vec Pointer to the Vec2 variable.
 * @return The length of the Vec2.
 */
f32 zinc_vec2_len(const Vec2 *vec);

/**
 * @brief Normalizes a Vec2 variable, making its length 1.
 *
 * @param[in, out] vec Pointer to the Vec2 variable to be normalized.
 */
void zinc_vec2_normalize(Vec2 *vec);

/**
 * @brief Scales a Vec2 variable by a constant factor and stores the result in a destination Vec2 variable.
 *
 * @param[in] vec Pointer to the Vec2 variable to be scaled.
 * @param[in] c The scaling factor.
 * @param[out] dest Pointer to the destination Vec2 variable.
 */
void zinc_vec2_scale(const Vec2 *vec, f32 c, Vec2 *dest);

/**
 * @brief Adds two Vec2 variables and stores the result in a destination Vec2 variable.
 *
 * @param[in] a Pointer to the first Vec2 variable.
 * @param[in] b Pointer to the second Vec2 variable.
 * @param[out] dest Pointer to the destination Vec2 variable.
 */
void zinc_vec2_add(const Vec2 *a, const Vec2 *b, Vec2 *dest);

/**
 * @brief Subtracts one Vec2 variable from another and stores the result in a destination Vec2 variable.
 *
 * @param[in] a Pointer to the Vec2 variable to be subtracted from.
 * @param[in] b Pointer to the Vec2 variable to subtract.
 * @param[out] dest Pointer to the destination Vec2 variable.
 */
void zinc_vec2_sub(const Vec2 *a, const Vec2 *b, Vec2 *dest);

/**
 * @brief Calculates the dot product of two Vec2 variables.
 *
 * @param[in] a Pointer to the first Vec2 variable.
 * @param[in] b Pointer to the second Vec2 variable.
 * @return The dot product of the two Vec2 variables.
 */
f32 zinc_vec2_dot(const Vec2 *a, const Vec2 *b);

#endif
