#include "../include/mat2.h"

inline void zinc_mat2_zero(Mat2 mat)
{
	Mat2 tmp = ZINC_MAT2_ZERO;
	zinc_mat2_copy(tmp, mat);
}

inline void zinc_mat2_eye(Mat2 mat)
{
	Mat2 tmp = ZINC_MAT2_EYE;
	zinc_mat2_copy(tmp, mat);
}

inline void zinc_mat2_scale(Mat2 mat, f32 c)
{
	mat[0][0] *= c;
	mat[0][1] *= c;
	mat[1][0] *= c;
	mat[1][1] *= c;
}

inline void zinc_mat2_copy(const Mat2 src, Mat2 dest)
{
	dest[0][0] = src[0][0];
	dest[0][1] = src[0][1];
	dest[1][0] = src[1][0];
	dest[1][1] = src[1][1];
}

inline void zinc_mat2_add(const Mat2 a, const Mat2 b, Mat2 dest)
{
	dest[0][0] = a[0][0] + b[0][0];
	dest[0][1] = a[0][1] + b[0][1];
	dest[1][0] = a[1][0] + b[1][0];
	dest[1][1] = a[1][1] + b[1][1];
}

inline void zinc_mat2_sub(const Mat2 a, const Mat2 b, Mat2 dest)
{
	dest[0][0] = a[0][0] - b[0][0];
	dest[0][1] = a[0][1] - b[0][1];
	dest[1][0] = a[1][0] - b[1][0];
	dest[1][1] = a[1][1] - b[1][1];
}

inline void zinc_mat2_mul(const Mat2 a, const Mat2 b, Mat2 dest)
{
	const f32 a00 = a[0][0], b00 = b[0][0], a01 = a[0][1], b01 = b[0][1],
		      a10 = a[1][0], b10 = b[1][0], a11 = a[1][1], b11 = b[1][1];

	dest[0][0] = a00*b00 + a01*b10; 
	dest[0][1] = a00*b01 + a01*b11; 
	dest[1][0] = a10*b00 + a11*b10;
	dest[1][1] = a10*b01 + a11*b11; 
}

inline void zinc_mat2_mulv(const Mat2 mat, const Vec2 *vec, Vec2 *dest)
{
	const f32 x = vec->x, y = vec->y;

	dest->x = x*mat[0][0] + y*mat[0][1];
	dest->y = x*mat[1][0] + y*mat[1][1];
}

inline void zinc_mat2_transpose_to(const Mat2 mat, Mat2 dest)
{
	dest[0][0] = mat[0][0];
	dest[0][1] = mat[1][0];
	dest[1][0] = mat[0][1];
	dest[1][1] = mat[1][1];
}

inline void zinc_mat2_transpose(Mat2 mat)
{
	const f32 mat00 = mat[0][0], mat01 = mat[0][1],
		      mat10 = mat[1][0], mat11 = mat[1][1];

	mat[0][0] = mat00;
	mat[0][1] = mat10;
	mat[1][0] = mat01;
	mat[1][1] = mat11;
}

inline f32 zinc_mat2_determinant(const Mat2 mat)
{
	return mat[0][0]*mat[1][1] - mat[1][0]*mat[0][1];
}

inline f32 zinc_mat2_trace(const Mat2 mat)
{
	return mat[0][0] + mat[1][1];
}

