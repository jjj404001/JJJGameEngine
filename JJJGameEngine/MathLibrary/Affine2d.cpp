/******************************************************************************/
/*!
file name : Affine2d.cpp
author    : Jaejun Jang
email     : jjj404001@gmail.com


DigiPen login     : jaejun.jang
Course name       : CS230
Assignment number :#1

term   :Spring 2018
brief  :
    This file contains the function using for calculating with affine matrix.
      
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
#include "Affine2d.hpp"
#include <cmath> 
#include <cassert>


//()operator overloading for accessing affine 2d.
float& Affine2d::operator()(const int column, const int row)      
{
	assert("Out of index." && column < 3 && row < 3 && column >= 0 && row >= 0);
	//return element of affine matrix.
    return value[column][row];
}

const float& Affine2d::operator()(const int column, const int row) const//same with above but using const parameter.
{
	assert("Out of index." && column < 3 && row < 3 && column >= 0 && row >= 0);
	//return element of affine matrix.
    return value[column][row];
}

float* Affine2d::operator[](const int column)
{
	assert("Out of index." && column < 3 && column >= 0);
	return value[column];
}

const float* Affine2d::operator[](const int column) const
{
	assert("Out of index." && column < 3 && column >= 0 );
	return value[column];
}


//  *operator overloading for multiplying affine matrix with affine matrix.
Affine2d Affine2d::operator*(Affine2d input_affine) const
{
    Affine2d result; //variable for calculated affine matrix.



	auto i = 0,j = 0,k = 0; //variable for loop index.

	while(i < AFFINE2D_DIMENSION)
	{
	
		while(j < AFFINE2D_DIMENSION)
		{
				
				
			while(k < AFFINE2D_DIMENSION)
			{
				result(i,j) += value[i][k] * input_affine(k,j);

					
					
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
Affine2d& Affine2d::operator*=(Affine2d input_affine)
{
	*this = *this * input_affine;
    return *this;
}


//function for transpose affine matrix.
Affine2d& Affine2d::transpose()
{
	float temporary_memory; //variable for memory original affine matrix


	for(auto loop_index = 1; loop_index < 3; ++loop_index)
	{
		temporary_memory         = value[0][loop_index];
		
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


Affine2d Affine2d::build_rotation(float degree)
{
	const Vector3 u = {std::cos(degree), std::sin(degree), 0}; //u,v,t vectors for easy-building affine matrix.
	const Vector3 v = {-std::sin(degree), std::cos(degree), 0};
	const Vector3 t = {0.0f, 0.0f, 1};

	const Affine2d rotation_matrix = { u, v, t };

	
	//return rotation matrix.
	return rotation_matrix;
}


Affine2d Affine2d::build_identity()
{
	Affine2d identity;
	const auto number_of_columns = 3; //number of columns
	const auto number_of_rows    = 3; //number of rows

	
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

Affine2d Affine2d::build_scale(float scale_factor)
{
	Affine2d scale;
	const auto number_of_columns = 3; //number of columns
	const auto number_of_rows    = 3; //number of rows

	
	for(auto loop_index1 = 0; loop_index1 < number_of_columns; ++loop_index1)
	{
		for(auto loop_index2 = 0; loop_index2 < number_of_rows; ++loop_index2)
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

Affine2d Affine2d::build_scale(float scale_factor1, float scale_factor2)
{
	auto scale = build_identity();

	
	
	//manually build scale matrix.
	scale(0,0) = scale_factor1;
	scale(1,1) = scale_factor2;
	scale(2,2) = 1.0f;

	
	
	//return builded scale matrix.
	return scale;
}

Affine2d Affine2d::build_affine_translation(float xposition, float yposition)
{
	auto translation = build_identity(); //initialize translatino matrix with identity matrix.
	
	translation[0][2] = xposition;
	translation[1][2] = yposition;
	
	
	//return builded translation matrix.
	return translation;
}

std::ostream& operator<<(std::ostream& input_ostream, Affine2d input_affine)
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
