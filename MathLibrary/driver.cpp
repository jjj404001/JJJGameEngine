/******************************************************************************/
/*!
file name : driver.hpp
author    : Jaejun Jang
email     : jjj404001@gmail.com


DigiPen login     : jaejun.jang
Course name       : CS230
Assignment number :#1

term   :Spring 2018
brief  :
    This file contains Test cases for Assignment 1.
      
    TEST_CASE include:
	TEST_CASE("vector2 constructor")
	TEST_CASE("vector2 addition")
	TEST_CASE("vector2 subtraction")
	TEST_CASE("vector2 negation")
	TEST_CASE("vector2 scaling")
	TEST_CASE("vector2 comparison")
	TEST_CASE("vector2 dot function")
	TEST_CASE("vector2 perpendicular_to function")
	TEST_CASE("vector2 magnitude & magnitude squared")
	TEST_CASE("vector2 normalize function")
	TEST_CASE("vector2 distance_between function")
	TEST_CASE("vector2 angle between two vectors")
	TEST_CASE("matrix2 constructor & element access")
	TEST_CASE("matrix2 access & getting elements")
	TEST_CASE("matrix2 matrix multiplcation")
	TEST_CASE("matrix2 transform")
	TEST_CASE("matrix2 transpose")
	TEST_CASE("matrix2 identity")
	TEST_CASE("matrix2 scale")
	TEST_CASE("matrix2 determinant")
	TEST_CASE("matrix2 inverse")
	TEST_CASE("vector3 constructor")
	TEST_CASE("vector3 addition")
	TEST_CASE("vector3 subtraction")
	TEST_CASE("vector3 negation")
	TEST_CASE("vector3 scaling")
	TEST_CASE("vector3 comparison")
	TEST_CASE("vector3 dot product")
	TEST_CASE("vector3 cross product")
	TEST_CASE("vector3 magnitude")
	TEST_CASE("vector3 normalize function")
	TEST_CASE("vector3 distance_between function")
	TEST_CASE("vector3 angle between two vectors")
	TEST_CASE("affine2d constructor & element access")
	TEST_CASE("affine2d element access")
	TEST_CASE("affine2d transpose")
	TEST_CASE("affine2d rotation")
	TEST_CASE("affine2d identity")
	TEST_CASE("affine2d scale")
	TEST_CASE("affine2d translation")
	TEST_CASE("affine2d matrix multiplcation")
	TEST_CASE("matrix2 rotation")

*/
/******************************************************************************/
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "vector2.hpp"
#include "vector3.hpp"
#include "matrix2.hpp"
#include "affine2d.hpp"
#include <iostream>

namespace
{
	//using these for making test case.
	
    const float epsilon = std::numeric_limits<float>::epsilon(); // testing float's precision.
	const float pi = 4.0f * std::atan(1.0f);
}


TEST_CASE("vector2 constructor")
{
    vector2 zero;                        // should be {0.0f, 0.0f}
    REQUIRE((zero.x == 0.0f && zero.y == 0.0f));
	
	

    vector2 fill_float(1.0f);            // should be {1.0f, 1.0f}
    REQUIRE((fill_float.x == 1.0f && fill_float.y == 1.0f));
	
	

    vector2 custom_xy(1.0f, 2.0f);       // should be {1.0f, 2.0f}
    REQUIRE((custom_xy.x == 1.0f && custom_xy.y == 2.0f));
	
	

    vector2 zero_curly{};                // should be {0.0f, 0.0f}
    REQUIRE((zero_curly.x == 0.0f && zero_curly.y == 0.0f));
	
	

    vector2 fill_float_curly{2.0f};      // should be {2.0f, 2.0f}
    REQUIRE((fill_float_curly.x == 2.0f && fill_float_curly.y == 2.0f));
	
	

    vector2 custom_xy_curly{1.0f, 2.0f}; // should be {1.0f, 2.0f}
    REQUIRE((custom_xy_curly.x == 1.0f && custom_xy_curly.y == 2.0f));
}

TEST_CASE("vector2 addition")
{
    vector2 one(1.0f);
    vector2 negative_one(-1.0f);
    vector2 zero = one + negative_one;   // 1 + -1 = 0.should be 0
    REQUIRE((zero.x == 0.0f && zero.y == 0.0f));

    zero = one;
    zero += negative_one;                // 1 += (-1) = 0. should be 0
    REQUIRE((zero.x == 0.0f && zero.y == 0.0f));
}

TEST_CASE("vector2 subtraction")
{
	vector2 negative_one(-1.0f, -1.0f);
	vector2 zero(0.0f, 0.0f);
	vector2 one(1.0f);
	vector2 two(2.0f);
	vector2 three(3.0f);
	
	one = two - one;             // 2 - 1 =   1. should be  1
	REQUIRE((one.x == 1.0f && one.y == 1.0f));
	
	zero -= one;                 // 0 - 1 =-  1. should be -1
	REQUIRE((zero.x == -1.0f && zero.y == -1.0f));
	
	negative_one -= negative_one;// (-1) - (-1) = 0. should be 0
	REQUIRE((negative_one.x == 0.0f && negative_one.y == 0.0f));
}

TEST_CASE("vector2 negation")
{
    vector2 minus_ten(-10.0f);
    vector2 ten = -minus_ten; // -10.0f , -10.0f
    REQUIRE((ten.x == 10.0f && ten.y == 10.0f));
}

