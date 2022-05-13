#include <iostream>
#include <cstring>
#include <string>


#include "input.hpp"
#include "input_file.hpp"

extern char** gargv;
extern int gargc;

const std::string wejscie::zwroc_wejscie() {
	std::string wejscie = "";

	if (gargc == 1) {
		std::cout << "Podaj wyrazenie do obliczenia: ";
		getline(std::cin, wejscie, '\n');

	} else if (gargc == 3) {
		if (strcmp("-cr", gargv[1]) == 0) {
			wejscie = gargv[2];

		} else if (strcmp("-fr", gargv[1]) == 0) {
			plik_wejsciowy odczyt(gargv[2]);
			wejscie = odczyt.odczytaj_z_pliku();

		}
	}
	
	return wejscie;
}