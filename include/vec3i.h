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
 * @param vec Pointer to the Vec3i variable to be initialized.
 */
void zinc_vec3i_zero(Vec3i *vec);

/**
 * @brief Initializes a Vec3i variable with values (1, 1, 1).
 *
 * @param vec Pointer to the Vec3i variable to be initialized.
 */
void zinc_vec3i_one(Vec3i *vec);

/**
 * @brief Copies the values from one Vec3i variable to another.
 *
 * @param src Pointer to the source Vec3i variable.
 * @param dest Pointer to the destination Vec3i variable.
 */
void zinc_vec3i_copy(const Vec3i *src, Vec3i *dest);

/**
 * @brief Calculates the squared length of a Vec3i variable.
 *
 * @param vec Pointer to the Vec3i variable.
 * @return The squared length of the Vec3i.
 */
f32 zinc_vec3i_squared_len(const Vec3i *vec);

/**
 * @brief Calculates the length of a Vec3i variable.
 *
 * @param vec Pointer to the Vec3i variable.
 * @return The length of the Vec3i.
 */
f32 zinc_vec3i_len(const Vec3i *vec);

/**
 * @brief Scales a Vec3i variable by a constant factor.
 *
 * @param vec Pointer to the Vec3i variable to be scaled.
 * @param c The scaling factor.
 */
void zinc_vec3i_scale(Vec3i *vec, i32 c);

/**
 * @brief Adds two Vec3i variables and stores the result in a destination Vec3i variable.
 *
 * @param a Pointer to the first Vec3i variable.
 * @param b Pointer to the second Vec3i variable.
 * @param dest Pointer to the destination Vec3i variable.
 */
void zinc_vec3i_add(const Vec3i *a, const Vec3i *b, Vec3i *dest);

/**
 * @brief Subtracts one Vec3i variable from another and stores the result in a destination Vec3i variable.
 *
 * @param a Pointer to the Vec3i variable to be subtracted from.
 * @param b Pointer to the Vec3i variable to subtract.
 * @param dest Pointer to the destination Vec3i variable.
 */
void zinc_vec3i_sub(const Vec3i *a, const Vec3i *b, Vec3i *dest);

/**
 * @brief Calculates the dot product of two Vec3i variables.
 *
 * @param a Pointer to the first Vec3i variable.
 * @param b Pointer to the second Vec3i variable.
 * @return The dot product of the two Vec3i variables.
 */
f32 zinc_vec3i_dot(const Vec3i *a, const Vec3i *b);

#endif