TEST_CASE("vector2 scaling")
{
    vector2 ten(2.0f);
    ten *= 5.0f;
    REQUIRE((ten.x == 10.0f && ten.y == 10.0f));

    ten = 2 * vector2(5.0f);
    REQUIRE((ten.x == 10.0f && ten.y == 10.0f));

    ten = vector2(5.0f) * 2;
    REQUIRE((ten.x == 10.0f && ten.y == 10.0f));

    ten = vector2(50.0f);
    ten /= 5.0f;
    REQUIRE((ten.x == 10.0f && ten.y == 10.0f));

    ten = vector2(100.0f) / 10.f;
    REQUIRE((ten.x == 10.0f && ten.y == 10.0f));
}

TEST_CASE("vector2 comparison")
{
    vector2 input1(1.0f, 1.0f);
    vector2 input2(1.0f, 1.0f);
    vector2 input3(2.0f, 2.0f);


    REQUIRE(input1 == input2);
    REQUIRE(!(input1 != input2));
    REQUIRE(!(input1 == input3));
    REQUIRE(input1 != input3);
}

TEST_CASE("vector2 dot function")
{
    float x1 = -10.123f, y1 = 3.12456f;
    float x2 = 0.10123f, y2 = 300.12456f;
    vector2 a{x1, y1};
    vector2 b{x2, y2};
    REQUIRE(dot(a, b) == x1 * x2 + y1 * y2);
    REQUIRE(dot(a, b) == dot(b, a));
}

TEST_CASE("vector2 perpendicular_to function")
{
    const auto x1 = -10.123f, y1 = 3.12456f;
    vector2 original{x1, y1};
    auto perp = perpendicular_to(original);
    REQUIRE(dot(original, perp) <= epsilon);
}

TEST_CASE("vector2 magnitude & magnitude squared")
{
    //magnitude is 5
    vector2 v1 = {3,4};
    //magnitude is 10
    vector2 v2 = {8,6};

    float testValue = 5.0f;
    REQUIRE(magnitude_of(v1) == testValue);

    testValue = 10.0f;
    REQUIRE(magnitude_of(v2) == testValue);

    testValue *= testValue;
    REQUIRE(squared_magnitude_of(v2) == testValue);
}

TEST_CASE("vector2 normalize function")
{
    vector2 unit_vector{-std::sqrt(0.5f), std::sqrt(0.5f)};
    vector2 norm_vector = {-500.0f, 500.0f};
            norm_vector = normalize(norm_vector);
    REQUIRE(unit_vector == norm_vector);


    vector2 normalized_vector = {-970987.564564f, 531.0545f};
            normalized_vector = normalize(normalized_vector);

    REQUIRE(magnitude_of(normalized_vector) - 1.0f <= epsilon);
    REQUIRE(squared_magnitude_of(normalized_vector) - 1.0f <= epsilon);
}

TEST_CASE("vector2 distance_between function")
{
    vector2 u = {0.0f, 1.0f};
    vector2 v = {0.0f, -1.0f};
    vector2 j = {1.0f, 0.0f};
    vector2 k = {-1.0f, 0.0f};

    REQUIRE(distance_between(u, v) == 2.0f);
    REQUIRE(distance_between_squared(u, v) == 4.0f);

    REQUIRE(distance_between(j, k) == 2.0f);
    REQUIRE(distance_between_squared(j, k) == 4.0f);


    float x1 = -10.123f, y1 = 3.12456f;
    float x2 = 0.10123f, y2 = 300.12456f;

    u = {x1, y1};
    v = {x2, y2};

    REQUIRE(distance_between(u, v) -
            std::sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)) <= epsilon);
 
    REQUIRE(distance_between_squared(u, v) -
            ((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)) <= epsilon);
}

TEST_CASE("vector2 angle between two vectors")
{
    vector2 u = {10,10};
    vector2 v = perpendicular_to(u);


    REQUIRE(angle_between( u, v ) == 90);

    v = {10,10};


    REQUIRE(angle_between( u, v ) == 0);

    v = {-10,0};


    REQUIRE(angle_between( u, v ) == 135);
}

