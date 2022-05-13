/** @file*/

#ifndef OPERATIONS_HPP
#define OPERATIONS_HPP

#include <string>

/** Klasa abstrakcyja dzialanie
* @brief Jest klas� bazow� dla klasy @ref dzialanie_dwuargumentowe.
*/

class dzialanie {
protected:

	/** Klasa zagnie�d�ona argumenty*/
	class argumenty {
	public:
		std::string m_lancuch_argumentow;				///< �a�cuch przechowuj�cy argumenty oddzielone spacjami

		/** Funkcja operatorowa klasy zagnie�d�onej argumenty
		* Zwraca warto�� wybranego argumentu.
		* @param[in] indeks Indeks argumentu w �a�cuchu argument�w
		* @return Liczba ca�kowita
		*/
		long operator[](const unsigned short& indeks) const;
		
	};

	argumenty m_przekazane_argumenty;				///< Obiekt zagnie�d�onej klasy argumenty
	const unsigned short m_argumentowosc_operacji;	///< Liczba argument�w potrzebnych do przeprowadzenia danej operacji

public:

	/** Konstruktor domy�lny klasy dzia�anie
	* @param[in] argumentowosc_operacji Liczba argument�w potrzebnych do przeprowadzenia danej operacji
	*/
	dzialanie(unsigned short argumentowosc_operacji = 0);

	/** Metoda czysto wirtualna klasy dzia�anie
	* Zwraca wynik operacji.
	* @return Liczba ca�kowita
	*/
	virtual long oblicz() = 0;

	/** Metoda niemodyfikuj�ca klasy dzia�anie
	* Zwraca ilo�� argument�w potrzebnych do przeprowadzenia danej operacji.
	* @return Liczba ca�kowita bez znaku
	*/
	unsigned short zwroc_argumentowosc_operacji() const { return m_argumentowosc_operacji; }

	/** Metoda klasy dzia�anie
	* Pobiera �a�cuch argument�w operacji.
	* @param[in] lancuch_argumentow �a�cuch przechowuj�cy argumenty oddzielone spacjami
	*/
	void wprowadz_lancuch_argumentow(std::string lancuch_argumentow) { m_przekazane_argumenty.m_lancuch_argumentow = lancuch_argumentow; }
	
};

/** Klasa abstrakcyja dzialanie dwuargumentowe
* @brief Jej bezpo�rednim przodkiem jest klasa @ref dzialanie. Dziedzicz� po niej klasy reprezentuj�ce konkretne dzia�ania dwuargumentowe. 
*/

class dzialanie_dwuargumentowe : public dzialanie {
public:
	/** Konstruktor domy�lny klasy dzia�anie dwuargumentowe
	* Ustawia warto�� pola m_argumentowosc_operacji odziedziczonego po klasie @ref dzialanie na 2.
	*/
	dzialanie_dwuargumentowe();
};

/** Klasa dodawanie dziedzicz�ca po klasie @ref dzialanie_dwuargumentowe*/

class dodawanie final : public dzialanie_dwuargumentowe {
public:
	using dzialanie_dwuargumentowe::dzialanie_dwuargumentowe;

	/** Metoda wirtualna klasy @ref dodawanie 
	* Zwraca wynik operacji dodawania.
	* @return Liczba ca�kowita
	*/
	virtual long oblicz() override;
};

/** Klasa odejmowanie dziedzicz�ca po klasie @ref dzialanie_dwuargumentowe*/

class odejmowanie final : public dzialanie_dwuargumentowe {
public:
	using dzialanie_dwuargumentowe::dzialanie_dwuargumentowe;

	/** Metoda wirtualna klasy @ref odejmowanie
	* Zwraca wynik operacji odejmowania.
	* @return Liczba ca�kowita
	*/
	virtual long oblicz() override;
};

/** Klasa mnozenie dziedzicz�ca po klasie @ref dzialanie_dwuargumentowe*/

class mnozenie final : public dzialanie_dwuargumentowe {
public:
	using dzialanie_dwuargumentowe::dzialanie_dwuargumentowe;

	/** Metoda wirtualna klasy @ref mnozenie
	* Zwraca wynik operacji mno�enia.
	* @return Liczba ca�kowita
	*/
	virtual long oblicz() override;
};

/** Klasa dzielenie_calkowite dziedzicz�ca po klasie @ref dzialanie_dwuargumentowe*/

class dzielenie_calkowite final : public dzialanie_dwuargumentowe {
public:
	using dzialanie_dwuargumentowe::dzialanie_dwuargumentowe;

	/** Metoda wirtualna klasy @ref dzielenie_calkowite
	* Zwraca wynik operacji dzielenia ca�kowitego.
	* @return Liczba ca�kowita
	*/
	virtual long oblicz() override;
};

/** Klasa dzielenie_modulo dziedzicz�ca po klasie @ref dzialanie_dwuargumentowe*/

class dzielenie_modulo final : public dzialanie_dwuargumentowe {
public:
	using dzialanie_dwuargumentowe::dzialanie_dwuargumentowe;

	/** Metoda wirtualna klasy @ref dzielenie_modulo
	* Zwraca wynik operacji dzielenia modulo.
	* @return Liczba ca�kowita
	*/
	virtual long oblicz() override;
};

/** Klasa potegowanie dziedzicz�ca po klasie @ref dzialanie_dwuargumentowe*/

class potegowanie final : public dzialanie_dwuargumentowe {
public:
	using dzialanie_dwuargumentowe::dzialanie_dwuargumentowe;

	/** Metoda wirtualna klasy @ref potegowanie
	* Zwraca wynik operacji dzielenia pot�gowania.
	* @return Liczba ca�kowita
	*/
	virtual long oblicz() override;
};

#endif