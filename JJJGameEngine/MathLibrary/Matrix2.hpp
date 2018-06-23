/******************************************************************************/
/*!
file name : Matrix2.hpp
author    : Jaejun Jang
email     : jjj404001@gmail.com


DigiPen login     : jaejun.jang
Course name       : CS230
Assignment number :#1

term   :Spring 2018
brief  :
    This file contains the function prototypes and struct Matrix2 using for calculating with matrix.
      
    Functions include:
	in Matrix2 struct :
       + float& operator()(int column,int row);      //()operator overloading for accessing 2*2 matrix.
       + float operator()(int column,int row) const;
    
    
       + Matrix2 operator*(int multiplier);        //multiplication with integer.
       + Matrix2 operator*(float multiplier);      //multiplication with float.

       + Matrix2& operator*=(int multiplier);      //multiplication with integer.
       + Matrix2& operator*=(float multiplier);    //multiplication with float.

       + Vector2 operator*(Vector2 inputVector);   //multiplication with vector.
       + Vector2 operator*=(Vector2 inputVector);  //multiplication with vector.

       + Matrix2& operator*=(Matrix2 inputMatrix); //multiplication with matrix.

       + Matrix2& transpose();                     // transpose given matrix.
       + Matrix2& transpose(Matrix2 inputMatrix);  // transpose given matrix.


       + float determinant_of(Matrix2 inputMatrix); // calculate determinant of given matrix.
       + Matrix2 inverse_of(Matrix2 inputMatrix);   // calculate inverse of given matrix.
	 
	non-member normal function :
	   + Matrix2 operator*(Matrix2 firstInputMatrix,Matrix2 secondInputMatrix); //multiplication with matrix.
	   + Matrix2 build_rotation(float degree);                      // build rotation matrix.
       + Matrix2 build_identity(void);                              // build identity matrix.
       + Matrix2 build_scale(float scaleFactor);                    // build uniform sacle matrix.
       + Matrix2 build_scale(float scaleFactor1,float scaleFactor2);// build non uniform matrix.

*/
/******************************************************************************/
#pragma once
#include "Vector2.hpp"


struct Matrix2 {
    float value[2][2];

    //constructors
    Matrix2()
    {
        value[0][0] = 0.0f;
        value[0][1] = 0.0f;
        value[1][0] = 0.0f;
        value[1][1] = 0.0f;
    }

    //explicit constructors
    Matrix2(const float column0_row0, const float column0_row1, const float column1_row0, const float column1_row1)
    {
        value[0][0] = column0_row0;
        value[0][1] = column0_row1;
        value[1][0] = column1_row0;
        value[1][1] = column1_row1;
    }

    //constructor for Vector2.
    Matrix2(const Vector2 column0, const Vector2 column1)
    {
        value[0][0] = column0.x;
        value[0][1] = column0.y;
        value[1][0] = column1.x;
        value[1][1] = column1.y;
    }

    
    float& operator()(int column,int row);      //()operator overloading for accessing 2*2 matrix.
    float operator()(int column,int row) const;

	float* operator[](int column);      //()operator overloading for accessing 2*2 matrix.
	const float* operator[](int column) const;
    
    
    Matrix2 operator*(int multiplier);      //multiplication with integer.
    Matrix2 operator*(float multiplier);    //multiplication with float.

	Matrix2& operator*=(int multiplier);    //multiplication with integer.
	Matrix2& operator*=(float multiplier);  //multiplication with float.
	
	Vector2 operator*(Vector2 input_vector); //multiplication with vector.
    Vector2 operator*=(Vector2 input_vector); //multiplication with vector.
	
    Matrix2& operator*=(Matrix2 input_matrix); //multiplication with matrix.

    Matrix2& transpose(); // transpose given matrix.
    Matrix2& transpose(Matrix2 input_matrix); // transpose given matrix.
    

    float determinant_of(Matrix2 input_matrix); // calculate determinant of given matrix.
    Matrix2 inverse_of(Matrix2 input_matrix); // calculate inverse of given matrix.


	Matrix2 operator*(Matrix2 second_input_matrix); //multiplication with matrix.


	static Matrix2 build_rotation(float degree); // build rotation matrix.
	static Matrix2 build_identity(void);         // build identity matrix.
	static Matrix2 build_scale(float scaleFactor);// build uniform sacle matrix.
	static Matrix2 build_scale(float scaleFactor1, float scaleFactor2);// build non uniform matrix.
};

    

    