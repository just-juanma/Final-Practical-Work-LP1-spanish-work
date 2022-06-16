#include "cHangar.h"

cHangar::cHangar(short _cantTotal) {
	this->almacenados = new cListaAvion(_cantTotal, true);
}

cHangar::~cHangar() {
	delete this->almacenados;
}

void cHangar::Almacenar(cAvion* _avion)
{
	this->almacenados->agregar(_avion);
}

cAvion* cHangar::Despachar(short _pos)
{
	return this->almacenados[0][_pos];
}

//int cHangar::buscarAvion(string ID)
//{
//	for (int i = 0; i < almacenados->getCantTotal(); i++) {
//		if (this->almacenados[0][i].getID() == ID) { //eror aca
//			return i;
//		}
//	}
//}

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
