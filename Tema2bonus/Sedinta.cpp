#include "Sedinta.h"

Sedinta::Sedinta(const short zi, const short ora, float durata, const String& subiect): Nota(zi, ora), durata(durata), subiect(subiect) {
	if (durata <= 0) {
		throw new Exceptie("Durata invalida");
	}
}

Sedinta::~Sedinta() { durata = 0; }

Sedinta& Sedinta::operator=(const Sedinta& sedinta) {
	if (this != &sedinta) {
		Nota::operator=(sedinta);
		durata = sedinta.durata;
		subiect = sedinta.subiect;
	}
	return *this;
}

bool Sedinta::operator==(const Sedinta& sedinta) const {
	return (Nota::operator==(sedinta) and durata == sedinta.durata and subiect == sedinta.subiect);
}

void Sedinta::afiseaza() const { std::cout << "Sedinta,";  Nota::afiseaza(); std::cout << ", durata: " << durata << ", subiect: "; subiect.afiseaza(); }

float Sedinta::rDurata() const {
	return this->durata;
}

String Sedinta::rSubiect() const {
	return this->subiect;
}
