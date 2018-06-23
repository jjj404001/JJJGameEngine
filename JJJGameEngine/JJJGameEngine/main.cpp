#include "Affine2d.hpp"
#include <iostream>
#include "Vector2.hpp"

int main()
{
	Affine2d zero = Affine2d::build_identity();

	std::cout << zero << std::endl;

	Vector2 v = { 99, 98 };

	std::cout << v.x << std::endl;
	std::cout << v.y << std::endl;

	Vector2 j = { 1, 1 };

	std::cout << j.magnitude() << std::endl;

	return 0;
}
