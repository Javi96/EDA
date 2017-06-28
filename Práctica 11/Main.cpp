#include "Foro.h"

#include <iostream>
#include <string>
using namespace std;

void muestra_mensaje(const Mensaje& m) {
	cout << "ID:" << m.id() << endl;
	cout << "REMITENTE:" << m.remitente() << endl;
	cout << "ASUNTO:" << m.asunto() << endl;
	cout << "CUERPO:" << m.cuerpo() << endl;
	cout << "---" << endl;
}

void muestra_mensajes(const Foro& foro, const Lista<MID>& mensajes) {
	Lista<MID>::ConstIterator p = mensajes.cbegin();
	while (p != mensajes.cend()) {
		muestra_mensaje(foro.consulta_mensaje(p.elem()));
		p.next();
	}
}

void muestra_foro(const Foro& foro) {
	muestra_mensajes(foro, foro.recupera_mensajes(foro.numero_mensajes()));
}

void ultimos_mensajes(Foro& foro) {
	unsigned int n;
	cin >> n;
	string nada;
	getline(cin, nada);
	muestra_mensajes(foro, foro.recupera_mensajes(n));
}

void elimina_mensaje(Foro& foro) {
	MID id;
	cin >> id;
	string nada;
	getline(cin, nada);
	foro.elimina_mensaje(id);
	muestra_foro(foro);
}

void consulta_mensaje(const Foro& foro) {
	MID id;
	cin >> id;
	string nada;
	getline(cin, nada);
	try {
		muestra_mensaje(foro.consulta_mensaje(id));
	}
	catch (ENoHayMensaje) {
		cout << "MENSAJE_NO_EXISTE" << endl;
	}
}

void envia_mensaje(Foro& foro) {
	string nada;
	getline(cin, nada);
	int id;
	cin >> id;
	getline(cin, nada);
	string remitente;
	string asunto;
	string cuerpo;
	getline(cin, remitente);
	getline(cin, asunto);
	getline(cin, cuerpo);
	try {
		foro.envia_mensaje(id, remitente, asunto, cuerpo);
		muestra_foro(foro);
	}
	catch (EMIDDuplicado) {
		cout << "MENSAJE_DUPLICADO" << endl;
	}
}

int main() {
	Foro foro;
	string comando;
	while (cin >> comando) {
		if (comando == "envia") envia_mensaje(foro);
		else if (comando == "consulta") consulta_mensaje(foro);
		else if (comando == "elimina") elimina_mensaje(foro);
		else if (comando == "ultimos") ultimos_mensajes(foro);
	}
	system("PAUSE");
	return 0;
}