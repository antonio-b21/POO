#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include <cstdlib>
#include <algorithm>

//----------------------------------------Participant
class Participant {
protected:
	static int contor;
	std::string nume;
	std::string cnp;
	std::string tip;

	virtual void cit(std::istream& is, bool tipTrimis) {
		is.exceptions(std::istream::failbit);
		try {
			std::cout << "nume: "; is >> nume;
			std::cout << "cnp: "; is >> cnp;
			if (tipTrimis == 0) {
			alegeTip:
                std::cout << "tip: "; is >> tip;
				if (tip != "elev" and tip != "profesor") {
					std::cout << "optiune invalida, variantele sunt: elev, profesor" << "\n";
                    goto alegeTip;
				}
			}
			else {
                tip = "elev";
			}
		}
		catch (const std::ios_base::failure&) {
			is.clear();
			is.ignore(INT_MAX, '\n');
			std::cout << "Numar invalid\n";
			cit(is, tipTrimis);
		}
	}
	virtual void afi(std::ostream& os) const {
		os << "nume:" << nume << "\n";
		os << "cnp:" << cnp << "\n";
        os << "tip:" << tip << "\n";
	}

public:
	Participant(std::string nume = "", std::string cnp = "", std::string tip = "") {
		contor++;
		this->nume = nume;
		this->cnp = cnp;
		this->tip = tip;
	}

	Participant(const Participant& parti) {
		contor++;
		this->nume = parti.nume;
		this->cnp = parti.cnp;
		this->tip = parti.tip;
	}
	virtual ~Participant() { contor--; }

	Participant& operator=(const Participant& parti) {
		if (this != &parti) {
			this->nume = parti.nume;
			this->cnp = parti.cnp;
			this->tip = parti.tip;
		}
		return *this;
	}

	static int contorGet() { return contor; }
	std::string numeGet() { return nume; }
	std::string cnpGet() { return cnp; }
	std::string tipGet() { return tip; }

	virtual void citire(std::istream& is, bool tip = 0) {
		cit(is, tip);
	}
	virtual void afisare(std::ostream& os) const {
		afi(os);
	}
};
int Participant::contor = 0;

//----------------------------------------Activitate
class Activitate {
protected:
	static int contor;
	std::string nume;
	int anul;
	int luna;
	int ziua;
	int durata;
	std::vector<Participant> participanti;

	virtual void citParticipanti(std::istream& is) = 0;
	virtual void cit(std::istream& is) {
		is.exceptions(std::istream::failbit);
		try {
			std::cout << "nume: "; is >> nume;
			std::cout << "anul: "; is >> anul;
			std::cout << "luna: "; is >> luna;
			std::cout << "ziua: "; is >> ziua;
			std::cout << "durata: "; is >> durata;
		}
		catch (const std::ios_base::failure&) {
			is.clear();
			is.ignore(INT_MAX, '\n');
			std::cout << "Numar invalid\n";
			cit(is);
		}
	}
	virtual void afi(std::ostream& os) const {
		os << "nume:" << nume << "\n";
		os << "anul:" << anul << "\n";
		os << "luna:" << luna << "\n";
		os << "ziua:" << ziua << "\n";
		os << "durata:" << durata << "\n";
		os << "participanti:" << participanti.size() << "\n";
		for (std::vector<Participant>::const_iterator i = participanti.begin(); i != participanti.end(); i++) {
			i->afisare(os);
		}
	}

public:
	Activitate(std::string nume= "", int anul = 0, int luna = 0, int ziua = 0, int durata = 0) {
		contor++;
		this->nume = nume;
		this->anul = anul;
		this->luna = luna;
		this->ziua = ziua;
		this->durata = durata;
	}

	Activitate(const Activitate& activ) {
		contor++;
		this->nume = activ.nume;
		this->anul = activ.anul;
		this->luna = activ.luna;
		this->ziua = activ.ziua;
		this->durata = activ.durata;
		participanti.insert(participanti.end(), activ.participanti.begin(), activ.participanti.end());
	}
	virtual ~Activitate() { contor--; participanti.clear(); }

	Activitate& operator=(const Activitate& activ) {
		if (this != &activ) {
			this->nume = activ.nume;
			this->anul = activ.anul;
			this->luna = activ.luna;
			this->ziua = activ.ziua;
			this->durata = activ.durata;
			participanti.clear();
			participanti.insert(participanti.end(), activ.participanti.begin(), activ.participanti.end());
		}
		return *this;
	}

	static int contorGet() { return contor; }
	std::string numeGet() { return nume; }
	int anulGet() { return anul; }
	int lunaGet() { return luna; }
	int ziuaGet() { return ziua; }
	int durataGet() { return durata; }
	std::vector<Participant> participantiGet() { return participanti; }

	virtual void citire(std::istream& is) {
		cit(is);
	}
	virtual void afisare(std::ostream& os) const {
		afi(os);
	}
};
int Activitate::contor = 0;

//----------------------------------------Curs
class Curs : public Activitate {
protected:
	int credite;

