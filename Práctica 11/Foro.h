#ifndef _FORO_H
#define _FORO_H

#include "lista.h"
#include "diccionario.h"
#include <string>
using namespace std;


/* Alias para el tipo de los identificadores de mensajes */
typedef unsigned int MID;

/**
Representación de los mensajes
*/
class Mensaje {
public:
	/**
	Construye un mensaje
	@param id El identificador del mensaje
	@param remitente El nombre del usuario que envía el mensaje
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
Excepción señalada cuando se trata de enviar un mensaje con un
identificador duplicado
*/
class EMIDDuplicado {};

/**
Excepción señalada cuando se consulta un mensaje que no existe
*/
class ENoHayMensaje {};

class Foro {
public:
	/**
	Operacion 'crea'. Crea un foro vacío.
	*/
	Foro();
	/**
	Envía un mensaje al foro.
	@param id El identificador del mensaje
	@param remitente El remitente del mensaje
	@param asunto El asunto del mensaje
	@param cuerpo El cuerpo del mensaje
	@error EMIDDuplicado si el identificador del mensaje está duplicado
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
	Elimina un mensaje. Si el mensaje no existe, la operación no tiene efecto.
	@param id El identificador del mensaje a eliminar
	*/
	void elimina_mensaje(MID id);
	/**
	Recupera una lista con los 'n' mensajes más recientes (o con todos los
	mensajes del foro, si en éste hay menos de 'n' mensajes)
	@param n El número de mensajes a recuperar
	@return La lista con los mensajes más recientes, en el orden de envío al foro
	(primero los más recientes, luego los menos recientes)
	*/
	Lista<MID> recupera_mensajes(unsigned int n) const;
	/**
	Devuelve el número de mensajes en el foro
	@return Número de mensajes
	*/
	unsigned int numero_mensajes() const;
private:
	Diccionario<MID, Mensaje> _mensajes;
	Lista<MID> _id;
	unsigned int _contador;
};

#endif