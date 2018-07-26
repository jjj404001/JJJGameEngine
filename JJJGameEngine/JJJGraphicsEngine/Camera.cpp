#include "Camera.h"

void Camera::SetWorld(Affine2d Translation, Affine2d Rotation, Affine2d Scale)
{
	const auto combind_affine = Translation * Rotation * Scale;


	world_ = Affine3d::build_identity();
	world_.value[0][0] = combind_affine.value[0][0];
	world_.value[0][1] = combind_affine.value[0][1];
	world_.value[0][2] = combind_affine.value[0][2];
	world_.value[1][0] = combind_affine.value[1][0];
	world_.value[1][1] = combind_affine.value[1][1];
	world_.value[1][2] = combind_affine.value[1][2];
	world_.value[2][0] = combind_affine.value[2][0];
	world_.value[2][1] = combind_affine.value[2][1];
	world_.value[2][2] = combind_affine.value[2][2];
}

void Camera::SetWorld(Affine3d Translation, Affine3d Rotation, Affine3d Scale)
{
	const auto combind_affine = Translation * Rotation * Scale;


	world_ = Affine3d::build_identity();
	world_.value[0][0] = combind_affine.value[0][0];
	world_.value[0][1] = combind_affine.value[0][1];
	world_.value[0][2] = combind_affine.value[0][2];
	world_.value[0][3] = combind_affine.value[0][3];
	world_.value[1][0] = combind_affine.value[1][0];
	world_.value[1][1] = combind_affine.value[1][1];
	world_.value[1][2] = combind_affine.value[1][2];
	world_.value[1][3] = combind_affine.value[1][3];
	world_.value[2][0] = combind_affine.value[2][0];
	world_.value[2][1] = combind_affine.value[2][1];
	world_.value[2][2] = combind_affine.value[2][2];
	world_.value[2][3] = combind_affine.value[2][3];
	world_.value[3][0] = combind_affine.value[3][0];
	world_.value[3][1] = combind_affine.value[3][1];
	world_.value[3][2] = combind_affine.value[3][2];
	world_.value[3][3] = combind_affine.value[3][3];
}



Affine3d Camera::CombindMatrix()
{
	return (proj_ * view_ * world_);
}
