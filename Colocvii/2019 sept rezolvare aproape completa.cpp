#include <iostream>
#include <string>
#include <vector>

class Zbor {
protected:
	static int contor;
	std::string destinatie;
	int anul;
	int luna;
	int ziua;
	int ora;
	double durata;
	double pret;

	virtual void cit(std::istream& is) {
		std::cout << "destinatie: "; is >> destinatie;
		std::cout << "anul: "; is >> anul;
		std::cout << "luna: "; is >> luna;
		std::cout << "ziua: "; is >> ziua;
		std::cout << "ora: "; is >> ora;
		std::cout << "durata: "; is >> durata;
		std::cout << "pret: "; is >> pret;
	}
	virtual void afi(std::ostream& os) const {
		os << "destinatie:" << destinatie << "\n";
		os << "anul:" << anul << "\n";
		os << "luna:" << luna << "\n";
		os << "ziua:" << ziua << "\n";
		os << "ora:" << ora << "\n";
		os << "durata:" << durata << "\n";
		os << "pret:" << pret << "\n";
	}

public:
	Zbor(std::string destinatie = "", int anul = 0, int luna = 0, int ziua = 0, int ora = 0, double durata = 0, double pret = 0) {
		contor++;
		this->destinatie = destinatie;
		this->anul = anul;
		this->luna = luna;
		this->ziua = ziua;
		this->ora = ora;
		this->durata = durata;
		this->pret = pret;
	}

	Zbor(const Zbor& zbor) {
		contor++;
		this->destinatie = zbor.destinatie;
		this->anul = zbor.anul;
		this->luna = zbor.luna;
		this->ziua = zbor.ziua;
		this->ora = zbor.ora;
		this->durata = zbor.durata;
		this->pret = zbor.pret;
	}
	virtual ~Zbor() { contor--; }

	Zbor& operator=(const Zbor& zbor) {
		if (this != &zbor) {
			this->destinatie = zbor.destinatie;
			this->anul = zbor.anul;
			this->luna = zbor.luna;
			this->ziua = zbor.ziua;
			this->ora = zbor.ora;
			this->durata = zbor.durata;
			this->pret = zbor.pret;
		}
		return *this;
	}

	static int contorGet() { return contor; }
	std::string destinatieGet() { return destinatie; }
	int anulGet() { return anul; }
	int lunaGet() { return luna; }
	int ziuaGet() { return ziua; }
	int oraGet() { return ora; }
	double durataGet() { return durata; }
	double pretGet() { return pret; }

	virtual void citire(std::istream& is) {
		cit(is);
	}
	virtual void afisare(std::ostream& os) const {
		afi(os);
	}
};
int Zbor::contor = 0;

//----------------------------------------Comp
class Comp {
protected:
	static int contor;
	std::string nume;
	std::string sediu;
	std::string cod;
	int infiintare;
	std::vector<std::string> destinatii;
	std::vector<Zbor> zboruri;

	virtual void cit(std::istream& is) {
		std::cout << "nume: "; is >> nume;
		std::cout << "sediu: "; is >> sediu;
		std::cout << "cod: "; is >> cod;
		std::cout << "infiintare: "; is >> infiintare;
		int nrZboruri;
		std::cout << "nrZboruri: "; is >> nrZboruri;
		for (int i = 0; i < nrZboruri; i++) {
			Zbor zbor;
			std::cout << "zbor: " << "\n"; zbor.citire(is);
			destinatii.push_back(zbor.destinatieGet());
			zboruri.push_back(zbor);
		}

	}
	virtual void afi(std::ostream& os) const {
		os << "nume:" << nume << "\n";
		os << "sediu:" << sediu << "\n";
		os << "cod:" << cod << "\n";
		os << "infiintare:" << infiintare << "\n";
		os << "destinatii:" << destinatii.size() << "\n";
		for (std::vector<std::string>::const_iterator i = destinatii.begin(); i != destinatii.end(); i++) {
			os << *i << " ";
		} os << "\n";
	}
	virtual void afiZboruri(std::ostream& os) const {
		os << "zboruri:" << zboruri.size() << "\n";
		for (std::vector<Zbor>::const_iterator i = zboruri.begin(); i != zboruri.end(); i++) {
			i->afisare(os); os << "\n";
		} os << "\n";
	}

public:
	Comp(std::string nume = "", std::string sediu = "", std::string cod = "", int infiintare = 0) {
		contor++;
		this->nume = nume;
		this->sediu = sediu;
		this->cod = cod;
		this->infiintare = infiintare;
	}

