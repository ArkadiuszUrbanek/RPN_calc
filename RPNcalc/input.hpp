/** @file*/

#ifndef INPUT_HPP
#define INPUT_HPP

#include <string>

/** Klasa zapewniaj�ca obs�ug� wej�cia do programu*/

class wejscie {
public:

	/** Metoda statyczna klasy @ref wejscie
	* Sprawdza argumenty wej�ciowe wprowadzone do programu i na ich podstawie zwraca �a�cuch zwieraj�cy wyra�enie z odpowiedniego wej�cia.
	* @return �a�cuch zawieraj�cy wyra�enie
	*/
	static const std::string zwroc_wejscie();

};

#endif