	virtual void citParticipanti(std::istream& is) {
		is.exceptions(std::istream::failbit);
		try {
			int nrParticipanti;
			std::cout << "nrParticipanti: "; is >> nrParticipanti;
			for (int i = 0; i < nrParticipanti; i++) {
				Participant parti;
				std::cout << "parti: " << "\n"; parti.citire(is);
				participanti.push_back(parti);
			}
			std::sort(participanti.begin(), participanti.end(), [](Participant& i, Participant& j) { return (i.numeGet() < j.numeGet()); });
		}
		catch (const std::ios_base::failure&) {
			is.clear();
			is.ignore(INT_MAX, '\n');
			std::cout << "Numar invalid\n";
			citParticipanti(is);
		}
	}
	virtual void cit(std::istream& is) {
		is.exceptions(std::istream::failbit);
		try {
			std::cout << "credite: "; is >> credite;
			citParticipanti(is);
		}
		catch (const std::ios_base::failure&) {
			is.clear();
			is.ignore(INT_MAX, '\n');
			std::cout << "Numar invalid\n";
			cit(is);
		}
	}
	virtual void afi(std::ostream& os) const {
		os << "credite:" << credite << "\n";
	}

public:
	Curs(std::string nume= "", int anul = 0, int luna = 0, int ziua = 0, int durata = 0, int credite = 0) : Activitate(nume, anul, luna, ziua, durata) {
		this->credite = credite;
	}

	Curs(const Curs& activ) : Activitate(activ) {
		this->credite = activ.credite;
	}
	virtual ~Curs() {  }

	Curs& operator=(const Curs& activ) {
		if (this != &activ) {
			Activitate::operator=(activ);
			this->credite = activ.credite;
		}
		return *this;
	}

	int crediteGet() { return credite; }

	virtual void citire(std::istream& is) {
		Activitate::cit(is);
		cit(is);
	}
	virtual void afisare(std::ostream& os) const {
		Activitate::afi(os);
		afi(os);
	}
};

//----------------------------------------Concurs
class Concurs : public Activitate {
protected:
	std::vector<std::pair<Participant, double>> premianti;

	virtual void citParticipanti(std::istream& is) {
		is.exceptions(std::istream::failbit);
		try {
			int nrParticipanti;
			std::cout << "nrParticipanti: "; is >> nrParticipanti;
			for (int i = 0; i < nrParticipanti; i++) {
				Participant parti;
				std::cout << "parti: " << "\n"; parti.citire(is, 1);
				participanti.push_back(parti);
			}
		}
		catch (const std::ios_base::failure&) {
			is.clear();
			is.ignore(INT_MAX, '\n');
			std::cout << "Numar invalid\n";
			citParticipanti(is);
		}
	}
	virtual void cit(std::istream& is) {
		is.exceptions(std::istream::failbit);
		try {
			citParticipanti(is);
			int nrPremianti;
			std::cout << "nrPremianti: "; is >> nrPremianti;
			for (int i = 0; i < nrPremianti; i++) {
				Participant premiant;
				std::cout << "premiant: " << "\n"; premiant.citire(is, 1);
				double punctaj;
				std::cout << "punctaj: "; is >> punctaj;
				premianti.push_back({premiant, punctaj});
			}
			std::sort(premianti.begin(), premianti.end(), [](std::pair<Participant, double>& i, std::pair<Participant, double>& j) { return i.second < j.second; });
		}
		catch (const std::ios_base::failure&) {
			is.clear();
			is.ignore(INT_MAX, '\n');
			std::cout << "Numar invalid\n";
			cit(is);
		}
	}
	virtual void afi(std::ostream& os) const {
		os << "premianti: " << premianti.size() << "\n";
		for (std::vector<std::pair<Participant, double>>::const_iterator i = premianti.begin(); i != premianti.end(); i++) {
			os << "punctaj:" << i->second << "\n";
			i->first.afisare(os);
		} os << "\n";
	}

public:
	Concurs(std::string nume= "", int anul = 0, int luna = 0, int ziua = 0, int durata = 0) : Activitate(nume, anul, luna, ziua, durata) {
	}

	Concurs(const Concurs& activ) : Activitate(activ) {
		premianti.insert(premianti.end(), activ.premianti.begin(), activ.premianti.end());
	}
	virtual ~Concurs() { premianti.clear(); }

	Concurs& operator=(const Concurs& activ) {
		if (this != &activ) {
			Activitate::operator=(activ);
			premianti.clear();
			premianti.insert(premianti.end(), activ.premianti.begin(), activ.premianti.end());
		}
		return *this;
	}

	std::vector<std::pair<Participant, double>> premiantiGet() { return premianti; }

	virtual void citire(std::istream& is) {
		Activitate::cit(is);
		cit(is);
	}
	virtual void afisare(std::ostream& os) const {
		Activitate::afi(os);
		afi(os);
	}
};

//----------------------------------------ConcursOnline
class ConcursOnline : public Concurs {
protected:
	std::string site;