	Comp(const Comp& comp) {
		contor++;
		this->nume = comp.nume;
		this->sediu = comp.sediu;
		this->cod = comp.cod;
		this->infiintare = comp.infiintare;
		destinatii.insert(destinatii.end(), comp.destinatii.begin(), comp.destinatii.end());
		zboruri.insert(zboruri.end(), comp.zboruri.begin(), comp.zboruri.end());
	}
	virtual ~Comp() { contor--; destinatii.clear(); zboruri.clear(); }

	Comp& operator=(const Comp& comp) {
		if (this != &comp) {
			this->nume = comp.nume;
			this->sediu = comp.sediu;
			this->cod = comp.cod;
			this->infiintare = comp.infiintare;
			destinatii.clear();
			destinatii.insert(destinatii.end(), comp.destinatii.begin(), comp.destinatii.end());
			zboruri.clear();
			zboruri.insert(zboruri.end(), comp.zboruri.begin(), comp.zboruri.end());
		}
		return *this;
	}

	static int contorGet() { return contor; }
	std::string numeGet() { return nume; }
	std::string sediuGet() { return sediu; }
	std::string codGet() { return cod; }
	int infiintareGet() { return infiintare; }
	std::vector<std::string> destinatiiGet() { return destinatii; }
	std::vector<Zbor> zboruriGet() { return zboruri; }

	virtual void citire(std::istream& is) {
		cit(is);
	}
	virtual void afisare(std::ostream& os) const {
		afi(os);
		afiZboruri(os);
	}
};
int Comp::contor = 0;

//----------------------------------------LowCost
class LowCost : virtual public Comp {
protected:
	double pretBagaj;
	double maxBagaj;

	virtual void cit(std::istream& is) {
		std::cout << "pretBagaj: "; is >> pretBagaj;
		std::cout << "maxBagaj: "; is >> maxBagaj;
	}
	virtual void afi(std::ostream& os) const {
		os << "pretBagaj:" << pretBagaj << "\n";
		os << "maxBagaj:" << maxBagaj << "\n";
	}
	virtual void afiZboruri(std::ostream& os) const {
		os << "zboruri:" << zboruri.size() << "\n";
		for (std::vector<Zbor>::const_iterator i = zboruri.begin(); i != zboruri.end(); i++) {
			i->afisare(os);
			os << "pretBagaj:" << pretBagaj << "\n";
			os << "maxBagaj:" << maxBagaj << "\n";
			os << "\n";
		} os << "\n";
	}

public:
	LowCost(std::string nume = "", std::string sediu = "", std::string cod = "", int infiintare = 0, double pretBagaj = 0, double maxBagaj = 0) : Comp(nume, sediu, cod, infiintare) {
		this->pretBagaj = pretBagaj;
		this->maxBagaj = maxBagaj;
	}

	LowCost(const LowCost& comp) : Comp(comp) {
		this->pretBagaj = comp.pretBagaj;
		this->maxBagaj = comp.maxBagaj;
	}
	virtual ~LowCost() {}

	LowCost& operator=(const LowCost& comp) {
		if (this != &comp) {
			Comp::operator=(comp);
			this->pretBagaj = comp.pretBagaj;
			this->maxBagaj = comp.maxBagaj;
		}
		return *this;
	}

	double pretBagajGet() { return pretBagaj; }
	double maxBagajGet() { return maxBagaj; }

	virtual void citire(std::istream& is) {
		Comp::cit(is);
		cit(is);
	}
	virtual void afisare(std::ostream& os) const {
		Comp::afi(os);
		afi(os);
		afiZboruri(os);
	}
};

//----------------------------------------DeLinie
class DeLinie : virtual public Comp {
protected:
	std::vector<std::string> escale;

