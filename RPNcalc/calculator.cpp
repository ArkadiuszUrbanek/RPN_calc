#include <sstream>
#include <string>
#include <iostream>

#include "logs.hpp"
#include "stack.hpp"
#include "operators.hpp"
#include "calculator.hpp"

kalkulator::kalkulator(const std::string& lancuch) : m_lancuch(lancuch) {}

long kalkulator::oblicz_wartosc_wyrazenia() const {
	std::istringstream strumien_wyrazenia(m_lancuch);
	operatory operatory;
	logi logi;
	stos stos;

	std::string slowo = "";

	while (strumien_wyrazenia >> slowo) {
		std::istringstream strumien_slowa(slowo);
		long liczba_calkowita = 0;

		if (strumien_slowa >> liczba_calkowita) {
			stos.poloz_element(liczba_calkowita);
			logi.zapisz_do_pliku(liczba_calkowita, stos);

		} else {			
			strumien_slowa.clear();
			strumien_slowa.seekg(0, std::ios_base::beg);

			std::string symbol_operacji = "", lancuch_argumentow = "";
			long operand = 0, wynik_operacji = 0;
			unsigned short argumentowosc_operacji = 0;

			strumien_slowa >> symbol_operacji;
			logi.zapisz_do_pliku(symbol_operacji, stos);

			argumentowosc_operacji = operatory.zwroc_argumentowosc_operatora(symbol_operacji);
			for (unsigned short licznik = 0; licznik < argumentowosc_operacji; licznik++) {
				stos.zdejmij_element(operand);
				lancuch_argumentow += std::to_string(operand);
				if(licznik + 1 != argumentowosc_operacji) lancuch_argumentow += ' ';

			}

			wynik_operacji = operatory.wykonaj_operacje(symbol_operacji, lancuch_argumentow);
			stos.poloz_element(wynik_operacji);
			logi.zapisz_do_pliku(wynik_operacji, stos);
		}
	}

	long wynik_ostateczny = 0;
	stos.zdejmij_element(wynik_ostateczny);
	

	return wynik_ostateczny;
}