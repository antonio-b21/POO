#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include <cstdlib>
#include <algorithm>


//----------------------------------------Dezinfectant
class Dezinfectant {
protected:
	static int contor;
	double eficienta;
	std::vector<std::string> ingrediente;
    std::vector<std::string> suprafete;

	virtual void cit(std::istream& is);
	virtual void afi(std::ostream& os) const;

public:
	Dezinfectant(std::vector<std::string> ingrediente = {}, std::vector<std::string> suprafete = {}) {
		contor++;
        this->ingrediente = ingrediente;
        this->suprafete = suprafete;
	}

	Dezinfectant(const Dezinfectant& dezinfectant);
	virtual ~Dezinfectant() = 0;

	Dezinfectant& operator=(const Dezinfectant& dezinfectant);

	static int contorGet() { return contor; }
	double eficientaGet() const { return eficienta; }
	std::vector<std::string> ingredienteGet() const { return ingrediente; }
    std::vector<std::string> suprafeteGet() const { return suprafete; }

	virtual void citire(std::istream& is);
	virtual void afisare(std::ostream& os) const;
};
int Dezinfectant::contor = 0;

void Dezinfectant::cit(std::istream& is) {
    is.exceptions(std::istream::failbit);
citDezinfectant:
    try {
        int nrIngrediente;
        std::cout << "nrIngrediente: "; is >> nrIngrediente;
        for (int i = 0; i < nrIngrediente; i++) {
            std::string ingredient;
            std::cout << "ingredient: "; is >> ingredient;
            ingrediente.push_back(ingredient);
        }
        int nrSuprafete;
        std::cout << "nrSuprafete: "; is >> nrSuprafete;
        for (int i = 0; i < nrSuprafete; i++) {
            std::string sprafata;
            std::cout << "sprafata: "; is >> sprafata;
            suprafete.push_back(sprafata);
        }
    }
    catch (const std::ios_base::failure&) {
        is.clear();
        is.ignore(INT_MAX, '\n');
        std::cout << "Numar invalid\n";
        goto citDezinfectant;
    }
}
void Dezinfectant::afi(std::ostream& os) const {
    os << "eficienta:" << eficienta << "\n";
    os << "ingrediente:" << ingrediente.size() << "\n";
    for (std::vector<std::string>::const_iterator i = ingrediente.begin(); i != ingrediente.end(); i++) {
        os << *i << "\n";
    }
    os << "suprafete:" << suprafete.size() << "\n";
    for (std::vector<std::string>::const_iterator i = suprafete.begin(); i != suprafete.end(); i++) {
        os << *i << "\n";
    }
}

Dezinfectant::Dezinfectant(const Dezinfectant& dezinfectant) {
    contor++;
    this->eficienta = dezinfectant.eficienta;
    ingrediente.insert(ingrediente.end(), dezinfectant.ingrediente.begin(), dezinfectant.ingrediente.end());
    suprafete.insert(suprafete.end(), dezinfectant.suprafete.begin(), dezinfectant.suprafete.end());
}
Dezinfectant::~Dezinfectant() {
    contor--;
    ingrediente.clear();
    suprafete.clear();
}

Dezinfectant& Dezinfectant::operator=(const Dezinfectant& dezinfectant) {
    if (this != &dezinfectant) {
        this->eficienta = dezinfectant.eficienta;
        ingrediente.clear();
        ingrediente.insert(ingrediente.end(), dezinfectant.ingrediente.begin(), dezinfectant.ingrediente.end());
        suprafete.clear();
        suprafete.insert(suprafete.end(), dezinfectant.suprafete.begin(), dezinfectant.suprafete.end());
    }
    return *this;
}

void Dezinfectant::citire(std::istream& is) {
    cit(is);
}
void Dezinfectant::afisare(std::ostream& os) const {
    afi(os);
}

//----------------------------------------DezinfectantBacterii
class DezinfectantBacterii : virtual public Dezinfectant {
protected:
	int nrSpeciiBacterii;
	static int nrSpeciiBacteriiExistente;

