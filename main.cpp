#include "Racional.h"

#include <iostream>
#include <string>
using namespace std;

   // Codigo de prueba
   // El programa se comporta como el del control 1, con la
   // salvedad de que, ahora, mantiene una 'precion' para 
   // realizar los cálculos, que indica si los cálculos deben
   // hacerse con precisión 'short', 'int' o 'long'. Se admite,
   // además, los siguientes comandos, que permiten cambiar
   // la precisión:
   //   s: cambia a precisión 'short'.
   //   i: cambia a precisión 'int'
   //   l: cambia a precisión 'long'
   // La ejecución de estos comandos, aparte de cambiar la precision,
   // imprimen por pantalla, respectivamente, PRECISION_SHORT, 
   // PRECISION_INT y PRECISION_LONG.
   // Inicialmente, la precisión es 'long'. 

enum TPrecision {SHORT, INT, LONG};
 
   // Lee una fraccion de la entrada estandar
template <class T>   
Racional<T> leeFraccion() {
	T numer, denom;
	char sdiv;
	cin >> numer >> sdiv >> denom;
	return Racional<T>(numer, denom);
}

template <class T>
void procesaOperacion(const string &comando) {
	 try {
      Racional<T> arg1 = leeFraccion<T>();
 	  Racional<T> arg2 = leeFraccion<T>();
 	  // Se ejecuta el comando
  	  switch (comando[0]) {
		  case '+':
			  cout << arg1.suma(arg2) << endl;
			  break;
		  case '-':
			  cout << arg1 - arg2 << endl;
			  break;
		  case '*':
			  arg1 *= arg2;
			  cout << arg1 << endl;
			  break;
		  case '/':
		      arg1.divideYActualiza(arg2);
			  cout << arg1 << endl;
			  break;
		   case '=':
			   cout << (arg1 == arg2) << endl;
			   break;
	   }
	 }
	 catch (typename Racional<T>::EDenominadorCero) {
	   cout << "ERROR_EN_ARGUMENTO" << endl;
	   string resto_linea;
	   getline(cin,resto_linea);
	 }
	catch (typename Racional<T>::EDivisionPorCero) {
	  cout << "DIVISION_POR_CERO" << endl;
	}
 }	


int main() {
	string comando;
	cout << boolalpha;
	  TPrecision precision=LONG;
	  // Se ejecutan los comandos
	  while (cin >> comando) {
	      switch(comando[0]) {
  		    case 's': 
		      precision = SHORT;
			  cout << "PRECISION_SHORT" << endl;
			  break;
		    case 'i':
              precision=INT;
			  cout << "PRECISION_INT" << endl;
              break;
            case 'l':
              precision=LONG;
			  cout << "PRECISION_LONG" << endl;
              break;			  
            default:  
		      switch(precision) {
			    case SHORT: procesaOperacion<short>(comando); break;
                case INT: procesaOperacion<int>(comando); break;
                case LONG: procesaOperacion<long>(comando); break;			
		      }
	      }    
	  }
}	  
		  
