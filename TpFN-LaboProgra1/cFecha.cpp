#include "cFecha.h"

cFecha::cFecha(short _hora, short _minuto) {
	this->horarioEsperado.tm_hour = _hora;
	this->horarioEsperado.tm_min = _minuto;
}

cFecha::~cFecha() { }
