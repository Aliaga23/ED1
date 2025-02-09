//---------------------------------------------------------------------------

#pragma hdrstop

#include "PoliJAAV.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

#include <iomanip>
PoliJAAV::PoliJAAV()
{
    nt = 0;
}

bool PoliJAAV::es_cero()
{
    return nt == 0;
}

int PoliJAAV::grado()
{
    if (nt > 0) {
        int max = VJAAV[MAXp - 1];
        for (int i = MAXp; i >= MAXp / 2; i--) {
            if (VJAAV[i] > max) {
                max = VJAAV[i];
            }
        }
        return max;
    } else {
        cout << "ERROR: NO EXISTEN TERMINOS" << endl;
        return 0; // Agregado para evitar advertencias del compilador
    }
}

int PoliJAAV::exponente(int nro)
{
    if (nro >= 1 && nro <= nt) {
        return VJAAV
            [MAXp / 2 + nro -
                1]; // El exponente se encuentra en esta posici�n del arreglo
    }
}

int PoliJAAV::coeficiente(int exp)
{
    if (exp >= 0 && exp <= grado()) {
        for (int i = 0; i < nt; i++) {
            if (exp == VJAAV[MAXp / 2 + i]) {
                return VJAAV
                    [i]; // El coeficiente se encuentra en esta posici�n del arreglo
            }
        }
    }
}

void PoliJAAV::asignar_coeficiente(int coef, int exp)
{
    if (nt > 0) {
        int lug = -1;
        for (int i = nt; i > 0; i--) {
            if (exp == VJAAV[MAXp - i - 1]) {
                lug = i;
                break;
            }
        }
        if (lug != -1) {
            VJAAV[lug] = coef;
            if (VJAAV[lug] == 0) {
                for (int i = lug; i < nt - 1; i++) {
                    VJAAV[MAXp - i - 1] = VJAAV[MAXp - i - 2];
                }
                VJAAV[MAXp - nt] = 0;
                nt--;
            }
        } else {
            cout << "ERROR: NO EXISTE TERMINO CON ESE EXP" << endl;
        }
    }
}

void PoliJAAV::poner_termino(int coef, int exp)
{
    if (coef != 0 && exp >= 0) {
        // Buscar si existe un t�rmino con el mismo exponente
        int i;
        int k = nt;
        for (i = MAXp / 2; i < k + MAXp / 2; i++) {
            if (exp == VJAAV[i]) {
                // Existe un t�rmino con el mismo exponente
                if (coef + VJAAV[i - MAXp / 2] == 0) {
                    // Si la suma resulta en 0, eliminar ambos t�rminos
                    VJAAV[i - MAXp / 2] =
                        0; // Marcar el coeficiente como no utilizado
                    VJAAV[i] = -1; // Marcar el exponente como no utilizado
                    nt--; // Decrementar la cantidad de t�rminos
                } else {
                    // Si no resulta en 0, simplemente actualizamos el coeficiente
                    VJAAV[i - MAXp / 2] += coef;
                }
                break;
            }
        }

        if (i == k + MAXp / 2) {
            // No se encontr� un t�rmino existente con el mismo exponente, agregar un nuevo t�rmino
            if (k < MAXp / 2) {
                VJAAV[nt] = coef;
                VJAAV[nt + MAXp / 2] = exp;
                nt++;
            } else {
                cout << "ERROR: Se ha excedido el l�mite de t�rminos" << endl;
            }
        }
    }
}

void PoliJAAV::generar()
{
    for (int i = 0; i < MAXp / 2; i++) {
        VJAAV[i] = 0;
    }
    for (int i = MAXp - 1; i > (MAXp / 2) - 1; i--) {
        VJAAV[i] = -1;
    }
}
void PoliJAAV::to_str()
{
    cout << "V";
    for (int i = 0; i < MAXp / 2; i++) {
        if (VJAAV[i] != 0)
            cout << "[" << VJAAV[i] << "]";
    }

    for (int i = MAXp - 1; i >= MAXp / 2; i--) {
        if (VJAAV[i] != -1)
            cout << "[" << VJAAV[i] << "]";
    }
    cout << endl;
    cout << numero_terminos() << endl;
}
int PoliJAAV::numero_terminos()
{
    return nt;
}

void PoliJAAV::sumar(PoliJAAV* p1, PoliJAAV* p2, PoliJAAV*&pr)
{
    // Implementar la suma de los polinomios p1 y p2 y almacenar el resultado en pr
}

void PoliJAAV::restar(PoliJAAV* p1, PoliJAAV* p2, PoliJAAV*&pr)
{
    // Implementar la resta de los polinomios p1 y p2 y almacenar el resultado en pr
}

void PoliJAAV::multiplicar(PoliJAAV* p1, PoliJAAV* p2, PoliJAAV*&pr)
{
    // Implementar la multiplicaci�n de los polinomios p1 y p2 y almacenar el resultado en pr
}

