#ifndef CEXCEPTION_H
#define CEXCEPTION_H
#include <exception>
#include "gbl.h"

class bad_getter : public exception {
public:
	const char* what() const throw() {
		return "El elemento que se intenta obtener no existe\n";
	}
};

class bad_setter : public exception {
public:
	const char* what() const throw() {
		return "El elemento que se intenta insertar no existe\n";
	}
};


class null_modelo : public exception {
public:	
	const char* what() const throw() {
		return "No se pudo cargar el modelo\n";
	}
};

class null_pista :public exception {
	public:
	const char* what() const throw() {
		return "No se pudo cargar la pista\n";
	}
};

class error_despegue_cessna : public exception {
public: 
	const char* what() const throw() {
		return "No se pudo despegar el cessna\n";
	}
};

class error_despegue_biplano : public exception {
public:
	const char* what() const throw() {
		return "No se pudo despegar el biplano\n";
	}
};

class error_aterrizaje_cessna :public exception {
public:
	const char* what() const throw() {
		return "No se pudo aterrizar el cessna\n";
	}
}; 


class error_aterrizaje_biplano :public exception {
public:
	const char* what() const throw() {
		return "No se pudo aterrizar el biplano\n";
	}
};

class error_tanque_cessna :public exception {
public:
	const char* what() const throw() {
		return "Error tanque del cessna\n";
	}
};

class error_tanque_biplano :public exception {
public:
	const char* what() const throw() {
		return "Error tanque del biplano\n";
	}
};

class error_tiempoMaximo :public exception {
	public:
	const char* what() const throw() {
		return "El tiempo máximo de vuelo, no alcanza\n";
	}
};

class error_largo_pista :public exception {
	public:
	const char* what() const throw() {
		return "El largo de la pista no es suficiente\n";
	}
};

class error_ancho_pista :public exception {
	public:
	const char* what() const throw() {
		return "El ancho de la pista no es suficiente\n";
	}
};

#endif // !CEXCEPTION_H