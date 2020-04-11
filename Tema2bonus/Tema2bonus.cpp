#include <iostream>
#include "Remainder.h"
#include "Exceptie.h"

int main() {
	try {
		Remainder R1, R2, R3;
		R1.adSedinta(121, 8, 0.5, "Stabilirea temelor de casa pentru studentii de anul 3"); // adaugarea in Remainder a unei sedinte care incepe 
																	// la ora 8, ziua 121 si dureaza jumatate de ora, avand subiectul mentionat.
		R1.adApel(121, 12, "0722123321"); // adaugarea in Remainder a unei apel care trebuie realizat in ziua 121, ora 12, catre numarul mentionat.
		R1.adSedinta(121, 10, 3, "Stabilirea proiectelor finale pentru anul 4"); // adaugarea in Remainder a unei sedinte care incepe la ora 10, 
																				 // ziua 121 si dureaza 3 ore, avand subiectul mentionat.
		//R1.adSedinta(121, 9, 2, "Stabilirea proiectelor pentru anul 2"); // incerc adaugarea in Remainder a unei sedinte care incepe la ora 9,
										// ziua 121 si dureaza 2 ore, avand subiectul mentionat.Rezulta exceptie : suprapunere cu alta sedinta.
		R1.adApel(121, 12, "0744990099");	// adaugarea in Remainder a unei apel care trebuie realizat la ora 12, ziua 121 catre
											//	numarul mentionat.E ok(difera de nota adaugata deja mai sus)
		R1.afiseaza(20, 0); // afisarea notelor memorate in Remainder care sunt “active” dupa ziua 20, ora 0.
		std::cout << "\n";

		R1[2].afiseaza();	// afisare detalii despre nota memorata, cu indexul 2. (sedinta de la ora 10 ziua 121)
		std::cout << "\n";

		//R2.adApel(121, 12, "0744990099");
		R2.adApel(121, 12, "0744990099");
		R2.adApel(121, 12, "0744919099");
		R2.adSedinta(8, 12, 0.5, "Stabilirea temelor de casa pentru studentii de anul 3");
		//R2.adApel(12, 12, "072212331");
		R2.adApel(13, 12, "0722123000");
		//R2.adSedinta(121, 10, 3, "Stabilirea proiectelor pentru anul 4");
		R2.afiseaza(); // afisarea notelor memorate in Remainder care sunt active dupa ziua 1, ora 0.
		std::cout << "\n";

		R3 = R1 + R2;
		R3.afiseaza();
		std::cout << "\n";

		try {
			int ziua, ora;
			std::cin.exceptions(std::istream::failbit);
			std::cin >> ziua; std::cin >> ora;
			R3.urmeaza(ziua, ora);
		} catch (std::ios_base::failure) {
			throw new Exceptie("Nu este numar");
		}
	} catch (Exceptie* e) {
		e->afiseaza();
		delete e;
	}
}