	virtual void cit(std::istream& is);
	virtual void afi(std::ostream& os) const;

public:
	DezinfectantBacterii(std::vector<std::string> ingrediente = {}, std::vector<std::string> suprafete = {}, int nrSpeciiBacterii = 0) : Dezinfectant(ingrediente, suprafete) {
		this->nrSpeciiBacterii = nrSpeciiBacterii;
        this->eficienta = nrSpeciiBacterii / nrSpeciiBacteriiExistente;
	}
	DezinfectantBacterii(const DezinfectantBacterii& dezinfectant);
	virtual ~DezinfectantBacterii();

	DezinfectantBacterii& operator=(const DezinfectantBacterii& dezinfectant);

	int nrSpeciiBacteriiGet() const { return nrSpeciiBacterii; }
	static int nrSpeciiBacteriiExistenteGet() { return nrSpeciiBacteriiExistente; }

	virtual void citire(std::istream& is);
	virtual void afisare(std::ostream& os) const;
};
int DezinfectantBacterii::nrSpeciiBacteriiExistente = 1000000000;

void DezinfectantBacterii::cit(std::istream& is) {
    is.exceptions(std::istream::failbit);
citDezinfectantBacterii:
    try {
        std::cout << "nrSpeciiBacterii: "; is >> nrSpeciiBacterii;
        eficienta = (double)nrSpeciiBacterii / nrSpeciiBacteriiExistente;
    }
    catch (const std::ios_base::failure&) {
        is.clear();
        is.ignore(INT_MAX, '\n');
        std::cout << "Numar invalid\n";
        goto citDezinfectantBacterii;
    }
}
void DezinfectantBacterii::afi(std::ostream& os) const {
    os << "nrSpeciiBacterii:" << nrSpeciiBacterii << "\n";
}

DezinfectantBacterii::DezinfectantBacterii(const DezinfectantBacterii& dezinfectant) : Dezinfectant(dezinfectant) {
    this->nrSpeciiBacterii = dezinfectant.nrSpeciiBacterii;
}
DezinfectantBacterii::~DezinfectantBacterii() {
}

DezinfectantBacterii& DezinfectantBacterii::operator=(const DezinfectantBacterii& dezinfectant) {
    if (this != &dezinfectant) {
        Dezinfectant::operator=(dezinfectant);
        this->nrSpeciiBacterii = dezinfectant.nrSpeciiBacterii;
    }
    return *this;
}

void DezinfectantBacterii::citire(std::istream& is) {
    Dezinfectant::cit(is);
    cit(is);
}
void DezinfectantBacterii::afisare(std::ostream& os) const {
    Dezinfectant::afi(os);
    afi(os);
}

//----------------------------------------DezinfectantFungi
class DezinfectantFungi : virtual public Dezinfectant {
protected:
	int nrSpeciiFungi;
	static int nrSpeciiFungiExistente;

	virtual void cit(std::istream& is);
	virtual void afi(std::ostream& os) const;

public:
	DezinfectantFungi(std::vector<std::string> ingrediente = {}, std::vector<std::string> suprafete = {}, int nrSpeciiFungi = 0) : Dezinfectant(ingrediente, suprafete) {
		this->nrSpeciiFungi = nrSpeciiFungi;
        this->eficienta = nrSpeciiFungi / nrSpeciiFungiExistente;
	}
	DezinfectantFungi(const DezinfectantFungi& dezinfectant);
	virtual ~DezinfectantFungi();

	DezinfectantFungi& operator=(const DezinfectantFungi& dezinfectant);

	int nrSpeciiFungiGet() const { return nrSpeciiFungi; }
	static int nrSpeciiFungiExistenteGet() { return nrSpeciiFungiExistente; }

	virtual void citire(std::istream& is);
	virtual void afisare(std::ostream& os) const;
};
int DezinfectantFungi::nrSpeciiFungiExistente = 1500000;

void DezinfectantFungi::cit(std::istream& is) {
    is.exceptions(std::istream::failbit);
citDezinfectantFungi:
    try {
        std::cout << "nrSpeciiFungi: "; is >> nrSpeciiFungi;
        eficienta = (double)nrSpeciiFungi / nrSpeciiFungiExistente;
    }
    catch (const std::ios_base::failure&) {
        is.clear();
        is.ignore(INT_MAX, '\n');
        std::cout << "Numar invalid\n";
        goto citDezinfectantFungi;
    }
}
void DezinfectantFungi::afi(std::ostream& os) const {
    os << "nrSpeciiFungi:" << nrSpeciiFungi << "\n";
}

