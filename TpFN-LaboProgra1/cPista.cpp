#include "cPista.h"

cPista::cPista(float _largo, float _ancho) : 
	largo(_largo), 
	ancho(_ancho) { }

cPista::~cPista() { };

bool cPista::operator==(cAvion* avion) {
	
	if (this->largo <= avion->getLargoAvion() && 
		this->ancho <= avion->getAnchoAvion() &&
		this->getLuO() &&
		getPosicionFinalAvion(avion) < this->largo)
		return true;
	return false;
}

float cPista::getPosicionFinalAvion(cAvion* avion) { 
	float tiempo = this->getTiempoIdeal(avion);
	return (avion->getVelocidad() * tiempo - 0.5 * avion->getAceleracion() * tiempo * tiempo);
}