﻿//---------------------------------------------------------------------------

#pragma hdrstop

#include "PilaLista.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

PilaL::PilaL(){
    L = new ListaP();
}

bool PilaL::vacia(){
    return L->vacia();
}

void PilaL::meter(int e){
    L->inserta(L->primero(), e);
}

void PilaL::sacar(int& e){
    if(!vacia()){
        e = L->recupera(L->primero());
        L->suprime(L->primero());
    }
}

int PilaL::cima(){
    if(!vacia()){
        return L->recupera(L->primero());
    }
}

string PilaL::to_str(){
    string r = "";
    PilaL* aux = new PilaL();
    while(!vacia()){
        int e;
        sacar(e);
        r += "| "+to_string(e)+" |\n";
        aux->meter(e);
    }
    while(!aux->vacia()){
        int e;
        aux->sacar(e);
        meter(e);
    }
    r += "+---+\n";
    return r;
}