#ifndef CHANGAR_H
#define CHANGAR_H
#include "gbl.h"
#include "cListaAvion.h"
#include "cException.h"

class cHangar
{
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

	/// <summary>
	/// Se agrega a la lista de aviones almacenados 
	/// </summary>
	/// <param name="avion">Avion a agregar</param>
	bool almacenar(cAvion* avion);
	
	/// <summary>
	/// Se saca el avion de la lista
	/// </summary>
	/// <param name="pos">Posicion en el hangar que se desea devolver</param>
	/// <returns></returns>
	cAvion* despachar(short pos);
	
	/// <summary>
	/// Se retorna el avion de la lista
	/// </summary>
	/// <param name="ID">ID del avion que se desea buscar</param>
	/// <returns></returns>
	int buscarAvion(string ID);
	
	short getCantActual();
	
	bool operator==(cAvion* avion);
	
private: 
	
	cListaAvion* almacenados;
	
};

inline short cHangar::getCantActual() { return this->almacenados->getCantActual(); }

#endif // !CHANGAR_H