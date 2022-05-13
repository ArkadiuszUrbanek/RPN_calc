/** @file*/

#ifndef CALCULATOR_HPP
#define CALCULATOR_HPP

/** Klasa obliczaj�ca warto�� wprowadzonego wyra�enia zapisanego w ONP*/

class kalkulator {
private:
	const std::string& m_lancuch; ///< Sta�a referencja do �a�cucha przechowuj�cego wyra�enie wej�ciowe 

public:

	/** Konstruktor jednoargumentowy klasy @ref klakulator
	* @param[in] Sta�a referencja do �a�cucha z wyra�eniem zapisanym w ONP
	*/
	kalkulator(const std::string&);

	/** Metoda niemodyfikuj�ca klasy @ref kalkulator
	* Oblicza warto�� wprowadzonego wyra�enia zapisanego w ONP.
	* @return Liczba ca�kowita bed�ca wynikiem ostatecznym obliczonego wyra�enia zapisanego w ONP
	*/
	long oblicz_wartosc_wyrazenia() const;

};

#endif

