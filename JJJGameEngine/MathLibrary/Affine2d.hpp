/******************************************************************************/
/*!
file name : Affine2d.hpp
author    : Jaejun Jang
email     : jjj404001@gmail.com


DigiPen login     : jaejun.jang
Course name       : CS230
Assignment number :#1

term   :Spring 2018
brief  :
    This file contains the function prototypes and Affine2d struct using for calculating with affine matrix.
      
    Functions include:
	in Affine2d struct :
       + float& operator()(int column,int row);         //()operator overloading for accessing 2*2 matrix.
	   + float  operator()(int column,int row) const;   //same with above but using const parameter.
       + Affine2d operator*(Affine2d InputAffine) const;//  *operator overloading for multiplying affine matrix with affine matrix.
       + Affine2d& operator*=(Affine2d InputAffine);    //  *= operator overloading for multyplying affine matrix with affine matrix.
	   + Affine2d& transpose(void);                     // transpose given affine matrix.
	 
	non-member normal function :
	   + Affine2d Build_rotation(float degree);                           // build rotation affine matrix with given degree.
	   + Affine2d Build_identity(void);                               // build identity matrix.
	   + Affine2d build_scale(float scaleFactor);                     // build uniform affine sacle matrix.
	   + Affine2d build_scale(float scaleFactor1, float scaleFactor2);// build non uniform affine sacle matrix.
	   + Affine2d build_affine_translation(float Xposition, float Yposition);// build translation affine matrix with given number.
  
*/
/******************************************************************************/
#pragma once
#include <ostream>
#include "Vector3.hpp" // Vector3 struct.
#define AFFINE2D_DIMENSION 3


struct Affine2d
{
    //3*3 matrix consist of 3 vectors.
    float value[3][3] = {{0,},{0,},{0,}};

    Affine2d() = default;  //default constructor. filled with 0.

    Affine2d(const Vector3 column0, const Vector3 column1, const Vector3 column2) :
		value{ {column0.x, column0.y, column0.z},{ column1.x, column1.y, column1.z}, {column2.x, column2.y, column2.z} } {}     //constructor for 3 Vector3.

    Affine2d(const float column0_row0, const float column0_row1, const float column0_row2,
			 const float column1_row0, const float column1_row1, const float column1_row2,
			 const float column2_row0, const float column2_row1, const float column2_row2) :
             value{column0_row0, column0_row1, column0_row2,
                       column1_row0, column1_row1, column1_row2,
                       column2_row0, column2_row1, column2_row2}{}//explicit constructor using 9 floats.


	


    float& operator()(const int column, const int row);        
	const float&  operator()(const int column, const int row) const;

	float* operator[](const int column);       
	const float* operator[](const int column) const;


    Affine2d operator*(const Affine2d input_affine) const;//*operator overloading for multiplying affine matrix with affine matrix.
    Affine2d& operator*=(const Affine2d input_affine);    //*= operator overloading for multyplying affine matrix with affine matrix.
	
	Affine2d& transpose(); // transpose given affine matrix.

	friend std::ostream& operator<<(std::ostream& input_ostream, const Affine2d input_affine);


	static Affine2d build_rotation(const float degree);                       // build rotation affine matrix with given degree.
	static Affine2d build_identity();                               // build identity matrix.
	static Affine2d build_scale(const float scale_factor);                     // build uniform affine sacle matrix.
	static Affine2d build_scale(const float scale_factor1, const float scale_factor2);// build non uniform affine sacle matrix.
	static Affine2d build_affine_translation(const float xposition, const float yposition);// build translation affine matrix with given number.
};
////////////Non member function////////////
std::ostream& operator<<(std::ostream& input_ostream, const Affine2d input_affine);