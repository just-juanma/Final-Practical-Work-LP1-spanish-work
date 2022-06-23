#ifndef CEXCEPTION_H
#define CEXCEPTION_H
#include <exception>
#include "gbl.h"

class null_modelo : public exception {
public:	
	const char* what() const throw() {
		return "Error: No se pudo cargar el modelo\n";
	}
};

class null_pista :public exception {
public:
	const char* what() const throw() {
		return "Error: No se pudo cargar la pista\n";
	}
};

class null_status : public exception {
public:
	const char* what() const throw() {
		return "Error: Estado desconocido de un avion no tiene donde switchear\n";
	}
};

class error_despegue : public exception {
public: 
	const char* what() const throw() {
		return "Error: No pudo despegar el avion\n";
	}
};

class error_aterrizaje :public exception {
public:
	const char* what() const throw() {
		return "Error: No se pudo aterrizar el avion\n";
	}
}; 

class error_largo_pista :public exception {
public:
	const char* what() const throw() {
		return "Error: El largo de la pista no es suficiente\n";
	}
};

class error_ancho_pista :public exception {
public:
	const char* what() const throw() {
		return "Error: El ancho de la pista no es suficiente\n";
	}
};

class error_null_avion :public exception {
public: 
	const char* what()const throw() {
		return "Error: El avion no existe";
	}
};

class error_incidente : public exception {
public:
	const char* what() const throw() {
		return "Error: El avion se encuentra en un incidente\n";
	}
};

class error_avion_almacenado :public exception {
public:
	const char* what()const throw() {
		return "Error: El avion no pudo ser almacenado";
	}
};

class error_pista_ocupada :public exception {
public:
	const char* what()const throw() {
		return "Error: no se puede usar la pista, esta misma esta ocupada";
	}
};

class error_id_incorrecto :public exception {
public:
	const char* what()const throw() {
		return "Error: el ID no pertenece al modelo de avion esperado";
	}
};

class error_input :public exception {
public:
	const char* what()const throw() {
		return "Error: El valor ingresado no se corresponde con el tipo de dato esperado";
	}
};


#endif // !CEXCEPTION_H