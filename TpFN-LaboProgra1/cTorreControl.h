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
	/// Permite al avion despegar, sin antes hacer su checkeo interno y su relacion con la pista
	/// </summary>
	/// <param name="_avion">: avion que intenta aterrizar</param>
	void autorizarDespegue(cAvion* _avion);

	/// <summary>
	/// Permite al avion aterrizar, sin antes hacer su checkeo interno y su relacion con la pista
	/// </summary>
	/// <param name="_avion">: Avion que intenta aterrizar</param>
	void autorizarAterrizaje(cAvion* _avion);

	void autorizarEstacionamiento(cAvion* _avion);

	/// <summary>
	/// Imprime los detalles de cada avion
	/// </summary>
	void imprimirDetalles();
	
	void verificarHorario(cAvion* _avion);

	/// <summary>
	/// Debido a que para despegar el avion tiene que estar en la lista, se utiliza este metodo para 
	/// agregarlo previamente
	/// </summary>
	/// <param name="_avion">Avion a agregar</param>
	void agregarAvionesListados(cAvion* _avion);
	/// <summary>
	/// Controla que el avion este en la lista de la torre
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
