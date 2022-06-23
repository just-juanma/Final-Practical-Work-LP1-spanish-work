#ifndef CHANGAR_H
#define CHANGAR_H
#include "gbl.h"
#include "cListaAvion.h"
#include "cException.h"

class cHangar
{
	friend class cTorreControl;
public:
	
	/// <summary>
	/// Constructor parametrizado por defecto
	/// </summary>
	/// <param name="_cantTotal>: Capacidad maxima del hangar</param>
	cHangar(short _cantTotal = MAX_LISTA);
	
	/// <summary>
	/// Destructor por defecto
	/// </summary>
	~cHangar(); 

	short getCantActual();
	
	/// <summary>
	/// Se agrega a la lista de aviones almacenados 
	/// </summary>
	/// <param name="avion">Avion a agregar</param>
	bool almacenar(cAvion* _avion);
	
	/// <summary>
	/// Se saca el avion de la lista
	/// </summary>
	cAvion* despachar(cAvion* _avion);
	
	cAvion* operator[](short _pos);
private: 
	
	cListaAvion* almacenados;
	
};

inline short cHangar::getCantActual() { return this->almacenados->getCantActual(); }

#endif // !CHANGAR_H