#ifndef ZINC_VEC4I_H
#define ZINC_VEC4I_H

#include "types.h"

#define ZINC_VEC4I_ZERO_INIT {{0, 0, 0, 0}}
#define ZINC_VEC4I_ONE_INIT  {{1, 1, 1, 1}}
#define ZINC_VEC4I_ZERO ((Vec4i) ZINC_VEC4I_ZERO_INIT)
#define ZINC_VEC4I_ONE  ((Vec4i) ZINC_VEC4I_ONE_INIT)

#define ZINC_VEC4I_INIT(_x, _y, _z, _w) {{(_x), (_y), (_z), (_w)}}
#define ZINC_VEC4I(_x, _y, _z, _w) \
    ((Vec4i) ZINC_VEC4I_INIT((_x), (_y), (_z), (_w)))

typedef union Vec4i {
	struct {
		i32 x;
		i32 y;
		i32 z;
		i32 w;
	};
	i32 arr[4];
} Vec4i;

/**
 * @brief Initializes a Vec4i variable with zero values.
 *
 * @param[in, out] vec Pointer to the Vec4i variable to be initialized.
 */
void zinc_vec4i_zero(Vec4i *vec);

/**
 * @brief Initializes a Vec4i variable with values (1, 1, 1, 1).
 *
 * @param[in, out] vec Pointer to the Vec4i variable to be initialized.
 */
void zinc_vec4i_one(Vec4i *vec);

/**
 * @brief Copies the values from one Vec4i variable to another.
 *
 * @param[in] src Pointer to the source Vec4i variable.
 * @param[out] dest Pointer to the destination Vec4i variable.
 */
void zinc_vec4i_copy(const Vec4i *src, Vec4i *dest);

/**
 * @brief Calculates the squared length of a Vec4i variable.
 *
 * @param[in] vec Pointer to the Vec4i variable.
 * @return The squared length of the Vec4i.
 */
i32 zinc_vec4i_squared_len(const Vec4i *vec);

/**
 * @brief Calculates the length of a Vec4i variable.
 *
 * @param[in] vec Pointer to the Vec4i variable.
 * @return The length of the Vec4i.
 */
f32 zinc_vec4i_len(const Vec4i *vec);

/**
 * @brief Scales a Vec4i variable by a constant factor and stores the result in a destination Vec4i variable.
 *
 * @param[in] vec Pointer to the Vec4i variable to be scaled.
 * @param[in] c The scaling factor.
 * @param[out] dest Pointer to the destination Vec4i variable.
 */
void zinc_vec4i_scale(const Vec4i *vec, i32 c, Vec4i *dest);

/**
 * @brief Divides a Vec4i variable by a constant and stores the result in a destination Vec4i variable.
 *
 * @param[in] vec Pointer to the Vec4i variable to be divided.
 * @param[in] c The constant. 
 * @param[out] dest Pointer to the destination Vec4i variable.
 */
void zinc_vec4i_div(const Vec4i *vec, i32 c, Vec4i *dest);

/**
 * @brief Adds two Vec4i variables and stores the result in a destination Vec4i variable.
 *
 * @param[in] a Pointer to the first Vec4i variable.
 * @param[in] b Pointer to the second Vec4i variable.
 * @param[out] dest Pointer to the destination Vec4i variable.
 */
void zinc_vec4i_add(const Vec4i *a, const Vec4i *b, Vec4i *dest);

/**
 * @brief Subtracts one Vec4i variable from another and stores the result in a destination Vec4i variable.
 *
 * @param[in] a Pointer to the Vec4i variable to be subtracted from.
 * @param[in] b Pointer to the Vec4i variable to subtract.
 * @param[out] dest Pointer to the destination Vec4i variable.
 */
void zinc_vec4i_sub(const Vec4i *a, const Vec4i *b, Vec4i *dest);

/**
 * @brief Calculates the dot product of two Vec4i variables.
 *
 * @param[in] a Pointer to the first Vec4i variable.
 * @param[in] b Pointer to the second Vec4i variable.
 * @return The dot product of the two Vec4i variables.
 */
i32 zinc_vec4i_dot(const Vec4i *a, const Vec4i *b);

#endif