TEST_CASE("matrix2 constructor & element access")
{
    matrix2 zero;
    REQUIRE(zero(0, 0) == 0.0f);
    REQUIRE(zero(0, 1) == 0.0f);
    REQUIRE(zero(1, 0) == 0.0f);
    REQUIRE(zero(1, 1) == 0.0f);

    vector2 column1{1.0f, 2.0f};
    vector2 column2{3.0f, 4.0f};
    matrix2 column_init{column1, column2};
    REQUIRE(column_init(0, 0) == column1.x);
    REQUIRE(column_init(0, 1) == column1.y);
    REQUIRE(column_init(1, 0) == column2.x);
    REQUIRE(column_init(1, 1) == column2.y);

    float column0_row0 = 4.0f, column0_row1 = 3.0f, column1_row0 = 2.0f, column1_row1 = 1.0f;
    matrix2 explicit_init{column0_row0, column0_row1, column1_row0, column1_row1};
    REQUIRE(explicit_init(0, 0) == column0_row0);
    REQUIRE(explicit_init(0, 1) == column0_row1);
    REQUIRE(explicit_init(1, 0) == column1_row0);
    REQUIRE(explicit_init(1, 1) == column1_row1);
}
//test element access: setting & getting elements for non-const and just getting elements for const
TEST_CASE("matrix2 access & getting elements")
{
	const matrix2 const_testMatrix{1.0f, 2.0f, 3.0f, 4.0f};
	
	REQUIRE(const_testMatrix(0,0) == 1.0f);
	REQUIRE(const_testMatrix(0,1) == 2.0f);
	REQUIRE(const_testMatrix(1,0) == 3.0f);
	REQUIRE(const_testMatrix(1,1) == 4.0f);
	
	matrix2 testMatrix = {9.0f, 10.0f, 11.0f, 12.0f};
	
	testMatrix(0,0) = 5.0f;
	testMatrix(0,1) = 6.0f;
	testMatrix(1,0) = 7.0f;
	testMatrix(1,1) = 8.0f;
	
	REQUIRE(testMatrix(0,0) == 5.0f);
	REQUIRE(testMatrix(0,1) == 6.0f);
	REQUIRE(testMatrix(1,0) == 7.0f);
	REQUIRE(testMatrix(1,1) == 8.0f);
}
TEST_CASE("matrix2 matrix multiplcation")
{
    const matrix2 identity{1.0f, 0.0f, 0.0f, 1.0f};
    const matrix2 four321{4.0f, 3.0f, 2.0f, 1.0f};
    matrix2 identity_result = identity * four321;
    REQUIRE(identity_result(0, 0) == four321(0, 0));
    REQUIRE(identity_result(0, 1) == four321(0, 1));
    REQUIRE(identity_result(1, 0) == four321(1, 0));
    REQUIRE(identity_result(1, 1) == four321(1, 1));

    identity_result = four321 * identity;
    REQUIRE(identity_result(0, 0) == four321(0, 0));
    REQUIRE(identity_result(0, 1) == four321(0, 1));
    REQUIRE(identity_result(1, 0) == four321(1, 0));
    REQUIRE(identity_result(1, 1) == four321(1, 1));

    vector2 u = {10, -3};
            u = normalize(u);

    vector2 v = perpendicular_to(u);

    matrix2 uv{u, v};
    matrix2 uv_transpose{{u.x, v.x}, {u.y, v.y}};
    matrix2 to_identity = uv * uv_transpose;
    REQUIRE(( to_identity(0, 0) - identity(0, 0) ) <= epsilon);
    REQUIRE(( to_identity(0, 1) - identity(0, 1) ) <= epsilon);
    REQUIRE(( to_identity(1, 0) - identity(1, 0) ) <= epsilon);
    REQUIRE(( to_identity(1, 1) - identity(1, 1) ) <= epsilon);

	to_identity = uv_transpose * uv;
	REQUIRE((to_identity(0, 0) - identity(0, 0)) <= epsilon);
	REQUIRE((to_identity(0, 1) - identity(0, 1)) <= epsilon);
	REQUIRE((to_identity(1, 0) - identity(1, 0)) <= epsilon);
	REQUIRE((to_identity(1, 1) - identity(1, 1)) <= epsilon);

    matrix2 m1 = {1,7,2,4};
    matrix2 m2 = {3,3,5,2};

    matrix2 m3 = m1;
    m3 *= m2;

    REQUIRE(m3(0,0) == 38.0f); 
    REQUIRE(m3(0,1) == 17.0f); 
    REQUIRE(m3(1,0) == 26.0f); 
    REQUIRE(m3(1,1) == 14.0f); 
}


//test matrix2 transform vector
TEST_CASE("matrix2 transform")
{
	//test between manually transposed matrix and function made transposed matrix.
	//using transform.
	vector2 u = normalize({-10.0f, 11.1f});
    vector2 v = perpendicular_to(u);
    vector2 j = {u.x, u.y};
    vector2 k = {v.x, v.y};

 
	matrix2 tester{j, k};

    vector2 worldX = matrix2{j, k} * vector2{1.0f, 0.0f};
    vector2 worldY = matrix2{j, k} * vector2{0.0f, 1.0f};
	
	matrix2 transPosed = {worldX, worldY};
	
	tester.transpose();

	
    REQUIRE(tester(0, 0) == transPosed(0, 0));
	REQUIRE(tester(0, 1) == transPosed(0, 1));
    REQUIRE(tester(1, 0) == transPosed(1, 0));
	REQUIRE(tester(1, 1) == transPosed(1, 1));

}



TEST_CASE("matrix2 transpose")
{
    vector2 column_u{-1, 3.5f};
    vector2 column_v{2.5f, 4.0f};
    matrix2 original{column_u, column_v};
    matrix2 transposed = original.transpose();

    REQUIRE(transposed(0, 0) == column_u.x);
    REQUIRE(transposed(0, 1) == column_v.x);
    REQUIRE(transposed(1, 0) == column_u.y);
    REQUIRE(transposed(1, 1) == column_v.y);
}



TEST_CASE("matrix2 identity")
{
    const matrix2 identity{1.0f, 0.0f, 0.0f, 1.0f};
    matrix2 identity_result = build_identity();
    REQUIRE(identity_result(0, 0) == identity(0, 0));
    REQUIRE(identity_result(0, 1) == identity(0, 1));
    REQUIRE(identity_result(1, 0) == identity(1, 0));
    REQUIRE(identity_result(1, 1) == identity(1, 1));
}

