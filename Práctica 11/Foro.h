#ifndef _FORO_H
#define _FORO_H

#include "lista.h"
#include "diccionario.h"
#include <string>
using namespace std;


/* Alias para el tipo de los identificadores de mensajes */
typedef unsigned int MID;

/**
Representaci�n de los mensajes
*/
class Mensaje {
public:
	/**
	Construye un mensaje
	@param id El identificador del mensaje
	@param remitente El nombre del usuario que env�a el mensaje
	@param asunto El asunto del mensaje
	@param cuerpo El contenido del mensaje
	*/
	Mensaje(MID id, const string& remitente, const string& asunto, const string& cuerpo);
	/**
	Consulta el identificador del mensaje
	@return el identificador
	*/
	const MID id() const;
	/**
	Consulta el remitente del mensaje
	@return el remitente
	*/
	const string& remitente() const;
	/**
	Consulta el asunto del mensaje
	@return el asunto
	*/
	const string& asunto() const;
	/**
	Consulta el cuerpo del mensaje
	@return el cuerpo
	*/
	const string& cuerpo() const;
private:
	MID _id;            // identificador
	string _remitente;  // remitente
	string _asunto;     // asunto
	string _cuerpo;     // cuerpo
};


/**
Excepci�n se�alada cuando se trata de enviar un mensaje con un
identificador duplicado
*/
class EMIDDuplicado {};

/**
Excepci�n se�alada cuando se consulta un mensaje que no existe
*/
class ENoHayMensaje {};

class Foro {
public:
	/**
	Operacion 'crea'. Crea un foro vac�o.
	*/
	Foro();
	/**
	Env�a un mensaje al foro.
	@param id El identificador del mensaje
	@param remitente El remitente del mensaje
	@param asunto El asunto del mensaje
	@param cuerpo El cuerpo del mensaje
	@error EMIDDuplicado si el identificador del mensaje est� duplicado
	*/
	void envia_mensaje(MID id, const string& remitente, const string& asunto, const string& cuerpo);
	/**
	Recupera un mensaje
	@param id El identificador del mensaje a recuperar
	@return El mensaje recuperado
	@error ENoHayMensaje si no existe un mensaje con el identificador proporcionado
	*/
	const Mensaje& consulta_mensaje(MID id) const;

	/**
	Elimina un mensaje. Si el mensaje no existe, la operaci�n no tiene efecto.
	@param id El identificador del mensaje a eliminar
	*/
	void elimina_mensaje(MID id);
	/**
	Recupera una lista con los 'n' mensajes m�s recientes (o con todos los
	mensajes del foro, si en �ste hay menos de 'n' mensajes)
	@param n El n�mero de mensajes a recuperar
	@return La lista con los mensajes m�s recientes, en el orden de env�o al foro
	(primero los m�s recientes, luego los menos recientes)
	*/
	Lista<MID> recupera_mensajes(unsigned int n) const;
	/**
	Devuelve el n�mero de mensajes en el foro
	@return N�mero de mensajes
	*/
	unsigned int numero_mensajes() const;
private:
	Diccionario<MID, Mensaje> _mensajes;
	Lista<MID> _id;
	unsigned int _contador;
};

#endif