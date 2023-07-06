#include "../include/vec4i.h"
#include <string.h>
#include <math.h>

inline void zinc_vec4i_zero(Vec4i *vec)
{
	Vec4i tmp = ZINC_VEC4I_ZERO;
	zinc_vec4i_copy(&tmp, vec);
}

inline void zinc_vec4i_one(Vec4i *vec)
{
	Vec4i tmp = ZINC_VEC4I_ONE;
	zinc_vec4i_copy(&tmp, vec);
}

inline void zinc_vec4i_copy(const Vec4i *src, Vec4i *dest)
{
	memcpy(dest, src, 4*sizeof(f32));
}

inline f32 zinc_vec4i_squared_len(const Vec4i *vec)
{
	return vec->x*vec->x + vec->y*vec->y + vec->z*vec->z + vec->w*vec->w;
}

inline f32 zinc_vec4i_len(const Vec4i *vec)
{
	return sqrtf(zinc_vec4i_squared_len(vec));
}

inline void zinc_vec4i_scale(Vec4i *vec, i32 c)
{
	vec->x /= c;
	vec->y /= c;
	vec->z /= c;
	vec->w /= c;
}

inline void zinc_vec4i_add(const Vec4i *a, const Vec4i *b, Vec4i *dest)
{
	dest->x = a->x + b->x;
	dest->y = a->y + b->y;
	dest->z = a->z + b->z;
	dest->w = a->w + b->w;
}

inline void zinc_vec4i_sub(const Vec4i *a, const Vec4i *b, Vec4i *dest)
{
	dest->x = a->x - b->x;
	dest->y = a->y - b->y;
	dest->z = a->z - b->z;
	dest->w = a->w - b->w;
}

inline f32 zinc_vec4i_dot(const Vec4i *a, const Vec4i *b)
{
	return a->x*b->x + a->y*b->y + a->z*b->z + a->w*b->w;
}