TEST_CASE("matrix2 scale")
{
	//uniform scale
    const matrix2 ten{10.0f, 0.0f, 0.0f, 10.0f};
    matrix2 uniform_scale = build_scale(10.0f);
    REQUIRE(uniform_scale(0, 0) == ten(0, 0));
    REQUIRE(uniform_scale(0, 1) == ten(0, 1));
    REQUIRE(uniform_scale(1, 0) == ten(1, 0));
    REQUIRE(uniform_scale(1, 1) == ten(1, 1));


	//non uniform scale
    const matrix2 ten_twenty{10.0f, 0.0f, 0.0f, 20.0f};
    matrix2 nonuniform_scale = build_scale(10.0f, 20.0f);
    REQUIRE(nonuniform_scale(0, 0) == ten_twenty(0, 0));
    REQUIRE(nonuniform_scale(0, 1) == ten_twenty(0, 1));
    REQUIRE(nonuniform_scale(1, 0) == ten_twenty(1, 0));
    REQUIRE(nonuniform_scale(1, 1) == ten_twenty(1, 1));
}

TEST_CASE("matrix2 determinant")
{
    matrix2 one234 = {1,2,3,4};
    matrix2 identity = build_identity();
    float result;

    result = one234.determinant_of(one234);
    REQUIRE(result == -2);

    result = identity.determinant_of(identity);
    REQUIRE(result == 1);
}

TEST_CASE("matrix2 inverse")
{
    matrix2 one234       = {1,2,3,4};
    matrix2 inversed1234 = inversed1234.inverse_of(one234);
    matrix2 result       = one234 * inversed1234;
    matrix2 identity     = build_identity();


    REQUIRE(result(0,0) == identity(0,0));
    REQUIRE(result(0,1) == identity(0,1));
    REQUIRE(result(1,0) == identity(1,0));
    REQUIRE(result(1,1) == identity(1,1));
}

TEST_CASE("vector3 constructor")
{
    vector3 zero;
    REQUIRE((zero.x == 0.0f && zero.y == 0.0f && zero.z == 0.0f));

    vector3 fill_float(1.0f);
    REQUIRE((fill_float.x == 1.0f && fill_float.y == 1.0f && fill_float.z == 1.0f));

    vector3 custom_xyz(1.0f, 2.0f, 3.0f);
    REQUIRE((custom_xyz.x == 1.0f && custom_xyz.y == 2.0f && custom_xyz.z == 3.0f));

    vector3 zero_curly{};
    REQUIRE((zero_curly.x == 0.0f && zero_curly.y == 0.0f && zero_curly.z == 0.0f));

    vector3 fill_float_curly{2.0f};
    REQUIRE((fill_float_curly.x == 2.0f && fill_float_curly.y == 2.0f && fill_float_curly.z == 2.0f));

    vector3 custom_xyz_curly{1.0f, 2.0f, 3.0f};
    REQUIRE((custom_xyz_curly.x == 1.0f && custom_xyz_curly.y == 2.0f && custom_xyz_curly.z == 3.0f));
}

TEST_CASE("vector3 addition")
{
    vector3 one(1.0f);
    vector3 negative_one(-1.0f);
    vector3 zero = one + negative_one;
    REQUIRE((zero.x == 0.0f && zero.y == 0.0f && zero.z == 0.0f));

    zero = one;
    zero += negative_one;
    REQUIRE((zero.x == 0.0f && zero.y == 0.0f && zero.z == 0.0f));
}

TEST_CASE("vector3 subtraction")
{
	vector3 negative_one(-1.0f, -1.0f, 1.0f);
	vector3 zero(0.0f, 0.0f, 0.0f);
	vector3 one(1.0f, 1.0f, 1.0f);
	vector3 two(2.0f, 2.0f, 2.0f);
	vector3 three(3.0f, 3.0f, 3.0f);
	
	one = two - one;             // 2 - 1 =   1. should be  1
	REQUIRE((one.x == 1.0f && one.y == 1.0f && one.z));
	
	zero -= one;                 // 0 - 1 =-  1. should be -1
	REQUIRE((zero.x == -1.0f && zero.y == -1.0f && zero.z == -1.0f));
	
	negative_one -= negative_one;// (-1) - (-1) = 0. should be 0
	REQUIRE((negative_one.x == 0.0f && negative_one.y == 0.0f && negative_one.z == 0.0f));
}

TEST_CASE("vector3 negation")
{
    vector3 minus_ten(-10.0f);
    vector3 ten = -minus_ten;
    REQUIRE((ten.x == 10.0f && ten.y == 10.0f && ten.z == 10.f));
}

TEST_CASE("vector3 scaling")
{
    vector3 ten(2.0f);
    ten *= 5.0f;
    REQUIRE((ten.x == 10.0f && ten.y == 10.0f && ten.z == 10.0f));

    ten = 2 * vector3(5.0f);
    REQUIRE((ten.x == 10.0f && ten.y == 10.0f && ten.z == 10.0f));

    ten = vector3(5.0f) * 2;
    REQUIRE((ten.x == 10.0f && ten.y == 10.0f && ten.z == 10.0f));

    ten = vector3(50.0f);
    ten /= 5.0f;
    REQUIRE((ten.x == 10.0f && ten.y == 10.0f && ten.z == 10.0f));

    ten = vector3(100.0f) / 10.f;
    REQUIRE((ten.x == 10.0f && ten.y == 10.0f && ten.z == 10.0f));
}

