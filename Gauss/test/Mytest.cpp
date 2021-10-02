#include "Solver.h"
#include "header.h"
#include "../Test_gauss/gtest.h"
#define RANDOM 100

TEST(myTest,cosntructor_vector){
	int R = 5;
	ASSERT_NO_THROW(Vector(R));
}
TEST(myTest, cosntructor_matrix) {
	int R = 5;
	ASSERT_NO_THROW(matrix(R,R));
}
TEST(myTest, summ_vector) {
	int A = 10;
	double R[10] = {1,2,3,4,5,6,7,8,9,10};
	int B = 5;
	double S[5] = { 1,2,3,4,5};
	Vector v1(A,R);
	Vector v2(B,S);
	Vector v3;
	v3 = v2 + v1;
	double P[10]{ 2,4,6,8,10,6,7,8,9,10};
	Vector v4(10,P);
	ASSERT_TRUE(v3==v4);
}

TEST(myTest, SOLV_test) {
	int R = 5;
	matrix A(R, R, RANDOM);
	Vector x(R), b(R, RANDOM);
	Solver SOLV(A, x, b);
	SOLV.PrintM(1);
	SOLV.Gauss();
	SOLV.PrintM(2);
	SOLV.PrintX();
	SOLV.Check();
	cout << endl;
	cout << "Proverka: A*x=" << endl;
	SOLV.PrintB();
	ASSERT_TRUE( SOLV.Check() );
}