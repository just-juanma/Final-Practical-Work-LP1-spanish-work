#include "cBiplano.h"

ushort cBiplano::velMaxDesBip = 240;
ushort cBiplano::velMaxAteBip = 220;

cBiplano::cBiplano(string _ID, float _largoAvion, float _anchoAvion, string _destino,
	short _pasajerosActuales, eEstado _estado, short _velocidad, time_t _horaSalida,
	float _inclinacion) : 
	cAvion(_ID, _largoAvion, _anchoAvion, 2, _destino, _pasajerosActuales, _estado, _velocidad, _horaSalida) 
{
	this->inclinacion = _inclinacion;
}

cBiplano::~cBiplano() { }

void cBiplano::despegar() {
	switchEstado(this->estado);
	this->velocidad = velMaxDesBip;
	this->inclinacion = 25;
}

void cBiplano::aterrizar() {
	switchEstado(this->estado);
	this->velocidad = velMaxAteBip;
}

void cBiplano::estacionar() {
	switchEstado(this->estado);
	this->velocidad = 0;
	this->inclinacion = 0;
	this->pasajerosActual = 0;
}

bool cBiplano::operator>(cModelo* _modelo) {
	if (_modelo->getLimitePasajeros()> this->pasajerosActual)
		return true;
	return false;
}

istream& operator>>(istream& is, cBiplano& biplano) {
	tm aux;
	cout << "Ingrese el destino del Biplano: " << endl;
	is >> biplano.destino;
	biplano.inputCleaning();
	cout << "Ingrese la cantidad de pasajeros actuales: " << endl;
	try {
		int aux; is >> aux;
		if (isdigit(aux))
			biplano.pasajerosActual = aux;
		else throw error_input();
	}
	catch (error_input& e)
	{
		cout << e.what();
	}
	biplano.horaSalida = cFecha::getHorarioActual();
	aux = *localtime(&biplano.horaSalida);
	cout << "Ingrese la hora de salida: " << endl;
	is >> aux.tm_hour;
	cout << "Ingrese los minutos de salida: " << endl;
	is >> aux.tm_min;
	biplano.horaSalida = mktime(&aux);
	try {
		if (biplano < biplano.getCombustible()) {	
			biplano.estado = eEstado::aterrizando;
			biplano.estacionar();
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

string cBiplano::to_string() const {
	stringstream ss;
	ss	<< "-----------------------------" << endl
		<< "Avion ID [" << this->ID << "]" << endl
		<< "Largo: " << this->largoAvion << "metros" << endl
		<< "Ancho: " << this->anchoAvion << "metros" << endl
		<< "Cantidad de helices: " << this->helice << endl
		<< "Estado: " << enumToString(this->estado) << endl;	
		if (this->estado == eEstado::enVuelo) {
	ss		<< "Destino: " << this->destino << endl
			<< "Hora de salida: " << ctime(&this->horaSalida) << endl
			<< "Velocidad actual: " << this->velocidad << endl
			<< "Cantidad actual de pasajeros: " << this->pasajerosActual << endl
			<< "Inclinacion actual del avion: " << this->inclinacion << endl;			
		}
		
	return ss.str();
}