#include "cCESSNA.h"

ushort cCESSNA::velMaxDesCes = 200;
ushort cCESSNA::velMaxAteCes = 180;

cCESSNA::cCESSNA(string _ID, float _largoAvion, float _anchoAvion, string _destino,
	short _pasajerosActuales, eEstado _estado, short _velocidad, time_t _horaSalida,
	bool _controlAutomatico, float _cargaActual, bool _alerones) : 
	cAvion(_ID, _largoAvion, _anchoAvion, 1, _destino, _pasajerosActuales, _estado, _velocidad, _horaSalida)
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

void cCESSNA::despegar() {
	switchEstado(this->estado);
	this->horaSalida = cFecha::getHorarioActual();
	this->velocidad = velMaxDesCes;
	this->alerones = false;
	this->controlAutomatico = true;
}

void cCESSNA::aterrizar() {
	switchEstado(this->estado);
	this->velocidad = velMaxAteCes;
}

void cCESSNA::estacionar() {
	switchEstado(this->estado);
	this->horaSalida = 0;
	this->velocidad = 0;
	this->alerones = true;
	this->controlAutomatico = false;
	this->pasajerosActual = 0;
	this->cargaActual = 0;
}

istream& operator>>(istream& is, cCESSNA& CESSNA) {
	float cargaActualAux = 0;
	cout << "Ingrese la carga actual: " << endl;
	is >> cargaActualAux;
	try {
		CESSNA.setCargaActual(cargaActualAux);
	}
	catch (invalid_argument& e) {
		cout << e.what() << endl;
	}
	return is;
}

string cCESSNA::to_string() const {
	stringstream ss;

	ss  << "-----------------------------" << endl
		<< "Avion ID [" << this->ID << "]" << endl
		<< "Largo: " << this->largoAvion << "metros" << endl
		<< "Ancho: " << this->anchoAvion << "metros" << endl
		<< "Cantidad de helices: " << this->helice << endl
		<< "Estado: " << enumToString(this->estado) << endl;
		if (this->estado == eEstado::enVuelo) {
	ss	    << "Destino: " << this->destino << endl
			<< "Hora de salida: " << ctime(&this->horaSalida) << endl
			<< "Velocidad actual: " << this->velocidad << endl
			<< "Cantidad actual de pasajeros: " << this->pasajerosActual << endl
			<< "Control automatico: " << this->controlAutomatico << endl
			<< "Carga actual: " << this->cargaActual << endl
			<< "Alerones: " << this->alerones << endl;
	    }
	return ss.str();
}