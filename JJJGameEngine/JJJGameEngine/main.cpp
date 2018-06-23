#include "Affine2d.hpp"
#include <iostream>

int main()
{
	Affine2d zero = Affine2d::build_identity();

	std::cout << zero << std::endl;


	return 0;
}
