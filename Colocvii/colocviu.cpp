#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include <cstdlib>
#include <algorithm>


typedef std::string vectorTip1;
typedef std::string vectorTipD1;
//----------------------------------------Baza
class Baza {
protected:
	static int contor;
	std::string text1;
	std::string text2;
	std::string text3;
	std::string text4;
	std::string text5;
	int numar1;
	int numar2;
	int numar3;
	int numar4;
	double numar5;
	double numar6;
	std::vector<vectorTip1> vector1;

	virtual void cit(std::istream& is);
	virtual void afi(std::ostream& os) const;

public:
	Baza(std::string text1 = "", std::string text2 = "", std::string text3 = "", std::string text4= "", std::string text5= "", int numar1 = 0, int numar2 = 0, int numar3 = 0, int numar4 = 0, double numar5 = 0, double numar6 = 0) {
		contor++;
		this->text1 = text1;
		this->text2 = text2;
		this->text3 = text3;
		this->text4 = text4;
		this->text5 = text5;
		this->numar1 = numar1;
		this->numar2 = numar2;
		this->numar3 = numar3;
		this->numar4 = numar4;
		this->numar5 = numar5;
		this->numar6 = numar6;
	}

	Baza(const Baza& baza);
	virtual ~Baza();

	Baza& operator=(const Baza& baza);

	static int contorGet() { return contor; }
	std::string text1Get() const { return text1; }
	std::string text2Get() const { return text2; }
	std::string text3Get() const { return text3; }
	std::string text4Get() const { return text4; }
	std::string text5Get() const { return text5; }
	int numar1Get() const { return numar1; }
	int numar2Get() const { return numar2; }
	int numar3Get() const { return numar3; }
	int numar4Get() const { return numar4; }
	double numar5Get() const { return numar5; }
	double numar6Get() const { return numar6; }
	std::vector<vectorTip1> vector1Get() const { return vector1; }

	virtual void citire(std::istream& is);
	virtual void afisare(std::ostream& os) const;
};
int Baza::contor = 0;

void Baza::cit(std::istream& is) {
    is.exceptions(std::istream::failbit);
citBaza:
    try {
        std::cout << "text1: "; is >> text1;
        std::cout << "text2: "; is >> text2;
        std::cout << "text3: "; is >> text3;
        std::cout << "text4: "; is >> text4;
        std::cout << "text5: "; is >> text5;
        std::cout << "numar1: "; is >> numar1;
        std::cout << "numar2: "; is >> numar2;
        std::cout << "numar3: "; is >> numar3;
        std::cout << "numar4: "; is >> numar4;
        std::cout << "numar5: "; is >> numar5;
        std::cout << "numar6: "; is >> numar6;
        int nrVector1;
        std::cout << "nrVector1: "; is >> nrVector1;
        for (int i = 0; i < nrVector1; i++) {
            vectorTip1 Vector1;
            std::cout << "Vector1: "; is >> Vector1;
            vector1.push_back(Vector1);
        }
    }
    catch (const std::ios_base::failure&) {
        is.clear();
        is.ignore(INT_MAX, '\n');
        std::cout << "Numar invalid\n";
        goto citBaza;
    }
}
void Baza::afi(std::ostream& os) const {
    os << "text1:" << text1 << "\n";
    os << "text2:" << text2 << "\n";
    os << "text3:" << text3 << "\n";
    os << "text4:" << text4 << "\n";
    os << "text5:" << text5 << "\n";
    os << "numar1:" << numar1 << "\n";
    os << "numar2:" << numar2 << "\n";
    os << "numar3:" << numar3 << "\n";
    os << "numar4:" << numar4 << "\n";
    os << "numar5:" << numar5 << "\n";
    os << "numar6:" << numar6 << "\n";
    os << "vector1:" << vector1.size() << "\n";
    for (std::vector<vectorTip1>::const_iterator i = vector1.begin(); i != vector1.end(); i++) {
        os << *i << " ";
    }
}

Baza::Baza(const Baza& baza) {
    contor++;
    this->text1 = baza.text1;
    this->text2 = baza.text2;
    this->text3 = baza.text3;
    this->text4 = baza.text4;
    this->text5 = baza.text5;
    this->numar1 = baza.numar1;
    this->numar2 = baza.numar2;
    this->numar3 = baza.numar3;
    this->numar4 = baza.numar4;
    this->numar5 = baza.numar5;
    this->numar6 = baza.numar6;
    vector1.insert(vector1.end(), baza.vector1.begin(), baza.vector1.end());
}
Baza::~Baza() {
    contor--;
    vector1.clear();
}

