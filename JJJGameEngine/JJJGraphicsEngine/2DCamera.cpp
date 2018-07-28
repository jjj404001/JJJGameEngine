#include "2DCamera.h"

void TwoDimensionalCamera::Initialize(long res_x, long res_y)
{
	proj_ = Affine3d::build_scale(zoom_ * 2 / res_x, zoom_ * 2 / res_y, -2.0f / (far_ - near_));
	view_  = Affine3d::build_identity();
	world_ = Affine3d::build_identity();

	right_.x = static_cast<float>(res_x);
	up_.y    = static_cast<float>(res_y);

	// rotation.
	//view_.value[0][0] = right_.x;
	//view_.value[0][1] = right_.y;
	//view_.value[1][0] = up_.x;
	//view_.value[1][1] = up_.y;
	// translation to opposite direction, to make it to 0.
	view_.value[0][3] = right_ * -center_;
	view_.value[1][3] = up_    * -center_;
	
	view_ *= Affine3d::build_rotation(rotation_);
}