﻿//---------------------------------------------------------------------------

#pragma hdrstop

#include "Poli_SM.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#include <vector>
#include <algorithm>
PoliS::PoliS()
{
    mem = new CsMemoria();
    ptr_poli = NULO;
    nt = 0;
}

PoliS::PoliS(CsMemoria* m)
{
    mem = m;
    ptr_poli = NULO;
    nt = 0;
}

// mem->obtener_dato(dir,expP)
// mem->obtener_dato(dir,sigP)
// mem->obtener_dato(dir,coefP)
int PoliS::buscar_exponente(int exp)
{
    int dir = ptr_poli;
    if (dir != NULO) {
        int dir_ex = NULO;
        while (dir != NULO && dir_ex == NULO) {
            if (mem->obtener_dato(dir, expP) == exp) // dir->exp == exp
                dir_ex = dir;
            dir = mem->obtener_dato(dir, sigP); // dir->sig
        }
        return dir_ex;
    } else {
        cout << "EXCEPTION NO EXISTE ESE TERMINO\n";
        return NULO;
    }
}

int PoliS::buscar_termino_n(int i)
{
    int dir = ptr_poli;
    if (dir != NULO) {
        int dir_ter = NULO;
        int nt = 0;
        while (dir != NULO && dir_ter == NULO) {
            nt++;
            if (nt == i)
                dir_ter = dir;
            dir = mem->obtener_dato(dir, sigP); // dir->sig;
        }
        return dir_ter;
    } else {
        cout << "EXCEPTION NO EXISTE ESE TERMINO\n";
        return NULO;
    }
}

bool PoliS::es_cero()
{
    return nt == 0;
}

int PoliS::grado()
{
    int dir = ptr_poli;
    if (dir != NULO) {
        int max_grado = mem->obtener_dato(dir, expP); // dir->exp;
        while (dir != NULO) {
            if (mem->obtener_dato(dir, expP) > max_grado)
                // (dir->exp > max_grado)
                max_grado = mem->obtener_dato(dir, expP); // dir->exp;
            dir = mem->obtener_dato(dir, sigP); // dir->sig;
        }
        return max_grado;
    } else
        cout << "POLINOMIO NO TIENE TERMINOS\n";
}

int PoliS::coeficiente(int exp)
{
    int dir = buscar_exponente(exp);
    if (dir != NULO)
        return mem->obtener_dato(dir, coefP); // dir->coef;
    else
        cout << "POLINOMO NO TIENE ESTE TERMINO\n";
}

int PoliS::anterior(int dir)
{
    int x = ptr_poli;
    ;
    int ant = NULO;
    while (x != NULO) {
        if (x == dir)
            return ant;
        ant = x;
        x = mem->obtener_dato(x, sigP); // x->sig;
    }
    return NULO;
}

void PoliS::asignar_coeficiente(int coef, int exp)
{
    int dir = buscar_exponente(exp);
    if (dir != NULO) {
        mem->poner_dato(dir, coefP, coef); // dir->coef = coef;
        if (coef == 0) {
            if (dir == ptr_poli) { // Se elimina el primero
                ptr_poli = mem->obtener_dato(ptr_poli, sigP); // ptr_poli->sig;
            } else {
                int ant = anterior(dir);
                int dir_sig = mem->obtener_dato(dir, sigP); // dir->sig
                mem->poner_dato(ant, sigP, dir_sig); // ant->sig = dir_sig;
            }
            mem->delete_espacio(dir); // delete(dir);
            nt--;
        }
    } else
        cout << "POLINOMO NO TIENE ESTE TERMINO\n";
}

/*
 void PoliS::asignar_coeficiente(int coef, int exp) {
 int dir = buscar_exponente(exp);
 if (dir != NULO) {
 dir->coef = coef;
 if (coef == 0) {
 if (dir == ptr_poli) { // Se elimina el primero
 ptr_poli = ptr_poli->sig;
 }
 else {
 //-----------------
 int x = ptr_poli; ;
 int ant = NULO;
 while (x != NULO) {
 if (x == dir)
 break;
 ant = x;
 x = x->sig;
 }
 //-----------------
 ant->sig = dir->sig;
 }
 delete(dir);
 nt--;
 }
 }
 else
 cout << "POLINOMO NO TIENE ESTE TERMINO\n";
 } */

