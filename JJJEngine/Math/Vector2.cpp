/******************************************************************************/
/*!
file name : Vector2.cpp
author    : Jaejun Jang
email     : jjj404001@gmail.com


DigiPen login     : jaejun.jang
Course name       : CS230
Assignment number :#1

term   :Spring 2018
brief  :
    This file contains the function for calculating with veector2.
      
    Functions include:
	in Vector2 struct :
	   + Vector2 operator+(Vector2 input_vector) const; //addition with +
	   + Vector2& operator+=(Vector2 input_vector);	  //addition with +=


       + Vector2 operator-(Vector2 input_vector) const; //subtraction with -
       + Vector2& operator-=(Vector2 input_vector);     //subtraction with -=
    
	
       + Vector2 operator-(void);					  //-(unary prefix)

    
       + Vector2 operator*(float input_float) const; // * for vector to float scaling with Vector2
       + Vector2 operator*(int input_int) const;    // * for vector to int scaling with Vector2

    
       + Vector2& operator*=(float input_float);    // *= vector to float scaling with Vector2
       + Vector2& operator*=(int input_int);        // *= vector to int scaling with Vector2


    
       + Vector2 operator/(float input_float) const; //    * for vector to float dividing with Vector2
       + Vector2 operator/(int input_int) const;     //    * for vector to int dividing with Vector2
       + Vector2& operator/=(float input_float);     //    *= vector to float dividing with Vector2
       + Vector2& operator/=(int input_int);         //    *= vector to int dividing with Vector2
	
       + float operator*(Vector2 input_vector) const;
	 
	non-member normal function :
	   + Vector2 operator*(float input_float,Vector2 input_vector);  //    * for float to vector scaling with Vector2
	   + Vector2 operator*(int input_int,Vector2 input_vector);      //    * for int to vector scaling with Vector2
	   + Vector2 operator*=(float input_float,Vector2 input_vector); //    *= float to vector scaling with Vector2
	   + Vector2 operator*=(int input_int,Vector2 input_vector);     //    *= int to scaling with Vector2



	   + bool operator==(const Vector2 Firstinput_vector, const Vector2 Secondinput_vector); //Determine if two vectors are equal or not.
	   + bool operator!=(const Vector2 Firstinput_vector, const Vector2 Secondinput_vector); //Determine if two vectors are NOT equal or not.


	   + float dot(const Vector2 Firstinput_vector,const Vector2 Secondinput_vector); //Function for testing dot product


	   + Vector2 perpendicular_to(const Vector2 input_vector);//Calculate vector which is perpendicular
															 //from given vector.


	   + Vector2 normalize(Vector2 input_vector); //Normalize given vector
 

	   + float magnitude_of(const Vector2 input_vector);         //Calculate magnitude of given vector.
	   + float squared_magnitude_of(const Vector2 input_vector); //Calculate squared magnitude of given vector.


	   + float distance_between(Vector2 Firstinput_vector, Vector2 Secondinput_vector);         //distance between two vectors.!!TREAT VECTORS AS POINT!!
	   + float distance_between_squared(Vector2 Firstinput_vector, Vector2 Secondinput_vector); //squared distance between two vectors.!!TREAT VECTORS AS POINT!!


	   + float angle_between(Vector2 firstinput_vector, Vector2 secondinput_vector); //Angle between two vectors.

*/
/******************************************************************************/

#include <cmath>
#include "Vector2.hpp"
#include "Matrix2.hpp"


//PI = 3.14...
namespace
{
	const float pi = 4.0f * std::atan(1.0f);
}

Vector2& Vector2::operator=(const Vector2& input_vector)
{
	value[0] = input_vector.value[0];
	value[1] = input_vector.value[1];

	return *this;
}

//+ operator overloading for Vector2.
Vector2 Vector2::operator+(const Vector2 input_vector) const
{
	//add newly created Vector2. which is going to be addition of Vector2.
	const Vector2 result(value[0] + input_vector.value[0], value[1] + input_vector.value[1]);

	//addition of 2 vectors.
	return result;
}
//+= operator overloading for Vector2.
Vector2& Vector2::operator+=(const Vector2 input_vector)
{
	value[0] += input_vector.value[0];
	value[1] += input_vector.value[1];


	//addition of 2 vectors.
	return *this;
}


//-= operator overloading for Vector2
Vector2& Vector2::operator-=(const Vector2 input_vector)
{
	value[0] -= input_vector.value[0];
	value[1] -= input_vector.value[1];


	//subtraction of 2 vectors.
	return *this;
}

//-(subtraction) operator overloading for Vector2
Vector2 Vector2::operator-(const Vector2 input_vector) const
{
	return { value[0] - input_vector.value[0], value[1] - input_vector.value[1] };
}

//-(unary prefix) operator overloading for Vector2
Vector2 Vector2::operator-() const
{
   return {-value[0],-value[1] };
}


//Scaling

