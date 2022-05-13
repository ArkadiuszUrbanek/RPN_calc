/** @file*/

#ifndef OPERATORS_HPP
#define OPERATORS_HPP

#include <string>
#include "operations.hpp"

/** Klasa przechowuj¹ca i zwracaj¹ca wszystkie niezbêdne informacje o zdefiniowanych operatorach w programie*/

class operatory {
private:

	/** Struktura przechowuj¹ca informacjê o operatorze*/
	struct charakterystyka_operatora {
		std::string symbol_operatora;	//< £añcuch przechowuj¹cy symbol operatora
		short priorytet_operatora;		//< Liczba ca³kowita okreœlaj¹ca priorytet operatora
		dzialanie& dzialanie;			//< Referencja do klasy bazowej dzia³anie po której dziedzicz¹ odpowiednie operacje
	};

	const static charakterystyka_operatora m_tablica_operatorow[];	//< Statyczna, sta³a tablica struktur przechowuj¹cych informacje o operatorach
	const static size_t m_dlugosc;									//< D³ugoœæ statycznej, sta³ej tablicy struktur

public:
	/** Metoda niemodyfikuj¹ca klasy operatory
	* Zwraca d³ugoœæ tablicy operatorów.
	* @return Liczba ca³kowita bez znaku
	*/
	size_t pobierz_ilosc_operatrow() const;

	/** Metoda niemodyfikuj¹ca klasy operatory
	* Zwraca symbol operatora z tablicy operatorów na podstawie podanego indeksu.
	* @param[in] indeks Pozycja do odczytu z tablicy operatorów
	* @return £añcuch przechowuj¹cy symbol operatora
	*/
	std::string pobierz_operator(size_t indeks) const;

	/** Metoda niemodyfikuj¹ca klasy operatory
	* Zwraca priorytet operatora z tablicy operatorów na podstawie jego symbolu.
	* @param[in] lancuch £añcuch przechowuj¹cy symbol operatora
	* @return Liczba ca³kowita
	*/
	short zwroc_priorytet_operatora(const std::string& lancuch) const;

	/** Metoda niemodyfikuj¹ca klasy operatory
	* Zwraca liczbê argumentów jak¹ dany operator potrzebuje do wykonania operacji.
	* @param[in] lancuch £añcuch przechowuj¹cy symbol operatora
	* @return Liczba ca³kowita bez znaku
	*/
	unsigned short zwroc_argumentowosc_operatora(const std::string& lancuch) const;

	/** Metoda niemodyfikuj¹ca klasy operatory
	* Zwraca wynik dzia³ania wykonanego na podstawie podanych argumentów i symbolu operatora.
	* @param[in] symbol_operatora £añcuch przechowuj¹cy symbol operatora
	* @param[in] argumenty_operacji £añcuch przechowuj¹cy argumenty potrzebne do wykonania operacji
	* @return Liczba ca³kowita
	*/
	long wykonaj_operacje(const std::string& symbol_operatora, const std::string argumenty_operacji) const;

};

#endif
