//---------------------------------------------------------------------------

#ifndef Parcial1H
#define Parcial1H
//---------------------------------------------------------------------------
#include <iostream>
#include <string>
#include "Listas.h"

using namespace std;

class PoliLP2 {
private:
    ListaP k;

public:
    PoliLP2();
    bool es_cero();
    int grado();
    int coeficiente(int exp);
    void asignar_coeficiente(int coef, int exp);
    void poner_termino(int coef, int exp);
    int numero_terminos();
    int exponente(int nro);
    void derivar();
    string to_str();
    float evalua(float x);
    string k_to_str();
};
#endif
