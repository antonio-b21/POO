#pragma once
#include <iostream>
#include "Fractie.h"

class Sistem {
	static int nrEcuatii;
	Fractie** ec = new Fractie * [nrEcuatii];
	int rang = 0;
	int col = 0;
	int lin = 0;
	Fractie detPrin;
	Fractie CalculeazaDet(int);
	void DeterminaRang();
	void Determinat();
	void Incompatibil();
	void Nedeterminat();
public:
	friend istream& operator>> (istream&, Sistem&);
	friend ostream& operator<< (ostream&, const Sistem&);
	void Rezolva();
};

