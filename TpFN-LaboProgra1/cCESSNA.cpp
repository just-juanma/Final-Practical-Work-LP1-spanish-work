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
	if (this->pasajerosActual < _modelo->getLimitePasajeros() &&
		this->cargaActual < _modelo->getLimiteCarga())
		return true;
	return false;
}

void cCESSNA::despegar() {
	setEstado(despegando);
	this->horaSalida = cFecha::getHorarioActual();
	this->velocidad = velMaxDesCes;
	this->alerones = false;
	this->controlAutomatico = true;
}

void cCESSNA::aterrizar() {
	setEstado(aterrizando);
	this->velocidad = velMaxAteCes;
	this->alerones = true;
}

void cCESSNA::estacionar() {
	setEstado(estacionado);
	this->horaSalida = 0;
	this->velocidad = 0;
	this->alerones = false;
	this->controlAutomatico = false;
	this->pasajerosActual = 0;
	this->cargaActual = 0;
}

istream& operator>>(istream& is, cCESSNA& CESSNA) {
	tm aux;
	cout << "Ingrese el destino del CESSNA: " << endl;
	getline(is, CESSNA.destino);
	cout << "Ingrese la cantidad de pasajeros actuales: " << endl;
	try {
		is >> CESSNA.pasajerosActual;
		if (isalpha(CESSNA.pasajerosActual)) {
			CESSNA.pasajerosActual = 0;
			throw error_input();
		}
	}
	catch (error_input& e) {
		cout << e.what();
	}
	cout << "Ingrese la cantidad de carga actual (en kg): " << endl;
	is >> CESSNA.cargaActual;
	CESSNA.horaSalida = cFecha::getHorarioActual();
	aux = *localtime(&CESSNA.horaSalida);
	cout << "- Ingrese hora y minuto de salida/llegada (Del dia de la fecha) -" << endl;
	try
	{
		cout << "Ingrese la hora de salida: " << endl;
		is >> aux.tm_hour;
		if (isalpha(aux.tm_hour)) {
			aux.tm_hour = 0;
			throw error_input();
		}
		cout << "Ingrese los minutos de salida: " << endl;
		is >> aux.tm_min;
		if (isalpha(aux.tm_min)) {
			aux.tm_min = 0;
			throw error_input();
		}
	}
	catch (const std::exception&)
	{

	}
	
	CESSNA.inputCleaning();
	CESSNA.horaSalida = mktime(&aux);
	try {
		if (!(CESSNA < CESSNA.getCombustible())) {
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
		<< "Largo: " << this->largoAvion << " metros" << endl
		<< "Ancho: " << this->anchoAvion << " metros" << endl
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