	virtual void cit(std::istream& is) {
		int nrEscale;
		std::cout << "nrEscale: "; is >> nrEscale;
		for (int i = 0; i < nrEscale; i++) {
			std::string escala;
			std::cout << "escala: "; is >> escala;
			escale.push_back(escala);
		}
	}
	virtual void afi(std::ostream& os) const {
		os << "escale:" << escale.size() << "\n";
		for (std::vector<std::string>::const_iterator i = escale.begin(); i != escale.end(); i++) {
			os << *i << " ";
		} os << "\n";
	}
	virtual void afiZboruri(std::ostream& os) const {
		os << "zboruri:" << zboruri.size() << "\n";
		for (std::vector<Zbor>::const_iterator i = zboruri.begin(); i != zboruri.end(); i++) {
			i->afisare(os);
			os << "escale:" << escale.size() << "\n";
			for (std::vector<std::string>::const_iterator i = escale.begin(); i != escale.end(); i++) {
				os << *i << " ";
			} os << "\n";
		} os << "\n";
	}

public:
	DeLinie(std::string nume = "", std::string sediu = "", std::string cod = "", int infiintare = 0) : Comp(nume, sediu, cod, infiintare) {}

	DeLinie(const DeLinie& comp) : Comp(comp) {}
	virtual ~DeLinie() { escale.clear(); }

	DeLinie& operator=(const DeLinie& comp) {
		if (this != &comp) {
			Comp::operator=(comp);
			escale.clear();
			escale.insert(escale.end(), comp.escale.begin(), comp.escale.end());
		}
		return *this;
	}

	std::vector<std::string> escaleGet() { return escale; }

	virtual void citire(std::istream& is) {
		Comp::cit(is);
		cit(is);
	}
	virtual void afisare(std::ostream& os) const {
		Comp::afi(os);
		afi(os);
		afiZboruri(os);
	}
};

//----------------------------------------Charter
class Charter : virtual public Comp {
protected:
	std::string operatorr;
	double difPret;

	virtual void cit(std::istream& is) {
		std::cout << "operatorr: "; is >> operatorr;
		std::cout << "difPret: "; is >> difPret;
	}
	virtual void afi(std::ostream& os) const {
		os << "operatorr:" << operatorr << "\n";
		os << "difPret:" << difPret << "\n";
	}

public:
	Charter(std::string nume = "", std::string sediu = "", std::string cod = "", int infiintare = 0, std::string operatorr = "", double difPret = 0) : Comp(nume, sediu, cod, infiintare) {
		this->operatorr = operatorr;
		this->difPret = difPret;
	}

	Charter(const Charter& comp) : Comp(comp) {
		this->operatorr = comp.operatorr;
		this->difPret = comp.difPret;
	}
	virtual ~Charter() {}

	Charter& operator=(const Charter& comp) {
		if (this != &comp) {
			Comp::operator=(comp);
			this->operatorr = comp.operatorr;
			this->difPret = comp.difPret;
		}
		return *this;
	}

	std::string operatorrGet() { return operatorr; }
	double difPretGet() { return difPret; }

	virtual void citire(std::istream& is) {
		Comp::cit(is);
		cit(is);
	}
	virtual void afisare(std::ostream& os) const {
		Comp::afi(os);
		afi(os);
		afiZboruri(os);
	}
};

//----------------------------------------LowCostCharter
class LowCostCharter : public LowCost, public Charter {
protected:

	virtual void cit(std::istream& is) {}
	virtual void afi(std::ostream& os) const {}

public:
	LowCostCharter(std::string nume = "", std::string sediu = "", std::string cod = "", int infiintare = 0, double pretBagaj = 0, double maxBagaj = 0, std::string operatorr = "", double difPret = 0) : LowCost(nume, sediu, cod, infiintare, pretBagaj, maxBagaj), Charter(nume, sediu, cod, infiintare, operatorr, difPret) {}

	LowCostCharter(const LowCostCharter& comp) : LowCost(comp), Charter(comp) {}

	virtual ~LowCostCharter() {}

	LowCostCharter& operator=(const LowCostCharter& comp) {
		if (this != &comp) {
			LowCost::operator=(comp);
			Charter::operator=(comp);
		}
		return *this;
	}


	virtual void citire(std::istream& is) {
		Comp::cit(is);
		LowCost::cit(is);
		Charter::cit(is);
		cit(is);
	}
	virtual void afisare(std::ostream& os) const {
		Comp::afi(os);
		LowCost::afi(os);
		Charter::afi(os);
		afi(os);
		afiZboruri(os);
	}
};

//----------------------------------------DeLinieCharter
class DeLinieCharter : public DeLinie, public Charter {
protected:

	virtual void cit(std::istream& is) {}
	virtual void afi(std::ostream& os) const {}

public:
	DeLinieCharter(std::string nume = "", std::string sediu = "", std::string cod = "", int infiintare = 0, std::string operatorr = "", double difPret = 0) : DeLinie(nume, sediu, cod, infiintare), Charter(nume, sediu, cod, infiintare, operatorr, difPret) {}

