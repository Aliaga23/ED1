//---------------------------------------------------------------------------

#pragma hdrstop

#include "Conjunto_Lis.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

ConjuntoListaPtr::ConjuntoListaPtr() {
	lista = new ListaPtr();
}

bool ConjuntoListaPtr::vacio() {
	return lista->vacia();
}

int ConjuntoListaPtr::cardinal() {
	return lista->longitud();
}

int ConjuntoListaPtr::ordinal(int e) {
	int c = 0;
	NodoLP* aux = lista->primero();
	while (aux != NULL) {
		c++; // empieza en 1
		if (lista->recupera(aux) == e) {
			return c;
		}
		aux = lista->siguiente(aux);
	}
	return -1;
}

void ConjuntoListaPtr::inserta(int e) {
	if (!pertenece(e)) {
		lista->inserta(lista->primero(), e);
	}
}

void ConjuntoListaPtr::insertaExamen(int e) {
	NodoLP* pertenece = lista->localiza(e);
	if (pertenece == NULL) { // significa que e no está en la lista
		lista->inserta(lista->primero(), e);
	}
	else
		cout << "ELEMENTO YA PERTENECE\n";
}

void ConjuntoListaPtr::insertaExamen1(int e) {
	NodoLP* aux = lista->primero();
	bool pertenece = false;
	while (aux != NULL) {
		if (aux->elemento == e) {
			pertenece = true;
			break;
		}
		else
			aux = aux->sig;
	}
	if (pertenece == false) {
		lista->inserta(lista->primero(), e);
	}
	else
		cout << "ELEMENTO YA PERTENECE\n";
}

void ConjuntoListaPtr::suprime(int e) {
	if (pertenece(e)) {
		NodoLP* nodo = lista->localiza(e);
		lista->suprime(nodo);
	}
}

bool ConjuntoListaPtr::pertenece(int e) {
	NodoLP* existe = lista->localiza(e);
	if (existe == NULL)
		return false;
	else
		return true;

}

int ConjuntoListaPtr::muestrea() {
	if (!vacio()) {
		srand(time(NULL));
		int pos = rand() % cardinal();
		return elemento(pos);
	}
	else
		return 0;
}

int ConjuntoListaPtr::elemento(int pos) {
	int c = 0;
	NodoLP* aux = lista->primero();
	while (aux != NULL) {
		if (c == pos) {
			return lista->recupera(aux);
		}
		c++;
		aux = lista->siguiente(aux);
	}
	return 0;
}

void ConjuntoListaPtr::reiniciar() {
	while (vacio() == false) {
		int r = muestrea();
		suprime(r);
	}
}

string ConjuntoListaPtr::toStr() {
	// return lista->toStr();
	string r = "{";
	for (int i = 0; i < cardinal(); i++) {
		r += to_string(elemento(i));
		if (i < cardinal() - 1) {
			r += ",";
		}
	}
	r += "}";
	return r;
}

void ConjuntoListaPtr::unir(ConjuntoListaPtr *b, ConjuntoListaPtr *c) {
	c->reiniciar();
	ConjuntoListaPtr *aux = new ConjuntoListaPtr();
	ConjuntoListaPtr *a = this;
	// Para insertar a en c
	while (a->vacio() == false) {
		int r = a->muestrea();
		c->inserta(r);
		a->suprime(r);
		aux->inserta(r);
	}
	// Para recuperar los datos de a
	while (aux->vacio() == false) {
		int r = aux->muestrea();
		aux->suprime(r);
		a->inserta(r);
	}
	// Para insertar b en c
	while (b->vacio() == false) {
		int r = b->muestrea();
		c->inserta(r);
		b->suprime(r);
		aux->inserta(r);
	}
	// Para recuperar los datos de b
	while (aux->vacio() == false) {
		int r = aux->muestrea();
		aux->suprime(r);
		b->inserta(r);
	}
}

