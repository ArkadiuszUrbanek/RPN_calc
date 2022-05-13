/** @file*/

#ifndef INPUT_HPP
#define INPUT_HPP

#include <string>

/** Klasa zapewniaj¹ca obs³ugê wejœcia do programu*/

class wejscie {
public:

	/** Metoda statyczna klasy @ref wejscie
	* Sprawdza argumenty wejœciowe wprowadzone do programu i na ich podstawie zwraca ³añcuch zwieraj¹cy wyra¿enie z odpowiedniego wejœcia.
	* @return £añcuch zawieraj¹cy wyra¿enie
	*/
	static const std::string zwroc_wejscie();

};

#endif

