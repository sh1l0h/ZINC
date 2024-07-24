#include "mat4.h"

inline void zinc_mat4_zero(Mat4 mat)
{
	Mat4 tmp = ZINC_MAT4_ZERO;
	zinc_mat4_copy(tmp, mat);
}

inline void zinc_mat4_eye(Mat4 mat)
{
	Mat4 tmp = ZINC_MAT4_EYE;
	zinc_mat4_copy(tmp, mat);
}

inline void zinc_mat4_scale(Mat4 mat, f32 c)
{
	mat[0][0] *= c;
	mat[0][1] *= c;
	mat[0][2] *= c;
	mat[0][3] *= c;
	mat[1][0] *= c;
	mat[1][1] *= c;
	mat[1][2] *= c;
	mat[1][3] *= c;
	mat[2][0] *= c;
	mat[2][1] *= c;
	mat[2][2] *= c;
	mat[2][3] *= c;
	mat[3][0] *= c;
	mat[3][1] *= c;
	mat[3][2] *= c;
	mat[3][3] *= c;
}

inline void zinc_mat4_copy(const Mat4 src, Mat4 dest)
{
	dest[0][0] = src[0][0];
	dest[0][1] = src[0][1];
	dest[0][2] = src[0][2];
	dest[0][3] = src[0][3];
	dest[1][0] = src[1][0];
	dest[1][1] = src[1][1];
	dest[1][2] = src[1][2];
	dest[1][3] = src[1][3];
	dest[2][0] = src[2][0];
	dest[2][1] = src[2][1];
	dest[2][2] = src[2][2];
	dest[2][3] = src[2][3];
	dest[3][0] = src[3][0];
	dest[3][1] = src[3][1];
	dest[3][2] = src[3][2];
	dest[3][3] = src[3][3];
}

inline void zinc_mat4_add(const Mat4 a, const Mat4 b, Mat4 dest)
{
	dest[0][0] = a[0][0] + b[0][0];
	dest[0][1] = a[0][1] + b[0][1];
	dest[0][2] = a[0][2] + b[0][2];
	dest[0][3] = a[0][3] + b[0][3];
	dest[1][0] = a[1][0] + b[1][0];
	dest[1][1] = a[1][1] + b[1][1];
	dest[1][2] = a[1][2] + b[1][2];
	dest[1][3] = a[1][3] + b[1][3];
	dest[2][0] = a[2][0] + b[2][0];
	dest[2][1] = a[2][1] + b[2][1];
	dest[2][2] = a[2][2] + b[2][2];
	dest[2][3] = a[2][3] + b[2][3];
	dest[3][0] = a[3][0] + b[3][0];
	dest[3][1] = a[3][1] + b[3][1];
	dest[3][2] = a[3][2] + b[3][2];
	dest[3][3] = a[3][3] + b[3][3];
}

inline void zinc_mat4_sub(const Mat4 a, const Mat4 b, Mat4 dest)
{
	dest[0][0] = a[0][0] - b[0][0];
	dest[0][1] = a[0][1] - b[0][1];
	dest[0][2] = a[0][2] - b[0][2];
	dest[0][3] = a[0][3] - b[0][3];
	dest[1][0] = a[1][0] - b[1][0];
	dest[1][1] = a[1][1] - b[1][1];
	dest[1][2] = a[1][2] - b[1][2];
	dest[1][3] = a[1][3] - b[1][3];
	dest[2][0] = a[2][0] - b[2][0];
	dest[2][1] = a[2][1] - b[2][1];
	dest[2][2] = a[2][2] - b[2][2];
	dest[2][3] = a[2][3] - b[2][3];
	dest[3][0] = a[3][0] - b[3][0];
	dest[3][1] = a[3][1] - b[3][1];
	dest[3][2] = a[3][2] - b[3][2];
	dest[3][3] = a[3][3] - b[3][3];
}

inline void zinc_mat4_mul(const Mat4 a, const Mat4 b, Mat4 dest)
{
	const f32 a00 = a[0][0], b00 = b[0][0], a01 = a[0][1], b01 = b[0][1], a02 = a[0][2], b02 = b[0][2], a03 = a[0][3], b03 = b[0][3],
		      a10 = a[1][0], b10 = b[1][0], a11 = a[1][1], b11 = b[1][1], a12 = a[1][2], b12 = b[1][2], a13 = a[1][3], b13 = b[1][3],
		      a20 = a[2][0], b20 = b[2][0], a21 = a[2][1], b21 = b[2][1], a22 = a[2][2], b22 = b[2][2], a23 = a[2][3], b23 = b[2][3],
		      a30 = a[3][0], b30 = b[3][0], a31 = a[3][1], b31 = b[3][1], a32 = a[3][2], b32 = b[3][2], a33 = a[3][3], b33 = b[3][3];

	dest[0][0] = a00*b00 + a01*b10 + a02*b20 + a03*b30;
	dest[0][1] = a00*b01 + a01*b11 + a02*b21 + a03*b31;
	dest[0][2] = a00*b02 + a01*b12 + a02*b22 + a03*b32;
	dest[0][3] = a00*b03 + a01*b13 + a02*b23 + a03*b33;
	dest[1][0] = a10*b00 + a11*b10 + a12*b20 + a13*b30;
	dest[1][1] = a10*b01 + a11*b11 + a12*b21 + a13*b31; 
	dest[1][2] = a10*b02 + a11*b12 + a12*b22 + a13*b32; 
	dest[1][3] = a10*b03 + a11*b13 + a12*b23 + a13*b33; 
	dest[2][0] = a20*b00 + a21*b10 + a22*b20 + a23*b30;
	dest[2][1] = a20*b01 + a21*b11 + a22*b21 + a23*b31;
	dest[2][2] = a20*b02 + a21*b12 + a22*b22 + a23*b32;
	dest[2][3] = a20*b03 + a21*b13 + a22*b23 + a23*b33;
	dest[3][0] = a30*b00 + a31*b10 + a32*b20 + a33*b30;
	dest[3][1] = a30*b01 + a31*b11 + a32*b21 + a33*b31;
	dest[3][2] = a30*b02 + a31*b12 + a32*b22 + a33*b32;
	dest[3][3] = a30*b03 + a31*b13 + a32*b23 + a33*b33;
}

