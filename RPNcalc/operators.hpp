/** @file*/

#ifndef OPERATORS_HPP
#define OPERATORS_HPP

#include <string>
#include "operations.hpp"

/** Klasa przechowująca i zwracająca wszystkie niezbędne informacje o zdefiniowanych operatorach w programie*/

class operatory {
private:

	/** Struktura przechowująca informację o operatorze*/
	struct charakterystyka_operatora {
		std::string symbol_operatora;	//< Łańcuch przechowujący symbol operatora
		short priorytet_operatora;		//< Liczba całkowita określająca priorytet operatora
		dzialanie& dzialanie;			//< Referencja do klasy bazowej działanie po której dziedziczą odpowiednie operacje
	};

	const static charakterystyka_operatora m_tablica_operatorow[];	//< Statyczna, stała tablica struktur przechowujących informacje o operatorach
	const static size_t m_dlugosc;									//< Długość statycznej, stałej tablicy struktur

public:
	/** Metoda niemodyfikująca klasy operatory
	* Zwraca długość tablicy operatorów.
	* @return Liczba całkowita bez znaku
	*/
	size_t pobierz_ilosc_operatrow() const;

	/** Metoda niemodyfikująca klasy operatory
	* Zwraca symbol operatora z tablicy operatorów na podstawie podanego indeksu.
	* @param[in] indeks Pozycja do odczytu z tablicy operatorów
	* @return Łańcuch przechowujący symbol operatora
	*/
	std::string pobierz_operator(size_t indeks) const;

	/** Metoda niemodyfikująca klasy operatory
	* Zwraca priorytet operatora z tablicy operatorów na podstawie jego symbolu.
	* @param[in] lancuch Łańcuch przechowujący symbol operatora
	* @return Liczba całkowita
	*/
	short zwroc_priorytet_operatora(const std::string& lancuch) const;

	/** Metoda niemodyfikująca klasy operatory
	* Zwraca liczbę argumentów jaką dany operator potrzebuje do wykonania operacji.
	* @param[in] lancuch Łańcuch przechowujący symbol operatora
	* @return Liczba całkowita bez znaku
	*/
	unsigned short zwroc_argumentowosc_operatora(const std::string& lancuch) const;

	/** Metoda niemodyfikująca klasy operatory
	* Zwraca wynik działania wykonanego na podstawie podanych argumentów i symbolu operatora.
	* @param[in] symbol_operatora Łańcuch przechowujący symbol operatora
	* @param[in] argumenty_operacji Łańcuch przechowujący argumenty potrzebne do wykonania operacji
	* @return Liczba całkowita
	*/
	long wykonaj_operacje(const std::string& symbol_operatora, const std::string argumenty_operacji) const;

};

#endif
