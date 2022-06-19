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

cAvion* cHangar::despachar(short _pos)
{
	cAvion* aux = this->almacenados[0][_pos];
	*this->almacenados - almacenados[0][_pos];
	return aux;
}

int cHangar::buscarAvion(string ID)
{
	for (ushort i = 0; i < almacenados->getCantTotal(); i++) {
		if (almacenados[0][i]->getID() == ID) {
			return i;
		}
	}
	return -1;
}

bool cHangar::operator==(cAvion* avion)
{
	for (ushort i = 0; i < this->almacenados->getCantActual(); i++) {
		if (this->almacenados[0][i] == avion) {
			return true;
		}
	}
	return false;
}