TEST_CASE("vector3 comparison")
{
    vector3 input0(1.0f, 1.0f, 1.0f);
    vector3 input1(1.0f, 1.0f, 1.0f);
    vector3 input2(2.0f, 2.0f, 2.0f);


    REQUIRE(input0 == input1);
    REQUIRE(!(input0 != input1));
    REQUIRE(!(input0 == input2));
    REQUIRE(input0 != input2);
}


TEST_CASE("vector3 dot product")
{
    float x1 = -10.123f, y1 = 3.12456f, z1 = 4.12345f;
    float x2 = 0.10123f, y2 = 300.12456f, z2 = 30.1234f;
    vector3 a{x1, y1, z1};
    vector3 b{x2, y2, z2};
    REQUIRE(dot(a, b) == x1 * x2 + y1 * y2 + z1 * z2);
    REQUIRE(dot(a, b) == dot(b, a));
}

TEST_CASE("vector3 cross product")
{
	float x1 = -12.345f, y1 = 3.456f, z1 = 4.567f;
    float x2 = 0.123f, y2 = 300.123f, z2 = 30.123f;
    vector3 a{x1, y1, z1};
    vector3 b{x2, y2, z2};
    REQUIRE(cross(a, b).x == (x1 * y2) - (y1 * x2));
    REQUIRE(cross(a, b).y == (y1 * z2) - (z1 * y2));
	REQUIRE(cross(a, b).z == (z1 * x2) - (x1 * z2));
}

TEST_CASE("vector3 magnitude")
{
    //magnitude is 11
    vector3 v1 = {7,6,6};
    //magnitude is 6
    vector3 v2 = {2,4,4};

    float testValue = 11.0f;
    REQUIRE(magnitude_of(v1) == testValue);

    testValue = 6.0f;
    REQUIRE(magnitude_of(v2) == testValue);

    testValue *= testValue;
    REQUIRE(squared_magnitude_of(v2) == testValue);
}

TEST_CASE("vector3 normalize function")
{
    vector3 unit_vector{0,0,0};

    
    vector3 norm_vector = {-500.0f, 500.0f, 500.0f};

            unit_vector.x = -500.f / magnitude_of(norm_vector);
            unit_vector.y =  500.f / magnitude_of(norm_vector);
            unit_vector.z =  500.f / magnitude_of(norm_vector);

            norm_vector = normalize(norm_vector);


    REQUIRE(unit_vector == norm_vector);


    vector3 normalized_vector = {-970987.564564f, 531.0545f, 123.1234f};
            normalized_vector = normalize(normalized_vector);

    REQUIRE(magnitude_of(normalized_vector) - 1.0f <= epsilon);
    REQUIRE(squared_magnitude_of(normalized_vector) - 1.0f <= epsilon);
}

TEST_CASE("vector3 distance_between function")
{
    vector3 u = {0.0f, 0.0f, 0.0f};
    vector3 v = {0.0f, 4.0f, 3.0f};


    vector3 j = {0.0f, 0.0f, 0.0f};
    vector3 k = {2.0f, 6.0f, 3.0f};

    REQUIRE(distance_between(u, v) == 5.0f);
    REQUIRE(distance_between_squared(u, v) == 25.0f);

    REQUIRE(distance_between(j, k) == 7.0f);
    REQUIRE(distance_between_squared(j, k) == 49.0f);


    float x1 = -10.123f, y1 = 3.12456f, z1 = 32.44f;
    float x2 = 0.10123f, y2 = 300.12456f, z2 = 221.32f;

    u = {x1, y1, z1};
    v = {x2, y2, z2};

    REQUIRE(distance_between(u, v) -
            std::sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) + (z1 - z2) * (z1 - z2)) <= epsilon);

    REQUIRE(distance_between_squared(u, v) -
            ((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) + (z1 - z2) * (z1 - z2)) <= epsilon);


    x1 = 10.0f, y1 = 22.33f, z1 = 44.22f;
    x2 = 10.0f, y2 = 22.33f, z2 = 44.22f;

    u = {x1,y1,z1};
    v = {x2,y2,z2};

    REQUIRE(distance_between(u, v) -
            std::sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) + (z1 - z2) * (z1 - z2)) <= epsilon);

    REQUIRE(distance_between_squared(u, v) -
    ((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) + (z1 - z2) * (z1 - z2)) <= epsilon);


    x2 = 11.0f, y2 = 23.33f, z2 = 45.22f;
    v = {x2,y2,z2};

    REQUIRE(distance_between(u, v) -
            std::sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) + (z1 - z2) * (z1 - z2)) <= epsilon);

    REQUIRE(distance_between_squared(u, v) -
    ((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) + (z1 - z2) * (z1 - z2)) <= epsilon);
}

TEST_CASE("vector3 angle between two vectors")
{
    vector3 u = {10,10,0};
    vector3 v = {10,-10,0};

    REQUIRE(angle_between( u, v ) == 90);



    v = {10,10,0};
    REQUIRE(angle_between( u, v ) == 0);




    v = {-10,0,0};
    REQUIRE(angle_between( u, v ) == 135);
}


