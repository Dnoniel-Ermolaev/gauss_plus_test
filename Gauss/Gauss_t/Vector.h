#pragma once
#include "Header.h"

class Vector
{
	//ERRORS W;
	int size;
	double* value;
public:
	void RANDOM(int argc, double* b);
	void term();
	Vector(int n = 1);
	Vector(int n, double* v);
	Vector(int n, int max);
	Vector(const Vector& v);
	~Vector();
	void swap(int a, int b);
	Vector& operator=(const Vector& v);
	Vector operator+(const Vector& v) const;
	Vector operator-(const Vector& v) const;
	Vector& operator-=(const Vector& v);
	Vector& operator+=(const Vector& v);
	friend Vector operator*(double p, const Vector& v);
	friend Vector operator*(const Vector& v, double p);
	double& operator[](int i);
	const double& operator[](int i) const;
	bool operator==(const Vector& v) const;
	int GetSize() const;
	friend std::ostream& operator<<(std::ostream& os, const Vector& v);
	friend std::istream& operator >> (std::istream& is, const Vector& v);
	friend class Solver;
};