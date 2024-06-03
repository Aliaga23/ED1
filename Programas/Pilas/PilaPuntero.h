//---------------------------------------------------------------------------

#ifndef PilaPunteroH
#define PilaPunteroH
//---------------------------------------------------------------------------
#include <iostream>
#include <string>

using namespace std;

struct NodoPun{
    int elemento;
	NodoPun* sig;
};

class PilaP{
    private:
		NodoPun* tope;
	public:
        PilaP();
        bool vacia();
        void meter(int e);
        void sacar(int& e);
        int cima();
        string to_str();
};

#endif
