//---------------------------------------------------------------------------

#ifndef DicolaSMH
#define DicolaSMH
//---------------------------------------------------------------------------
#include <iostream>
#include "CSMemoria.h"
#include <string>
using namespace std;

class Dicola {
private:
	CsMemoria* m;
	int ini, fin;

public:
	Dicola();
	Dicola(CsMemoria* mem);
	bool vacia();
	void poner(int e);
	void sacar(int &e);
	int primero();
	void poner_frente(int e);
	void sacar_final(int &e);
	int ultimo();
	string to_str();
};
#endif
