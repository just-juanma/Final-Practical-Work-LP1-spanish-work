#pragma once
#include "cLista.h"
#include "cAvion.h"
class cListaAviones : public cLista<cAvion>
{
	friend class cTorreControl;
public:
	cListaAviones(short _cantTotal = MAX_LISTA, bool _checkEliminar = false);
	~cListaAviones();
	ushort getcantTotal() const ;
};

