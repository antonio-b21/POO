#include "Fractie.h"

Fractie::Fractie(): numarator(0), numitor(1) {}
Fractie::Fractie(int numarator, int numitor): numarator(numarator) {
	if (numitor != 0)
		this->numitor = numitor;
	//ce fac daca numitorul este 0?
	Simplificare();
}
Fractie::Fractie(const Fractie& frac): numarator(frac.numarator), numitor(frac.numitor) {}
Fractie::~Fractie() {}
void Fractie::SeteazaNumarator(int numarator) {
	this->numarator = numarator;
	Simplificare();
}
void Fractie::SeteazaNumitor(int numitor) {
	this->numitor = numitor;
	Simplificare();
}
int Fractie::FurnizeazaNumarator() const {
	return numarator;
}
int Fractie::FurnizeazaNumitor() const {
	return numitor;
}
void Fractie::Simplificare() {
	if (numarator == 0) {
		numitor = 1;
	} else {
		if (numitor < 0) {
			numarator *= -1, numitor *= -1;
		}
		int minim = min(abs(numarator), numitor);
		for (int i = 2; i <= minim; i++) {
			while (numarator % i == 0 and numitor % i == 0) {
				numarator /= i, numitor /= i, minim /= i;
			}
		}
	}
}
ostream& operator<< (ostream& os, const Fractie& frac) {
	os << frac.numarator;
	if (frac.numitor != 1) {
		os << "/" << frac.numitor;
	}
	return os;
}
istream& operator>> (istream& os, Fractie& frac) {
	cout << "Numarator=";
	os >> frac.numarator;
	if (frac.numarator == 0) {
		frac.numitor = 1;
	} else {
		cout << "Numitor=  ";
		os >> frac.numitor;
	}
	frac.Simplificare();
	return os;
}
Fractie Fractie::operator+ (const Fractie& frac) const {
	Fractie rez;
	rez.numitor = numitor * frac.numitor;
	rez.numarator = numarator * frac.numitor + numitor * frac.numarator;
	rez.Simplificare();
	return rez;
}
Fractie Fractie::operator- (const Fractie& frac) const {
	Fractie rez;
	rez.numitor = numitor * frac.numitor;
	rez.numarator = numarator * frac.numitor - numitor * frac.numarator;
	rez.Simplificare();
	return rez;
}
Fractie Fractie::operator* (const Fractie& frac) const {
	Fractie rez;
	rez.numarator = numarator * frac.numarator;
	rez.numitor = numitor * frac.numitor;
	rez.Simplificare();
	return rez;
}
Fractie Fractie::operator/ (const Fractie& frac) const {
	Fractie rez;
	rez.numarator = numarator * frac.numitor;
	rez.numitor = numitor * frac.numarator;
	//ce fac daca frac.numarator e 0?
	rez.Simplificare();
	return rez;
}
Fractie operator* (const Fractie& frac, int scalar) {
	Fractie rez(frac.numarator * scalar, frac.numitor);
	rez.Simplificare();
	return rez;
}
Fractie operator* (int scalar, const Fractie& frac) {
	return frac * scalar;
}
bool Fractie::operator!= (int numar) const {
	if (numitor == 1) {
		return (numarator != numar);
	}
	return 1;
}
bool Fractie::operator== (int numar) const {
	if (numitor == 1) {
		return (numarator == numar);
	}
	return 0;
}
Fractie* CitMemAfis(int nr) {
	Fractie* fractii = new Fractie[nr];
	for (int i = 0; i < nr; i++) {
		cout << "F" << i + 1 << ":\n";
		cin >> fractii[i];
	}
	cout << "\n";
	for (int i = 0; i < nr; i++) {
		cout << "F" << i + 1 << "= " << fractii[i] << "; ";
	}
	cout << "\n";
	return fractii;
}