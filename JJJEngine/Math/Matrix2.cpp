/******************************************************************************/
/*!
file name : matrix2.cpp
author    : Jaejun Jang
email     : jjj404001@gmail.com


DigiPen login     : jaejun.jang
Course name       : CS230
Assignment number :#1

term   :Spring 2018
brief  :
    This file contains the function for calculating with matrix.
      
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
#include "Matrix2.hpp"
#include <cmath>



//()operator overloading for accessing 2*2 matrix.
float& Matrix2::operator()(int column, int row)
{
    //using standard column - row form.
    //simply return element of 2*2 matrix.
    return value[column][row];
}

//()operator overloading for accessing 2*2 matrix. Using const matrix.
float Matrix2::operator()(int column,int row) const
{
    return value[column][row];
}

float* Matrix2::operator[](int column)
{
	return value[column];
}

const float* Matrix2::operator[](int column) const
{
	return value[column];
}


//* operator overloading for multiplication with 2*2 matrix.


template<typename Number>
Matrix2 Matrix2::operator*(Number multiplier)
{
	for(auto i = 0; i < 2;i++)
	{
		for(auto j = 0; j < 2; j++)
		{
			value[i][j] *= multiplier;
		}
	}
	//return calculated matrix.
    return *this;
}

template<typename Number>
Matrix2& Matrix2::operator*=(Number multiplier)
{
	for(auto i = 0; i < 2;i++)
	{
		for(auto j = 0; j < 2; j++)
		{
			value[i][j] *= multiplier;
		}
	}
	
	//return calculated matrix.
	return *this;
}

//multiplication with vector.
Vector2 Matrix2::operator*(Vector2 inputVector)
{
    Vector2 result;

    //multiply matrix with vector
    //      [ a, b ]  *  [e]  =  [ae + bf]
    //      [ c, d ]     [f]     [ce + df]

    result.x = (value[0][0] * inputVector.x) + (value[0][1] * inputVector.y);
    result.y = (value[1][0] * inputVector.x) + (value[1][1] * inputVector.y);

	//return calculated matrix.
    return result;
}

//multiplication with vector.
Vector2 Matrix2::operator*=(const Vector2 input_vector)
{
    Vector2 result;

    //multiply matrix with vector
    //      [ a, b ]  *  [e]  =  [ae + bf]
    //      [ c, d ]     [f]     [ce + df]

    result.x = (value[0][0] * input_vector.x) + (value[0][1] * input_vector.y);
    result.y = (value[1][0] * input_vector.x) + (value[1][1] * input_vector.y);

	//return calculated matrix.
    return result;
}

Matrix2& Matrix2::operator*=(Matrix2 inputMatrix)
{
    Matrix2 result;

    //matrix multiplication : [a b][e f]
    //                        [c d][g h]
    //                      =   [ae + bg, af + bh]
    //                          [ce + dg, cf + dh]

    result(0,0) = (value[0][0] * inputMatrix(0,0)) + (value[0][1] * inputMatrix(1,0));
    result(0,1) = (value[0][0] * inputMatrix(0,1)) + (value[0][1] * inputMatrix(1,1));
    result(1,0) = (value[1][0] * inputMatrix(0,0)) + (value[1][1] * inputMatrix(1,0));
    result(1,1) = (value[1][0] * inputMatrix(0,1)) + (value[1][1] * inputMatrix(1,1));

    value[0][0] = result(0,0);
    value[0][1] = result(0,1);
    value[1][0] = result(1,0);
    value[1][1] = result(1,1);


    //duplicate calculated result to matrix who calls operator.


	//return calculated matrix.
    return *this;
}

//transpose vector.
//for convenient use.
Matrix2& Matrix2::transpose()
{
	const auto temporaryMemory = value[0][1];
    value[0][1] = value[1][0];
    value[1][0] = temporaryMemory;

	//return transposed matrix.
    return *this;
}


float Matrix2::determinant()
{
    //calculate determinant of given matrix
    //using triangle rule.
	
	//determinant is : [a, b]  
	//				   [c, d]  ,  ad - bc = determinant
	const auto result = *this[0][0] * *this[1][1] - *this[0][1] * *this[1][0];

	//return determinant
    return result;
}

Matrix2 Matrix2::inverse()
{
    Matrix2 result;
	
	//inverse matrix : [a, b]				[ d, -b] /(divided by) determinant of original.
	//				   [c, d], transform to [-c,  a]
	const auto determinant = this->determinant();
    

    result(0,0) = *this[1][1] / determinant;
    result(0,1) = -*this[0][1] / determinant;
    result(1,0) = -*this[1][0] / determinant;
    result(1,1) = *this[0][0] / determinant;

	//return inversed matrix.
    return result;
}


//multiplication with matrix.
Matrix2 Matrix2::operator*(Matrix2 secondInputMatrix)
{
	Matrix2 result;

	//matrix multiplication : [a b][e f]
	//                        [c d][g h]
	//                      =   [ae + bg, af + bh]
	//                          [ce + dg, cf + dh]


	result(0, 0) = (value[0][0] * secondInputMatrix(0, 0)) + (value[0][1] * secondInputMatrix(1, 0));
	result(0, 1) = (value[0][0] * secondInputMatrix(0, 1)) + (value[0][1] * secondInputMatrix(1, 1));
	result(1, 0) = (value[1][0] * secondInputMatrix(0, 0)) + (value[1][1] * secondInputMatrix(1, 0));
	result(1, 1) = (value[1][0] * secondInputMatrix(0, 1)) + (value[1][1] * secondInputMatrix(1, 1));

	//return calculated matrix.
	return result;
}


//build rotation matrix
Matrix2 Matrix2::build_rotation(float degree)
{
	const auto cos_degree = std::cos(degree);
	const auto sin_degree = std::sin(degree);

	//rotation matrix : [ cos(degree), sin(degree)]
	//					[-sin(degree), cos(degree)]
	const Matrix2 rotation = { cos_degree, sin_degree, -sin_degree, cos_degree };

	//return rotation matrix.
	return rotation;
}

//build identity matrix
Matrix2 Matrix2::build_identity()
{
	const Matrix2 identity = { 1,0,0,1 };

	//return identity matrix.
	return identity;
}
// build uniform sacle matrix.
Matrix2 Matrix2::build_scale(float scaleFactor)
{
	//return builded uniform scale matrix.
	return { scaleFactor, 0, 0, scaleFactor };
}

// build non uniform matrix.
Matrix2 Matrix2::build_scale(float scaleFactor1, float scaleFactor2)
{
	//return builded non uniform scale matrix.
	return { scaleFactor1, 0, 0, scaleFactor2 };
}
