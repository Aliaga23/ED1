//---------------------------------------------------------------------------

#pragma hdrstop

#include "Matriz_SM.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

MatrizSM::MatrizSM() {
	mem = new CsMemoria();
	ptrMatD = NULO;
	df = 0;
	dc = 0;
	repe = 0;
	nt=0;
}

MatrizSM::MatrizSM(CsMemoria* m)
{
	mem = m;
	ptrMatD = NULO;
	df = dc = repe = 0;
	nt = 0;
}

void MatrizSM::dimensionar(int f, int c)
{
    df = f;
    dc = c;
}

int MatrizSM::dimension_fila()
{
    return df;
}

int MatrizSM::dimension_columna()
{
    return dc;
}

int MatrizSM::existe(int f, int c)
{
    int aux = ptrMatD;
    while (aux != NULO) {
        int aux_fil = mem->obtener_dato(aux, filMC);
        int aux_col = mem->obtener_dato(aux, colMC);
        if (aux_fil == f && aux_col == c)
            return aux;
        int aux_sig = mem->obtener_dato(aux, sigMC);
        aux = aux_sig;
    }
    return NULO;
}

int MatrizSM::anterior(int p)
{
    if (nt == 0 || p == ptrMatD) {
        return NULO;
    } else {
        int x = ptrMatD;
        int ant = NULO;
        while (x != NULO) {
            if (x == p) {
                return ant;
            }
            ant = x;
            int x_sig = mem->obtener_dato(x, sigMC);
            x = x_sig;
        }
    }
}

void MatrizSM::suprime(int p)
{
    if (nt == 0) {
        return;
    } else if (p == ptrMatD) {
        int x = ptrMatD;
        int ptrMatD_sig = mem->obtener_dato(ptrMatD, sigMC);
        ptrMatD = ptrMatD_sig;
        mem->delete_espacio(x);
    } else {
        int ant = anterior(p);
        int p_sig = mem->obtener_dato(p, sigMC);
        mem->poner_dato(ant, sigMC, p_sig);
        mem->delete_espacio(p);
    }
}

void MatrizSM::poner(int f, int c, int valor)
{
    if (f >= 1 && f <= df && c >= 1 && c <= dc) {
        int pos = existe(f, c);
        if (pos == NULO && valor != repe) {
            int nuevo = mem->new_espacio(dataMC);
            mem->poner_dato(nuevo, filMC, f);
            mem->poner_dato(nuevo, colMC, c);
            mem->poner_dato(nuevo, datoMC, valor);
            mem->poner_dato(nuevo, sigMC, ptrMatD);
            ptrMatD = nuevo;
            nt++;
        } else {
            mem->poner_dato(pos, datoMC, valor);
            if (valor == repe) {
                suprime(pos);
                nt--;
            }
        }
    }
}

int MatrizSM::elemento(int f, int c)
{
    if (f >= 1 && f <= df && c >= 1 && c <= dc) {
        int pos = existe(f, c);
        if (pos != NULO) {
            int pos_dato = mem->obtener_dato(pos, datoMC);
            return pos_dato;
        } else
            return repe;
    }
    return 0;
}

void MatrizSM::definir_valor_repetido(int valor)
{
    repe = valor;
}

string MatrizSM::to_str()
{
    string r = "";
    for (int i = 1; i <= df; i++) {
        r += "| ";
        int espacios = 3;
        r += string(espacios, ' ');
        for (int j = 1; j <= dc; j++) {
            int e = elemento(i, j);
            r += to_string(e);
            // Añade espacios para alinear los números
            int espacios = 7 - to_string(e).length();
			r += string(espacios, ' ');
        }
        r += "|\n";
    }
    r += "NT: " + to_string(nt) + "\n";
    return r;
}
void MatrizSM::transponer() {
    int temp_df = dc;  // Intercambia las dimensiones
    int temp_dc = df;
    int temp_ptrMatD = NULO;

    // Recorre la matriz actual
    for (int i = 1; i <= df; i++) {
        for (int j = 1; j <= dc; j++) {
            int valor = elemento(i, j);

            if (valor != repe) {
                // Encuentra la posición en la matriz transpuesta
                int nuevo = existe(j, i);

                if (nuevo == NULO) {
                    nuevo = mem->new_espacio(dataMC);
                    mem->poner_dato(nuevo, filMC, j);
                    mem->poner_dato(nuevo, colMC, i);
                }

                mem->poner_dato(nuevo, datoMC, valor);
                mem->poner_dato(nuevo, sigMC, temp_ptrMatD);
                temp_ptrMatD = nuevo;
            }
        }
    }

    // Copia los valores actualizados y las dimensiones
    df = temp_df;
    dc = temp_dc;
    ptrMatD = temp_ptrMatD;
}
//	 bool MatrizSM::esSimetrica() {
//	if (df != dc) {
//		// Si el número de filas no es igual al número de columnas, no puede ser simétrica.
//		return false;
//	}
//
//	// Compara la matriz original con su traspuesta
//	for (int i = 1; i <= df; i++) {
//		for (int j = 1; j <= dc; j++) {
//			if (elemento(i, j) != elemento(j, i)) {
//				// Si se encuentra al menos un elemento diferente, la matriz no es simétrica.
//				return false;
//			}
//		}
//	}
//
//	// Si no se encontraron elementos diferentes, la matriz es simétrica.
//	return true;
//}




