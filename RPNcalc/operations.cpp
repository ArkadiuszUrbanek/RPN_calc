#include <iostream>
#include <sstream>
#include <string>
#include <cmath>

#include "operations.hpp"

dzialanie::dzialanie(unsigned short argumentowosc_operacji) : m_przekazane_argumenty(), m_argumentowosc_operacji(argumentowosc_operacji) {}

long dzialanie::argumenty::operator[](const unsigned short& indeks) const {
	std::istringstream strumien(m_lancuch_argumentow);
	int aktualny_indeks = -1;
	long argument = 0;

	while (true) {
		try {
			if (strumien >> argument) {
				aktualny_indeks++;
				if (aktualny_indeks == indeks) break;

			} else {
				throw "Nie znaleziono pasujacego argumentu do wykonania operacji.";

			}

		} catch (const char* komunikat) {
			std::cerr << komunikat;
			exit(EXIT_FAILURE);
		}
	}
	
	
	return argument;
}

dzialanie_dwuargumentowe::dzialanie_dwuargumentowe() : dzialanie(2) {}



long dodawanie::oblicz() {
	return m_przekazane_argumenty[1] + m_przekazane_argumenty[0];
}



long odejmowanie::oblicz() {
	return m_przekazane_argumenty[1] - m_przekazane_argumenty[0];
}



long mnozenie::oblicz() {
	return m_przekazane_argumenty[1] * m_przekazane_argumenty[0];
}



long dzielenie_calkowite::oblicz() {
	return m_przekazane_argumenty[1] / m_przekazane_argumenty[0];
}



long dzielenie_modulo::oblicz() {
	return m_przekazane_argumenty[1] % m_przekazane_argumenty[0];
}



long potegowanie::oblicz() {
	return (long)pow(m_przekazane_argumenty[1], m_przekazane_argumenty[0]);
}