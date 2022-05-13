/** @file*/

#ifndef CALCULATOR_HPP
#define CALCULATOR_HPP

/** Klasa obliczaj¹ca wartoœæ wprowadzonego wyra¿enia zapisanego w ONP*/

class kalkulator {
private:
	const std::string& m_lancuch; ///< Sta³a referencja do ³añcucha przechowuj¹cego wyra¿enie wejœciowe 

public:

	/** Konstruktor jednoargumentowy klasy @ref klakulator
	* @param[in] Sta³a referencja do ³añcucha z wyra¿eniem zapisanym w ONP
	*/
	kalkulator(const std::string&);

	/** Metoda niemodyfikuj¹ca klasy @ref kalkulator
	* Oblicza wartoœæ wprowadzonego wyra¿enia zapisanego w ONP.
	* @return Liczba ca³kowita bed¹ca wynikiem ostatecznym obliczonego wyra¿enia zapisanego w ONP
	*/
	long oblicz_wartosc_wyrazenia() const;

};

#endif

