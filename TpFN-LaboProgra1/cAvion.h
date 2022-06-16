#ifndef CAVION_H
#define CAVION_H
#include "gbl.h"
#include "eEstado.h"
#include "cModelo.h"

class cAvion
{
public:
	
	/// <summary>
	/// Constructor parametrizado por defecto
	/// Especialmente diseñado para aviones actualmente en vuelo
	/// </summary>
	/// <param name="_ID">: ID del avion</param>
	/// <param name="_largoAvion">: Largo del avion</param>
	/// <param name="_anchoAvion">: Ancho del avion</param>
	/// <param name="_helice">: Cantidad de helices que dispone el avion</param>
	/// <param name="_destino">: Destino del avion</param>
	/// <param name="_pasajerosActuales">: Cantidad de pasajeros actuales</param>
	/// <param name="_estado">: Estado del vuelo</param>
	/// <param name="_velocidad">: Velocidad actual del avion</param>
	/// <param name="_horaSalida">: Hora de salida del avion</param>
	cAvion(string _ID = "", short _largoAvion = 0, short _anchoAvion = 0, short _helice = 0, string _destino = "",
		   short _pasajerosActuales = 0, eEstado _estado = eEstado::desconocido, short _velocidad = 0, time_t _horaSalida = 0);
	
	/// <summary>
	/// Destructor por defecto
	/// </summary>	
	~cAvion();
	
	/// <summary>
	/// Obtiene la cantidad de pasajeros que debera ser informada a la torre de control
	/// </summary>
	/// <returns></returns>
	short getPasajerosActual() const;
	
	/// <summary>
	/// Obtiene el largo del avion
	/// </summary>
	/// <returns>Largo del avion</returns>
	short getLargoAvion() const;
	
	/// <summary>
	/// Obtiene el ancho del avion
	/// </summary>
	/// <returns>Ancho del avion</returns>
	short getAnchoAvion() const;
	
	/// <summary>
	/// Obtiene el estado del avion
	/// </summary>
	/// <returns>Estado actual del avion</returns>
	eEstado getEstado() const;
	
	/// <summary>
	/// Setea el destino del avion
	/// </summary>
	/// <param name="_destino">: Destino del avion</param>
	void setDestino(string _destino);
	
	/// <summary>
	/// Setea la cantidad actual de pasajeros
	/// </summary>
	/// <param name="_pasajerosActuales">: Cantidad actual de pasajeros</param>
	void setPasajerosActuales(short _pasajerosActuales);
	
	/// <summary>
	/// Setea velocidad actual del avion
	/// </summary>
	/// <param name="_velocidad">: Velocidad actual del avion</param>
	void setVelocidad(short _velocidad);
	
	/// <summary>
	/// Setea el modelo
	/// </summary>
	/// <param name="_modelo">: Modelo actual</param>
	void setModelo(cModelo* _modelo);
	
	/// <summary>
	/// Cambia el estado del avion
	/// </summary>
	/// <param name="_estado">: Estado a cambiar</param>
	void switchEstado(eEstado _estado);
	
	/// <summary>
	/// Genera los cambios necesarios para que el avion pueda despegar
	/// </summary>
	virtual void despegar() = 0;
	
	/// <summary>
	/// Genera los cambios necesarios para que el avion pueda aterrizar
	/// </summary>
	virtual void aterrizar() = 0;

	/// <summary>
	/// Genera los cambios necesarios para que el avion pueda estacionar
	/// </summary>
	virtual void estacionar() = 0;

	/// <summary>
	/// Segun el avion, concatena todos los datos en un solo string
	/// </summary>
	/// <returns>Cadena concatenada</returns>
	virtual string to_string() const = 0;
	
	/// <summary>
	/// Controla que un avion no este excedido de su capacidad de pasajeros
	/// En caso de CESSNA, verifica tambien que el peso no se exceda
	/// </summary>
	/// <param name="modelo">: Modelo del avion a comparar</param>
	/// <returns>True en caso que se exceda, false en caso contrario</returns>
	virtual bool operator>(cModelo* modelo) = 0;

	bool operator<(cCombustible* _combustible);
	
	/// <summary>
	/// Permite generar la salida de los datos del avion
	/// </summary>
	/// <returns>Flujo de salida</returns>
	friend ostream& operator<<(ostream& os, const cAvion& avion);
	
	/// <summary>
	/// Permite generar la entrada de los datos del avion
	/// </summary>
	/// <returns>Flujo de entrada</returns>
	friend istream& operator>>(istream& is, cAvion& avion);
	
protected:
	
	const short largoAvion;
	const short anchoAvion;
	const string ID;
	short helice;
	short pasajerosActual;
	short velocidad;
	eEstado estado;
	string destino;
	time_t horaSalida; 
	cModelo* modelo;
};

inline short cAvion::getPasajerosActual() const { return this->pasajerosActual; }

inline short cAvion::getLargoAvion() const { return this->largoAvion; }

inline short cAvion::getAnchoAvion() const { return this->anchoAvion; }

inline eEstado cAvion::getEstado() const { return this->estado; }

inline void cAvion::setDestino(string _destino) { this->destino = _destino; }

inline void cAvion::setPasajerosActuales(short _pasajerosActuales) { this->pasajerosActual = _pasajerosActuales; }

inline void cAvion::setVelocidad(short _velocidad) { this->velocidad = _velocidad; }

inline void cAvion::setModelo(cModelo* _modelo) { this->modelo = _modelo; }

inline ostream& operator<<(ostream& os, const cAvion& avion) { return os << avion.to_string() << endl; }

#endif // !CAVION_H
