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
	Fractie CalculeazaDet(int col);
	void DeterminaRang();
	void Incompatibil();
	void Determinat();
	void Nedeterminat();
public:
	friend istream& operator >> (istream& os, Sistem& sis);
	friend ostream& operator << (ostream& os, const Sistem& sis);
	void Rezolva();
};

