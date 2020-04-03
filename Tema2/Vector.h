#pragma once
#include "Complex.h"

class Vector {
protected:
	int dim;
	Complex* v;
public:
	Vector();
	Vector(int);
	Vector(const Vector&);
	~Vector();
	Vector& operator=(const Vector&);
	virtual void push(const Complex&, int);
	virtual Complex pop(int);
	friend ostream& operator<<(ostream&, const Vector&);
	friend istream& operator>>(istream&, Vector&);
};

