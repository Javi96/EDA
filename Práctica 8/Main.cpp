#include "diccionario.h"
#include "lista.h"
#include <iostream>
#include <string>
using namespace std;


// Clase Puntuacion. Sirve para representar la puntuacion final  (nota)
// obtenida por un alumno.
class Puntuacion {
public:
	string alumno;
	int nota;
	Puntuacion(const string& nombre, int puntuacion) : alumno(nombre), nota(puntuacion) {}
};

void califica(const Lista<string>& bien, const Lista<string>& mal, Lista<Puntuacion>& listado) {
	// A IMPLEMENTAR
	Diccionario<string,int> diccionario = Diccionario<string, int>();
	Lista<string>::ConstIterator i = bien.cbegin();
	Lista<string>::ConstIterator e = bien.cend();
	while (i != e) {
		if (diccionario.contiene(i.elem())) {
			diccionario.inserta(i.elem(),diccionario.valorPara(i.elem())+1);
		}
		else {
			diccionario.inserta(i.elem(), 1);
		}
		i.next();
	}
	i = mal.cbegin();
	e = mal.cend();
	while (i != e) {
		if (diccionario.contiene(i.elem())) {
			diccionario.inserta(i.elem(), diccionario.valorPara(i.elem()) - 1);
		}
		else {
			diccionario.inserta(i.elem(), -1);
		}
		i.next();
	}
	Diccionario<string, int>::ConstIterator j = diccionario.cbegin();
	Diccionario<string, int>::ConstIterator k = diccionario.cend();
	while (j != k) {
		if (j.valor() != 0) {
			listado.pon_final(Puntuacion(j.clave(),j.valor()));
		}
		j.next();
	}
}

void imprimePuntuaciones(Lista<Puntuacion>& listado) {
	Lista<Puntuacion>::ConstIterator i = listado.cbegin();
	Lista<Puntuacion>::ConstIterator e = listado.cend();
	while (i != e) {
		cout << "[" << i.elem().alumno << ":" << i.elem().nota << "]";
		i.next();
	}
	cout << endl;
}

void leeResultados(Lista<string>& bien, Lista<string>& mal) {
	string nombre;
	do {
		cin >> nombre;
		if (nombre != "#") {
			string resultado;
			cin >> resultado;
			if (resultado == "+")
				bien.pon_final(nombre);
			else
				mal.pon_final(nombre);
		}
	} while (nombre != "#");
}

int main() {
	string comienzo;
	while (cin >> comienzo) {
		Lista<string> bien;
		Lista<string> mal;
		Lista<Puntuacion> listado;
		leeResultados(bien, mal);
		califica(bien, mal, listado);
		imprimePuntuaciones(listado);
	}
	return 0;
}