//---------------------------------------------------------------------------

#pragma hdrstop

#include "Conjunto_SM.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
ConjuntoSm::ConjuntoSm()
{
    mem = new CsMemoria();
    ptrConj = NULO;
    cant = 0;
}

ConjuntoSm::ConjuntoSm(CsMemoria* m)
{
    mem = m;
    ptrConj = NULO;
    cant = 0;
}

bool ConjuntoSm::vacio()
{
    return cant == 0;
}

int ConjuntoSm::cardinal()
{
    return cant;
}

int ConjuntoSm::ordinal(int e)
{
    int c = 0;
    int aux = ptrConj;
    while (aux != NULO) {
        c++; // empieza en 1
        int aux_dato = mem->obtener_dato(aux, dato); // (aux,"->dato")
        if (aux_dato == e) {
            return c;
        }
        aux = mem->obtener_dato(aux, c_sig); // (aux,"->sig")
    }
    return -1;
}

void ConjuntoSm::inserta(int e)
{
    if (!pertenece(e)) {
        int dir = mem->new_espacio(datos); // (dato,sig)
        if (dir != NULO) {
            mem->poner_dato(dir, dato, e); // dir->dato = e;
            mem->poner_dato(dir, c_sig, ptrConj); // dir->sig = ptrConj;
            ptrConj = dir;
            cant++;
        } else
            cout << "ERROR NO EXISTE ESPACIO EN LA MEMORIA\n";
    } else
        cout << "ERROR ELEMENTO YA EXISTE\n";
}

int ConjuntoSm::localiza(int e)
{
    int x = ptrConj;
    while (x != NULO) {
        int x_dato = mem->obtener_dato(x, dato);
        if (x_dato == e)
            return x;
        x = mem->obtener_dato(x, c_sig); // (x,"->sig"  x->sig;
    }
    return NULO;
}

int ConjuntoSm::anterior(int p)
{
    if (this->vacio()) {
    } else if (p == ptrConj) {
    } else {
        int x = ptrConj;
        int ant = NULO;
        while (x != NULO) {
            if (x == p) {
                return ant;
            }
            ant = x;
            x = mem->obtener_dato(x, c_sig); // (x,"->sig"  x->sig;
        }
    }
}

void ConjuntoSm::suprime(int e)
{
    int p = localiza(e);
    if (cant == 0) {
        return;
    } else if (p == ptrConj) {
        int x = ptrConj;
        ptrConj = mem->obtener_dato(ptrConj, c_sig); // ptrConj->sig;
        mem->delete_espacio(x); // delete(x);
    } else {
        int ant = anterior(p);
        int p_sig = mem->obtener_dato(p, c_sig); // p->sig;
        mem->poner_dato(ant, c_sig, p_sig); // ant->sig = p->sig;
        mem->delete_espacio(p); // delete(p);
    }
    cant--;
}

bool ConjuntoSm::pertenece(int e)
{
    int x = ptrConj;
    while (x != NULO) {
        int x_dato = mem->obtener_dato(x, dato);
        if (x_dato == e)
            return true;
        x = mem->obtener_dato(x, c_sig); // x->sig;
    }
    return false;
}

int ConjuntoSm::muestrea()
{
    if (!vacio()) {
        int lug = (rand() % cardinal()) + 1;
        int dir = ptrConj;
        int cont = 0;
        for (int i = 1; i <= cardinal(); i++) {
            cont++;
            if (cont == lug)
                return mem->obtener_dato(dir, dato); // dir->dato;
            dir = mem->obtener_dato(dir, c_sig); // dir = dir->sig;
        }
    }
}

int ConjuntoSm::elemento(int pos)
{
    int c = 0;
    int aux = ptrConj;
    while (aux != NULO) {
        if (c == pos)
            return mem->obtener_dato(aux, dato); // aux->dato;
        c++;
        aux = mem->obtener_dato(aux, c_sig); // aux->sig;
    }
    return 0;
}

void ConjuntoSm::reiniciar()
{
    while (vacio() == false) {
        int r = muestrea();
        suprime(r);
    }
}
/*  string ConjuntoSm::toStr() {
	string r = "{";
	for (int i = 0; i < cant; i++) {
		r += to_string(elemento(i));
		if (i < cant - 1) {
			r += ",";
		}
	}
	r += "}";
	return r;
}       */
string ConjuntoSm::to_str()
{
    string s = "{";
    int p = ptrConj;
    int c = 0;
    while (p != NULO) {
        c++;
        int ele = mem->obtener_dato(p, dato); // p->dato;
        s += to_string(ele);
        if (c < cant)
            s += ",";
        p = mem->obtener_dato(p, c_sig); // p->sig;
    }
    return s + "}";
}

