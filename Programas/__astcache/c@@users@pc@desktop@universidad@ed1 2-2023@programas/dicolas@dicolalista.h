//---------------------------------------------------------------------------

#ifndef DicolaListaH
#define DicolaListaH
//---------------------------------------------------------------------------
#include <iostream>
#include <string>
#include "UListaV.h"

using namespace std;

class DicolaL {
private:
	ListaV* L;

public:
	DicolaL();
	bool vacia();
	void poner(int e);
	void sacar(int &e);
	int primero();
	int ultimo();
	void poner_frente(int e);
	void sacar_final(int &e);
	string to_str();
};
#endif
