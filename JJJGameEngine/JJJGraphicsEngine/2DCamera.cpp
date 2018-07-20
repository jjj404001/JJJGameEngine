#include "2DCamera.h"

void TwoDimensionalCamera::Initialize(long res_x, long res_y)
{
	proj_ = Affine2d::build_scale(zoom_ * 2 / res_x, zoom_ * 2 / res_y);
	view_  = Affine2d::build_identity();
	world_ = Affine2d::build_identity();

	right_.x = res_x;
	up_.y = res_y;

	// rotation.
	view_.value[0][0] = right_.x;
	view_.value[0][1] = right_.y;
	view_.value[1][0] = up_.x;
	view_.value[1][1] = up_.y;
	// translation to opposite direction, to make it to 0.
	view_.value[0][2] = right_ * -center_;
	view_.value[1][2] = up_    * -center_;
	
	view_ *= Affine2d::build_rotation(rotation_);
}

void TwoDimensionalCamera::SetWorld(Affine2d Translation, Affine2d Rotation, Affine2d Scale)
{
	world_ = Translation * Rotation * Scale;
}

Affine2d TwoDimensionalCamera::CombindMatrix()
{
	return (proj_ * view_ * world_);
}
