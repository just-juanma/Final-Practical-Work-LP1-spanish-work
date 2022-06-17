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
	cBiplano(string _ID = "", short _largoAvion = 0, short _anchoAvion = 0, string _destino = "",
		short _pasajerosActuales = 0, eEstado _estado = eEstado::desconocido, short _velocidad = 0, time_t _horaSalida = 0,
		float _inclinacion = 0);
	
	/// <summary>
	/// Destructor por defecto
	/// </summary>	
	~cBiplano();

	/// <summary>
	/// Obtiene la velocidad de despegue, su inclinacion cambia
	/// </summary>
	void despegar();

	/// <summary>
	/// Disminuye sy velocidad para aterrizar
	/// </summary>
	void aterrizar();

	/// <summary>
	/// Sube los alerones y apaga el control automatico de estabilizacion de vuelo
	/// Los pasajeros descienden y se retira la carga
	/// </summary>
	void estacionar();

	bool operator>(cModelo* _modelo);

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

	string to_string() const;

protected:

	float inclinacion;
	static ushort velMaxDesBip; // Velocidad maxima de despegue en Biplano
	static ushort velMaxAteBip; // Velocidad maxima de despegue en Biplano

};

inline void cBiplano::aterrizar() { this->velocidad = velMaxAteBip; }

#endif // !CBIPLANO_H