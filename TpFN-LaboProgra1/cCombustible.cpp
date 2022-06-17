#include "cCombustible.h"

cCombustible::cCombustible(short hora, short minuto) {
	this->duracion = new cFecha(hora, minuto);
}

cCombustible::~cCombustible() { delete this->duracion; }