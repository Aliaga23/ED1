//---------------------------------------------------------------------------

#pragma hdrstop

#include "ListasPtr.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
 ListaPtr::ListaPtr() {
	longi = 0;
	ptrElementos = NULL;
}

// Funciones de direccion
NodoLP* ListaPtr::fin() {
	if (vacia()) {
		cout << "LISTA VACIA\n";
	}
	else {
		NodoLP* ptrFin;
		NodoLP* x = ptrElementos;
		while (x != NULL) {
			ptrFin = x;
			x = x->sig;
		}
		return ptrFin;
	}
}

NodoLP* ListaPtr::primero() {
	return ptrElementos;
}

NodoLP* ListaPtr::siguiente(NodoLP* p) {
	if (this->vacia()) {
		//cout << "LISTA VACIA\n";
		return NULL;
	}
	else {
		return p->sig;
	}
}

NodoLP* ListaPtr::anterior(NodoLP* p) {
	if (this->vacia()) {
		cout << "LISTA VACIA\n";
	}
	else if (p == primero()) {
		cout << "DIRECCION INCORRECTA\n";
	}
	else {
		NodoLP* x = ptrElementos;
		NodoLP* ant = NULL;
		while (x != NULL) {
			if (x == p) {
				return ant;
			}
			ant = x;
			x = x->sig;
		}
	}
}

// Selector
int ListaPtr::recupera(NodoLP* p) {
	if (this->vacia()) {
//		cout << "LISTA VACIA\n";
		return 0;
	}
	else {
		return p->elemento;
	}
}

// modificadores
void ListaPtr::inserta(NodoLP* p, int e) {
	NodoLP* x = new NodoLP;
	if (x != NULL) {
		x->elemento = e;
		x->sig = NULL;
		if (vacia()) {
			ptrElementos = x;
			longi = 1;
		}
		else {
			longi++;
			if (p == primero()) {
				x->sig = p;
				ptrElementos = x;
			}
			else {
				NodoLP* ant = anterior(p);
				ant->sig = x;
				x->sig = p;
			}
		}
	}
}

void ListaPtr::suprime(NodoLP* p) {
	if (longi == 0) {
		cout << "LISTA VACIA\n";
		return;
	}
	else if (p == ptrElementos) {
		NodoLP*x = ptrElementos;
		ptrElementos = ptrElementos->sig;
		delete(x);
	}
	else {
		NodoLP* ant = anterior(p);
		ant->sig = p->sig;
		delete(p);
	}
	longi--;
}

void ListaPtr::modifica(NodoLP* p, int e) {
	if (vacia()) {
		cout << "LISTA VACIA\n";
	}
	else {
		p->elemento = e;
	}
}

//
bool ListaPtr::vacia() {
	return longi == 0; // ptrElementos == NULL;
}

int ListaPtr::longitud() {
	return longi;
}

string ListaPtr::toStr() {
	string r = "[";
	NodoLP* x = ptrElementos;
	while (x != NULL) {
		r += to_string(x->elemento);
		if (x->sig != NULL)
			r += ",";
		x = x->sig;
	}
	r = r + "]";
	return r;
}

//
NodoLP* ListaPtr::localiza(int e) {
	NodoLP* x = ptrElementos;
	while (x != NULL) {
		if (x->elemento == e)
			return x;
		x = x->sig;
	}
	return NULL;
}

void ListaPtr::elimina_dato(int e) {
	NodoLP* x = ptrElementos;
	while (x != NULL) {
		if (x->elemento == e) {
			NodoLP* sup = x;
			x = x->sig;
			suprime(sup);
		}
		else {
			x = x->sig;
		}
	}
}

void ListaPtr::anula() {
	longi = 0;
	NodoLP* x = ptrElementos;
	while (x != NULL) {
		NodoLP* aux = x;
		x = x->sig;
		delete(aux);
	}
	ptrElementos = NULL;
}

void ListaPtr::inserta_inicio(int e) {
	inserta(ptrElementos, e);
}

void ListaPtr::inserta_fin(int e) {
	NodoLP* x = new NodoLP;
	x->elemento = e;
	x->sig = NULL;
	if (vacia()) {
		ptrElementos = x;
	}
	else {
		NodoLP* final = fin();
		final->sig = x;
	}
	longi++;
}

void ListaPtr::muestra_nodos() {
	cout << "ptrElementos --> ";
	if (vacia()) {
		cout << "NULL";
	}
	else {
		NodoLP* aux = ptrElementos;
		while (aux != NULL) {
			cout << "Nodo direccion: " << &(*aux);
			cout << " | Nodo dato: " << aux->elemento;
			if (aux->sig == NULL)
				cout << " | Nodo sig: NULL";
			else
				cout << " | Nodo sig: " << &(*aux->sig);
			aux = aux->sig;
			cout << endl << "                 ";
		}
	}
	cout << endl;
}

bool ListaPtr::es_palindroma() {
	if (this->vacia()) {
		cout << "LISTA VACIA" << endl;
		return false;
	}
	else if (this->longitud() == 1) {
		return true;
	}
	else {
		NodoLP* adelante;
		NodoLP* atras;
		adelante = primero();
		atras = fin();
		while (atras->sig != adelante && atras != adelante) {
			if (adelante->elemento != atras->elemento) {
				return false;
			}
			adelante = siguiente(adelante);
			atras = anterior(atras);
		}
		return true;
	}
}

