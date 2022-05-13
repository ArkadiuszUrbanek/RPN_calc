/** @file*/

#ifndef STACK_HPP
#define STACK_HPP

#include <iostream>

/** Klasa obs�uguj�ca stos*/

class stos {
private:
	int m_dlugosc;		///< liczba element�w po�o�onych na stos
	int m_rozmiar;		///< rzeczywista d�ugo�� stosu
	long* m_wsk_spod;	///< wska�nik na sp�d stosu

public:
	/** Konstruktor domy�lny klasy stos
	* @param[in] rozmiar Opcjonalny argument, s�u��cy do ustawienia ilo��i pami�ci, kt�ra ma zosta� przydzielona
	*/
	stos(const int& rozmiar = 0);

	/** Destruktor klasy stos
	* Dealokuje pami�� przydzielon� obiektowi klasy stos.
	*/
	~stos();

	/** Metoda niemodyfikuj�ca klasy stos
	* Zwraca rzeczywist� d�ugo�� stosu.
	* @return Liczba ca�kowita 
	*/
	int pobierz_rozmiar() const;

	/** Metoda niemodyfikuj�ca klasy stos
	* Zwraca liczb� element�w znajduj�cych si� na stosie.
	* @return Liczba ca�kowita
	*/
	int pobierz_dlugosc() const;

	/** Metoda klasy stos
	* K�adzie element typu long na stos.
	* @param[in] element Sta�a referencja do elementu typu long 
	*/
	void poloz_element(const long& element);

	/** Metoda klasy stos
	* Zedjmuje element typu long ze stosu.
	* @param[in,out] element Referencja do elementu typu long
	* @return true - oznacza, �e uda�o si� �ci�gn�� element ze stosu lub false - oznacza, �e nie uda�o si� �ci�gn�� elementu ze stosu
	*/
	bool zdejmij_element(long& element);

	/** Zaprzyja�niona funkcja operatorowa
	* Dodaje do strumienia wyj�ciowego warto�ci znajduj�ce si� na stosie zaczynaj�c od jego spodu.
	* @param[in,out] Referencja do strumienia wyj�ciowego
	* @param[in] Sta�a referencja do obiektu typu stos
	* @return Referencja do strumienia wyj�ciowego 
	*/
	friend std::ostream& operator<<(std::ostream& strumien_wyjsciowy, const stos& stos);
};



#endif