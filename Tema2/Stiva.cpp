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
		cerr << "Memorie insuficienta";
		exit(1);
	}
	for (int i = 0; i < dim; i++) {
		v[i] = aux.v[i];
	}
	v[dim++] = nr;
}

Complex Stiva::pop() {
	Stiva aux(*this);
	delete[] v;
	try {
		v = new Complex[--dim];
	} catch (bad_array_new_length) {
		cerr << "Stiva este goala. underflow";
		exit(1);
	}
	for (int i = 0; i < dim; i++) {
		v[i] = aux.v[i];
	}
	return aux.v[dim];
}

ostream& operator<<(ostream& os, const Stiva& sti) {
	os << "Stiva:[";
	for (int i = 0; i < sti.dim - 1; i++) {
		os << sti.v[i] << ", ";
	}
	if (sti.dim > 0) {
		os << sti.v[sti.dim - 1];
	}
	os << "]";
	return os;
}
