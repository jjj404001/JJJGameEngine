/******************************************************************************/
/*!
file name : Vector3.cpp
author    : Jaejun Jang
email     : jjj404001@gmail.com


DigiPen login     : jaejun.jang
Course name       : CS230
Assignment number :#1

term   :Spring 2018
brief  :
    This file contains the function using for calculating with matrix.
      
    Functions include:
	in Vector3 struct :
	   + Vector3 operator+(Vector3 InputVector) const; //addition with +
	   + Vector3& operator+=(Vector3 InputVector);	  //addition with +=

       + Vector3 operator-(Vector3 InputVector) const; //subtraction with -
       + Vector3& operator-=(Vector3 InputVector);	  //subtraction with -=
       + Vector3 operator-(void);					  //unary prefix

	   
       + Vector3 operator*(float InputFloat) const; //    * for vector to float scaling with Vector3
       + Vector3 operator*(int InputInt) const;     //    * for vector to int scaling with Vector3
       + Vector3& operator*=(float InputFloat);     //    *= vector to float scaling with Vector3
       + Vector3& operator*=(int InputInt);         //    *= vector to int scaling with Vector3


       +  operator/(float InputFloat) const;//    * for vector to float dividing with Vector3
       + Vector3 operator/(int InputInt) const;    //    * for vector to int dividing with Vector3
       + Vector3& operator/=(float InputFloat);    //    *= vector to float dividing with Vector3
       + Vector3& operator/=(int InputInt);        //    *= vector to int dividing with Vector3



    
       + float operator*(Vector3 InputVector) const; //Dot product. !!not scaling!!
 
	non-member normal function :
	   + Vector3 operator*(float InputFloat,Vector3 InputVector);  //    * for float to vector scaling with Vector3
	   + Vector3 operator*(int InputInt,Vector3 InputVector);      //    * for int to vector scaling with Vector3
	   + Vector3 operator*=(float InputFloat,Vector3 InputVector); //    *= float to vector scaling with Vector3
	   + Vector3 operator*=(int InputInt,Vector3 InputVector);     //    *= int to scaling with Vector3

	   + bool operator==(const Vector3 FirstInputVector, const Vector3 SecondInputVector); //Determine if two vectors are equal or not.

	   + bool operator!=(const Vector3 FirstInputVector, const Vector3 SecondInputVector); //Determine if two vectors are NOT equal or not.


	   + float dot(const Vector3 FirstInputVector,const Vector3 SecondInputVector);     //Function for dot product
	   + Vector3 cross(const Vector3 FirstInputVector,const Vector3 SecondInputVector); //Function for cross product


	   + Vector3 perpendicular_to(const Vector3 InputVector);//Calculate vector which is perpendicular
															 //from given vector.


	   + float magnitude_of(const Vector3 InputVector);          //Calculate magnitude of given vector.
	   + float squared_magnitude_of(const Vector3 InputVector); //Calculate squared magnitude of given vector.


	   + Vector3 normalize(Vector3 InputVector); //Normalize given vector


	   + float distance_between(Vector3 FirstInputVector, Vector3 SecondInputVector);         //distance between two vectors.!!TREAT VECTORS AS POINT!!
	   + float distance_between_squared(Vector3 FirstInputVector, Vector3 SecondInputVector); //squared distance between two vectors.!!TREAT VECTORS AS POINT!!


	   + float angle_between(Vector3 firstInputVector, Vector3 secondInputVector); //Angle between two vectors.

*/
/******************************************************************************/

#include <cmath>
#include "Vector3.hpp"


namespace
{
	const float PI = 4.0f * std::atan(1.0f);
}

//+ operator overloading for Vector3.
Vector3 Vector3::operator+(Vector3 InputVector) const
{
	//add newly created Vector3. which is going to be addition of Vector3.
	Vector3 result(x,y,z);


	result.x += InputVector.x;
	result.y += InputVector.y;
    result.z += InputVector.z;


	//addition of 2 vectors.
	return result;
}
//+= operator overloading for Vector3.
Vector3& Vector3::operator+=(Vector3 InputVector)
{
	x += InputVector.x;
	y += InputVector.y;
    z += InputVector.z;

	//addition of 2 vectors.
	return *this;
}


//-= operator overloading for Vector3
Vector3& Vector3::operator-=(Vector3 InputVector)
{
    x -= InputVector.x;
    y -= InputVector.y;
    z -= InputVector.z;


	//subtraction of 2 vectors.
	return *this;
}

