/** @file*/

#ifndef VALIDATE_HPP
#define VALIDATE_HPP

#include <string>

/** Klasa sprawdzaj�ca poprawno�� wyra�enia wej�ciowego*/

class walidacja {
private:
	const std::string& m_lancuch; ///< Sta�a referencja do �a�cucha przechowuj�cego wyra�enie wej�ciowe 

	/** Metoda niemodyfikuj�ca klasy walidacja
	* Sprawdza czy przekazany do niej �ancuch jest liczb� ca�kowit�.
	* @param[in] lancuch �a�cuch do sprawdzenia
	* @return true - oznacza, �e �a�cuch przechowuje liczb� ca�kowit� lub false - oznacza, �e przekazany �a�cuch nie reprezentuje liczby ca�kowitej
	*/
	bool czy_liczba_calkowita(const std::string& lancuch) const;

	/** Metoda niemodyfikuj�ca klasy walidacja
	* Sprawdza czy przekazany do niej �ancuch jest operatorem zdefiniowanym w programie.
	* @param[in] lancuch �a�cuch do sprawdzenia
	* @return true - oznacza, �e �a�cuch jest symbolem operatora lub false - oznacza, �e przekazany �a�cuch nie jest symbolem �adnego zdefiniowanego operatora
	*/
	bool czy_operator(const std::string& lancuch) const;

public:
	/** Konstruktor jednoargumentowy klasy walidacja
	* @param[in] lancuch Sta�a referencja do �a�cucha przechowuj�cego wyra�enie wej�ciowe
	*/
	walidacja(const std::string& lancuch);

	/** Metoda niemodyfikuj�ca klasy walidacja
	* Sprawdza czy przekazany do niej �ancuch jest wyra�eniem zapisanym w ONP.
	* @return true - oznacza, �e �a�cuch jest wyra�eniem ONP lub false - oznacza, �e przekazany �a�cuch nie jest wyra�eniem ONP
	*/
	bool czy_poprawne_wyrazenie() const;

};

#endif
