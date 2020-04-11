#include "String.h"

String::String(const char* mesaj) {
	this->mesaj = new char[strlen(mesaj)+1];
	strcpy_s(this->mesaj, strlen(mesaj) + 1, mesaj);
}

String::String(const String& string) {
	mesaj = new char[strlen(string.mesaj) + 1];
	strcpy_s(mesaj, strlen(string.mesaj) + 1, string.mesaj);
}

String::~String() {
	delete[] mesaj;
	mesaj = NULL;
}

String& String::operator=(const String& string) {
	if (this != &string) {
		delete[] mesaj;
		mesaj = new char[strlen(string.mesaj) + 1];
		strcpy_s(mesaj, strlen(string.mesaj) + 1, string.mesaj);
	}
	return *this;
}

bool String::operator==(const String& string) const {
	unsigned i, j;
	for (i = 0, j = 0; mesaj[i] != NULL and string.mesaj[j] != NULL; i++, j++) {
		if (mesaj[i] != string.mesaj[j]) {
			return false;
		}
	}
	if (mesaj[i] != string.mesaj[j]) {
		return false;
	}
	return true;
}

void String::afiseaza() const{
	std::cout << mesaj << '\n';
}

unsigned String::lungime() const {
	return strlen(mesaj);
}