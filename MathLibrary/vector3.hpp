/******************************************************************************/
/*!
file name : vector3.hpp
author    : Jaejun Jang
email     : jjj404001@gmail.com


DigiPen login     : jaejun.jang
Course name       : CS230
Assignment number :#1

term   :Spring 2018
brief  :
    This file contains the function prototypes and struct vector3 using for calculating with matrix.
      
    Functions include:
	in vector3 struct :
	   + vector3 operator+(vector3 InputVector) const; //addition with +
	   + vector3& operator+=(vector3 InputVector);	  //addition with +=

       + vector3 operator-(vector3 InputVector) const; //subtraction with -
       + vector3& operator-=(vector3 InputVector);	  //subtraction with -=
       + vector3 operator-(void);					  //unary prefix

	   
       + vector3 operator*(float InputFloat) const; //    * for vector to float scaling with vector3
       + vector3 operator*(int InputInt) const;     //    * for vector to int scaling with vector3
       + vector3& operator*=(float InputFloat);     //    *= vector to float scaling with vector3
       + vector3& operator*=(int InputInt);         //    *= vector to int scaling with vector3


       +  operator/(float InputFloat) const;//    * for vector to float dividing with vector3
       + vector3 operator/(int InputInt) const;    //    * for vector to int dividing with vector3
       + vector3& operator/=(float InputFloat);    //    *= vector to float dividing with vector3
       + vector3& operator/=(int InputInt);        //    *= vector to int dividing with vector3



    
       + float operator*(vector3 InputVector) const; //Dot product. !!not scaling!!
 
	non-member normal function :
	   + vector3 operator*(float InputFloat,vector3 InputVector);  //    * for float to vector scaling with vector3
	   + vector3 operator*(int InputInt,vector3 InputVector);      //    * for int to vector scaling with vector3
	   + vector3 operator*=(float InputFloat,vector3 InputVector); //    *= float to vector scaling with vector3
	   + vector3 operator*=(int InputInt,vector3 InputVector);     //    *= int to scaling with vector3

	   + bool operator==(const vector3 FirstInputVector, const vector3 SecondInputVector); //Determine if two vectors are equal or not.

	   + bool operator!=(const vector3 FirstInputVector, const vector3 SecondInputVector); //Determine if two vectors are NOT equal or not.


	   + float dot(const vector3 FirstInputVector,const vector3 SecondInputVector);     //Function for dot product
	   + vector3 cross(const vector3 FirstInputVector,const vector3 SecondInputVector); //Function for cross product


	   + vector3 perpendicular_to(const vector3 InputVector);//Calculate vector which is perpendicular
															 //from given vector.


	   + float magnitude_of(const vector3 InputVector);          //Calculate magnitude of given vector.
	   + float squared_magnitude_of(const vector3 InputVector); //Calculate squared magnitude of given vector.


	   + vector3 normalize(vector3 InputVector); //Normalize given vector


	   + float distance_between(vector3 FirstInputVector, vector3 SecondInputVector);         //distance between two vectors.!!TREAT VECTORS AS POINT!!
	   + float distance_between_squared(vector3 FirstInputVector, vector3 SecondInputVector); //squared distance between two vectors.!!TREAT VECTORS AS POINT!!


	   + float angle_between(vector3 firstInputVector, vector3 secondInputVector); //Angle between two vectors.

*/
/******************************************************************************/
#pragma once
#include <array>

struct vector3
{
    float x = 0;
    float y = 0;
    float z = 0;
	
	//constructor for vector3 initialization
	vector3() = default;

    vector3(float InitX)
    {
        x = InitX;
        y = InitX;
		z = InitX;
    }
    
    vector3(float InitX, float InitY, float InitZ)
    {
        x = InitX;
        y = InitY;
        z = InitZ;
    }
    //addition

	vector3 operator+(vector3 InputVector) const; //addition with +
	vector3& operator+=(vector3 InputVector);	  //addition with +=

    //subtraction
    vector3 operator-(vector3 InputVector) const; //subtraction with -
    vector3& operator-=(vector3 InputVector);	  //subtraction with -=
    vector3 operator-(void);					  //unary prefix


    //Scaling
    
    vector3 operator*(float InputFloat) const; //    * for vector to float scaling with vector3
    vector3 operator*(int InputInt) const;     //    * for vector to int scaling with vector3
    vector3& operator*=(float InputFloat);     //    *= vector to float scaling with vector3
    vector3& operator*=(int InputInt);         //    *= vector to int scaling with vector3


    //Dividing
    
    vector3 operator/(float InputFloat) const;//    * for vector to float dividing with vector3
    vector3 operator/(int InputInt) const;    //    * for vector to int dividing with vector3
    vector3& operator/=(float InputFloat);    //    *= vector to float dividing with vector3
    vector3& operator/=(int InputInt);        //    *= vector to int dividing with vector3



    //Dot product. !!not scaling!!
    float operator*(vector3 InputVector) const;

	// 
    
};
///////////////////////////////////////////////////////////////////////////////
/////////////////////////non-member normal function.///////////////////////////
///////////////////////////////////////////////////////////////////////////////

//Scaling

vector3 operator*(float InputFloat,vector3 InputVector);  //    * for float to vector scaling with vector3
vector3 operator*(int InputInt,vector3 InputVector);      //    * for int to vector scaling with vector3
vector3 operator*=(float InputFloat,vector3 InputVector); //    *= float to vector scaling with vector3
vector3 operator*=(int InputInt,vector3 InputVector);     //    *= int to scaling with vector3


//Comparison operator

bool operator==(const vector3 FirstInputVector, const vector3 SecondInputVector); //Determine if two vectors are equal or not.

bool operator!=(const vector3 FirstInputVector, const vector3 SecondInputVector); //Determine if two vectors are NOT equal or not.


float dot(const vector3 FirstInputVector,const vector3 SecondInputVector);     //Function for dot product
vector3 cross(const vector3 FirstInputVector,const vector3 SecondInputVector); //Function for cross product


vector3 perpendicular_to(const vector3 InputVector);//Calculate vector which is perpendicular
													//from given vector.


float magnitude_of(const vector3 InputVector);          //Calculate magnitude of given vector.
float squared_magnitude_of(const vector3 InputVector); //Calculate squared magnitude of given vector.


vector3 normalize(vector3 InputVector); //Normalize given vector


float distance_between(vector3 FirstInputVector, vector3 SecondInputVector);         //distance between two vectors.!!TREAT VECTORS AS POINT!!
float distance_between_squared(vector3 FirstInputVector, vector3 SecondInputVector); //squared distance between two vectors.!!TREAT VECTORS AS POINT!!


float angle_between(vector3 firstInputVector, vector3 secondInputVector); //Angle between two vectors.