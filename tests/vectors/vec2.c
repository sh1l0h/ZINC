#define ZINC_WITHOUT_PREFIX
#include "vec2.h"
#include "cut.h"

static bool vec2_eq(Vec2 a, Vec2 b)
{
    return f32_eq(a.arr[0], b.arr[0]) && f32_eq(a.arr[1], b.arr[1]);
}

CUT_TEST(test_vec2_constructor)
{
    Vec2 v = vec2(3.0f, 4.0f);

    CUT_ASSERT(f32_eq(v.arr[0], 3.0f));
    CUT_ASSERT(f32_eq(v.arr[1], 4.0f));

#if __STDC_VERSION__ >= 201112L
    CUT_ASSERT(f32_eq(v.x, 3.0f));
    CUT_ASSERT(f32_eq(v.y, 4.0f));
#endif

    CUT_TEST_PASS;
}

CUT_TEST(test_vec2_zero)
{
    Vec2 v = vec2_zero();

    CUT_ASSERT(f32_eq(v.arr[0], 0.0f));
    CUT_ASSERT(f32_eq(v.arr[1], 0.0f));

    CUT_TEST_PASS;
}

CUT_TEST(test_vec2_one)
{
    Vec2 v = vec2_one();

    CUT_ASSERT(f32_eq(v.arr[0], 1.0f));
    CUT_ASSERT(f32_eq(v.arr[1], 1.0f));

    CUT_TEST_PASS;
}

CUT_TEST(test_vec2_scale)
{
    Vec2 v = vec2(2.0f, 3.0f);
    Vec2 result = vec2_scale(v, 2.0f);

    CUT_ASSERT(f32_eq(result.arr[0], 4.0f));
    CUT_ASSERT(f32_eq(result.arr[1], 6.0f));

    CUT_ASSERT(f32_eq(v.arr[0], 2.0f));
    CUT_ASSERT(f32_eq(v.arr[1], 3.0f));

    CUT_TEST_PASS;
}

CUT_TEST(test_vec2_scale_eq)
{
    Vec2 v = vec2(2.0f, 3.0f);
    Vec2 result = vec2_scale_eq(&v, 2.0f);

    CUT_ASSERT(f32_eq(v.arr[0], 4.0f));
    CUT_ASSERT(f32_eq(v.arr[1], 6.0f));
    CUT_ASSERT(f32_eq(result.arr[0], 4.0f));
    CUT_ASSERT(f32_eq(result.arr[1], 6.0f));

    CUT_TEST_PASS;
}

CUT_TEST(test_vec2_add)
{
    Vec2 a = vec2(1.0f, 2.0f);
    Vec2 b = vec2(3.0f, 4.0f);
    Vec2 result = vec2_add(a, b);

    CUT_ASSERT(f32_eq(result.arr[0], 4.0f));
    CUT_ASSERT(f32_eq(result.arr[1], 6.0f));

    CUT_ASSERT(f32_eq(a.arr[0], 1.0f));
    CUT_ASSERT(f32_eq(a.arr[1], 2.0f));
    CUT_ASSERT(f32_eq(b.arr[0], 3.0f));
    CUT_ASSERT(f32_eq(b.arr[1], 4.0f));

    CUT_TEST_PASS;
}

CUT_TEST(test_vec2_add_eq)
{
    Vec2 a = vec2(1.0f, 2.0f);
    Vec2 b = vec2(3.0f, 4.0f);
    Vec2 result = vec2_add_eq(&a, b);

    CUT_ASSERT(f32_eq(a.arr[0], 4.0f));
    CUT_ASSERT(f32_eq(a.arr[1], 6.0f));
    CUT_ASSERT(f32_eq(result.arr[0], 4.0f));
    CUT_ASSERT(f32_eq(result.arr[1], 6.0f));

    CUT_ASSERT(f32_eq(b.arr[0], 3.0f));
    CUT_ASSERT(f32_eq(b.arr[1], 4.0f));

    CUT_TEST_PASS;
}