// mem->obtener_dato(dir,expP)
// mem->obtener_dato(dir,sigP)
// mem->obtener_dato(dir,coefP)
// mem->poner_dato(dir, coefP, coef); dir->coef = coef;
// mem->poner_dato(ant, sigP, dir_sig); dir_sig = mem->obtener_dato(dir,sigP)
// int aux = mem->new_espacio("coef,exp,sig");
void PoliS::poner_termino(int coef, int exp)
{
    if (coef != 0 && exp >= 0) {
        int existe = buscar_exponente(exp);
        if (existe == NULO) { // Nueva Insercion
            int aux = mem->new_espacio(datosP);
            // NodoP* aux = new NodoP();
            if (aux != NULO) {
                mem->poner_dato(aux, coefP, coef); // aux->coef = coef;
                mem->poner_dato(aux, expP, exp); // aux->exp = exp;
				mem->poner_dato(aux, sigP, ptr_poli); // aux->sig = ptr_poli;
                ptr_poli = aux;
				nt++;
            } else
                cout << "NO EXISTE ESPACIO MEMORIA\n";
        } else { // Modificar
            int nuevo_coef = mem->obtener_dato(existe, coefP) + coef;
            // existe->coef + coef
            mem->poner_dato(existe, coefP, nuevo_coef);
            // existe->coef = nuevo_coef;
            if (nuevo_coef == 0) {
                if (existe == ptr_poli) { // Se elimina el primero
                    ptr_poli = mem->obtener_dato(ptr_poli, sigP);
                    // ptr_poli->sig;
                } else {
                    int ant = anterior(existe);
                    int existe_sig = mem->obtener_dato(existe, sigP);
                    // existe->sig
                    mem->poner_dato(ant, sigP, existe_sig);
                    // ant->sig = existe_sig;
                }
                mem->delete_espacio(existe); // delete(existe);
                nt--;
            }
        }
    }
}

int PoliS::numero_terminos()
{
    return nt;
}

int PoliS::exponente(int nro)
{
    int dir = buscar_termino_n(nro);
    if (dir != NULO)
        return mem->obtener_dato(dir, expP); // dir->exp;
    else
        cout << "NO EXISTE ESE NUMERO DE TERMINO\n";
}

void PoliS::sumar(PoliS* p1, PoliS* p2, PoliS*&pr)
{
    pr = new PoliS();
    for (int i = 1; i <= p1->numero_terminos(); i++) {
        int ex = p1->exponente(i);
        int co = p1->coeficiente(ex);
        pr->poner_termino(ex, co);
    }
    for (int i = 1; i <= p2->numero_terminos(); i++) {
        int ex = p2->exponente(i);
        int co = p2->coeficiente(ex);
        pr->poner_termino(ex, co);
    }
}

void PoliS::restar(PoliS* p1, PoliS* p2, PoliS*&pr)
{
    pr = new PoliS();
    for (int i = 1; i <= p1->numero_terminos(); i++) {
        int ex = p1->exponente(i);
        int co = p1->coeficiente(ex);
        pr->poner_termino(ex, co);
    }
    for (int i = 1; i <= p2->numero_terminos(); i++) {
        int ex = p2->exponente(i);
        int co = p2->coeficiente(ex);
        pr->poner_termino(-ex, co);
    }
}

void PoliS::multiplicar(PoliS* p1, PoliS* p2, PoliS*& pr)
{
    pr = new PoliS(); // Inicializa el polinomio resultado pr

    for (int i = 1; i <= p1->numero_terminos(); i++) {
        for (int j = 1; j <= p2->numero_terminos(); j++) {
            int coef1 = p1->coeficiente(p1->exponente(i));
            int coef2 = p2->coeficiente(p2->exponente(j));
            int exp1 = p1->exponente(i);
            int exp2 = p2->exponente(j);

            int nuevo_coef = coef1 * coef2;
            int nuevo_exp = exp1 + exp2;

            pr->poner_termino(nuevo_coef, nuevo_exp); // Agrega el término al polinomio resultado pr
        }
    }
}
void PoliS::derivar()
{
    int n = numero_terminos();
    int* exn = new int[n];
	int* con = new int[n];
    int c = 0;
    while (!es_cero()) {
        int ex = exponente(1);
        int co = coeficiente(ex);
        poner_termino(-co, ex);
        exn[c] = ex;
        con[c] = co;
        c++;
    }
    for (int i = 0; i < n; i++) {
        int ex = exn[i];
        int co = con[i];
        poner_termino(co * ex, ex - 1);
    }
}

