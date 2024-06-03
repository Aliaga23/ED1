//---------------------------------------------------------------------------

#ifndef ColaListaH
#define ColaListaH
//---------------------------------------------------------------------------
#include <iostream>
#include <string>

#include "UListaV.h"

using namespace std;

class ColaL {
private:
	ListaV* L;

public:
	ColaL();
	bool vacia();
	void poner(int e);
	void sacar(int &e);
	int primero();
	string to_str();
};
#endif
