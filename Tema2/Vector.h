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
	virtual void push(const Complex&) = 0;
	virtual Complex pop() = 0;
	bool eImaginar() const;
	friend ostream& operator<<(ostream&, const Vector&);
	friend istream& operator>>(istream&, Vector&);
};

