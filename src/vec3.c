#include "../include/vec3.h"
#include <string.h>
#include <math.h>

inline void zinc_vec3_zero(Vec3 *vec)
{
	Vec3 tmp = ZINC_VEC3_ZERO;
	zinc_vec3_copy(&tmp, vec);
}

inline void zinc_vec3_one(Vec3 *vec)
{
	Vec3 tmp = ZINC_VEC3_ONE;
	zinc_vec3_copy(&tmp, vec);
}

inline void zinc_vec3_copy(const Vec3 *src, Vec3 *dest)
{
	memcpy(dest, src, 3*sizeof(f32));
}

inline f32 zinc_vec3_squared_len(const Vec3 *vec)
{
	return vec->x*vec->x + vec->y*vec->y + vec->z*vec->z;
}

inline f32 zinc_vec3_len(const Vec3 *vec)
{
	return sqrtf(zinc_vec3_squared_len(vec));
}

inline void zinc_vec3_normalize(Vec3 *vec)
{
	f32 len = zinc_vec3_len(vec);
    if(len == 0.0f) return;
	zinc_vec3_scale(vec, 1.0f/len, vec);
}

inline void zinc_vec3_scale(const Vec3 *vec, f32 c, Vec3 *dest)
{
	dest->x = vec->x * c;
	dest->y = vec->y * c;
    dest->z = vec->z * c;
}

inline void zinc_vec3_add(const Vec3 *a, const Vec3 *b, Vec3 *dest)
{
	dest->x = a->x + b->x;
	dest->y = a->y + b->y;
	dest->z = a->z + b->z;
}

inline void zinc_vec3_sub(const Vec3 *a, const Vec3 *b, Vec3 *dest)
{
	dest->x = a->x - b->x;
	dest->y = a->y - b->y;
	dest->z = a->z - b->z;
}

inline f32 zinc_vec3_dot(const Vec3 *a, const Vec3 *b)
{
	return a->x*b->x + a->y*b->y + a->z*b->z;
}

void zinc_vec3_cross(const Vec3 *a, const Vec3 *b, Vec3 *dest)
{
    dest->x = a->y*b->z - a->z*b->y;
    dest->y = a->z*b->x - a->x*b->z;
    dest->z = a->x*b->y - a->y*b->x;
}
