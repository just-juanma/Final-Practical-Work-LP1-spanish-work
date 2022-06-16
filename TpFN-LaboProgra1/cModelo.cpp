#include "cModelo.h"

cModelo::cModelo(string _nombre, float _limiteCarga, float _aceleracion, short _limitePasajeros) : nombre(_nombre) {
	this->limiteCarga = _limiteCarga;
	this->aceleracion = _aceleracion;
	this->limitePasajeros = _limitePasajeros;
}

cModelo::~cModelo() { }