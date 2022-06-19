#ifndef CHANGAR_H
#define CHANGAR_H
#include "gbl.h"
#include "cListaAvion.h"
#include "cException.h"
class cHangar
{
public:
	
	cHangar(short _cantTotal);
	~cHangar(); 
	/// <summary>
	/// Se agrega a la lista de aviones almacenados 
	/// </summary>
	/// <param name="avion">Avion a agregar</param>
	bool Almacenar(cAvion* avion); 
	/// <summary>
	/// Se saca el avion de la lista
	/// </summary>
	/// <param name="pos">Posicion en el hangar que se desea devolver</param>
	/// <returns></returns>
	cAvion* Despachar(short pos);
	/// <summary>
	/// Se retorna el avion de la lista
	/// </summary>
	/// <param name="ID">ID del avion que se desea buscar</param>
	/// <returns></returns>
	int buscarAvion(string ID);
	int getCantActual();
	bool operator==(cAvion* avion);
private: 
	
	cListaAvion* almacenados;
	
};

#endif // !CHANGAR_H