//-(subtraction) operator overloading for Vector3
Vector3 Vector3::operator-(Vector3 InputVector) const
{
    Vector3 result(x,y,z);

    result.x = InputVector.x;
    result.y = InputVector.y;
    result.z = InputVector.z;
    //add newly created Vector3. which is addition of Vector3.
    return result;
}

//-(unary prefix) operator overloading for Vector3
Vector3 Vector3::operator-(void)
{
	x = -x;
	y = -y;
    z = -z;


   return Vector3(x,y,z);
}


//Scaling

//* operator overloading for Vector3 with float
Vector3 Vector3::operator*(float InputFloat) const
{
	Vector3 result(x,y,z);

	result.x *= InputFloat;
	result.y *= InputFloat;
    result.z *= InputFloat;


	return result;
}

//* operator overloading for Vector3 with int
Vector3 Vector3::operator*(int InputInt) const
{
	Vector3 result(x,y,z);

	result.x *= InputInt;
	result.y *= InputInt;
    result.z *= InputInt;

	return result;
}

// *= operator overloading for Vector3 with float
Vector3& Vector3::operator*=(float InputFloat)
{
	x *= InputFloat;
	y *= InputFloat;
    z *= InputFloat;

	return *this;
}

// *= operator overloading for Vector3 with int
Vector3& Vector3::operator*=(int InputInt)
{
	x *= InputInt;
	y *= InputInt;
    z *= InputInt;

	return *this;
}

//Dividing
//  / for vector to float dividing with Vector3
Vector3 Vector3::operator/(float InputFloat) const
{
	Vector3 result(x,y,z);

	result.x /= InputFloat;
	result.y /= InputFloat;
    result.z /= InputFloat;

	return result;
}

//  / for vector to int dividing with Vector3
Vector3 Vector3::operator/(int InputInt) const
{
	Vector3 result(x,y,z);

	result.x /= InputInt;
	result.y /= InputInt;
    result.z /= InputInt;

	return result;
}

//  /= vector to float dividing with Vector3
Vector3& Vector3::operator/=(float InputFloat)
{
	x /= InputFloat;
	y /= InputFloat;
    z /= InputFloat;

	return *this;
}
    
//  /= vector to int dividing with Vector3
Vector3& Vector3::operator/=(int InputInt)
{
	x /= InputInt;
	y /= InputInt;
    z /= InputInt;

	return *this;
}


//Dot product. !!not scaling!!
float Vector3::operator*(Vector3 InputVector) const
{
	//doing dot product.
	float result = (InputVector.x * x) + (InputVector.y * y) + (InputVector.z * z); 


	return result;
}






///////////////////////////////////////////////////////////////////////////////
/////////////////////////non-member normal function.///////////////////////////
///////////////////////////////////////////////////////////////////////////////
//Scaling
//* for float to vector scaling with Vector3
Vector3 operator*(const float InputFloat,const Vector3 InputVector)
{
	Vector3 result;

	result.x = InputFloat * InputVector.x;
	result.y = InputFloat * InputVector.y;
    result.z = InputFloat * InputVector.z;

	return result;
}

//* for int to vector scaling with Vector3
Vector3 operator*(const int InputInt,const Vector3 InputVector)
{
	Vector3 result;

	result.x = InputInt * InputVector.x;
	result.y = InputInt * InputVector.y;
    result.z = InputInt * InputVector.z;

	return result;
}

//*= float to vector scaling with Vector3
Vector3 operator*=(float InputFloat,Vector3 InputVector)
{
	return Vector3(InputFloat * InputVector.x, InputFloat * InputVector.y, InputFloat * InputVector.z);
}
    
//*= int to scaling with Vector3
Vector3 operator*=(int InputInt,Vector3 InputVector)
{
	return Vector3(InputInt * InputVector.x, InputInt * InputVector.y, InputInt * InputVector.z);
}



//Dividing
//    / for vector to float dividing with Vector3
Vector3 operator/(const float InputFloat, Vector3 InputVector)
{
	Vector3 result;

	result.x = InputVector.x / InputFloat;
	result.y = InputVector.y / InputFloat;
    result.z = InputVector.z / InputFloat;

	return result;
}

//    /* for vector to int dividing with Vector3
Vector3 operator/(const int InputInt, Vector3 InputVector)
{
	Vector3 result;

	result.x = InputVector.x / InputInt;
	result.y = InputVector.y / InputInt;
    result.z = InputVector.z / InputInt;

	return result;
}