DezinfectantFungi::DezinfectantFungi(const DezinfectantFungi& dezinfectant) : Dezinfectant(dezinfectant) {
    this->nrSpeciiFungi = dezinfectant.nrSpeciiFungi;
}
DezinfectantFungi::~DezinfectantFungi() {
}

DezinfectantFungi& DezinfectantFungi::operator=(const DezinfectantFungi& dezinfectant) {
    if (this != &dezinfectant) {
        Dezinfectant::operator=(dezinfectant);
        this->nrSpeciiFungi = dezinfectant.nrSpeciiFungi;
    }
    return *this;
}

void DezinfectantFungi::citire(std::istream& is) {
    Dezinfectant::cit(is);
    cit(is);
}
void DezinfectantFungi::afisare(std::ostream& os) const {
    Dezinfectant::afi(os);
    afi(os);
}

//----------------------------------------DezinfectantVirusuri
class DezinfectantVirusuri : virtual public Dezinfectant {
protected:
	int nrSpeciiVirusuri;
	static int nrSpeciiVirusuriExistente;

	virtual void cit(std::istream& is);
	virtual void afi(std::ostream& os) const;

public:
	DezinfectantVirusuri(std::vector<std::string> ingrediente = {}, std::vector<std::string> suprafete = {}, int nrSpeciiVirusuri = 0) : Dezinfectant(ingrediente, suprafete) {
		this->nrSpeciiVirusuri = nrSpeciiVirusuri;
        this->eficienta = nrSpeciiVirusuri / nrSpeciiVirusuriExistente;
	}
	DezinfectantVirusuri(const DezinfectantVirusuri& dezinfectant);
	virtual ~DezinfectantVirusuri();

	DezinfectantVirusuri& operator=(const DezinfectantVirusuri& dezinfectant);

	int nrSpeciiVirusuriGet() const { return nrSpeciiVirusuri; }
	static int nrSpeciiVirusuriExistenteGet() { return nrSpeciiVirusuriExistente; }

	virtual void citire(std::istream& is);
	virtual void afisare(std::ostream& os) const;
};
int DezinfectantVirusuri::nrSpeciiVirusuriExistente = 100000000;

void DezinfectantVirusuri::cit(std::istream& is) {
    is.exceptions(std::istream::failbit);
citDezinfectantVirusuri:
    try {
        std::cout << "nrSpeciiVirusuri: "; is >> nrSpeciiVirusuri;
        eficienta = (double)nrSpeciiVirusuri / nrSpeciiVirusuriExistente;
    }
    catch (const std::ios_base::failure&) {
        is.clear();
        is.ignore(INT_MAX, '\n');
        std::cout << "Numar invalid\n";
        goto citDezinfectantVirusuri;
    }
}
void DezinfectantVirusuri::afi(std::ostream& os) const {
    os << "nrSpeciiVirusuri:" << nrSpeciiVirusuri << "\n";
}

DezinfectantVirusuri::DezinfectantVirusuri(const DezinfectantVirusuri& dezinfectant) : Dezinfectant(dezinfectant) {
    this->nrSpeciiVirusuri = dezinfectant.nrSpeciiVirusuri;
}
DezinfectantVirusuri::~DezinfectantVirusuri() {
}

DezinfectantVirusuri& DezinfectantVirusuri::operator=(const DezinfectantVirusuri& dezinfectant) {
    if (this != &dezinfectant) {
        Dezinfectant::operator=(dezinfectant);
        this->nrSpeciiVirusuri = dezinfectant.nrSpeciiVirusuri;
    }
    return *this;
}

void DezinfectantVirusuri::citire(std::istream& is) {
    Dezinfectant::cit(is);
    cit(is);
}
void DezinfectantVirusuri::afisare(std::ostream& os) const {
    Dezinfectant::afi(os);
    afi(os);
}

//----------------------------------------DezinfectantUniversal
class DezinfectantUniversal : public DezinfectantBacterii, public DezinfectantFungi, public DezinfectantVirusuri {
protected:

