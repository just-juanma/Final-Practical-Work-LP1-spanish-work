#ifndef CCOMBUSTIBLE_H
#define CCOMBUSTIBLE_H
#include "gbl.h"
#include "cFecha.h"

class cCombustible
{
public:
	
	/// <summary>
	/// Constructor parametrizado por defecto
	/// </summary>
	/// <param name="hora">: Hora de duracion del combustible</param>
	/// <param name="minuto": Minuto de duracion del combustible></param>
	cCombustible(short hora = 0, short minuto = 0);
	
	/// <summary>
	/// Destructor por defecto
	/// </summary>
	~cCombustible();
	
	/// <summary>
	/// 1 de cada 50 cargas de combustible falla, lo que significa restar la duracion de horas y minutos
	/// </summary>
	void fallaCombustible(short* hora, short* minuto);

	cFecha* getDuracion() const;

private:
	
	cFecha* duracion;
	
};

inline cFecha* cCombustible::getDuracion() const { return this->duracion; }

#endif // !CCOMBUSTIBLE_H

