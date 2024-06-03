//---------------------------------------------------------------------------

#ifndef PilaListaH
#define PilaListaH
//---------------------------------------------------------------------------
#include <iostream>
#include <string>
#include "Lista_SM.h"
#include "Listas.h"

using namespace std;

class PilaL{
    private:
        ListaP* L;
    public:
        PilaL();
        bool vacia();
        void meter(int e);
        void sacar(int& e);
        int cima();
        string to_str();
};
#endif
