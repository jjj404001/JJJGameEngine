/******************************************************************************/
/*!
file name : Affine3d.cpp
author    : Jaejun Jang
email     : jjj404001@gmail.com


DigiPen login     : jaejun.jang
Course name       : CS230
Assignment number :#1

term   :Spring 2018
brief  :
This file contains the function using for calculating with affine matrix.

Functions include:
in Affine3d struct :
+ float& operator()(int column,int row);         //()operator overloading for accessing 2*2 matrix.
+ float  operator()(int column,int row) const;   //same with above but using const parameter.
+ Affine3d operator*(Affine3d InputAffine) const;//  *operator overloading for multiplying affine matrix with affine matrix.
+ Affine3d& operator*=(Affine3d InputAffine);    //  *= operator overloading for multyplying affine matrix with affine matrix.
+ Affine3d& transpose(void);                     // transpose given affine matrix.

non-member normal function :
+ Affine3d Build_rotation(float degree);                           // build rotation affine matrix with given degree.
+ Affine3d Build_identity(void);                               // build identity matrix.
+ Affine3d build_scale(float scaleFactor);                     // build uniform affine sacle matrix.
+ Affine3d build_scale(float scaleFactor1, float scaleFactor2);// build non uniform affine sacle matrix.
+ Affine3d build_translation(float Xposition, float Yposition);// build translation affine matrix with given number.

*/
/******************************************************************************/
#include "Affine3d.h"
#include <cmath> 
#include <cassert>
#include "Vector3.hpp"
#include "Vector2.hpp"


//()operator overloading for accessing affine 2d.
float& Affine3d::operator()(const int column, const int row)
{
	assert("Out of index." && column <= 3 && row <= 3 && column >= 0 && row >= 0);
	//return element of affine matrix.
	return value[column][row];
}

const float& Affine3d::operator()(const int column, const int row) const//same with above but using const parameter.
{
	assert("Out of index." && column <= 3 && row <= 3 && column >= 0 && row >= 0);
	//return element of affine matrix.
	return value[column][row];
}

float* Affine3d::operator[](const int column)
{
	assert("Out of index." && column <= 3 && column >= 0);
	return value[column];
}

const float* Affine3d::operator[](const int column) const
{
	assert("Out of index." && column <= 3 && column >= 0);
	return value[column];
}

Affine3d Affine3d::operator+(const Affine3d input_affine) const
{
	Affine3d result;

	result.value[0][0] = value[0][0] + input_affine[0][0];
	result.value[0][1] = value[0][1] + input_affine[0][1];
	result.value[0][2] = value[0][2] + input_affine[0][2];
	result.value[1][0] = value[1][0] + input_affine[1][0];
	result.value[1][1] = value[1][1] + input_affine[1][1];
	result.value[1][2] = value[1][2] + input_affine[1][2];
	result.value[2][0] = value[2][0] + input_affine[2][0];
	result.value[2][1] = value[2][1] + input_affine[2][1];
	result.value[2][2] = value[2][2] + input_affine[2][2];

	return result;
}

Affine3d& Affine3d::operator+=(const Affine3d input_affine)
{
	Affine3d result(*this + input_affine);

	*this = result;

	return *this;
}


