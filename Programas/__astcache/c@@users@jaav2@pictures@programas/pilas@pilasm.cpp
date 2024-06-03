//---------------------------------------------------------------------------

#pragma hdrstop

#include "PilaSM.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#include <iomanip>
PilaS::PilaS()
{
	mem = new CsMemoria();
    tope = NULO;
}

PilaS::PilaS(CsMemoria* m)
{
    mem = m;
    tope = NULO;
}

bool PilaS::vacia()
{
    return tope == NULO;
}

void PilaS::meter(int e)
{
	int aux = mem->new_espacio(datosPun); //new NodoP;
    if (aux != NULO) {
        mem->poner_dato(aux, elementoPun, e); //aux->elemento = e;
        mem->poner_dato(aux, sigPun, tope); //aux->sig = tope;
        tope = aux;
    } else
        cout << "ERROR NO HAY MEMORIA\n" << endl;
}

void PilaS::sacar(int &e)
{
    if (!vacia()) {
		int x = tope;
        e = mem->obtener_dato(tope, elementoPun); //tope->elemento;
		tope = mem->obtener_dato(tope, sigPun); //tope->sig;
        mem->delete_espacio(x); //delete(x);
    }
}

int PilaS::cima()
{
    if (!vacia()) {
        return mem->obtener_dato(tope, elementoPun); //tope->elemento;
    }
}

string PilaS::to_str()
{
	string r = "+";
//	for (int i = 2; i <= 4+ 4; i++) {
//		r += "-";
//	}
//	r += "+\n";
	PilaS* aux = new PilaS();
	while (!vacia()) {
		int e;
		sacar(e);
		cout<< "| " << setw(4)<<to_string(e) << " |\n";
		aux->meter(e);
	}
	while (!aux->vacia()) {
		int e;
		aux->sacar(e);
		meter(e);
	}
//	r += "+";
//	for (int i = 2; i <= 4 + 4; i++) {
//		r += "-";
//	}
//	r += "+\n";
	return r;
}
