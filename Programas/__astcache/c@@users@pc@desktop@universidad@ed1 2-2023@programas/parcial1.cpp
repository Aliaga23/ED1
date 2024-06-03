//---------------------------------------------------------------------------

#pragma hdrstop

#include "Parcial1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

#pragma hdrstop

#include "Parcial1.h"

PoliLP2::PoliLP2() {}

bool PoliLP2::es_cero()
{
    return k.vacia();
}

int PoliLP2::grado()
{
    if (!es_cero()) {
        return k.longitud() - 1;
    } else {
        cout << "POLINOMIO NO TIENE TERMINOS" << endl;
        return 0;
    }
}

int PoliLP2::coeficiente(int exp) {
	if (!es_cero() && exp >= 0) {
		direccionP d = k.localiza(exp);
		if (d != NULL) {
			return d->elemento;  // Cambia k.recupera(d) por d->elemento
		} else {
			return 0;
		}
	} else {
		cout << "POLINOMIO NO TIENE ESTE TERMINO" << endl;
		return 0;
	}
}
void PoliLP2::asignar_coeficiente(int coef, int exp)
{
    if (exp >= 0) {
        direccionP d = k.localiza(exp);
        if (d != NULL) {
            k.modifica(d, coef);
        } else {
            k.inserta_ultimo(coef);
        }
    } else {
        cout << "NO SE PERMITEN EXPONENTES NEGATIVOS" << endl;
    }
}

void PoliLP2::poner_termino(int coef, int exp)
{
	if (coef != 0) {
		if (exp >= 0) {
			int max_grado = grado() + 1;
			if (exp > max_grado) {
				for (int i = max_grado; i <= exp; i++) {
					k.inserta_ultimo(0);
				}
				k.inserta_ultimo(coef);
			} else {
				direccionP termino = k.primero();
				for (int i = 0; i < exp; i++) {
					termino = k.siguiente(termino);
				}
				k.modifica(termino, coef);
			}
		} else {
			cout << "NO SE PERMITEN EXPONENTES NEGATIVOS" << endl;
		}
	}

}


int PoliLP2::numero_terminos()
{
	return grado() + 1; // Hay un término por cada exponente hasta el grado
}
int PoliLP2::exponente(int nro) {
	if (nro >= 1 && nro <= numero_terminos()) {
		direccionP d = k.primero();
		for (int i = 1; i < nro; i++) {
			d = k.siguiente(d);
		}
		return d->elemento;  // Cambia k.recupera(d) por d->elemento
	} else {
		cout << "NO EXISTE ESE NUMERO DE TERMINO" << endl;
		return 0;
	}
}
void PoliLP2::derivar()
{
	int max_exp = grado()+1;
	for (int exp = 0; exp <= max_exp; exp++) {
		direccionP d = k.localiza(exp);
		if (d != NULL) {
			int coef = k.recupera(d);
			k.modifica(d, coef * exp);
		}
	}
	direccionP d = k.localiza(0);
	if (d != NULL) {
		k.suprime(d);
	}
}

float PoliLP2::evalua(float x)
{
    float resultado = 0.0;
    for (direccionP d = k.primero(); d != NULL; d = k.siguiente(d)) {
        int coef = k.recupera(d);
        int exp = k.recupera(d);
        resultado += coef * pow(x, exp);
    }
    return resultado;
}

string PoliLP2::k_to_str()
{
    return k.to_str_inverso();
}
string PoliLP2::to_str() {
    string s = "";
	direccionP d = k.fin();
	bool firstTerm = true;

	for (int exp = k.longitud(); exp >= 1; exp--) {
		int coef = k.recupera(d);

		if (coef != 0) {
			if (coef > 0 && !firstTerm) {
				s += "+";
			}

			if (exp > 0) {
				s += to_string(coef) + "x^" + to_string(exp-1);  // Incluye "x^exponente"
			} else {
				s += to_string(coef);
			}

			firstTerm = false;
		}

		d = k.anterior(d);
    }

    if (s.empty()) {
        s = "0";
    }

    return s;
}

