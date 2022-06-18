#include "cCombustible.h"

cCombustible::cCombustible(short hora, short minuto) {
	try {
		this->duracion = new cFecha(hora, minuto);
	}
	catch (bad_alloc& e) {
		cout << e.what();
	}
}

cCombustible::~cCombustible() { delete this->duracion; }