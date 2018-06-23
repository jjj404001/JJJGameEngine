/******************************************************************************/
/*!
file name : affine2d.hpp
author    : Jaejun Jang
email     : jjj404001@gmail.com


DigiPen login     : jaejun.jang
Course name       : CS230
Assignment number :#1

term   :Spring 2018
brief  :
    This file contains the function prototypes and affine2d struct using for calculating with affine matrix.
      
    Functions include:
	in affine2d struct :
       + float& operator()(int column,int row);         //()operator overloading for accessing 2*2 matrix.
	   + float  operator()(int column,int row) const;   //same with above but using const parameter.
       + affine2d operator*(affine2d InputAffine) const;//  *operator overloading for multiplying affine matrix with affine matrix.
       + affine2d& operator*=(affine2d InputAffine);    //  *= operator overloading for multyplying affine matrix with affine matrix.
	   + affine2d& transpose(void);                     // transpose given affine matrix.
	 
	non-member normal function :
	   + affine2d build_affine_rotation(float degree);                           // build rotation affine matrix with given degree.
	   + affine2d build_affine_identity(void);                               // build identity matrix.
	   + affine2d build_affine_scale(float scaleFactor);                     // build uniform affine sacle matrix.
	   + affine2d build_affine_scale(float scaleFactor1, float scaleFactor2);// build non uniform affine sacle matrix.
	   + affine2d build_affine_translation(float Xposition, float Yposition);// build translation affine matrix with given number.
  
*/
/******************************************************************************/
#pragma once
#include "vector3.hpp" // vector3 struct.


struct affine2d
{
    //3*3 matrix consist of 3 vectors.
    float affine_map[3][3] = {0,};

    affine2d() = default;  //default constructor. filled with 0.

    affine2d(const vector3 column0, const vector3 column1, const vector3 column2) :
    affine_map{column0.x, column0.y, column0.z, column1.x, column1.y, column1.z, column2.x, column2.y, column2.z}{}     //constructor for 3 vector3.

    affine2d(const float column0_row0, const float column0_row1, const float column0_row2,
			 const float column1_row0, const float column1_row1, const float column1_row2,
			 const float column2_row0, const float column2_row1, const float column2_row2) :
             affine_map{column0_row0, column0_row1, column0_row2,
                       column1_row0, column1_row1, column1_row2,
                       column2_row0, column2_row1, column2_row2}{}//explicit constructor using 9 floats.



    float& operator()(const int column, const int row);         //()operator overloading for accessing 2*2 matrix.
    float  operator()(const int column, const int row) const;   //same with above but using const parameter.

    affine2d operator*(affine2d input_affine) const;//*operator overloading for multiplying affine matrix with affine matrix.
    affine2d& operator*=(affine2d input_affine);    //*= operator overloading for multyplying affine matrix with affine matrix.
	
	affine2d& transpose(void); // transpose given affine matrix.




	static affine2d build_affine_rotation(float degree);                       // build rotation affine matrix with given degree.
	static affine2d build_affine_identity(void);                               // build identity matrix.
	static affine2d build_affine_scale(float scale_factor);                     // build uniform affine sacle matrix.
	static affine2d build_affine_scale(float scale_factor1, float scale_factor2);// build non uniform affine sacle matrix.
	static affine2d build_affine_translation(float xposition, float yposition);// build translation affine matrix with given number.
};
////////////////////////////////////////////////////
////////////////non-member function/////////////////
////////////////////////////////////////////////////


	