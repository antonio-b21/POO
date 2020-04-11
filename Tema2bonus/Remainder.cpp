#include "Remainder.h"

Remainder::Remainder() {}

Remainder::Remainder(const Remainder& remainder) {
	for (unsigned i = 0; i < remainder.note.size(); i++) {
		if (Apel* a = dynamic_cast<Apel*>(remainder.note[i])) {
			Apel* apel = new Apel(a->rZi(), a->rOra(), a->rNrTelefon());
			note.push_back(apel);
		} else if (Sedinta* s = dynamic_cast<Sedinta*>(remainder.note[i])) {
			Sedinta* sedinta = new Sedinta(s->rZi(), s->rOra(), s->rDurata(), s->rSubiect());
			note.push_back(sedinta);
		}
	}
}

Remainder::~Remainder() {
	for (unsigned i = 0; i < note.size(); i++) {
		if (Apel* a = dynamic_cast<Apel*>(note[i])) {
			delete note[i];
			note[i] = NULL;
		} else if (Sedinta* s = dynamic_cast<Sedinta*>(note[i])) {
			delete note[i];
			note[i] = NULL;
		}
	}
	note.clear();
}

Remainder Remainder::operator+(const Remainder& remainder) const {
	Remainder rezultat(*this);

	for (unsigned i = 0; i < remainder.note.size(); i++) {
		bool ok = 1;
		for (unsigned j = 0; j < note.size(); j++) {

			if (Apel* a1 = dynamic_cast<Apel*>(remainder.note[i])) {
				if (Apel* a2 = dynamic_cast<Apel*>(note[j])) {
					if (*a1 == *a2) {
						ok = 0;
						break;
					}
				}
			} else if (Sedinta* s1 = dynamic_cast<Sedinta*>(remainder.note[i])) {
				if (Sedinta* s2 = dynamic_cast<Sedinta*>(note[j])) {
					if (*s1 == *s2) {
						ok = 0;
						break;
					} else if (s2->rZi() == s1->rZi() and (s1->rOra() <= s2->rOra() and s2->rOra() <= s1->rOra() + s1->rDurata() or
														   s2->rOra() <= s1->rOra() and s1->rOra() <= s2->rOra() + s2->rDurata())) {
						throw new Exceptie("Sedinta se suprapune cu alta sedinta din remainder");
					}
					
				}
			}
		}
		if (ok) {
			if (Apel* a = dynamic_cast<Apel*>(remainder.note[i])) {
				Apel* apel = new Apel(a->rZi(), a->rOra(), a->rNrTelefon());
				rezultat.note.push_back(apel);
			} else if (Sedinta* s = dynamic_cast<Sedinta*>(remainder.note[i])) {
				Sedinta* sedinta = new Sedinta(s->rZi(), s->rOra(), s->rDurata(), s->rSubiect());
				rezultat.note.push_back(sedinta);
			}
		}
	}
	return rezultat;
}

Remainder& Remainder::operator=(const Remainder& remainder) {
	if (this != &remainder) {
		for (unsigned i = 0; i < note.size(); i++) {
			if (Apel* a = dynamic_cast<Apel*>(note[i])) {
				delete note[i];
				note[i] = NULL;
			} else if (Sedinta* s = dynamic_cast<Sedinta*>(note[i])) {
				delete note[i];
				note[i] = NULL;
			}
		}
		note.clear();
		for (unsigned i = 0; i < remainder.note.size(); i++) {
			if (Apel* a = dynamic_cast<Apel*>(remainder.note[i])) {
				Apel* apel = new Apel(a->rZi(), a->rOra(), a->rNrTelefon());
				note.push_back(apel);
			} else if (Sedinta* s = dynamic_cast<Sedinta*>(remainder.note[i])) {
				Sedinta* sedinta = new Sedinta(s->rZi(), s->rOra(), s->rDurata(), s->rSubiect());
				note.push_back(sedinta);
			}
		}
	}
	return *this;
}

Nota& Remainder::operator[](const unsigned index) {
	if (index >= note.size()) {
		throw new Exceptie("Nota inexistenta");
	}
	return *note[index];
}

void Remainder::adSedinta(const short zi, const short ora, float durata, const char* subiect) {
	Sedinta* sedinta = new Sedinta(zi, ora, durata, subiect);
	for (unsigned i = 0; i < note.size(); i++) {
		if (Sedinta* s1 = dynamic_cast<Sedinta*>(note[i])) {
			if (sedinta->rZi() == s1->rZi() and (s1->rOra() < sedinta->rOra() and sedinta->rOra() < s1->rOra() + s1->rDurata() or 
												 sedinta->rOra() < s1->rOra() and s1->rOra() < sedinta->rOra() + sedinta->rDurata())) {
				throw new Exceptie("Sedinta se suprapune cu alta sedinta din remainder");
			}
		}
	}
	note.push_back(sedinta);
}

void Remainder::adApel(const short zi, const short ora, const char* nrTelefon) {
	Apel* apel = new Apel(zi, ora, nrTelefon);
	for (unsigned i = 0; i < note.size(); i++) {
		if (Apel* a1 = dynamic_cast<Apel*>(note[i])) {
			if (*a1 == *apel) {
				throw new Exceptie("Apelul exista deja in remainder");
			}
		}
	}
	note.push_back(apel);
}

void Remainder::afiseaza(const short zi, const short ora) const {
	for (unsigned i = 0; i < note.size(); i++) {
		if (note[i]->rZi() >= zi and note[i]->rOra() >= ora) {
			note[i]->afiseaza();
		}
	}
}

void Remainder::urmeaza(const short zi, const short ora) const {
	if (zi <= 0 or zi > 365 or ora < 0 or ora >23 ) {
		throw new Exceptie("Data invalida");
	}
	for (unsigned i = 0; i < note.size(); i++) {
		if (note[i]->rZi() == zi and note[i]->rOra() == ora) { // si ora si note[i]->rOra sunt nr intregi 
			note[i]->afiseaza();
		}
	}
}
