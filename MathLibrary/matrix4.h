#pragma once
#include "vector2.hpp"
#include "vector3.hpp"
#include "vector4.h"

enum Axis
{
	X,
	Y,
	Z
};
struct matrix4
{
	float value[4][4] = {};


	vector4 operator*(vector4 input_matrix); //multiplication with vector4.


	matrix4 operator*(matrix4 input_matrix); //multiplication with vector4.
	matrix4& operator*=(matrix4 input_matrix); //multiplication with vector4.

	static matrix4 Build_translation(vector3 input);
	static matrix4 Build_rotation(float input_radian, Axis axis = Z);
	static matrix4 Build_scale(float input_factor);
	static matrix4 Build_scale(vector2 input_factor);
	static matrix4 Build_identity();
};