#pragma once
#include "Sedinta.h"
#include "Apel.h"
#include "Exceptie.h"
#include <vector>

class Remainder {
	std::vector<Nota*> note;
public:
	Remainder();
	Remainder(const Remainder&);
	~Remainder();
	Remainder operator+(const Remainder&) const;
	Remainder& operator=(const Remainder&);
	Nota& operator[](const unsigned);
	void adSedinta(const short, const short, float, const char*);
	void adApel(const short, const short, const char*);
	void afiseaza(const short = 1, const short = 0) const;
	void urmeaza(const short, const short) const;

};
