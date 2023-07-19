#include "../include/vec2i.h"
#include <string.h>
#include <math.h>

inline void zinc_vec2i_zero(Vec2i *vec)
{
	Vec2i tmp = ZINC_VEC2I_ZERO;
	zinc_vec2i_copy(&tmp, vec);
}

inline void zinc_vec2i_one(Vec2i *vec)
{
	Vec2i tmp = ZINC_VEC2I_ONE;
	zinc_vec2i_copy(&tmp, vec);
}

inline void zinc_vec2i_copy(const Vec2i *src, Vec2i *dest)
{
	memcpy(dest, src, 2*sizeof(i32));
}

inline i32 zinc_vec2i_squared_len(const Vec2i *vec)
{
	return vec->x*vec->x + vec->y*vec->y;
}

inline f32 zinc_vec2i_len(const Vec2i *vec)
{
	return sqrtf(zinc_vec2i_squared_len(vec));
}

inline void zinc_vec2i_scale(const Vec2i *vec, i32 c, Vec2i *dest)
{
	dest->x = vec->x * c;
	dest->y = vec->y * c;
}

inline void zinc_vec2i_add(const Vec2i *a, const Vec2i *b, Vec2i *dest)
{
	dest->x = a->x + b->x;
	dest->y = a->y + b->y;
}

inline void zinc_vec2i_sub(const Vec2i *a, const Vec2i *b, Vec2i *dest)
{
	dest->x = a->x - b->x;
	dest->y = a->y - b->y;
}

inline i32 zinc_vec2i_dot(const Vec2i *a, const Vec2i *b)
{
	return a->x*b->x + a->y*b->y;
}
