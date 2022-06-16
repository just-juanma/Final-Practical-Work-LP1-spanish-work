#include "cFecha.h"

cFecha::cFecha() { 
	this->horarioEsperado.tm_hour = 0;
	this->horarioEsperado.tm_min = 0;
}

cFecha::~cFecha() { }

void cFecha::setHorarioEsperado(short hora, short minuto) {
	this->horarioEsperado.tm_hour = hora;
	this->horarioEsperado.tm_min = minuto;
}