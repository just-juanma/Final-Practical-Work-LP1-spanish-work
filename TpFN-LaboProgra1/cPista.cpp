#include "cPista.h"

//cPista::cPista(short _largo = MAX_PISTA, short _ancho = MAX_PISTA) {
//	this->largo = _largo; 
//	this->ancho = _ancho;
//}
//
//cPista::~cPista();
//
//bool cPista::operator==(cAvion* avion) {
//	return (this->largo <= avion->getLargo() && this->ancho <= avion->getAncho());
//}
//
//ushort cPista::getVelocidad(cAvion* avion) {
//	//Implementar logica de MRUV y fisica 
//}
//
//float cPista::getTiempoIdeal(cAvion* avion) const {
//	return (avion->getVelocidad() / avion->getAceleracion());
//};
//float cPista::getPosicionFinalAvion(cAvion* avion) { 
//	float tiempo = this->getTiempoIdeal(avion);
//	return (avion->getVelocidad() * tiempo - 0.5 * avion->getAceleracion() * tiempo * tiempo);
//}