#pragma once
#include <iostream>
using namespace std;
class Complex {
	float re, im;
public:
	Complex();
	Complex(float, float);
	Complex(const Complex&);
	~Complex();
	Complex& operator= (const Complex&);
	bool eImaginar();
	friend ostream& operator<<(ostream&, const Complex&);
	friend istream& operator>>(istream&, Complex&);
};

