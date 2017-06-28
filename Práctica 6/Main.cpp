#include "Arbin.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;


int busquedaEnProfundidad(const Arbin<int>& cuenca, int & cuenta) {
	int cont_der = 0, cont_izq = 0;

	Arbin<int> der = cuenca.hijoDer();
	Arbin<int> izq = cuenca.hijoIz();
	if (der.esVacio() && izq.esVacio()) {
		return 1;
	}
	else if (der.esVacio()) {
		cont_izq += busquedaEnProfundidad(izq, cuenta);
	}
	else if (izq.esVacio()) {
		cont_der += busquedaEnProfundidad(der, cuenta);
	}
	else {
		cont_izq += busquedaEnProfundidad(izq, cuenta);
		cont_der += busquedaEnProfundidad(der, cuenta);
	}
	if (cont_der >= 3) {
		cuenta++;
	}
	if (cont_izq >= 3) {
		cuenta++;
	}

	if (cont_der + cont_izq + cuenca.raiz() < 0) {
		return 0;
	}
	return cont_der + cont_izq + cuenca.raiz();
}

int numeroTramosNavegables(const Arbin<int>& cuenca) {
	// A IMPLEMENTAR
	int cuenta = 0;
	busquedaEnProfundidad(cuenca, cuenta);
	return cuenta;
}

Arbin<int> leeArbol(istream& in) {
	char c;
	in >> c;
	switch (c) {
	case '#': return Arbin<int>();
	case '[': {
		int raiz;
		in >> raiz;
		in >> c;
		return Arbin<int>(raiz);
	}
	case '(': {
		Arbin<int> iz = leeArbol(in);
		int raiz;
		in >> raiz;
		Arbin<int> dr = leeArbol(in);
		in >> c;
		return Arbin<int>(iz, raiz, dr);
	}
	default: return Arbin<int>();
	}
}

int main() {
	Arbin<int> cuenca;
	while (cin.peek() != EOF) {
		cout << numeroTramosNavegables(leeArbol(cin));
		string restoLinea;
		getline(cin, restoLinea);
		if (cin.peek() != EOF) cout << endl;
	}
	return 0;
}