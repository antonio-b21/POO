#include <iostream>
#include <string>
#include <vector>
#include <typeinfo>
#include <stdexcept>
#include <cstdlib>

//----------------------------------------------MASINA
class Masina {
protected:
	static int contor;
	std::string model;
	std::string transmisie;
	int masa;
	int vitezaMax;
public:
	Masina(std::string = "", std::string = "manuala", int = 1450, int = 180);
	Masina(const Masina&);
	virtual ~Masina();

	static int exista();

	Masina& operator=(const Masina&);

	virtual void afisare(std::ostream&) const;
	virtual void citire(std::istream&);
	friend std::ostream& operator<<(std::ostream&, const Masina&);
	friend std::istream& operator>>(std::istream&, Masina&);
};

int Masina::contor = 0;

int Masina::exista() {
	return contor;
}

Masina::Masina(std::string model, std::string transmisie, int masa, int vitezaMax) : model(model), transmisie(transmisie), masa(masa), vitezaMax(vitezaMax) { contor++; };

Masina::Masina(const Masina& masina) : model(masina.model), transmisie(masina.transmisie), masa(masina.masa), vitezaMax(masina.vitezaMax) { contor++; };

Masina::~Masina() { contor--; };

Masina& Masina::operator=(const Masina& masina) {
	if (this != &masina) {
		this->model = masina.model;
		this->transmisie = masina.transmisie;
		this->masa = masina.masa;
		this->vitezaMax = masina.vitezaMax;
	}
	return *this;
}

void Masina::afisare(std::ostream& os) const {
	os << model << " are o transmisie " << transmisie << ", o masa de " << masa << " kg, care atinge viteza de " << vitezaMax << " km/h";
}

void Masina::citire(std::istream& is) {
	std::cout << "Model: ";
	is >> model;
	std::cout << "Transmisie: ";
	is >> transmisie;
	std::cout << "Masa: ";
	is >> masa;
	std::cout << "Viteza maxima: ";
	is >> vitezaMax;
}

std::ostream& operator<<(std::ostream& os, const Masina& masina) {
	masina.afisare(os);
	return os;
}

std::istream& operator>>(std::istream& is, Masina& masina) {
	masina.citire(is);
	return is;
}

//----------------------------------------------COUPE
class Coupe : public Masina {
	int nrUsi;
public:
	Coupe(std::string = "", std::string = "manuala", int = 1450, int = 180, int = 2);
	Coupe(const Coupe&);
	~Coupe();

	Coupe& operator=(const Coupe&);

	void afisare(std::ostream&) const;
	void citire(std::istream&);
	friend std::ostream& operator<<(std::ostream&, const Coupe&);
	friend std::istream& operator>>(std::istream&, Coupe&);
};

Coupe::Coupe(std::string model, std::string transmisie, int masa, int vitezaMax, int nrUsi) : Masina(model, transmisie, masa, vitezaMax), nrUsi(nrUsi) {};

Coupe::Coupe(const Coupe& masina) : Masina(masina), nrUsi(masina.nrUsi) {};

Coupe::~Coupe() {};

Coupe& Coupe::operator=(const Coupe& masina) {
	if (this != &masina) {
		Masina::operator=(masina);
		this->nrUsi = masina.nrUsi;
	}
	return *this;
}

void Coupe::afisare(std::ostream& os) const {
	os << "Masina tip Coupe ";
	Masina::afisare(os);
	os << " avand " << nrUsi << " usi";
}

void Coupe::citire(std::istream& is) {
	Masina::citire(is);
	std::cout << "Numar usi: ";
	is >> nrUsi;
}

std::ostream& operator<<(std::ostream& os, const Coupe& masina) {
	masina.afisare(os);
	return os;
}

std::istream& operator>>(std::istream& is, Coupe& masina) {
	masina.citire(is);
	return is;
}

//----------------------------------------------Hothatch
class Hothatch : public Masina {
	std::string tractiune;
public:
	Hothatch(std::string = "", std::string = "manuala", int = 1450, int = 180, std::string = "fata");
	Hothatch(const Hothatch&);
	~Hothatch();

	Hothatch& operator=(const Hothatch&);

