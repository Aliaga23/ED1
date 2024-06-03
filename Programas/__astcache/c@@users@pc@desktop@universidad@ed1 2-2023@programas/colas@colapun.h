//---------------------------------------------------------------------------

#ifndef ColaPunH
#define ColaPunH
//---------------------------------------------------------------------------
#include <iostream>
#include <string>

using namespace std;

struct NodoC{
    int elemento;
    NodoC* sig;
};

class ColaP{
    private:
        NodoC* ini;
        NodoC* fin;
    public:
        ColaP();
        bool vacia();
		void poner(int e);
		void sacar(int &e);
		int primero();
		string to_str();
};
#endif
