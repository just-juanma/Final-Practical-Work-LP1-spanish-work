#include "cBiplano.h"

ushort cBiplano::velMaxDesBip = 240;
ushort cBiplano::velMaxAteBip = 220;

cBiplano::cBiplano(string _ID, short _largoAvion, short _anchoAvion, string _destino,
	short _pasajerosActuales, eEstado _estado, short _velocidad, time_t _horaSalida,
	float _inclinacion) : 
	cAvion(_ID, _largoAvion, _anchoAvion, 2, _destino, _pasajerosActuales, _estado, _velocidad, _horaSalida) 
{
	this->inclinacion = _inclinacion;
}

cBiplano::~cBiplano() { }

bool cBiplano::operator>(cModelo* _modelo) {
	if (this->pasajerosActual > _modelo->getLimitePasajeros())
		return true;
	return false;
}

void cBiplano::despegar() {
	//Implementrar logica para el despegue
}

void cBiplano::estacionar() {
	//Implementar logica para el estacionamiento
}

string cBiplano::to_string() const {
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
		<< "Inclinacion del avion: " << this->inclinacion << endl;	
	return ss.str();
}