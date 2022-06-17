#ifndef CFECHA_H
#define CFECHA_H
#include "gbl.h"

class cFecha 
{
public:
	
	/// <summary>
	/// Constructor parametrizado por defecto
	/// </summary>
	/// <param name="_hora">: Hora a setear</param>
	/// <param name="_minuto">: Minuto a setear</param>
	cFecha(short _hora = 0, short _minuto = 0);
	
	/// <summary>
	/// Destructor por defecto
	/// </summary>
	~cFecha();
	
	time_t getHorarioEsperado() const;
	
	static time_t getHorarioActual();

private:
	
	struct tm horarioEsperado;
	
};

/// <seealso cref="https://en.cppreference.com/w/cpp/language/const_cast"/>
inline time_t cFecha::getHorarioEsperado() const { return mktime(const_cast<tm*>(&horarioEsperado)); }

inline time_t cFecha::getHorarioActual() { return time(NULL); }

#endif // !CFECHA_H

