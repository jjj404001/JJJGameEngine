#pragma once
#include "Camera.h"

class TwoDimensionalCamera : public Camera
{
	float rotation_ = 0.0f;

	Vector3 right_;
	Vector3 up_;


public:
	float distance = 0.1f;
	void Initialize(long res_x, long res_y);
};