	void cit(std::istream& is);
	void afi(std::ostream& os) const;

public:
	DezinfectantUniversal(std::vector<std::string> ingrediente = {}, std::vector<std::string> suprafete = {}, int nrSpeciiBacteriiBacterii = 0, int nrSpeciiBacteriiFungi = 0, int nrSpeciiBacteriiVirusuri = 0) : DezinfectantBacterii(ingrediente, suprafete, nrSpeciiBacteriiBacterii), DezinfectantFungi(ingrediente, suprafete, nrSpeciiBacteriiFungi), DezinfectantVirusuri(ingrediente, suprafete, nrSpeciiBacteriiVirusuri) {
	}
	DezinfectantUniversal(const DezinfectantUniversal& dezinfectant);
	~DezinfectantUniversal();

	DezinfectantUniversal& operator=(const DezinfectantUniversal& dezinfectant);


	void citire(std::istream& is);
	void afisare(std::ostream& os) const;
};

void DezinfectantUniversal::cit(std::istream& is) {
    is.exceptions(std::istream::failbit);
citDezinfectantUniversal:
    try {
        eficienta = double(DezinfectantBacterii::nrSpeciiBacterii + DezinfectantFungi::nrSpeciiFungi + DezinfectantVirusuri::nrSpeciiVirusuri) / (DezinfectantBacterii::nrSpeciiBacteriiExistente + DezinfectantFungi::nrSpeciiFungiExistente + DezinfectantVirusuri::nrSpeciiVirusuriExistente);
    }
    catch (const std::ios_base::failure&) {
        is.clear();
        is.ignore(INT_MAX, '\n');
        std::cout << "Numar invalid\n";
        goto citDezinfectantUniversal;
    }
}
void DezinfectantUniversal::afi(std::ostream& os) const {
}

DezinfectantUniversal::DezinfectantUniversal(const DezinfectantUniversal& dezinfectant) : DezinfectantBacterii(dezinfectant), DezinfectantFungi(dezinfectant), DezinfectantVirusuri(dezinfectant) {
}
DezinfectantUniversal::~DezinfectantUniversal() {
}

DezinfectantUniversal& DezinfectantUniversal::operator=(const DezinfectantUniversal& dezinfectant) {
    if (this != &dezinfectant) {
        DezinfectantBacterii::operator=(dezinfectant);
        DezinfectantFungi::operator=(dezinfectant);
        DezinfectantVirusuri::operator=(dezinfectant);
    }
    return *this;
}

void DezinfectantUniversal::citire(std::istream& is) {
    Dezinfectant::cit(is);
    DezinfectantBacterii::cit(is);
    DezinfectantFungi::cit(is);
    DezinfectantVirusuri::cit(is);
    cit(is);
}
void DezinfectantUniversal::afisare(std::ostream& os) const {
    Dezinfectant::afi(os);
    DezinfectantBacterii::afi(os);
    DezinfectantFungi::afi(os);
    DezinfectantVirusuri::afi(os);
    afi(os);
}

//----------------------------------------Masca
class Masca {
protected:
	static int contor;
	int protectie;

	virtual void cit(std::istream& is);
	virtual void afi(std::ostream& os) const;

public:
	Masca(int protectie = 0) {
		contor++;
		this->protectie = protectie;
	}

	Masca(const Masca& masca);
	virtual ~Masca();

	Masca& operator=(const Masca& masca);

	static int contorGet() { return contor; }
	int protectieGet() const { return protectie; }

	virtual void citire(std::istream& is);
	virtual void afisare(std::ostream& os) const;
};
int Masca::contor = 0;

void Masca::cit(std::istream& is) {
    is.exceptions(std::istream::failbit);
citMasca:
    try {
        std::cout << "protectie: "; is >> protectie;
    }
    catch (const std::ios_base::failure&) {
        is.clear();
        is.ignore(INT_MAX, '\n');
        std::cout << "Numar invalid\n";
        goto citMasca;
    }
}
void Masca::afi(std::ostream& os) const {
    os << "protectie:" << protectie << "\n";
}

Masca::Masca(const Masca& masca) {
    contor++;
    this->protectie = masca.protectie;
}
Masca::~Masca() {
    contor--;
}

Masca& Masca::operator=(const Masca& masca) {
    if (this != &masca) {
        this->protectie = masca.protectie;
    }
    return *this;
}

void Masca::citire(std::istream& is) {
    cit(is);
}
void Masca::afisare(std::ostream& os) const {
    afi(os);
}

