#include "mat3.h"

inline void zinc_mat3_zero(Mat3 mat)
{
	Mat3 tmp = ZINC_MAT3_ZERO;
	zinc_mat3_copy(tmp, mat);
}

inline void zinc_mat3_eye(Mat3 mat)
{
	Mat3 tmp = ZINC_MAT3_EYE;
	zinc_mat3_copy(tmp, mat);
}

inline void zinc_mat3_scale(Mat3 mat, f32 c)
{
	mat[0][0] *= c;
	mat[0][1] *= c;
	mat[0][2] *= c;
	mat[1][0] *= c;
	mat[1][1] *= c;
	mat[1][2] *= c;
	mat[2][0] *= c;
	mat[2][1] *= c;
	mat[2][2] *= c;
}

inline void zinc_mat3_copy(const Mat3 src, Mat3 dest)
{
	dest[0][0] = src[0][0];
	dest[0][1] = src[0][1];
	dest[0][2] = src[0][2];
	dest[1][0] = src[1][0];
	dest[1][1] = src[1][1];
	dest[1][2] = src[1][2];
	dest[2][0] = src[2][0];
	dest[2][1] = src[2][1];
	dest[2][2] = src[2][2];
}

inline void zinc_mat3_add(const Mat3 a, const Mat3 b, Mat3 dest)
{
	dest[0][0] = a[0][0] + b[0][0];
	dest[0][1] = a[0][1] + b[0][1];
	dest[0][2] = a[0][2] + b[0][2];
	dest[1][0] = a[1][0] + b[1][0];
	dest[1][1] = a[1][1] + b[1][1];
	dest[1][2] = a[1][2] + b[1][2];
	dest[2][0] = a[2][0] + b[2][0];
	dest[2][1] = a[2][1] + b[2][1];
	dest[2][2] = a[2][2] + b[2][2];
}

inline void zinc_mat3_sub(const Mat3 a, const Mat3 b, Mat3 dest)
{
	dest[0][0] = a[0][0] - b[0][0];
	dest[0][1] = a[0][1] - b[0][1];
	dest[0][2] = a[0][2] - b[0][2];
	dest[1][0] = a[1][0] - b[1][0];
	dest[1][1] = a[1][1] - b[1][1];
	dest[1][2] = a[1][2] - b[1][2];
	dest[2][0] = a[2][0] - b[2][0];
	dest[2][1] = a[2][1] - b[2][1];
	dest[2][2] = a[2][2] - b[2][2];
}

inline void zinc_mat3_mul(const Mat3 a, const Mat3 b, Mat3 dest)
{
	const f32 a00 = a[0][0], b00 = b[0][0], a01 = a[0][1], b01 = b[0][1], a02 = a[0][2], b02 = b[0][2],
		      a10 = a[1][0], b10 = b[1][0], a11 = a[1][1], b11 = b[1][1], a12 = a[1][2], b12 = b[1][2],
		      a20 = a[2][0], b20 = b[2][0], a21 = a[2][1], b21 = b[2][1], a22 = a[2][2], b22 = b[2][2];

	dest[0][0] = a00*b00 + a01*b10 + a02*b20;
	dest[0][1] = a00*b01 + a01*b11 + a02*b21;
	dest[0][2] = a00*b02 + a01*b12 + a02*b22;
	dest[1][0] = a10*b00 + a11*b10 + a12*b20;
	dest[1][1] = a10*b01 + a11*b11 + a12*b21; 
	dest[1][2] = a10*b02 + a11*b12 + a12*b22; 
	dest[2][0] = a20*b00 + a21*b10 + a22*b20;
	dest[2][1] = a20*b01 + a21*b11 + a22*b21;
	dest[2][2] = a20*b02 + a21*b12 + a22*b22;
}

inline void zinc_mat3_mulv(const Mat3 mat, const Vec3 *vec, Vec3 *dest)
{
	const f32 x = vec->x, y = vec->y, z = vec->z;

	dest->x = x*mat[0][0] + y*mat[0][1] + z*mat[0][2];
	dest->y = x*mat[1][0] + y*mat[1][1] + z*mat[1][2];
	dest->z = x*mat[2][0] + y*mat[2][1] + z*mat[2][2];
}

inline void zinc_mat3_transpose_to(const Mat3 mat, Mat3 dest)
{
	dest[0][0] = mat[0][0];
	dest[0][1] = mat[1][0];
	dest[0][2] = mat[2][0];
	dest[1][0] = mat[0][1];
	dest[1][1] = mat[1][1];
	dest[1][2] = mat[2][1];
	dest[2][0] = mat[0][2];
	dest[2][1] = mat[1][2];
	dest[2][2] = mat[2][2];
}

inline void zinc_mat3_transpose(Mat3 mat)
{
	const f32 mat00 = mat[0][0], mat01 = mat[0][1], mat02 = mat[0][2],
		      mat10 = mat[1][0], mat11 = mat[1][1], mat12 = mat[1][2],
		      mat20 = mat[2][0], mat21 = mat[2][1], mat22 = mat[2][2];

	mat[0][0] = mat00;
	mat[0][1] = mat10;
	mat[0][2] = mat20;
	mat[1][0] = mat01;
	mat[1][1] = mat11;
	mat[1][2] = mat21;
	mat[2][0] = mat02;
	mat[2][1] = mat12;
	mat[2][2] = mat22;
}

inline f32 zinc_mat3_determinant(const Mat3 mat)
{
	float det = 0;
	
	det = mat[0][0] * (mat[1][1] * mat[2][2] - mat[2][1] * mat[1][2]);
	det -= mat[1][0] * (mat[0][1] * mat[2][2] - mat[2][1] * mat[0][2]);
	det += mat[2][0] * (mat[0][1] * mat[1][2] - mat[1][1] * mat[0][2]);

	return det;
}

inline f32 zinc_mat3_trace(const Mat3 mat)
{
	return mat[0][0] + mat[1][1] + mat[2][2];
}