inline void zinc_mat4_mulv(const Mat4 mat, const Vec4 *vec, Vec4 *dest)
{
	const f32 x = vec->x, y = vec->y, z = vec->z, w = vec->w;

	dest->x = x*mat[0][0] + y*mat[0][1] + z*mat[0][2] + w*mat[0][3];
	dest->y = x*mat[1][0] + y*mat[1][1] + z*mat[1][2] + w*mat[1][3];
	dest->z = x*mat[2][0] + y*mat[2][1] + z*mat[2][2] + w*mat[2][3];
	dest->w = x*mat[3][0] + y*mat[3][1] + z*mat[3][2] + w*mat[3][3];
}

inline void zinc_mat4_transpose_to(const Mat4 mat, Mat4 dest)
{
	dest[0][0] = mat[0][0];
	dest[0][1] = mat[1][0];
	dest[0][2] = mat[2][0];
	dest[0][3] = mat[3][0];
	dest[1][0] = mat[0][1];
	dest[1][1] = mat[1][1];
	dest[1][2] = mat[2][1];
	dest[1][3] = mat[3][1];
	dest[2][0] = mat[0][2];
	dest[2][1] = mat[1][2];
	dest[2][2] = mat[2][2];
	dest[2][3] = mat[3][2];
	dest[3][0] = mat[0][3];
	dest[3][1] = mat[1][3];
	dest[3][2] = mat[2][3];
	dest[3][3] = mat[3][3];
}

inline void zinc_mat4_transpose(Mat4 mat)
{
	const f32 mat00 = mat[0][0], mat01 = mat[0][1], mat02 = mat[0][2], mat03 = mat[0][3], 
		      mat10 = mat[1][0], mat11 = mat[1][1], mat12 = mat[1][2], mat13 = mat[1][3], 
		      mat20 = mat[2][0], mat21 = mat[2][1], mat22 = mat[2][2], mat23 = mat[2][3], 
		      mat30 = mat[3][0], mat31 = mat[3][1], mat32 = mat[3][2], mat33 = mat[3][3]; 

	mat[0][0] = mat00;
	mat[0][1] = mat10;
	mat[0][2] = mat20;
	mat[0][3] = mat30;
	mat[1][0] = mat01;
	mat[1][1] = mat11;
	mat[1][2] = mat21;
	mat[1][3] = mat31;
	mat[2][0] = mat02;
	mat[2][1] = mat12;
	mat[2][2] = mat22;
	mat[2][3] = mat32;
	mat[3][0] = mat03;
	mat[3][1] = mat13;
	mat[3][2] = mat23;
	mat[3][3] = mat33;
}

inline f32 zinc_mat4_determinant(const Mat4 mat)
{
	float det = 0;

	det = mat[0][0] * (mat[1][1] * (mat[2][2] * mat[3][3] - mat[3][2] * mat[2][3]) -
					   mat[2][1] * (mat[1][2] * mat[3][3] - mat[3][2] * mat[1][3]) +
					   mat[3][1] * (mat[1][2] * mat[2][3] - mat[2][2] * mat[1][3]));

	det -= mat[1][0] * (mat[0][1] * (mat[2][2] * mat[3][3] - mat[3][2] * mat[2][3]) -
						mat[2][1] * (mat[0][2] * mat[3][3] - mat[3][2] * mat[0][3]) +
						mat[3][1] * (mat[0][2] * mat[2][3] - mat[2][2] * mat[0][3]));

	det += mat[2][0] * (mat[0][1] * (mat[1][2] * mat[3][3] - mat[3][2] * mat[1][3]) -
						mat[1][1] * (mat[0][2] * mat[3][3] - mat[3][2] * mat[0][3]) +
						mat[3][1] * (mat[0][2] * mat[1][3] - mat[1][2] * mat[0][3]));

	det -= mat[3][0] * (mat[0][1] * (mat[1][2] * mat[2][3] - mat[2][2] * mat[1][3]) -
						mat[1][1] * (mat[0][2] * mat[2][3] - mat[2][2] * mat[0][3]) +
						mat[2][1] * (mat[0][2] * mat[1][3] - mat[1][2] * mat[0][3]));

	return det;
}

inline f32 zinc_mat4_trace(const Mat4 mat)
{
	return mat[0][0] + mat[1][1] + mat[2][2] + mat[3][3];
}
