#include <iostream>
#include <conio.h>
#include <string>

#include <crtdbg.h>

#include "validate.hpp"
#include "calculator.hpp"
#include "input.hpp"

using namespace std;

char** gargv;
int gargc;

int main(int argc, char *argv[]) {

	#ifdef _WIN32

	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	#endif


	gargv = argv;
	gargc = argc;

	const string przechwycone_wyrazenie = wejscie::zwroc_wejscie();

	walidacja waliduj_wyrazenie(przechwycone_wyrazenie);

	if (waliduj_wyrazenie.czy_poprawne_wyrazenie()) {
		kalkulator kalkulator(przechwycone_wyrazenie);

		cout << "Wynik ostateczny: " << kalkulator.oblicz_wartosc_wyrazenia();
		_getch();

	} else {
		system("cls");
		cerr << "Wczytano niepoprawne wyrazenie.";
		exit(EXIT_FAILURE);

	}

	exit(EXIT_SUCCESS);
}