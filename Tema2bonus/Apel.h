#pragma once
#include "Nota.h"
#include "String.h"

class Apel: public Nota {
	String nrTelefon;
public:
	Apel(const short, const short, const String&);
	~Apel();
	Apel& operator=(const Apel&);
	bool operator==(const Apel&) const;
	void afiseaza() const;
	String rNrTelefon() const;

};

