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

	short getCantActual() const;

	/// <summary>
	/// Checkea que el avion no se encuentre repetido
	/// </summary>
	/// <param name="_avion">: Avion a buscar</param>
	/// <returns></returns>
	bool operator==(cAvion* _avion);

};

inline cListaAvion::cListaAvion(short _cantTotal, bool _checkEliminar) : cLista(_cantTotal, _checkEliminar) { }

inline cListaAvion::~cListaAvion() { }

inline short cListaAvion::getCantActual() const { return cantActual; }

inline bool cListaAvion::operator==(cAvion* _avion) { return noRepetido(_avion); }

#endif // !CLISTAAVION_H