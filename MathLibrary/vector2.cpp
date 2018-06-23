/******************************************************************************/
/*!
file name : vector2.cpp
author    : Jaejun Jang
email     : jjj404001@gmail.com


DigiPen login     : jaejun.jang
Course name       : CS230
Assignment number :#1

term   :Spring 2018
brief  :
    This file contains the function for calculating with veector2.
      
    Functions include:
	in vector2 struct :
	   + vector2 operator+(vector2 input_vector) const; //addition with +
	   + vector2& operator+=(vector2 input_vector);	  //addition with +=


       + vector2 operator-(vector2 input_vector) const; //subtraction with -
       + vector2& operator-=(vector2 input_vector);     //subtraction with -=
    
	
       + vector2 operator-(void);					  //-(unary prefix)

    
       + vector2 operator*(float input_float) const; // * for vector to float scaling with vector2
       + vector2 operator*(int input_int) const;    // * for vector to int scaling with vector2

    
       + vector2& operator*=(float input_float);    // *= vector to float scaling with vector2
       + vector2& operator*=(int input_int);        // *= vector to int scaling with vector2


    
       + vector2 operator/(float input_float) const; //    * for vector to float dividing with vector2
       + vector2 operator/(int input_int) const;     //    * for vector to int dividing with vector2
       + vector2& operator/=(float input_float);     //    *= vector to float dividing with vector2
       + vector2& operator/=(int input_int);         //    *= vector to int dividing with vector2
	
       + float operator*(vector2 input_vector) const;
	 
	non-member normal function :
	   + vector2 operator*(float input_float,vector2 input_vector);  //    * for float to vector scaling with vector2
	   + vector2 operator*(int input_int,vector2 input_vector);      //    * for int to vector scaling with vector2
	   + vector2 operator*=(float input_float,vector2 input_vector); //    *= float to vector scaling with vector2
	   + vector2 operator*=(int input_int,vector2 input_vector);     //    *= int to scaling with vector2



	   + bool operator==(const vector2 Firstinput_vector, const vector2 Secondinput_vector); //Determine if two vectors are equal or not.
	   + bool operator!=(const vector2 Firstinput_vector, const vector2 Secondinput_vector); //Determine if two vectors are NOT equal or not.


	   + float dot(const vector2 Firstinput_vector,const vector2 Secondinput_vector); //Function for testing dot product


	   + vector2 perpendicular_to(const vector2 input_vector);//Calculate vector which is perpendicular
															 //from given vector.


	   + vector2 normalize(vector2 input_vector); //Normalize given vector
 

	   + float magnitude_of(const vector2 input_vector);         //Calculate magnitude of given vector.
	   + float squared_magnitude_of(const vector2 input_vector); //Calculate squared magnitude of given vector.


	   + float distance_between(vector2 Firstinput_vector, vector2 Secondinput_vector);         //distance between two vectors.!!TREAT VECTORS AS POINT!!
	   + float distance_between_squared(vector2 Firstinput_vector, vector2 Secondinput_vector); //squared distance between two vectors.!!TREAT VECTORS AS POINT!!


	   + float angle_between(vector2 firstinput_vector, vector2 secondinput_vector); //Angle between two vectors.

*/
/******************************************************************************/

#include <cmath>
#include "vector2.hpp"


//PI = 3.14...
namespace
{
	const float pi = 4.0f * std::atan(1.0f);
}

//+ operator overloading for vector2.
vector2 vector2::operator+(const vector2 input_vector) const
{
	//add newly created vector2. which is going to be addition of vector2.
	vector2 result(x,y);


	result.x += input_vector.x;
	result.y += input_vector.y;


	//addition of 2 vectors.
	return result;
}
//+= operator overloading for vector2.
vector2& vector2::operator+=(const vector2 input_vector)
{
	x += input_vector.x;
	y += input_vector.y;


	//addition of 2 vectors.
	return *this;
}


//-= operator overloading for vector2
vector2& vector2::operator-=(const vector2 input_vector)
{
    x -= input_vector.x;
    y -= input_vector.y;


	//subtraction of 2 vectors.
	return *this;
}

//-(subtraction) operator overloading for vector2
vector2 vector2::operator-(const vector2 input_vector) const
{
	return { x - input_vector.x, y - input_vector.y };
}

//-(unary prefix) operator overloading for vector2
vector2 vector2::operator-(void) const
{
   return {-x,-y};
}


//Scaling

//* operator overloading for vector2 with float
vector2 vector2::operator*(const float input_float) const
{
	vector2 result(x,y);

	result.x *= input_float;
	result.y *= input_float;

	return result;
}

//* operator overloading for vector2 with int
vector2 vector2::operator*(const int input_int) const
{
	vector2 result(x,y);

	result.x *= input_int;
	result.y *= input_int;

	return result;
}

// *= operator overloading for vector2 with float
vector2& vector2::operator*=(const float input_float)
{
	x *= input_float;
	y *= input_float;

	return *this;
}

// *= operator overloading for vector2 with int
vector2& vector2::operator*=(const int input_int)
{
	x *= input_int;
	y *= input_int;

	return *this;
}

//Dividing
//  / for vector to float dividing with vector2
vector2 vector2::operator/(const float input_float) const
{
	vector2 result(x,y);

	result.x /= input_float;
	result.y /= input_float;

	return result;
}

//  / for vector to int dividing with vector2
vector2 vector2::operator/(const int input_int) const
{
	vector2 result(x,y);

	result.x /= input_int;
	result.y /= input_int;

	return result;
}