TEST_CASE("affine2d constructor & element access")
{
    affine2d zero;
    REQUIRE(zero(0, 0) == 0.0f);
    REQUIRE(zero(0, 1) == 0.0f);
    REQUIRE(zero(0, 2) == 0.0f);
    REQUIRE(zero(1, 0) == 0.0f);
    REQUIRE(zero(1, 1) == 0.0f);
    REQUIRE(zero(1, 2) == 0.0f);
    REQUIRE(zero(2, 0) == 0.0f);
    REQUIRE(zero(2, 1) == 0.0f);
    REQUIRE(zero(2, 2) == 0.0f);

    vector3 column1{1.0f, 2.0f, 3.0f};
    vector3 column2{5.0f, 5.0f, 6.0f};
    vector3 column3{7.0f, 8.0f, 9.0f};
    affine2d column_init{column1, column2, column3};
    REQUIRE(column_init(0, 0) == column1.x);
    REQUIRE(column_init(0, 1) == column1.y);
    REQUIRE(column_init(0, 2) == column1.z);
    REQUIRE(column_init(1, 0) == column2.x);
    REQUIRE(column_init(1, 1) == column2.y);
    REQUIRE(column_init(1, 2) == column2.z);
    REQUIRE(column_init(2, 0) == column3.x);
    REQUIRE(column_init(2, 1) == column3.y);
    REQUIRE(column_init(2, 2) == column3.z);

    float column0_row0 = 9.0f, column0_row1 = 9.0f, column0_row2 = 7.0f, column1_row0 = 6.0f,
          column1_row1 = 5.0f, column1_row2 = 4.0f, column2_row0 = 3.0f, column2_row1 = 2.0f,
          column2_row2 = 1.0f;
    affine2d explicit_init{column0_row0, column0_row1, column0_row2, column1_row0, column1_row1,
                           column1_row2, column2_row0, column2_row1, column2_row2};
    REQUIRE(explicit_init(0, 0) == column0_row0);
    REQUIRE(explicit_init(0, 1) == column0_row1);
    REQUIRE(explicit_init(0, 2) == column0_row2);
    REQUIRE(explicit_init(1, 0) == column1_row0);
    REQUIRE(explicit_init(1, 1) == column1_row1);
    REQUIRE(explicit_init(1, 2) == column1_row2);
    REQUIRE(explicit_init(2, 0) == column2_row0);
    REQUIRE(explicit_init(2, 1) == column2_row1);
    REQUIRE(explicit_init(2, 2) == column2_row2);
}

TEST_CASE("affine2d element access")
{
    const affine2d const_matrix{1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f, 7.0f, 8.0f, 9.0f};
    REQUIRE(const_matrix(0, 0) == 1.0f);
    REQUIRE(const_matrix(0, 1) == 2.0f);
    REQUIRE(const_matrix(0, 2) == 3.0f);
    REQUIRE(const_matrix(1, 0) == 4.0f);
    REQUIRE(const_matrix(1, 1) == 5.0f);
    REQUIRE(const_matrix(1, 2) == 6.0f);
    REQUIRE(const_matrix(2, 0) == 7.0f);
    REQUIRE(const_matrix(2, 1) == 8.0f);
    REQUIRE(const_matrix(2, 2) == 9.0f);

    affine2d m;
    m(0, 0) = 1.0f;
    REQUIRE(m(0, 0) == 1.0f);
    m(0, 1) = 2.0f;
    REQUIRE(m(0, 1) == 2.0f);
    m(0, 2) = 3.0f;
    REQUIRE(m(0, 2) == 3.0f);
    m(1, 0) = 4.0f;
    REQUIRE(m(1, 0) == 4.0f);
    m(1, 1) = 5.0f;
    REQUIRE(m(1, 1) == 5.0f);
    m(1, 2) = 6.0f;
    REQUIRE(m(1, 2) == 6.0f);
    m(2, 0) = 7.0f;
    REQUIRE(m(2, 0) == 7.0f);
    m(2, 1) = 8.0f;
    REQUIRE(m(2, 1) == 8.0f);
    m(2, 2) = 9.0f;
    REQUIRE(m(2, 2) == 9.0f);
}



TEST_CASE("affine2d transpose")
{
    vector3 column_u{-1, 3.5f, 0};
    vector3 column_v{2.5f, 4.0f, 0};
    vector3 column_w{5.3f, -2.4f, 1};
    affine2d original{column_u, column_v, column_w};
    affine2d transposed = original.transpose();

    REQUIRE(transposed(0, 0) == column_u.x);
    REQUIRE(transposed(0, 1) == column_v.x);
    REQUIRE(transposed(0, 2) == column_w.x);
    REQUIRE(transposed(1, 0) == column_u.y);
    REQUIRE(transposed(1, 1) == column_v.y);
    REQUIRE(transposed(1, 2) == column_w.y);
    REQUIRE(transposed(2, 0) == column_u.z);
    REQUIRE(transposed(2, 1) == column_v.z);
    REQUIRE(transposed(2, 2) == column_w.z);
}

