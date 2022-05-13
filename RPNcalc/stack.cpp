#include <cstring>

#include "stack.hpp"

stos::stos(const int& rozmiar) : m_rozmiar(rozmiar), m_dlugosc(0) {
	if (m_rozmiar != 0) {
		m_wsk_spod = new long[m_rozmiar] {};
	} else {
		m_wsk_spod = nullptr;
	}
}

stos::~stos() {
	delete[] m_wsk_spod;
}

int stos::pobierz_rozmiar() const {
	return m_rozmiar;
}

int stos::pobierz_dlugosc() const {
	return m_dlugosc;
}

void stos::poloz_element(const long& element) {
	if (m_rozmiar == m_dlugosc) {
		long* pom = new long[++m_rozmiar] {};

		std::memcpy(pom, m_wsk_spod, m_dlugosc * sizeof(long));

		delete[] m_wsk_spod;
		m_wsk_spod = pom;
	}
		
	m_wsk_spod[m_dlugosc++] = element;
}

bool stos::zdejmij_element(long& element) {
	if (m_dlugosc > 0) {
		element = m_wsk_spod[--m_dlugosc];

		long* pom = new long[--m_rozmiar] {};

		std::memcpy(pom, m_wsk_spod, m_dlugosc * sizeof(long));

		delete[] m_wsk_spod;
		m_wsk_spod = pom;

		return true;
	}

	return false;
}

std::ostream& operator<<(std::ostream& strumien_wyjsciowy, const stos& stos) {
	for (int licznik = 0; licznik < stos.m_dlugosc; licznik++) {
		strumien_wyjsciowy << stos.m_wsk_spod[licznik] << " ";
	}
	return strumien_wyjsciowy;
}