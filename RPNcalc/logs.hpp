/** @file*/

#ifndef LOGS_HPP
#define LOGS_HPP

#include <string>
#include <fstream>
#include "stack.hpp"

/** Klasa obs³uguj¹ca zapis logów do pliku tekstowego*/

class logi {
private:
	static const std::string m_nazwa_pliku;	///< Statyczny, sta³y ³añcuch przechowuj¹cy nazwê pliku, do którego bêd¹ zapisywane logi
	std::ofstream m_strumien_pliku;			///< Wyjœciowy strumieñ plikowy

public:

	/** Konstruktor domyœlny klasy @ref logi 
	* @brief Otwiera strumieñ plikowy.
	*/
	logi();

	/** Metoda klasy @ref logi
	* Zapisuje do pliku liczbê ca³kowit¹ pobran¹ z ³añcucha wejœciowego i aktualn¹ zawartoœæ stosu.
	* @note Ta metoda jest przeci¹¿ona.
	* @param[in] liczba_calkowita Liczba ca³kowita odczytana z ³añcucha wejœciowego
	* @param[in] stos Sta³a referencja do obiektu klasy @ref stos
	*/
	void zapisz_do_pliku(long liczba_calkowita, const stos& stos);

	/** Metoda klasy @ref logi
	* Zapisuje do pliku symbol operatora pobrany z ³añcucha wejœciowego i aktualn¹ zawartoœæ stosu.
	* @note Ta metoda jest przeci¹¿ona.
	* @param[in] symbol_operatora Symbol operatora odczytany z ³añcucha wejœciowego
	* @param[in] stos Sta³a referencja do obiektu klasy @ref stos
	*/
	void zapisz_do_pliku(std::string symbol_operatora, const stos& stos);

	/** Destruktor klasy @ref logi
	* Zamyka strumieñ plikowy.
	*/
	~logi() { m_strumien_pliku.close(); }

};

#endif

