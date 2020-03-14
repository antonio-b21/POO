#pragma once
#include <iostream>
#include <algorithm>
using namespace std;
class Fractie {
	int numarator, numitor;
public:
	Fractie();
	Fractie(int numa, int numi);
	Fractie(const Fractie& fract);
	~Fractie();
	void SeteazaNumarator(int numa);
	void SeteazaNumitor(int numi);
	int FurnizeazaNumarator();
	int FurnizeazaNumitor();
	void Simplificare();
	friend ostream& operator << (ostream& os, const Fractie& fract);
	friend istream& operator >> (istream& os, Fractie& fract);
	Fractie operator + (const Fractie& frac);
	Fractie operator - (const Fractie& frac);
	Fractie operator * (const Fractie& frac);
	Fractie operator / (const Fractie& frac);
	bool operator != (int num);
	bool operator == (int num);
	friend Fractie operator * (const Fractie& frac, int scl);
	friend Fractie operator * (int scl, const Fractie& frac);
	friend Fractie* CitMemAfis(int nr);
};
Fractie* CitMemAfis(int nr);
