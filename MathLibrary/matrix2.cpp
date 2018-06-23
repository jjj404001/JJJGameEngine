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
#include "matrix2.hpp"
#include <cmath>



//()operator overloading for accessing 2*2 matrix.
float& matrix2::operator()(int column, int row)
{
    //using standard column - row form.
    //simply return element of 2*2 matrix.
    return m_matrix2Array[column][row];
}

//()operator overloading for accessing 2*2 matrix. Using const matrix.
float matrix2::operator()(int column,int row) const
{
    return m_matrix2Array[column][row];
}





//* operator overloading for multiplication with 2*2 matrix.


//multiplication with integer.
matrix2 matrix2::operator*(int multiplier)
{
	int i = 0, j = 0; //variables for loop.
	
	
	for(i = 0; i < 2;i++)
	{
		for(j = 0; j < 2; j++)
		{
			m_matrix2Array[i][j] *= multiplier;
		}
		
		j = 0;
	}
	
    //simply multiply each element of matrix with given integer.

	//return calculated matrix.
    return *this;
}

//multiplication with float.
matrix2 matrix2::operator*(float multiplier)
{
	int i = 0, j = 0; //variables for loop.
	
	
	for(i = 0; i < 2;i++)
	{
		for(j = 0; j < 2; j++)
		{
			m_matrix2Array[i][j] *= multiplier;
		}
		
		j = 0;
	}
	
    //simply multiply each element of matrix with given float.

	//return calculated matrix.
    return *this;
}

//multiplication with integer.
matrix2& matrix2::operator*=(int multiplier)
{
	int i = 0, j = 0; //variables for loop.
	
	
	for(i = 0; i < 2;i++)
	{
		for(j = 0; j < 2; j++)
		{
			m_matrix2Array[i][j] *= multiplier;
		}
		
		j = 0;
	}
	
	//simply multiply each element of matrix with given integer.


	//return calculated matrix.
	return *this;
}

//multiplication with float.
matrix2& matrix2::operator*=(float multiplier)
{
	int i = 0, j = 0; //variables for loop.
	
	
	for(i = 0; i < 2;i++)
	{
		for(j = 0; j < 2; j++)
		{
			m_matrix2Array[i][j] *= multiplier;
		}
		
		j = 0;
	}
	
	//simply multiply each element of matrix with given float.

	//return calculated matrix.
	return *this;	
}

//multiplication with vector.
vector2 matrix2::operator*(vector2 inputVector)
{
    vector2 result;

    //multiply matrix with vector
    //      [ a, b ]  *  [e]  =  [ae + bf]
    //      [ c, d ]     [f]     [ce + df]

    result.x = (m_matrix2Array[0][0] * inputVector.x) + (m_matrix2Array[0][1] * inputVector.y);
    result.y = (m_matrix2Array[1][0] * inputVector.x) + (m_matrix2Array[1][1] * inputVector.y);

	//return calculated matrix.
    return result;
}

//multiplication with vector.
vector2 matrix2::operator*=(vector2 inputVector)
{
    vector2 result;

    //multiply matrix with vector
    //      [ a, b ]  *  [e]  =  [ae + bf]
    //      [ c, d ]     [f]     [ce + df]

    result.x = (m_matrix2Array[0][0] * inputVector.x) + (m_matrix2Array[0][1] * inputVector.y);
    result.y = (m_matrix2Array[1][0] * inputVector.x) + (m_matrix2Array[1][1] * inputVector.y);

	//return calculated matrix.
    return result;
}

matrix2& matrix2::operator*=(matrix2 inputMatrix)
{
    matrix2 result;

    //matrix multiplication : [a b][e f]
    //                        [c d][g h]
    //                      =   [ae + bg, af + bh]
    //                          [ce + dg, cf + dh]

    result(0,0) = (m_matrix2Array[0][0] * inputMatrix(0,0)) + (m_matrix2Array[0][1] * inputMatrix(1,0));
    result(0,1) = (m_matrix2Array[0][0] * inputMatrix(0,1)) + (m_matrix2Array[0][1] * inputMatrix(1,1));
    result(1,0) = (m_matrix2Array[1][0] * inputMatrix(0,0)) + (m_matrix2Array[1][1] * inputMatrix(1,0));
    result(1,1) = (m_matrix2Array[1][0] * inputMatrix(0,1)) + (m_matrix2Array[1][1] * inputMatrix(1,1));

    m_matrix2Array[0][0] = result(0,0);
    m_matrix2Array[0][1] = result(0,1);
    m_matrix2Array[1][0] = result(1,0);
    m_matrix2Array[1][1] = result(1,1);


    //duplicate calculated result to matrix who calls operator.


	//return calculated matrix.
    return *this;
}

