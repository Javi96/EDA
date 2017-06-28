#include "Arbin.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void busquedaEnProfundidad(const Arbin<char>& falda, int & cuenta, int & cuentaParcial) {
	Arbin<char> der = falda.hijoDer();
	Arbin<char> izq = falda.hijoIz();
	if (falda.raiz() == 'X') {
		cuenta = cuenta + cuentaParcial * 2;
	}
	if (der.esVacio() && izq.esVacio()) {
		cuentaParcial--;
	}
	else {
		if (!izq.esVacio()) {
			cuentaParcial++;
			busquedaEnProfundidad(izq, cuenta, cuentaParcial);
		}
		if (!der.esVacio()) {
			cuentaParcial++;
			busquedaEnProfundidad(der, cuenta, cuentaParcial);
		}
		cuentaParcial--;
	}
}

int tiempoAyuda(const Arbin<char>& falda) {
	// A IMPLEMENTAR
	int cuenta = 0, cuentaParcial = 0;
	busquedaEnProfundidad(falda, cuenta, cuentaParcial);
	return cuenta;
}

Arbin<char> leeArbol(istream& in) {
	char c;
	in >> c;
	switch (c) {
	case '#': return Arbin<char>();
	case '[': {
		char raiz;
		in >> raiz;
		in >> c;
		return Arbin<char>(raiz);
	}
	case '(': {
		Arbin<char> iz = leeArbol(in);
		char raiz;
		in >> raiz;
		Arbin<char> dr = leeArbol(in);
		in >> c;
		return Arbin<char>(iz, raiz, dr);
	}
	default: return Arbin<char>();
	}
}

int main() {
	Arbin<char> falda;
	while (cin.peek() != EOF) {
		cout << tiempoAyuda(leeArbol(cin));
		string restoLinea;
		getline(cin, restoLinea);
		if (cin.peek() != EOF) cout << endl;
	}
	return 0;
}