#include "cFecha.h"
 
time_t cFecha::local = time(&local);

cFecha::cFecha() { 
	this->horarioEsperado.tm_hour = 0;
	this->horarioEsperado.tm_min = 0;
}

cFecha::~cFecha() { }

void cFecha::setHorarioEsperado(short hora, short minuto) {
	this->horarioEsperado.tm_hour = hora;
	this->horarioEsperado.tm_min = minuto;
}