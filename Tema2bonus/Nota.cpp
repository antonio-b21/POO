#include "Nota.h"

Nota::Nota(const short zi, const short ora): zi(zi), ora(ora) {
	if (zi <= 0 or zi > 365 or ora < 0 or ora >23) {
		throw new Exceptie("Data invalida");
	}
}

Nota::~Nota() { zi = 0; ora = 0; }

Nota& Nota::operator=(const Nota& nota) {
	if (this != &nota) {
		zi = nota.zi;
		ora = nota.ora;
	}
	return *this;
}

bool Nota::operator==(const Nota& nota) const {
	return (zi == nota.zi and ora == nota.ora);
}

void Nota::afiseaza() const { std::cout << "ziua: " << zi << ", ora: " << ora; }

short Nota::rZi() const {
	return this->zi;
}

short Nota::rOra() const {
	return this->ora;
}
