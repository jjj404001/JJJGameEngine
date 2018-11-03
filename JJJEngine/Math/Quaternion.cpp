#include "Quaternion.h"

Quaternion Quaternion::Conjugate()
{
	return {w, -x, -y, -z};
}
float Quaternion::Norm()
{
	return sqrt(w * w + x * x + y * y + z * z);
}

Quaternion Quaternion::operator*(Quaternion input)
{
	const auto result_w = (w * input.w) - (vector() * input.vector());
	const auto cross    = Vector3::cross(vector(), input.vector());
	const Vector3 result_v((input.vector() * w) + (vector() * input.w) + cross);

	return { result_w, result_v.x, result_v.y, result_v.z};
}

Vector3 Quaternion::operator*(Vector3 input)
{
	Quaternion temp(input, 0.0f);
	Vector3 result = Vector3::cross(vector(), input);
	

	return input + (result * (2 * w)) + (Vector3::cross(vector(), result) * 2);
}

Vector3 Quaternion::vector()
{
	return {value[1], value[2], value[3]};
}

Quaternion Quaternion::Identity()
{
	return {1.0f, 0.0f, 0.0f, 0.0f};
}

Affine3d Quaternion::ToAffine3d()
{
	return Affine3d(1 - (2 * y * y) - (2 * z * z), (2 * x * y) - (2 * w * z), (2 * x * z) + (2 * w * y), 0.0f,
					(2 * x * y) + (2 * w * z), 1 - (2 * x * x) - (2 * z * z), (2 * y * z) - (2 * w * x), 0.0f,
					(2 * x * z) + (2 * w * y), (2 * y * z) + (2 * w * x), 1 - (2 * x * x) - (2 * y * y), 0.0f,
					0.0f, 0.0f, 0.0f, 1.0f);
}

Quaternion Quaternion::Inverse()
{
	auto conjugate = this->Conjugate();


	return conjugate / (w * w + x * x + y * y + z * z);
}

template <typename Number>
Quaternion Quaternion::operator/(Number input)
{
	const Quaternion result = { w / input, x / input, y / input, z / input };
	return result;
}
