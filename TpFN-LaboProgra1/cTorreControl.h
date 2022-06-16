#ifndef CTORRECONTROL_H
#define CTORRECONTROL_H
#include "gbl.h"
#include "cPista.h"
#include "cAvion.h"
#include "cListaAvion.h"
#include "cHangar.h"

class cTorreControl
{
public:
	
	/// <summary>
	/// Constructor por defecto
	/// </summary>
	cTorreControl(ushort tamHangar = MAX_LISTA, ushort tamlista = MAX_LISTA);
	
	/// <summary>
	/// Destructor por defecto
	/// </summary>	
	~cTorreControl();

	void setLista(cListaAvion* lista);
	
	/// <summary>
	/// Recibe el avion busca asignarlo a la pista
	/// </summary>
	/// <param name="avion">: avion que busca pista</param>
	/// <returns>True en caso de poder, false en caso contrario</returns>
	bool asignarPista(cPista* pista);
	
	/// <summary>
	/// Permite al avion despegar, sin antes hacer su checkeo interno y su relacion con la pista
	/// </summary>
	/// <param name="avion">: avion que intenta aterrizar</param>
	/// <returns>True en caso de poder, false en caso contrario</returns>
	bool autorizarDespegue(cAvion* avion);

	/// <summary>
	/// Permite al avion aterrizar, sin antes hacer su checkeo interno y su relacion con la pista
	/// </summary>
	/// <param name="avion">: avion que intenta aterrizar</param>
	/// <returns></returns>
	bool autorizarAterrizaje(cAvion* avion);

	/// <summary>
	/// Imprime los detalles de cada avion
	/// </summary>
	void imprimirDetalles();
	
	/// <summary>
	/// Controla que el avion este en la lista
	/// </summary>
	/// <param name="avion">: Avion que debe estar listado</param>
	/// <returns>True en caso de no estar, false en caso contrario</returns>
	bool operator!=(cAvion* avion);
	
private:
	
	cPista* pista;
	cListaAvion* lista;
	cHangar* hangar;
};

inline void cTorreControl::setLista(cListaAvion* _lista) { this->lista = _lista; }

#endif // !CTORRECONTROL_H
