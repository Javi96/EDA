#ifndef _RACIONAL_H
#define _RACIONAL_H

#include <iostream>
#include <cmath>

using namespace std;

template <class T>
class Racional {
public:
      //Excepcion que se lanza cuando se trata de crear
	  //una fraccion con denominador 0
	class EDenominadorCero {};
      //Excepcion que se lanza cuando se produce una division
      //por 0
	class EDivisionPorCero {};

	 // Constructora por defecto: crea la fraccion 0/1
	Racional();

   	  // Constructora para crear la fraccion num / denom
	  // Si denom es 0, levanta una excepcion de tipo 
	  // EDenominadorCero.
	Racional(long num, long denom);

	  // La fraccion mas 'r' 
	Racional suma(const Racional &r) const;
	
	  // La fraccion menos 'r'
	Racional operator-(const Racional &r) const;
	
	  // Actualiza la fraccion al resultado de multiplicar por  'r'
	void operator*=(const Racional &r);
	
	  // Actualiza la fraccion al resultado de dividirla por 'r'.
	  // Si r es 0, levanta una excepcion EDivisionPorCero.
	void divideYActualiza(const Racional &r);
	
	  // Funcion de equivalencia
	bool operator ==(const Racional &r) const;
	
	  // Funcion que permite escribir una fraccion en un 'stream'
    friend ostream& operator<< (ostream& out, const Racional<T>& f) {
  	   out << f._numer << "/" << f._denom;
  	   return out;
    }	  
private:
	long _numer;     // El numerador
	long _denom;     // El denominador 
	void reduce();   // Transforma la fraccion en una equivalente irreducible (es decir, una en la que
	                 // el denominador es siempre positivo, y el unico divisor comun del numerador y el 
					 // denominador es 1)	
	static long mcm(long v1, long v2);     // Minimo comun multiplo de v1 y v2
	static long mcd(long v1, long v2);     // Maximo comun divisor de v1 y v2 
};



  //Metodos publicos
  // ADAPTAR PARA SE CORRESPONDAN CON LOS DE LA PLANTILLA
  
Racional::Racional() {
	_numer = 0;
	_denom = 1;
}


Racional::Racional(long num, long denom) {
	if (denom == 0) throw EDenominadorCero();
	else {
		_numer = num;
		_denom = denom;
		reduce();
	}
}


Racional Racional::suma(const Racional &r) const {
	if (_denom == r._denom) {
		return Racional(_numer + r._numer,_denom);
	}
	else {
		long ndenom = mcm(_denom, r._denom);
		return Racional(_numer*(ndenom / _denom)+r._numer*(ndenom / r._denom),
		                ndenom);
	}
}


Racional Racional::operator-(const Racional &r) const {
	if (_denom == r._denom) {
		return Racional(_numer - r._numer,_denom);
	}
	else {
		long ndenom = mcm(_denom, r._denom);
		return Racional(_numer*(ndenom / _denom)-r._numer*(ndenom / r._denom),
		                ndenom);
	}
}


void Racional::operator*=(const Racional &r) {
    _numer =_numer*r._numer;
    _denom = _denom*r._denom;
    reduce();
}


void Racional::divideYActualiza(const Racional &r) {
	if (r._numer == 0) throw EDivisionPorCero();
	else {
	    _numer =  _numer*r._denom;
	    _denom = _denom*r._numer;
	    reduce();
	}
}


bool Racional::operator ==(const Racional &r) const {
	return _numer == r._numer && _denom == r._denom;
}

 
// Metodos privados
void Racional::reduce() {
	  // Se asegura que el denominador siempre sea positivo   
	if (_denom < 0) {
		_numer = -_numer;
		_denom = -_denom;
	}
	  // Se divide numerador y denominador por el maximo comun divisor de ambos
	long fsimp = mcd(_numer, _denom);
	_numer /= fsimp;
	_denom /= fsimp;
}

long Racional::mcd(long v1, long v2) {
	  // El calculo del maximo comun divisor se hace por el algoritmo de Euclides
	v1 = abs(v1); 
    v2 = abs(v2);	
	if (v1 < v2) {
		long tmp = v1;
		v1 = v2;
		v2 = tmp;
	}
	while (v2 != 0) {
		long nv2 = v1%v2;
		v1 = v2;
		v2 = nv2;
	}
	return v1;
}

long Racional::mcm(long v1, long v2) {
	return v1*v2 / mcd(v1, v2);
}




#endif