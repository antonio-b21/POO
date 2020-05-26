//----------------------------------------Tplate
template <class T> //<> pt specializare
class Tplate; //<Specializare>
template <class T> //dispare la specializare
std::ostream& operator<<(std::ostream&, const Tplate<T>&);
template <class T> //dispare la specializare
std::istream& operator>>(std::istream&, Tplate<T>&);

template <class T>
class Tplate {
	int nrObiecte;
	std::vector<T> obiecte;
	static Tplate* instanta; //pt singleton xD
	Tplate();
	Tplate(const Tplate&);
public:
	static Tplate* instantiaza();
	~Tplate();

	Tplate& operator=(const Tplate&);

	friend std::ostream& operator<<<T>(std::ostream&, const Tplate&); //<T> se muta la parametru
	friend std::istream& operator>><T>(std::istream&, Tplate&); //<T> se muta la parametru
};

template <class T> //dispare la specializare
Tplate<T>* Tplate<T>::instanta = nullptr;

template <class T> //dispare la specializare
Tplate<T>::Tplate() :nrObiecte(0) {}

template <class T> //dispare la specializare
Tplate<T>::Tplate(const Tplate& tplate) : nrObiecte(tplate.nrObiecte) {
	for (int i = 0; i < nrObiecte; i++) {
		obiecte.push_back(tplate.obiecte[i]);
	}
}

template <class T> //dispare la specializare
Tplate<T>* Tplate<T>::instantiaza() {
	if (!instanta) {
		try {
			instanta = new Tplate<T>;
		}
		catch (const std::bad_alloc&) {
			std::cerr << "Memorie insuficienta\n";
			exit(1);
		}
	}
	return instanta;
}

template <class T> //dispare la specializare
Tplate<T>::~Tplate() {
	obiecte.clear();
}

template <class T> //dispare la specializare
Tplate<T>& Tplate<T>::operator=(const Tplate& tplate) {
	if (this != &tplate) {
		obiecte.clear();
		nrObiecte = tplate.nrObiecte;
		for (int i = 0; i < nrObiecte; i++) {
			obiecte.push_back(tplate.obiecte[i]);
		}
	}
	return *this;
}

template <class T> //dispare la specializare
std::ostream& operator<<(std::ostream& os, const Tplate<T>& tplate) { //la specializare se pune numele direct
	std::cout << "Aceste " << tplate.nrObiecte << " obiecte " << std::string(typeid(T).name()).substr(6) << " sunt in tplate:\n";
	for (class std::vector<T>::const_iterator it = tplate.obiecte.begin(); it != tplate.obiecte.end(); it++) {
		os << *it << "\n";
	}
	return os;
}

template <class T> //dispare la specializare
std::istream& operator>>(std::istream& is, Tplate<T>& tplate) {
	tplate.obiecte.clear();
	tplate.nrObiecte = 0; //la specializare se pune numele direct
	std::cout << "Cate obiecte " << std::string(typeid(T).name()).substr(6) << " adaugati?\nR: ";
	is.exceptions(std::istream::failbit);
	try {
		is >> tplate.nrObiecte;
	}
	catch (const std::ios::failure&) {
		is.clear();
		is.ignore(INT_MAX, '\n');
		std::cout << "Numar invalid\n";
		return is;
	}
	for (int i = 1; i <= tplate.nrObiecte; i++) {
		std::cout << "\Obiect " << i << "\n";
		T obiect;
		std::cin >> obiect;
		tplate.obiecte.push_back(obiect);
	}
	return is;
} // nu uita ca e singleton deci Tplate<Tip>* = Tplate<Tip>::instantiaza();