//transpose vector.
//for convenient use.
matrix2& matrix2::transpose(void)
{
    float temporaryMemory; // for storing elements of given matrix.

    temporaryMemory = m_matrix2Array[0][1];
    m_matrix2Array[0][1] = m_matrix2Array[1][0];
    m_matrix2Array[1][0] = temporaryMemory;

	//return transposed matrix.
    return *this;
}

//transpose given vector.
matrix2& matrix2::transpose(matrix2 inputMatrix)
{
    float temporaryMemory; // for storing elements of given matrix.

    temporaryMemory = inputMatrix(0,1);
    inputMatrix(0,1) = inputMatrix(1,0);
    inputMatrix(1,0) = temporaryMemory;

	//return transposed matrix.
    return *this;
}


float matrix2::determinant_of(matrix2 inputMatrix)
{
    //calculate determinant of given matrix
    //using triangle rule.
	
	//determinant is : [a, b]  
	//				   [c, d]  ,  ad - bc = determinant
    float result = inputMatrix(0,0) * inputMatrix(1,1) - inputMatrix(0,1) * inputMatrix(1,0);

	//return determinant
    return result;
}

matrix2 matrix2::inverse_of(matrix2 inputMatrix)
{
    matrix2 result;
	
	//inverse matrix : [a, b]				[ d, -b] /(divided by) determinant of original.
	//				   [c, d], transform to [-c,  a]
    float determinant = determinant_of(inputMatrix);
    

    result(0,0) =  inputMatrix(1,1) / determinant;
    result(0,1) = -inputMatrix(0,1) / determinant;
    result(1,0) = -inputMatrix(1,0) / determinant;
    result(1,1) =  inputMatrix(0,0) / determinant;

	//return inversed matrix.
    return result;
}




////////////////////////////////////////////////////
////////////////non-member function/////////////////
////////////////////////////////////////////////////


//multiplication with vector.
matrix2 operator*(matrix2 firstInputMatrix,matrix2 secondInputMatrix)
{
    matrix2 result;

    //matrix multiplication : [a b][e f]
    //                        [c d][g h]
    //                      =   [ae + bg, af + bh]
    //                          [ce + dg, cf + dh]


    result(0,0) = (firstInputMatrix(0,0) * secondInputMatrix(0,0)) + (firstInputMatrix(0,1) * secondInputMatrix(1,0));
    result(0,1) = (firstInputMatrix(0,0) * secondInputMatrix(0,1)) + (firstInputMatrix(0,1) * secondInputMatrix(1,1));
    result(1,0) = (firstInputMatrix(1,0) * secondInputMatrix(0,0)) + (firstInputMatrix(1,1) * secondInputMatrix(1,0));
    result(1,1) = (firstInputMatrix(1,0) * secondInputMatrix(0,1)) + (firstInputMatrix(1,1) * secondInputMatrix(1,1));

	//return calculated matrix.
    return result;
}

//build rotation matrix
matrix2 build_rotation(float degree)
{
    float cosDegree = std::cos(degree);
    float sinDegree = std::sin(degree);
	
	//rotation matrix : [ cos(degree), sin(degree)]
	//					[-sin(degree), cos(degree)]
    matrix2 rotation = {cosDegree, sinDegree, -sinDegree, cosDegree};

	//return rotation matrix.
    return rotation;
}

//build identity matrix
matrix2 build_identity(void)
{
    matrix2 identity = {1,0,0,1};

	//return identity matrix.
    return identity;
}
// build uniform sacle matrix.
matrix2 build_scale(float scaleFactor)
{
	//return builded uniform scale matrix.
    return {scaleFactor, 0, 0, scaleFactor};
}

// build non uniform matrix.
matrix2 build_scale(float scaleFactor1,float scaleFactor2)
{
	//return builded non uniform scale matrix.
    return { scaleFactor1, 0, 0, scaleFactor2};
}
