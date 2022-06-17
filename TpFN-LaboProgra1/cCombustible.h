#ifndef CCOMBUSTIBLE_H
#define CCOMBUSTIBLE_H
#include "gbl.h"
#include "cFecha.h"

class cCombustible
{
public:
	
	
	cCombustible(short hora = 0, short minuto = 0);
	
	/// <summary>
	/// Destructor por defecto
	/// </summary>
	~cCombustible();

	cFecha* getDuracion() const;

private:
	
	cFecha* duracion;
	
};

//inline void cCombustible::cargarCombustible(short hora, short minuto) { this->duracionCombustible->setHorarioEsperado(hora, minuto); }

inline cFecha* cCombustible::getDuracion() const { return this->duracion; }

#endif // !CCOMBUSTIBLE_H

