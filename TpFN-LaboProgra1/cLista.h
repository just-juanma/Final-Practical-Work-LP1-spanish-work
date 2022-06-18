#ifndef CLISTA_H
#define CLISTA_H
#include "gbl.h"

template <typename T>

class cLista
{
public:
	
	/// <summary>
	/// Constructor parametrizado por defecto
	/// </summary>
	/// <param name="_cantTotal">: Cantidad total de la lista</param>
	/// <param name="_checkEliminar">: Se pretende eliminar los punteros internos? si (true)/no (false)</param>
	cLista(short _cantTotal = MAX_LISTA, bool _checkEliminar = false);
	
	/// <summary>
	/// Destructor por defecto
	/// </summary>
	~cLista();
	
	/// <summary>
	/// Agrega un elemento a la lista
	/// </summary>
	/// <param name="elemento">: Elemento a agregar</param>
	void agregar(T* elemento);
	
	/// <summary>
	/// ELIMINA un elemento de la lista
	/// </summary>
	/// <param name="elemento">: Elemento a eliminar</param>
	void eliminar(T* elemento);
	
	/// <summary>
	/// Agrega un elemento mediante "+"
	/// </summary>
	/// <param name="elemento">: Elemento a agregar</param>
	void operator+(T* elemento);
	
	/// <summary>
	/// Elimina un elemento mediante "-"
	/// </summary>
	/// <param name="elemento">: ELemento a eliminar</param>
	void operator-(T* elemento);
	
	/// <summary>
	/// Retorna el elemento[i]
	/// </summary>
	/// <param name="i">: Indice del elemento en la lista</param>
	/// <returns>El i-esimo elemento de la lista</returns>
	T* operator[](short i);
	
	/// <summary>
	/// Aumenta la capacidad de la lista mediante "++"
	/// </summary>
	void operator++();

private:
	
	/// <summary>
	/// Aumenta el tamaño de la lista en +1
	/// </summary>
	void resize();
	
	/// <summary>
	/// Ordena los elementos para enviar el eliminado al final de la lista
	/// </summary>
	void ordenar();

	/// <summary>
	/// Recorre la lista y se fija si encuentra un elemento igual
	/// </summary>
	/// <returns>True en caso de encontrarlo, false en caso contrario</returns>
	bool noRepetido(T* elemento);
	
protected:
	

	T** lista;
	short cantTotal;
	ushort cantActual;
	bool checkEliminar;
	
};

template <typename T>
inline cLista<T>::cLista(short _cantTotal, bool _checkEliminar) {
	this->cantActual = 0;
	this->checkEliminar = _checkEliminar;
	try {
		this->lista = new T * [_cantTotal];
		this->cantTotal = _cantTotal;
		for (ushort i = 0; i < this->cantTotal; i++)
			this->lista[i] = NULL;
	}
	catch (bad_alloc& e) {
		cout << "Error al crear la lista: " << e.what() << endl;
	}
}

template <typename T>
inline cLista<T>::~cLista() {
	if (this->checkEliminar)
		for (ushort i = 0; i < this->cantActual; i++)
			delete this->lista[i];
	delete[] this->lista;
}

template <typename T>
inline void cLista<T>::agregar(T* elemento) {
	try {
		if (this->cantActual == this->cantTotal)
			throw out_of_range("Error: La cantidad actual de elementos es igual a la cantidad total de elementos");
		else if (!elemento)
			throw invalid_argument("Error: El elemento que se intenta agregar no existe");
		else if (this->noRepetido(elemento))
			throw invalid_argument("Error: El elemento ya existe en la lista");
		this->lista[this->cantActual++] = elemento;
	}
	catch (out_of_range& e) {
		cout << e.what() << endl;
	}
	catch (invalid_argument& e) {
		cout << e.what() << endl;
	}
}

template <typename T>
inline void cLista<T>::eliminar(T* elemento) {
	try {
		if (!elemento)
			throw invalid_argument("Error: El elemento que se intenta eliminar no existe");
		for (ushort i = 0; i < this->cantActual; i++) {
			if (this->lista[i] == elemento) {
				delete this->lista[i];
				this->lista[i] = NULL;
				ordenar();
				this->cantActual--;
				return;
			}
		}
		throw invalid_argument("Error: El elemento que se intenta eliminar no existe");
	}
	catch (invalid_argument& e) {
		cout << e.what() << endl;
	}
}

template <typename T>
inline void cLista<T>::operator+(T* elemento) { agregar(elemento); }

template <typename T>
inline void cLista<T>::operator-(T* elemento) { eliminar(elemento); }

template <typename T>
inline T* cLista<T>::operator[](short i) {
	try {
		if (i >= 0 && i < this->cantActual)
			return lista[i];
		throw out_of_range("Error: Se esta intentando acceder a un elemento imposible de acceder");
	}
	catch (out_of_range& e) {
		cout << e.what() << endl;
	}
}

template <typename T>
inline void cLista<T>::operator++() { resize(); }

template <typename T>
inline void cLista<T>::resize() {
	try {
		T** tempList = new T * [++this->cantTotal];
		memcpy(tempList, this->lista, this->cantTotal * sizeof(T*));
		delete[] tempList;
		this->lista[this->cantTotal - 1] = NULL;
		this->lista = tempList;
	}
	catch (bad_alloc& e) {
		cout << e.what() << endl;
	}
}

template <typename T>
inline void cLista<T>::ordenar() {
	for (ushort i = 0; i < this->cantActual; i++)
		for (ushort j = i; j < this->cantActual - 1; j++)
			if (!this->lista[i])
				swap(this->lista[j], this->lista[j + 1]);
}

template <typename T>
inline bool cLista<T>::noRepetido(T* elemento) {
	for (ushort i = 0; i < this->cantActual; i++)
		if (this->lista[i] == elemento)
			return true;
	return false;
}

#endif // !LISTA_H