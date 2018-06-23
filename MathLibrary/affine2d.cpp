/******************************************************************************/
/*!
file name : affine2d.cpp
author    : Jaejun Jang
email     : jjj404001@gmail.com


DigiPen login     : jaejun.jang
Course name       : CS230
Assignment number :#1

term   :Spring 2018
brief  :
    This file contains the function using for calculating with affine matrix.
      
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
#include "affine2d.hpp"
#include <cmath>
#include <cassert>


//()operator overloading for accessing affine 2d.
float& affine2d::operator()(const int column, const int row)      
{
	assert(column < 3 && row < 3);
	//return element of affine matrix.
    return affine_map[column][row];
}

float  affine2d::operator()(const int column, const int row) const//same with above but using const parameter.
{
	assert(column < 3 && row < 3);
	//return element of affine matrix.
    return affine_map[column][row];
}


//  *operator overloading for multiplying affine matrix with affine matrix.
affine2d affine2d::operator*(affine2d input_affine) const
{
    affine2d result; //variable for calculated affine matrix.
	const int number_of_rows    = 3; // and rows of given matrix. in this case, they will be always 3 * 3.
	const int number_of_columns = 3; // variables for describe number of columns
	
	
	int i = 0,j = 0,k = 0; //variable for loop index.

	while(i < number_of_columns)
	{
			
			
		while(j < number_of_rows)
		{
				
				
			while(k < number_of_columns)
			{
				result(i,j) += affine_map[i][k] * input_affine(k,j);

					
					
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
affine2d& affine2d::operator*=(affine2d input_affine)
{
	*this = *this * input_affine;
    return *this;
}


//function for transpose affine matrix.
affine2d& affine2d::transpose(void)
{
	float temporary_memory; //variable for memory original affine matrix


	for(auto loop_index = 1; loop_index < 3; ++loop_index)
	{
		temporary_memory         = affine_map[0][loop_index];
		
		affine_map[0][loop_index] = affine_map[loop_index][0];
		affine_map[loop_index][0] = temporary_memory;
	}
	
	//handling exception
	temporary_memory = affine_map[1][2];
	
	affine_map[1][2] = affine_map[2][1];
	affine_map[2][1] = temporary_memory;
	

	
	//return transposed affine matrix.
	return *this;
}


affine2d affine2d::build_affine_rotation(float degree)
{
	affine2d rotationMatrix;                            //rotation matrix.
	vector3 u = {std::cos(degree), std::sin(degree), 0}; //u,v,t vectors for easy-building affine matrix.
	vector3 v = {-std::sin(degree), std::cos(degree), 0};
	vector3 t = {0.0f, 0.0f, 1};
	
	rotationMatrix = { u, v, t };

	
	//return rotation matrix.
	return rotationMatrix;
}


affine2d affine2d::build_affine_identity(void)
{
	affine2d identity;
	const int number_of_columns = 3; //number of columns
	const int number_of_rows    = 3; //number of rows

	
	for(auto loop_index1 = 0; loop_index1 < number_of_columns; ++loop_index1)
	{
		for(auto loop_index2 = 0; loop_index2 < number_of_rows; ++loop_index2)
		{
			if( loop_index1 == loop_index2 )
			{
				identity( loop_index1, loop_index2 ) = 1.0f;
			}
			else
			{
				identity( loop_index1, loop_index2 ) = 0.0f;
			}
		}
	}
	
	//return builded identity matrix.
	return identity;
}

affine2d affine2d::build_affine_scale(float scale_factor)
{
	affine2d scale;
	const int number_of_columns = 3; //number of columns
	const int number_of_rows    = 3; //number of rows

	auto loop_index1 = 0;  //loop indexes.
	auto loop_index2 = 0;
	
	for(loop_index1 = 0; loop_index1 < number_of_columns; ++loop_index1)
	{
		for(loop_index2 = 0; loop_index2 < number_of_rows; ++loop_index2)
		{
			if( loop_index1 == loop_index2 )
			{
				scale( loop_index1, loop_index2 ) = scale_factor;
			}
			else
			{
				scale( loop_index1, loop_index2 ) = 0.0f;
			}
		}
	}
	
	//manualy put value in last element of affine matrix.
	scale(2,2) = 1.0;
	
	
	//return builded affine scale matrix
	return scale;
}

affine2d affine2d::build_affine_scale(float scale_factor1, float scale_factor2)
{
	affine2d scale = build_affine_identity();

	
	
	//manually build scale matrix.
	scale(0,0) = scale_factor1;
	scale(1,1) = scale_factor2;
	scale(2,2) = 1.0f;

	
	
	//return builded scale matrix.
	return scale;
}

affine2d affine2d::build_affine_translation(float xposition, float yposition)
{
	affine2d translation = build_affine_identity(); //initialize translatino matrix with identity matrix.
	
	translation.affine_map[0][2] = xposition;
	translation.affine_map[1][2] = yposition;
	
	
	//return builded translation matrix.
	return translation;
}