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
		if (this->ID == "01")      this->modelo = new cModelo("CESSNA C-210N CENTURION", float(200.6), 1, 10, 2, 10);
		else if (this->ID == "02") this->modelo = new cModelo("CESSNA C10T CC-PON", float(182.1), float(1.3), 9, 3, 21);
		else if (this->ID == "03") this->modelo = new cModelo("Cessna P210N Particular", float(170.3), float(1.2), 11, 0, 50);
		// Bato: seguir con 7 ID mas, tienen que haber modelos para 10 aviones (5 CESSNA y 5 Biplanos)
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

void cAvion::switchEstado(eEstado _estado) {
	try {
		if (_estado == eEstado::despegando) {
			this->estado = eEstado::enVuelo;
		}
		else if (_estado == eEstado::enVuelo) {
			this->estado = eEstado::aterrizando;
		}
		else if (_estado == eEstado::aterrizando) {
			this->estado = eEstado::estacionado;
		}
		else if (_estado == eEstado::estacionado)
		{
			this->estado = eEstado::despegando;
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