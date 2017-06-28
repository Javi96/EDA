#ifndef _LIBRERIA_H
#define _LIBRERIA_H

#include "Libro.h"
#include "diccionario.h"
/****  
REALIZAR LAS INCLUSIONES
ADICIONALES QUE SE ESTIMEN NECESARIAS 
*****/

/**
 Excepción que debe levantarse cuando trata
 de comprarse un libro para el que no hay 
 existencias 
*/
class ENoHayEjemplares {};
/**
 Excepción que debe levantarse cuando trata
 de consultarse información de un libro que 
 no existe.
*/
class ELibroNoExiste {};

class Libreria {
public:
    /**
	 Crea una librería vacía 
	 */
	Libreria();
	/**
	  Añade una cantidad dada de ejemplares de un libro a la librería.
	  Si el libro no está, lo da de alta con el número indicado de
	  ejemplares. Si el libro está, suma el número indicado de ejemplares
	  a los ya existentes.
	  @libro El libro del que van a añadirse ejemplares
	  @n Número de ejemplares a añadir
	*/
	void an_libro(const Libro& libro, unsigned int n);
	/**
	  Registra la compra de un ejemplar de un libro. En caso
	  de que no queden existencias (es decir, de que el número
	  de ejemplares disponibles sea 0), levanta una excepción
	  ENoHayEjemplares. En caso de que el libro no esté dado
	  de alta, levanta la excepción ELibroNoExiste.
	  @libro El libro que se compra
	*/
	void comprar(const Libro& libro);
	/**
	  Comprueba si un libro está dado de alta en la librería.
	  @libro El libro a comprobar
	  @return True si el libro está dado de alta, False en otro caso.
	*/
	bool esta_libro(const Libro& libro) const;
	/**
	  Elimina un libro del catálogo. Si el libro no está en
	  el catálogo, la operación no tiene ningún efecto.
	  @libro El libro a eliminar
	*/	
	void elim_libro(const Libro& libro);
	/**
	  Devuelve el número de ejemplares disponibles para un libro dado.
	  Levanta la excepción ELibroNoExiste si el libro no está dado de alta.
	  @libro El libro cuyas existencias se consultan
	  @return Número de ejemplares del libro.
	*/
	int num_ejemplares(const Libro& libro) const;
	/**
	  Devuelve el número de libros distintos que están dados de alta
	  en el catálogo
	  @return Número de libros distintos datos de alta en la librería
	*/
	int num_libros() const;
private:
	string _nombre;
	unsigned int _cantidad;
	Diccionario<string,unsigned int> _libreriaDic;
	int _numTotalLibros;

/****  
   INLCUIR LAS DEFINICIONES NECESARIAS PARA 
   LA REPRESENTACIÓN DEL TAD
*****/
};

#endif