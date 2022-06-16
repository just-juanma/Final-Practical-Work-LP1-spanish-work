#ifndef CMODELO_H
#define CMODELO_H
#include "gbl.h"
#include "cCombustible.h"

class cModelo
{
public:
	
	/// <summary>
	/// Constructor parametrizado por defecto
	/// </summary>
	/// <param name="_nombre">: Nombre del modelo</param>
	/// <param name="_limiteCarga">: Limite de carga del modelo</param>
	/// <param name="_aceleracion">: Aceleracion del modelo</param>
	/// <param name="_limitePasajeros">: Limite de pasajeros del modelo</param>
	cModelo(string _nombre = "", float _limiteCarga = 0, float _aceleracion = 0, short _limitePasajeros = 0);

	~cModelo();
	
	cCombustible* getCombustible() const;
	
	short getLimitePasajeros() const;
	
	short getLimiteCarga() const;

	/// <summary>
	/// Asigna combustible al modelo
	/// </summary>
	/// <param name="_combustible">: Combustible a agregar</param>
	void operator=(cCombustible* _combustible);
	
private:
	
	const string nombre;
	float limiteCarga;
	float aceleracion;
	short limitePasajeros;		
	cCombustible* combustible;

};

inline cCombustible* cModelo::getCombustible() const { return combustible; }

inline short cModelo::getLimitePasajeros() const { return this->limitePasajeros; }

inline void cModelo::operator=(cCombustible* _combustible) { this->combustible = _combustible; }

inline short cModelo::getLimiteCarga() const { return this->limiteCarga; }

#endif // !CMODELO_H