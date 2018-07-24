/******************************************************************************/
/*!
file name : Vector3.hpp
author    : Jaejun Jang
email     : jjj404001@gmail.com


DigiPen login     : jaejun.jang
Course name       : CS230
Assignment number :#1

term   :Spring 2018
brief  :
    This file contains the function prototypes and struct Vector3 using for calculating with matrix.
      
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
#pragma once


struct Vector3
{
	float value[3]{0,};
	float& x = value[0];
	float& y = value[1];
	float& z = value[2];

	//constructor for Vector3 initialization
	Vector3() = default;

	Vector3(float InitX, float InitY, float InitZ)
	{
		value[0] = InitX;
		value[1] = InitY;
		value[2] = InitZ;
	}

	Vector3& operator=(const Vector3& InputVector);

	//addition

	Vector3 operator+(Vector3 InputVector) const; //addition with +
	Vector3& operator+=(Vector3 InputVector); //addition with +=

	//subtraction
	Vector3 operator-(Vector3 InputVector) const; //subtraction with -
	Vector3& operator-=(Vector3 InputVector); //subtraction with -=
	Vector3 operator-(); //unary prefix


	//Scaling
	template <typename Number>
	Vector3 operator*(Number Input) const //    * for vector to float scaling with Vector3=
	{
		Vector3 result(x * Input, y * Input, z * Input);

		return result;
	}
	template <typename Number>
	Vector3& operator*=(Number Input) //    *= vector to int scaling with Vector3
	{
		x *= Input;
		y *= Input;
		z *= Input;

		return *this;
	}


	//Dividing
	template <typename Number>
	Vector3 operator/(Number Input) const; //    * for vector to float dividing with Vector3
	template <typename Number>
	Vector3& operator/=(Number input); //    *= vector to int dividing with Vector3


	//Dot product. !!not scaling!!
	float operator*(Vector3 input_vector) const;

	static Vector3 cross(Vector3 first_input_vector, Vector3 second_input_vector); //Function for cross product


	//Comparison operator

	bool operator==(Vector3 first_input_vector) const; //Determine if two vectors are equal or not.
	bool operator!=(Vector3 first_input_vector) const; //Determine if two vectors are NOT equal or not.


	float magnitude() const; //Calculate magnitude of given vector.
	float squared_magnitude() const; //Calculate squared magnitude of given vector.


	Vector3 normalize(); //Normalize given vector


	float distance_between(Vector3 second_input_vector) const; //distance between two vectors.!!TREAT VECTORS AS POINT!!
	float distance_between_squared(Vector3 second_input_vector) const;
	//squared distance between two vectors.!!TREAT VECTORS AS POINT!!


	float angle_between(Vector3 second_input_vector) const; //Angle between two vectors.
};