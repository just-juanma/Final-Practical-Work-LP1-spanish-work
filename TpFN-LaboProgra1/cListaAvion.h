#ifndef CLISTAAVION_H
#define CLISTAAVION_H
#include "gbl.h"
#include "cLista.h"
#include "cAvion.h"

class cListaAvion : public cLista<cAvion>
{
	friend class cTorreControl;
	
public:
	
	/// <summary>
	/// Constructor parametrizado por defecto
	/// </summary>
	/// <param name="_cantTotal">: Cantidad total de elementos</param>
	/// <param name="_checkEliminar">: se pretende eliminar los punteros internos? si (true)/no (false)</param>
	cListaAvion(short _cantTotal = MAX_LISTA, bool _checkEliminar = false);
	
	~cListaAvion();
	
	short getCantTotal() const;
	
	short getCantActual() const;
	
	string getID(int pos) const;
	
	bool repetido(cAvion* avion);

	bool operator ==(cAvion* avion);
private: 
	
}
inline cListaAvion::cListaAvion(short _cantTotal, bool _checkEliminar) : cLista(_cantTotal, _checkEliminar) { }

inline cListaAvion::~cListaAvion() { }

inline short cListaAvion::getCantTotal() const { return cantTotal; }

inline short cListaAvion::getCantActual() const { return cantActual; }

inline bool cListaAvion::repetido(cAvion* avion) { return noRepetido(avion); }

inline bool cListaAvion::operator==(cAvion* avion)
{
	for (ushort i = 0; i < this->cantActual; i++) {
		if (this->lista[0][i].getID() == avion->getID()) {
			return true;
		}
	}
	return false;
}

//inline string cListaAvion::getID(int _pos) const { return this->lista[0]->getID(); }

#endif // !CLISTAAVION_H