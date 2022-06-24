#include "cFecha.h"

cFecha::cFecha(short _hora, short _minuto) {
	time_t aux = cFecha::getHorarioActual();
	horarioEsperado = *localtime(&aux);
	this->horarioEsperado.tm_hour = _hora;
	this->horarioEsperado.tm_min = _minuto;
}

cFecha::~cFecha() { }
