#include "Libreria.h"

Libreria::Libreria() {
	_libreriaDic = Diccionario<string, unsigned int>();
	_numTotalLibros = 0;
}
void Libreria::an_libro(const Libro& libro, unsigned int n) {
	if (!esta_libro(libro)){
		_numTotalLibros++;
		_libreriaDic.inserta(libro.nombre(), n);
	}
	else
		_libreriaDic.inserta(libro.nombre(), _libreriaDic.valorPara(libro.nombre()) + n);
}

void Libreria::comprar(const Libro& libro) {
	if (!esta_libro(libro))
		throw ELibroNoExiste();
	else {
		if (_libreriaDic.valorPara(libro.nombre()) <= 0)
			throw ENoHayEjemplares();
		else
			_libreriaDic.inserta(libro.nombre(), _libreriaDic.valorPara(libro.nombre()) -1);
	}
}
bool Libreria::esta_libro(const Libro& libro) const {
	return _libreriaDic.contiene(libro.nombre());
}

void Libreria::elim_libro(const Libro& libro) {
	if (_libreriaDic.contiene(libro.nombre()))
	{
		_libreriaDic.borra(libro.nombre());
		_numTotalLibros--;
	}
}
	
int Libreria::num_ejemplares(const Libro& libro) const {
	return (!esta_libro(libro)) ? throw ELibroNoExiste() : _libreriaDic.valorPara(libro.nombre());
}

int Libreria::num_libros() const {
	return _numTotalLibros;
}