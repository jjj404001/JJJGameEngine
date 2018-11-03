// Author : Jaejun Jang
// Date   : 2018 06 26
// Quaternion struct for using in math library.
#pragma once
#include "Vector3.hpp"
#include "Constant.h"
#include "Affine3d.h"

struct Quaternion
{
	float value[4] = { 0, };

	const float& w = value[0];
	const float& x = value[1];
	const float& y = value[2];
	const float& z = value[3];


	Quaternion(Vector3 normalized_rotation_axis, float rotation_angle)
		: value{ cosf(rotation_angle * 1 / Math::RADIAN / 2),
				 normalized_rotation_axis.value[0] * sinf(rotation_angle * 1 / Math::RADIAN / 2),
				 normalized_rotation_axis.value[1] * sinf(rotation_angle * 1 / Math::RADIAN / 2),
				 normalized_rotation_axis.value[2] * sinf(rotation_angle * 1 / Math::RADIAN / 2) }
	{}

	/*Quaternion(float normalized_x, float normalized_y, float normalized_z, float rotation_angle)
		: value{ cosf(rotation_angle * Math::RADIAN / 2),
				 normalized_x * sinf(rotation_angle * Math::RADIAN / 2),
				 normalized_y * sinf(rotation_angle * Math::RADIAN / 2),
				 normalized_z * sinf(rotation_angle * Math::RADIAN / 2) }
	{}*/

	Quaternion(float normalized_w, float normalized_x, float normalized_y, float normalized_z)
		: value{ normalized_w, normalized_x , normalized_y , normalized_z  }
	{}


	Quaternion Conjugate();
	float Norm(); //or lenght?
	Quaternion Inverse();

	template<typename Number>
	Quaternion operator/(Number input);

	Quaternion operator*(Quaternion input);
	Vector3 operator*(Vector3 input);

	Vector3 vector();

	static Quaternion Identity();
	Affine3d ToAffine3d();
	// TODO: Interpolation
};
