#include "cCombustible.h"

cCombustible::cCombustible(short hora, short minuto) {
	try {
		fallaCombustible(&hora, &minuto);
		this->duracion = new cFecha(hora, minuto);
	}
	catch (bad_alloc& e) {
		cout << e.what();
	}
}

void cCombustible::fallaCombustible(short* hora, short* minuto) {
	int rNumber = rand() % 51;
	if (rNumber == 0) {
		hora -= rand() % (*hora + 1);
		minuto -= rand() % (*minuto + 1);
	}
}

cCombustible::~cCombustible() { delete this->duracion; }