	void afisare(std::ostream&) const;
	void citire(std::istream&);
	friend std::ostream& operator<<(std::ostream&, const Hothatch&);
	friend std::istream& operator>>(std::istream&, Hothatch&);
};

Hothatch::Hothatch(std::string model, std::string transmisie, int masa, int vitezaMax, std::string tractiune) : Masina(model, transmisie, masa, vitezaMax), tractiune(tractiune) {};

Hothatch::Hothatch(const Hothatch& masina) : Masina(masina), tractiune(masina.tractiune) {};

Hothatch::~Hothatch() {};

Hothatch& Hothatch::operator=(const Hothatch& masina) {
	if (this != &masina) {
		Masina::operator=(masina);
		this->tractiune = masina.tractiune;
	}
	return *this;
}

void Hothatch::afisare(std::ostream& os) const {
	os << "Masina tip Hothatch ";
	Masina::afisare(os);
	os << " avand tractiune " << tractiune;
}

void Hothatch::citire(std::istream& is) {
	Masina::citire(is);
	std::cout << "Tip tractiune: ";
	is >> tractiune;
}

std::ostream& operator<<(std::ostream& os, const Hothatch& masina) {
	masina.afisare(os);
	return os;
}

std::istream& operator>>(std::istream& is, Hothatch& masina) {
	masina.citire(is);
	return is;
}

//----------------------------------------------CABRIO
class Cabrio : public Masina {
	std::string acoperis;
public:
	Cabrio(std::string = "", std::string = "manuala", int = 1450, int = 180, std::string = "metalic");
	Cabrio(const Cabrio&);
	~Cabrio();

	Cabrio& operator=(const Cabrio&);

	void afisare(std::ostream&) const;
	void citire(std::istream&);
	friend std::ostream& operator<<(std::ostream&, const Cabrio&);
	friend std::istream& operator>>(std::istream&, Cabrio&);
};

Cabrio::Cabrio(std::string model, std::string transmisie, int masa, int vitezaMax, std::string acoperis) : Masina(model, transmisie, masa, vitezaMax), acoperis(acoperis) {};

Cabrio::Cabrio(const Cabrio& masina) : Masina(masina), acoperis(masina.acoperis) {};

Cabrio::~Cabrio() {};

Cabrio& Cabrio::operator=(const Cabrio& masina) {
	if (this != &masina) {
		Masina::operator=(masina);
		this->acoperis = masina.acoperis;
	}
	return *this;
}

void Cabrio::afisare(std::ostream& os) const {
	os << "Masina tip Cabrio ";
	Masina::afisare(os);
	os << " avand acoperis " << acoperis;
}

void Cabrio::citire(std::istream& is) {
	Masina::citire(is);
	std::cout << "Tip acoperis: ";
	is >> acoperis;
}

std::ostream& operator<<(std::ostream& os, const Cabrio& masina) {
	masina.afisare(os);
	return os;
}

std::istream& operator>>(std::istream& is, Cabrio& masina) {
	masina.citire(is);
	return is;
}

//----------------------------------------------SUPERSPORT
class Supersport : public Masina {
	int putere;
	std::string deVanzare;
public:
	Supersport(std::string = "", std::string = "manuala", int = 1450, int = 180, int = 120, std::string = "Da");
	Supersport(const Supersport&);
	~Supersport();

	Supersport& operator=(const Supersport&);

	void afisare(std::ostream&) const;
	void citire(std::istream&);
	friend std::ostream& operator<<(std::ostream&, const Supersport&);
	friend std::istream& operator>>(std::istream&, Supersport&);

	bool vanzare() const;
};

Supersport::Supersport(std::string model, std::string transmisie, int masa, int vitezaMax, int putere, std::string deVanzare) : Masina(model, transmisie, masa, vitezaMax), putere(putere), deVanzare(deVanzare) {};

Supersport::Supersport(const Supersport& masina) : Masina(masina), putere(masina.putere), deVanzare(masina.deVanzare) {};

Supersport::~Supersport() {};

Supersport& Supersport::operator=(const Supersport& masina) {
	if (this != &masina) {
		Masina::operator=(masina);
		this->putere = masina.putere;
		this->deVanzare = masina.deVanzare;
	}
	return *this;
}

