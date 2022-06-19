#include "cPista.h"

cPista::cPista(float _largo, float _ancho) : 
	largo(_largo), 
	ancho(_ancho) { }

cPista::~cPista() { };

bool cPista::operator==(cAvion* avion) {
	return (this->largo <= avion->getLargoAvion() && this->ancho <= avion->getAnchoAvion() && this->getLuO());
}


float cPista::getTiempoIdeal(cAvion* avion) const {
	return (avion->getVelocidad() / avion->getAceleracionAvion());
};
float cPista::getPosicionFinalAvion(cAvion* avion) { 
	float tiempo = this->getTiempoIdeal(avion);
	return (avion->getVelocidad() * tiempo - 0.5 * avion->getAceleracionAvion() * tiempo * tiempo);
}