void ListaPtr::inserta(int k, int elem) {
	// funciona cuando hay 1 o mas datos en la lista
	if (k >= 0 && k < longi) {
		NodoLP* nuevo_nodo = new NodoLP;
		nuevo_nodo->elemento = elem;
		nuevo_nodo->sig = NULL;
		if (k == 0) {
			nuevo_nodo->sig = ptrElementos;
			ptrElementos = nuevo_nodo;
		}
		else {
			NodoLP* aux = ptrElementos;
			int cont = 0;
			while (cont < k && aux != NULL) {
				aux = aux->sig;
				cont++;
			}
			NodoLP* ant = anterior(aux);
			ant->sig = nuevo_nodo;
			nuevo_nodo->sig = aux;

		}
	}
}

void ListaPtr::elimina_nodo_con_mayor_dato() {
	if (this->vacia()) {
		return;
	}
	else if (this->longi == 1) {
		this->suprime(this->primero());
	}
	else {
		NodoLP* elim;
		NodoLP* recorre;
		// elim = ptrElementos;
		// recorre = ptrElementos;
		elim = recorre = ptrElementos;
		while (recorre != NULL) {
			if (recorre->elemento > elim->elemento) {
				elim = recorre;
			}
			recorre = recorre->sig;
		}
		this->suprime(elim);
	}
}

// Lista: 5,3,2,4,3,10,5,6 ----> Lista Nueva: 2,4,3,10,5,6
ListaPtr* ListaPtr::sin_repetidos_ptr() {
	// Copia de la lista original
	ListaPtr* nueva = new ListaPtr();
	NodoLP* aux = ptrElementos;
	while (aux != NULL) {
		nueva->inserta_fin(aux->elemento);
		aux = aux->sig;
	}
	//
	NodoLP* nodo1 = nueva->primero();
	while (nodo1 != nueva->fin()) {
		NodoLP* nodo2 = nueva->siguiente(nodo1);
		bool repetido = false;
		while (nodo2 != NULL && repetido == false) {
			if (nodo1->elemento == nodo2->elemento) {
				repetido = true;
			}
			nodo2 = nodo2->sig;
		}
		if (repetido == true) {
			NodoLP* elim = nodo1;
			nodo1 = nodo1->sig;
			nueva->suprime(elim);
		}
		else {
			nodo1 = nodo1->sig;
		}
	}
	return nueva;
}

ListaPtr ListaPtr::sin_repetidos() {
	ListaPtr nueva;
	NodoLP* aux = ptrElementos;
	while (aux != NULL) {
		nueva.inserta_fin(aux->elemento);
		aux = aux->sig;
	}
	//
	NodoLP* nodo1 = nueva.primero();
	while (nodo1 != nueva.fin()) {
		NodoLP* nodo2 = nueva.siguiente(nodo1);
		bool repetido = false;
		while (nodo2 != NULL && repetido == false) {
			if (nodo1->elemento == nodo2->elemento) {
				repetido = true;
			}
			nodo2 = nodo2->sig;
		}
		if (repetido == true) {
			NodoLP* elim = nodo1;
			nodo1 = nodo1->sig;
			nueva.suprime(elim);
		}
		else {
			nodo1 = nodo1->sig;
		}
	}
	return nueva;
}

void ListaPtr::intercambio(NodoLP* nodo1, NodoLP* nodo2) {
	if (nodo1 == ptrElementos) {
		if (nodo1->sig == nodo2) {
			nodo1->sig = nodo2->sig;
			nodo2->sig = nodo1;
			ptrElementos = nodo2;
		}
		else {
			NodoLP* sigNodo1 = nodo1->sig;
			NodoLP* antNodo2 = anterior(nodo2);
			nodo1->sig = nodo2->sig;
			nodo2->sig = sigNodo1;
			antNodo2->sig = nodo1;
			ptrElementos = nodo2;
		}
	}
	else {
		if (nodo1->sig == nodo2) {
			NodoLP* antNodo1 = anterior(nodo1);
			nodo1->sig = nodo2->sig;
			antNodo1->sig = nodo2;
			nodo2->sig = nodo1;
		}
		else {
			NodoLP* antNodo1 = anterior(nodo1);
			NodoLP* sigNodo1 = nodo1->sig;
			NodoLP* antNodo2 = anterior(nodo2);
			nodo1->sig = nodo2->sig;
			antNodo1->sig = nodo2;
			nodo2->sig = sigNodo1;
			antNodo2->sig = nodo1;
		}
	}
}

void ListaPtr::ordenamiento() {
	int n = this->longitud();
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			NodoLP* nodo1 = nodoEnPosicion(i);
			NodoLP* nodo2 = nodoEnPosicion(j);
			int elem2 = nodo2->elemento;
			int elem1 = nodo1->elemento;
			if (elem2 < elem1) {
				intercambio(nodo1, nodo2);
			}
		}
	}
}

NodoLP* ListaPtr::nodoEnPosicion(int k) {
	if (this->vacia()) {
		return NULL;
	}
	else {
		NodoLP* aux = ptrElementos;
		int cont = 0;
		while (cont < k) {
			aux = aux->sig;
			cont++;
		}
		return aux;
	}
}
