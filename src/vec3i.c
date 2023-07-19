#include "../include/vec3i.h"
#include <string.h>
#include <math.h>

inline void zinc_vec3i_zero(Vec3i *vec)
{
	Vec3i tmp = ZINC_VEC3I_ZERO;
	zinc_vec3i_copy(&tmp, vec);
}

inline void zinc_vec3i_one(Vec3i *vec)
{
	Vec3i tmp = ZINC_VEC3I_ONE;
	zinc_vec3i_copy(&tmp, vec);
}

inline void zinc_vec3i_copy(const Vec3i *src, Vec3i *dest)
{
	memcpy(dest, src, 3*sizeof(f32));
}

inline i32 zinc_vec3i_squared_len(const Vec3i *vec)
{
	return vec->x*vec->x + vec->y*vec->y + vec->z*vec->z;
}

inline f32 zinc_vec3i_len(const Vec3i *vec)
{
	return sqrtf(zinc_vec3i_squared_len(vec));
}

inline void zinc_vec3i_scale(const Vec3i *vec, i32 c, Vec3i *dest)
{
	dest->x = vec->x * c;
	dest->y = vec->y * c;
	dest->z = vec->z * c;
}

inline void zinc_vec3i_add(const Vec3i *a, const Vec3i *b, Vec3i *dest)
{
	dest->x = a->x + b->x;
	dest->y = a->y + b->y;
	dest->z = a->z + b->z;
}

inline void zinc_vec3i_sub(const Vec3i *a, const Vec3i *b, Vec3i *dest)
{
	dest->x = a->x - b->x;
	dest->y = a->y - b->y;
	dest->z = a->z - b->z;
}

inline i32 zinc_vec3i_dot(const Vec3i *a, const Vec3i *b)
{
	return a->x*b->x + a->y*b->y + a->z*b->z;
}
