#include "cTorreControl.h"

cTorreControl::cTorreControl(short _tamHangar, short _tamlista, float largo, float ancho) {
	try {
		this->hangar = new cHangar(_tamHangar); 
		this->lista = new cListaAvion(_tamlista); 
		this->pista = new cPista(largo, ancho);
	}
	catch (bad_alloc& e) {
		cout << e.what() << endl;
	}
}

cTorreControl::~cTorreControl() { 
	delete this->hangar; 
	delete this->lista; 
	delete this->pista; 
}; 

void cTorreControl::imprimirDetalles()
{
	cout << "-----------------------------" << endl
		 << "Aviones fuera del hangar: " << endl;
	for (ushort i = 0; i < this->lista->cantActual; i++)
		cout << *this->lista[0][i];
	cout << "-----------------------------" << endl 
		 << "Aviones en el hangar: " << endl;
	for (ushort i = 0; i < this->hangar->getCantActual(); i++)
		cout << *this->hangar[0][i];
}


bool cTorreControl::operator!=(cAvion* avion)
{
	if(this->lista->noRepetido(avion))
			return true;
	return false;
}

void cTorreControl::autorizarDespegue(cAvion* _avion) {
	try {
		if (this->pista->getLuO() &&								 // control que la pista este libre
			!(*_avion > _avion->getModelo()) &&						 // control que no se exceda el limite de pasajeros (y quizas carga)
			*this != _avion &&										 // control que el avion este registrado	
			*_avion < _avion->getCombustible() &&					 // control que el combustible alcance	
			_avion->getHoraSalida() <= cFecha::getHorarioActual())   // control que el avion se encuentre en horario
		{	 									 
			this->hangar->despachar(_avion);						 // se despacha el avion del hangar
			this->pista->switchLuO();				                 // cambia el estado de la pista
			_avion->despegar();						                 // despegue del avion
			this->pista->switchLuO();								 // cambia el estado de la pista
		}
		else {
			throw error_despegue();
		}
	}
	catch (error_despegue& e) {
		cout << e.what();
	}
}	

void cTorreControl::autorizarAterrizaje(cAvion* _avion) {
	try {											
		if (*this->pista == _avion &&							     // control que el avion pueda aterrizar en la pista
			!(* _avion > _avion->getModelo()) &&	                 // control que no se exceda el limite de pasajeros (y quizas carga)
			_avion->getDestino() == "San Francisco")                 // control que el destino sea el de la torre
		{    		
			_avion->aterrizar();					                 // aterrizaje del avion
			this->pista->switchLuO();								 //el avion ocupa la pista a la hora de aterriza
			*this->pista = _avion;				                     // reserva el avion en la pista
			*this->lista + _avion;					                 // se agrega al registro de aviones a controlar
			autorizarEstacionamiento(_avion);						 // luego de aterrizar por protocolos de seguridad se decide mandar al hangar el avion, 
																	 // pero luego puede partir a la hora que desee
		}
		else
			throw error_aterrizaje();
	}
	catch (error_aterrizaje& e) {
		cout << e.what();
	}
}

void cTorreControl::autorizarEstacionamiento(cAvion* _avion) {
	_avion->estacionar();							                 // estacionamiento del avion
	this->hangar->almacenar(_avion);				                 // almacenamiento del avion
	this->pista->switchLuO();						                 // cambio de estado de la pista
}													
													
void cTorreControl::verificarHorario(cAvion* _avion) {
	try {
		if (*_avion < _avion->getCombustible())
			cout << "El avion se encuentra en horario" << endl;
		else
			throw error_incidente();
	}
	catch (error_incidente& e) {
		cout << e.what();
	}
}

