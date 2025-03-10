//---------------------------------------------------------------------------

#pragma hdrstop

#include "DicolaV3.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
DicolaV3::DicolaV3()
{
    ini = fin = 0;
    v = new int[MAXVD3];
}

bool DicolaV3::vacia()
{
    return ini == fin;
}

int DicolaV3::siguiente(int dir)
{
    if (dir == MAXVD3 - 1)
        return 0;
    else
        return dir + 1;
}

void DicolaV3::poner(int e)
{
    if (siguiente(fin) != ini) {
        v[fin] = e;
        fin = siguiente(fin);
    }
}

void DicolaV3::sacar(int &e)
{
    if (!vacia()) {
        e = v[ini];
        ini = siguiente(ini);
    }
}

int DicolaV3::primero()
{
    if (!vacia())
        return v[ini];
}

int DicolaV3::anterior(int dir)
{
    if (dir == 0)
        return MAXVD3 - 1;
    else
        return dir - 1;
}

int DicolaV3::ultimo()
{
    if (!vacia()) {
        return v[fin];
    }
}

void DicolaV3::poner_frente(int e)
{
    if (siguiente(fin) != ini) {
        ini = anterior(ini);
        v[ini] = e;
    }
}

void DicolaV3::sacar_final(int &e)
{
    if (!vacia()) {
        e = v[fin - 1];
        fin = anterior(fin);
    }
}

string DicolaV3::to_str()
{
    string s = "<<";
    int e;
    DicolaV3* aux = new DicolaV3();
    while (!vacia()) {
        sacar(e);
        aux->poner(e);
        s += to_string(e);
        if (!vacia())
            s += ",";
    }
    while (!aux->vacia()) {
        aux->sacar(e);
        poner(e);
    }
    return s + "<<";
}
