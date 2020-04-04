#include "Vector.h"

Vector::Vector(): dim(0) {
	v = new Complex[dim];
}

Vector::Vector(int dim) :dim(dim) {
	try{
		v = new Complex[dim];
	} catch (bad_array_new_length) {
		terminate();
	}
}

Vector::Vector(const Vector& vec): dim(vec.dim) {
	try {
		v = new Complex[dim];
	} catch (bad_array_new_length) {
		terminate();
	}
	for (int i = 0; i < dim; i++) {
		v[i] = vec.v[i];
	}
}

Vector::~Vector() {
	dim = 0;
	delete[] v;
}

Vector& Vector::operator=(const Vector& vec) {
	if (this != &vec) {
		if (dim != vec.dim) {
			delete[] v;
			dim = vec.dim;
			try {
				v = new Complex[dim];
			} catch (bad_array_new_length) {
				terminate();
			}
			for (int i = 0; i < dim; i++) {
				v[i] = vec.v[i];
			}
		}
	}
	return *this;
}

bool Vector::eImaginar() const {
	for (int i = 0; i < dim; i++) {
		if (v[i].eImaginar() == false) {
			return false;
		}
	}
	return true;
}

ostream& operator<<(ostream& os, const Vector& vec) {
	os << "[";
	for (int i = 0; i < vec.dim - 1; i++) {
		os << vec.v[i] << ", ";
	}
	if (vec.dim > 0) {
		os << vec.v[vec.dim - 1];
	}
	os << "]";
	return os;
}

istream& operator>>(istream& is, Vector& vec) {
	if (vec.dim) {
		vec.dim = 0;
		delete[] vec.v;
	}
	cin.exceptions(istream::failbit);
	try {
		cout << "Dim: ";
		is >> vec.dim;
		if (vec.dim < 0) {
			throw vec.dim;
		}
		vec.v = new Complex[vec.dim];
	} catch (ios_base::failure) {
		std::cin.clear();
		std::cin.ignore(INT_MAX, '\n');
		cin >> vec;
	} catch (int) {
		cin >> vec;
	} catch (bad_array_new_length) {
		terminate();
	}
	for (int i = 0; i < vec.dim; i++) {
		try {
			cout << "v[" << i << "]: ";
			cin >> vec.v[i];
		} catch (ios_base::failure) {
			std::cin.clear();
			std::cin.ignore(INT_MAX, '\n');
			i--;
		}
	}
	return is;
}
