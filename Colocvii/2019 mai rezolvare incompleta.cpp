#include <iostream>
#include <string>
#include <vector>

//----------------------------------------Tren
class Tren {
protected:
	static int contor;
	std::string cod;
	int distanta;
public:
	Tren(std::string = "", int = 0);
	Tren(const Tren&);
	virtual ~Tren();

	static int exista();

	Tren& operator=(const Tren&);

	std::string getCod() {return cod;}

	virtual void afisare(std::ostream&) const;
	virtual void citire(std::istream&);
	virtual void afisareA(std::ostream&) const;
	virtual void citireA(std::istream&);
};

int Tren::contor = 0;

int Tren::exista() {
	return contor;
}

Tren::Tren(std::string cod, int distanta) : cod(cod), distanta(distanta) { contor++; };

Tren::Tren(const Tren& tren) : cod(tren.cod), distanta(tren.distanta) { contor++; };

Tren::~Tren() { contor--; };

Tren& Tren::operator=(const Tren& tren) {
	if (this != &tren) {
		this->cod = tren.cod;
		this->distanta = tren.distanta;
	}
	return *this;
}

void Tren::afisare(std::ostream& os) const {
	os << "\ncod: " << cod;
	os << "\ndistanta: " <<  distanta;
}

void Tren::citire(std::istream& is) {
	std::cout << "cod: ";
	is >> cod;
	std::cout << "distanta: ";
	is >> distanta;
}

void Tren::afisareA(std::ostream& os) const {
	afisare(os);
}

void Tren::citireA(std::istream& is) {
	citire(is);
}

//----------------------------------------TrenInter
class TrenInter : virtual public Tren {
protected:
	int nrLoc;
public:
	TrenInter(std::string = "", int = 0, int = 0);
	TrenInter(const TrenInter&);
	virtual ~TrenInter();

	TrenInter& operator=(const TrenInter&);

	virtual void afisare(std::ostream&) const;
	virtual void citire(std::istream&);
	virtual void afisareA(std::ostream&) const;
	virtual void citireA(std::istream&);
};

TrenInter::TrenInter(std::string cod, int distanta, int nrLoc) : Tren(cod, distanta), nrLoc(nrLoc) {};

TrenInter::TrenInter(const TrenInter& tren) : Tren(tren), nrLoc(tren.nrLoc) {};

TrenInter::~TrenInter() {};

TrenInter& TrenInter::operator=(const TrenInter& tren) {
	if (this != &tren) {
		Tren::operator=(tren);
		this->nrLoc = tren.nrLoc;
	}
	return *this;
}

void TrenInter::afisare(std::ostream& os) const {
	os << "\nnrLoc: " << nrLoc;
}

void TrenInter::citire(std::istream& is) {
	std::cout << "nrLoc: ";
	is >> nrLoc;
}

void TrenInter::afisareA(std::ostream& os) const {
    Tren::afisare(os);
	afisare(os);
}

void TrenInter::citireA(std::istream& is) {
    Tren::citire(is);
	citire(is);
}

//----------------------------------------TrenCls1
class TrenCls1 : virtual public Tren {
protected:
	std::vector<std::string> meniu;
public:
	TrenCls1(std::string = "", int = 0);
	TrenCls1(const TrenCls1&);
	virtual ~TrenCls1();

	TrenCls1& operator=(const TrenCls1&);

	virtual void afisare(std::ostream&) const;
	virtual void citire(std::istream&);
	virtual void afisareA(std::ostream&) const;
	virtual void citireA(std::istream&);
};

TrenCls1::TrenCls1(std::string cod, int distanta) : Tren(cod, distanta) {};

TrenCls1::TrenCls1(const TrenCls1& tren) : Tren(tren) {
	for (unsigned i = 0; i < tren.meniu.size(); i++) {
		meniu.push_back(tren.meniu[i]);
	}
};

TrenCls1::~TrenCls1() {
	meniu.clear();
};

TrenCls1& TrenCls1::operator=(const TrenCls1& tren) {
	if (this != &tren) {
		Tren::operator=(tren);
		meniu.clear();
		for (unsigned i = 0; i < tren.meniu.size(); i++) {
			meniu.push_back(tren.meniu[i]);
		}
	}
	return *this;
}