template <typename Number>
Vector2 Vector2::operator*(const Number input_float) const
{
	const Vector2 result(value[0] * input_float, value[1] * input_float);


	return result;
}

template <typename Number>
Vector2& Vector2::operator*=(const Number input_int)
{
	value[0] *= input_int;
	value[1] *= input_int;

	return *this;
}

//Dividing
template <typename Number>
Vector2 Vector2::operator/(const Number input_float) const
{
	const Vector2 result(value[0] / input_float, value[1] / input_float);


	return result;
}
    
template <typename Number>
Vector2& Vector2::operator/=(const Number input_int)
{
	value[0] /= input_int;
	value[1] /= input_int;

	return *this;
}

//Dot product. !!not scaling!!
float Vector2::operator*(const Vector2 input_vector) const
{
	//doing dot product.
	const float result = (input_vector.value[0] * value[0]) + (input_vector.value[1] * value[1]);


	return result;
}

Vector2 Vector2::operator*(const Matrix2 input_matrix) const
{
	const Vector2 column0 = { input_matrix.value[0][0], input_matrix.value[1][0] };
	const Vector2 column1 = { input_matrix.value[0][1], input_matrix.value[1][1] };

	return Vector2(*this * column0, *this * column1);
}


//Comparison operator
//Determine if two vectors are equal or not.
bool Vector2::operator==(const Vector2 input_vector) const
{
	//Condition is "if x component of first vector and second vector is equal, and also
	//if y component of first vector and second vector is equal, then return true.
	//else, return false.
	return (value[0] == input_vector.value[0]) && (value[1] == input_vector.value[1]);
}
//Determine if two vectors are NOT equal or not.
bool Vector2::operator!=(const Vector2 input_vector) const
{
	//Condition is "if x component of first vector and second vector is NOT equal, and also
	//if y component of first vector and second vector is NOT equal, then return true.
	//else, return false.
	return (value[0] != input_vector.value[0]) || (value[1] != input_vector.value[1]);
}

//Angle between two vectors.
float Vector2::angle_between(const Vector2 secondinput_vector) const
{
	// angle between two vectors theory
	// angle is
	//         cos a  = |v1| dot product |v2|
	//		            ---------------------(divied by)
	//            (magnitude of v1) * (magnitude of v2)
	// arc-cosine is inverse function of cosine.
	//  so cosine(angle)                           = value of trigonometric function.
	// arc-cosine(value of trigonometric function) = angle. in radian.
	const auto radian = 180.0f / pi;
	auto angle = (*this * secondinput_vector);
	angle /= this->magnitude() * secondinput_vector.magnitude();
	angle = std::acos(angle) * radian; // calculate value of arc cosine and translate it to degree.

	return angle;
}


///////////////////////////////////////////////////////////////////////////////
/////////////////////////non-member normal function.///////////////////////////
///////////////////////////////////////////////////////////////////////////////

//making vector which is perpendicular
//from given vector.
Vector2 Vector2::perpendicular() const
{
	const auto angle = 90 * pi / 180; // 90 degree

	// rotation vector for 90 degree is :
	//		[ 0, -1 ]
	//		[ 1,  0 ]

	//variable for rotation vector
	const Matrix2 rotation_vector = { cosf(angle), -sinf(angle), sinf(angle), cosf(angle) };


	

	return (*this) * rotation_vector;
}

//Calculate magnitude of given vector.
float Vector2::magnitude() const
{
	//Calculate square of magnitude of vector.
	auto magnitude = (value[0] * value[0]) + (value[1] * value[1]);

	//Calculate square root of squared magnitude.
	magnitude = sqrt(magnitude);

	return magnitude;
}

//Calculate squared magnitude of given vector.
float Vector2::squared_magnitude()
{
	//Calculate square of magnitude of vector.
	const auto magnitude = (value[0] * value[0]) + (value[1] * value[1]);


	return magnitude;
}

//Normalize given vector
Vector2 Vector2::normalize()
{
	const auto magnitude = this->magnitude();

	//normalizing vector through dividing by magnitude.
	value[0] /= magnitude;
	value[1] /= magnitude;

	//return normalized input vector.
	return *this;
}

//distance between two vectors.!!TREAT VECTORS AS POINT!!
float Vector2::distance_between(const Vector2 firstinput_vector, const Vector2 secondinput_vector)
{
	//vector for storing calculated value.
	const Vector2 distance_vector(firstinput_vector.value[0] - secondinput_vector.value[0], firstinput_vector.value[1] - secondinput_vector.value[1]);
	

	return distance_vector.magnitude();
}

//squared distance between two vectors.!!TREAT VECTORS AS POINT!!
float Vector2::distance_between_squared(const Vector2 firstinput_vector, const Vector2 secondinput_vector)
{
	return (firstinput_vector.value[0] - secondinput_vector.value[0]) * (firstinput_vector.value[0] - secondinput_vector.value[0]) + (firstinput_vector.value[1] - secondinput_vector.value[1]) * (firstinput_vector.value[1] - secondinput_vector.value[1]);
}