TEST_CASE("affine2d rotation")
{
    float cos225 = std::cos(3.0f * pi / 8.0f);
    float sin225 = std::sin(3.0f * pi / 8.0f);
    const affine2d rotate45{{cos225, sin225, 0}, {-sin225, cos225, 0}, {0, 0, 1}};
    affine2d rotation = build_affine_rotation(3.0f * pi / 8.0f);

    REQUIRE(rotation(0, 0) == rotate45(0, 0));
    REQUIRE(rotation(0, 1) == rotate45(0, 1));
    REQUIRE(rotation(1, 0) == rotate45(1, 0));
    REQUIRE(rotation(1, 1) == rotate45(1, 1));

    rotation = build_affine_rotation(pi);
	
	
	
    REQUIRE((rotation(0, 0) - -1.0f) <= epsilon);
    REQUIRE((rotation(0, 1) - 0) <= epsilon);
    REQUIRE((rotation(0, 2) - 0) <= epsilon);
    REQUIRE((rotation(1, 0) - 0) <= epsilon);
    REQUIRE((rotation(1, 1) - -1.0f) <= epsilon);
    REQUIRE((rotation(1, 2) - 0) <= epsilon);
    REQUIRE((rotation(2, 0) - 0) <= epsilon);
    REQUIRE((rotation(2, 1) - 0) <= epsilon);
    REQUIRE((rotation(2, 2) - 1) <= epsilon);
}

TEST_CASE("affine2d identity")
{
    const affine2d identity{1.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f};
    affine2d identity_result = build_affine_identity();
    REQUIRE(identity_result(0, 0) == identity(0, 0));
    REQUIRE(identity_result(0, 1) == identity(0, 1));
    REQUIRE(identity_result(0, 2) == identity(0, 2));
    REQUIRE(identity_result(1, 0) == identity(1, 0));
    REQUIRE(identity_result(1, 1) == identity(1, 1));
    REQUIRE(identity_result(1, 2) == identity(1, 2));
    REQUIRE(identity_result(2, 0) == identity(2, 0));
    REQUIRE(identity_result(2, 1) == identity(2, 1));
    REQUIRE(identity_result(2, 2) == identity(2, 2));
}

TEST_CASE("affine2d scale")
{
    const affine2d ten{10.0f, 0.0f, 0.0f, 0.0f, 10.0f, 0.0f, 0, 0, 1};
    affine2d uniform_scale = build_affine_scale(10.0f);
    REQUIRE(uniform_scale(0, 0) == ten(0, 0));
    REQUIRE(uniform_scale(0, 1) == ten(0, 1));
    REQUIRE(uniform_scale(0, 2) == ten(0, 2));
    REQUIRE(uniform_scale(1, 0) == ten(1, 0));
    REQUIRE(uniform_scale(1, 1) == ten(1, 1));
    REQUIRE(uniform_scale(1, 2) == ten(1, 2));
    REQUIRE(uniform_scale(2, 0) == ten(2, 0));
    REQUIRE(uniform_scale(2, 1) == ten(2, 1));
    REQUIRE(uniform_scale(2, 2) == ten(2, 2));


    const affine2d ten_twenty{10.0f, 0.0f, 0.0f, 0.0f, 20.0f, 0.0f, 0, 0, 1};
    affine2d nonuniform_scale = build_affine_scale(10.0f, 20.0f);
    REQUIRE(nonuniform_scale(0, 0) == ten_twenty(0, 0));
    REQUIRE(nonuniform_scale(0, 1) == ten_twenty(0, 1));
    REQUIRE(nonuniform_scale(0, 2) == ten_twenty(0, 2));
    REQUIRE(nonuniform_scale(1, 0) == ten_twenty(1, 0));
    REQUIRE(nonuniform_scale(1, 1) == ten_twenty(1, 1));
    REQUIRE(nonuniform_scale(1, 2) == ten_twenty(1, 2));
    REQUIRE(nonuniform_scale(2, 0) == ten_twenty(2, 0));
    REQUIRE(nonuniform_scale(2, 1) == ten_twenty(2, 1));
    REQUIRE(nonuniform_scale(2, 2) == ten_twenty(2, 2));
}


TEST_CASE("affine2d translation")
{
    float tx = 4.0f, ty = -3.0f;
    const affine2d right4down3 = {{1, 0, 0}, {0, 1, 0}, {tx, ty, 1}};
    affine2d translation_matrix = build_affine_translation(tx, ty);
    REQUIRE(translation_matrix(0, 0) == right4down3(0, 0));
    REQUIRE(translation_matrix(0, 1) == right4down3(0, 1));
    REQUIRE(translation_matrix(0, 2) == right4down3(0, 2));
    REQUIRE(translation_matrix(1, 0) == right4down3(1, 0));
    REQUIRE(translation_matrix(1, 1) == right4down3(1, 1));
    REQUIRE(translation_matrix(1, 2) == right4down3(1, 2));
    REQUIRE(translation_matrix(2, 0) == right4down3(2, 0));
    REQUIRE(translation_matrix(2, 1) == right4down3(2, 1));
    REQUIRE(translation_matrix(2, 2) == right4down3(2, 2));
}

