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
	try {
		if (_avion) {
			*this->almacenados + _avion;
			return true;
		}
		else {
			throw error_null_avion();
		}
	}
	catch (error_null_avion& e) {
		cout << e.what();
	}
	return false;
}

void cHangar::despachar(cAvion* _avion) { 
	try {
		if(!_avion)
			throw error_null_avion();
		*this->almacenados - _avion;
	}
	catch (error_null_avion& e) {
		cout << e.what();
	}
}