//----------------------------------------MascaChirurgicala
class MascaChirurgicala : public Masca {
protected:
	std::string culoare;
	int pliuri;

	void cit(std::istream& is);
	void afi(std::ostream& os) const;

public:
	MascaChirurgicala(int protectie = 0, std::string culoare= "", int pliuri = 0) : Masca(protectie) {
		this->culoare = culoare;
		this->pliuri = pliuri;
	}
	MascaChirurgicala(const MascaChirurgicala& masca);
	~MascaChirurgicala();

	MascaChirurgicala& operator=(const MascaChirurgicala& masca);

	std::string culoareGet() const { return culoare; }
	int pliuriGet() const { return pliuri; }

	void citire(std::istream& is);
	void afisare(std::ostream& os) const;
};

void MascaChirurgicala::cit(std::istream& is) {
    is.exceptions(std::istream::failbit);
citMascaChirurgicala:
    try {
        std::cout << "culoare: "; is >> culoare;
        std::cout << "pliuri: "; is >> pliuri;
    }
    catch (const std::ios_base::failure&) {
        is.clear();
        is.ignore(INT_MAX, '\n');
        std::cout << "Numar invalid\n";
        goto citMascaChirurgicala;
    }
}
void MascaChirurgicala::afi(std::ostream& os) const {
    os << "culoare:" << culoare << "\n";
    os << "pliuri:" << pliuri << "\n";
}

MascaChirurgicala::MascaChirurgicala(const MascaChirurgicala& masca) : Masca(masca) {
    this->culoare = masca.culoare;
    this->pliuri = masca.pliuri;
}
MascaChirurgicala::~MascaChirurgicala() {
}

MascaChirurgicala& MascaChirurgicala::operator=(const MascaChirurgicala& masca) {
    if (this != &masca) {
        Masca::operator=(masca);
        this->culoare = masca.culoare;
        this->pliuri = masca.pliuri;
    }
    return *this;
}

void MascaChirurgicala::citire(std::istream& is) {
    protectie = 0;
    cit(is);
}
void MascaChirurgicala::afisare(std::ostream& os) const {
    Masca::afi(os);
    afi(os);
}

//----------------------------------------MascaPolicarbonat
class MascaPolicarbonat : public Masca {
protected:
	std::string prindere;

	void cit(std::istream& is);
	void afi(std::ostream& os) const;

public:
	MascaPolicarbonat(std::string prindere = "") : Masca(0) {
		this->prindere = prindere;
	}
	MascaPolicarbonat(const MascaPolicarbonat& masca);
	~MascaPolicarbonat();

	MascaPolicarbonat& operator=(const MascaPolicarbonat& masca);

	std::string prindereGet() const { return prindere; }

	void citire(std::istream& is);
	void afisare(std::ostream& os) const;
};

void MascaPolicarbonat::cit(std::istream& is) {
    is.exceptions(std::istream::failbit);
citMascaPolicarbonat:
    try {
        std::cout << "prindere: "; is >> prindere;
    }
    catch (const std::ios_base::failure&) {
        is.clear();
        is.ignore(INT_MAX, '\n');
        std::cout << "Numar invalid\n";
        goto citMascaPolicarbonat;
    }
}
void MascaPolicarbonat::afi(std::ostream& os) const {
    os << "prindere:" << prindere << "\n";
}

MascaPolicarbonat::MascaPolicarbonat(const MascaPolicarbonat& masca) : Masca(masca) {
    this->prindere = masca.prindere;
}
MascaPolicarbonat::~MascaPolicarbonat() {
}

MascaPolicarbonat& MascaPolicarbonat::operator=(const MascaPolicarbonat& masca) {
    if (this != &masca) {
        Masca::operator=(masca);
        this->prindere = masca.prindere;
    }
    return *this;
}

void MascaPolicarbonat::citire(std::istream& is) {
    Masca::cit(is);
    cit(is);
}
void MascaPolicarbonat::afisare(std::ostream& os) const {
    Masca::afi(os);
    afi(os);
}


//----------------------------------------Achizitie
class Achizitie {
protected:
	static int contor;
	std::string numeClient;
	int ziua;
	int luna;
	int anul;
	std::vector<Dezinfectant*> dezinfectanti;

