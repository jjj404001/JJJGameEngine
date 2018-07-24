#pragma once
#include <cmath>

namespace Math
{
	enum Axis
	{
		X,
		Y,
		Z
	};


	const float PI = 4.0f * std::atan(1.0f);
	const auto  RADIAN = 180.0f / PI;

	template<typename Number>
	Number ToRadian(Number input) { return input * (PI / 180); };
}