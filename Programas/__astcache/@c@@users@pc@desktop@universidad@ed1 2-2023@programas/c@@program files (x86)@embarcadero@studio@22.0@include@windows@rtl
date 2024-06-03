//---------------------------------------------------------------------------

#pragma hdrstop

#include "DicolaSM.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

       Dicola::Dicola() {
	ini = -1;
	fin = -1;
	m = new CsMemoria();
}

Dicola::Dicola(CsMemoria* mem) {
	ini = -1;
	fin = -1;
	m = mem;
}

bool Dicola::vacia() {
	return ini == -1 && fin == -1;
}

void Dicola::poner(int e) {
	int aux = m->new_espacio("ant,elem,sig");
	m->poner_dato(aux, "->elem", e);
	if (vacia()) {
		m->poner_dato(aux, "->ant", aux);
		m->poner_dato(aux, "->sig", aux);
		ini = aux;
		fin = aux;
	}
	else {
		m->poner_dato(aux, "->ant", fin);
		m->poner_dato(fin, "->sig", aux);
		m->poner_dato(aux, "->sig", ini);
		m->poner_dato(ini, "->ant", aux);
		fin = aux;
	}
}

void Dicola::sacar(int &e) {
	if (!vacia()) {
		e = m->obtener_dato(ini, "->elem");
		int aux = ini;
		if (ini == fin) {
			ini = -1;
			fin = -1;
		}
		else {
			ini = m->obtener_dato(ini, "->sig");
			m->poner_dato(ini, "->ant", fin);
			m->poner_dato(fin, "->sig", ini);
		}
		m->delete_espacio(aux);
	}
}

int Dicola::primero() {
	if (!vacia()) {
		return m->obtener_dato(ini, "->elem");
	}
}

void Dicola::poner_frente(int e) {
	int aux = m->new_espacio("ant,elem,sig");
	m->poner_dato(aux, "->elem", e);
	if (vacia()) {
		m->poner_dato(aux, "->ant", aux);
		m->poner_dato(aux, "->sig", aux);
		ini = aux;
		fin = aux;
	}
	else {
		m->poner_dato(aux, "->sig", ini);
		m->poner_dato(ini, "->ant", aux);
		m->poner_dato(aux, "->ant", fin);
		m->poner_dato(fin, "->sig", aux);
		ini = aux;
	}
}

void Dicola::sacar_final(int &e) {
	if (!vacia()) {
		e = m->obtener_dato(fin, "->elem");
		int aux = fin;
		if (ini == fin) {
			ini = -1;
			fin = -1;
		}
		else {
			fin = m->obtener_dato(fin, "->ant");
			m->poner_dato(fin, "->sig", ini);
			m->poner_dato(ini, "->ant", fin);
		}
		m->delete_espacio(aux);
	}
}

int Dicola::ultimo() {
	if (!vacia())
		return m->obtener_dato(fin, "->elem");
}

string Dicola::to_str() {
	string s = "<<";
	int e;
	Dicola* aux = new Dicola();
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