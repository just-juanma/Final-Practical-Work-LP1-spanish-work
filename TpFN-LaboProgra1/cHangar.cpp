#include "cHangar.h"

cHangar::cHangar(short _cantTotal) {
	try {
		this->almacenados = new cListaAvion(_cantTotal, true);
	}
	catch (bad_alloc& e) {
		cout << e.what() << endl;
	}
}

cHangar::~cHangar() { delete this->almacenados; }

bool cHangar::almacenar(cAvion* _avion)
{
	if (_avion) {
		*this->almacenados + _avion;
		return true;
	}
	else {
		throw error_null_avion();
	}
	return false;
}

void cHangar::despachar(cAvion* avion) { *this->almacenados - avion; }
