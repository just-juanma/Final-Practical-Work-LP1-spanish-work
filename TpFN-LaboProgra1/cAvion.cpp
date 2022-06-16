#include "cAvion.h"

cAvion::cAvion(string _ID, short _largoAvion, short _anchoAvion, short _helice, string _destino,
	short _pasajerosActual, eEstado _estado, short _velocidad, time_t _horaSalida) :
	ID(_ID), largoAvion(_largoAvion), anchoAvion(_anchoAvion) {
	this->estado = _estado;
	this->helice = _helice;
	this->destino = _destino;
	this->pasajerosActual = _pasajerosActual;
	this->velocidad = _velocidad;
	this->horaSalida = _horaSalida;
	this->modelo = NULL;
}

cAvion::~cAvion() {	}

void cAvion::switchEstado(eEstado _estado) {
	if (_estado == eEstado::enVuelo) {
		_estado = eEstado::aterrizando;
	}
	else if (_estado == eEstado::despegando) {
		_estado = eEstado::enVuelo;
	}
	else if (_estado == eEstado::aterrizando) {
		//this->estado = eEstado::desconocido; chequear que se hace aca -----------------------------------------
	}
}

bool cAvion::operator<(cCombustible* _combustible) {
	if(this->horaSalida + _combustible->getDuracion()->getHorarioEsperado() >= cFecha::getHorarioActual())
		return true;
	return false;
}

istream& operator>>(istream& is, cAvion& avion) {	
	cout << "Ingrese el destino del avion: " << endl;
	is >> avion.destino;
	cout << "Ingrese la cantidad de pasajeros actuales: " << endl;
	is >> avion.pasajerosActual;
	return is;
}