	virtual void cit(std::istream& is) {
		is.exceptions(std::istream::failbit);
		try {
			std::cout << "site: "; is >> site;
		}
		catch (const std::ios_base::failure&) {
			is.clear();
			is.ignore(INT_MAX, '\n');
			std::cout << "Numar invalid\n";
			cit(is);
		}
	}
	virtual void afi(std::ostream& os) const {
		os << "site:" << site << "\n";
	}

public:
	ConcursOnline(std::string nume= "", int anul = 0, int luna = 0, int ziua = 0, int durata = 0, std::string site = "") : Concurs(nume, anul, luna, ziua, durata) {
		this->site = site;
	}

	ConcursOnline(const ConcursOnline& activ) : Concurs(activ) {
		this->site = activ.site;
	}
	virtual ~ConcursOnline() {  }

	ConcursOnline& operator=(const ConcursOnline& activ) {
		if (this != &activ) {
			Concurs::operator=(activ);
			this->site = activ.site;
		}
		return *this;
	}

	std::string siteGet() { return site; }

	virtual void citire(std::istream& is) {
		Activitate::cit(is);
		Concurs::cit(is);
		cit(is);
	}
	virtual void afisare(std::ostream& os) const {
		Activitate::afi(os);
		Concurs::afi(os);
		afi(os);
	}
};

//----------------------------------------Meniu
class Meniu {
    std::vector<Activitate*> active;
    static Meniu* instanta;
    Meniu() {}
public:
    ~Meniu() { active.clear(); }
    static Meniu* instantaGet() { if(instanta == nullptr) instanta = new Meniu; return instanta;}

    void ruleaza() {
        std::string optiune;
        while (true) {
            {
                std::cout << "optiuni:" << "\n";
                std::cout << "1. adauga o activitate cu n participanti" << "\n";
                std::cout << "2. afiseaza participanti alfabetic pe activitati" << "\n";
                std::cout << "3. afiseaza participanti pentru o activitate dintr-o anumita data" << "\n";
				std::cout << "4. afiseaza premiantii si profesorii care participa la cursuri" << "\n";
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
                Activitate* activ;
                try {
                    std::string tip;
                alege:
                    std::cout << "tip: "; std::cin >> tip;
                    if (tip == "Curs") {
                        activ = new Curs;
                    }
					else if (tip == "Concurs") {
                        activ = new Concurs;
                    }
					else if (tip == "ConcursOnline") {
                        activ = new ConcursOnline;
                    }
                    else {
                        std::cout << "optiune invalida, variantele sunt: Curs, Concurs, ConcursOnline" << "\n";
                        goto alege;
                    }
                }
                catch (const std::bad_alloc&) {
                    std::cerr << "Memorie insuficienta\n";
                    exit(1);
                }
                activ->citire(std::cin);
                active.push_back(activ);
            }
            else if (optiune == "2") {
				for (std::vector<Activitate*>::iterator it = active.begin(); it != active.end(); it++) {
                    (*it)->afisare(std::cout);  std::cout << "\n";
                }
            }
            else if (optiune == "3") {
				int anul, luna, ziua;
				std::cout << "anul:"; std::cin >> anul;
				std::cout << "luna:"; std::cin >> luna;
				std::cout << "ziua:"; std::cin >> ziua ;
                for (std::vector<Activitate*>::iterator it = active.begin(); it != active.end(); it++) {
					if ((*it)->anulGet() == anul and (*it)->lunaGet() == luna and (*it)->ziuaGet() == ziua) {
						std::vector<Participant> participanti = (*it)->participantiGet();
						for (std::vector<Participant>::iterator i = participanti.begin(); i != participanti.end(); i++) {
							i->afisare(std::cout);
						}
					}
                }
            }
			else if (optiune == "4") {
				std::cout << "premianti:" << "\n";
                for (std::vector<Activitate*>::iterator it = active.begin(); it != active.end(); it++) {
					if (Concurs* concurs = dynamic_cast<Concurs*>(*it)) {
						std::vector<std::pair<Participant, double>> premianti = concurs->premiantiGet();
						for (std::vector<std::pair<Participant, double>>::iterator i = premianti.begin(); i != premianti.end(); i++) {
							std::cout << "punctaj:" << i->second << "\n";
                            i->first.afisare(std::cout);
						}
					}
                }
				std::cout << "profesori care participa la cursuri:" << "\n";
                for (std::vector<Activitate*>::iterator it = active.begin(); it != active.end(); it++) {
					if (dynamic_cast<Curs*>(*it)) {
						std::vector<Participant> participanti = (*it)->participantiGet();
						for (std::vector<Participant>::iterator i = participanti.begin(); i != participanti.end(); i++) {
							if (i->tipGet() == "profesor") {
								i->afisare(std::cout);
							}
						}
					}
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
};
Meniu* Meniu::instanta = nullptr;

//----------------------------------------Main
int main() {
	Meniu* meniu = Meniu::instantaGet();
	meniu->ruleaza();
	delete meniu;

	return 0;
}
