#include <iostream>
using namespace std;
#include <string>

#include "lista.h"
#include "pila.h"

// INCLUIR EL RESTO DE TADS QUE SE CONSIDEREN OPORTUNOS


// Imprime la lista por la salida estandar
void imprime(const Lista<char>& l) {
	Lista<char>::ConstIterator it = l.cbegin();
	while (it != l.cend()) {
		cout << it.elem();
		it.next();
	}
	cout << endl;
}

bool esVocal(const char & vocal) {
	char aux = tolower(vocal);
	return aux == 'a' || aux == 'e' || aux == 'i'|| aux == 'o' || aux == 'u';
}

void invierteSecuenciasNoVocales(Lista<char> &mensaje) {
	// A IMPLEMENTAR
	Lista<char>::Iterator begin = mensaje.begin();
	Lista<char>::Iterator end = mensaje.end();
	Pila<char> pila = Pila<char>();
	while (begin != end) {
		pila.apila(begin.elem());
		begin = mensaje.eliminar(begin);
	}	
	while (!pila.esVacia()) {
		if (!esVocal(pila.cima())) {
			mensaje.insertar(pila.cima(), begin);
		}
		else {
			mensaje.pon_ppio(pila.cima());
			begin = mensaje.begin();
		}
		pila.desapila();
	}
}

// Codifica el mensaje
void codifica(Lista<char>& mensaje) {
	invierteSecuenciasNoVocales(mensaje);
	mensaje.enredar();    // Esta operacion debe ser implementada como
						  // un nuevo metodo de Lista
}

// Transforma la linea en una lista de caracteres
void construyeMensaje(const string& linea, Lista<char>& mensaje) {
	for (unsigned int i = 0; i < linea.size(); i++)
		mensaje.pon_final(linea[i]);
}

int main() {
	string linea;
	while (getline(cin, linea)) {
		Lista<char> mensaje;
		construyeMensaje(linea, mensaje);
		codifica(mensaje);
		imprime(mensaje);
	}
	return 0;
}