void PoliJAAV::derivar()
{
    for (int i = MAXp / 2; i < nt + MAXp / 2; i++) {
        if (VJAAV[i] != -1) {
            // Verificar que el t�rmino no est� marcado como no utilizado

            int coeficiente = VJAAV[i - MAXp / 2];
            int exponente = VJAAV[i];

            // Aplicar la regla de derivaci�n
            VJAAV[i - MAXp / 2] = coeficiente * exponente;
            VJAAV[i] = exponente - 1;

            // Si el exponente se vuelve negativo, eliminar el t�rmino
            if (VJAAV[i] < 0) {
                VJAAV[i - MAXp / 2] = 0;
                VJAAV[i] = -1;
                nt--;
            }
        }
    }
}

double PoliJAAV::evalua(double x)
{
	double resultado = 0;
	for (int i = nt; i > 0; i--) {
		int coeficiente = VJAAV[i - 1];
		int exponente = VJAAV[i + MAXp / 2 - 1];
		resultado += coeficiente * pow(x, exponente);
	}
	return resultado;
}
string PoliJAAV::to_str2()
{
    string s = "";
    bool primer_termino = true;

    for (int i = MAXp / 2; i < nt + MAXp / 2; i++) {
        if (VJAAV[i] != -1) {
            // Verificar que el t�rmino no est� marcado como no utilizado
            int coeficiente = VJAAV[i - MAXp / 2];
            int exponente = VJAAV[i];

            if (coeficiente > 0) {
                if (!primer_termino) {
                    s += "+";
                }
                s += to_string(coeficiente);
                s += "x";
                if (exponente > 1) {
                    s += "^" + to_string(exponente);
                } else if (exponente == 1) {
                    // Si el exponente es 1, mostrar x^1 como x
                    s += "^1";
                } else if (exponente == 0) {
                    // Si el exponente es 0, mostrar x^0 como 1
                    s += "^0";
                }
                primer_termino = false;
            } else if (coeficiente < 0) {
                s += to_string(coeficiente);
                s += "x";
                if (exponente > 1) {
                    s += "^" + to_string(exponente);
                } else if (exponente == 1) {
                    // Si el exponente es 1, mostrar x^1 como x
                    s += "^1";
                } else if (exponente == 0) {
                    // Si el exponente es 0, mostrar x^0 como 1
                    s += "^0";
                }
                primer_termino = false;
            }
        }
    }

    if (s.empty()) {
        s = "0";
    }

    return s;
}

void PoliJAAV::mostrar_integral()
{
    bool firstTerm = true;

    for (int i = 1; i <= nt; i++) {
        int exp = exponente(i);
        int coef = coeficiente(exp);

        if (coef != 0) {
            if (coef < 0) {
                if (!firstTerm) {
                    cout << "-";
                }
                coef = -coef;
            } else if (!firstTerm) {
                cout << "+";
            }

            if (exp == 0) {
                cout << coef;
            } else {
                if (exp == 1) {
                    cout << coef;
                } else {
                    cout << "(" << coef << "/" << (exp + 1) << ")";
                }
                cout << "x";
                if (exp != 1) {
                    cout << "^" << exp + 1;
                }
            }

            firstTerm = false;
        }
    }

    if (firstTerm) {
        cout << "C";
    } else {
        cout << "+C";
    }

    cout << endl;
}


double PoliJAAV::area2(double a, double b) {
    // Aseg�rate de que a sea menor o igual que b
    if (a > b) {
        double temp = a;
        a = b;
        b = temp;
    }

    double integral_a = 0.0;
    double integral_b = 0.0;

    for (int i = 1; i <= nt; i++) {
        int exp = exponente(i);
        int coef = coeficiente(exp);

        // Calcula las contribuciones a la integral en a y b
        integral_a += (coef * 1.0 / (exp + 1)) * pow(a, exp + 1);
        integral_b += (coef * 1.0 / (exp + 1)) * pow(b, exp + 1);
    }

    // Calcula el �rea como el valor absoluto de la diferencia entre las integrales
    double area = abs(integral_b - integral_a);

    return area;
}

void PoliJAAV::punto_minimo(double a, double b) {
	double minY = evalua(a);
    double minX = a;
    double x = a;

    while (x <= b) {
		double evalua2 = evalua(x);
		if (evalua2 < minY) {
			minY = evalua2;
            minX = x;
		}
		cout << x << " , " << evalua2 << endl;
        x = x + 0.001;
    }

    if (fabs(minX) < 1e-6) {
	cout << "Punto minimo: (0," << minY << ")" << std::endl;
	} else {
		cout << "Punto minimo: (" << std::fixed << std::setprecision(5) << minX << "," << minY << ")" << std::endl;
    }
}

void PoliJAAV::punto_maximo(double a, double b) {
	double maxY = evalua(a);
    double maxX = a;
    double x = a;

    while (x <= b) {
		double evalua2 = evalua(x);
		if (evalua2 > maxY) {
			maxY = evalua2;
            maxX = x;
		}
         cout << x << " , " << evalua2 << endl;
        x = x + 0.001;
    }

    if (fabs(maxX) < 1e-6) {
		std::cout << "Punto maximo: (0," << maxY << ")" << std::endl;
	} else {
		std::cout << "Punto maximo: (" << std::fixed << std::setprecision(5) << maxX << "," << maxY << ")" << std::endl;
    }
}

