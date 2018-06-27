#include "Affine2d.hpp"
#include <iostream>
#include "Vector2.hpp"
#include  "Quaternion.h"


#include <OpenGL_functions.h>
int main()
{
	Quaternion q1 = Quaternion(Vector3(0.0f, 1.0f, 0.0f), 90);
	Quaternion q2 = Quaternion(Vector3(1.0f, 0.0f, 0.0f), 45);
	Quaternion q3 = q2 * q1;

	Vector3 vecRot = q3 * Vector3(1, 0, 0);

	std::cout << "q1   (" << q1.w << ", " << q1.x << ", " << q1.y << ", "<< q1.z << ")" << std::endl;
	std::cout << "q2   (" << q2.w << ", " << q2.x << ", " << q2.y << ", "<< q2.z << ")" << std::endl;
	std::cout << "q3   (" << q3.w << ", " << q3.x << ", " << q3.y << ", "<< q3.z << ")" << std::endl;

	return 0;
}