	virtual void cit(std::istream& is);
	virtual void afi(std::ostream& os) const;

public:
	Achizitie(std::string numeClient= "", int ziua = 0, int luna = 0, int anul = 0) {
		contor++;
		this->numeClient = numeClient;
		this->ziua = ziua;
		this->luna = luna;
		this->anul = anul;
	}

	Achizitie(const Achizitie& achizitie);
	~Achizitie();

	Achizitie& operator=(const Achizitie& achizitie);

	static int contorGet() { return contor; }
	std::string numeClientGet() const { return numeClient; }
	int ziuaGet() const { return ziua; }
	int lunaGet() const { return luna; }
	int anulGet() const { return anul; }
	std::vector<Dezinfectant*> dezinfectantiGet() const { return dezinfectanti; }

	void citire(std::istream& is);
	void afisare(std::ostream& os) const;
};
int Achizitie::contor = 0;

void Achizitie::cit(std::istream& is) {
    is.exceptions(std::istream::failbit);
citAchizitie:
    try {
        std::cout << "numeClient: "; is >> numeClient;
        std::cout << "ziua: "; is >> ziua;
        std::cout << "luna: "; is >> luna;
        std::cout << "anul: "; is >> anul;
        int nrDezinfectanti;
        std::cout << "nrDezinfectanti: "; is >> nrDezinfectanti;
        for (int i = 0; i < nrDezinfectanti; i++) {
            Dezinfectant* dezinfectant;
            std::cout << "dezinfectant: "; dezinfectant->citire(is);
            dezinfectanti.push_back(dezinfectant);
        }
    }
    catch (const std::ios_base::failure&) {
        is.clear();
        is.ignore(INT_MAX, '\n');
        std::cout << "Numar invalid\n";
        goto citAchizitie;
    }
}
void Achizitie::afi(std::ostream& os) const {
    os << "numeClient:" << numeClient << "\n";
    os << "ziua:" << ziua << "\n";
    os << "luna:" << luna << "\n";
    os << "anul:" << anul << "\n";
    os << "dezinfectanti:" << dezinfectanti.size() << "\n";
    for (std::vector<Dezinfectant*>::const_iterator i = dezinfectanti.begin(); i != dezinfectanti.end(); i++) {
        (*i)->afisare(os); os << " ";
    }
}

Achizitie::Achizitie(const Achizitie& achizitie) {
    contor++;
    this->numeClient = achizitie.numeClient;
    this->ziua = achizitie.ziua;
    this->luna = achizitie.luna;
    this->anul = achizitie.anul;
    dezinfectanti.insert(dezinfectanti.end(), achizitie.dezinfectanti.begin(), achizitie.dezinfectanti.end());
}
Achizitie::~Achizitie() {
    contor--;
    dezinfectanti.clear();
}

Achizitie& Achizitie::operator=(const Achizitie& achizitie) {
    if (this != &achizitie) {
        this->numeClient = achizitie.numeClient;
        this->ziua = achizitie.ziua;
        this->luna = achizitie.luna;
        this->anul = achizitie.anul;
        dezinfectanti.clear();
        dezinfectanti.insert(dezinfectanti.end(), achizitie.dezinfectanti.begin(), achizitie.dezinfectanti.end());
    }
    return *this;
}

void Achizitie::citire(std::istream& is) {
    cit(is);
}
void Achizitie::afisare(std::ostream& os) const {
    afi(os);
}



//----------------------------------------Meniu
class Meniu {
    std::vector<Dezinfectant*> dezinfectante;
    static Meniu* instanta;
    Meniu() {}
public:
    ~Meniu();
    static Meniu* instantaGet();

    void ruleaza();
};
Meniu::~Meniu() { dezinfectante.clear(); }

Meniu* Meniu::instanta = nullptr;
Meniu* Meniu::instantaGet() {
    if(instanta == nullptr) {
        instanta = new Meniu;
    }
    return instanta;
}

