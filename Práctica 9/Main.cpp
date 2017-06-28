#include "Libreria.h"
#include <string>
#include <iostream>
using namespace std;


void an_libro(Libreria& libreria) {
	string libro;
	unsigned int cantidad;
	cin >> libro >> cantidad;
	  // Se añade el libro a la libreria,
	  // y se imprime el número de libros
	  // disponibles tras el añadido.
	libreria.an_libro(libro,cantidad);
	cout << libreria.num_libros() << endl;
}

void comprar(Libreria& libreria) {
	string libro;
	cin >> libro;
	try {
		  // Se registra una compra de un libro,
		  // y se imprime el número de libros 
		  // disponibles tras la compra.
		libreria.comprar(libro);
		cout << libreria.num_ejemplares(libro) << endl;
	}
	catch (ENoHayEjemplares) {
		cout << "NO_HAY_EJEMPLARES" << endl;
	}
	catch (ELibroNoExiste) {
		cout << "LIBRO_NO_EXISTE" << endl;
	}
}

void esta_libro(const Libreria& libreria) {
	string libro;
	cin >> libro;
	cout << libreria.esta_libro(libro) << endl;
}

void elim_libro(Libreria& libreria) {
	string libro;
	cin >> libro;
		  // Se elimina un libro, y se imprime el número 
		  // de libros disponibles tras la eliminación.
	libreria.elim_libro(libro);
	cout << libreria.num_libros() << endl;
}

void num_ejemplares(Libreria& libreria) {
	string libro;
	cin >> libro;
	try {
		cout << libreria.num_ejemplares(libro) << endl;
	}
	catch (ELibroNoExiste) {
		cout << "LIBRO_NO_EXISTE" << endl;
	}
}

int main() {
	Libreria libreria;
	string comando;
	cout << boolalpha;
	   // Bucle de ejecución de comandos: lee un comando, y 
	   // lo ejecuta
	while(cin >> comando) {
			if (comando == "an_libro") an_libro(libreria);
			else if (comando == "comprar") comprar(libreria);
			else if (comando == "esta_libro") esta_libro(libreria);
			else if (comando == "elim_libro") elim_libro(libreria);
			else if (comando == "num_ejemplares") num_ejemplares(libreria);
	}
	return 0;
}