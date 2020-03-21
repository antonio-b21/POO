#pragma once
#include <iostream>
#include <algorithm>
using namespace std;
class Fractie {
	int numarator, numitor;
public:
	Fractie();
	Fractie(int, int);
	Fractie(const Fractie&);
	~Fractie();
	void SeteazaNumarator(int);
	void SeteazaNumitor(int);
	int FurnizeazaNumarator() const;
	int FurnizeazaNumitor() const;
	void Simplificare();
	friend ostream& operator<< (ostream&, const Fractie&);
	friend istream& operator>> (istream&, Fractie&);
	Fractie operator+ (const Fractie&) const;
	Fractie operator- (const Fractie&) const;
	Fractie operator* (const Fractie&) const;
	Fractie operator/ (const Fractie&) const;
	friend Fractie operator* (const Fractie&, int);
	friend Fractie operator* (int, const Fractie&);
	bool operator!= (int) const;
	bool operator== (int) const;
	friend Fractie* CitMemAfis(int);
};
Fractie* CitMemAfis(int);
