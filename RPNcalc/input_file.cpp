#include <string>
#include <fstream>
#include "input_file.hpp"

plik_wejsciowy::plik_wejsciowy(const char* nazwa_pliku) : m_nazwa_pliku(nazwa_pliku) {
	m_strumien_pliku.open(m_nazwa_pliku, std::ios::in);
}

std::string plik_wejsciowy::odczytaj_z_pliku() {
	std::string calosc = "";

	if (m_strumien_pliku.is_open()) {
		std::string wejscie;

		while (m_strumien_pliku >> wejscie) {
			if (!calosc.empty()) {
				calosc += ' ';
			}

			calosc += wejscie;
		}

	}

	return calosc;
	
}