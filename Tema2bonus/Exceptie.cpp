#include "Exceptie.h"

Exceptie::Exceptie(const String& mesaj): mesaj(mesaj) {}

Exceptie::~Exceptie() {}

void Exceptie::afiseaza() const { mesaj.afiseaza(); }