	DeLinieCharter(const DeLinieCharter& comp) : DeLinie(comp), Charter(comp) {}

	virtual ~DeLinieCharter() {}

	DeLinieCharter& operator=(const DeLinieCharter& comp) {
		if (this != &comp) {
			DeLinie::operator=(comp);
			Charter::operator=(comp);
		}
		return *this;
	}


	virtual void citire(std::istream& is) {
		Comp::cit(is);
		DeLinie::cit(is);
		Charter::cit(is);
		cit(is);
	}
	virtual void afisare(std::ostream& os) const {
		Comp::afi(os);
		DeLinie::afi(os);
		Charter::afi(os);
		afi(os);
		afiZboruri(os);
	}
};

//----------------------------------------Meniu
class Meniu {
	std::vector<Comp*> companii1;
	std::vector<LowCost*> companii2;
	std::vector<DeLinie*> companii3;
	std::vector<Charter*> companii4;
	std::vector<LowCostCharter*> companii5;
	std::vector<DeLinieCharter*> companii6;
	static Meniu* instanta;
	Meniu() {}
public:
	~Meniu() { companii1.clear(); companii2.clear(); companii3.clear(); companii4.clear(); companii5.clear(); companii6.clear(); }
	static Meniu* instantaGet() { if (instanta == nullptr) instanta = new Meniu; return instanta; }

