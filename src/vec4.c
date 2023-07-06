#include "../include/vec4.h"
#include <string.h>
#include <math.h>

inline void zinc_vec4_zero(Vec4 *vec)
{
	Vec4 tmp = ZINC_VEC4_ZERO;
	zinc_vec4_copy(&tmp, vec);
}

inline void zinc_vec4_one(Vec4 *vec)
{
	Vec4 tmp = ZINC_VEC4_ONE;
	zinc_vec4_copy(&tmp, vec);
}

inline void zinc_vec4_copy(const Vec4 *src, Vec4 *dest)
{
	memcpy(dest, src, 4*sizeof(f32));
}

inline f32 zinc_vec4_squared_len(const Vec4 *vec)
{
	return vec->x*vec->x + vec->y*vec->y + vec->z*vec->z + vec->w*vec->w;
}

inline f32 zinc_vec4_len(const Vec4 *vec)
{
	return sqrtf(zinc_vec4_squared_len(vec));
}

inline void zinc_vec4_norm(Vec4 *vec)
{
	f32 len = zinc_vec4_len(vec);
	zinc_vec4_scale(vec, 1.0f/len);
}

inline void zinc_vec4_scale(Vec4 *vec, f32 c)
{
	vec->x /= c;
	vec->y /= c;
	vec->z /= c;
	vec->w /= c;
}

inline void zinc_vec4_add(const Vec4 *a, const Vec4 *b, Vec4 *dest)
{
	dest->x = a->x + b->x;
	dest->y = a->y + b->y;
	dest->z = a->z + b->z;
	dest->w = a->w + b->w;
}

inline void zinc_vec4_sub(const Vec4 *a, const Vec4 *b, Vec4 *dest)
{
	dest->x = a->x - b->x;
	dest->y = a->y - b->y;
	dest->z = a->z - b->z;
	dest->w = a->w - b->w;
}

inline f32 zinc_vec4_dot(const Vec4 *a, const Vec4 *b)
{
	return a->x*b->x + a->y*b->y + a->z*b->z + a->w*b->w;
}
