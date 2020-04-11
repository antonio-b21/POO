#include "Apel.h"

Apel::Apel(const short zi, const short ora, const String& nrTelefon): Nota(zi, ora), nrTelefon(nrTelefon) {
	if (nrTelefon.lungime() != 10) {
		throw new Exceptie("Numar de telefon invalid");
	}
}

Apel::~Apel() {}

Apel& Apel::operator=(const Apel& apel) {
	if (this != &apel) {
		Nota::operator=(apel);
		nrTelefon = apel.nrTelefon;
	}
	return *this;
}

bool Apel::operator==(const Apel& apel) const {
	return (Nota::operator==(apel) and nrTelefon == apel.nrTelefon);
}

void Apel::afiseaza() const { std::cout << "Apel,    "; Nota::afiseaza(); std::cout << ", nrTelefon: "; nrTelefon.afiseaza(); }

String Apel::rNrTelefon() const {
	return this->nrTelefon;
}
