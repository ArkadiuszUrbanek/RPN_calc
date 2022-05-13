#include <iostream>
#include <string>

#include "operators.hpp"
#include "operations.hpp"

static dodawanie operacja_dodawania;
static odejmowanie operacja_odejmowania;
static mnozenie operacja_mnozenia;
static dzielenie_calkowite operacja_dzielenia_calkowitego;
static dzielenie_modulo operacja_dzielenia_modulo;
static potegowanie operacja_potegowania;

const operatory::charakterystyka_operatora operatory::m_tablica_operatorow[] = { {"+", 0, operacja_dodawania}, {"-", 0, operacja_odejmowania}, {"*", 1, operacja_mnozenia}, {"/", 1, operacja_dzielenia_calkowitego}, {"%", 1, operacja_dzielenia_modulo}, {"^", 2, operacja_potegowania} };

const size_t operatory::m_dlugosc = sizeof(m_tablica_operatorow) / sizeof(m_tablica_operatorow[0]);

size_t operatory::pobierz_ilosc_operatrow() const {
	return m_dlugosc;
}

std::string operatory::pobierz_operator(size_t indeks) const {
	try {
		if (indeks >= m_dlugosc) throw "Proba odczytu operatora spoza tablicy.";	
		return m_tablica_operatorow[indeks].symbol_operatora;

	} catch (const char *komunikat) {
		std::cerr << komunikat;
		exit(EXIT_FAILURE);
	}
}

short operatory::zwroc_priorytet_operatora(const std::string& lancuch) const {
	try {
		for (size_t indeks = 0; indeks < m_dlugosc; indeks++) {
			if (lancuch == m_tablica_operatorow[indeks].symbol_operatora) return m_tablica_operatorow[indeks].priorytet_operatora;
		}

		throw "Probowano znalezc priorytet nieistniejacego operatora.";
	} catch (const char* komunikat) {
		std::cerr << komunikat;
		exit(EXIT_FAILURE);
	}
}

unsigned short operatory::zwroc_argumentowosc_operatora(const std::string& lancuch) const {
	try {
		for (size_t indeks = 0; indeks < m_dlugosc; indeks++) {
			if (lancuch == m_tablica_operatorow[indeks].symbol_operatora) return m_tablica_operatorow[indeks].dzialanie.zwroc_argumentowosc_operacji();
		}

		throw "Probowano znalezc argumentowosc nieistniejacego operatora.";
	}
	catch (const char* komunikat) {
		std::cerr << komunikat;
		exit(EXIT_FAILURE);
	}

}

long operatory::wykonaj_operacje(const std::string& symbol_operatora, const std::string argumenty_operacji) const {
	try {
		for (size_t indeks = 0; indeks < m_dlugosc; indeks++) {
			if (symbol_operatora == m_tablica_operatorow[indeks].symbol_operatora) {
				m_tablica_operatorow[indeks].dzialanie.wprowadz_lancuch_argumentow(argumenty_operacji);
				return m_tablica_operatorow[indeks].dzialanie.oblicz();
			}
		}

		throw "Probowano wykonac niezdefiniowana operacje.";
	} catch (const char* komunikat) {
		std::cerr << komunikat;
		exit(EXIT_FAILURE);
	}
}
