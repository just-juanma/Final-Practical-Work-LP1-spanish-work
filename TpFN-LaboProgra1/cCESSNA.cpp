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
	if ((this->pasajerosActual > _modelo->getLimitePasajeros() || this->pasajerosActual < 0) ||
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
	tm aux;
	cout << "Ingrese el destino del CESSNA: " << endl;
	is >> CESSNA.destino;
	cout << "Ingrese la cantidad de pasajeros actuales: " << endl;
	try {
		int aux; is >> aux;
		if (int(aux)!=aux && !isalpha(aux))
			CESSNA.pasajerosActual = aux;
		else throw error_input();
		}
			catch (error_input& e)
			{
				cout << e.what();
			}
	cout << "Ingrese la cantidad de carga actual (en kg): " << endl;
	is >> CESSNA.cargaActual;
	CESSNA.horaSalida = cFecha::getHorarioActual();
	aux = *localtime(&CESSNA.horaSalida);
	cout << "Ingrese la hora de salida: " << endl;
	is >> aux.tm_hour;
	cout << "Ingrese los minutos de salida: " << endl;
	is >> aux.tm_min;
	CESSNA.inputCleaning();
	CESSNA.horaSalida = mktime(&aux);
	try {
		if (CESSNA < CESSNA.getCombustible()) {
			CESSNA.estado = eEstado::aterrizando;
			CESSNA.estacionar();
		}
		else {
			throw invalid_argument("Error: la hora de partida no es valida");
		}
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