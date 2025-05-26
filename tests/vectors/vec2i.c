#define ZINC_WITHOUT_PREFIX
#include "vec2i.h"
#include "cut.h"

CUT_TEST(test_vec2i_constructor)
{
    Vec2i v = vec2i(3, 4);

    CUT_ASSERT(v.arr[0] == 3);
    CUT_ASSERT(v.arr[1] == 4);

#if __STDC_VERSION__ >= 201112L
    CUT_ASSERT(v.x == 3);
    CUT_ASSERT(v.y == 4);
#endif

    CUT_TEST_PASS;
}

CUT_TEST(test_vec2i_zero)
{
    Vec2i v = vec2i_zero();

    CUT_ASSERT(v.arr[0] == 0);
    CUT_ASSERT(v.arr[1] == 0);
    CUT_TEST_PASS;
}

CUT_TEST(test_vec2i_one)
{
    Vec2i v = vec2i_one();

    CUT_ASSERT(v.arr[0] == 1);
    CUT_ASSERT(v.arr[1] == 1);
    CUT_TEST_PASS;
}

CUT_TEST(test_vec2i_scale)
{
    Vec2i v = vec2i(2, 3);
    Vec2i result = vec2i_scale(v, 2);

    CUT_ASSERT(result.arr[0] == 4);
    CUT_ASSERT(result.arr[1] == 6);

    CUT_ASSERT(v.arr[0] == 2);
    CUT_ASSERT(v.arr[1] == 3);

    CUT_TEST_PASS;
}

CUT_TEST(test_vec2i_scale_eq)
{
    Vec2i v = vec2i(2, 3);
    Vec2i result = vec2i_scale_eq(&v, 2);

    CUT_ASSERT(v.arr[0] == 4);
    CUT_ASSERT(v.arr[1] == 6);
    CUT_ASSERT(result.arr[0] == 4);
    CUT_ASSERT(result.arr[1] == 6);

    CUT_TEST_PASS;
}

CUT_TEST(test_vec2i_div)
{
    Vec2i v = vec2i(10, 15);
    Vec2i result = vec2i_div(v, 5);

    CUT_ASSERT(result.arr[0] == 2);
    CUT_ASSERT(result.arr[1] == 3);

    CUT_ASSERT(v.arr[0] == 10);
    CUT_ASSERT(v.arr[1] == 15);

    CUT_TEST_PASS;
}

CUT_TEST(test_vec2i_div_eq)
{
    Vec2i v = vec2i(10, 15);
    Vec2i result = vec2i_div_eq(&v, 5);

    CUT_ASSERT(v.arr[0] == 2);
    CUT_ASSERT(v.arr[1] == 3);
    CUT_ASSERT(result.arr[0] == 2);
    CUT_ASSERT(result.arr[1] == 3);

    CUT_TEST_PASS;
}

CUT_TEST(test_vec2i_add)
{
    Vec2i a = vec2i(1, 2);
    Vec2i b = vec2i(3, 4);
    Vec2i result = vec2i_add(a, b);

    CUT_ASSERT(result.arr[0] == 4);
    CUT_ASSERT(result.arr[1] == 6);

    CUT_ASSERT(a.arr[0] == 1);
    CUT_ASSERT(a.arr[1] == 2);
    CUT_ASSERT(b.arr[0] == 3);
    CUT_ASSERT(b.arr[1] == 4);

    CUT_TEST_PASS;
}

CUT_TEST(test_vec2i_add_eq)
{
    Vec2i a = vec2i(1, 2);
    Vec2i b = vec2i(3, 4);
    Vec2i result = vec2i_add_eq(&a, b);

    CUT_ASSERT(a.arr[0] == 4);
    CUT_ASSERT(a.arr[1] == 6);
    CUT_ASSERT(result.arr[0] == 4);
    CUT_ASSERT(result.arr[1] == 6);

    CUT_ASSERT(b.arr[0] == 3);
    CUT_ASSERT(b.arr[1] == 4);

    CUT_TEST_PASS;
}

CUT_TEST(test_vec2i_sub)
{
    Vec2i a = vec2i(5, 8);
    Vec2i b = vec2i(2, 3);
    Vec2i result = vec2i_sub(a, b);

    CUT_ASSERT(result.arr[0] == 3);
    CUT_ASSERT(result.arr[1] == 5);

    CUT_ASSERT(a.arr[0] == 5);
    CUT_ASSERT(a.arr[1] == 8);
    CUT_ASSERT(b.arr[0] == 2);
    CUT_ASSERT(b.arr[1] == 3);

    CUT_TEST_PASS;
}

CUT_TEST(test_vec2i_sub_eq)
{
    Vec2i a = vec2i(5, 8);
    Vec2i b = vec2i(2, 3);
    Vec2i result = vec2i_sub_eq(&a, b);

    CUT_ASSERT(a.arr[0] == 3);
    CUT_ASSERT(a.arr[1] == 5);
    CUT_ASSERT(result.arr[0] == 3);
    CUT_ASSERT(result.arr[1] == 5);

    CUT_ASSERT(b.arr[0] == 2);
    CUT_ASSERT(b.arr[1] == 3);

    CUT_TEST_PASS;
}

CUT_TEST(test_vec2i_dot)
{
    Vec2i a = vec2i(2, 3);
    Vec2i b = vec2i(4, 5);
    i32 result = vec2i_dot(a, b);

    CUT_ASSERT(result == 23);

    CUT_TEST_PASS;
}

CUT_TEST(test_vec2i_squared_norm2)
{
    Vec2i v = vec2i(3, 4);
    i32 result = vec2i_squared_norm2(v);

    CUT_ASSERT(result == 25);

    CUT_TEST_PASS;
}

CUT_TEST(test_vec2i_norm2)
{
    Vec2i v = vec2i(3, 4);
    f32 result = vec2i_norm2(v);

    CUT_ASSERT(f32_eq(result, 5.0f));

    CUT_TEST_PASS;
}

CUT_TEST(test_vec2i_norm2_zero)
{
    Vec2i v = vec2i_zero();
    f32 result = vec2i_norm2(v);

    CUT_ASSERT(f32_eq(result, 0.0f));

    CUT_TEST_PASS;
}
