/** @file*/

#ifndef INPUT_FILE_HPP
#define INPUT_FILE_HPP

#include <string>
#include <fstream>

/** Klasa obs�uguj�ca odczyt wyra�enia z pliku tekstowego*/

class plik_wejsciowy {
private:
	const std::string m_nazwa_pliku;	///< Nazwa pliku, z kt�rego b�dzie odczytywane wyra�enie
	std::ifstream m_strumien_pliku;		///< Wej�ciowy strumie� plikowy

public:

	/** Konstruktor jednoargumentowy klasy @ref plik_wejsciowy
	* Otwiera plik o podanej nazwie.
	* @param[in] nazwa_pliku Nazwa pliku do odczytu podana w argumentcie wiersza polece�
	*/
	plik_wejsciowy(const char* nazwa_pliku);

	/** Metoda klasy @ref plik_wejsciowy
	* Odczytuje z pliku tekstowego argument po argumencie i wstawia miedzy nie spacje. 
	* @return Odczytane wyra�enie z pliku
	*/
	std::string odczytaj_z_pliku();

	/** Destruktor klasy @ref plik_wejsciowy
	* @note Je�eli plik nie zosta� otwarty metoda close() nie zostanie wykonana.
	* Zamyka strumie� plikowy.
	*/
	~plik_wejsciowy() { if(m_strumien_pliku.is_open()) m_strumien_pliku.close(); }
};

#endif
