#ifndef ZINC_VEC2I_H
#define ZINC_VEC2I_H

#include "utils.h"

typedef union Vec2i {
    i32 arr[2];
#if __STDC_VERSION__ >= 201112L
    struct {
        i32 x;
        i32 y;
    };
#endif
} Vec2i;

static ZINC_FORCE_INLINE Vec2i ZINC_PREF(vec2i)(i32 x, i32 y)
{
    return (Vec2i) {{x, y}};
}

static ZINC_FORCE_INLINE Vec2i ZINC_PREF(vec2i_zero)()
{
    return ZINC_PREF(vec2i)(0, 0);
}

static ZINC_FORCE_INLINE Vec2i ZINC_PREF(vec2i_one)()
{
    return ZINC_PREF(vec2i)(1, 1);
}

static ZINC_FORCE_INLINE Vec2i ZINC_PREF(vec2i_scale)(Vec2i vec, i32 s)
{
    return ZINC_PREF(vec2i)(vec.arr[0] * s, vec.arr[1] * s);
}

static ZINC_FORCE_INLINE Vec2i ZINC_PREF(vec2i_scale_eq)(Vec2i *vec,
                                                       i32 s)
{
    vec->arr[0] *= s;
    vec->arr[1] *= s;

    return *vec;
}

static ZINC_FORCE_INLINE Vec2i ZINC_PREF(vec2i_div)(Vec2i vec, i32 s)
{
    return ZINC_PREF(vec2i)(vec.arr[0] / s, vec.arr[1] / s);
}

static ZINC_FORCE_INLINE Vec2i ZINC_PREF(vec2i_div_eq)(Vec2i *vec,
                                                       i32 s)
{
    vec->arr[0] /= s;
    vec->arr[1] /= s;

    return *vec;
}

static ZINC_FORCE_INLINE Vec2i ZINC_PREF(vec2i_add)(Vec2i a, Vec2i b)
{
    return ZINC_PREF(vec2i)(a.arr[0] + b.arr[0], a.arr[1] + b.arr[1]);
}

static ZINC_FORCE_INLINE Vec2i ZINC_PREF(vec2i_add_eq)(Vec2i *vec, Vec2i b)
{
    vec->arr[0] += b.arr[0];
    vec->arr[1] += b.arr[1];

    return *vec;
}

static ZINC_FORCE_INLINE Vec2i ZINC_PREF(vec2i_sub)(Vec2i a, Vec2i b)
{
    return ZINC_PREF(vec2i)(a.arr[0] - b.arr[0], a.arr[1] - b.arr[1]);
}

static ZINC_FORCE_INLINE Vec2i ZINC_PREF(vec2i_sub_eq)(Vec2i *vec, Vec2i b)
{
    vec->arr[0] -= b.arr[0];
    vec->arr[1] -= b.arr[1];

    return *vec;
}

static ZINC_FORCE_INLINE i32 ZINC_PREF(vec2i_dot)(Vec2i a, Vec2i b)
{
    return a.arr[0] * b.arr[0] + a.arr[1] * b.arr[1];
}

static ZINC_FORCE_INLINE i32 ZINC_PREF(vec2i_squared_norm2)(Vec2i vec)
{
    return ZINC_PREF(vec2i_dot)(vec, vec);
}

static ZINC_FORCE_INLINE f32 ZINC_PREF(vec2i_norm2)(Vec2i vec)
{
    return sqrtf(ZINC_PREF(vec2i_squared_norm2)(vec));
}

#endif