TEST_CASE("affine2d matrix multiplcation")
{
    const affine2d identity{1.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f};
    const affine2d one23456789{1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f, 7.0f, 8.0f, 9.0f};
    affine2d identity_result = identity * one23456789;
    REQUIRE(identity_result(0, 0) == one23456789(0, 0));
    REQUIRE(identity_result(0, 1) == one23456789(0, 1));
    REQUIRE(identity_result(0, 2) == one23456789(0, 2));
    REQUIRE(identity_result(1, 0) == one23456789(1, 0));
    REQUIRE(identity_result(1, 1) == one23456789(1, 1));
    REQUIRE(identity_result(1, 2) == one23456789(1, 2));
    REQUIRE(identity_result(2, 0) == one23456789(2, 0));
    REQUIRE(identity_result(2, 1) == one23456789(2, 1));
    REQUIRE(identity_result(2, 2) == one23456789(2, 2));

    identity_result = one23456789 * identity;
    REQUIRE(identity_result(0, 0) == one23456789(0, 0));
    REQUIRE(identity_result(0, 1) == one23456789(0, 1));
    REQUIRE(identity_result(0, 2) == one23456789(0, 2));
    REQUIRE(identity_result(1, 0) == one23456789(1, 0));
    REQUIRE(identity_result(1, 1) == one23456789(1, 1));
    REQUIRE(identity_result(1, 2) == one23456789(1, 2));
    REQUIRE(identity_result(2, 0) == one23456789(2, 0));
    REQUIRE(identity_result(2, 1) == one23456789(2, 1));
    REQUIRE(identity_result(2, 2) == one23456789(2, 2));

    vector2 u = normalize(vector2{10, -3});
    vector2 v = perpendicular_to(u);
    vector2 t = {-1.23f, 1.98f}; // !!warning. too big argument can cause problem in precision
    affine2d uvt{{u.x, u.y, 0}, {v.x, v.y, 0}, {t.x, t.y, 1}};
    affine2d uvt_inverse{{u.x, v.x, 0}, {u.y, v.y, 0}, {-dot(u, t), -dot(v, t), 1}};
    affine2d to_identity = uvt * uvt_inverse;

	
	
	
    REQUIRE(std::abs(to_identity(0, 0) - identity(0, 0)) <= epsilon);
    REQUIRE(std::abs(to_identity(0, 1) - identity(0, 1)) <= epsilon);
    REQUIRE(std::abs(to_identity(0, 2) - identity(0, 2)) <= epsilon);
    REQUIRE(std::abs(to_identity(1, 0) - identity(1, 0)) <= epsilon);
    REQUIRE(std::abs(to_identity(1, 1) - identity(1, 1)) <= epsilon);
    REQUIRE(std::abs(to_identity(1, 2) - identity(1, 2)) <= epsilon);
    REQUIRE(std::abs(to_identity(2, 0) - identity(2, 0)) <= epsilon);
    REQUIRE(std::abs(to_identity(2, 1) - identity(2, 1)) <= epsilon);
    REQUIRE(std::abs(to_identity(2, 2) - identity(2, 2)) <= epsilon);


    to_identity = uvt_inverse * uvt;
    REQUIRE(std::abs(to_identity(0, 0) - identity(0, 0)) <= epsilon);
    REQUIRE(std::abs(to_identity(0, 1) - identity(0, 1)) <= epsilon);
    REQUIRE(std::abs(to_identity(0, 2) - identity(0, 2)) <= epsilon);
    REQUIRE(std::abs(to_identity(1, 0) - identity(1, 0)) <= epsilon);
    REQUIRE(std::abs(to_identity(1, 1) - identity(1, 1)) <= epsilon);
    REQUIRE(std::abs(to_identity(1, 2) - identity(1, 2)) <= epsilon);
    REQUIRE(std::abs(to_identity(2, 0) - identity(2, 0)) <= epsilon);
    REQUIRE(std::abs(to_identity(2, 1) - identity(2, 1)) <= epsilon);
    REQUIRE(std::abs(to_identity(2, 2) - identity(2, 2)) <= epsilon);

    float cos45 = std::cos(pi / 4.0f);
    float sin45 = std::cos(pi / 4.0f);
    affine2d rotate45AndScale1020{{cos45, sin45, 0}, {-sin45, cos45, 0}, {0, 0, 1}};
    affine2d scale = {{10.0f, 0, 0}, {0, 20.0f, 0}, {0, 0, 1}};
    rotate45AndScale1020 *= scale;
    REQUIRE(rotate45AndScale1020(0, 0) == 10.0f * cos45);
    REQUIRE(rotate45AndScale1020(0, 1) == 20.0f * sin45);
    REQUIRE(rotate45AndScale1020(1, 0) == -10.0f * sin45);
    REQUIRE(rotate45AndScale1020(1, 1) == 20.0f * cos45);
}

TEST_CASE("matrix2 rotation")
{
    float cos225 = std::cos(3.0f * pi / 8.0f);
    float sin225 = std::sin(3.0f * pi / 8.0f);
    matrix2 rotate45{cos225, sin225, -sin225, cos225};
    matrix2 rotation = build_rotation(3.0f * pi / 8.0f);


    REQUIRE((rotation(0, 0) - rotate45(0, 0)) <= epsilon);
    REQUIRE((rotation(0, 1) - rotate45(0, 1)) <= epsilon);
    REQUIRE((rotation(1, 0) - rotate45(1, 0)) <= epsilon);
    REQUIRE((rotation(1, 1) - rotate45(1, 1)) <= epsilon);

    rotation = build_rotation(pi);


    REQUIRE((rotation(0, 0) - -1.0f) <= epsilon);
    REQUIRE((rotation(0, 1) - 0) <= epsilon);
    REQUIRE((rotation(1, 0) - 0) <= epsilon);
    REQUIRE((rotation(1, 1) - -1.0f) <= epsilon);
	
}
