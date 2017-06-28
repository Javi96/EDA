#include "Foro.h"


/*** METODOS DE Mensaje ***/

Mensaje::Mensaje(MID id, const string& remitente, const string& asunto, const string& cuerpo) :
	_id(id), _remitente(remitente), _asunto(asunto), _cuerpo(cuerpo) {}

const MID Mensaje::id() const {
	return _id;
}

const string& Mensaje::remitente() const {
	return _remitente;
}

const string& Mensaje::asunto() const {
	return _asunto;
}

const string& Mensaje::cuerpo() const {
	return _cuerpo;
}


/*** METODOS DE Foro ***/

Foro::Foro() {
	// A IMPLEMENTAR
	_mensajes = Diccionario<MID, Mensaje>();
	_id = Lista<MID>();
	_contador = 0;
}

void Foro::envia_mensaje(MID id, const string& remitente, const string& asunto, const string& cuerpo) {
	// A IMPLEMENTAR
	if (_mensajes.contiene(id)) {
		throw EMIDDuplicado();
	}
	_mensajes.inserta(id, Mensaje(id, remitente, asunto, cuerpo));
	_id.pon_final(id);
	_contador++;
}

const Mensaje& Foro::consulta_mensaje(MID id) const {
	// A IMPLEMENTAR
	if (!_mensajes.contiene(id)) {
		throw ENoHayMensaje();
	}
	return _mensajes.valorPara(id);
}

void Foro::elimina_mensaje(MID id) {
	// A IMPLEMENTAR
	if (_mensajes.contiene(id)) {
		_mensajes.borra(id);
		Lista<MID>::Iterator begin = _id.begin();
		Lista<MID>::Iterator end = _id.end();
		while (begin != end) {
			if (begin.elem() == id) {
				begin = _id.eliminar(begin);
			}
			else {
				begin.next();
			}
			
		}
		_contador--;
	}
}

Lista<MID> Foro::recupera_mensajes(unsigned int n) const {
	// A IMPLEMENTAR
	Lista<MID> _lista = Lista<MID>();
	Lista<MID>::ConstIterator begin = _id.cbegin();
	Lista<MID>::ConstIterator end = _id.cend();
	if (n > _contador) {
		while (begin != end) {
			_lista.pon_ppio(begin.elem());
			begin.next();
		}
	}
	else {
		unsigned int _cont = 0;
		while (begin != end) {
			if (_cont >= _contador - n) {
				_lista.pon_ppio(begin.elem());
			}
			begin.next();
			_cont++;
		}
	}
	return _lista;
}

unsigned int Foro::numero_mensajes() const {
	// A IMPLEMENTAR
	return _contador;
}