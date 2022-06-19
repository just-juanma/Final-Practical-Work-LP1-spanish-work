#include "cHangar.h"

cHangar::cHangar(short _cantTotal) {
	this->almacenados = new cListaAvion(_cantTotal, true);
}

cHangar::~cHangar() {
	delete this->almacenados;
}

bool cHangar::Almacenar(cAvion* _avion)
{
	if (_avion) {
		this->almacenados->agregar(_avion);
		return true;
	}
	else {
		throw error_null_avion();
	}
	return false;
}

cAvion* cHangar::Despachar(short _pos)
{
	return this->almacenados[0][_pos];
}

int cHangar::buscarAvion(string ID)
{
	for (int i = 0; i < almacenados->getCantTotal(); i++) {
		string id = almacenados[0][i]->getID();
		if (id == ID) { 
			return i;
		}
	}
}

int cHangar::getCantActual() {
	return this->almacenados->getCantTotal();
}

bool cHangar::operator==(cAvion* avion)
{
	for (ushort i = 0; i < this->almacenados->getCantActual(); i++) {
		if (this->almacenados[0][i] == avion) {
			return true;
		}
	}
}


