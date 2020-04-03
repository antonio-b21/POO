#include "Stiva.h"

Stiva::Stiva(): Vector() {}

Stiva::Stiva(int dim): Vector(dim) {}

Stiva::Stiva(const Stiva& sti): Vector(sti) {}

Stiva::~Stiva() {}

Stiva& Stiva::operator=(const Stiva& sti) {
	if (this != &sti) {
		Vector::operator=(sti);
	}
	return *this;
}

void Stiva::push(const Complex& nr) {
	Stiva aux(*this);
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

Complex Stiva::pop() {
	Stiva aux(*this);
	delete[] v;
	v = new Complex[--dim];
	for (int i = 0; i < dim; i++) {
		v[i] = aux.v[i];
	}
	return aux.v[dim];
}

bool Stiva::eImaginara() const {
	for (int i = 0; i < dim; i++) {
		if (v[i].eImaginar() == false) {
			return false;
		}
	}
	return true;
}

ostream& operator<<(ostream& os, const Stiva& sti) {
	os << "Stiva:" << static_cast<Vector>(sti);
	return os;
}
