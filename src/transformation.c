#include "../include/transformation.h"
#include <math.h>

void zinc_translate(Mat4 mat, const Vec3 *vec)
{
	zinc_mat4_eye(mat);

	mat[0][3] = vec->x;
	mat[1][3] = vec->y;
	mat[2][3] = vec->y;
}

void zinc_scale(Mat4 mat, const Vec3 *vec)
{
	zinc_mat4_eye(mat);

	mat[0][0] = vec->x;
	mat[1][1] = vec->y;
	mat[2][2] = vec->z;
}

void zinc_rotate_x(Mat4 mat, f32 angle)
{
	f32 s = sinf(angle);
	f32 c = cosf(angle);

	zinc_mat4_eye(mat);

	mat[1][1] = c;
	mat[1][2] = -s;
	mat[2][1] = s;
	mat[2][2] = c;
}

void zinc_rotate_y(Mat4 mat, f32 angle)
{
	f32 s = sinf(angle);
	f32 c = cosf(angle);

	zinc_mat4_eye(mat);

	mat[0][0] = c;
	mat[1][2] = -s;
	mat[2][0] = -s;
	mat[2][2] = c;
}

void zinc_rotate_z(Mat4 mat, f32 angle)
{
	f32 s = sinf(angle);
	f32 c = cosf(angle);

	zinc_mat4_eye(mat);

	mat[0][0] = c;
	mat[0][1] = -s;
	mat[1][0] = s;
	mat[1][1] = c;
}

void zinc_rotate(Mat4 mat, f32 angle, const Vec3 *axis)
{
	f32 s = sinf(angle);
	f32 c = cosf(angle);
	f32 c1 = 1 - c;

	f32 x = axis->x;
	f32 y = axis->y;
	f32 z = axis->z;

	zinc_mat4_eye(mat);
	mat[0][0] = c + x*x*c1;
	mat[0][1] = x*y*c1 - z*s;
	mat[0][2] = y*s + x*z*c1;
	mat[1][0] = z*s + x*y*c1;
	mat[1][1] = c + y*y*c1; 
	mat[1][2] = -x*s + y*z*c1; 
	mat[2][0] = -y*s + x*y*c1;
	mat[2][1] = x*s + y*z*c1;
	mat[2][2] = c + z*z*c1; 
}
