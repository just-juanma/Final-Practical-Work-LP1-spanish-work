#ifndef CCOMBUSTIBLE_H
#define CCOMBUSTIBLE_H
#include "gbl.h"
#include "cFecha.h"

class cCombustible
{
public:
	
	/// <summary>
	/// Constructor por defecto
	/// </summary>
	cCombustible();
	
	/// <summary>
	/// Destructor por defecto
	/// </summary>
	~cCombustible();

	void cargarCombustible(short hora, short minuto);
	

	// PODRIA GENERAR PROBLEMAS DE RECURSIVIDAD, ESPERAR
	///// <summary>
	///// Compara la hora esperada con la local para saber si el avion esta en horario
	///// </summary>
	///// <returns>True en caso de estar en horario, false en caso contrario</returns>
	//bool avionEnHorario(cAvion* avion);

	cFecha* getDuracion() const;

private:
	
	cFecha* duracionCombustible;
	
};

inline void cCombustible::cargarCombustible(short hora, short minuto) { this->duracionCombustible->setHorarioEsperado(hora, minuto); }

inline cFecha* cCombustible::getDuracion() const { return this->duracionCombustible; }

#endif // !CCOMBUSTIBLE_H

