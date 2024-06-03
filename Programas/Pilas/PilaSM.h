//---------------------------------------------------------------------------

#ifndef PilaSMH
#define PilaSMH
//---------------------------------------------------------------------------
#include <iostream>
#include <string>
#include "CSMemoria.h"

using namespace std;

const string datosPun = "elemento,sig";
const string elementoPun = "->elemento";
const string sigPun = "->sig";

class PilaS{
    private:
        int tope;
		CsMemoria* mem;
	public:
		PilaS();
        PilaS(CsMemoria* m);
        bool vacia();
        void meter(int e);
        void sacar(int& e);
        int cima();
        string to_str();
};
#endif
