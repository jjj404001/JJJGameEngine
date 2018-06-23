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
#include "Vector3.hpp"
#include "Constant.h"



//+ operator overloading for Vector3.
Vector3 Vector3::operator+(Vector3 InputVector) const
{
	//add newly created Vector3. which is going to be addition of Vector3.
	Vector3 result(x,y,z);


	result += InputVector;



	//addition of 2 vectors.
	return result;
}
//+= operator overloading for Vector3.
Vector3& Vector3::operator+=(Vector3 InputVector)
{
	value[0] += InputVector.x;
	value[1] += InputVector.y;
	value[2] += InputVector.z;

	//addition of 2 vectors.
	return *this;
}


//-= operator overloading for Vector3
Vector3& Vector3::operator-=(Vector3 InputVector)
{
	value[0] -= InputVector.x;
	value[1] -= InputVector.y;
	value[2] -= InputVector.z;


	//subtraction of 2 vectors.
	return *this;
}

//-(subtraction) operator overloading for Vector3
Vector3 Vector3::operator-(Vector3 InputVector) const
{
    Vector3 result(x,y,z);

	result -= InputVector;

    //add newly created Vector3. which is addition of Vector3.
    return result;
}

//-(unary prefix) operator overloading for Vector3
Vector3 Vector3::operator-()
{
	value[0] = -value[0];
	value[1] = -value[1];
	value[2] = -value[2];


   return {x,y,z};
}


//Scaling

//* operator overloading for Vector3 with float
template<typename Number>
Vector3 Vector3::operator*(Number Input) const
{
	Vector3 result(x * Input, y * Input, z * Input);

	return result;
}
// *= operator overloading for Vector3 with int
template<typename Number>
Vector3& Vector3::operator*=(Number Input)
{
	x *= Input;
	y *= Input;
    z *= Input;

	return *this;
}

//Dividing
//  / for vector to float dividing with Vector3
template<typename Number>
Vector3 Vector3::operator/(Number Input) const
{
	Vector3 result(x,y,z);

	result.x /= Input;
	result.y /= Input;
    result.z /= Input;

	return result;
}
    
//  /= vector to int dividing with Vector3
template<typename Number>
Vector3& Vector3::operator/=(Number input)
{
	value[0] /= input;
	value[1] /= input;
	value[2] /= input;

	return *this;
}


//Dot product. !!not scaling!!
float Vector3::operator*(const Vector3 input_vector) const
{
	//doing dot product.
	const auto result = (input_vector.x * x) + (input_vector.y * y) + (input_vector.z * z); 


	return result;
}



//Comparison operator
//Determine if two vectors are equal or not.
bool Vector3::operator==(const Vector3 first_input_vector) const
{
	//Condition is "if x component of first vector and second vector is equal, and also
	//if y component of first vector and second vector is equal, then return true.
	//else, return false.

	const auto both_vectors_are_equal = (first_input_vector.x == this->x)
		&& (first_input_vector.y == this->y)
		&& (first_input_vector.z == this->z);


	return both_vectors_are_equal;
}
//Determine if two vectors are NOT equal or not.
bool Vector3::operator!=(const Vector3 FirstInputVector) const
{
	//Condition is "if x component of first vector and second vector is NOT equal, and also
	//if y component of first vector and second vector is NOT equal, then return true.
	//else, return false.

	const auto both_vectors_are_not_equal = (FirstInputVector.x != this->x)
		|| (FirstInputVector.y != this->y)
		|| (FirstInputVector.z != this->z);

	return both_vectors_are_not_equal;
}


///////////////////////////////////////////////////////////////////////////////
/////////////////////////non-member normal function.///////////////////////////
///////////////////////////////////////////////////////////////////////////////



//Function for cross product
Vector3 Vector3::cross(const Vector3 first_input_vector,const Vector3 second_input_vector)
{
	const Vector3 result = { (first_input_vector.x * second_input_vector.y) - (first_input_vector.y * second_input_vector.x),
					   (first_input_vector.y * second_input_vector.z) - (first_input_vector.z * second_input_vector.y),
					   (first_input_vector.z * second_input_vector.x) - (first_input_vector.x * second_input_vector.z)};
	
	
	return result;
}


//Calculate magnitude of given vector.
float Vector3::magnitude() const
{
	//Calculate square of magnitude of vector.
	float magnitude = squared_magnitude();

	//Calculate square root of squared magnitude.
	magnitude = sqrt(magnitude);


	return magnitude;
}

//Calculate squared magnitude of given vector.
float Vector3::squared_magnitude() const
{
	//Calculate square of magnitude of vector.
	const auto magnitude = (x * x) + (y * y) + (z * z);


	return magnitude;
}

//Normalize given vector
Vector3 Vector3::normalize()
{
	const auto magnitude = this->magnitude();

	//normalizing vector through dividing by magnitude.
	*this /= magnitude;


	//return normalized input vector.
	return *this;
}

//distance between two vectors.!!TREAT VECTORS AS POINT!!
float Vector3::distance_between(Vector3 SecondInputVector) const
{
	//vector for storing calculated value.
	Vector3 distanceVector = { 0, 0, 0 };
	
	//storing FirstInputVector - SecondInputVector
	distanceVector.value[0] = this->x - SecondInputVector.x;
	distanceVector.value[1] = this->y - SecondInputVector.y;
    distanceVector.value[2] = this->z - SecondInputVector.z;



	return distanceVector.magnitude();
}

//squared distance between two vectors.!!TREAT VECTORS AS POINT!!
float Vector3::distance_between_squared(const Vector3 second_input_vector) const
{
	//vector for storing calculated value.

	Vector3 distanceVector = { 0, 0, 0 };

	//storing FirstInputVector - SecondInputVector
	
    

	distanceVector.value[0] = this->x - second_input_vector.x;
	distanceVector.value[1] = this->y - second_input_vector.y;
    distanceVector.value[2] = this->z - second_input_vector.z;



	return distanceVector.squared_magnitude();
}

//Angle between two vectors.
float Vector3::angle_between(Vector3 second_input_vector) const
{
	

	// angle between two vectors theory
	// angle is
	//         cos a  = |v1| dot product |v2|
	//		            ---------------------(divied by)
	//            (magnitude of v1) * (magnitude of v2)
	// arc-cosine is inverse function of cosine.
	//  so cosine(angle)                           = value of trigonometric function.
	// arc-cosine(value of trigonometric function) = angle. in radian.

	float angle = *this * second_input_vector;
	angle /= this->magnitude() * second_input_vector.magnitude();
	angle  = std::acos(angle)  * Math::RADIAN; // calculate value of arc cosine and translate it to degree.

	return angle;
}
