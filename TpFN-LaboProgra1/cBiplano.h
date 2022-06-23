#ifndef CBIPLANO_H
#define CBIPLANO_H
#include "gbl.h"
#include "cAvion.h"
#include "eEstado.h"

class cBiplano : public cAvion
{
public:

	/// <summary>
	/// Constructor parametrizado por defecto
	/// </summary>
	/// <param name="_ID">: ID del avion</param>
	/// <param name="_largoAvion">: Largo del avion</param>
	/// <param name="_anchoAvion">: Ancho del avion</param>
	/// <param name="_destino">: Destino del avion</param>
	/// <param name="_pasajerosActuales">: Cantidad de pasajeros actuales</param>
	/// <param name="_estado">: Estado del vuelo</param>
	/// <param name="_velocidad">: Velocidad actual del avion</param>
	/// <param name="_horaSalida">: Hora de salida del avion</param>
	/// <param name="_inclinacion">: Angulo de inclinacion del avion</param>
	cBiplano(string _ID = "", float _largoAvion = 0, float _anchoAvion = 0, string _destino = "",
		short _pasajerosActuales = 0, eEstado _estado = eEstado::desconocido, short _velocidad = 0, time_t _horaSalida = 0,
		float _inclinacion = 0);

	/// <summary>
	/// Destructor por defecto
	/// </summary>	
	~cBiplano();

	/// <summary>
	/// Aumenta su velocidad, su inclinacion y el estado cambian
	/// </summary>
	void despegar();

	/// <summary>
	/// Disminuye su velocidad y cambia su estado
	/// </summary>
	void aterrizar();

	/// <summary>
	/// Equilibra la inclinacion, los pasajeros y la velocidad descienden. Cambia su estado
	/// </summary>
	void estacionar();

	string to_string() const;

	bool operator>(cModelo* _modelo);

	static float getVelDes();
	
	static float getVelAte();

	/// <summary>
	/// Permite generar la salida de los datos del avion
	/// </summary>
	/// <returns>Flujo de salida</returns>
	friend ostream& operator<<(ostream& os, const cBiplano& biplano);

	/// <summary>
	/// Permite generar la entrada de los datos del avion
	/// </summary>
	/// <returns>Flujo de entrada</returns>
	friend istream& operator>>(istream& is, cBiplano& biplano);


protected:

	static ushort velMaxDesBip; // Velocidad maxima de despegue en Biplano
	static ushort velMaxAteBip; // Velocidad maxima de despegue en Biplano
	float inclinacion;

};

inline float cBiplano::getVelDes() { return cBiplano::velMaxDesBip; }

inline float cBiplano::getVelAte() { return cBiplano::velMaxAteBip; }

inline ostream& operator<<(ostream& os, const cBiplano& biplano) {	return os << biplano.to_string(); }

#endif // !CBIPLANO_H