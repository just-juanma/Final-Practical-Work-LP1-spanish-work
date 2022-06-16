#include "cTorreControl.h"

cTorreControl::cTorreControl(ushort _tamHangar, ushort _tamlista) {
	this->hangar = new cHangar(_tamHangar); 
	this->lista = new cListaAvion(_tamlista);
	this->pista = NULL;
}

cTorreControl::~cTorreControl() {}; 

bool cTorreControl::asignarPista(cPista* _pista) {
	this->pista = _pista; 
}

bool cTorreControl::autorizarDespegue(cAvion* avion) {
	
	for (int i = 0; i < this->lista->getCantTotal(); i++) {
		if (*pista==avion) {
			*this->lista - avion;
			avion->despegar();
		}
		else {
			throw new exception("El avion no puede despegar hay un avion en la pista");
		}
	}
}

void cTorreControl::imprimirDetalles()
{
	stringstream slt;
	for (ushort i = 0; i < this->lista->cantActual; i++) {
		slt << this->lista[0][i]->imprimir();
	}
	for (ushort i = 0; i < this->hangar->getCantActual(); i++) {
		slt << this->lista[0][i]->imprimir();
	}
	cout << slt.str() << endl;
}

//bool cTorreControl::operator!=(cAvion* avion)
//{
//	for(ushort i=0;i<this->lista->cantActual;i++){
//		if (*this->lista[i][0] == avion) { error en esta linea
//			return false;
//		}
//	}
//	for (ushort i = 0; i < this->hangar->getCantActual(); i++) {
//		if (*this->hangar == avion) {
//			return false;
//		}
//	}
//	return true;
//}

bool cTorreControl::asignarPista(cAvion* avion)
{
	if (*this->pista == avion) {
		this->autorizarAterrizaje(avion);
	};
}


//bool cTorreControl::autorizarAterrizaje(cAvion* avion) {
//	
//	for (int i = 0; i < this->lista->getCantTotal(); i++) {
//		if(this->pista->getposicionFinal()<this->pista->getLargo()&&*pista==avion){
//			avion->switchEstado(aterrizando);
//			avion->aterrizar();
//			*this->lista+avion;
//	}
//	Hacer aca un switch de que quiere hacer el avion,Por ejemplo: 
//  definir si va al hangar o decide recargar combustible y luego despegar
//	
//}