Baza& Baza::operator=(const Baza& baza) {
    if (this != &baza) {
        this->text1 = baza.text1;
        this->text2 = baza.text2;
        this->text3 = baza.text3;
        this->text4 = baza.text4;
        this->text5 = baza.text5;
        this->numar1 = baza.numar1;
        this->numar2 = baza.numar2;
        this->numar3 = baza.numar3;
        this->numar4 = baza.numar4;
        this->numar5 = baza.numar5;
        this->numar6 = baza.numar6;
        vector1.clear();
        vector1.insert(vector1.end(), baza.vector1.begin(), baza.vector1.end());
    }
    return *this;
}

void Baza::citire(std::istream& is) {
    cit(is);
}
void Baza::afisare(std::ostream& os) const {
    afi(os);
}

//----------------------------------------Derivata
class Derivata : public Baza {
protected:
	std::string textD1;
	std::string textD2;
	std::string textD3;
	std::string textD4;
	std::string textD5;
	int numarD1;
	int numarD2;
	int numarD3;
	int numarD4;
	double numarD5;
	double numarD6;
	std::vector<vectorTipD1> vectorD1;

	virtual void cit(std::istream& is);
	virtual void afi(std::ostream& os) const;

public:
	Derivata(std::string text1 = "", std::string text2 = "", std::string text3 = "", std::string text4= "", std::string text5= "", int numar1 = 0, int numar2 = 0, int numar3 = 0, int numar4 = 0, double numar5 = 0, double numar6 = 0, std::string textD1 = "", std::string textD2 = "", std::string textD3 = "", std::string textD4= "", std::string textD5= "", int numarD1 = 0, int numarD2 = 0, int numarD3 = 0, int numarD4 = 0, double numarD5 = 0, double numarD6 = 0) : Baza(text1, text2, text3, text4, text5, numar1, numar2, numar3, numar4, numar5, numar6) {
		this->textD1 = textD1;
		this->textD2 = textD2;
		this->textD3 = textD3;
		this->textD4 = textD4;
		this->textD5 = textD5;
		this->numarD1 = numarD1;
		this->numarD2 = numarD2;
		this->numarD3 = numarD3;
		this->numarD4 = numarD4;
		this->numarD5 = numarD5;
		this->numarD6 = numarD6;
	}
	Derivata(const Derivata& baza);
	virtual ~Derivata();

	Derivata& operator=(const Derivata& baza);

	std::string textD1Get() const { return textD1; }
	std::string textD2Get() const { return textD2; }
	std::string textD3Get() const { return textD3; }
	std::string textD4Get() const { return textD4; }
	std::string textD5Get() const { return textD5; }
	int numarD1Get() const { return numarD1; }
	int numarD2Get() const { return numarD2; }
	int numarD3Get() const { return numarD3; }
	int numarD4Get() const { return numarD4; }
	double numarD5Get() const { return numarD5; }
	double numarD6Get() const { return numarD6; }
	std::vector<vectorTipD1> vectorD1Get() const { return vectorD1; }

	virtual void citire(std::istream& is);
	virtual void afisare(std::ostream& os) const;
};

void Derivata::cit(std::istream& is) {
    is.exceptions(std::istream::failbit);
citDerivata:
    try {
        std::cout << "textD1: "; is >> textD1;
        std::cout << "textD2: "; is >> textD2;
        std::cout << "textD3: "; is >> textD3;
        std::cout << "textD4: "; is >> textD4;
        std::cout << "textD5: "; is >> textD5;
        std::cout << "numarD1: "; is >> numarD1;
        std::cout << "numarD2: "; is >> numarD2;
        std::cout << "numarD3: "; is >> numarD3;
        std::cout << "numarD4: "; is >> numarD4;
        std::cout << "numarD5: "; is >> numarD5;
        std::cout << "numarD6: "; is >> numarD6;
        int nrVectorD1;
        std::cout << "nrVectorD1: "; is >> nrVectorD1;
        for (int i = 0; i < nrVectorD1; i++) {
            vectorTipD1 VectorD1;
            std::cout << "VectorD1: "; is >> VectorD1;
            vectorD1.push_back(VectorD1);
        }
    }
    catch (const std::ios_base::failure&) {
        is.clear();
        is.ignore(INT_MAX, '\n');
        std::cout << "Numar invalid\n";
        goto citDerivata;
    }
}
void Derivata::afi(std::ostream& os) const {
    os << "textD1:" << textD1 << "\n";
    os << "textD2:" << textD2 << "\n";
    os << "textD3:" << textD3 << "\n";
    os << "textD4:" << textD4 << "\n";
    os << "textD5:" << textD5 << "\n";
    os << "numarD1:" << numarD1 << "\n";
    os << "numarD2:" << numarD2 << "\n";
    os << "numarD3:" << numarD3 << "\n";
    os << "numarD4:" << numarD4 << "\n";
    os << "numarD5:" << numarD5 << "\n";
    os << "numarD6:" << numarD6 << "\n";
    os << "vectorD1:" << vectorD1.size() << "\n";
    for (std::vector<vectorTipD1>::const_iterator i = vectorD1.begin(); i != vectorD1.end(); i++) {
        os << *i << " ";
    }
}

