#include "../include/camera.h"
#include <math.h>

void zinc_view_matrix(Mat4 mat, const Vec3 *pos, const Vec3 *right, const Vec3 *up, const Vec3 *forward)
{
	mat[0][0] = right->arr[0];
	mat[0][1] = right->arr[1];
	mat[0][2] = right->arr[2];
	mat[0][3] = -zinc_vec3_dot(pos, right);

	mat[1][0] = up->arr[0];
	mat[1][1] = up->arr[1];
	mat[1][2] = up->arr[2];
	mat[1][3] = -zinc_vec3_dot(pos, up);

	mat[2][0] = forward->arr[0];
	mat[2][1] = forward->arr[1];
	mat[2][2] = forward->arr[2];
	mat[2][3] = -zinc_vec3_dot(pos, forward);

	mat[3][0] = 0;
	mat[3][1] = 0;
	mat[3][2] = 0;
	mat[3][3] = 1;
}

void zinc_orthographic_projection(Mat4 mat, f32 far, f32 near, f32 top, f32 bottom, f32 right, f32 left)
{
	zinc_mat4_eye(mat);

	mat[0][0] = 2.0f / (right - left);
	mat[0][3] = -(right + left) / (right - left);

	mat[1][1] = 2.0f / (top - bottom);
	mat[1][3] = -(top + bottom) / (top - bottom);

	mat[2][2] = 2.0f / (far - near);
	mat[2][3] = -(far + near) / (far - near);
}

void zinc_persective_projection(Mat4 mat, f32 far, f32 near, f32 fov, f32 aspect_ratio)
{
	f32 t = tanf(fov/2.0f);

	zinc_mat4_zero(mat);
	mat[0][0] = 1.0f/aspect_ratio*t;
	mat[1][1] = 1.0f/t;
	mat[2][2] = (far + near)/(far - near); 
	mat[2][3] = -2.0f*far*near/(far - near); 
	mat[3][2] = 1.0f;
}
