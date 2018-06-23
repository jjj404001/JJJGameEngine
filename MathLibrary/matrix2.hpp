/******************************************************************************/
/*!
file name : matrix2.hpp
author    : Jaejun Jang
email     : jjj404001@gmail.com


DigiPen login     : jaejun.jang
Course name       : CS230
Assignment number :#1

term   :Spring 2018
brief  :
    This file contains the function prototypes and struct matrix2 using for calculating with matrix.
      
    Functions include:
	in matrix2 struct :
       + float& operator()(int column,int row);      //()operator overloading for accessing 2*2 matrix.
       + float operator()(int column,int row) const;
    
    
       + matrix2 operator*(int multiplier);        //multiplication with integer.
       + matrix2 operator*(float multiplier);      //multiplication with float.

       + matrix2& operator*=(int multiplier);      //multiplication with integer.
       + matrix2& operator*=(float multiplier);    //multiplication with float.

       + vector2 operator*(vector2 inputVector);   //multiplication with vector.
       + vector2 operator*=(vector2 inputVector);  //multiplication with vector.

       + matrix2& operator*=(matrix2 inputMatrix); //multiplication with matrix.

       + matrix2& transpose();                     // transpose given matrix.
       + matrix2& transpose(matrix2 inputMatrix);  // transpose given matrix.


       + float determinant_of(matrix2 inputMatrix); // calculate determinant of given matrix.
       + matrix2 inverse_of(matrix2 inputMatrix);   // calculate inverse of given matrix.
	 
	non-member normal function :
	   + matrix2 operator*(matrix2 firstInputMatrix,matrix2 secondInputMatrix); //multiplication with matrix.
	   + matrix2 build_rotation(float degree);                      // build rotation matrix.
       + matrix2 build_identity(void);                              // build identity matrix.
       + matrix2 build_scale(float scaleFactor);                    // build uniform sacle matrix.
       + matrix2 build_scale(float scaleFactor1,float scaleFactor2);// build non uniform matrix.

*/
/******************************************************************************/
#pragma once
#include "vector2.hpp"


struct matrix2 {
    float m_matrix2Array[2][2];

    //constructors
    matrix2()
    {
        m_matrix2Array[0][0] = 0.0f;
        m_matrix2Array[0][1] = 0.0f;
        m_matrix2Array[1][0] = 0.0f;
        m_matrix2Array[1][1] = 0.0f;
    }

    //explicit constructors
    matrix2(float column0_row0, float column0_row1, float column1_row0, float column1_row1)
    {
        m_matrix2Array[0][0] = column0_row0;
        m_matrix2Array[0][1] = column0_row1;
        m_matrix2Array[1][0] = column1_row0;
        m_matrix2Array[1][1] = column1_row1;
    }

    //constructor for vector2.
    matrix2(vector2 column0, vector2 column1)
    {
        m_matrix2Array[0][0] = column0.x;
        m_matrix2Array[0][1] = column0.y;
        m_matrix2Array[1][0] = column1.x;
        m_matrix2Array[1][1] = column1.y;
    }

    
    float& operator()(int column,int row);      //()operator overloading for accessing 2*2 matrix.
    float operator()(int column,int row) const;
    
    
    matrix2 operator*(int multiplier);      //multiplication with integer.
    matrix2 operator*(float multiplier);    //multiplication with float.

	matrix2& operator*=(int multiplier);    //multiplication with integer.
	matrix2& operator*=(float multiplier);  //multiplication with float.
	
	vector2 operator*(vector2 inputVector); //multiplication with vector.
    vector2 operator*=(vector2 inputVector); //multiplication with vector.
	
    matrix2& operator*=(matrix2 inputMatrix); //multiplication with matrix.

    matrix2& transpose(); // transpose given matrix.
    matrix2& transpose(matrix2 inputMatrix); // transpose given matrix.
    

    float determinant_of(matrix2 inputMatrix); // calculate determinant of given matrix.
    matrix2 inverse_of(matrix2 inputMatrix); // calculate inverse of given matrix.
};

////////////////////////////////////////////////////
////////////////non-member function/////////////////
////////////////////////////////////////////////////

    matrix2 operator*(matrix2 firstInputMatrix,matrix2 secondInputMatrix); //multiplication with matrix.
    matrix2 build_rotation(float degree); // build rotation matrix.
    matrix2 build_identity(void);         // build identity matrix.
    matrix2 build_scale(float scaleFactor);// build uniform sacle matrix.
    matrix2 build_scale(float scaleFactor1,float scaleFactor2);// build non uniform matrix.

    