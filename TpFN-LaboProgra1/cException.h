#ifndef CEXCEPTION_H
#define CEXCEPTION_H
#include <exception>
#include "gbl.h"

class null_modelo : public exception {
public:	
	const char* what() const throw() {
		return "No se pudo cargar el modelo";
	}
};

class null_pista :public exception {
	public:
	const char* what() const throw() {
		return "No se pudo cargar la pista";
	}
};

class error_despegue_cessna : public exception {
public: 
	const char* what() const throw() {
		return "No se pudo despegar el cessna";
	}
};

class error_despegue_biplano : public exception {
public:
	const char* what() const throw() {
		return "No se pudo despegar el biplano";
	}
};

class error_aterrizaje_cessna :public exception {
public:
	const char* what() const throw() {
		return "No se pudo aterrizar el cessna";
	}
}; 


class error_aterrizaje_biplano :public exception {
public:
	const char* what() const throw() {
		return "No se pudo aterrizar el biplano";
	}
};

class error_tanque_cessna :public exception {
public:
	const char* what() const throw() {
		return "Error tanque del cessna";
	}
};

class error_tanque_biplano :public exception {
public:
	const char* what() const throw() {
		return "Error tanque del biplano";
	}
};

class error_tiempoMaximo :public exception {
	public:
	const char* what() const throw() {
		return "El tiempo máximo de vuelo, no alcanza";
	}
};

class error_largo_pista :public exception {
	public:
	const char* what() const throw() {
		return "El largo de la pista no es suficiente";
	}
};

class error_ancho_pista :public exception {
	public:
	const char* what() const throw() {
		return "El ancho de la pista no es suficiente";
	}
};

#endif // !CEXCEPTION_H