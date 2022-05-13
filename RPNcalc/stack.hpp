/** @file*/

#ifndef STACK_HPP
#define STACK_HPP

#include <iostream>

/** Klasa obs³uguj¹ca stos*/

class stos {
private:
	int m_dlugosc;		///< liczba elementów po³o¿onych na stos
	int m_rozmiar;		///< rzeczywista d³ugoœæ stosu
	long* m_wsk_spod;	///< wskaŸnik na spód stosu

public:
	/** Konstruktor domyœlny klasy stos
	* @param[in] rozmiar Opcjonalny argument, s³u¿¹cy do ustawienia iloœæi pamiêci, która ma zostaæ przydzielona
	*/
	stos(const int& rozmiar = 0);

	/** Destruktor klasy stos
	* Dealokuje pamiêæ przydzielon¹ obiektowi klasy stos.
	*/
	~stos();

	/** Metoda niemodyfikuj¹ca klasy stos
	* Zwraca rzeczywist¹ d³ugoœæ stosu.
	* @return Liczba ca³kowita 
	*/
	int pobierz_rozmiar() const;

	/** Metoda niemodyfikuj¹ca klasy stos
	* Zwraca liczbê elementów znajduj¹cych siê na stosie.
	* @return Liczba ca³kowita
	*/
	int pobierz_dlugosc() const;

	/** Metoda klasy stos
	* K³adzie element typu long na stos.
	* @param[in] element Sta³a referencja do elementu typu long 
	*/
	void poloz_element(const long& element);

	/** Metoda klasy stos
	* Zedjmuje element typu long ze stosu.
	* @param[in,out] element Referencja do elementu typu long
	* @return true - oznacza, ¿e uda³o siê œci¹gn¹æ element ze stosu lub false - oznacza, ¿e nie uda³o siê œci¹gn¹æ elementu ze stosu
	*/
	bool zdejmij_element(long& element);

	/** ZaprzyjaŸniona funkcja operatorowa
	* Dodaje do strumienia wyjœciowego wartoœci znajduj¹ce siê na stosie zaczynaj¹c od jego spodu.
	* @param[in,out] Referencja do strumienia wyjœciowego
	* @param[in] Sta³a referencja do obiektu typu stos
	* @return Referencja do strumienia wyjœciowego 
	*/
	friend std::ostream& operator<<(std::ostream& strumien_wyjsciowy, const stos& stos);
};



#endif