void Supersport::afisare(std::ostream& os) const {
	os << "Masina tip Supersport ";
	Masina::afisare(os);
	os << " avand " << putere << " kW";
}

void Supersport::citire(std::istream& is) {
	Masina::citire(is);
	std::cout << "Putere: ";
	is >> putere;
	std::cout << "De vanzare: ";
	is >> deVanzare;
}

std::ostream& operator<<(std::ostream& os, const Supersport& masina) {
	masina.afisare(os);
	return os;
}

std::istream& operator>>(std::istream& is, Supersport& masina) {
	masina.citire(is);
	return is;
}

bool Supersport::vanzare() const {
	if (deVanzare == "Da") {
		return true;
	}
	return false;
}

//----------------------------------------------TEMPLATE
template <class T>
class Expozitie;
template <class T>
std::ostream& operator<<(std::ostream&, const Expozitie<T>&);
template <class T>
std::istream& operator>>(std::istream&, Expozitie<T>&);

template <class T>
class Expozitie {
	int nrMasini;
	std::vector<T> masini;
	static Expozitie* instanta;
	Expozitie();
	Expozitie(const Expozitie&);
public:
	static Expozitie* instantiaza();
	~Expozitie();

	Expozitie& operator=(const Expozitie&);

	friend std::ostream& operator<<<T>(std::ostream&, const Expozitie&);
	friend std::istream& operator>><T>(std::istream&, Expozitie&);
};

template <class T>
Expozitie<T>* Expozitie<T>::instanta = nullptr;

template <class T>
Expozitie<T>::Expozitie() :nrMasini(0) {}

template <class T>
Expozitie<T>::Expozitie(const Expozitie& expozitie) : nrMasini(expozitie.nrMasini) {
	for (int i = 0; i < nrMasini; i++) {
		masini.push_back(expozitie.masini[i]);
	}
}

template <class T>
Expozitie<T>* Expozitie<T>::instantiaza() {
	if (!instanta) {
		try {
			instanta = new Expozitie<T>;
		}
		catch (const std::bad_alloc&) {
			std::cerr << "Memorie insuficienta\n";
			exit(1);
		}
	}
	return instanta;
}

template <class T>
Expozitie<T>::~Expozitie() {
	masini.clear();
}

template <class T>
Expozitie<T>& Expozitie<T>::operator=(const Expozitie& expozitie) {
	if (this != &expozitie) {
		masini.clear();
		nrMasini = expozitie.nrMasini;
		for (int i = 0; i < nrMasini; i++) {
			masini.push_back(expozitie.masini[i]);
		}
	}
	return *this;
}

template <class T>
std::ostream& operator<<(std::ostream& os, const Expozitie<T>& expozitie) {
	std::cout << "Aceste " << expozitie.nrMasini << " masini " << std::string(typeid(T).name()).substr(6) << " participa la expozitie:\n";
	for (class std::vector<T>::const_iterator it = expozitie.masini.begin(); it != expozitie.masini.end(); it++) {
		os << *it << "\n";
	}
	return os;
}

template <class T>
std::istream& operator>>(std::istream& is, Expozitie<T>& expozitie) {
	expozitie.masini.clear();
	expozitie.nrMasini = 0;
	std::cout << "Cate masini " << std::string(typeid(T).name()).substr(6) << " doriti sa inscrieti la expozitie?\nR: ";
	is.exceptions(std::istream::failbit);
	try {
		is >> expozitie.nrMasini;
	}
	catch (const std::ios::failure&) {
		is.clear();
		is.ignore(INT_MAX, '\n');
		std::cout << "Numar invalid\n";
		return is;
	}
	for (int i = 1; i <= expozitie.nrMasini; i++) {
		std::cout << "\nMasina " << i << "\n";
		T masina;
		std::cin >> masina;
		expozitie.masini.push_back(masina);
	}
	return is;
}

//----------------------------------------------SPECIALIZARE
template <>
class Expozitie<Supersport>;
std::ostream& operator<<(std::ostream&, const Expozitie<Supersport>&);
std::istream& operator>>(std::istream&, Expozitie<Supersport>&);

