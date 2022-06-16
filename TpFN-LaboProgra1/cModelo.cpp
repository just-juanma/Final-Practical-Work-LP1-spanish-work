#include "cModelo.h"

cModelo::cModelo(string _nombre, float _limiteCarga, float _aceleracion, short _limitePasajeros,
				 short hora, short minuto) : nombre(_nombre) {
	this->limiteCarga = _limiteCarga;
	this->aceleracion = _aceleracion;
	this->limitePasajeros = _limitePasajeros;
	this->combustible = new cCombustible(hora, minuto);
}

cModelo::~cModelo() {
	delete this->combustible;
}