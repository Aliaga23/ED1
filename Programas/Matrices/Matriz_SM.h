//---------------------------------------------------------------------------

#ifndef Matriz_SMH
#define Matriz_SMH
//---------------------------------------------------------------------------

#include <iostream>
#include <string>
#include "CSMemoria.h"

using namespace std;

const string dataMC = "fil,col,dato,sig";
const string filMC = "->fil";
const string colMC = "->col";
const string datoMC = "->dato";
const string sigMC = "->sig";

class MatrizSM {
private:
    CsMemoria* mem;
    int ptrMatD;
    int repe, df, dc;
    int nt;

    int anterior(int p);
    void suprime(int p);
    int existe(int f, int c);

public:
	MatrizSM();
    MatrizSM(CsMemoria* m);
    void dimensionar(int f, int c);
    int dimension_fila();
    int dimension_columna();
    void poner(int f, int c, int valor);
    int elemento(int f, int c);
    void definir_valor_repetido(int valor);
	string to_str();
	void transponer();
};
#endif
