﻿//---------------------------------------------------------------------------

#pragma hdrstop

#include "Matriz_PunteroDoble.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
MatrizPD::MatrizPD() {
	ptrFil = NULL;
	df = dc = repe = 0;
	nt = 0;
}

void MatrizPD::dimensionar(int f, int c) {
	df = f;
	dc = c;
}

int MatrizPD::dimension_fila() {
	return df;
}

int MatrizPD::dimension_columna() {
	return dc;
}

NodoMc* MatrizPD::buscar(int f, int c) {
	NodoMf* auxf = ptrFil;
	while (auxf != NULL) {
		if (auxf->fil == f) {
			NodoMc* auxc = auxf->ptrCol;
			while (auxc != NULL) {
				if (auxc->col == c)
					return auxc;
				auxc = auxc->sigC;
			}
			return NULL;
		}
		auxf = auxf->sigF;
	}
	return NULL;
}

NodoMf* MatrizPD::buscar(int f) {
	NodoMf* auxf = ptrFil;
	while (auxf != NULL) {
		if (auxf->fil == f)
			return auxf;
		auxf = auxf->sigF;
	}
	return NULL;
}

NodoMf* MatrizPD::posicionIns(int f) {
	NodoMf* aux = ptrFil;
	while (aux != NULL) {
		if (f < aux->fil)
			return aux;
		aux = aux->sigF;
	}
	return NULL;
}

void MatrizPD::suprimir(NodoMf* dirFil, NodoMc* dirCol) {
	if (dirCol == dirFil->ptrCol)
		dirFil->ptrCol = dirFil->ptrCol->sigC;
	else {
		NodoMc* ant;
		// Codido de anterior
		NodoMc* x = dirFil->ptrCol;
		ant = NULL;
		while (x != NULL) {
			if (x == dirCol)
				break;
			ant = x;
			x = x->sigC;
		}
		//
		ant->sigC = dirCol->sigC;
	}
	delete(dirCol);
	nt--;
	if (dirFil->ptrCol == NULL) {
		suprimir(dirFil);
	}
}

void MatrizPD::suprimir(NodoMf* dir) {
	if (dir == ptrFil) {
		ptrFil = ptrFil->sigF;
	}
	else {
		NodoMf* ant = dir->antF;
		NodoMf* sig = dir->sigF;
		ant->sigF = sig;
		if (sig != NULL)
			sig->antF = ant;
	}
	delete(dir);
}

void MatrizPD::insertar(int f, int c, int v) {
	NodoMc* x = new NodoMc;
	if (x != NULL) {
		x->col = c;
		x->dato = v;
		x->sigC = NULL;
		NodoMf* dirFila = buscar(f); // Buscamos si ya existe la fila
		if (dirFila != NULL)
		{ // Ya existe la fila, insertamos el nodo de columna
			x->sigC = dirFila->ptrCol;
			dirFila->ptrCol = x;
		}
		else { // Insercion nueva, hay dos casos
			NodoMf* xf = new NodoMf;
			if (xf != NULL) {
				xf->fil = f;
				xf->antF = NULL;
				xf->sigF = NULL;
				xf->ptrCol = NULL;
				NodoMf* posF = posicionIns(f);
				if (posF == NULL)
				{ // No  hay datos en los nodos o se tendra q insertar al final
					if (ptrFil == NULL) // No hay datos
							ptrFil = xf;
					else { // Insercion a lo ultimo
						NodoMf* fin = ptrFil;
						while (fin->sigF != NULL)
							fin = fin->sigF;
						xf->antF = fin;
						fin->sigF = xf;
					}
				}
				else { // Se inserta en el primero, o algun nodo que no sea al final
					if (posF == ptrFil) { // Inserta al inicio
						xf->sigF = ptrFil;
						ptrFil->antF = xf;
						ptrFil = xf;
					}
					else { // Insercion por el medio
						NodoMf* ant = posF->antF;
						NodoMf* sig = posF;
						xf->sigF = sig;
						xf->antF = ant;
						ant->sigF = xf;
						sig->antF = xf;
					}
				}
				x->sigC = xf->ptrCol;
				xf->ptrCol = x;
			}
		}
		nt++;
	}
	else
		cout << "ERROR NO EXISTE ESPACIO DE MEMORIA\n";
}

void MatrizPD::poner(int f, int c, int valor) {
	if (f >= 1 && f <= df && c >= 1 && c <= dc) {
		NodoMc* dir = buscar(f, c);
		if (dir != NULL) {
			dir->dato = valor;
			// Analizar si valor == repe
			if (valor == repe) {
				NodoMf* dirFila = buscar(f);
				suprimir(dirFila, dir);
			}
		}
		else if (valor != repe) // Insercion nueva
				insertar(f, c, valor);

	}
}

int MatrizPD::elemento(int f, int c) {
	if (f >= 1 && f <= df && c >= 1 && c <= dc) {
		NodoMc* dir = buscar(f, c);
		if (dir != NULL)
			return dir->dato;
		else
			return repe;
	}
}

void MatrizPD::definir_valor_repetido(int valor) {
	bool hayRepe = false;
	NodoMf* auxF = ptrFil;
	while (auxF != NULL && hayRepe == false) {
		NodoMc* auxC = auxF->ptrCol;
		while (auxC != NULL && hayRepe == false) {
			if (auxC->dato == valor)
				hayRepe = true;
			auxC = auxC->sigC;
		}
		auxF = auxF->sigF;
	}
	if (ptrFil == NULL || hayRepe == false) {
		repe = valor;
	}
	else {
		int nRep = valor;
		int aRep = repe;
		for (int i = 1; i <= df; i++) {
			for (int j = 1; j <= dc; j++) {
				int e = elemento(i, j);
				if (e == nRep) {
					NodoMf* dirF = buscar(i);
					NodoMc* dirC = buscar(i, j);
					suprimir(dirF, dirC);
				}
				else if (e == aRep)
					insertar(i, j, aRep);
			}
		}
		repe = valor;
	}
}

string MatrizPD::to_str() {
	string r = "";
	for (int i = 1; i <= df; i++) {
		r += "| ";
		for (int j = 1; j <= dc; j++) {
			int e = elemento(i, j);
			r += to_string(e) + "  ";
		}
		r += "|\n";
	}
	r += "NT: " + to_string(nt) + "\n";
	return r;
}
