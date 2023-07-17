#include <stdio.h>
#include "../include/io.h"

void zinc_vec2_print(const Vec2 *vec)
{
	printf("(%f, %f)\n", vec->x, vec->y);
}

void zinc_vec2i_print(const Vec2i *vec)
{
	printf("(%d, %d)\n", vec->x, vec->y);
}

void zinc_vec3_print(const Vec3 *vec)
{
	printf("(%f, %f, %f)\n", vec->x, vec->y, vec->z);
}

void zinc_vec3i_print(const Vec3i *vec)
{
	printf("(%d, %d, %d)\n", vec->x, vec->y, vec->z);
}

void zinc_vec4_print(const Vec4 *vec)
{
	printf("(%f, %f, %f, %f)\n", vec->x, vec->y, vec->z, vec->w);
}

void zinc_vec4i_print(const Vec4i *vec)
{
	printf("(%d, %d, %d, %d)\n", vec->x, vec->y, vec->z, vec->w);
}

void zinc_mat2_print(const Mat2 mat)
{
	printf("\n");
	for(u8 i = 0; i < 2; i++){
		printf("|%11.5f, %11.5f|\n", mat[i][0], mat[i][1]);
	}
}

void zinc_mat3_print(const Mat3 mat)
{
	printf("\n");
	for(u8 i = 0; i < 3; i++){
		printf("|%11.5f, %11.5f, %11.5f|\n", mat[i][0], mat[i][1], mat[i][2]);
	}
}

void zinc_mat4_print(const Mat4 mat)
{
	printf("\n");
	for(u8 i = 0; i < 4; i++){
		printf("|%11.5f, %11.5f, %11.5f, %11.5f|\n", mat[i][0], mat[i][1], mat[i][2], mat[i][3]);
	}
}
