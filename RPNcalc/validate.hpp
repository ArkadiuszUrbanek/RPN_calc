/** @file*/

#ifndef VALIDATE_HPP
#define VALIDATE_HPP

#include <string>

/** Klasa sprawdzaj¹ca poprawnoœæ wyra¿enia wejœciowego*/

class walidacja {
private:
	const std::string& m_lancuch; ///< Sta³a referencja do ³añcucha przechowuj¹cego wyra¿enie wejœciowe 

	/** Metoda niemodyfikuj¹ca klasy walidacja
	* Sprawdza czy przekazany do niej ³ancuch jest liczb¹ ca³kowit¹.
	* @param[in] lancuch £añcuch do sprawdzenia
	* @return true - oznacza, ¿e ³añcuch przechowuje liczbê ca³kowit¹ lub false - oznacza, ¿e przekazany ³añcuch nie reprezentuje liczby ca³kowitej
	*/
	bool czy_liczba_calkowita(const std::string& lancuch) const;

	/** Metoda niemodyfikuj¹ca klasy walidacja
	* Sprawdza czy przekazany do niej ³ancuch jest operatorem zdefiniowanym w programie.
	* @param[in] lancuch £añcuch do sprawdzenia
	* @return true - oznacza, ¿e ³añcuch jest symbolem operatora lub false - oznacza, ¿e przekazany ³añcuch nie jest symbolem ¿adnego zdefiniowanego operatora
	*/
	bool czy_operator(const std::string& lancuch) const;

public:
	/** Konstruktor jednoargumentowy klasy walidacja
	* @param[in] lancuch Sta³a referencja do ³añcucha przechowuj¹cego wyra¿enie wejœciowe
	*/
	walidacja(const std::string& lancuch);

	/** Metoda niemodyfikuj¹ca klasy walidacja
	* Sprawdza czy przekazany do niej ³ancuch jest wyra¿eniem zapisanym w ONP.
	* @return true - oznacza, ¿e ³añcuch jest wyra¿eniem ONP lub false - oznacza, ¿e przekazany ³añcuch nie jest wyra¿eniem ONP
	*/
	bool czy_poprawne_wyrazenie() const;

};

#endif
