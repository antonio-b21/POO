#include "Fractie.h"

Fractie::Fractie() {
	numarator = 0;
	numitor = 1;
}
Fractie::Fractie(int numa, int numi) {
	numarator = numa;
	if (numi != 0)
		numitor = numi;
	//ce fac daca numitorul este 0?
	Simplificare();
}
Fractie::Fractie(const Fractie& fract) {
	numarator = fract.numarator;
	numitor = fract.numitor;
}
Fractie::~Fractie() {
	//cout<<"Sterge "<<*this<<"\n";
	;
}
void Fractie::SeteazaNumarator(int numa) {
	numarator = numa;
	Simplificare();
}
void Fractie::SeteazaNumitor(int numi) {
	numitor = numi;
	Simplificare();
}
int Fractie::FurnizeazaNumarator() {
	return numarator;
}
int Fractie::FurnizeazaNumitor() {
	return numitor;
}
void Fractie::Simplificare() {
	if (numarator == 0) {
		numitor = 1;
	}
	else {
		if (numitor < 0) {
			numarator *= -1;
			numitor *= -1;
		}
		int minim = min(abs(numarator), numitor);
		for (int i = 2; i <= minim; i++) {
			while (numarator % i == 0 and numitor % i == 0) {
				numarator /= i;
				numitor /= i;
				minim /= i;
			}
		}
	}
}
ostream& operator << (ostream& os, const Fractie& frac) {
	if (frac.numitor == 1)
		os << frac.numarator;
	else
		os << frac.numarator << "/" << frac.numitor;
	return os;
}
istream& operator >> (istream& os, Fractie& frac) {
	cout << "Numarator=";
	os >> frac.numarator;
	cout << "Numitor=  ";
	os >> frac.numitor;
	frac.Simplificare();
	return os;
}
Fractie Fractie::operator + (const Fractie& frac) {
	Fractie rez;
	rez.numitor = numitor * frac.numitor;
	rez.numarator = numarator * frac.numitor + numitor * frac.numarator;
	rez.Simplificare();
	return rez;
}
Fractie Fractie::operator - (const Fractie& frac) {
	Fractie rez;
	rez.numitor = numitor * frac.numitor;
	rez.numarator = numarator * frac.numitor - numitor * frac.numarator;
	rez.Simplificare();
	return rez;
}
Fractie Fractie::operator * (const Fractie& frac) {
	Fractie rez;
	rez.numarator = numarator * frac.numarator;
	rez.numitor = numitor * frac.numitor;
	rez.Simplificare();
	return rez;
}
Fractie Fractie::operator / (const Fractie& frac) {
	Fractie rez;
	rez.numarator = numarator * frac.numitor;
	rez.numitor = numitor * frac.numarator;  //Ce faci daca frac.numarator e 0?
	rez.Simplificare();
	return rez;
}
bool Fractie::operator != (int num) {
	if (numitor == 1)
		return (numarator != num);
	return 1;
}
bool Fractie::operator == (int num) {
	if (numitor == 1)
		return (numarator == num);
	return 0;
}
Fractie operator * (const Fractie& frac, int scl) {
	Fractie rez;
	rez.numarator = frac.numarator * scl;
	rez.numitor = frac.numitor;
	rez.Simplificare();
	return rez;
}
Fractie operator * (int scl, const Fractie& frac) {
	Fractie rez;
	rez = frac * scl;
	return rez;
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