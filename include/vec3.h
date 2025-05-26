#ifndef ZINC_VEC3_H
#define ZINC_VEC3_H

#include "utils.h"

typedef union Vec3 {
	f32 arr[3];
#if __STDC_VERSION__ >= 201112L
	struct {
		f32 x;
		f32 y;
		f32 z;
	};
#endif
} Vec3;

static ZINC_FORCE_INLINE Vec3 ZINC_PREF(vec3)(f32 x, f32 y, f32 z)
{
    return (Vec3) {{x, y, z}};
}

static ZINC_FORCE_INLINE Vec3 ZINC_PREF(vec2_zero)()
{
    return ZINC_PREF(vec3)(0.0f, 0.0f, 0.0f);
}

static ZINC_FORCE_INLINE Vec3 ZINC_PREF(vec2_one)()
{
    return ZINC_PREF(vec3)(1.0f, 1.0f, 1.0f);
}

static ZINC_FORCE_INLINE Vec3 ZINC_PREF(vec3_scale)(Vec3 vec, f32 s)
{
    return ZINC_PREF(vec3)(vec.arr[0] * s, vec.arr[1] * s,
                           vec.arr[2] * s);
}

static ZINC_FORCE_INLINE Vec3 ZINC_PREF(vec3_scale_eq)(Vec3 *vec,
                                                       f32 s)
{
    vec->arr[0] *= s;
    vec->arr[1] *= s;
    vec->arr[2] *= s;

    return *vec;
}

static ZINC_FORCE_INLINE Vec3 ZINC_PREF(vec3_add)(Vec3 a, Vec3 b)
{
    return ZINC_PREF(vec3)(a.arr[0] + b.arr[0],
                           a.arr[1] + b.arr[1],
                           a.arr[2] + b.arr[2]);
}

static ZINC_FORCE_INLINE Vec3 ZINC_PREF(vec3_add_eq)(Vec3 *vec,
                                                     Vec3 b)
{
	vec->arr[0] += b.arr[0];
	vec->arr[1] += b.arr[1];
	vec->arr[2] += b.arr[2];

    return *vec;
}

static ZINC_FORCE_INLINE Vec3 ZINC_PREF(vec3_sub)(Vec3 a, Vec3 b)
{
    return ZINC_PREF(vec3)(a.arr[0] - b.arr[0],
                           a.arr[1] - b.arr[1],
                           a.arr[2] - b.arr[2]);
}

static ZINC_FORCE_INLINE Vec3 ZINC_PREF(vec3_sub_eq)(Vec3 *vec,
                                                     Vec3 b)
{
	vec->arr[0] -= b.arr[0];
	vec->arr[1] -= b.arr[1];
	vec->arr[2] -= b.arr[2];

    return *vec;
}

static ZINC_FORCE_INLINE f32 ZINC_PREF(vec3_dot)(Vec3 a, Vec3 b)
{
	return a.arr[0] * b.arr[0] + a.arr[1] * b.arr[1] +
        a.arr[2] * b.arr[2];
}

static ZINC_FORCE_INLINE f32 ZINC_PREF(vec3_squared_norm2)(Vec3 vec)
{
	return ZINC_PREF(vec3_dot)(vec, vec);
}

static ZINC_FORCE_INLINE f32 ZINC_PREF(vec3_norm2)(Vec3 vec)
{
	return sqrtf(ZINC_PREF(vec3_squared_norm2)(vec));
}

static ZINC_FORCE_INLINE Vec3 ZINC_PREF(vec3_normalize)(Vec3 vec)
{
	f32 len = ZINC_PREF(vec3_norm2)(vec);

    if (ZINC_UNLIKELY(ZINC_PREF(f32_eq)(len, 0.0f)))
        return vec;

    return ZINC_PREF(vec3_scale)(vec, 1.0f / len);
}

static ZINC_FORCE_INLINE Vec3 ZINC_PREF(vec3_normalize_eq)(Vec3 *vec)
{
	f32 len = ZINC_PREF(vec3_norm2)(*vec);

    if (ZINC_UNLIKELY(ZINC_PREF(f32_eq)(len, 0.0f)))
        return *vec;

    return ZINC_PREF(vec3_scale_eq)(vec, 1.0f / len);
}

#endif
