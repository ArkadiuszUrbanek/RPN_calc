/** @file*/

#ifndef LOGS_HPP
#define LOGS_HPP

#include <string>
#include <fstream>
#include "stack.hpp"

/** Klasa obs�uguj�ca zapis log�w do pliku tekstowego*/

class logi {
private:
	static const std::string m_nazwa_pliku;	///< Statyczny, sta�y �a�cuch przechowuj�cy nazw� pliku, do kt�rego b�d� zapisywane logi
	std::ofstream m_strumien_pliku;			///< Wyj�ciowy strumie� plikowy

public:

	/** Konstruktor domy�lny klasy @ref logi 
	* @brief Otwiera strumie� plikowy.
	*/
	logi();

	/** Metoda klasy @ref logi
	* Zapisuje do pliku liczb� ca�kowit� pobran� z �a�cucha wej�ciowego i aktualn� zawarto�� stosu.
	* @note Ta metoda jest przeci��ona.
	* @param[in] liczba_calkowita Liczba ca�kowita odczytana z �a�cucha wej�ciowego
	* @param[in] stos Sta�a referencja do obiektu klasy @ref stos
	*/
	void zapisz_do_pliku(long liczba_calkowita, const stos& stos);

	/** Metoda klasy @ref logi
	* Zapisuje do pliku symbol operatora pobrany z �a�cucha wej�ciowego i aktualn� zawarto�� stosu.
	* @note Ta metoda jest przeci��ona.
	* @param[in] symbol_operatora Symbol operatora odczytany z �a�cucha wej�ciowego
	* @param[in] stos Sta�a referencja do obiektu klasy @ref stos
	*/
	void zapisz_do_pliku(std::string symbol_operatora, const stos& stos);

	/** Destruktor klasy @ref logi
	* Zamyka strumie� plikowy.
	*/
	~logi() { m_strumien_pliku.close(); }

};

#endif

