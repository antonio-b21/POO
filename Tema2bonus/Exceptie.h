#pragma once
#include "String.h"

class Exceptie {
	String mesaj;
public:
	Exceptie(const String&);
	~Exceptie();
	void afiseaza() const;
};

