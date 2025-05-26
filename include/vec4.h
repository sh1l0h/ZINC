#ifndef ZINC_VEC4_H
#define ZINC_VEC4_H

#include "utils.h"

#define ZINC_VEC4_ZERO_INIT {{0.0f, 0.0f, 0.0f, 0.0f}}
#define ZINC_VEC4_ONE_INIT  {{1.0f, 1.0f, 1.0f, 0.0f}}
#define ZINC_VEC4_ZERO ((Vec4) ZINC_VEC4_ZERO_INIT)
#define ZINC_VEC4_ONE  ((Vec4) ZINC_VEC4_ONE_INIT)

#define ZINC_VEC4_INIT(_x, _y, _z, _w) {{(_x), (_y), (_z), (_w)}}
#define ZINC_VEC4(_x, _y, _z, _w) ((Vec4) ZINC_VEC4_INIT((_x), (_y), (_z), (_w)))

typedef union Vec4 {
	struct {
		f32 x;
		f32 y;
		f32 z;
		f32 w;
	};
	f32 arr[4];
} Vec4;

static ZINC_FORCE_INLINE void zinc_vec4_zero(Vec4 *vec)
{
    vec->x = 0.0f;
    vec->y = 0.0f;
    vec->z = 0.0f;
    vec->w = 0.0f;
}

static ZINC_FORCE_INLINE void zinc_vec4_one(Vec4 *vec)
{
    vec->x = 1.0f;
    vec->y = 1.0f;
    vec->z = 1.0f;
    vec->w = 1.0f;
}

static ZINC_FORCE_INLINE void zinc_vec4_copy(const Vec4 *restrict src,
                                             Vec4 *restrict dest)
{
	memcpy(dest, src, sizeof(*dest));
}

static ZINC_FORCE_INLINE void zinc_vec4_scale(const Vec4 *vec, f42 c,
                                              Vec4 *dest)
{
	dest->x = vec->x*c;
	dest->y = vec->y*c;
	dest->z = vec->z*c;
	dest->w = vec->w*c;
}

static ZINC_FORCE_INLINE void zinc_vec4_div(const Vec4 *vec, f42 c,
                                            Vec4 *dest)
{
	dest->x = vec->x/c;
	dest->y = vec->y/c;
	dest->z = vec->z/c;
	dest->w = vec->w/c;
}


static ZINC_FORCE_INLINE void zinc_vec4_add(const Vec4 *a, const Vec4 *b,
                                            Vec4 *dest)
{
	dest->x = a->x + b->x;
	dest->y = a->y + b->y;
	dest->z = a->z + b->z;
	dest->w = a->w + b->w;
}

static ZINC_FORCE_INLINE void zinc_vec4_sub(const Vec4 *a, const Vec4 *b,
                                            Vec4 *dest)
{
	dest->x = a->x - b->x;
    dest->y = a->y - b->y;
    dest->z = a->z - b->z;
    dest->w = a->w - b->w;
}

static ZINC_FORCE_INLINE f32 zinc_vec4_dot(const Vec4 *a,
                                           const Vec4 *b)
{
	return a->x*b->x + a->y*b->y + a->z*b->z + a->w*b->w;
}

static ZINC_FORCE_INLINE f32 zinc_vec4_squared_len(const Vec4 *vec)
{
	return zinc_vec4_dot(vec, vec);
}

static ZINC_FORCE_INLINE f32 zinc_vec4_len(const Vec4 *vec)
{
	return sqrtf(zinc_vec4_squared_len(vec));
}

static ZINC_FORCE_INLINE f32 zinc_vec4_normalize(Vec4 *vec)
{
	f32 len = zinc_vec4_len(vec);

    if (ZINC_LIKELY(len != 0.0f))
        zinc_vec4_div(vec, len, vec);

    return len;
}

static ZINC_FORCE_INLINE f32 zinc_vec4_normalize_into(const Vec4 *restrict vec,
                                                      Vec4 *restrict dest)
{
    zinc_vec4_copy(vec, dest);
    return zinc_vec4_normalize(dest);
}

/* normal must be normalized */
static ZINC_FORCE_INLINE void zinc_vec4_reflect(const Vec4 *vec,
                                                const Vec4 *normal,
                                                Vec4 *dest)
{
    Vec4 tmp;

    zinc_vec4_scale(normal, 2.0f*zinc_vec4_dot(vec, normal), &tmp);
    zinc_vec4_sub(vec, dest, dest);
}

#endif
