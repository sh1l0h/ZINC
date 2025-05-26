#ifndef ZINC_VEC2_H
#define ZINC_VEC2_H

#include "utils.h"

typedef union Vec2 {
    f32 arr[2];
#if __STDC_VERSION__ >= 201112L
    struct {
        f32 x;
        f32 y;
    };
#endif
} Vec2;

static ZINC_FORCE_INLINE Vec2 ZINC_PREF(vec2)(f32 x, f32 y)
{
    return (Vec2) {{x, y}};
}

static ZINC_FORCE_INLINE Vec2 ZINC_PREF(vec2_zero)()
{
    return ZINC_PREF(vec2)(0.0f, 0.0f);
}

static ZINC_FORCE_INLINE Vec2 ZINC_PREF(vec2_one)()
{
    return ZINC_PREF(vec2)(1.0f, 1.0f);
}

static ZINC_FORCE_INLINE Vec2 ZINC_PREF(vec2_scale)(Vec2 vec, f32 s)
{
    return ZINC_PREF(vec2)(vec.arr[0] * s, vec.arr[1] * s);
}

static ZINC_FORCE_INLINE Vec2 ZINC_PREF(vec2_scale_eq)(Vec2 *vec,
                                                       f32 s)
{
    vec->arr[0] *= s;
    vec->arr[1] *= s;

    return *vec;
}

static ZINC_FORCE_INLINE Vec2 ZINC_PREF(vec2_add)(Vec2 a, Vec2 b)
{
    return ZINC_PREF(vec2)(a.arr[0] + b.arr[0], a.arr[1] + b.arr[1]);
}

static ZINC_FORCE_INLINE Vec2 ZINC_PREF(vec2_add_eq)(Vec2 *vec, Vec2 b)
{
    vec->arr[0] += b.arr[0];
    vec->arr[1] += b.arr[1];

    return *vec;
}

static ZINC_FORCE_INLINE Vec2 ZINC_PREF(vec2_sub)(Vec2 a, Vec2 b)
{
    return ZINC_PREF(vec2)(a.arr[0] - b.arr[0], a.arr[1] - b.arr[1]);
}

static ZINC_FORCE_INLINE Vec2 ZINC_PREF(vec2_sub_eq)(Vec2 *vec, Vec2 b)
{
    vec->arr[0] -= b.arr[0];
    vec->arr[1] -= b.arr[1];

    return *vec;
}

static ZINC_FORCE_INLINE f32 ZINC_PREF(vec2_dot)(Vec2 a, Vec2 b)
{
    return a.arr[0] * b.arr[0] + a.arr[1] * b.arr[1];
}

static ZINC_FORCE_INLINE f32 ZINC_PREF(vec2_squared_norm2)(Vec2 vec)
{
    return ZINC_PREF(vec2_dot)(vec, vec);
}

static ZINC_FORCE_INLINE f32 ZINC_PREF(vec2_norm2)(Vec2 vec)
{
    return sqrtf(ZINC_PREF(vec2_squared_norm2)(vec));
}

static ZINC_FORCE_INLINE Vec2 ZINC_PREF(vec2_normalize)(Vec2 vec)
{
    f32 len = ZINC_PREF(vec2_norm2)(vec);

    if (ZINC_UNLIKELY(ZINC_PREF(f32_eq)(len, 0.0f)))
        return vec;

    return ZINC_PREF(vec2_scale)(vec, 1.0f / len);
}

static ZINC_FORCE_INLINE Vec2 ZINC_PREF(vec2_normalize_eq)(Vec2 *vec)
{
    f32 len = ZINC_PREF(vec2_norm2)(*vec);

    if (ZINC_UNLIKELY(ZINC_PREF(f32_eq)(len, 0.0f)))
        return *vec;

    return ZINC_PREF(vec2_scale_eq)(vec, 1.0f / len);
}

#endif
