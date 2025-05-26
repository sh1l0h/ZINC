#ifndef ZINC_TYPES_H
#define ZINC_TYPES_H

#include <stdint.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <float.h>

#define ZINC_PI        3.141592653589793238462643383279
#define ZINC_PI_OVER_2 1.570796326794896619231321691639
#define ZINC_PI_OVER_4 0.785398163397448309615660845819
#define ZINC_E         2.718281828459045235360287471352
#define ZINC_LN2       0.693147180559945309417232121458
#define ZINC_LN10      2.302585092994045684017991454684

typedef uint8_t  u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;

typedef int8_t  i8;
typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

typedef float  f32;
typedef double f64;

#if defined(_MSC_VER)
#   define ZINC_FORCE_INLINE __forceinline
#elif defined(__GNUC__) || defined(__clang__)
#   define ZINC_FORCE_INLINE __attribute__((always_inline)) inline
#else
#   define ZINC_FORCE_INLINE inline
#endif

#if defined(__GNUC__) || defined(__clang__)
#   define ZINC_LIKELY(x) __builtin_expect(!!(x), 1)
#   define ZINC_UNLIKELY(x) __builtin_expect(!!(x), 0)
#else
#   define ZINC_LIKELY(x) (x)
#   define ZINC_UNLIKELY(x) (x)
#endif

#if defined(ZINC_WITHOUT_PREFIX)
#   define ZINC_PREF(_name) _name
#else
#   define ZINC_PREF(_name) zinc_##_name
#endif

#define ZINC_MAX(_a, _b) ((_a) < (_b) ? (_b) : (_a))
#define ZINC_MIN(_a, _b) ((_a) > (_b) ? (_b) : (_a))

static ZINC_FORCE_INLINE bool ZINC_PREF(f32_eq)(f32 a, f32 b)
{
    f32 tmp;

    if (a == b)
        return true;

    tmp = ZINC_MIN(fabs(a) + fabs(b), FLT_MAX) * fabs(a - b);
    return tmp < ZINC_MAX(FLT_MIN, tmp);
}

#endif
