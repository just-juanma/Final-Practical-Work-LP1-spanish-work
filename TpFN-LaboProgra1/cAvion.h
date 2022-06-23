#ifndef CAVION_H
#define CAVION_H
#include "gbl.h"
#include "eEstado.h"
#include "cModelo.h"
#include "cException.h"

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
	cAvion(string _ID = "", float _largoAvion = 0, float _anchoAvion = 0, short _helice = 0, string _destino = "",
		   short _pasajerosActuales = 0, eEstado _estado = eEstado::desconocido, short _velocidad = 0, time_t _horaSalida = 0);

	/// <summary>
	/// Destructor por defecto
	/// </summary>	
	~cAvion();
	
	time_t getHoraSalida() const;

	string getDestino() const;
	
	short getPasajerosActual() const;
	
	float getLargoAvion() const;

	float getAnchoAvion() const;
	
	eEstado getEstado() const;
	
	string getID() const;
	
	cModelo* getModelo() const;
	
	cCombustible* getCombustible() const;
	
	short getVelocidad() const;	
	
	float getAceleracion() const;

	void setDestino(string _destino);

	void setPasajerosActuales(short _pasajerosActuales);
	
	void setVelocidad(short _velocidad);
	
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
	
	string enumToString(eEstado _estado) const;

	void inputCleaning();

	/// <summary>
	/// Controla que un avion no este excedido de su capacidad de pasajeros
	/// En caso de CESSNA, verifica tambien que el peso no se exceda
	/// </summary>
	/// <param name="modelo">: Modelo del avion a comparar</param>
	/// <returns>True en caso que se exceda, false en caso contrario</returns>
	virtual bool operator>(cModelo* modelo) = 0;

	/// <summary>
	/// Verifica que el avion este en horario
	/// </summary>
	/// <param name="_combustible">: Combustible del avion</param>
	/// <returns></returns>
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
	
	const string ID;
	const float largoAvion;
	const float anchoAvion;
	short helice;
	short pasajerosActual;
	short velocidad;
	eEstado estado;
	string destino;
	time_t horaSalida; 
	cModelo* modelo;
};

inline void cAvion::inputCleaning() {
	int ch;
	while ((ch = getchar()) != '\n' && ch != EOF);
}

inline time_t cAvion::getHoraSalida() const { return horaSalida; }

inline string cAvion::getDestino() const { return this->destino; }

inline short cAvion::getVelocidad() const { return this->velocidad; }

inline float cAvion::getAceleracion() const { return this->modelo->getAceleracion(); }

inline cModelo* cAvion::getModelo() const { return this->modelo; }

inline cCombustible* cAvion::getCombustible() const { return this->modelo->getCombustible(); }

inline short cAvion::getPasajerosActual() const { return this->pasajerosActual; }

inline float cAvion::getLargoAvion() const { return this->largoAvion; }

inline float cAvion::getAnchoAvion() const { return this->anchoAvion; }

inline eEstado cAvion::getEstado() const { return this->estado; }

inline string cAvion::getID() const { return this->ID; }

inline void cAvion::setDestino(string _destino) { 
	if (_destino == "")
		throw invalid_argument("Error: El destino que se intenta setear es invalido\n");
	this->destino = _destino; 
}

inline void cAvion::setPasajerosActuales(short _pasajerosActuales) { 
	if (_pasajerosActuales <= 0)
		throw invalid_argument("Error: La cantidad de pasajeros que se intenta setear es invalida\n");
	this->pasajerosActual = _pasajerosActuales; 
}

inline void cAvion::setVelocidad(short _velocidad) {
	if (_velocidad < 0)
		throw invalid_argument("Error: La velocidad del avion que se intenta setear es invalida\n");
	this->velocidad = _velocidad; 
}

inline ostream& operator<<(ostream& os, const cAvion& avion) { return os << avion.to_string() << endl; }

#endif // !CAVION_H