//  *operator overloading for multiplying affine matrix with affine matrix.
Affine3d Affine3d::operator*(Affine3d input_affine) const
{
	Affine3d result; //variable for calculated affine matrix.



	auto i = 0, j = 0, k = 0; //variable for loop index.

	while (i < AFFINE3D_DIMENSION)
	{

		while (j < AFFINE3D_DIMENSION)
		{


			while (k < AFFINE3D_DIMENSION)
			{
				result(i, j) += value[i][k] * input_affine(k, j);



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

//  *=operator overloading for multiplying affine matrix with affine matrix.
Affine3d& Affine3d::operator*=(Affine3d input_affine)
{
	*this = *this * input_affine;
	return *this;
}

Vector4 Affine3d::operator*(const Vector4 input_affine) const
{
	const auto _x = (value[0][0] * input_affine.value[0] + value[1][0] * input_affine.value[1]
			       + value[2][0] * input_affine.value[2] + value[3][0] * input_affine.value[3]);

	const auto _y = (value[0][1] * input_affine.value[0] + value[1][1] * input_affine.value[1]
				   + value[2][1] * input_affine.value[2] + value[3][1] * input_affine.value[3]);

	const auto _z = (value[0][2] * input_affine.value[0] + value[1][2] * input_affine.value[1]
			   	   + value[2][2] * input_affine.value[2] + value[3][2] * input_affine.value[3]);

	const auto _w = (value[0][3] * input_affine.value[0] + value[1][3] * input_affine.value[1]
				   + value[2][3] * input_affine.value[2] + value[3][3] * input_affine.value[3]);
	return Vector4(_x, _y, _z, _w);
}


//function for transpose affine matrix.
Affine3d& Affine3d::transpose()
{
	float temporary_memory; //variable for memory original affine matrix


	for (auto loop_index = 1; loop_index < AFFINE3D_DIMENSION; ++loop_index)
	{
		temporary_memory = value[0][loop_index];

		value[0][loop_index] = value[loop_index][0];
		value[loop_index][0] = temporary_memory;
	}

	//handling exception
	temporary_memory = value[1][2];

	value[1][2] = value[2][1];
	value[2][1] = temporary_memory;



	//return transposed affine matrix.
	return *this;
}

//https://1drv.ms/f/s!AtYPT4LaIMURjEXnU7qVazIv8u1u
Affine3d Affine3d::build_rotation(float degree, Math::Axis axis)
{
	const Vector2 u = { std::cos(degree),  -std::sin(degree)};
	const Vector2 v = { std::sin(degree), std::cos(degree)};

	Affine3d rotation_matrix = build_identity();

	if(axis == Math::Axis::X)
	{
		rotation_matrix[1][1] = u.x;
		rotation_matrix[1][2] = u.y;
		rotation_matrix[2][1] = v.x;
		rotation_matrix[2][2] = v.y;
	}
	else if (axis == Math::Axis::Y)
	{
		rotation_matrix[0][0] = u.x;
		rotation_matrix[0][2] = u.y;
		rotation_matrix[2][0] = v.x;
		rotation_matrix[2][2] = v.y;
	}
	else if (axis == Math::Axis::Z)
	{
		rotation_matrix[0][0] = u.x;
		rotation_matrix[0][1] = u.y;
		rotation_matrix[1][0] = v.x;
		rotation_matrix[1][1] = v.y;
	}

	return rotation_matrix;
}


Affine3d Affine3d::build_identity()
{
	Affine3d identity;


	for (auto loop_index1 = 0; loop_index1 < AFFINE3D_DIMENSION; ++loop_index1)
	{
		for (auto loop_index2 = 0; loop_index2 < AFFINE3D_DIMENSION; ++loop_index2)
		{
			if (loop_index1 == loop_index2)
			{
				identity(loop_index1, loop_index2) = 1.0f;
			}
			else
			{
				identity(loop_index1, loop_index2) = 0.0f;
			}
		}
	}

	//return builded identity matrix.
	return identity;
}

Affine3d Affine3d::build_scale(float scale_factor)
{
	Affine3d scale;


	for (auto loop_index1 = 0; loop_index1 < AFFINE3D_DIMENSION; ++loop_index1)
	{
		for (auto loop_index2 = 0; loop_index2 < AFFINE3D_DIMENSION; ++loop_index2)
		{
			if (loop_index1 == loop_index2)
			{
				scale(loop_index1, loop_index2) = scale_factor;
			}
			else
			{
				scale(loop_index1, loop_index2) = 0.0f;
			}
		}
	}

	//manualy put value in last element of affine matrix.
	scale(2, 2) = 1.0;


	//return builded affine scale matrix
	return scale;
}

Affine3d Affine3d::build_scale(float scale_factor1, float scale_factor2)
{
	auto scale = build_identity();



	//manually build scale matrix.
	scale(0, 0) = scale_factor1;
	scale(1, 1) = scale_factor2;
	scale(2, 2) = 1.0f;



	//return builded scale matrix.
	return scale;
}

Affine3d Affine3d::build_scale(const float scale_factor1, const float scale_factor2, const float scale_factor3)
{
	auto scale = build_identity();



	//manually build scale matrix.
	scale(0, 0) = scale_factor1;
	scale(1, 1) = scale_factor2;
	scale(2, 2) = scale_factor3;



	//return builded scale matrix.
	return scale;
}

Affine3d Affine3d::build_translation(const float xposition, const float yposition, const float zposition)
{
	auto translation = build_identity(); //initialize translatino matrix with identity matrix.

	translation[0][2] = xposition;
	translation[1][2] = yposition;
	translation[2][2] = zposition;


	//return builded translation matrix.
	return translation;
}

std::ostream& operator<<(std::ostream& input_ostream, Affine3d input_affine)
{
	input_ostream << "[";
	input_ostream << input_affine[0][0] << ",";
	input_ostream << input_affine[0][1] << ",";
	input_ostream << input_affine[0][1] << "]" << std::endl;

	input_ostream << "[";
	input_ostream << input_affine[1][0] << ",";
	input_ostream << input_affine[1][1] << ",";
	input_ostream << input_affine[1][2] << "]" << std::endl;

	input_ostream << "[";
	input_ostream << input_affine[2][0] << ",";
	input_ostream << input_affine[2][1] << ",";
	input_ostream << input_affine[2][2] << "]" << std::endl;

	return input_ostream;
}
