/******************************************************************************/
/*!
file name : Vector4.hpp
author    : Jaejun Jang
email     : jjj404001@gmail.com


DigiPen login     : jaejun.jang
Course name       : CS230
Assignment number :#1

term   :Spring 2018
brief  :
This file contains the function prototypes and struct Vector4 using for calculating with matrix.

Functions include:
in Vector4 struct :
+ Vector4 operator+(Vector4 InputVector) const; //addition with +
+ Vector4& operator+=(Vector4 InputVector);	  //addition with +=

+ Vector4 operator-(Vector4 InputVector) const; //subtraction with -
+ Vector4& operator-=(Vector4 InputVector);	  //subtraction with -=
+ Vector4 operator-(void);					  //unary prefix


+ Vector4 operator*(float InputFloat) const; //    * for vector to float scaling with Vector4
+ Vector4 operator*(int InputInt) const;     //    * for vector to int scaling with Vector4
+ Vector4& operator*=(float InputFloat);     //    *= vector to float scaling with Vector4
+ Vector4& operator*=(int InputInt);         //    *= vector to int scaling with Vector4


+  operator/(float InputFloat) const;//    * for vector to float dividing with Vector4
+ Vector4 operator/(int InputInt) const;    //    * for vector to int dividing with Vector4
+ Vector4& operator/=(float InputFloat);    //    *= vector to float dividing with Vector4
+ Vector4& operator/=(int InputInt);        //    *= vector to int dividing with Vector4




+ float operator*(Vector4 InputVector) const; //Dot product. !!not scaling!!

non-member normal function :
+ Vector4 operator*(float InputFloat,Vector4 InputVector);  //    * for float to vector scaling with Vector4
+ Vector4 operator*(int InputInt,Vector4 InputVector);      //    * for int to vector scaling with Vector4
+ Vector4 operator*=(float InputFloat,Vector4 InputVector); //    *= float to vector scaling with Vector4
+ Vector4 operator*=(int InputInt,Vector4 InputVector);     //    *= int to scaling with Vector4

+ bool operator==(const Vector4 FirstInputVector, const Vector4 SecondInputVector); //Determine if two vectors are equal or not.

+ bool operator!=(const Vector4 FirstInputVector, const Vector4 SecondInputVector); //Determine if two vectors are NOT equal or not.


+ float dot(const Vector4 FirstInputVector,const Vector4 SecondInputVector);     //Function for dot product
+ Vector4 cross(const Vector4 FirstInputVector,const Vector4 SecondInputVector); //Function for cross product


+ Vector4 perpendicular_to(const Vector4 InputVector);//Calculate vector which is perpendicular
//from given vector.


+ float magnitude_of(const Vector4 InputVector);          //Calculate magnitude of given vector.
+ float squared_magnitude_of(const Vector4 InputVector); //Calculate squared magnitude of given vector.


+ Vector4 normalize(Vector4 InputVector); //Normalize given vector


+ float distance_between(Vector4 FirstInputVector, Vector4 SecondInputVector);         //distance between two vectors.!!TREAT VECTORS AS POINT!!
+ float distance_between_squared(Vector4 FirstInputVector, Vector4 SecondInputVector); //squared distance between two vectors.!!TREAT VECTORS AS POINT!!


+ float angle_between(Vector4 firstInputVector, Vector4 secondInputVector); //Angle between two vectors.

*/
/******************************************************************************/
#pragma once


struct Vector4
{
	float value[4]{ 0, };
	const float& x = value[0];
	const float& y = value[1];
	const float& z = value[2];
	const float& w = value[3];

	//constructor for Vector4 initialization
	Vector4() = default;

	Vector4(float InitX, float InitY, float InitZ, float InitW)
	{
		value[0] = InitX;
		value[1] = InitY;
		value[2] = InitZ;
		value[3] = InitW;
	}

	//addition

	Vector4 operator+(Vector4 InputVector) const; //addition with +
	Vector4& operator+=(Vector4 InputVector); //addition with +=

											  //subtraction
	Vector4 operator-(Vector4 InputVector) const; //subtraction with -
	Vector4& operator-=(Vector4 InputVector); //subtraction with -=
	Vector4 operator-(); //unary prefix


						 //Scaling
	template <typename Number>
	Vector4 operator*(Number Input) const; //    * for vector to float scaling with Vector4=
	template <typename Number>
	Vector4& operator*=(Number Input); //    *= vector to int scaling with Vector4


									   //Dividing
	template <typename Number>
	Vector4 operator/(Number Input) const; //    * for vector to float dividing with Vector4
	template <typename Number>
	Vector4& operator/=(Number input); //    *= vector to int dividing with Vector4


									   //Dot product. !!not scaling!!
	float operator*(Vector4 input_vector) const;

	static Vector4 cross(Vector4 first_input_vector, Vector4 second_input_vector); //Function for cross product


	bool operator==(Vector4 first_input_vector) const; //Determine if two vectors are equal or not.
	bool operator!=(Vector4 first_input_vector) const; //Determine if two vectors are NOT equal or not.


	float magnitude() const; //Calculate magnitude of given vector.
	float squared_magnitude() const; //Calculate squared magnitude of given vector.


	Vector4 normalize(); //Normalize given vector


	float distance_between(Vector4 second_input_vector) const; //distance between two vectors.!!TREAT VECTORS AS POINT!!
	float distance_between_squared(Vector4 second_input_vector) const;
	//squared distance between two vectors.!!TREAT VECTORS AS POINT!!


	float angle_between(Vector4 second_input_vector) const; //Angle between two vectors.
};