#include "cCombustible.h"

cCombustible::cCombustible(short hora, short minuto) {
	this->duracionCombustible = new cFecha(hora, minuto);
}

cCombustible::~cCombustible() {
	delete this->duracionCombustible;
}