void TrenCls1::afisare(std::ostream& os) const {
	for (unsigned i = 0; i < meniu.size(); i++) {
		os << "\n" << meniu[i];
	}
}

void TrenCls1::citire(std::istream& is) {
	int nr;
	std::cout << "nr: ";
	is >> nr;
	for (int i = 0; i < nr; i++) {
		std::string nume;
		std::cout << "nume: ";
		is >> nume;
		meniu.push_back(nume);
	}
}

void TrenCls1::afisareA(std::ostream& os) const {
	Tren::afisare(os);
	afisare(os);
}

void TrenCls1::citireA(std::istream& is) {
	Tren::citire(is);
	citire(is);
}

//----------------------------------------TrenInterCls1
class TrenInterCls1 : public TrenInter, public TrenCls1 {
public:
	TrenInterCls1(std::string = "", int = 0, int = 0);
	TrenInterCls1(const TrenInterCls1&);
	~TrenInterCls1();

	TrenInterCls1& operator=(const TrenInterCls1&);

	void afisare(std::ostream&) const;
	void citire(std::istream&);
	void afisareA(std::ostream&) const;
	void citireA(std::istream&);
};

TrenInterCls1::TrenInterCls1(std::string cod, int distanta, int nrLoc) : TrenInter(cod, distanta, nrLoc), TrenCls1(cod, distanta) {};

TrenInterCls1::TrenInterCls1(const TrenInterCls1& tren) : TrenInter(tren), TrenCls1(tren) {};

TrenInterCls1::~TrenInterCls1() {};

TrenInterCls1& TrenInterCls1::operator=(const TrenInterCls1& tren) {
	if (this != &tren) {
		TrenInter::operator=(tren);
		TrenCls1::operator=(tren);
	}
	return *this;
}

void TrenInterCls1::afisare(std::ostream& os) const {}

void TrenInterCls1::citire(std::istream& is) {}

void TrenInterCls1::afisareA(std::ostream& os) const {
    Tren::afisare(os);
	TrenInter::afisare(os);
	TrenCls1::afisare(os);
}

void TrenInterCls1::citireA(std::istream& is) {
    Tren::citire(is);
	TrenInter::citire(is);
	TrenCls1::citire(is);
}

//----------------------------------------Bilet
class Bilet {
protected:
	static int contor;
	std::string statieP;
	std::string statieS;
	int ziua;
	int ora;
	Tren* tren;
	int durata;
	int distanta;
	double pret;
	std::string serie;
public:
	Bilet(std::string = "", std::string = "", int = 0, int = 0, Tren* = nullptr, int = 0, int = 0);
	Bilet(const Bilet&);
	~Bilet();

	static int exista();

	Bilet& operator=(const Bilet&);

	std::string getCodTren() { return tren->getCod(); }
	int getDistanta() { return distanta; }
	std::string getSerie() { return serie; }

	void afisare(std::ostream&) const;
	void citire(std::istream&);
};

int Bilet::contor = 0;

int Bilet::exista() {
	return contor;
}

Bilet::Bilet(std::string statieP, std::string statieS, int ziua, int ora, Tren* tren, int durata, int distanta) : statieP(statieP), statieS(statieS), ziua(ziua), ora(ora), tren(tren), durata(durata), distanta(distanta), pret(0), serie("") { contor++; };

Bilet::Bilet(const Bilet& bilet) : statieP(bilet.statieP), statieS(bilet.statieS), ziua(bilet.ziua), ora(bilet.ora), tren(bilet.tren), durata(bilet.durata), distanta(bilet.distanta), pret(bilet.pret), serie(bilet.serie) { contor++; };

Bilet::~Bilet() { contor--; };

Bilet& Bilet::operator=(const Bilet& bilet) {
	if (this != &bilet) {
		this->statieP = bilet.statieP;
		this->statieS = bilet.statieS;
		this->ziua = bilet.ziua;
		this->ora = bilet.ora;
		this->tren = bilet.tren;
		this->durata = bilet.durata;
		this->distanta = bilet.distanta;
		this->pret = bilet.pret;
	}
	return *this;
}