void ConjuntoSm::unir(ConjuntoSm* b, ConjuntoSm* c)
{
    c->reiniciar();
    ConjuntoSm* aux = new ConjuntoSm();
    ConjuntoSm* a = this;
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

void ConjuntoSm::intersectar(ConjuntoSm* b, ConjuntoSm* c)
{
    c->reiniciar();
    ConjuntoSm* a = this;
    ConjuntoSm* aux = new ConjuntoSm();
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
ConjuntoSm* ConjuntoSm::complemento()
{
	ConjuntoSm* c =
		new ConjuntoSm(mem); // Pasa la memoria como parámetro al nuevo conjunto
	for (int i = 1; i <= max; i++)
	{ // Ajusta MAX según el rango de elementos posibles
		if (!pertenece(i)) {
			c->inserta(i);
		}
	}
	return c;
}
  */
  void ConjuntoSm::complementoAnB(ConjuntoSm* b, ConjuntoSm* c)
{
	c->reiniciar();
	ConjuntoSm* a = this;

    while (!a->vacio() && !b->vacio()) {
        int elementoA = a->muestrea();
		int elementoB = b->muestrea();

        if (elementoA != elementoB) {
            c->inserta(elementoA);
        }

        a->suprime(elementoA);
        b->suprime(elementoB);
    }

    // Agregar los elementos restantes de a a c, si los hay
    while (!a->vacio()) {
        int elementoA = a->muestrea();
        c->inserta(elementoA);
        a->suprime(elementoA);
	}
}

ConjuntoSm* ConjuntoSm::diferenciaSimetrica(ConjuntoSm* b)
{
	ConjuntoSm* a = this;
	ConjuntoSm* c = new ConjuntoSm();

	ConjuntoSm* aCopy = new ConjuntoSm();
	ConjuntoSm* bCopy = new ConjuntoSm();

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

	return c;
}
/*
void ordenarConjunto(ConjuntoSm* original, ConjuntoSm* ordenado) {
	while (!original->vacio()) {
		int menor = original->muestrea();
		int elemento = menor;

		// Encuentra el elemento más pequeño en el conjunto original
		while (!original->vacio()) {
			int actual = original->muestrea();
			if (actual < menor) {
				menor = actual;
			}
		}

		// Mueve el elemento más pequeño al conjunto ordenado
		ordenado->inserta(menor);

		// Elimina el elemento más pequeño del conjunto original
		original->suprime(menor);
	}
}
   */
	 void ConjuntoSm::ordenarConjunto()
{
    if (vacio() || cant == 1) {
        // El conjunto está vacío o ya está ordenado
		return;
    }

    int minElemento;
    int pActual, pMin, pSiguiente;

    pActual = ptrConj;

    while (pActual != NULO) {
        pMin = pActual;
        minElemento = mem->obtener_dato(pActual, dato);

        pSiguiente = mem->obtener_dato(pActual, c_sig);
        while (pSiguiente != NULO) {
            int elementoActual = mem->obtener_dato(pSiguiente, dato);
            if (elementoActual < minElemento) {
                minElemento = elementoActual;
                pMin = pSiguiente;
            }
            pSiguiente = mem->obtener_dato(pSiguiente, c_sig);
        }

        // Intercambiar los elementos
        int temp = mem->obtener_dato(pActual, dato);
        mem->poner_dato(pActual, dato, minElemento);
        mem->poner_dato(pMin, dato, temp);

        pActual = mem->obtener_dato(pActual, c_sig);
    }
}
/*void ConjuntoSm::ordenarConjunto() {
    if (vacio() || cant == 1) {
        // El conjunto está vacío o ya está ordenado
        return;
    }

    int pActual, pMin, pSiguiente;

    pActual = ptrConj;

    while (pActual != NULO) {
        pMin = pActual;

        pSiguiente = mem->obtenerDato(pActual, c_sig);
        while (pSiguiente != NULO) {
            int elementoActual = mem->obtenerDato(pSiguiente, dato);
            int elementoMin = mem->obtenerDato(pMin, dato);

            if (elementoActual < elementoMin) {
                pMin = pSiguiente;
            }
            pSiguiente = mem->obtenerDato(pSiguiente, c_sig);
        }

        // Intercambiar los elementos
        if (pMin != pActual) {
            // Intercambia los datos de los elementos
            int datoActual = mem->obtenerDato(pActual, dato);
            int datoMin = mem->obtenerDato(pMin, dato);
            mem->ponerDato(pActual, dato, datoMin);
            mem->ponerDato(pMin, dato, datoActual);
        }

        pActual = mem->obtenerDato(pActual, c_sig);
    }
}
*/

