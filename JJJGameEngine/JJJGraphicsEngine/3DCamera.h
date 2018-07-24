#pragma once
#include "Camera.h"
class ThreeDimensionalCamera : public Camera
{
	float fov_ = 70.f;
	

	float rotation_ = 0.0f;


	Vector3 centerPosition_ = Vector3(0.f, 0.f, -1.f);  // world space coordinates.
	Vector3 eyePosition_ = Vector3(0.f, 0.f, 0.f);      // world space coordinates.

	Quaternion orientation_ = Quaternion(0.f, 0.f, 0.f, 1.f); // Identity.

															 // Standard reference axes.


	Vector3 left_ = Vector3(-1.f, 0.f, 0.f);  // left local camera vector.
	Vector3 right_ = Vector3(1.f, 0.f, 0.f);  // left local camera vector.
	Vector3 forward_ = Vector3(0.f, 0.f, -1.f);  // forward local camera vector.
	Vector3 up_ = Vector3(0.f, 1.f, 0.f);   // up local camera vector.

public:
	void Initialize(long res_x, long res_y);

	Affine3d perspective(float fovy, float aspect, float zNear, float zFar);
};