void Bilet::afisare(std::ostream& os) const {
	os << "\nstatieP:" << statieP;
	os << "\nstaties:" << statieS;
	os << "\nziua:" << ziua;
	os << "\nora:" << ora;
	os << "\ntren:"; tren->afisareA(os);
	os << "\ndurata:" << durata;
	os << "\ndistanta:" << distanta;
	os << "\npret:" << pret;
	os << "\nserie:" << serie;
}

void Bilet::citire(std::istream& is) {
	std::cout << "statieP: ";
	is >> statieP;
	std::cout << "statieS: ";
	is >> statieS;
	std::cout << "ziua: ";
	is >> ziua;
	std::cout << "ora: ";
	is >> ora;
	std::string tip;
tiptren:
	is >> tip;
	if (tip == "Regio") {
		tren = new Tren;
	}
	else if (tip == "Inter") {
		tren = new TrenInter;
	}
	else if (tip == "Cls1") {
		tren = new TrenCls1;
	}
	else if (tip == "InterCls1") {
		tren = new TrenInterCls1;
	}
	else {
		goto tiptren;
	}
	std::cout << "tren: ";
	tren->citireA(is);

	std::cout << "durata: ";
	is >> durata;
	std::cout << "distanta: ";
	is >> distanta;

	if (TrenInterCls1* trenul = dynamic_cast<TrenInterCls1*>(tren)) {
		pret = 0.7 * distanta * 1.2;
		serie = "IRI-" + std::to_string(contor);
	}
	else if (TrenInter* trenul = dynamic_cast<TrenInter*>(tren)) {
		pret = 0.7 * distanta;
		serie = "IRII-" + std::to_string(contor);
	}
	else if (TrenCls1* trenul = dynamic_cast<TrenCls1*>(tren)) {
		pret = 0.39 * distanta * 1.2;
		serie = "RI-" + std::to_string(contor);
	}
	else {
		pret = 0.39 * distanta;
		serie = "RII-" + std::to_string(contor);
	}
}

//----------------------------------------Main
int main() {
	std::vector<Bilet*> bilete;
	std::string optiune;
	while (true) {
		{
			std::cout << "Optiuni:\n";
			std::cout << "1. elibereaza bilet\n";
			std::cout << "2. bilete pt trenul\n";
			std::cout << "3. bilete pt distanta\n";
			std::cout << "4. anulare bilet\n";
			std::cout << "0. Iesire\nR: ";
		}
		std::cin >> optiune;
		std::cin.clear();
		std::cin.ignore(INT_MAX, '\n');
		std::cout << "\n";
		if (optiune == "0") {
			break;
		}
		else if (optiune == "1") {
			Bilet* bilet;
			try {
				bilet = new Bilet;
			}
			catch (const std::bad_alloc&) {
				std::cerr << "Memorie insuficienta\n";
				exit(1);
			}
			bilet->citire(std::cin);
			bilete.push_back(bilet);
		}
		else if (optiune == "2") {
			std::string cod;
			std::cin >> cod;

			for (std::vector<Bilet*>::iterator it = bilete.begin(); it != bilete.end(); it++) {
				if ((*it)->getCodTren() == cod) {
					(*it)->afisare(std::cout);
				}
			}
		}
		else if (optiune == "3") {
			int distanta;
			std::cin >> distanta;

			for (std::vector<Bilet*>::iterator it = bilete.begin(); it != bilete.end(); it++) {
				if ((*it)->getDistanta() > distanta) {
					(*it)->afisare(std::cout);
				}
			}
		}
		else if (optiune == "4") {
			std::string serie;
			std::cin >> serie;

			for (std::vector<Bilet*>::iterator it = bilete.begin(); it != bilete.end(); it++) {
				if ((*it)->getSerie() == serie) {
					bilete.erase(it);
					break;
				}
			}
		}
		else {
			std::cout << "Optiune invalida\n";
		}
		std::cin.get();
		std::cin.clear();
		std::cin.ignore(INT_MAX, '\n');
		std::cout << "\n";
	}

	return 0;
}
