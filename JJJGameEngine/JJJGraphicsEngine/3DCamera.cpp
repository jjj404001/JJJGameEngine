#include "3DCamera.h"

void ThreeDimensionalCamera::Initialize(long res_x, long res_y)
{

}

Affine3d ThreeDimensionalCamera::perspective(float fovy, float aspect, float zNear, float zFar)
{
	float const tanHalfFovy = tan(fovy / 2.0f);

	Affine3d Result = Affine3d::build_identity();
	Result[0][0] = (1.0f) / (aspect * tanHalfFovy);
	Result[1][1] = (1.0f) / (tanHalfFovy);
	Result[2][2] = -(zFar + zNear) / (zFar - zNear);
	Result[2][3] = -(1.0f);
	Result[3][2] = -(2.0f * zFar * zNear) / (zFar - zNear);
	return Result;
}
