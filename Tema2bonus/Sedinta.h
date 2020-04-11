#pragma once
#include "Nota.h"
#include "String.h"

class Sedinta: public Nota {
	float durata;
	String subiect;
public:
	Sedinta(const short, const short, float, const String&);
	~Sedinta();
	Sedinta& operator=(const Sedinta&);
	bool operator==(const Sedinta&) const;
	void afiseaza() const;
	float rDurata() const;
	String rSubiect() const;
};

