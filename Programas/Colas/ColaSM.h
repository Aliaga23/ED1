//---------------------------------------------------------------------------

#ifndef ColaSMH
#define ColaSMH
//---------------------------------------------------------------------------
#include <iostream>
#include <string>
#include "CSMemoria.h"

const string datosC = "elemento,sig";
const string elementoC = "->elemento";
const string sigC = "->sig";

class ColaS {
private:
	CsMemoria* mem;
	int ini, fin;

public:
	ColaS();
	ColaS(CsMemoria* m);
	bool vacia();
	void poner(int e);
	void sacar(int &e);
	int primero();
	string to_str();
};
#endif
