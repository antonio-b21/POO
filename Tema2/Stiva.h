#pragma once
#include "Vector.h"

class Stiva: public Vector {
public:
	Stiva();
	Stiva(int);
	Stiva(const Stiva&);
	~Stiva();
	Stiva& operator=(const Stiva&);
	void push(const Complex&);
	Complex pop();
	friend ostream& operator<<(ostream&, const Stiva&);
};

