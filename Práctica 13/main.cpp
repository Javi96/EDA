#include <iostream>
#include <string>
#include "pila.h"
using namespace std;

bool esEquilibrada(const string& chain) {
	Pila<char> stack;
	for (int i = 0; i < chain.length(); i++) {
		if (chain[i] == '[' || chain[i] == '{' || chain[i] == '(') {
			stack.apila(chain[i]);
		}
		else if (chain[i] == ']' || chain[i] == '}' || chain[i] == ')') {
			if (stack.esVacia())
				return false;
			switch (stack.cima())
			{
			case '[': if (chain[i] != ']') return false; break;
			case '{': if (chain[i] != '}') return false; break;
			case '(': if (chain[i] != ')') return false; break;
			default: return false; break;
			}
			stack.desapila();
		}
	}
	return stack.esVacia();
}


int main() {
	string cadena;
	while (getline(cin, cadena)) {
		if (esEquilibrada(cadena))
			cout << "EQUILIBRADA" << endl;
		else
			cout << "NO_EQUILIBRADA" << endl;
	}
	return 0;
}