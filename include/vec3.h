#ifndef ZINC_VEC3_H
#define ZINC_VEC3_H

#include "types.h"

#define ZINC_VEC3_ZERO_INIT {{0.0f, 0.0f, 0.0f}}
#define ZINC_VEC3_ONE_INIT  {{1.0f, 1.0f, 1.0f}}
#define ZINC_VEC3_ZERO ((Vec3) ZINC_VEC3_ZERO_INIT)
#define ZINC_VEC3_ONE  ((Vec3) ZINC_VEC3_ONE_INIT)

#define ZINC_VEC3_INIT(_x, _y, _z) {{(_x), (_y), (_z)}}
#define ZINC_VEC3(_x, _y, _z) ((Vec3) ZINC_VEC3_INIT((_x), (_y), (_z)))

typedef union Vec3 {
	struct {
		f32 x;
		f32 y;
		f32 z;
	};
	f32 arr[3];
} Vec3;

/**
 * @brief Initializes a Vec3 variable with zero values.
 *
 * @param[in, out] vec Pointer to the Vec3 variable to be initialized.
 */
void zinc_vec3_zero(Vec3 *vec);

/**
 * @brief Initializes a Vec3 variable with values (1.0, 1.0, 1.0).
 *
 * @param[in, out] vec Pointer to the Vec3 variable to be initialized.
 */
void zinc_vec3_one(Vec3 *vec);

/**
 * @brief Copies the values from one Vec3 variable to another.
 *
 * @param[in] src Pointer to the source Vec3 variable.
 * @param[out] dest Pointer to the destination Vec3 variable.
 */
void zinc_vec3_copy(const Vec3 *src, Vec3 *dest);

/**
 * @brief Calculates the squared length of a Vec3 variable.
 *
 * @param[in] vec Pointer to the Vec3 variable.
 * @return The squared length of the Vec3.
 */
f32 zinc_vec3_squared_len(const Vec3 *vec);

/**
 * @brief Calculates the length of a Vec3 variable.
 *
 * @param[in] vec Pointer to the Vec3 variable.
 * @return The length of the Vec3.
 */
f32 zinc_vec3_len(const Vec3 *vec);

/**
 * @brief Normalizes a Vec3 variable, making its length 1.
 *
 * @param[in, out] vec Pointer to the Vec3 variable to be normalized.
 */
void zinc_vec3_normalize(Vec3 *vec);

/**
 * @brief Scales a Vec3 variable by a constant factor and stores the result in a destination Vec3 variable.
 *
 * @param[in] vec Pointer to the Vec3 variable to be scaled.
 * @param[in] c The scaling factor.
 * @param[out] dest Pointer to the destination Vec3 variable.
 */
void zinc_vec3_scale(const Vec3 *vec, f32 c, Vec3 *dest);

/**
 * @brief Adds two Vec3 variables and stores the result in a destination Vec3 variable.
 *
 * @param[in] a Pointer to the first Vec3 variable.
 * @param[in] b Pointer to the second Vec3 variable.
 * @param[out] dest Pointer to the destination Vec3 variable.
 */
void zinc_vec3_add(const Vec3 *a, const Vec3 *b, Vec3 *dest);

/**
 * @brief Subtracts one Vec3 variable from another and stores the result in a destination Vec3 variable.
 *
 * @param[in] a Pointer to the Vec3 variable to be subtracted from.
 * @param[in] b Pointer to the Vec3 variable to subtract.
 * @param[out] dest Pointer to the destination Vec3 variable.
 */
void zinc_vec3_sub(const Vec3 *a, const Vec3 *b, Vec3 *dest);

/**
 * @brief Calculates the dot product of two Vec3 variables.
 *
 * @param[in] a Pointer to the first Vec3 variable.
 * @param[in] b Pointer to the second Vec3 variable.
 * @return The dot product of the two Vec3 variables.
 */
f32 zinc_vec3_dot(const Vec3 *a, const Vec3 *b);

/**
 * @brief Calculates the cross product of two Vec3 variables.
 *
 * @param[in] a Pointer to the first Vec3 variable.
 * @param[in] b Pointer to the second Vec3 variable.
 * @param[out] dest Pointer to the destination Vec3 variable.
 */
void zinc_vec3_cross(const Vec3 *a, const Vec3 *b, Vec3 *dest);

#endif
