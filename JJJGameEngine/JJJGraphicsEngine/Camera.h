#pragma once
#include "Vector2.hpp"
#include "Affine2d.hpp"
#include "Quaternion.h"

#define X_AXIS Vector3(1.f, 0.f, 0.f)
#define Y_AXIS Vector3(0.f, 1.f, 0.f)
#define Z_AXIS Vector3(0.f, 0.f, 1.f)



class Camera
{
	friend class TwoDimensionalCamera;
	friend class ThreeDimensionalCamera;

	Affine3d proj_;
	Affine3d view_;
	Affine3d world_;

	

	float near_ = .1f;
	float far_ = 1000.f;

public:
	Vector3 center_ = Vector3(0.f, 0.f, 0.f);
	float zoom_ = 1.0f;

	virtual void Initialize(long res_x, long res_y) = 0;
	Affine3d CombindMatrix();
	void SetWorld(Affine2d Translation, Affine2d Rotation, Affine2d Scale);
};
