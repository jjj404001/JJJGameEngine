/******************************************************************************/
/*!
file name : Vector2.hpp
author    : Jaejun Jang
email     : jjj404001@gmail.com


DigiPen login     : jaejun.jang
Course name       : CS230
Assignment number :#1

term   :Spring 2018
brief  :
    This file contains the function prototype and struct Vector2 for calculating with veector2.
      
    Functions include:
	in Vector2 struct :
	   + Vector2 operator+(Vector2 InputVector) const; //addition with +
	   + Vector2& operator+=(Vector2 InputVector);	  //addition with +=


       + Vector2 operator-(Vector2 InputVector) const; //subtraction with -
       + Vector2& operator-=(Vector2 InputVector);     //subtraction with -=
    
	
       + Vector2 operator-(void);					  //-(unary prefix)

    
       + Vector2 operator*(float InputFloat) const; // * for vector to float scaling with Vector2
       + Vector2 operator*(int InputInt) const;    // * for vector to int scaling with Vector2

    
       + Vector2& operator*=(float InputFloat);    // *= vector to float scaling with Vector2
       + Vector2& operator*=(int InputInt);        // *= vector to int scaling with Vector2


    
       + Vector2 operator/(float InputFloat) const; //    * for vector to float dividing with Vector2
       + Vector2 operator/(int InputInt) const;     //    * for vector to int dividing with Vector2
       + Vector2& operator/=(float InputFloat);     //    *= vector to float dividing with Vector2
       + Vector2& operator/=(int InputInt);         //    *= vector to int dividing with Vector2
	
       + float operator*(Vector2 InputVector) const;
	 
	non-member normal function :
	   + Vector2 operator*(float InputFloat,Vector2 InputVector);  //    * for float to vector scaling with Vector2
	   + Vector2 operator*(int InputInt,Vector2 InputVector);      //    * for int to vector scaling with Vector2
	   + Vector2 operator*=(float InputFloat,Vector2 InputVector); //    *= float to vector scaling with Vector2
	   + Vector2 operator*=(int InputInt,Vector2 InputVector);     //    *= int to scaling with Vector2



	   + bool operator==(const Vector2 FirstInputVector, const Vector2 SecondInputVector); //Determine if two vectors are equal or not.
	   + bool operator!=(const Vector2 FirstInputVector, const Vector2 SecondInputVector); //Determine if two vectors are NOT equal or not.


	   + float dot(const Vector2 FirstInputVector,const Vector2 SecondInputVector); //Function for testing dot product


	   + Vector2 perpendicular_to(const Vector2 InputVector);//Calculate vector which is perpendicular
															 //from given vector.


	   + Vector2 normalize(Vector2 InputVector); //Normalize given vector
 

	   + float magnitude_of(const Vector2 InputVector);         //Calculate magnitude of given vector.
	   + float squared_magnitude_of(const Vector2 InputVector); //Calculate squared magnitude of given vector.


	   + float distance_between(Vector2 FirstInputVector, Vector2 SecondInputVector);         //distance between two vectors.!!TREAT VECTORS AS POINT!!
	   + float distance_between_squared(Vector2 FirstInputVector, Vector2 SecondInputVector); //squared distance between two vectors.!!TREAT VECTORS AS POINT!!


	   + float angle_between(Vector2 firstInputVector, Vector2 secondInputVector); //Angle between two vectors.

*/
/******************************************************************************/
#pragma once


struct Matrix2;

struct Vector2
{
    //represent x-y vector componenet

	float value[2] = { 0, };
	float& x = value[0];
	float& y = value[1];

	
	

    //constructor for Vector2 initialization
	Vector2() = default;

    Vector2(const float init_x, const float init_y)
		: value{init_x, init_y} { }

	//copy
	Vector2& operator=(const Vector2& input_vector);

	//addition
	Vector2 operator+(Vector2 input_vector) const; //addition with +
	Vector2& operator+=(Vector2 input_vector);	  //addition with +=

	//subtraction
    Vector2 operator-(Vector2 input_vector) const; //subtraction with -
    Vector2& operator-=(Vector2 input_vector);     //subtraction with -=
    
	//unary prefix
    Vector2 operator-() const;					  //-(unary prefix)


    //Scaling
	template <typename Number>
    Vector2 operator*(Number input_float) const; // * for vector to Number scaling with Vector2
	template <typename Number>
    Vector2& operator*=(Number input_int);        // *= vector to Number scaling with Vector2


    //Dividing
	template <typename Number>
    Vector2 operator/(Number input_float) const; //    * for vector to float dividing with Vector2
	template <typename Number>
    Vector2& operator/=(Number input_float);     //    *= vector to float dividing with Vector2
	



    //Dot product. !!not scaling!!
    float operator*(Vector2 input_vector) const;
	//Multiply with matrix2
	Vector2 operator*(Matrix2 input_matrix) const;



	//Comparison operator
	bool operator==(Vector2 input_vector) const; //Determine if two vectors are equal or not.
	bool operator!=(Vector2 input_vector) const; //Determine if two vectors are NOT equal or not.



	float angle_between(Vector2 secondinput_vector) const; //Angle between two vectors.

	Vector2 perpendicular() const;//Calculate vector which is perpendicular
													  //from given vector.


	Vector2 normalize(); //Normalize given vector


	float magnitude() const;         //Calculate magnitude of given vector.
	float squared_magnitude(); //Calculate squared magnitude of given vector.


	float distance_between(Vector2 firstinput_vector, Vector2 secondinput_vector);         //distance between two vectors.!!TREAT VECTORS AS POINT!!
	float distance_between_squared(Vector2 firstinput_vector, Vector2 secondinput_vector); //squared distance between two vectors.!!TREAT VECTORS AS POINT!!

};




