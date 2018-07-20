#pragma once
#include "Camera.h"

class TwoDimensionalCamera : public Camera
{
	float zoom_;

	float rotation_;

	Vector2 right_;
	Vector2 up_;

	Vector2 center_;

	Affine2d proj_;
	Affine2d view_;
	Affine2d world_;

public:
	void Initialize(long res_x, long res_y);

	void SetWorld(Affine2d Translation, Affine2d Rotation, Affine2d Scale);

	Affine2d CombindMatrix();
};