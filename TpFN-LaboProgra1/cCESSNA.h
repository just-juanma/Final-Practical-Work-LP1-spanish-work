#ifndef CCESSNA_H
#define CCESNA_H
#include "gbl.h"
#include "cAvion.h"

class cCESSNA : public cAvion
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
	/// <param name="_alerones">: Alerones prendidos (true) o apagados (false)</param>
	/// <param name="_controlAutomatico">: Control automatico prendido (true) o apagado (false)</param>
	/// <param name="_cargaActual">: Cantidad de carga</param>
	/// <param name="_alerones">: Alerones subidos (true) o bajos (false)</param>
	cCESSNA(string _ID = "", float _largoAvion = 0, float _anchoAvion = 0, string _destino = "",
		short _pasajerosActuales = 0, eEstado _estado = eEstado::desconocido, short _velocidad = 0, time_t _horaSalida = 0,
		bool _controlAutomatico = false, short _cargaActual = 0, bool _alerones = false);
	
	/// <summary>
	/// Destructor por defecto
	/// </summary>	
	~cCESSNA();

	short getCargaActual() const;

	void setCargaActual(float _cargaActual);
	
	/// <summary>
	/// Aumenta su velocidad, baja los alerones y prende el control automatico de estabilizacion de vuelo
	/// </summary>
	void despegar();

	/// <summary>
	/// Disminuye su velocidad
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
	friend ostream& operator<<(ostream& os, const cCESSNA& CESSNA);

	/// <summary>
	/// Permite generar la entrada de los datos del avion
	/// </summary>
	/// <returns>Flujo de entrada</returns>
	friend istream& operator>>(istream& is, cCESSNA& CESSNA);
	
	string to_string() const;

protected:

	static ushort velMaxDesCes; // Velocidad Maxima de Despegue en CESSNA
	static ushort velMaxAteCes; // Velocidad Maxima de Aterrizaje en CESSNA
	bool alerones;
	bool controlAutomatico;
	short cargaActual;
};

inline short cCESSNA::getCargaActual() const { return this->cargaActual; }

inline void cCESSNA::setCargaActual(float _cargaActual) { 
	if(_cargaActual < 0)
		throw invalid_argument("Error: La carga del avion que se intenta setear es invalida\n");
	this->cargaActual = _cargaActual; 
}

inline ostream& operator<<(ostream& os, const cCESSNA& CESSNA) { return os << CESSNA.to_string(); }

#endif // !CCESSNA_H