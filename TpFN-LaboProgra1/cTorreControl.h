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
	/// Constructor parametrizado por defecto
	/// </summary>
	/// <param name="tamHangar">: Capacidad del hangar</param>
	/// <param name="tamlista">: Capacidad de la lista</param>
	/// <param name="largo">: Largo de la pista</param>
	/// <param name="ancho">: Ancho de la pista</param>
	cTorreControl(short tamHangar = MAX_LISTA, short tamlista = MAX_LISTA,
				  float largo = MAX_PISTA, float ancho = MAX_PISTA);

	/// <summary>
	/// Destructor por defecto
	/// </summary>	
	~cTorreControl();
	
	/// <summary>
	/// Recibe el avion busca asignarlo a la pista
	/// </summary>
	/// <param name="avion">: avion que busca pista</param>
	/// <returns>True en caso de poder, false en caso contrario</returns>
	bool asignarPistaAvion(cAvion* avion);
	
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

#endif // !CTORRECONTROL_H
