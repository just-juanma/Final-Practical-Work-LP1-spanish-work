#include "cCombustible.h"

cCombustible::cCombustible() { 
	this->duracionCombustible = new cFecha;
}

cCombustible::~cCombustible() {
	delete this->duracionCombustible;
}