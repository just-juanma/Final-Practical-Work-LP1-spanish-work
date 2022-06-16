#include "cListaAviones.h"



cListaAviones::cListaAviones(short _cantTotal,bool _checkEliminar ):cLista(_cantTotal, _checkEliminar) {
}


cListaAviones::~cListaAviones()
{
}

ushort cListaAviones::getcantTotal() const {
	return this->cantActual;
}