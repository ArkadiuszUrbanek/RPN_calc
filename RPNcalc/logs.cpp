#include <string>
#include <fstream>

#include "logs.hpp"
#include "stack.hpp"

const std::string logi::m_nazwa_pliku = "logi.txt";

logi::logi() {
	m_strumien_pliku.open(m_nazwa_pliku, std::ios::out | std::ios::trunc);
	m_strumien_pliku << "WEJSCIE\tOPERACJA         STOS\n";
}

void logi::zapisz_do_pliku(long liczba_calkowita, const stos& stos) {
	m_strumien_pliku << liczba_calkowita << '\t' << "daj na stos      " << stos << '\n';

}

void logi::zapisz_do_pliku(std::string symbol_operatora, const stos& stos) {
	m_strumien_pliku << symbol_operatora << '\t' << "wykonaj operacje " << stos << '\n';

}


