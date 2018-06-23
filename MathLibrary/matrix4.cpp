#include "matrix4.h"
#include <math.h>


vector4 matrix4::operator*(vector4 input_matrix)
{
	vector4 result;

	result.value[0] = input_matrix.value[0] * value[0][0] + input_matrix.value[1] * value[0][1]
					+ input_matrix.value[2] * value[0][2] + input_matrix.value[3] * value[0][3];

	result.value[1] = input_matrix.value[0] * value[1][0] + input_matrix.value[1] * value[1][1]
					+ input_matrix.value[2] * value[1][2] + input_matrix.value[3] * value[1][3];

	result.value[2] = input_matrix.value[0] * value[2][0] + input_matrix.value[1] * value[2][1]
					+ input_matrix.value[2] * value[2][2] + input_matrix.value[3] * value[2][3];

	result.value[3] = input_matrix.value[0] * value[3][0] + input_matrix.value[1] * value[3][1]
					+ input_matrix.value[2] * value[3][2] + input_matrix.value[3] * value[3][3];

	return result;
}


matrix4 matrix4::operator*(matrix4 input_matrix)
{
	matrix4 result;

	const int number_of_rows = 4; // and rows of given matrix. in this case, they will be always 3 * 3.
	const int number_of_columns = 4; // variables for describe number of columns


	int i = 0, j = 0, k = 0; //variable for loop index.

	while (i < number_of_columns)
	{


		while (j < number_of_rows)
		{


			while (k < number_of_columns)
			{
				result.value[i][j] += value[i][k] * input_matrix.value[k][j];



				k++;
			}
			k = 0;


			j++;
		}
		j = 0;


		i++;
	}


	//return result of multiplying of two affine matries.
	return result;
}


matrix4& matrix4::operator*=(matrix4 input_matrix)
{
	*this = *this * input_matrix;
	return *this;
}


matrix4 matrix4::Build_translation(vector3 input)
{
	matrix4 result = matrix4::Build_identity();

	result.value[0][3] = input.x;
	result.value[1][3] = input.y;
	result.value[2][3] = input.z;
	result.value[3][3] = 1.0f;


	return result;
}

matrix4 matrix4::Build_rotation(float input_radian, Axis axis)
{
	matrix4 result = matrix4::Build_identity();

	result.value[3][3] = 1.0f;

	const auto cosine = std::cosf(input_radian);
	const auto sine	  = std::sinf(input_radian);

	switch (axis)
	{
	case X:
		result.value[1][1] = cosine;
		result.value[1][2] = -sine;
		result.value[2][1] = sine;
		result.value[2][2] = cosine;
		break;
	case Y:
		result.value[0][0] = cosine;
		result.value[0][3] = sine;
		result.value[2][0] = -sine;
		result.value[2][3] = cosine;
		break;
	case Z:
		result.value[0][0] = cosine;
		result.value[0][1] = -sine;
		result.value[1][0] = sine;
		result.value[1][1] = cosine;
		break;
	}


	return result;
}

matrix4 matrix4::Build_scale(float input_factor)
{
	matrix4 result = { 0, };

	result.value[0][0] = input_factor;
	result.value[1][1] = input_factor;
	result.value[2][2] = input_factor;
	result.value[3][3] = 1.0f;

	return result;
}

matrix4 matrix4::Build_scale(vector2 input_factor)
{
	matrix4 result = { 0, };

	result.value[0][0] = input_factor.x;
	result.value[1][1] = input_factor.y;
	result.value[2][2] = 1.0f;
	result.value[3][3] = 1.0f;

	return result;
}


matrix4 matrix4::Build_identity()
{
	matrix4 result = { 0, };

	result.value[0][0] = 1.0f;
	result.value[1][1] = 1.0f;
	result.value[2][2] = 1.0f;
	result.value[3][3] = 1.0f;

	return result;
}