Derivata::Derivata(const Derivata& baza) : Baza(baza) {
    this->textD1 = baza.textD1;
    this->textD2 = baza.textD2;
    this->textD3 = baza.textD3;
    this->textD4 = baza.textD4;
    this->textD5 = baza.textD5;
    this->numarD1 = baza.numarD1;
    this->numarD2 = baza.numarD2;
    this->numarD3 = baza.numarD3;
    this->numarD4 = baza.numarD4;
    this->numarD5 = baza.numarD5;
    this->numarD6 = baza.numarD6;
    vectorD1.insert(vectorD1.end(), baza.vectorD1.begin(), baza.vectorD1.end());
}
Derivata::~Derivata() {
    vectorD1.clear();
}

Derivata& Derivata::operator=(const Derivata& baza) {
    if (this != &baza) {
        Baza::operator=(baza);
        this->textD1 = baza.textD1;
        this->textD2 = baza.textD2;
        this->textD3 = baza.textD3;
        this->textD4 = baza.textD4;
        this->textD5 = baza.textD5;
        this->numarD1 = baza.numarD1;
        this->numarD2 = baza.numarD2;
        this->numarD3 = baza.numarD3;
        this->numarD4 = baza.numarD4;
        this->numarD5 = baza.numarD5;
        this->numarD6 = baza.numarD6;
        vectorD1.clear();
        vectorD1.insert(vectorD1.end(), baza.vectorD1.begin(), baza.vectorD1.end());
    }
    return *this;
}

void Derivata::citire(std::istream& is) {
    Baza::cit(is);
    cit(is);
}
void Derivata::afisare(std::ostream& os) const {
    Baza::afi(os);
    afi(os);
}

//----------------------------------------Meniu
class Meniu {
    std::vector<Baza*> bazae;
    static Meniu* instanta;
    Meniu() {}
public:
    ~Meniu();
    static Meniu* instantaGet();

    void ruleaza();
};
Meniu::~Meniu() { bazae.clear(); }

Meniu* Meniu::instanta = nullptr;
Meniu* Meniu::instantaGet() {
    if(instanta == nullptr) {
        instanta = new Meniu;
    }
    return instanta;
}

void Meniu::ruleaza() {
    std::string optiune;
    while (true) {
        {
            std::cout << "optiuni:" << "\n";
            std::cout << "1. creeaza baza" << "\n";
            std::cout << "2. afiseaza bazae" << "\n";
            std::cout << "3. sterge baza " << "\n";
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
            Baza* baza;
            try {
                std::string tip;
            alege:
                std::cout << "tip: "; std::cin >> tip;
                if (tip == "Baza") {
                    baza = new Baza;
                }
                else if (tip == "Derivata") {
                    baza = new Derivata;
                }
                else {
                    std::cout << "optiune invalida, variantele sunt: Baza, Derivata" << "\n";
                    goto alege;
                }
            }
            catch (const std::bad_alloc&) {
                std::cerr << "Memorie insuficienta\n";
                exit(1);
            }
            baza->citire(std::cin);
            bazae.push_back(baza);
        }
        else if (optiune == "2") {
            for (std::vector<Baza*>::iterator it = bazae.begin(); it != bazae.end(); it++) {
                (*it)->afisare(std::cout);  std::cout << "\n";
            }
        }
        else if (optiune == "3") {
            for (std::vector<Baza*>::iterator it = bazae.begin(); it != bazae.end(); it++) {
                bazae.erase(it);
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