template <>
class Expozitie<Supersport> {
	int nrMasini;
	int nrMasiniVandute;
	std::vector<Supersport> masini;
	std::vector<std::pair<Supersport, int>> masiniVandute;
	static Expozitie* instanta;
	Expozitie();
	Expozitie(const Expozitie&);
public:
	static Expozitie* instantiaza();
	~Expozitie();

	Expozitie& operator=(const Expozitie&);
	Expozitie& operator-=(std::pair<int, int>);

	friend std::ostream& operator<<(std::ostream&, const Expozitie<Supersport>&);
	friend std::istream& operator>>(std::istream&, Expozitie<Supersport>&);
};

Expozitie<Supersport>* Expozitie<Supersport>::instanta = nullptr;

Expozitie<Supersport>::Expozitie() :nrMasini(0), nrMasiniVandute(0) {}

Expozitie<Supersport>::Expozitie(const Expozitie<Supersport>& expozitie) : nrMasini(expozitie.nrMasini), nrMasiniVandute(expozitie.nrMasiniVandute) {
	for (int i = 0; i < nrMasini; i++) {
		masini.push_back(expozitie.masini[i]);
	}
	for (int i = 0; i < nrMasiniVandute; i++) {
		masiniVandute.push_back(expozitie.masiniVandute[i]);
	}
}

Expozitie<Supersport>* Expozitie<Supersport>::instantiaza() {
	if (!instanta) {
		try {
			instanta = new Expozitie<Supersport>;
		}
		catch (const std::bad_alloc&) {
			std::cerr << "Memorie insuficienta\n";
			exit(1);
		}
	}
	return instanta;
}

Expozitie<Supersport>::~Expozitie() {
	masini.clear();
	masiniVandute.clear();
}

Expozitie<Supersport>& Expozitie<Supersport>::operator=(const Expozitie<Supersport>& expozitie) {
	if (this != &expozitie) {
		masini.clear();
		nrMasini = expozitie.nrMasini;
		for (int i = 0; i < nrMasini; i++) {
			masini.push_back(expozitie.masini[i]);
		}
		masiniVandute.clear();
		nrMasiniVandute = expozitie.nrMasiniVandute;
		for (int i = 0; i < nrMasiniVandute; i++) {
			masiniVandute.push_back(expozitie.masiniVandute[i]);
		}
	}
	return *this;
}

Expozitie<Supersport>& Expozitie<Supersport>::operator-=(std::pair<int, int> oferta) {
	int nrMasina = oferta.first - 1;
	int pret = oferta.second;
	if (nrMasina < 0 or nrMasina >= nrMasini) {
		throw std::out_of_range("Masina inexistenta\n");
	}
	std::vector<Supersport>::iterator it = masini.begin();
	while (nrMasina--) {
		it++;
	}
	Supersport masina = *it;
	if (masina.vanzare()) {
		masini.erase(it);
		nrMasini--;
		masiniVandute.push_back(std::pair<Supersport, int>(masina, pret));
		nrMasiniVandute++;
	}
	else {
		throw std::invalid_argument("Masina nu este de vanzare\n");
	}
	return *this;
}

std::ostream& operator<<(std::ostream& os, const Expozitie<Supersport>& expozitie) {
	std::cout << "Aceste " << expozitie.nrMasini << " masini Supersport participa la expozitie:\n";
	for (typename std::vector<Supersport>::const_iterator it = expozitie.masini.begin(); it != expozitie.masini.end(); it++) {
		os << *it;
		if (it->vanzare()) {
			std::cout << " poate fi cumparata";
		}
		os << "\n";
	}
	std::cout << "Aceste " << expozitie.nrMasiniVandute << " masini Supersport au fost vandute in cadrul expozitiei:\n";
	for (typename std::vector<std::pair<Supersport, int>>::const_iterator it = expozitie.masiniVandute.begin(); it != expozitie.masiniVandute.end(); it++) {
		os << it->first;
		if (it->first.vanzare()) {
			if (it->second == -1) {
				std::cout << " nu a fost vanduta";
			}
			else {
				std::cout << " a fost vanduta pentru " << it->second << " euro";
			}
		}
		os << "\n";
	}
	return os;
}

