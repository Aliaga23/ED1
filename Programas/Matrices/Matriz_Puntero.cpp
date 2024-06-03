//---------------------------------------------------------------------------

#pragma hdrstop

#include "Matriz_Puntero.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
MatrizPC::MatrizPC()
{
    ptrMatD = NULL;
    df = dc = repe = 0;
    nt = 0;
}

void MatrizPC::dimensionar(int f, int c)
{
    df = f;
    dc = c;
}

int MatrizPC::dimension_fila()
{
    return df;
}

int MatrizPC::dimension_columna()
{
    return dc;
}

NodoMC* MatrizPC::buscar(int f, int c)
{
    NodoMC* aux = ptrMatD;
    while (aux != NULL) {
        if (aux->fil == f && aux->col == c)
            return aux;
        aux = aux->sig;
    }
    return NULL;
}

void MatrizPC::poner(int f, int c, int valor)
{
    if (f >= 1 && f <= df && c >= 1 && c <= dc) {
        NodoMC* dir = buscar(f, c);
        if (dir == NULL && valor != repe) { // Dato nuevo
            NodoMC* x = new NodoMC;
            if (x != NULL) {
                x->fil = f;
                x->col = c;
                x->dato = valor;
                x->sig = ptrMatD;
                ptrMatD = x;
                nt++;
            } else
                cout << "ERROR NO EXISTE ESPACIO DE MEMORIA\n";
        } else {
            dir->dato = valor;
            if (valor == repe) {
                // Codigo de suprimir
                if (dir == ptrMatD)
                    ptrMatD = ptrMatD->sig;
                else {
                    NodoMC* ant;
                    // Codido de anterior
                    NodoMC* x = ptrMatD;
                    ant = NULL;
                    while (x != NULL) {
                        if (x == dir)
                            break;
                        ant = x;
                        x = x->sig;
                    }
                    //
                    ant->sig = dir->sig;
                }
                delete (dir);
                nt--;
                //
            }
        }
    }
}

int MatrizPC::elemento(int f, int c)
{
    if (f >= 1 && f <= df && c >= 1 && c <= dc) {
        NodoMC* dir = buscar(f, c);
        if (dir != NULL)
            return dir->dato;
        else
            return repe;
    }
}

void MatrizPC::definir_valor_repetido(int valor)
{
    bool hayRepe = false;
    NodoMC* aux = ptrMatD;
    while (aux != NULL && hayRepe == false) {
        if (aux->dato == valor)
            hayRepe = true;
        aux = aux->sig;
    }
    if (ptrMatD == NULL || hayRepe == false) {
        repe = valor;
    } else {
        int nRep = valor;
        int aRep = repe;
        for (int i = 1; i <= df; i++) {
            for (int j = 1; j <= dc; j++) {
                int e = elemento(i, j);
                if (e == nRep) {
                    NodoMC* dir = buscar(i, j);
                    // Codigo de suprimir
                    if (dir == ptrMatD)
                        ptrMatD = ptrMatD->sig;
                    else {
                        NodoMC* ant;
                        // Codido de anterior
                        NodoMC* x = ptrMatD;
                        ant = NULL;
                        while (x != NULL) {
                            if (x == dir)
                                break;
                            ant = x;
                            x = x->sig;
                        }
                        //
                        ant->sig = dir->sig;
                    }
                    delete (dir);
                    nt--;
                    //
                } else if (e == aRep) {
                    NodoMC* x = new NodoMC;
                    if (x != NULL) {
                        x->fil = i;
                        x->col = j;
                        x->dato = aRep;
                        x->sig = ptrMatD;
                        ptrMatD = x;
                        nt++;
                    } else
                        cout << "ERROR NO EXISTE ESPACIO DE MEMORIA\n";
                }
            }
        }
        repe = valor;
    }
}

string MatrizPC::to_str()
{
 string r = "";
	for (int i = 1; i <= df; i++) {
		r += "| ";
		for (int j = 1; j <= dc; j++) {
			int e = elemento(i, j);
			r += to_string(e);
			// A�ade espacios para alinear los n�meros
			int espacios = 6 - to_string(e).length();
			r += string(espacios, ' ');
		}
		r += "|\n";
	}
	r += "NT: " + to_string(nt) + "\n";
    return r;
}
void MatrizPC::transponer() {
	MatrizPC transpuesta;
    transpuesta.dimensionar(dc, df);  // Intercambiar las dimensiones

    for (int i = 1; i <= df; i++) {
        for (int j = 1; j <= dc; j++) {
            int valor = elemento(i, j);
            transpuesta.poner(j, i, valor);  // Intercambiar elementos
        }
    }

    // Ahora 'transpuesta' contiene la matriz transpuesta
    // Copiar 'transpuesta' de vuelta a 'this' para asignar la transpuesta a la matriz original
    *this = transpuesta;
}
//bool MatrizPC::esSimetrica() {
//	if (df != dc) {
//		// Si el n�mero de filas no es igual al n�mero de columnas, no puede ser sim�trica.
//		return false;
//	}
//
//	// Compara la matriz original con su traspuesta
//	for (int i = 1; i <= df; i++) {
//		for (int j = 1; j <= dc; j++) {
//			if (elemento(i, j) != elemento(j, i)) {
//				// Si se encuentra al menos un elemento diferente, la matriz no es sim�trica.
//				return false;
//			}
//		}
//	}
//
//	// Si no se encontraron elementos diferentes, la matriz es sim�trica.
//	return true;
//}

//void esSimetrica(MatrizPC* matriz) {
//	if (matriz->dimension_fila() != matriz->dimension_columna()) {
//		cout << "La matriz no es sim�trica, ya que el n�mero de filas no es igual al n�mero de columnas." << endl;
//		return;
//	}
//
//	bool esSimetrica = true;
//
//	for (int i = 1; i <= matriz->dimension_fila(); i++) {
//		for (int j = 1; j <= matriz->dimension_columna(); j++) {
//			if (matriz->elemento(i, j) != matriz->elemento(j, i)) {
//				esSimetrica = false;
//				break;
//			}
//		}
//		if (!esSimetrica) {
//			break;
//		}
//	}
//
//	if (esSimetrica) {
//		cout << "La matriz es sim�trica." << endl;
//	} else {
//		cout << "La matriz no es sim�trica." << endl;
//	}
//}



