#include "Racional.h"
#include <cmath>

//Metodos publicos

  //**** COMPLETAR
  //  Deben implementarse los metodos publicos de la clase
  //****


// Funciones amigas
ostream& operator<<(ostream& out, const Racional& f) {
	out << f._numer << "/" << f._denom;
	return out;
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
//////////////////////////////////////////////////////////////////////////////////////////////////////////////

Racional::Racional() {
	_numer = 0;
	_denom = 1;
}

Racional::Racional(long numer, long denom) {
	if (denom == 0) {
		throw EDenominadorCero();
	}
	_numer = numer;
	_denom = denom;
	reduce();
}

Racional Racional::suma(const Racional & f) {

	long new_denom = mcm(f._denom, _denom);
	long operando_1 = _numer*new_denom / _denom;
	long operando_2 = f._numer*new_denom / f._denom;
	Racional racional(operando_1 + operando_2, new_denom);
	racional.reduce();
	return racional;

}

/*Racional Racional::suma(const Racional & f) {

	Racional resultado;

	resultado._denom = f._denom * _denom;
	resultado._numer = _numer * f._denom + f._numer * _denom;
	resultado.reduce();
	return resultado;
}*/

void Racional::divideYActualiza(const Racional& f) {
	if (f._numer == 0) {
		throw EDivisionPorCero();
	}

	_numer = _numer*f._denom;
	_denom = _denom*f._numer;
	reduce();
}


