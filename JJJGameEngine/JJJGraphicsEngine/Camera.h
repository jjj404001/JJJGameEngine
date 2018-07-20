#pragma once
#include "Vector2.hpp"
#include "Affine2d.hpp"
#include "Quaternion.h"

#define X_AXIS Vector3(1.f, 0.f, 0.f)
#define Y_AXIS Vector3(0.f, 1.f, 0.f)
#define Z_AXIS Vector3(0.f, 0.f, 1.f)



class Camera
{
	struct ThreeDimensional
	{
		Vector3 centerPosition = Vector3(0.f, 0.f, -1.f);  // world space coordinates.
		Vector3 eyePosition = Vector3(0.f, 0.f, 0.f);      // world space coordinates.

																	  // Orientation of camera axes.
		Quaternion orientation = Quaternion(0.f, 0.f, 0.f, 1.f); // Identity.

																		 // Standard reference axes.


		Vector3 left = Vector3(-1.f, 0.f, 0.f);  // left local camera vector.
		Vector3 forward = Vector3(0.f, 0.f, -1.f);  // forward local camera vector.
		Vector3 up = Vector3(0.f, 1.f, 0.f);   // up local camera vector.
	};

	
public:
	virtual void Initialize(long res_x, long res_y) = 0;
};
