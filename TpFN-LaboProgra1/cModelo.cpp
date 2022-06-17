#include "cModelo.h"

cModelo::cModelo(string _nombre, float _limiteCarga, float _aceleracion, short _limitePasajeros,
				 short hora, short minuto) :
	nombre(_nombre) 
	{
	// No realizo una verificacion para estos argumentos, dado que los inicia el programa en el constructor de cAvion
	this->limiteCarga = _limiteCarga;
	this->aceleracion = _aceleracion;
	this->limitePasajeros = _limitePasajeros;
	try {
		this->combustible = new cCombustible(hora, minuto);
	}
	catch (bad_alloc& e) {
		cout << e.what() << endl;
	}
}

cModelo::~cModelo() { delete this->combustible; }