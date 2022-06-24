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
	setEstado(despegando);
	this->velocidad = velMaxDesBip;
	this->inclinacion = 25;
}

void cBiplano::aterrizar() {
	setEstado(aterrizando);
	this->velocidad = velMaxAteBip;
}

void cBiplano::estacionar() {
	setEstado(estacionado);
	this->velocidad = 0;
	this->inclinacion = 0;
	this->pasajerosActual = 0;
}

bool cBiplano::operator>(cModelo* _modelo) {
	if (this->pasajerosActual < _modelo->getLimitePasajeros())
		return true;
	return false;
}

istream& operator>>(istream& is, cBiplano& biplano) {
	tm aux;
	cout << "Ingrese el destino del Biplano: " << endl;
	getline(is, biplano.destino);
	cout << "Ingrese la cantidad de pasajeros actuales: " << endl;
	try {
		is >> biplano.pasajerosActual;
			if (isalpha(biplano.pasajerosActual)) {
				biplano.pasajerosActual = 0;
				throw error_input();
			}
	}
	catch (error_input& e) {
		cout << e.what();
	}

	biplano.horaSalida = cFecha::getHorarioActual();
	aux = *localtime(&biplano.horaSalida);
	cout << "- Ingrese hora y minuto de salida (Del dia de la fecha) -" << endl;
	cout << "Ingrese la hora (solo hh): " << endl;
	is >> aux.tm_hour;
	cout << "Ingrese los minutos (solo mm): " << endl;
	is >> aux.tm_min;
	biplano.horaSalida = mktime(&aux);
	biplano.inputCleaning();
	try {
		if (!(biplano < biplano.getCombustible())) {	
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
			ss << "Destino: " << this->destino << endl;
			ss << "Hora de salida: " << ctime(&this->horaSalida) << endl;
			ss << "Velocidad actual: " << this->velocidad << endl;
			ss << "Cantidad actual de pasajeros: " << this->pasajerosActual << endl;
			ss << "Inclinacion actual del avion: " << this->inclinacion << endl;
		}
		
	return ss.str();
}