//---------------------------------------------------------------------------

#ifndef Conjunto_LisH
#define Conjunto_LisH
//---------------------------------------------------------------------------
#include <iostream>
#include <string>

#include "ListasPtr.h"

using namespace std;

class ConjuntoListaPtr {
private:
	ListaPtr *lista;

public:
	ConjuntoListaPtr();
	bool vacio();
	int cardinal();
	int ordinal(int e);
	void inserta(int e);
	void insertaExamen(int e);
	void insertaExamen1(int e);
	void suprime(int e);
	bool pertenece(int e);
	int muestrea();
	int elemento(int pos);
	void reiniciar();
	string toStr();
	void unir(ConjuntoListaPtr *b, ConjuntoListaPtr *c);
	// ConjuntoListaPtr* unir(ConjuntoListaPtr* B);
	void intersectar(ConjuntoListaPtr *b, ConjuntoListaPtr *c);
};
#endif

