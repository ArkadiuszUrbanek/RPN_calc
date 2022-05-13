#include <cctype>
#include <sstream>

#include "validate.hpp"
#include "operators.hpp"

walidacja::walidacja(const std::string& lancuch) : m_lancuch(lancuch) {}

bool walidacja::czy_liczba_calkowita(const std::string& lancuch) const {
	size_t dlugosc = lancuch.size();
	for (size_t indeks = 0; indeks < dlugosc; indeks++) {
		if (!std::isdigit(lancuch[indeks])) return false;
	}

	return true;
}

bool walidacja::czy_operator(const std::string& lancuch) const{
	operatory operatory;
	size_t dlugosc = operatory.pobierz_ilosc_operatrow();
	for (size_t indeks = 0; indeks < dlugosc; indeks++) {
		if (lancuch == operatory.pobierz_operator(indeks)) return true;
	}

	return false;
}

bool walidacja::czy_poprawne_wyrazenie() const {
	std::istringstream strumien(m_lancuch);
	std::string pojedyncze_slowo = "";

	short priorytet_operatora_aktualny = -1, priorytet_operatora_nowy = 0;
	int ilosc_liczb_na_stosie = 0;
	operatory informacja_o_operatorach;

	while (strumien >> pojedyncze_slowo) {
		if (czy_liczba_calkowita(pojedyncze_slowo)) {
			
			ilosc_liczb_na_stosie++;
			priorytet_operatora_aktualny = -1;

		} else if (czy_operator(pojedyncze_slowo)) {
			

			ilosc_liczb_na_stosie -= informacja_o_operatorach.zwroc_argumentowosc_operatora(pojedyncze_slowo);
			if (ilosc_liczb_na_stosie < 0) return false;
			else ilosc_liczb_na_stosie++;

			if (priorytet_operatora_aktualny == -1) {
				priorytet_operatora_aktualny = informacja_o_operatorach.zwroc_priorytet_operatora(pojedyncze_slowo);

			} else {
				priorytet_operatora_nowy = informacja_o_operatorach.zwroc_priorytet_operatora(pojedyncze_slowo);

				if (priorytet_operatora_aktualny == priorytet_operatora_nowy) return false;
					else priorytet_operatora_aktualny = priorytet_operatora_nowy;
			}


		} else {
			return false;

		}
	}

	if (ilosc_liczb_na_stosie == 1) return true;
		else return false;
}
