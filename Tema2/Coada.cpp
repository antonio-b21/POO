#include "Coada.h"

Coada::Coada(): Vector() {}

Coada::Coada(int dim) : Vector(dim) {}

Coada::Coada(const Coada& coa) : Vector(coa) {}

Coada::~Coada() {}

Coada& Coada::operator=(const Coada& coa) {
	if (this != &coa) {
		Vector::operator=(coa);
	}
	return *this;
}

void Coada::push(const Complex& nr) {
	Coada aux(*this);
	delete[] v;
	try {
		v = new Complex[dim + 1];
	} catch (bad_array_new_length) {
		terminate();
	}
	for (int i = 0; i < dim; i++) {
		v[i] = aux.v[i];
	}
	v[dim++] = nr;
}

Complex Coada::pop() {
	Coada aux(*this);
	delete[] v;
	v = new Complex[--dim];
	for (int i = 0; i < dim; i++) {
		v[i] = aux.v[i + 1];
	}
	return aux.v[0];
}

bool Coada::eImaginara() const {
	for (int i = 0; i < dim; i++) {
		if (v[i].eImaginar() == false) {
			return false;
		}
	}
	return true;
}

ostream& operator<<(ostream& os, const Coada& coa) {
	os << "Coada:" << static_cast<Vector>(coa);
	return os;
}