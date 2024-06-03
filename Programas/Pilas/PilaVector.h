//---------------------------------------------------------------------------

#ifndef PilaVectorH
#define PilaVectorH
//---------------------------------------------------------------------------
#include <iostream>
#include <string>

using namespace std;

const int MAX_VP = 50;

class PilaV{
    private:
        int* elementos;
        int tope;
    public:
        PilaV();
        bool vacia();
        void meter(int e);
        void sacar(int& e);
        int cima();
		string to_str();
        void tope1();
};
#endif
