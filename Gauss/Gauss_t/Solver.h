#include "Matrix.h"

class Solver
{
	int i, j, m;
	int size=NULL;
	double aa, bb;
	double t1, t2, a;
	//ERRORS W;
	matrix A;
	Vector x, b;
	matrix tA;
	Vector tb;
	matrix copyA = A;
	Vector copyb = b;
public:
	Solver(const matrix& A, const Vector& x, const Vector& b); //���������� ��� ��������� ������,�������� ��� ������� ������ ������.
	Solver();//��������������� ���� �����, ���� ������ �����
	void Gauss();
	void PrintM( int t); 
	void PrintX();
	void PrintB();
	bool Check();
}; 