CUT_TEST(test_vec2_sub)
{
    Vec2 a = vec2(5.0f, 8.0f);
    Vec2 b = vec2(2.0f, 3.0f);
    Vec2 result = vec2_sub(a, b);

    CUT_ASSERT(f32_eq(result.arr[0], 3.0f));
    CUT_ASSERT(f32_eq(result.arr[1], 5.0f));

    CUT_ASSERT(f32_eq(a.arr[0], 5.0f));
    CUT_ASSERT(f32_eq(a.arr[1], 8.0f));
    CUT_ASSERT(f32_eq(b.arr[0], 2.0f));
    CUT_ASSERT(f32_eq(b.arr[1], 3.0f));

    CUT_TEST_PASS;
}

CUT_TEST(test_vec2_sub_eq)
{
    Vec2 a = vec2(5.0f, 8.0f);
    Vec2 b = vec2(2.0f, 3.0f);
    Vec2 result = vec2_sub_eq(&a, b);

    CUT_ASSERT(f32_eq(a.arr[0], 3.0f));
    CUT_ASSERT(f32_eq(a.arr[1], 5.0f));
    CUT_ASSERT(f32_eq(result.arr[0], 3.0f));
    CUT_ASSERT(f32_eq(result.arr[1], 5.0f));

    CUT_ASSERT(f32_eq(b.arr[0], 2.0f));
    CUT_ASSERT(f32_eq(b.arr[1], 3.0f));

    CUT_TEST_PASS;
}

CUT_TEST(test_vec2_dot)
{
    Vec2 a = vec2(2.0f, 3.0f);
    Vec2 b = vec2(4.0f, 5.0f);

    f32 result = vec2_dot(a, b);
    CUT_ASSERT(f32_eq(result, 23.0f));

    CUT_TEST_PASS;
}

CUT_TEST(test_vec2_squared_norm2)
{
    Vec2 v = vec2(3.0f, 4.0f);
    f32 result = vec2_squared_norm2(v);

    CUT_ASSERT(f32_eq(result, 25.0f));

    CUT_TEST_PASS;
}

CUT_TEST(test_vec2_norm2)
{
    Vec2 v = vec2(3.0f, 4.0f);
    f32 result = vec2_norm2(v);

    CUT_ASSERT(f32_eq(result, 5.0f));

    CUT_TEST_PASS;
}

CUT_TEST(test_vec2_normalize)
{
    Vec2 v = vec2(3.0f, 4.0f);
    Vec2 result = vec2_normalize(v);
    f32 length = 5.0f;
    Vec2 expected = vec2(3.0f / length, 4.0f / length);

    CUT_ASSERT(vec2_eq(result, expected));

    CUT_ASSERT(f32_eq(v.arr[0], 3.0f));
    CUT_ASSERT(f32_eq(v.arr[1], 4.0f));

    CUT_TEST_PASS;
}

CUT_TEST(test_vec2_normalize_eq)
{
    Vec2 v = vec2(3.0f, 4.0f);
    Vec2 result = vec2_normalize_eq(&v);
    f32 length = 5.0f;
    Vec2 expected = vec2(3.0f / length, 4.0f / length);

    CUT_ASSERT(vec2_eq(result, expected));
    CUT_ASSERT(vec2_eq(v, expected));

    CUT_TEST_PASS;
}

CUT_TEST(test_vec2_normalize_zero)
{
    Vec2 v = vec2_zero();
    Vec2 result = vec2_normalize(v);

    CUT_ASSERT(vec2_eq(result, v));

    CUT_TEST_PASS;
}

CUT_TEST(test_vec2_normalize_eq_zero)
{
    Vec2 v = vec2_zero();
    Vec2 result = vec2_normalize_eq(&v);

    CUT_ASSERT(vec2_eq(result, v));
    CUT_ASSERT(vec2_eq(v, vec2_zero()));

    CUT_TEST_PASS;
}
