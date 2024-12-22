#include "vec2.h"
#include <string.h>
#include <math.h>

inline void zinc_vec2_zero(Vec2 *vec)
{
	Vec2 tmp = ZINC_VEC2_ZERO;
	zinc_vec2_copy(&tmp, vec);
}

inline void zinc_vec2_one(Vec2 *vec)
{
	Vec2 tmp = ZINC_VEC2_ONE;
	zinc_vec2_copy(&tmp, vec);
}

inline void zinc_vec2_copy(const Vec2 *src, Vec2 *dest)
{
	memcpy(dest, src, sizeof(*dest));
}

inline f32 zinc_vec2_squared_len(const Vec2 *vec)
{
	return vec->x*vec->x + vec->y*vec->y;
}

inline f32 zinc_vec2_len(const Vec2 *vec)
{
	return sqrtf(zinc_vec2_squared_len(vec));
}

inline void zinc_vec2_normalize(Vec2 *vec)
{
	f32 len = zinc_vec2_len(vec);
    if(len == 0.0f) return;

	zinc_vec2_scale(vec, 1.0f/len, vec);
}

inline void zinc_vec2_scale(const Vec2 *vec, f32 c, Vec2 *dest)
{
	dest->x = vec->x * c;
	dest->y = vec->y * c;
}

inline void zinc_vec2_add(const Vec2 *a, const Vec2 *b, Vec2 *dest)
{
	dest->x = a->x + b->x;
	dest->y = a->y + b->y;
}

inline void zinc_vec2_sub(const Vec2 *a, const Vec2 *b, Vec2 *dest)
{
	dest->x = a->x - b->x;
	dest->y = a->y - b->y;
}

inline f32 zinc_vec2_dot(const Vec2 *a, const Vec2 *b)
{
	return a->x*b->x + a->y*b->y;
}
