#include "3DCamera.h"
#include "../GLMtest/glm/glm.hpp"
#include "../GLMtest/glm/gtc/matrix_transform.hpp"

void ThreeDimensionalCamera::Initialize(long res_x, long res_y)
{
	glm::mat4 proj__;
	proj__ = glm::perspective(glm::radians(45.0f), (float)res_x / (float)res_y, 0.1f, 100.0f);

	view_ = Affine3d::build_identity();
	world_ = Affine3d::build_identity();

	right_.x = static_cast<float>(res_x);
	up_.y = static_cast<float>(res_y);



	proj_.value[0][0] = proj__[0][0];
	proj_.value[0][1] = proj__[0][1];
	proj_.value[0][2] = proj__[0][2];
	proj_.value[0][3] = proj__[0][3];

	proj_.value[1][0] = proj__[1][0];
	proj_.value[1][1] = proj__[1][1];
	proj_.value[1][2] = proj__[1][2];
	proj_.value[1][3] = proj__[1][3];

	proj_.value[2][0] = proj__[2][0];
	proj_.value[2][1] = proj__[2][1];
	proj_.value[2][2] = proj__[2][2];
	proj_.value[2][3] = proj__[2][3];

	proj_.value[3][0] = proj__[3][0];
	proj_.value[3][1] = proj__[3][1];
	proj_.value[3][2] = proj__[3][2];
	proj_.value[3][3] = proj__[3][3];



	//view_ = Affine3d::build_scale(zoom_, zoom_ , zoom_);

	//right_.x = static_cast<float>(res_x);
	//up_.y = static_cast<float>(res_y);

	//// rotation.
	//view_.value[0][0] = right_.x;
	//view_.value[0][1] = right_.y;
	//view_.value[1][0] = up_.x;
	//view_.value[1][1] = up_.y;
	//// translation to opposite direction, to make it to 0.
	//view_.value[0][2] = right_ * -center_;
	//view_.value[1][2] = up_ * -center_;

	//view_ *= Affine3d::build_rotation(rotation_);
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
