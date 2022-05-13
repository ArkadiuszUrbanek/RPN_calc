/** @file*/

#ifndef OPERATORS_HPP
#define OPERATORS_HPP

#include <string>
#include "operations.hpp"

/** Klasa przechowuj�ca i zwracaj�ca wszystkie niezb�dne informacje o zdefiniowanych operatorach w programie*/

class operatory {
private:

	/** Struktura przechowuj�ca informacj� o operatorze*/
	struct charakterystyka_operatora {
		std::string symbol_operatora;	//< �a�cuch przechowuj�cy symbol operatora
		short priorytet_operatora;		//< Liczba ca�kowita okre�laj�ca priorytet operatora
		dzialanie& dzialanie;			//< Referencja do klasy bazowej dzia�anie po kt�rej dziedzicz� odpowiednie operacje
	};

	const static charakterystyka_operatora m_tablica_operatorow[];	//< Statyczna, sta�a tablica struktur przechowuj�cych informacje o operatorach
	const static size_t m_dlugosc;									//< D�ugo�� statycznej, sta�ej tablicy struktur

public:
	/** Metoda niemodyfikuj�ca klasy operatory
	* Zwraca d�ugo�� tablicy operator�w.
	* @return Liczba ca�kowita bez znaku
	*/
	size_t pobierz_ilosc_operatrow() const;

	/** Metoda niemodyfikuj�ca klasy operatory
	* Zwraca symbol operatora z tablicy operator�w na podstawie podanego indeksu.
	* @param[in] indeks Pozycja do odczytu z tablicy operator�w
	* @return �a�cuch przechowuj�cy symbol operatora
	*/
	std::string pobierz_operator(size_t indeks) const;

	/** Metoda niemodyfikuj�ca klasy operatory
	* Zwraca priorytet operatora z tablicy operator�w na podstawie jego symbolu.
	* @param[in] lancuch �a�cuch przechowuj�cy symbol operatora
	* @return Liczba ca�kowita
	*/
	short zwroc_priorytet_operatora(const std::string& lancuch) const;

	/** Metoda niemodyfikuj�ca klasy operatory
	* Zwraca liczb� argument�w jak� dany operator potrzebuje do wykonania operacji.
	* @param[in] lancuch �a�cuch przechowuj�cy symbol operatora
	* @return Liczba ca�kowita bez znaku
	*/
	unsigned short zwroc_argumentowosc_operatora(const std::string& lancuch) const;

	/** Metoda niemodyfikuj�ca klasy operatory
	* Zwraca wynik dzia�ania wykonanego na podstawie podanych argument�w i symbolu operatora.
	* @param[in] symbol_operatora �a�cuch przechowuj�cy symbol operatora
	* @param[in] argumenty_operacji �a�cuch przechowuj�cy argumenty potrzebne do wykonania operacji
	* @return Liczba ca�kowita
	*/
	long wykonaj_operacje(const std::string& symbol_operatora, const std::string argumenty_operacji) const;

};

#endif
