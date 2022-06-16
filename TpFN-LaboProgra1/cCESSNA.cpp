#include "cCESSNA.h"

ushort cCESSNA::velMaxDesCes = 200;
ushort cCESSNA::velMaxAteCes = 180;

cCESSNA::cCESSNA(string _ID, short _largoAvion, short _anchoAvion, string _destino,
	short _pasajerosActuales, eEstado _estado, short _velocidad, time_t _horaSalida,
	bool _controlAutomatico, short _cargaActual, bool _alerones) 
	: cAvion(_ID, _largoAvion, _anchoAvion, 1, _destino, _pasajerosActuales, _estado, _velocidad, _horaSalida)
{
	this->controlAutomatico = _controlAutomatico;
	this->cargaActual = _cargaActual;
	this->alerones = _alerones;
}

cCESSNA::~cCESSNA() { }
	
bool cCESSNA::operator>(cModelo* _modelo) {
	if (this->pasajerosActual > _modelo->getLimitePasajeros() || 
		this->cargaActual > _modelo->getLimiteCarga())
		return true;
	return false;
}

string cCESSNA::to_string() const {
	stringstream ss;

	ss << "Avion ID [" << this->ID << "]" << endl
		<< "Estado: " << this->estado << endl
		<< "Destino: " << this->destino << endl
		<< (this->horaSalida != 0 ? ctime(&this->horaSalida) : "El avion no se encuentra volando") << endl
		<< "Velocidad actual: " << this->velocidad << endl
		<< "Largo: " << this->largoAvion << "metros" << endl
		<< "Ancho: " << this->anchoAvion << "metros" << endl
		<< "Cantidad de helices: " << this->helice << endl
		<< "Cantidad actual de pasajeros: " << this->pasajerosActual << endl
		<< "Control automatico: " << this->controlAutomatico << endl
		<< "Carga actual: " << this->cargaActual << endl
		<< "Alerones: " << this->alerones << endl;
	
	return ss.str();
}

void cCESSNA::despegar() {
	// Implementrar logica para el despegue
}

void cCESSNA::estacionar() {
	// Implementar logica para el estacionamiento;
}