void ConjuntoListaPtr::intersectar(ConjuntoListaPtr *b, ConjuntoListaPtr *c) {
	c->reiniciar();
	ConjuntoListaPtr* a = this;
	ConjuntoListaPtr* aux = new ConjuntoListaPtr();
	// Inserto si el elemento pertenece a A y a B
	while (a->vacio() == false) {
		int r = a->muestrea();
		if (a->pertenece(r) && b->pertenece(r)) {
			c->inserta(r);
		}
		a->suprime(r);
		aux->inserta(r);
	}
	// Recupero los elementos de a
	while (aux->vacio() == false) {
		int r = aux->muestrea();
		aux->suprime(r);
		a->inserta(r);
	}
}
/*
bool ConjuntoL::vacio() {
	return elem->vacia();
}

bool ConjuntoL::pertenece(int e) {
	if (!elem->vacia()) {
		NodoL* p = elem->primero();
		while (p != NULL) {
			int ele = elem->recupera(p);
			if (e == ele)
				return true;
			p = elem->siguiente(p);
		}
		return false;
	}
	else {
		cout << "ERROR CONJUNTO SIN ELEMENTOS\n";
		return false;
	}
}

void ConjuntoL::inserta(int e) {
	if (vacio())
		elem->inserta(elem->primero(), e);
	else if (!pertenece(e))
		elem->inserta(elem->primero(), e);
}

int ConjuntoL::cardinal() {
	return elem->longitud();
}

int ConjuntoL::ordinal(int e) {
	if (!elem->vacia()) {
		int c = 0;
		NodoL* p = elem->primero();
		while (p != NULL) {
			c++;
			int ele = elem->recupera(p);
			if (e == ele)
				return c;
			p = elem->siguiente(p);
		}
		return 0;
	}
	else {
		cout << "ERROR CONJUNTO SIN ELEMENTOS\n";
		return 0;
	}

}

void ConjuntoL::suprime(int e) {
	if (pertenece(e)) {
		NodoL* p = elem->primero();
		while (p != NULL) {
			int ele = elem->recupera(p);
			if (e == ele) {
				elem->suprime(p);
				return;
			}
			p = elem->siguiente(p);
		}
	}
	else
		cout << "ERROR EL CONJUNTO NO TIENE ESE ELEMENTO\n";
}

int ConjuntoL::muestrea() {
	if (!vacio()) {
		int lug = (rand() % cardinal()) + 1;
		NodoL* dir = elem->primero();
		int cont = 0;
		for (int i = 1; i <= cardinal(); i++) {
			cont++;
			if (cont == lug)
				return elem->recupera(dir);
			dir = elem->siguiente(dir);
		}
	}
}

string ConjuntoL::to_str() {
	string s = "{";
	NodoL* p = elem->primero();
	while (p != NULL) {
		int ele = elem->recupera(p);
		s += to_string(ele);
		if (p != elem->fin())
			s += ",";
		p = elem->siguiente(p);
	}
	return s + "}";

    void ConjuntoListaP::diferenciaSimetrica(ConjuntoListaP* b, ConjuntoListaP* c)
{
    c->reiniciar();

    ConjuntoListaP* a = this;
    ConjuntoListaP* aCopy = new ConjuntoListaP();
    ConjuntoListaP* bCopy = new ConjuntoListaP();

    // Copiar elementos de a y b a las copias
    while (!a->vacio()) {
        int elementoA = a->muestrea();
        a->suprime(elementoA);
        aCopy->inserta(elementoA);
    }

    while (!b->vacio()) {
        int elementoB = b->muestrea();
        b->suprime(elementoB);
        bCopy->inserta(elementoB);
    }

    // Encontrar elementos en aCopy que no están en bCopy
    while (!aCopy->vacio()) {
        int elementoA = aCopy->muestrea();
        if (!bCopy->pertenece(elementoA)) {
            c->inserta(elementoA);
        }
        aCopy->suprime(elementoA);
    }

    // Encontrar elementos en bCopy que no están en aCopy
    while (!bCopy->vacio()) {
        int elementoB = bCopy->muestrea();
        if (!aCopy->pertenece(elementoB)) {
            c->inserta(elementoB);
        }
        bCopy->suprime(elementoB);
    }

    // Liberar la memoria de las copias
    delete aCopy;
    delete bCopy;
}
}*/
