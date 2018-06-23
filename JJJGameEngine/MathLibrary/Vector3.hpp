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
    float x = 0;
    float y = 0;
    float z = 0;
	
	//constructor for Vector3 initialization
	Vector3() = default;

    Vector3(float InitX)
    {
        x = InitX;
        y = InitX;
		z = InitX;
    }
    
    Vector3(float InitX, float InitY, float InitZ)
    {
        x = InitX;
        y = InitY;
        z = InitZ;
    }
    //addition

	Vector3 operator+(Vector3 InputVector) const; //addition with +
	Vector3& operator+=(Vector3 InputVector);	  //addition with +=

    //subtraction
    Vector3 operator-(Vector3 InputVector) const; //subtraction with -
    Vector3& operator-=(Vector3 InputVector);	  //subtraction with -=
    Vector3 operator-(void);					  //unary prefix


    //Scaling
    
    Vector3 operator*(float InputFloat) const; //    * for vector to float scaling with Vector3
    Vector3 operator*(int InputInt) const;     //    * for vector to int scaling with Vector3
    Vector3& operator*=(float InputFloat);     //    *= vector to float scaling with Vector3
    Vector3& operator*=(int InputInt);         //    *= vector to int scaling with Vector3


    //Dividing
    
    Vector3 operator/(float InputFloat) const;//    * for vector to float dividing with Vector3
    Vector3 operator/(int InputInt) const;    //    * for vector to int dividing with Vector3
    Vector3& operator/=(float InputFloat);    //    *= vector to float dividing with Vector3
    Vector3& operator/=(int InputInt);        //    *= vector to int dividing with Vector3



    //Dot product. !!not scaling!!
    float operator*(Vector3 input_vector) const;

	static Vector3 cross(const Vector3 first_input_vector, const Vector3 second_input_vector); //Function for cross product
};
///////////////////////////////////////////////////////////////////////////////
/////////////////////////non-member normal function.///////////////////////////
///////////////////////////////////////////////////////////////////////////////

//Scaling

Vector3 operator*(float InputFloat,Vector3 InputVector);  //    * for float to vector scaling with Vector3
Vector3 operator*(int InputInt,Vector3 InputVector);      //    * for int to vector scaling with Vector3
Vector3 operator*=(float InputFloat,Vector3 InputVector); //    *= float to vector scaling with Vector3
Vector3 operator*=(int InputInt,Vector3 InputVector);     //    *= int to scaling with Vector3


//Comparison operator

bool operator==(const Vector3 FirstInputVector, const Vector3 SecondInputVector); //Determine if two vectors are equal or not.

bool operator!=(const Vector3 FirstInputVector, const Vector3 SecondInputVector); //Determine if two vectors are NOT equal or not.




float magnitude_of(const Vector3 InputVector);          //Calculate magnitude of given vector.
float squared_magnitude_of(const Vector3 InputVector); //Calculate squared magnitude of given vector.


Vector3 normalize(Vector3 InputVector); //Normalize given vector


float distance_between(Vector3 FirstInputVector, Vector3 SecondInputVector);         //distance between two vectors.!!TREAT VECTORS AS POINT!!
float distance_between_squared(Vector3 FirstInputVector, Vector3 SecondInputVector); //squared distance between two vectors.!!TREAT VECTORS AS POINT!!


float angle_between(Vector3 firstInputVector, Vector3 secondInputVector); //Angle between two vectors.