string PoliS::to_str()
{ /*     PUEDE SERVIR PARA ORDENAR
	vector<pair<int, int>> terminos; // Almacena pares (coeficiente, exponente)

	// Recorrer todos los términos y agregarlos a la estructura temporal
	for (int i = 1; i <= numero_terminos(); i++) {
		int ex = exponente(i);
		int co = coeficiente(ex);
		terminos.push_back(make_pair(co, ex));
	}

	// Ordenar los términos en función del exponente de manera ascendente
	sort(terminos.begin(), terminos.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
		return a.second < b.second;
	});

	// Construir la cadena de caracteres a partir de los términos ordenados
	string s = "";
	for (const auto& termino : terminos) {
		int co = termino.first;
		int ex = termino.second;
		if (co > 0)
			s += "+";
		s += to_string(co) + "x^" + to_string(ex);
	}

	return s;*/
    string s = "";
    for (int i = numero_terminos(); i >= 1; i--) {
        int ex = exponente(i);
        int co = coeficiente(ex);
        if (co > 0)
            s += "+";
        s += to_string(co) + "x^" + to_string(ex);
    }
    return s;
}
float PoliS::evalua(float x)
{      /*
	int dir = ptr_poli;
	float resultado = 0.0;

	while (dir != NULO) {
		int coeficiente = mem->obtener_dato(dir, coefP);
		int exponente = mem->obtener_dato(dir, expP);
		int siguiente = mem->obtener_dato(dir, sigP);

		float termino = coeficiente * pow(x, exponente);
		resultado += termino;

		dir = siguiente;
	}

	// Almacena el resultado en la memoria simulada
	int resultado_dir = mem->new_espacio("eva");
	mem->poner_dato(resultado_dir, "->eva", resultado);

	return resultado; // Devuelve la dirección donde se almacenó el resultado

	*/

    float resultado = 0.0;
    int dir = ptr_poli;

    while (dir != NULO) {
        int coeficiente = mem->obtener_dato(dir, coefP);
        int exponente = mem->obtener_dato(dir, expP);
        int siguiente = mem->obtener_dato(dir, sigP);

        float termino = coeficiente * pow(x, exponente);
        resultado += termino;

        dir = siguiente;
    }

    return resultado;
}
void PoliS::ordenar()
{
	vector<pair<int, int>> terminos; // Almacena pares (coeficiente, exponente)

    // Recorrer todos los términos y agregarlos a la estructura temporal
    for (int i = 1; i <= numero_terminos(); i++) {
        int ex = exponente(i);
        int co = coeficiente(ex);
        terminos.push_back(make_pair(co, ex));
    }

	// Ordenar los términos en función del exponente de manera ascendente
	sort(terminos.begin(), terminos.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
		return a.second < b.second;
	});

    // Actualizar la estructura en memoria con los términos ordenados
	int dir_actual = ptr_poli;
    for (const auto& termino : terminos) {
        int co = termino.first;
        int ex = termino.second;

        // Actualizar el coeficiente y exponente en memoria
        mem->poner_dato(dir_actual, coefP, co);
        mem->poner_dato(dir_actual, expP, ex);

        dir_actual = mem->obtener_dato(dir_actual, sigP); // Avanzar al siguiente término
    }
}
void PoliS::mostrar_integral()
{
	for (int i = 0; i < numero_terminos(); i++) {
		int exp = exponente(i + 1);
		int coef = coeficiente(exp);
		cout << "(" << coef << "x^" << (exp + 1) << ")/" << (exp + 1);
		if (i < numero_terminos() - 1)
			cout << "+";
	}
	cout << endl;
}
