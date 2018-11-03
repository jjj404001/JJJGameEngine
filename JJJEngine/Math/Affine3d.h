/******************************************************************************/
/*!
file name : Affine3d.hpp
author    : Jaejun Jang
email     : jjj404001@gmail.com


DigiPen login     : jaejun.jang
Course name       : CS230
Assignment number :#1

term   :Spring 2018
brief  :
This file contains the function prototypes and Affine3d struct using for calculating with affine matrix.

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
+ Affine3d build_affine_translation(float Xposition, float Yposition);// build translation affine matrix with given number.

*/
/******************************************************************************/
#pragma once
#include <ostream>
#include "Vector4.h"
#include "Constant.h"
#define AFFINE3D_DIMENSION 4


struct Affine3d
{
	//3*3 matrix consist of 3 vectors.
	float value[4][4] = {{0,}, {0,}, {0,}, {0,}};

	Affine3d() = default; //default constructor. filled with 0.

	Affine3d(const float column0_row0, const float column1_row0, const float column2_row0, const float column3_row0,
	         const float column0_row1, const float column1_row1, const float column2_row1, const float column3_row1,
	         const float column0_row2, const float column1_row2, const float column2_row2, const float column3_row2,
	         const float column0_row3, const float column1_row3, const float column2_row3, const float column3_row3) :
		value{
			{column0_row0, column0_row1, column0_row2, column3_row0},
			{column1_row0, column1_row1, column1_row2, column3_row1},
			{column2_row0, column2_row1, column2_row2, column3_row2},
			{column0_row3, column1_row3, column2_row3, column3_row3}
		} 
			{} //explicit constructor using 9 floats.

	Affine3d(const Vector4 first_vector, const Vector4 second_vector, const Vector4 third_vector, const Vector4 forth_vector) :
		value{
			{first_vector.x, first_vector.y, first_vector.z, first_vector.w},
			{second_vector.x, second_vector.y, second_vector.z, second_vector.w},
			{third_vector.x, third_vector.y, third_vector.z, third_vector.w},
			{forth_vector.x, forth_vector.y, forth_vector.z, forth_vector.w}
		}
	{}

	float& operator()(const int column, const int row);
	const float& operator()(const int column, const int row) const;

	float* operator[](const int column);
	const float* operator[](const int column) const;


	Affine3d operator*(const Affine3d input_affine) const;
	//*operator overloading for multiplying affine matrix with affine matrix.
	Affine3d& operator*=(const Affine3d input_affine);
	//*= operator overloading for multyplying affine matrix with affine matrix.

	Affine3d& transpose(); // transpose given affine matrix.

	friend std::ostream& operator<<(std::ostream& input_ostream, const Affine3d input_affine);


	static Affine3d build_rotation(const float degree, Math::Axis axis = Math::Z); // build rotation affine matrix with given degree.
	static Affine3d build_identity(); // build identity matrix.
	static Affine3d build_scale(const float scale_factor); // build uniform affine sacle matrix.
	static Affine3d build_scale(const float scale_factor1, const float scale_factor2);
	// build non uniform affine sacle matrix.
	static Affine3d build_affine_translation(const float xposition, const float yposition);
	// build translation affine matrix with given number.
};

////////////Non member function////////////
std::ostream& operator<<(std::ostream& input_ostream, const Affine3d input_affine);
