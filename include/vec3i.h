#ifndef ZINC_VEC3I_H
#define ZINC_VEC3I_H

#include "types.h"

#define ZINC_VEC3I_ZERO {{0, 0, 0}}
#define ZINC_VEC3I_ONE {{1, 1, 1}}

typedef union Vec3i {
	struct {
		i32 x;
		i32 y;
		i32 z;
	};
	i32 arr[3];
} Vec3i;

/**
 * @brief Initializes a Vec3i variable with zero values.
 *
 * @param[in, out] vec Pointer to the Vec3i variable to be initialized.
 */
void zinc_vec3i_zero(Vec3i *vec);

/**
 * @brief Initializes a Vec3i variable with values (1, 1, 1).
 *
 * @param[in, out] vec Pointer to the Vec3i variable to be initialized.
 */
void zinc_vec3i_one(Vec3i *vec);

/**
 * @brief Copies the values from one Vec3i variable to another.
 *
 * @param[in] src Pointer to the source Vec3i variable.
 * @param[out] dest Pointer to the destination Vec3i variable.
 */
void zinc_vec3i_copy(const Vec3i *src, Vec3i *dest);

/**
 * @brief Calculates the squared length of a Vec3i variable.
 *
 * @param[in] vec Pointer to the Vec3i variable.
 * @return The squared length of the Vec3i.
 */
i32 zinc_vec3i_squared_len(const Vec3i *vec);

/**
 * @brief Calculates the length of a Vec3i variable.
 *
 * @param[in] vec Pointer to the Vec3i variable.
 * @return The length of the Vec3i.
 */
f32 zinc_vec3i_len(const Vec3i *vec);

/**
 * @brief Scales a Vec3i variable by a constant factor and stores the result in a destination Vec3i variable.
 *
 * @param[in] vec Pointer to the Vec3i variable to be scaled.
 * @param[in] c The scaling factor.
 * @param[out] dest Pointer to the destination Vec3i variable.
 */
void zinc_vec3i_scale(const Vec3i *vec, i32 c, Vec3i *dest);

/**
 * @brief Divides a Vec3i variable by a constant and stores the result in a destination Vec3i variable.
 *
 * @param[in] vec Pointer to the Vec3i variable to be divided.
 * @param[in] c The constant. 
 * @param[out] dest Pointer to the destination Vec3i variable.
 */
void zinc_vec3i_div(const Vec3i *vec, i32 c, Vec3i *dest);

/**
 * @brief Adds two Vec3i variables and stores the result in a destination Vec3i variable.
 *
 * @param[in] a Pointer to the first Vec3i variable.
 * @param[in] b Pointer to the second Vec3i variable.
 * @param[out] dest Pointer to the destination Vec3i variable.
 */
void zinc_vec3i_add(const Vec3i *a, const Vec3i *b, Vec3i *dest);

/**
 * @brief Subtracts one Vec3i variable from another and stores the result in a destination Vec3i variable.
 *
 * @param[in] a Pointer to the Vec3i variable to be subtracted from.
 * @param[in] b Pointer to the Vec3i variable to subtract.
 * @param[out] dest Pointer to the destination Vec3i variable.
 */
void zinc_vec3i_sub(const Vec3i *a, const Vec3i *b, Vec3i *dest);

/**
 * @brief Calculates the dot product of two Vec3i variables.
 *
 * @param[in] a Pointer to the first Vec3i variable.
 * @param[in] b Pointer to the second Vec3i variable.
 * @return The dot product of the two Vec3i variables.
 */
i32 zinc_vec3i_dot(const Vec3i *a, const Vec3i *b);

#endif
