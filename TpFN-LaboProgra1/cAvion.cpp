#include "cAvion.h"

cAvion::cAvion(string _ID, short _largoAvion, short _anchoAvion, short _helice, string _destino,
	short _pasajerosActual, eEstado _estado, short _velocidad, time_t _horaSalida) :
	ID(_ID), 
	largoAvion(_largoAvion), 
	anchoAvion(_anchoAvion) 
	{
	this->estado = _estado;
	this->destino = _destino;
	try {
		if(_helice <= 0 || pasajerosActual <= 0 || velocidad < 0 || horaSalida <= 0)
			throw invalid_argument("Error: Argumentos invalidos en el constructor de cAvion\n");
		this->velocidad = _velocidad;
		this->helice = _helice;
		this->pasajerosActual = _pasajerosActual;
		this->horaSalida = _horaSalida;
		if (this->ID == "01")      this->modelo = new cModelo("CESSNA C-210N CENTURION", 200.6, 1, 10, 2, 10);
		else if (this->ID == "02") this->modelo = new cModelo("CESSNA C10T CC-PON", 182.1, 1.3, 9, 3, 21);
		else if (this->ID == "03") this->modelo = new cModelo("Cessna P210N Particular", 170.3, 1.2, 11, 0, 50);
		// Bato: seguir con 7 ID mas, tienen que haber modelos para 10 aviones (5 CESSNA y 5 Biplanos)
		else throw null_modelo();
	}
	catch (invalid_argument &e) {
		cout << e.what();
	}
	catch (bad_alloc& e) {
		cout << e.what();
	}
	catch (null_modelo& e) {
		cout << e.what();
	}
}

cAvion::~cAvion() {	
	delete this->modelo;
}

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
	try {
		if(this->horaSalida + _combustible->getDuracion()->getHorarioEsperado() >= cFecha::getHorarioActual())
			return true;
		return false;
	}
	catch (invalid_argument& e) {
		cout << e.what();
	}
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