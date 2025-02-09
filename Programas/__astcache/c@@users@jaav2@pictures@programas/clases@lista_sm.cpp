﻿//---------------------------------------------------------------------------

#pragma hdrstop

#include "Lista_SM.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
ListaS::ListaS()
{
    ptr_elementos = NULO;
    longit = 0;
    mem = new CsMemoria();
}

ListaS::ListaS(CsMemoria* m)
{
    ptr_elementos = NULO;
    longit = 0;
    mem = m;
}


int ListaS::fin()
{
    if (vacia())
        cout << "ERROR: LISTA VACIA\n";
    else {
        int x = ptr_elementos;
        int ptr_fin;
        while (x != NULO) {
            ptr_fin = x;
            x = mem->obtener_dato(x, sigNL); // x->sig;
        }
        return ptr_fin;
    }
}

int ListaS::primero()
{
    if (!vacia())
        return ptr_elementos;
    else
        cout << "ERROR: LISTA VACIA\n";
}

int ListaS::siguiente(int d)
{
    if (vacia())
        cout << "ERROR: LISTA VACIA\n";
    else {
        if (d == fin())
            cout << "ERROR: DIRECCION ERRONEA\n";
        else
            return mem->obtener_dato(d, sigNL); // d->sig;
    }
}

int ListaS::anterior(int d)
{
    if (vacia())
        cout << "ERROR: LISTA VACIA\n";
    else {
        if (d == primero())
            cout << "ERROR: DIRECCION ERRONEA\n";
        else {
            int x = ptr_elementos;
            int ant = NULO;
            while (x != NULO) {
                if (x == d)
                    return ant;
                ant = x;
                x = mem->obtener_dato(x, sigNL); // x->sig;
            }
            return NULO;
        }
    }
}

bool ListaS::vacia()
{
    return longit == 0;
}

int ListaS::recupera(int d)
{
    if (vacia())
        cout << "ERROR: LISTA VACIA\n";
    else
        return mem->obtener_dato(d, elemNL); // d->elemento;
}

int ListaS::longitud()
{
    return longit;
}

// new Nodo;     mem->new_espacio("elemento,sig"); mem->new_espacio(datosNL);
void ListaS::inserta(int d, int e)
{
    int x = mem->new_espacio(datoNL); // NodoL* x = new NodoL;
    if (x != NULO) {
        mem->poner_dato(x, elemNL, e); // x->elemento = e;
        mem->poner_dato(x, sigNL, NULO); // x->sig = NULL;
        if (vacia()) {
            ptr_elementos = x;
            longit = 1;
        } else {
            longit++;
            if (d == primero()) {
                mem->poner_dato(x, sigNL, d); // x->sig = d;
                ptr_elementos = x;
            } else {
                int ant = anterior(d);
                mem->poner_dato(ant, sigNL, x); // ant->sig = x;
                mem->poner_dato(x, sigNL, d); // x->sig = d;
            }
        }
    } else
        cout << "ERROR: NO EXISTE ESPACIO DE MEMORIA\n";
}

void ListaS::inserta_primero(int e)
{
    int x = mem->new_espacio(datoNL); // NodoL* x = new NodoL;
    if (x != NULO) {
        mem->poner_dato(x, elemNL, e); // x->elemento = e;
        mem->poner_dato(x, sigNL, ptr_elementos); // x->sig = ptr_elementos
        ptr_elementos = x;
        longit++;
    } else
        cout << "ERROR: NO EXISTE ESPACIO DE MEMORIA\n";
}

void ListaS::inserta_ultimo(int e)
{
    int x = mem->new_espacio(datoNL); // NodoL* x = new NodoL;
    if (x != NULO) {
        mem->poner_dato(x, elemNL, e); // x->elemento = e;
        mem->poner_dato(x, sigNL, NULO); // x->sig = NULL;
        if (vacia())
            ptr_elementos = x;
        else
            mem->poner_dato(fin(), sigNL, x); // fin()->sig = x;
        longit++;
    } else
        cout << "ERROR: NO EXISTE ESPACIO DE MEMORIA\n";
}

// delete(x)     ->  mem->delete_espacio(x);
void ListaS::suprime(int d)
{
    if (longit == 0) {
        cout << "ERROR: LISTA VACIA\n";
        return;
    }
    if (d == ptr_elementos) {
        int x = ptr_elementos;
        ptr_elementos = mem->obtener_dato(ptr_elementos, sigNL);
        // ptr_elementos->sig;
        mem->delete_espacio(x); // delete(x);
    } else {
        int ant = anterior(d);
        mem->poner_dato(ant, sigNL, mem->obtener_dato(d, sigNL));
        // ant->sig = d->sig;
        mem->delete_espacio(d); // delete(d);
    }
    longit--;
}

void ListaS::modifica(int d, int e)
{
    if (vacia())
        cout << "ERROR: LISTA VACIA\n";
    else
        mem->poner_dato(d, elemNL, e); // d->elemento = e;
}

string ListaS::to_str()
{
    // mem->mostrar();
    string s = "[";
    int aux = ptr_elementos;
    while (aux != NULO) {
        int el = mem->obtener_dato(aux, elemNL); // aux->elemento
        s += to_string(el);
        aux = mem->obtener_dato(aux, sigNL); // aux->sig;
        if (aux != NULO)
            s += ",";
    }
    return s + "]";
}

int ListaS::localiza(int e)
{
    int aux = ptr_elementos;
    while (aux != NULO) {
        if (mem->obtener_dato(aux, elemNL) == e)
            return aux;
        aux = mem->obtener_dato(aux, sigNL); // aux->sig;
    }
    return NULO;
}

void ListaS::elimina_dato(int e)
{
    int aux = ptr_elementos;
    while (aux != NULO) {
        if (mem->obtener_dato(aux, elemNL) == e) {
            int sup = aux;
            aux = mem->obtener_dato(aux, sigNL); // aux->sig;
            suprime(sup);
        } else
            aux = mem->obtener_dato(aux, sigNL); // aux->sig;
    }
}

void ListaS::anula()
{
    while (!vacia())
		suprime(primero());
}

 void ListaS::EliminarAlInicio() {
	if (!vacia()) {
		int primerob = recupera(primero());
		suprime(primerob);
    }
}
