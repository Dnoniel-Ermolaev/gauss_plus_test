#include "Vector.h"
#include <cstdlib>
#include <ctime>

void Vector::RANDOM(int argc, double* b)
{
	unsigned int time_ui = unsigned int(time(NULL));
	MersenTw* numberG;
	numberG = MersenTw::getInstance();
	numberG->changeSeed(time_ui);
	if (NULL == numberG)
	{
		throw"WARNING";
	}
	for (int i = 0; i < size; i++)
			b[i] = numberG->getFloat();
	term();
}

void Vector::term()
{
	MersenTw* numberG = MersenTw::getInstance();
	if (NULL != numberG)
	{
		// destroy singleton object
		numberG->release();
		numberG = NULL;
	}
}

Vector::Vector(int n)
{
	value = new double[n];
	size = n;
	for (int i = 0; i < n; i++)
	{
		value[i] = 0.0;
	}
}

Vector::Vector(int n, double * v)
{
	value = new double[n];
	size = n;
	for (int i = 0; i < n; i++)
	{
		value[i] = v[i];
	}
}

Vector::Vector(int n, int max)
{
	srand((unsigned int)time(NULL));
	value = new double[n];
	size = n;
	RANDOM(size, value);
}

Vector::Vector(const Vector & v)
{
	size = v.size;
	value = new double[size];
	for (int i = 0; i < size; i++)
	{
		value[i] = v.value[i];
	}
}

Vector::~Vector()
{
	delete[] value;
}

void Vector::swap(int a, int b)
{
	double tmp = 0.0;
	tmp = value[a];
	value[a] = value[b];
	value[b] = tmp;
}

Vector & Vector::operator=(const Vector & v)
{
	if (this == &v)
		return *this;
	else if (size == v.size)
	{
		for (int i = 0; i < size; i++)
			value[i] = v.value[i];
		return *this;
	}
	else
	{
		delete[] value;

		size = v.size;
		value = new double[size];
		for (int i = 0; i < size; i++)
			value[i] = v.value[i];
		return *this;
	}
}

Vector Vector::operator+(const Vector & v) const
{
	int max = (size > v.size) ? size : v.size;
	int min = (size > v.size) ? v.size : size;
	Vector res(max);
	for (int i = 0; i < min; i++)
		res.value[i] = value[i] + v.value[i];
	if (size > v.size)
		for (int i = min; i < max; i++)
			res.value[i] = value[i];
	else
		for (int i = min; i < max; i++)
			res.value[i] = v.value[i];
	return res;
}

Vector Vector::operator-(const Vector & v) const
{
	int max = (size > v.size) ? size : v.size;
	int min = (size > v.size) ? v.size : size;
	Vector res(max);
	for (int i = 0; i < min; i++)
		res.value[i] = value[i] - v.value[i];
	if (size > v.size)
		for (int i = min; i < max; i++)
			res.value[i] = value[i];
	else
		for (int i = min; i < max; i++)
			res.value[i] = -v.value[i];
	return res;
}

Vector & Vector::operator-=(const Vector & v)
{
	int max = (size > v.size) ? size : v.size;
	int min = (size > v.size) ? v.size : size;
	int i = 0;
	double* res = new double[max];
	for (i = 0; i < min; i++)
		res[i] = value[i] - v.value[i];
	if (size > v.size)
		for (i = min; i < max; i++)
			res[i] = value[i];
	else
		for (i = min; i < max; i++)
			res[i] = -v.value[i];
	delete[] value;
	size = max;
	value = res;
	return *this;
}

Vector & Vector::operator+=(const Vector & v)
{
	int max = (size > v.size) ? size : v.size;
	int min = (size > v.size) ? v.size : size;
	int i = 0;
	double* res = new double[max];
	for (i = 0; i < min; i++)
		res[i] = value[i] + v.value[i];
	if (size > v.size)
		for (i = min; i < max; i++)
			res[i] = value[i];
	else
		for (i = min; i < max; i++)
			res[i] = v.value[i];
	delete[] value;
	value = res;
	size = max;
	return *this;
}

Vector operator*(double p, const Vector& v)
{
	Vector res(v.size);
	for (int i = 0; i < v.size; i++)
	{
		res.value[i] = p * v.value[i];
	}
	return res;
}

Vector operator*(const Vector& v, double p)
{
	Vector res(v.size);
	for (int i = 0; i < v.size; i++)
	{
		res.value[i] = v.value[i] * p;
	}
	return res;
}

double & Vector::operator[](int i)
{
	if (i >= 0 && i < size)
		return value[i];
	else
		return value[0];
}

const double& Vector::operator[](int i) const
{
	if (i >= 0 && i < size)
		return value[i];
	else
		return value[0];
}

bool Vector::operator==(const Vector& v) const
{
	int i = 0;
	while (i < size)
	{
		if (abs(value[i] - v.value[i]) < EPS)
			i++;
		else
			return false;
	}
	return true;
}

int Vector::GetSize() const
{
	return size;
}

std::ostream & operator<<(std::ostream & os, const Vector & v)
{
	os.width(7);
	os.precision(2);
	for (int i = 0; i < v.size; i++)
		os << std::fixed << v.value[i] << " ";
	os << std::endl;
	return os;
}

std::istream& operator >> (std::istream& is, const Vector& v)
{
	for (int i = 0; i < v.size; i++)
	{
		std::cout << "[" << i << "] = ";
		is >> v.value[i];
	}
	return is;
}