void Meniu::ruleaza() {
    //am modificat anumite lucruri
    std::cout << "demo" << "\n";
    MascaChirurgicala mc1, mc2(2, "verde brotăcel", 55), mc3(mc1), mc4, mc5;
    mc4 = mc2;
    mc5.citire(std::cin);
    mc1.afisare(std::cout); mc2.afisare(std::cout);
    MascaPolicarbonat* mp1=new MascaPolicarbonat(), * mp2=new MascaPolicarbonat();
    MascaPolicarbonat* mp3 = new MascaPolicarbonat("elastic");
    mp1->citire(std::cin); mp2->citire(std::cin);
    mp3->afisare(std::cout);
    Dezinfectant* d1 = new DezinfectantBacterii(std::vector<std::string>({"sulfati non-ionici", "sulfati cationici", "parfumuri", "Linalool", "Metilpropanol butilpentil"}), std::vector<std::string>({"lemn", "sticla", "metal", "ceramica", "marmura"}), 100000000);
    Dezinfectant* d2 = new DezinfectantVirusuri(std::vector<std::string>({"Alkil Dimetilm Benzil Crlorura de amoniu", "parfumuri", "Butilpentil metilpropinal"}), std::vector<std::string>({"lemn", "sticla", "ceramica", "marmura"}), 50000000);
    Dezinfectant* d3 = new DezinfectantFungi(std::vector<std::string>({"Alkil Etil Benzil Crlorura de amoniu", "parfumuri", "Butilpentil metilpropinal"}), std::vector<std::string>({"sticla", "plastic"}), 1400000);
    std::cout << d1->eficientaGet() << " " << d2->eficientaGet() << " " << d3->eficientaGet() << "\n";
    Achizitie* a1 = new Achizitie("PlushBio SRL", 26, 5, 2020);
    Achizitie* a2 = new Achizitie("Gucci", 25, 5, 2020);
    Achizitie a3, a4(*a1);

    //nu am avut timp sa fac chiar cerintele
    std::cout << "meniu" << "\n";
    std::string optiune;
    while (true) {
        {
            std::cout << "optiuni:" << "\n";
            std::cout << "1. creeaza dezinfectant" << "\n";
            std::cout << "2. afiseaza dezinfectante" << "\n";
            std::cout << "3. sterge dezinfectant " << "\n";
            std::cout << "4. afiseaza " << "\n";
            std::cout << "0. iesire" << "\n";
            std::cout << "R: ";
        }
        std::cin >> optiune;
        std::cin.clear();
        std::cin.ignore(INT_MAX, '\n');
        std::cout << "\n";
        if (optiune == "0") {
            return;
        }
        else if (optiune == "1") {
            Dezinfectant* dezinfectant;
            try {
                std::string tip;
            alege:
                std::cout << "tip: "; std::cin >> tip;
                if (tip == "DezinfectantBacterii") {
                    dezinfectant = new DezinfectantBacterii;
                }
                else if (tip == "DezinfectantFungi") {
                    dezinfectant = new DezinfectantFungi;
                }
                else if (tip == "DezinfectantVirusuri") {
                    dezinfectant = new DezinfectantVirusuri;
                }
                else if (tip == "DezinfectantUniversal") {
                    dezinfectant = new DezinfectantUniversal;
                }
                else {
                    std::cout << "optiune invalida, variantele sunt: DezinfectantBacterii, DezinfectantFungi, DezinfectantVirusuri, DezinfectantUniversal" << "\n";
                    goto alege;
                }
            }
            catch (const std::bad_alloc&) {
                std::cerr << "Memorie insuficienta\n";
                exit(1);
            }
            dezinfectant->citire(std::cin);
            dezinfectante.push_back(dezinfectant);
        }
        else if (optiune == "2") {
            for (std::vector<Dezinfectant*>::iterator it = dezinfectante.begin(); it != dezinfectante.end(); it++) {
                (*it)->afisare(std::cout);  std::cout << "\n";
            }
        }
        else if (optiune == "3") {
            for (std::vector<Dezinfectant*>::iterator it = dezinfectante.begin(); it != dezinfectante.end(); it++) {
                dezinfectante.erase(it);
                break;
            }
        }
        else {
            std::cout << "optiune invalida" << "\n";
        }
        std::cin.get();
        std::cin.clear();
        std::cin.ignore(INT_MAX, '\n');
        std::cout << "\n";
    }
}



//----------------------------------------Main
int main() {
	Meniu* meniu = Meniu::instantaGet();
	meniu->ruleaza();
	delete meniu;

	return 0;
}