	void ruleaza() {
		std::string optiune;
		while (true) {
			{
				std::cout << "optiuni:" << "\n";
				std::cout << "1. creeaza comp" << "\n";
				std::cout << "2. afiseaza zboruri de pe 1 oct 2019 pe categorii" << "\n";
				std::cout << "3. cauta companii dupa destinatie" << "\n";
				std::cout << "4. pret minim pentru destinatie" << "\n";
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
				try {
					std::string tip;
				alege:
					std::cout << "tip: "; std::cin >> tip;
					if (tip == "Comp") {
						Comp* comp = new Comp;
						comp->citire(std::cin);
						companii1.push_back(comp);
					}
					else if (tip == "LowCost") {
						LowCost* comp = new LowCost;
						comp->citire(std::cin);
						companii2.push_back(comp);
					}
					else if (tip == "DeLinie") {
						DeLinie* comp = new DeLinie;
						comp->citire(std::cin);
						companii3.push_back(comp);
					}
					else if (tip == "Charter") {
						Charter* comp = new Charter;
						comp->citire(std::cin);
						companii4.push_back(comp);
					}
					else if (tip == "LowCostCharter") {
						LowCostCharter* comp = new LowCostCharter;
						comp->citire(std::cin);
						companii5.push_back(comp);
					}
					else if (tip == "DeLinieCharter") {
						DeLinieCharter* comp = new DeLinieCharter;
						comp->citire(std::cin);
						companii6.push_back(comp);
					}
					else {
						std::cout << "optiune invalida, variantele sunt: Comp, LowCost, DeLinie, Charter, LowCostCharter, DeLinieCharter" << "\n";
						goto alege;
					}
				}
				catch (const std::bad_alloc&) {
					std::cerr << "Memorie insuficienta\n";
					exit(1);
				}
			}
			else if (optiune == "2") {
				std::cout << "companii:" << "\n";
				for (std::vector<Comp*>::iterator it = companii1.begin(); it != companii1.end(); it++) {
					std::vector<Zbor> zboruri = (*it)->zboruriGet();
					for (std::vector<Zbor>::iterator i = zboruri.begin(); i != zboruri.end(); i++) {
						if (i->ziuaGet() == 1 and i->lunaGet() == 10 and i->anulGet() == 2019) {
							i->afisare(std::cout);  std::cout << "\n";
						}
					}
				}
				std::cout << "companii LowCost:" << "\n";
				for (std::vector<LowCost*>::iterator it = companii2.begin(); it != companii2.end(); it++) {
					std::vector<Zbor> zboruri = (*it)->zboruriGet();
					for (std::vector<Zbor>::iterator i = zboruri.begin(); i != zboruri.end(); i++) {
						if (i->ziuaGet() == 1 and i->lunaGet() == 10 and i->anulGet() == 2019) {
							i->afisare(std::cout);  std::cout << "\n";
						}
					}
				}
				std::cout << "companii DeLinie:" << "\n";
				for (std::vector<DeLinie*>::iterator it = companii3.begin(); it != companii3.end(); it++) {
					std::vector<Zbor> zboruri = (*it)->zboruriGet();
					for (std::vector<Zbor>::iterator i = zboruri.begin(); i != zboruri.end(); i++) {
						if (i->ziuaGet() == 1 and i->lunaGet() == 10 and i->anulGet() == 2019) {
							i->afisare(std::cout);  std::cout << "\n";
						}
					}
				}
				std::cout << "companii Charter:" << "\n";
				for (std::vector<Charter*>::iterator it = companii4.begin(); it != companii4.end(); it++) {
					std::vector<Zbor> zboruri = (*it)->zboruriGet();
					for (std::vector<Zbor>::iterator i = zboruri.begin(); i != zboruri.end(); i++) {
						if (i->ziuaGet() == 1 and i->lunaGet() == 10 and i->anulGet() == 2019) {
							i->afisare(std::cout);  std::cout << "\n";
						}
					}
				}
				std::cout << "companii LowCostCharter:" << "\n";
				for (std::vector<LowCostCharter*>::iterator it = companii5.begin(); it != companii5.end(); it++) {
					std::vector<Zbor> zboruri = (*it)->zboruriGet();
					for (std::vector<Zbor>::iterator i = zboruri.begin(); i != zboruri.end(); i++) {
						if (i->ziuaGet() == 1 and i->lunaGet() == 10 and i->anulGet() == 2019) {
							i->afisare(std::cout);  std::cout << "\n";
						}
					}
				}
				std::cout << "companii DeLinieCharter:" << "\n";
				for (std::vector<DeLinieCharter*>::iterator it = companii6.begin(); it != companii6.end(); it++) {
					std::vector<Zbor> zboruri = (*it)->zboruriGet();
					for (std::vector<Zbor>::iterator i = zboruri.begin(); i != zboruri.end(); i++) {
						if (i->ziuaGet() == 1 and i->lunaGet() == 10 and i->anulGet() == 2019) {
							i->afisare(std::cout);  std::cout << "\n";
						}
					}
				}
			}
			else if (optiune == "3") {
				std::string destinatie;
				std::cout << "companii care zboara catre:"; std::cin >> destinatie;
				for (std::vector<Comp*>::iterator it = companii1.begin(); it != companii1.end(); it++) {
					std::vector<Zbor> zboruri = (*it)->zboruriGet();
					std::vector<Zbor>::iterator i;
					for (i = zboruri.begin(); i != zboruri.end(); i++) {
						if (i->destinatieGet() == destinatie) {
							(*it)->afisare(std::cout);  std::cout << "\n";
							break;
						}
					}
				}
				for (std::vector<LowCost*>::iterator it = companii2.begin(); it != companii2.end(); it++) {
					std::vector<Zbor> zboruri = (*it)->zboruriGet();
					std::vector<Zbor>::iterator i;
					for (i = zboruri.begin(); i != zboruri.end(); i++) {
						if (i->destinatieGet() == destinatie) {
							(*it)->afisare(std::cout);  std::cout << "\n";
							break;
						}
					}
				}
				for (std::vector<DeLinie*>::iterator it = companii3.begin(); it != companii3.end(); it++) {
					std::vector<Zbor> zboruri = (*it)->zboruriGet();
					std::vector<Zbor>::iterator i;
					for (i = zboruri.begin(); i != zboruri.end(); i++) {
						if (i->destinatieGet() == destinatie) {
							(*it)->afisare(std::cout);  std::cout << "\n";
							break;
						}
					}
					if (i != zboruri.end()) {
						std::vector<std::string> escale = (*it)->escaleGet();
						for (std::vector<std::string>::iterator i = escale.begin(); i != escale.end(); i++) {
							if (*i == destinatie) {
								(*it)->afisare(std::cout);  std::cout << "\n";
								break;
							}
						}
					}
				}
				for (std::vector<Charter*>::iterator it = companii4.begin(); it != companii4.end(); it++) {
					std::vector<Zbor> zboruri = (*it)->zboruriGet();
					std::vector<Zbor>::iterator i;
					for (i = zboruri.begin(); i != zboruri.end(); i++) {
						if (i->destinatieGet() == destinatie) {
							(*it)->afisare(std::cout);  std::cout << "\n";
							break;
						}
					}
				}
				for (std::vector<LowCostCharter*>::iterator it = companii5.begin(); it != companii5.end(); it++) {
					std::vector<Zbor> zboruri = (*it)->zboruriGet();
					std::vector<Zbor>::iterator i;
					for (i = zboruri.begin(); i != zboruri.end(); i++) {
						if (i->destinatieGet() == destinatie) {
							(*it)->afisare(std::cout);  std::cout << "\n";
							break;
						}
					}
				}
				for (std::vector<DeLinieCharter*>::iterator it = companii6.begin(); it != companii6.end(); it++) {
					std::vector<Zbor> zboruri = (*it)->zboruriGet();
					std::vector<Zbor>::iterator i;
					for (i = zboruri.begin(); i != zboruri.end(); i++) {
						if (i->destinatieGet() == destinatie) {
							(*it)->afisare(std::cout);  std::cout << "\n";
							break;
						}
					}
					if (i != zboruri.end()) {
						std::vector<std::string> escale = (*it)->escaleGet();
						for (std::vector<std::string>::iterator i = escale.begin(); i != escale.end(); i++) {
							if (*i == destinatie) {
								(*it)->afisare(std::cout);  std::cout << "\n";
								break;
							}
						}
					}
				}
			}
			else if (optiune == "4") {
				std::string destinatie;
				std::cout << "pret minim catre:"; std::cin >> destinatie;
				double pretMinim = 10000;
				for (std::vector<Comp*>::iterator it = companii1.begin(); it != companii1.end(); it++) {
					std::vector<Zbor> zboruri = (*it)->zboruriGet();
					std::vector<Zbor>::iterator i;
					for (i = zboruri.begin(); i != zboruri.end(); i++) {
						if (i->destinatieGet() == destinatie) {
							if (i->pretGet() < pretMinim) {
								pretMinim = i->pretGet();
							}
						}
					}
				}
				for (std::vector<LowCost*>::iterator it = companii2.begin(); it != companii2.end(); it++) {
					std::vector<Zbor> zboruri = (*it)->zboruriGet();
					std::vector<Zbor>::iterator i;
					for (i = zboruri.begin(); i != zboruri.end(); i++) {
						if (i->destinatieGet() == destinatie) {
							if (i->pretGet() < pretMinim) {
								pretMinim = i->pretGet();
							}
						}
					}
				}
				for (std::vector<DeLinie*>::iterator it = companii3.begin(); it != companii3.end(); it++) {
					std::vector<Zbor> zboruri = (*it)->zboruriGet();
					std::vector<Zbor>::iterator i;
					for (i = zboruri.begin(); i != zboruri.end(); i++) {
						if (i->destinatieGet() == destinatie) {
							if (i->pretGet() < pretMinim) {
								pretMinim = i->pretGet();
							}
						}
					}
				}
				for (std::vector<Charter*>::iterator it = companii4.begin(); it != companii4.end(); it++) {
					std::vector<Zbor> zboruri = (*it)->zboruriGet();
					std::vector<Zbor>::iterator i;
					for (i = zboruri.begin(); i != zboruri.end(); i++) {
						if (i->destinatieGet() == destinatie) {
							if (i->pretGet() < pretMinim) {
								pretMinim = i->pretGet();
							}
						}
					}
				}
				for (std::vector<LowCostCharter*>::iterator it = companii5.begin(); it != companii5.end(); it++) {
					std::vector<Zbor> zboruri = (*it)->zboruriGet();
					std::vector<Zbor>::iterator i;
					for (i = zboruri.begin(); i != zboruri.end(); i++) {
						if (i->destinatieGet() == destinatie) {
							if (i->pretGet() < pretMinim) {
								pretMinim = i->pretGet();
							}
						}
					}
				}
				for (std::vector<DeLinieCharter*>::iterator it = companii6.begin(); it != companii6.end(); it++) {
					std::vector<Zbor> zboruri = (*it)->zboruriGet();
					std::vector<Zbor>::iterator i;
					for (i = zboruri.begin(); i != zboruri.end(); i++) {
						if (i->destinatieGet() == destinatie) {
							if (i->pretGet() < pretMinim) {
								pretMinim = i->pretGet();
							}
						}
					}
				}
				std::cout << "pentru destinatia aleasa se poate ajunge cu minim " << pretMinim << "\n";

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
