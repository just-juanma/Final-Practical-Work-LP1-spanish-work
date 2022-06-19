#include "cTorreControl.h"

cTorreControl::cTorreControl(ushort _tamHangar, ushort _tamlista) {
	this->hangar = new cHangar(_tamHangar); 
	this->lista = new cListaAvion(_tamlista); 
	this->pista = NULL;
}

cTorreControl::~cTorreControl() { }; 


bool cTorreControl::autorizarDespegue(cAvion* avion) {
	
	for (int i = 0; i < this->lista->getCantTotal(); i++) {
		if (*pista == avion) {
			*this->lista - avion;
			avion->despegar();
		}
		else {
			throw exception("El avion no puede despegar hay un avion en la pista");
		}
	}
}

void cTorreControl::imprimirDetalles()
{
	stringstream slt;
	for (ushort i = 0; i < this->lista->cantActual; i++) {
		slt << this->lista[0][i]->to_string(); 
	}
	for (ushort i = 0; i < this->hangar->getCantActual(); i++) {
		slt << this->lista[0][i]->to_string(); 
	}
	cout << slt.str() << endl;
}

bool cTorreControl::operator!=(cAvion* avion)
{
	for(ushort i=0;i<this->lista->cantActual;i++){
		if (this->lista[i][0]->getID() == avion->getID()) {
			return false;
		}
	}
	for (ushort i = 0; i < this->hangar->getCantActual(); i++) {
		if (*this->hangar == avion) {
			return false;
		}
	}
	return true;
}

void cTorreControl::setPista(cPista* _pista) {
	this->pista = _pista;
}

bool cTorreControl::asignarPistaAvion(cAvion* avion) 
{
	if (*this->pista == avion) {
		this->autorizarAterrizaje(avion);
	};
}


bool cTorreControl::autorizarAterrizaje(cAvion* _avion) {
	
	for (int i = 0; i < this->lista->getCantTotal(); i++) {
		if (this->pista->getPosicionFinalAvion(_avion) < this->pista->getLargoPista() && *pista == _avion&&this->pista->getLuO()) {
			_avion->aterrizar();
			pista->switchLuO();
			*this->lista + _avion;
			if (hangar->Almacenar(_avion)) {
				pista->switchLuO();
				return true;
			}
			else {
				throw exception("El avion no pudo ser almacenado");
			}
		}
		else {
			throw exception("El avion no puede aterrizar hay un avion en la pista");
		}
	}
}

bool  cTorreControl::autorizarDespegue(cAvion* _avion) {
	for (int i = 0; i < this->lista->getCantTotal(); i++) {
		if (pista->getLuO()) {
			short avi = hangar->buscarAvion(_avion->getID());
			*this->lista - _avion;
			*this->hangar->Despachar(avi); //averigaur si se decide devolver el avion despachado
			_avion->despegar();
			pista->switchLuO();
			return true;
		}
		else {
			throw error_pista_ocupada();
			return false;
		}
	}
	return false;
}