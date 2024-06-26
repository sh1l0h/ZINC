#ifndef ZINC_VEC2I_H
#define ZINC_VEC2I_H

#include "types.h"

#define ZINC_VEC2I_ZERO_INIT {{0, 0}}
#define ZINC_VEC2I_ONE_INIT  {{1, 1}}
#define ZINC_VEC2I_ZERO ((Vec2i) ZINC_VEC2I_ZERO_INIT)
#define ZINC_VEC2I_ONE  ((Vec2i) ZINC_VEC2I_ONE_INIT)

#define ZINC_VEC2I_INIT(_x, _y) {{(_x), (_y)}}
#define ZINC_VEC2I(_x, _y) ((Vec2i) ZINC_VEC2I_INIT((_x), (_y)))

typedef union Vec2i {
	struct {
		i32 x;
		i32 y;
	};
	i32 arr[2];
} Vec2i;

/**
 * @brief Initializes a Vec2i variable with zero values.
 *
 * @param[in, out] vec Pointer to the Vec2i variable to be initialized.
 */
void zinc_vec2i_zero(Vec2i *vec);

/**
 * @brief Initializes a Vec2i variable with values (1, 1).
 *
 * @param[in, out] vec Pointer to the Vec2i variable to be initialized.
 */
void zinc_vec2i_one(Vec2i *vec);

/**
 * @brief Copies the values from one Vec2i variable to another.
 *
 * @param[in] src Pointer to the source Vec2i variable.
 * @param[out] dest Pointer to the destination Vec2i variable.
 */
void zinc_vec2i_copy(const Vec2i *src, Vec2i *dest);

/**
 * @brief Calculates the squared length of a Vec2i variable.
 *
 * @param[in] vec Pointer to the Vec2i variable.
 * @return The squared length of the Vec2i.
 */
i32 zinc_vec2i_squared_len(const Vec2i *vec);

/**
 * @brief Calculates the length of a Vec2i variable.
 *
 * @param[in] vec Pointer to the Vec2i variable.
 * @return The length of the Vec2i.
 */
f32 zinc_vec2i_len(const Vec2i *vec);

/**
 * @brief Scales a Vec2i variable by a constant factor and stores the result in a destination Vec2i variable.
 *
 * @param[in] vec Pointer to the Vec2i variable to be scaled.
 * @param[in] c The scaling factor.
 * @param[out] dest Pointer to the destination Vec2i variable.
 */
void zinc_vec2i_scale(const Vec2i *vec, i32 c, Vec2i *dest);

/**
 * @brief Divides a Vec2i variable by a constant and stores the result in a destination Vec2i variable.
 *
 * @param[in] vec Pointer to the Vec2i variable to be divided.
 * @param[in] c The constant. 
 * @param[out] dest Pointer to the destination Vec2i variable.
 */
void zinc_vec2i_div(const Vec2i *vec, i32 c, Vec2i *dest);

/**
 * @brief Adds two Vec2i variables and stores the result in a destination Vec2i variable.
 *
 * @param[in] a Pointer to the first Vec2i variable.
 * @param[in] b Pointer to the second Vec2i variable.
 * @param[out] dest Pointer to the destination Vec2i variable.
 */
void zinc_vec2i_add(const Vec2i *a, const Vec2i *b, Vec2i *dest);

/**
 * @brief Subtracts one Vec2i variable from another and stores the result in a destination Vec2i variable.
 *
 * @param[in] a Pointer to the Vec2i variable to be subtracted from.
 * @param[in] b Pointer to the Vec2i variable to subtract.
 * @param[out] dest Pointer to the destination Vec2i variable.
 */
void zinc_vec2i_sub(const Vec2i *a, const Vec2i *b, Vec2i *dest);

/**
 * @brief Calculates the dot product of two Vec2i variables.
 *
 * @param[in] a Pointer to the first Vec2i variable.
 * @param[in] b Pointer to the second Vec2i variable.
 * @return The dot product of the two Vec2i variables.
 */
i32 zinc_vec2i_dot(const Vec2i *a, const Vec2i *b);

#endif
