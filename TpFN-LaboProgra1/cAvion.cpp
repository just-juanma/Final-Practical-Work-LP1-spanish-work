#include "cAvion.h"

/// <seealso cref="https://en.cppreference.com/w/cpp/error/exception"/>
cAvion::cAvion(string _ID, float _largoAvion, float _anchoAvion, short _helice, string _destino,
	short _pasajerosActual, eEstado _estado, short _velocidad, time_t _horaSalida) :
	ID(_ID), 
	largoAvion(_largoAvion), 
	anchoAvion(_anchoAvion) 
	{
	this->estado = _estado;
	this->destino = _destino;
	this->velocidad = _velocidad;
	this->helice = _helice;
	this->pasajerosActual = _pasajerosActual;
	this->horaSalida = _horaSalida;
	try {
		if (this->ID == "01")      this->modelo = new cModelo("CESSNA C-210N CENTURION", float(200.6), 20, 10, 2, 10);
		else if (this->ID == "02") this->modelo = new cModelo("CESSNA C10T CC-PON", float(182.1), float(35.4), 9, 3, 21);
		else if (this->ID == "03") this->modelo = new cModelo("CESSNA P210N PARTICULAR", float(145), 50, 11, 0, 50);
		else if (this->ID == "04") this->modelo = new cModelo("CESSNA BULL-530 ", float(350.7), float(32.5), 12, 6, 15);
		else if (this->ID == "05") this->modelo = new cModelo("CESSNA A12 TCH", float(220.5), 15, 4, 1, 30);

		else if (this->ID == "06") this->modelo = new cModelo("BIPLANO 20-909", float(0), 40, 2, 0, 30);
		else if (this->ID == "07") this->modelo = new cModelo("BIPLANO 20-810", float(0), float(45.3), 1, 1, 15);
		else if (this->ID == "08") this->modelo = new cModelo("BIPLANO T-80", float(0), 22, 10, 1, 0);
		else if (this->ID == "09") this->modelo = new cModelo("BIPLANO T-30", float(0), float(18.1), 2, 0, 45);
		else if (this->ID == "10") this->modelo = new cModelo("BIPLANO Q100", float(0), 60, 5, 2, 10);
		else throw null_modelo();
	}
	catch (bad_alloc& e) {
		cout << e.what() << endl;
	}
	catch (null_modelo& e) {
		cout << e.what();
	}
}

cAvion::~cAvion() {	delete this->modelo; }

string cAvion::enumToString(eEstado _estado) const {
	switch (_estado)
	{
		case eEstado::desconocido: return "desconocido";
		case eEstado::despegando:  return "despegando";
		case eEstado::enVuelo:     return "en vuelo";
		case eEstado::aterrizando: return "aterrizando";
		case eEstado::estacionado: return "estacionado";
		default:				   return "desconocido";
	}
}

void cAvion::setEstado(eEstado _estado) {
	try {
		if (_estado) {
			this->estado = _estado;
		}
		else
			throw null_status();
	}
	catch (null_status& e) {
		cout << e.what();
	}
	return;
}

bool cAvion::operator<(cCombustible* _combustible) {
	try {
		if(this->horaSalida + _combustible->getDuracion()->getHorarioEsperado() >= cFecha::getHorarioActual())
			return true;
	}
	catch (invalid_argument& e) {
		cout << e.what();
	}
	return false;
}


istream& operator>>(istream& is, cAvion& avion) {
	string destinoAux = ""; short pasajerosActualAux = 0;
	cout << "Ingrese el destino del avion: " << endl;
	is >> destinoAux;
	cout << "Ingrese la cantidad de pasajeros actuales: " << endl;
	is >> pasajerosActualAux;
	try {
		avion.setDestino(destinoAux);
		avion.setPasajerosActuales(pasajerosActualAux);
	}
	catch (invalid_argument& e) {
		cout << e.what();
	}
	return is;
}