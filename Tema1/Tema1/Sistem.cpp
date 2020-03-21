#include "Sistem.h"

int Sistem::nrEcuatii = 2;

istream& operator>> (istream& os, Sistem& sis) {
	for (int i = 0; i < sis.nrEcuatii; i++) {
		cout << "Ecuatia " << i + 1 << ": F1*x + F2*y = F3\n";
		sis.ec[i] = CitMemAfis(sis.nrEcuatii + 1);
		cout << "-----------------------------------\n";
	}
	sis.DeterminaRang();
	return os;
}
ostream& operator<< (ostream& os, const Sistem& sis) {
	for (int i = 0; i < sis.nrEcuatii; i++) {
		os << "(" << sis.ec[i][0] << ")*x + (" << sis.ec[i][1] << ")*y = (" << sis.ec[i][2] << ")\n";
	}
	return os;
}
Fractie Sistem::CalculeazaDet(int col) {
	int* in = new int[nrEcuatii];
	for (int i = 0; i < nrEcuatii; i++) {
		if (i != col) {
			in[i] = i;
		} else {
			in[i] = nrEcuatii;
		}
	}
	Fractie det1 = ec[0][in[0]] * ec[1][in[1]];
	Fractie det2 = ec[1][in[0]] * ec[0][in[1]];
	Fractie det = det1 - det2;
	delete[] in;
	return det;
}
void Sistem::DeterminaRang() {
	Fractie det = CalculeazaDet(nrEcuatii);
	if (det != 0) {
		rang = 2;
		detPrin = det;
		col = -1, lin = -1;
	} else {
		if		  (ec[0][0] != 0 and CalculeazaDet(1) == 0) {
			rang = 1;
			detPrin = ec[0][0];
			lin = 0, col = 0;
		} else if (ec[1][0] != 0 and CalculeazaDet(1) == 0) {
			rang = 1;
			detPrin = ec[1][0];
			lin = 1, col = 0;
		} else if (ec[0][1] != 0 and CalculeazaDet(0) == 0) {
			rang = 1;
			detPrin = ec[0][1];
			lin = 0, col = 1;
		} else if (ec[1][1] != 0 and CalculeazaDet(0) == 0) {
			rang = 1;
			detPrin = ec[1][1];
			lin = 1, col = 1;
		} else {
			rang = 0;
			col = -1, lin = -1;
		}
	}
}
void Sistem::Rezolva() {
	if (rang == 2) return Determinat();
	if (rang == 1) return Nedeterminat();
	if (rang == 0) return Incompatibil();
}
void Sistem::Determinat() {
	cout << "Este compatibil determinat\n\n";
	cout << "Are solutia:\n";
	Fractie detx = CalculeazaDet(0);
	Fractie dety = CalculeazaDet(1);
	Fractie x = detx / detPrin;
	Fractie y = dety / detPrin;
	cout << "x = " << x << "\n";
	cout << "y = " << y << "\n";
}
void Sistem::Nedeterminat() {
	cout << "Este compatibil nedeterminat\n\n";
	cout << "Are solutiile:\n";
	Fractie lib = ec[lin][2]	   / ec[lin][col];
	Fractie dep = ec[lin][1 - col] / ec[lin][col];
	if (col == 0) {
		cout << "x=(" << lib << ")-(" << dep << ")*a\n";
		cout << "y=a\n";
	} else if (col == 1) {
		cout << "x=a\n";
		cout << "y=(" << lib << ")-(" << dep << ")*a\n";
	}
}
void Sistem::Incompatibil() {
	cout << "Este incompatibil\n";
}