//  /= vector to float dividing with vector2
vector2& vector2::operator/=(const float input_float)
{
	x /= input_float;
	y /= input_float;

	return *this;
}
    
//  /= vector to int dividing with vector2
vector2& vector2::operator/=(const int input_int)
{
	x /= input_int;
	y /= input_int;

	return *this;
}

//Dot product. !!not scaling!!
float vector2::operator*(const vector2 input_vector) const
{
	//doing dot product.
	const float result = (input_vector.x * x) + (input_vector.y * y); 


	return result;
}



//Comparison operator
//Determine if two vectors are equal or not.
bool vector2::operator==(const vector2 input_vector) const
{
	//Condition is "if x component of first vector and second vector is equal, and also
	//if y component of first vector and second vector is equal, then return true.
	//else, return false.
	return (x == input_vector.x) && (y == input_vector.y);
}
//Determine if two vectors are NOT equal or not.
bool vector2::operator!=(const vector2 input_vector) const
{
	//Condition is "if x component of first vector and second vector is NOT equal, and also
	//if y component of first vector and second vector is NOT equal, then return true.
	//else, return false.
	return (x != input_vector.x) || (y != input_vector.y);
}



///////////////////////////////////////////////////////////////////////////////
/////////////////////////non-member normal function.///////////////////////////
///////////////////////////////////////////////////////////////////////////////
//Scaling
//* for float to vector scaling with vector2
vector2 operator*(const float input_float, const vector2 input_vector)
{
	vector2 result;

	result.x = input_float * input_vector.x;
	result.y = input_float * input_vector.y;

	return result;
}

//* for int to vector scaling with vector2
vector2 operator*(const int input_int, const vector2 input_vector)
{
	vector2 result;

	result.x = input_int * input_vector.x;
	result.y = input_int * input_vector.y;

	return result;
}

//Dividing
//    / for vector to float dividing with vector2
vector2 operator/(const float input_float, vector2 input_vector)
{
	vector2 result;

	result.x = input_vector.x / input_float;
	result.y = input_vector.y / input_float;

	return result;
}

//    /* for vector to int dividing with vector2
vector2 operator/(const int input_int, vector2 input_vector)
{
	vector2 result;

	result.x = input_vector.x / input_int;
	result.y = input_vector.y / input_int;

	return result;
}



//Function for testing dot product

float dot(const vector2 firstinput_vector, const vector2 secondinput_vector)
{
	return ((firstinput_vector.x * secondinput_vector.x) + (firstinput_vector.y * secondinput_vector.y));
}


//making vector which is perpendicular
//from given vector.
vector2 perpendicular_to(const vector2 input_vector)
{
	//vector that perpendicular to Input Vector
	vector2 result;
	const auto angle = 90 * pi / 180; // 90 degree

	// rotation vector for 90 degree is :
	//		[ 0, -1 ]
	//		[ 1,  0 ]

	//enumeration for rotation vector.
	enum{
		x1,y1,x2,y2
	};


	//variable for rotation vector
	float rotation_vector[4] = { cosf(angle), -sinf(angle), sinf(angle), cosf(angle) };
	//float rotationVector[4] = { 0, -1, 1, 0 };
	result.x = (rotation_vector[x1] * input_vector.x + rotation_vector[y1] * input_vector.y);
	result.y = (rotation_vector[x2] * input_vector.x + rotation_vector[y2] * input_vector.y);

	return result;
}

//Calculate magnitude of given vector.
float magnitude_of(const vector2 input_vector)
{
	//Calculate square of magnitude of vector.
	auto magnitude = (input_vector.x * input_vector.x) + (input_vector.y * input_vector.y);

	//Calculate square root of squared magnitude.
	magnitude = sqrt(magnitude);

	return magnitude;
}

//Calculate squared magnitude of given vector.
float squared_magnitude_of(const vector2 input_vector)
{
	//Calculate square of magnitude of vector.
	const auto magnitude = (input_vector.x * input_vector.x) + (input_vector.y * input_vector.y);


	return magnitude;
}

//Normalize given vector
vector2 normalize(vector2 input_vector)
{
	const auto magnitude = magnitude_of(input_vector);

	//normalizing vector through dividing by magnitude.
	input_vector.x /= magnitude;
	input_vector.y /= magnitude;

	//return normalized input vector.
	return input_vector;
}

//distance between two vectors.!!TREAT VECTORS AS POINT!!
float distance_between(const vector2 firstinput_vector, const vector2 secondinput_vector)
{
	//vector for storing calculated value.
	vector2 distance_vector;
	
	//storing Firstinput_vector - Secondinput_vector
	distance_vector.x = firstinput_vector.x - secondinput_vector.x;
	distance_vector.y = firstinput_vector.y - secondinput_vector.y;

	return magnitude_of(distance_vector);
}

//squared distance between two vectors.!!TREAT VECTORS AS POINT!!
float distance_between_squared(const vector2 firstinput_vector, const vector2 secondinput_vector)
{
	return (firstinput_vector.x - secondinput_vector.x) * (firstinput_vector.x - secondinput_vector.x) + (firstinput_vector.y - secondinput_vector.y) * (firstinput_vector.y - secondinput_vector.y);
}

//Angle between two vectors.
float angle_between(const vector2 firstinput_vector, const vector2 secondinput_vector)
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
	auto angle = dot(firstinput_vector, secondinput_vector);
	angle /= magnitude_of(firstinput_vector) * magnitude_of(secondinput_vector);
	angle  = std::acos(angle) * radian; // calculate value of arc cosine and translate it to degree.

	return angle;
}

