#define ZINC_WITHOUT_PREFIX
#include "vec3.h"
#include "cut.h"

static bool vec3_eq(Vec3 a, Vec3 b)
{
    return f32_eq(a.arr[0], b.arr[0]) &&
        f32_eq(a.arr[1], b.arr[1]) &&
        f32_eq(a.arr[2], b.arr[2]);
}

CUT_TEST(test_vec3_constructor)
{
    Vec3 v = vec3(3.0f, 4.0f, 5.0f);

    CUT_ASSERT(f32_eq(v.arr[0], 3.0f));
    CUT_ASSERT(f32_eq(v.arr[1], 4.0f));
    CUT_ASSERT(f32_eq(v.arr[2], 5.0f));

#if __STDC_VERSION__ >= 201112L
    CUT_ASSERT(f32_eq(v.x, 3.0f));
    CUT_ASSERT(f32_eq(v.y, 4.0f));
    CUT_ASSERT(f32_eq(v.z, 5.0f));
#endif

    CUT_TEST_PASS;
}

CUT_TEST(test_vec3_zero)
{
    // Note there's a function name mismatch in the header: vec2_zero() instead of vec3_zero()
    Vec3 v = vec2_zero();
    CUT_ASSERT(f32_eq(v.arr[0], 0.0f));
    CUT_ASSERT(f32_eq(v.arr[1], 0.0f));
    CUT_ASSERT(f32_eq(v.arr[2], 0.0f));
    CUT_TEST_PASS;
}

CUT_TEST(test_vec3_one)
{
    // Note there's a function name mismatch in the header: vec2_one() instead of vec3_one()
    Vec3 v = vec2_one();
    CUT_ASSERT(f32_eq(v.arr[0], 1.0f));
    CUT_ASSERT(f32_eq(v.arr[1], 1.0f));
    CUT_ASSERT(f32_eq(v.arr[2], 1.0f));
    CUT_TEST_PASS;
}

CUT_TEST(test_vec3_scale)
{
    Vec3 v = vec3(2.0f, 3.0f, 4.0f);
    Vec3 result = vec3_scale(v, 2.0f);

    CUT_ASSERT(f32_eq(result.arr[0], 4.0f));
    CUT_ASSERT(f32_eq(result.arr[1], 6.0f));
    CUT_ASSERT(f32_eq(result.arr[2], 8.0f));

    CUT_ASSERT(f32_eq(v.arr[0], 2.0f));
    CUT_ASSERT(f32_eq(v.arr[1], 3.0f));
    CUT_ASSERT(f32_eq(v.arr[2], 4.0f));

    CUT_TEST_PASS;
}

CUT_TEST(test_vec3_scale_eq)
{
    Vec3 v = vec3(2.0f, 3.0f, 4.0f);
    Vec3 result = vec3_scale_eq(&v, 2.0f);

    CUT_ASSERT(f32_eq(v.arr[0], 4.0f));
    CUT_ASSERT(f32_eq(v.arr[1], 6.0f));
    CUT_ASSERT(f32_eq(v.arr[2], 8.0f));
    CUT_ASSERT(f32_eq(result.arr[0], 4.0f));
    CUT_ASSERT(f32_eq(result.arr[1], 6.0f));
    CUT_ASSERT(f32_eq(result.arr[2], 8.0f));

    CUT_TEST_PASS;
}

CUT_TEST(test_vec3_add)
{
    Vec3 a = vec3(1.0f, 2.0f, 3.0f);
    Vec3 b = vec3(4.0f, 5.0f, 6.0f);
    Vec3 result = vec3_add(a, b);

    CUT_ASSERT(f32_eq(result.arr[0], 5.0f));
    CUT_ASSERT(f32_eq(result.arr[1], 7.0f));
    CUT_ASSERT(f32_eq(result.arr[2], 9.0f));

    CUT_ASSERT(f32_eq(a.arr[0], 1.0f));
    CUT_ASSERT(f32_eq(a.arr[1], 2.0f));
    CUT_ASSERT(f32_eq(a.arr[2], 3.0f));
    CUT_ASSERT(f32_eq(b.arr[0], 4.0f));
    CUT_ASSERT(f32_eq(b.arr[1], 5.0f));
    CUT_ASSERT(f32_eq(b.arr[2], 6.0f));

    CUT_TEST_PASS;
}