std::istream& operator>>(std::istream& is, Expozitie<Supersport>& expozitie) {
	expozitie.masini.clear();
	expozitie.masiniVandute.clear();
	expozitie.nrMasini = 0;
	expozitie.nrMasiniVandute = 0;
	std::cout << "Cate masini Supersport doriti sa inscrieti la expozitie?\nR: ";
	is.exceptions(std::istream::failbit);
	try {
		is >> expozitie.nrMasini;
	}
	catch (const std::ios::failure&) {
		is.clear();
		is.ignore(INT_MAX, '\n');
		std::cout << "Numar invalid\n";
		return is;
	}
	for (int i = 1; i <= expozitie.nrMasini; i++) {
		std::cout << "\nMasina " << i << "\n";
		Supersport masina;
		is >> masina;
		expozitie.masini.push_back(masina);
	}
	return is;
}

//----------------------------------------------MAIN
int main() {
	std::vector<std::pair<Masina*, int>> masini;
	int nrMasini = 0;
	std::string optiune;
	while (true) {
		{
			std::cout << "Targul de masini sport din luna Mai\n\n";
			std::cout << "Optiuni:\n";
			std::cout << "1. Inscrie masini la targ\n";
			std::cout << "2. Afiseaza masinile care au fost la targ\n";
			std::cout << "3. Inscrie masini la expozitia de masini Coupe\n";
			std::cout << "4. Inscrie masini la expozitia de masini Hothatch\n";
			std::cout << "5. Inscrie masini la expozitia de masini Cabrio\n";
			std::cout << "6. Inscrie masini la expozitia de masini Supersport\n";
			std::cout << "7. Afiseaza masinile din expozitia de masini Coupe\n";
			std::cout << "8. Afiseaza masinile din expozitia de masini Hothatch\n";
			std::cout << "9. Afiseaza masinile din expozitia de masini Cabrio\n";
			std::cout << "10. Afiseaza masinile din expozitia de masini Supersport\n";
			std::cout << "11. Cumpara masina de la expozitia de masini Supersport\n";
			std::cout << "12. Afiseaza numarul total de masini care au participat la targ\n";
			std::cout << "0. Iesire\nR: ";
		}
		std::cin >> optiune;
		std::cin.clear();
		std::cin.ignore(INT_MAX, '\n');
		std::cout << "\n";
		if (optiune == "0") {
			std::cout << "Targul a luat sfarsit\n";
			Expozitie<Coupe>* expCoupe = Expozitie<Coupe>::instantiaza();
			Expozitie<Hothatch>* expHothatch = Expozitie<Hothatch>::instantiaza();
			Expozitie<Cabrio>* expCabrio = Expozitie<Cabrio>::instantiaza();
			Expozitie<Supersport>* expSupersport = Expozitie<Supersport>::instantiaza();
			delete expCoupe;
			delete expHothatch;
			delete expCabrio;
			delete expSupersport;
			break;
		}
		else if (optiune == "1") {
			std::cout << "Cate masini doriti sa inscrieti la targ?\nR: ";
			std::cin.exceptions(std::istream::failbit);
			try {
				std::cin >> nrMasini;
				for (int i = 1; i <= nrMasini; i++) {
					std::cout << "\nMasina " << i << "\nTip: ";
					std::string tip;
					std::cin >> tip;
					if (tip == "Coupe") {
						Coupe* masina;
						try {
							masina = new Coupe;
						}
						catch (const std::bad_alloc&) {
							std::cerr << "Memorie insuficienta\n";
							exit(1);
						}
						std::cin >> *masina;
						masini.push_back(std::pair<Masina*, int>(masina, -1));
					}
					else if (tip == "Hothatch") {
						Hothatch* masina;
						try {
							masina = new Hothatch;
						}
						catch (const std::bad_alloc&) {
							std::cerr << "Memorie insuficienta\n";
							exit(1);
						}
						std::cin >> *masina;
						masini.push_back(std::pair<Masina*, int>(masina, -1));
					}
					else if (tip == "Cabrio") {
						Cabrio* masina;
						try {
							masina = new Cabrio;
						}
						catch (const std::bad_alloc&) {
							std::cerr << "Memorie insuficienta\n";
							exit(1);
						}
						std::cin >> *masina;
						masini.push_back(std::pair<Masina*, int>(masina, -1));
					}
					else if (tip == "Supersport") {
						Supersport* masina;
						try {
							masina = new Supersport;
						}
						catch (const std::bad_alloc&) {
							std::cerr << "Memorie insuficienta\n";
							exit(1);
						}
						std::cin >> *masina;
						int pret = -1;
						if (masina->vanzare()) {
							std::cout << "S-a vandut cu: ";
							try {
								std::cin >> pret;
							}
							catch (const std::ios::failure&) {
								std::cin.clear();
								std::cin.ignore(INT_MAX, '\n');
								std::cout << "Numar invalid\n";
								i--;
								continue;
							}
						}
						masini.push_back(std::pair<Masina*, int>(masina, pret));
					}
					else {
						std::cout << "Puteti inscrie o masina din tipurile urmatoare: Coupe, Hothatch, Cabrio sau Supersport\n";
						i--;
					}
				}
			}
			catch (const std::ios::failure&) {
				std::cin.clear();
				std::cin.ignore(INT_MAX, '\n');
				std::cout << "Numar invalid\n";
			}
		}
		else if (optiune == "2") {
			std::cout << "La targ au fost " << nrMasini << " masini:\n";
			for (std::vector<std::pair<Masina*, int>>::iterator it = masini.begin(); it != masini.end(); it++) {
				std::cout << *it->first;
				Supersport* masina = dynamic_cast<Supersport*>(it->first);
				if (masina and masina->vanzare()) {
					if (it->second == -1) {
						std::cout << " nu a fost vanduta";
					}
					else {
						std::cout << " a fost vanduta pentru " << it->second << " euro";
					}
				}
				std::cout << "\n";
			}
		}
		else if (optiune == "3") {
			Expozitie<Coupe>* expCoupe = Expozitie<Coupe>::instantiaza();
			std::cin >> *expCoupe;
		}
		else if (optiune == "4") {
			Expozitie<Hothatch>* expHothatch = Expozitie<Hothatch>::instantiaza();
			std::cin >> *expHothatch;
		}
		else if (optiune == "5") {
			Expozitie<Cabrio>* expCabrio = Expozitie<Cabrio>::instantiaza();
			std::cin >> *expCabrio;
		}
		else if (optiune == "6") {
			Expozitie<Supersport>* expSupersport = Expozitie<Supersport>::instantiaza();
			std::cin >> *expSupersport;
		}
		else if (optiune == "7") {
			Expozitie<Coupe>* expCoupe = Expozitie<Coupe>::instantiaza();
			std::cout << *expCoupe;
		}
		else if (optiune == "8") {
			Expozitie<Hothatch>* expHothatch = Expozitie<Hothatch>::instantiaza();
			std::cout << *expHothatch;
		}
		else if (optiune == "9") {
			Expozitie<Cabrio>* expCabrio = Expozitie<Cabrio>::instantiaza();
			std::cout << *expCabrio;
		}
		else if (optiune == "10") {
			Expozitie<Supersport>* expSupersport = Expozitie<Supersport>::instantiaza();
			std::cout << *expSupersport;
		}
		else if (optiune == "11") {
			Expozitie<Supersport>* expSupersport = Expozitie<Supersport>::instantiaza();
			int nrMasina, pret;
			std::cin.exceptions(std::istream::failbit);
			try {
				std::cout << "Ce masina doriti sa cumparati?\nR: ";
				std::cin >> nrMasina;
				std::cout << "Cu ce suma doriti sa cumparati masina?\nR: ";
				std::cin >> pret;
				try {
					*expSupersport -= std::pair<int, int>(nrMasina, pret);
				}
				catch (const std::invalid_argument& e) {
					std::cout << e.what();
				}
				catch (const std::out_of_range& e) {
					std::cout << e.what();
				}
			}
			catch (const std::istream::failure&) {
				std::cin.clear();
				std::cin.ignore(INT_MAX, '\n');
				std::cout << "Raspuns invalid\n";
			}
		}
		else if (optiune == "12") {
			std::cout << "La targ a participat un total de " << Masina::exista() << " masini\n";
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
