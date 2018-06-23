/******************************************************************************/
/*!
file name : vector2.hpp
author    : Jaejun Jang
email     : jjj404001@gmail.com


DigiPen login     : jaejun.jang
Course name       : CS230
Assignment number :#1

term   :Spring 2018
brief  :
    This file contains the function prototype and struct vector2 for calculating with veector2.
      
    Functions include:
	in vector2 struct :
	   + vector2 operator+(vector2 InputVector) const; //addition with +
	   + vector2& operator+=(vector2 InputVector);	  //addition with +=


       + vector2 operator-(vector2 InputVector) const; //subtraction with -
       + vector2& operator-=(vector2 InputVector);     //subtraction with -=
    
	
       + vector2 operator-(void);					  //-(unary prefix)

    
       + vector2 operator*(float InputFloat) const; // * for vector to float scaling with vector2
       + vector2 operator*(int InputInt) const;    // * for vector to int scaling with vector2

    
       + vector2& operator*=(float InputFloat);    // *= vector to float scaling with vector2
       + vector2& operator*=(int InputInt);        // *= vector to int scaling with vector2


    
       + vector2 operator/(float InputFloat) const; //    * for vector to float dividing with vector2
       + vector2 operator/(int InputInt) const;     //    * for vector to int dividing with vector2
       + vector2& operator/=(float InputFloat);     //    *= vector to float dividing with vector2
       + vector2& operator/=(int InputInt);         //    *= vector to int dividing with vector2
	
       + float operator*(vector2 InputVector) const;
	 
	non-member normal function :
	   + vector2 operator*(float InputFloat,vector2 InputVector);  //    * for float to vector scaling with vector2
	   + vector2 operator*(int InputInt,vector2 InputVector);      //    * for int to vector scaling with vector2
	   + vector2 operator*=(float InputFloat,vector2 InputVector); //    *= float to vector scaling with vector2
	   + vector2 operator*=(int InputInt,vector2 InputVector);     //    *= int to scaling with vector2



	   + bool operator==(const vector2 FirstInputVector, const vector2 SecondInputVector); //Determine if two vectors are equal or not.
	   + bool operator!=(const vector2 FirstInputVector, const vector2 SecondInputVector); //Determine if two vectors are NOT equal or not.


	   + float dot(const vector2 FirstInputVector,const vector2 SecondInputVector); //Function for testing dot product


	   + vector2 perpendicular_to(const vector2 InputVector);//Calculate vector which is perpendicular
															 //from given vector.


	   + vector2 normalize(vector2 InputVector); //Normalize given vector
 

	   + float magnitude_of(const vector2 InputVector);         //Calculate magnitude of given vector.
	   + float squared_magnitude_of(const vector2 InputVector); //Calculate squared magnitude of given vector.


	   + float distance_between(vector2 FirstInputVector, vector2 SecondInputVector);         //distance between two vectors.!!TREAT VECTORS AS POINT!!
	   + float distance_between_squared(vector2 FirstInputVector, vector2 SecondInputVector); //squared distance between two vectors.!!TREAT VECTORS AS POINT!!


	   + float angle_between(vector2 firstInputVector, vector2 secondInputVector); //Angle between two vectors.

*/
/******************************************************************************/
#pragma once




struct vector2
{
    //represent x-y vector componenet
    float x =0;
    float y =0;


	

    //constructor for vector2 initialization
	vector2() = default;

    vector2(const float init_x)
    {
        x = init_x;
        y = init_x;
    }

    vector2(const float init_x, const float init_y)
    {
        x = init_x;
        y = init_y;
    }


	//addition

	vector2 operator+(vector2 input_vector) const; //addition with +
	vector2& operator+=(vector2 input_vector);	  //addition with +=

	//subtraction

    vector2 operator-(const vector2 input_vector) const; //subtraction with -
    vector2& operator-=(vector2 input_vector);     //subtraction with -=
    
	//unary prefix
	
    vector2 operator-(void) const;					  //-(unary prefix)


    //Scaling
    
    vector2 operator*(float input_float) const; // * for vector to float scaling with vector2
    vector2 operator*(int input_int) const;    // * for vector to int scaling with vector2

    
    vector2& operator*=(float input_float);    // *= vector to float scaling with vector2
    vector2& operator*=(int input_int);        // *= vector to int scaling with vector2


    //Dividing
    
    vector2 operator/(float input_float) const; //    * for vector to float dividing with vector2
    vector2 operator/(int input_int) const;     //    * for vector to int dividing with vector2
    vector2& operator/=(float input_float);     //    *= vector to float dividing with vector2
    vector2& operator/=(int input_int);         //    *= vector to int dividing with vector2
	



    //Dot product. !!not scaling!!
    float operator*(vector2 input_vector) const;

    

	//Comparison operator
	bool operator==(const vector2 input_vector) const; //Determine if two vectors are equal or not.
	bool operator!=(const vector2 input_vector) const; //Determine if two vectors are NOT equal or not.
};
///////////////////////////////////////////////////////////////////////////////
/////////////////////////non-member normal function.///////////////////////////
///////////////////////////////////////////////////////////////////////////////


//using non-member operator overloading for non-vector left operand

//Scaling

vector2 operator*(const float input_float, const vector2 input_vector);  //    * for float to vector scaling with vector2
vector2 operator*(const int input_int, const vector2 input_vector);      //    * for int to vector scaling with vector2


float dot(const vector2 FirstInputVector,const vector2 SecondInputVector); //Function for testing dot product
vector2 perpendicular_to(const vector2 input_vector);//Calculate vector which is perpendicular
													//from given vector.


vector2 normalize(vector2 input_vector); //Normalize given vector
 

float magnitude_of(const vector2 input_vector);         //Calculate magnitude of given vector.
float squared_magnitude_of(const vector2 input_vector); //Calculate squared magnitude of given vector.


float distance_between(const vector2 firstinput_vector, const vector2 secondinput_vector);         //distance between two vectors.!!TREAT VECTORS AS POINT!!
float distance_between_squared(const vector2 firstinput_vector, const vector2 secondinput_vector); //squared distance between two vectors.!!TREAT VECTORS AS POINT!!


float angle_between(const vector2 firstinput_vector, const vector2 secondinput_vector); //Angle between two vectors.



