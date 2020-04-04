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
		cerr << "Memorie insuficienta";
		exit(1);
	}
	for (int i = 0; i < dim; i++) {
		v[i] = aux.v[i];
	}
	v[dim++] = nr;
}

Complex Coada::pop() {
	Coada aux(*this);
	delete[] v;
	try {
		v = new Complex[--dim];
	} catch (bad_array_new_length) {
		cerr << "Coada este goala. underflow";
		exit(1);
	}
	for (int i = 0; i < dim; i++) {
		v[i] = aux.v[i + 1];
	}
	return aux.v[0];
}

ostream& operator<<(ostream& os, const Coada& coa) {
	os << "Coada:[";
	for (int i = 0; i < coa.dim - 1; i++) {
		os << coa.v[i] << ", ";
	}
	if (coa.dim > 0) {
		os << coa.v[coa.dim - 1];
	}
	os << "]";
	return os;
}