//Comparison operator
//Determine if two vectors are equal or not.
bool operator==(const Vector3 FirstInputVector, const Vector3 SecondInputVector)
{
	//Condition is "if x component of first vector and second vector is equal, and also
	//if y component of first vector and second vector is equal, then return true.
	//else, return false.

	const bool both_vectors_are_equal = (FirstInputVector.x == SecondInputVector.x)
                               && (FirstInputVector.y == SecondInputVector.y)
                               && (FirstInputVector.z == SecondInputVector.z);


	return both_vectors_are_equal;
}
//Determine if two vectors are NOT equal or not.
bool operator!=(const Vector3 FirstInputVector, const Vector3 SecondInputVector)
{
	//Condition is "if x component of first vector and second vector is NOT equal, and also
	//if y component of first vector and second vector is NOT equal, then return true.
	//else, return false.

	const auto both_vectors_are_not_equal = (FirstInputVector.x != SecondInputVector.x)
                                   || (FirstInputVector.y != SecondInputVector.y)
                                   || (FirstInputVector.z != SecondInputVector.z);

	return both_vectors_are_not_equal;
}

//Function for cross product
Vector3 Vector3::cross(const Vector3 first_input_vector,const Vector3 second_input_vector)
{
	const Vector3 result = { (first_input_vector.x * second_input_vector.y) - (first_input_vector.y * second_input_vector.x),
					   (first_input_vector.y * second_input_vector.z) - (first_input_vector.z * second_input_vector.y),
					   (first_input_vector.z * second_input_vector.x) - (first_input_vector.x * second_input_vector.z)};
	
	
	return result;
}


//Calculate magnitude of given vector.
float magnitude_of(const Vector3 InputVector)
{
	float magnitude;

	//Calculate square of magnitude of vector.
	magnitude =  (InputVector.x * InputVector.x);
    magnitude += (InputVector.y * InputVector.y);
    magnitude += (InputVector.z * InputVector.z);

	//Calculate square root of squared magnitude.
	magnitude = sqrt(magnitude);


	return magnitude;
}

//Calculate squared magnitude of given vector.
float squared_magnitude_of(const Vector3 InputVector)
{
	float magnitude;

	//Calculate square of magnitude of vector.
	magnitude =  (InputVector.x * InputVector.x);
    magnitude += (InputVector.y * InputVector.y);
    magnitude += (InputVector.z * InputVector.z);


	return magnitude;
}

//Normalize given vector
Vector3 normalize(Vector3 InputVector)
{
	float magnitude = magnitude_of(InputVector);

	//normalizing vector through dividing by magnitude.
	InputVector.x /= magnitude;
	InputVector.y /= magnitude;
    InputVector.z /= magnitude;

	//return normalized input vector.
	return InputVector;
}

//distance between two vectors.!!TREAT VECTORS AS POINT!!
float distance_between(Vector3 FirstInputVector, Vector3 SecondInputVector)
{
	//vector for storing calculated value.
	Vector3 distanceVector = { 0, 0, 0 };
	
	//storing FirstInputVector - SecondInputVector
	distanceVector.x = FirstInputVector.x - SecondInputVector.x;
	distanceVector.y = FirstInputVector.y - SecondInputVector.y;
    distanceVector.z = FirstInputVector.z - SecondInputVector.z;



	return magnitude_of(distanceVector);
}

//squared distance between two vectors.!!TREAT VECTORS AS POINT!!
float distance_between_squared(Vector3 FirstInputVector, Vector3 SecondInputVector)
{
	//vector for storing calculated value.

	Vector3 distanceVector = { 0, 0, 0 };

	//storing FirstInputVector - SecondInputVector
	
    

	distanceVector.x = FirstInputVector.x - SecondInputVector.x;
	distanceVector.y = FirstInputVector.y - SecondInputVector.y;
    distanceVector.z = FirstInputVector.z - SecondInputVector.z;



	return squared_magnitude_of(distanceVector);
}

//Angle between two vectors.
float angle_between(Vector3 firstInputVector, Vector3 secondInputVector)
{
	float angle  = 0; //variable for storing angle.
	float radian = 180.0f / PI;

	// angle between two vectors theory
	// angle is
	//         cos a  = |v1| dot product |v2|
	//		            ---------------------(divied by)
	//            (magnitude of v1) * (magnitude of v2)
	// arc-cosine is inverse function of cosine.
	//  so cosine(angle)                           = value of trigonometric function.
	// arc-cosine(value of trigonometric function) = angle. in radian.

	angle  = firstInputVector * secondInputVector;
	angle /= magnitude_of(firstInputVector) * magnitude_of(secondInputVector);
	angle  = std::acos(angle) * radian; // calculate value of arc cosine and translate it to degree.

	return angle;
}