CUT_TEST(test_vec3_add_eq)
{
    Vec3 a = vec3(1.0f, 2.0f, 3.0f);
    Vec3 b = vec3(4.0f, 5.0f, 6.0f);
    Vec3 result = vec3_add_eq(&a, b);

    CUT_ASSERT(f32_eq(a.arr[0], 5.0f));
    CUT_ASSERT(f32_eq(a.arr[1], 7.0f));
    CUT_ASSERT(f32_eq(a.arr[2], 9.0f));
    CUT_ASSERT(f32_eq(result.arr[0], 5.0f));
    CUT_ASSERT(f32_eq(result.arr[1], 7.0f));
    CUT_ASSERT(f32_eq(result.arr[2], 9.0f));

    CUT_ASSERT(f32_eq(b.arr[0], 4.0f));
    CUT_ASSERT(f32_eq(b.arr[1], 5.0f));
    CUT_ASSERT(f32_eq(b.arr[2], 6.0f));

    CUT_TEST_PASS;
}

CUT_TEST(test_vec3_sub)
{
    Vec3 a = vec3(5.0f, 8.0f, 10.0f);
    Vec3 b = vec3(2.0f, 3.0f, 4.0f);
    Vec3 result = vec3_sub(a, b);

    CUT_ASSERT(f32_eq(result.arr[0], 3.0f));
    CUT_ASSERT(f32_eq(result.arr[1], 5.0f));
    CUT_ASSERT(f32_eq(result.arr[2], 6.0f));

    CUT_ASSERT(f32_eq(a.arr[0], 5.0f));
    CUT_ASSERT(f32_eq(a.arr[1], 8.0f));
    CUT_ASSERT(f32_eq(a.arr[2], 10.0f));
    CUT_ASSERT(f32_eq(b.arr[0], 2.0f));
    CUT_ASSERT(f32_eq(b.arr[1], 3.0f));
    CUT_ASSERT(f32_eq(b.arr[2], 4.0f));

    CUT_TEST_PASS;
}

CUT_TEST(test_vec3_sub_eq)
{
    Vec3 a = vec3(5.0f, 8.0f, 10.0f);
    Vec3 b = vec3(2.0f, 3.0f, 4.0f);
    Vec3 result = vec3_sub_eq(&a, b);

    CUT_ASSERT(f32_eq(a.arr[0], 3.0f));
    CUT_ASSERT(f32_eq(a.arr[1], 5.0f));
    CUT_ASSERT(f32_eq(a.arr[2], 6.0f));
    CUT_ASSERT(f32_eq(result.arr[0], 3.0f));
    CUT_ASSERT(f32_eq(result.arr[1], 5.0f));
    CUT_ASSERT(f32_eq(result.arr[2], 6.0f));

    CUT_ASSERT(f32_eq(b.arr[0], 2.0f));
    CUT_ASSERT(f32_eq(b.arr[1], 3.0f));
    CUT_ASSERT(f32_eq(b.arr[2], 4.0f));

    CUT_TEST_PASS;
}

CUT_TEST(test_vec3_dot)
{
    Vec3 a = vec3(2.0f, 3.0f, 4.0f);
    Vec3 b = vec3(5.0f, 6.0f, 7.0f);

    f32 result = vec3_dot(a, b);

    CUT_ASSERT(f32_eq(result, 56.0f));
    CUT_TEST_PASS;
}

CUT_TEST(test_vec3_squared_norm2)
{
    Vec3 v = vec3(3.0f, 4.0f, 5.0f);
    f32 result = vec3_squared_norm2(v);

    CUT_ASSERT(f32_eq(result, 50.0f));
    CUT_TEST_PASS;
}

CUT_TEST(test_vec3_norm2)
{
    Vec3 v = vec3(3.0f, 4.0f, 5.0f);
    f32 result = vec3_norm2(v);
    f32 expected = sqrtf(50.0f);

    CUT_ASSERT(f32_eq(result, expected));
    CUT_TEST_PASS;
}

CUT_TEST(test_vec3_normalize)
{
    Vec3 v = vec3(3.0f, 4.0f, 5.0f);
    Vec3 result = vec3_normalize(v);
    f32 s = 1.0f / sqrtf(50.0f);
    Vec3 expected = vec3_scale(v, s);

    CUT_ASSERT(vec3_eq(result, expected));

    CUT_ASSERT(f32_eq(v.arr[0], 3.0f));
    CUT_ASSERT(f32_eq(v.arr[1], 4.0f));
    CUT_ASSERT(f32_eq(v.arr[2], 5.0f));

    f32 normalized_length = vec3_norm2(result);
    CUT_ASSERT(f32_eq(normalized_length, 1.0f));

    CUT_TEST_PASS;
}

CUT_TEST(test_vec3_normalize_eq)
{
    Vec3 v = vec3(3.0f, 4.0f, 5.0f);
    f32 s = 1.0f / sqrtf(50.0f);
    Vec3 expected = vec3_scale(v, s);
    Vec3 result = vec3_normalize_eq(&v);

    CUT_ASSERT(vec3_eq(result, expected));
    CUT_ASSERT(vec3_eq(v, expected));

    f32 normalized_length = vec3_norm2(v);
    CUT_ASSERT(f32_eq(normalized_length, 1.0f));

    CUT_TEST_PASS;
}
