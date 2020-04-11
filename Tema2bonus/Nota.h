#pragma once
#include "Exceptie.h"
#include <iostream>

class Nota {
protected:
	short zi;
	short ora;
public:
	Nota(const short, const short);
	virtual ~Nota() = 0;
	Nota& operator=(const Nota&);
	virtual bool operator==(const Nota&) const;
	virtual void afiseaza() const;
	short rZi() const;
	short rOra() const;
};

