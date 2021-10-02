#include <iostream>
#include "Solver.h"
#include "header.h"
#include "Vector.h"

#define RANDOM 100
void menu() {
	cout << "�������� ����� ������� ��������� ��� ����������:" << endl;
	cout << "������� 1, ���� �� ������ ������ ������� � � ������ b ��������������." << endl;
	cout << "������� 2, ���� �� ������ ��������� ������� � � ������ b ��������� �������." << endl;
	cout << "�����:";
}

int  main()
{
	
	setlocale(LC_ALL, "Russian");
	int R = NULL;
	int t = NULL;
	menu();
	cin >> t;
	if ((t == 0) || ((t != 1) && (t != 2)))
	{
		throw "WARNING";
	}

	switch (t)
	{
	case 1:
	{
		
		Solver SOLV;
		SOLV.PrintM(1);
		SOLV.Gauss();
		SOLV.PrintM(2);
		SOLV.PrintX();
		SOLV.Check();
		cout << endl;
		cout << "��������: A*x=" << endl;
		SOLV.PrintB();
		break;
	}
	case 2:
	{
		cout << "������� ������� �������:";
		cin >> R;

		if (R < 0)
		{
			throw "WARNING";
		}

		matrix A(R, R, RANDOM);
		Vector x(R), b(R, RANDOM);
		Solver SOLV(A, x, b);
		SOLV.PrintM(1);
		SOLV.Gauss();
		SOLV.PrintM(2);
		SOLV.PrintX();
		SOLV.Check();
		cout << endl;
		cout << "��������: A*x=" << endl;
		SOLV.PrintB();
		break;
	}
	}
	system("Pause");
	return 0;
}