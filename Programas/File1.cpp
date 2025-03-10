#include <iostream>
#include <string>
#include "iomanip"
#include "CsMemoria.h"
#include "Listas.h"
#include "Lista_SM.h"
#include "UListaV.h"
#include "LisPoli_Pun.h"
#include "LisPoli_Vec_Mem.h"
#include "Poli_Vec.h"
#include "Poli_Pun.h"
#include "Poli_SM.h"
#include "Conjunto_Lis.h"
#include "Conjunto_Pun.h"
#include "Conjunto_Vec.h"
#include "Conjunto_SM.h"
#include "Menu_Conjunto.h"
#include "ListasPtr.h"
#include "MatrizVec.h"
#include "Matriz_Puntero.h"
#include "Matriz_SM.h"
#include "Matriz_SMDoble.h"
#include "PoliJAAV.h"
#include "PilaPuntero.h"
#include "PilaSM.h"
#include "PilaStr.h"
#include "PilaVector.h"
#include "PilaLista.h"

using namespace std;

void menuPoliSM();
void menuPoliVec();
void menuListas();
void menuPoliPun();
void menuLS();
float area(PoliP fx, float a, float b);
void punto_minimo(PoliP* fx, float a, float b);
void intersectarConjuntos(ConjuntoPtr* a, ConjuntoPtr* b, ConjuntoPtr &c);
void complementoInterseccion(ConjuntoPtr* a, ConjuntoPtr* b, ConjuntoPtr &c);
void menuS();
void menuPruebaParcial();
bool esSimetrica(MatrizSM &matriz);
string infijaToPostfija(string cadena);
int evaluarPostfija(string cadena);
int evalua(float op1, char op, float op2);
int prioridadInfija(char c);
int prioridadPila(char c);
bool digito(char c);
bool operador(char c);
void invertir(PilaS* p);
int main()
{
    //  MatrizV matriz;

    // Dimensiona la matriz con 4 filas y 4 columnas
    //matriz.dimensionar(4, 4);

    // Ingresa algunos datos en la matriz
    //    matriz.poner(1, 1, 0);
    //	matriz.poner(1, 2, 0);
    //	matriz.poner(1, 3, 0);
    //	matriz.poner(1, 4, 11);
    //	matriz.poner(3, 1, 0);
    //	matriz.poner(3, 2, 50);
    //	matriz.poner(3, 3, 85);
    //	matriz.poner(3, 4, 2581);
    //
    //	matriz.poner(4, 1, 7);
    //	matriz.poner(4, 2, 0);
    //	//matriz.poner(4, 3, 2);
    //	matriz.poner(4, 4, 0);
    //	matriz.definir_valor_repetido(59);
    //	string repre;
    //	repre=matriz.to_str();
    //	cout<<repre;
    //---------------------------------------------
    //	CsMemoria* memoria;
    //	MatrizSmDb* matriz;
    //	memoria = new CsMemoria();
    //	matriz = new MatrizSmDb(memoria);
    //	////	// Definir el valor repetido
    //	matriz->definir_valor_repetido(5);
    //	////
    //	////	// Dimensionar la matriz 3x3
    //	matriz->dimensionar(4, 3);
    //	///matriz->poner(1, 2, 50);
    //	//		if (esSimetrica(*matriz)) {
    //	//			cout << "La matriz es simetrica." << endl;
    //	//		} else {
    //	//			cout << "La matriz no es simetrica." << endl;
    //	//		}
    //	// matriz->dimensionar(4, 3);
    //	//
    //	//	// Llenar la matriz con datos
    //	matriz->poner(2, 2, 500);
    //	matriz->poner(1, 2, 2);
    //	//
    //	//
    //	cout << "Matriz:\n" << matriz->toStr() << endl;
    //	matriz->transponer();
    //
    //	//	matriz->definir_valor_repetido(15);
    //	//	// Mostrar la matriz
    //	cout << "Matriz:\n" << matriz->toStr() << endl;
    //
    //	//cout << "Matriz:\n" << matriz->to_str() << endl;
    //	// Mostrar la memoria
    //	memoria->mostrar();
    //--------------------------------------------------------------------
    //MatrizPC matriz;
    //MatrizPC* matriz;
    //matriz = new MatrizPC();
    //matriz->definir_valor_repetido(15);
    //matriz->dimensionar(4, 3);
    //
    //			 cout << "Matriz:\n" << matriz->to_str() << endl;
    //			 matriz->transponer();
    //			 matriz->definir_valor_repetido(15);
    //			 matriz->poner(1, 2, 1500);
    //			  cout << "Matriz:\n" << matriz->to_str() << endl;
    //
    //       string a = "(20+3)*5";
    //	string b = "2 3 5*+";
    //	string p = infijaToPostfija(a);
    //	cout << p << endl;
    //	float real = evaluarPostfija(p);
    //	cout << real << endl;
    //---Para Pilas borrar momentaneamente en Lista con punteros o sm lo de lista vacia (error)
    //
    //	CsMemoria* memoria = new CsMemoria;
    //
    //	p->meter(5);
    //	p->meter(4455);
    //	p->meter(3);
    //	//	int a;
    //	//	p->sacar(a);
    //	//	p->tope1();
    //	//	cout << p->cima() << endl;
    //	//	cout << p->to_str() << endl;
    //	//	memoria->mostrar();
    //	//	int a;
    //	//	p->sacar(a);
    //	//	memoria->mostrar();
    //	//	   p->meter(30);
    //	//	memoria->mostrar();
    //	//cout << p->to_str() << endl;
    //	invertir(p);
    //	//	cout << p->to_str() << endl;
    //	//	memoria->mostrar();
    /*
	CsMemoria* memoria = new CsMemoria;
	PilaS* p = new PilaS(memoria);
	p->meter(5);
	p->meter(4455);
	p->meter(3);
	//	int a;
	//	p->sacar(a);
	//	p->tope1();
	cout << p->cima() << endl;
	cout << p->to_str() << endl;
	memoria->mostrar();
	int a;
	p->sacar(a);
	memoria->mostrar();
	p->meter(30);
	int d;
	cin >> d;
	p->meter(d);

	memoria->mostrar();
	  */
//
//	CsMemoria* memoria;
//	PilaS* p;
//	int opcion;
//	do {
//		cout << "1.Crear Memoria\n";
//		cout << "2.Pedir espacio\n";
//		cout << "3.Crear Pila\n";
//		cout << "4.Pedir Pila\n";
//		cout << "5.Invertir 2 Ultimos\n";
//		cout << "6.Mostrar Memoria\n";
//		cout << "7.Salir\n";
//		cout << "Opcion: ";
//		cin >> opcion;
//		switch (opcion) {
//			case 1: {
//				memoria = new CsMemoria();
//			} break;
//			case 2: {
//				string id;
//				cin.ignore();
//				cout << "IDs: ";
//				getline(cin, id);
//				memoria->new_espacio(id);
//			} break;
//			case 3: {
//				p = new PilaS(memoria);
//			} break;
//			case 4: {
//				int dato;
//
//				cin >> dato;
//				p->meter(dato);
//
//			} break;
//			case 5: {
//				invertir(p);
//			} break;
//			case 6: {
//				memoria->mostrar();
//
//			} break;
//		}
//		system("pause");
//		system("cls");
//	} while (opcion != 7);

    ConjuntoPtr A;
	ConjuntoPtr B;
	ConjuntoPtr C;

	int opcion;

	do {


		cout << "1. Insertar valor en A\n";
		cout << "2. Insertar valor en B\n";
		cout << "3. Realizar interseccion \n";
		cout << "4. Mostrar C\n";
		cout << "5.Salir\n";
	   cout << "Opcion: ";
		cin >> opcion;

		switch (opcion) {
			case 1: {
				int valorA;
			   cout << "Ingrese valor para A: ";
			  cin >> valorA;
				A.inserta(valorA);
			} break;
			case 2: {
				int valorB;
				cout << "Ingrese valor para B: ";
			   cin >> valorB;
				B.inserta(valorB);
			} break;
			case 3: {

					 intersectarConjuntos(&A, &B, C);
			} break;
			case 4: {

			  cout << C.to_str() <<endl;
			} break;
		}

	} while (opcion != 5);

	system("pause");
	return 0;
}

void invertir(PilaS* p)
{
	int ultimo;
	int penultimo;

	if (!p->vacia()) {
		p->sacar(ultimo);

		if (!p->vacia()) {
			p->sacar(penultimo);
			p->meter(ultimo);
			p->meter(penultimo);
		} else {
			p->meter(ultimo);

			cout << "No hay suficientes elementos" << endl;
		}
	} else {
		cout << "Lista vacia" << endl;
	}
}

void menuPruebaParcial()
{
    PoliJAAV* p;
    int opcion;
    do {
        cout << "1.Crear \n";
        cout << "2.Poner Termino\n";
        cout << "3.Grado\n";
        cout << "4.Derivada\n";
        cout << "5.Mostrar Polinomio\n";
        cout << "6.Mostrar Atributos\n";
        cout << "7.Integral\n";
        cout << "8.Area\n";
        cout << "9.Punto minimo\n";
        cout << "10.Punto maximo\n";
        cout << "11.Salir\n";

        cout << "Opcion: ";
        cin >> opcion;
        switch (opcion) {
            case 1: {
                p = new PoliJAAV();
                p->generar();
            } break;
            case 2: {
                int co, ex;
                cout << "Ingrese coeficiente" << endl;
                cin >> co;
                cout << "Ingrese exponente" << endl;
                cin >> ex;
                p->poner_termino(co, ex);

            } break;
            case 3: {
                cout << p->grado() << endl;
            } break;
            case 4: {
                p->derivar();
                cout << p->to_str2() << endl;
            } break;
            case 5: {
                cout << p->to_str2() << endl;
            } break;
            case 6: {
                p->to_str();
            } break;
            case 7: {
                cout << "Integral del polinomio: ";
                p->mostrar_integral();
            } break;
            case 8: {
                int a;
                int b;
                cout << "a:" << endl;
                cin >> a;

                cout << "b:" << endl;
                cin >> b;
                double area = p->area2(a, b);

                cout << "�rea bajo la curva entre x = " << a << " y x = " << b
                     << ": " << area << endl;

            } break;
            case 9: {
                double a, b;
                cout << "Ingrese a" << endl;
                cin >> a;
                cout << "Ingrese b" << endl;
                cin >> b;
                p->punto_minimo(a, b);
            } break;
            case 10: {
                double a, b;
                cout << "Ingrese a" << endl;
                cin >> a;
                cout << "Ingrese b" << endl;
                cin >> b;
                p->punto_maximo(a, b);
            } break;
        }
        system("pause");
        system("cls");
    } while (opcion != 11);
}
bool esSimetrica(MatrizSM &matriz)
{
    int df = matriz.dimension_fila();
    int dc = matriz.dimension_columna();

    if (df != dc) {
        // Si el n�mero de filas no es igual al n�mero de columnas, no puede ser sim�trica.
        return false;
    }

    // Compara la matriz original con su traspuesta
    for (int i = 1; i <= df; i++) {
        for (int j = 1; j <= dc; j++) {
            if (matriz.elemento(i, j) != matriz.elemento(j, i)) {
                // Si se encuentra al menos un elemento diferente, la matriz no es sim�trica.
                return false;
            }
        }
    }

    // Si no se encontraron elementos diferentes, la matriz es sim�trica.
    return true;
}
bool sonOpuestos(PoliP* a, PoliP* b)
{
    PoliP* suma = new PoliP();
    for (int i = 1; i <= a->numero_terminos(); i++) {
        int exp = a->exponente(i);
        int coef = a->coeficiente(exp);
        suma->poner_termino(coef, exp);
    }
    for (int i = 1; i <= b->numero_terminos(); i++) {
        int exp = b->exponente(i);
        int coef = b->coeficiente(exp);
        suma->poner_termino(coef, exp);
    }
    return suma->es_cero();
}

bool sonIguales(PoliP* a, PoliP* b)
{
    PoliP* suma = new PoliP();
    suma->sumar(a, b, suma);
    return suma->es_cero();
    for (int i = 1; i <= a->numero_terminos(); i++) {
        int exp = a->exponente(i);
        int coef = a->coeficiente(exp);
        suma->poner_termino(coef, exp);
    }
    for (int i = 1; i <= b->numero_terminos(); i++) {
        int exp = b->exponente(i);
        int coef = b->coeficiente(exp);
        suma->poner_termino(-coef, exp);
    }
    return suma->es_cero();
}

void menuS()
{
    ListaS* list;
    CsMemoria* mem;
    int opcion;
    do {
        cout << "1.Crear Memoria\n";
        cout << "2.Pedir espacio\n";
        cout << "3.Crear Lista\n";
        cout << "4.Mostrar memoria\n";
        cout << "5.Mostrar lista\n";
        cout << "6.INSERTAR DIR PRIMERO \n L.INSERTAR(L->PRIMERO,DATO)\n";
        cout << "7.INSERTAR DIR FIN\n";
        cout << "8.INSERTAR SIGUIENTE PRIMERO\n L.INSERTAR(L,SIGUIENTE,DATO)\n";
        cout << "9.INSERTAR ANTERIOR FIN\n";
        cout << "10.SUPRIMIR SIGUIENTE PRIMERO\n";
        cout << "11.Salir\n";
        cout << "Opcion: ";
        cin >> opcion;
        switch (opcion) {
            case 1: {
                mem = new CsMemoria();
                cout << "Memoria Creada" << endl;
            } break;
            case 2: {
                string ids;
                cin.ignore();
                cout << "IDS a guardar: ";
                getline(cin, ids);
                mem->new_espacio(ids);
            } break;
            case 3: {
                list = new ListaS(mem);
                cout << "Lista Creada" << endl;
            } break;
            case 4: {
                cout << "La Memoria\n" << endl;
                mem->mostrar();
            } break;
            case 5: {
                cout << "La Lista\n" << endl;

                cout << list->to_str() << endl;
            } break;
            case 6: {
                int e;
                cout << "Dato: ";
                cin >> e;
                list->inserta_primero(e);
                cout << list->to_str() << endl;

            } break;
            case 7: {
                int e;
                cout << "Dato: ";
                cin >> e;
                list->inserta_ultimo(e);
                cout << list->to_str() << endl;

            } break;
            case 8: {
                int e;
                cout << "Dato: ";
                cin >> e;
                //insertar(direccion,elemento);
                list->inserta(list->siguiente(list->primero()), e);
                cout << list->to_str() << endl;
            } break;
            case 9: {
                int e;
                cin >> e;
                list->inserta(list->fin(), e);
            } break;

            case 10: {
                list->suprime(list->siguiente(list->primero()));
            } break;
        }
        system("pause");
        system("cls");
    } while (opcion != 11);
}
void complementoInterseccion(ConjuntoPtr* a, ConjuntoPtr* b, ConjuntoPtr &c)
{
    for (int i = 0; i < a->cardinal(); i++) {
        int eA = a->elemento(i);
        if (!(a->pertenece(eA) && b->pertenece(eA))) {
            c.inserta(eA);
        }
    }
    for (int i = 0; i < b->cardinal(); i++) {
        int eB = b->elemento(i);
        if (!(a->pertenece(eB) && b->pertenece(eB))) {
            c.inserta(eB);
        }
    }
}
void intersectarConjuntos(ConjuntoPtr* a, ConjuntoPtr* b, ConjuntoPtr &c)
{
    ConjuntoPtr aux;
    for (int i = 0; i < a->cardinal(); i++) {
        int elemA = a->elemento(i);
        if (a->pertenece(elemA) && b->pertenece(elemA)) {
            c.inserta(elemA);
        }
    }
    for (int i = 0; i < b->cardinal(); i++) {
        int elemB = b->elemento(i);
        if (b->pertenece(elemB) && a->pertenece(elemB)) {
            c.inserta(elemB);
        }
    }
}

//void IntersectarConjuntos(ConjuntoPtr* a, ConjuntoPtr* b, ConjuntoPtr& c) {
//	c.reiniciar();
//	ConjuntoPtr aux;
//	// Inserto si el elemento pertenece a A y a B
//	while (!a->vacio()) {
//		int r = a->muestrea();
//		if (a->pertenece(r) && b->pertenece(r)) {
//			c.inserta(r);
//		}
//		a->suprime(r);
//        aux.inserta(r);
//    }
//    // Recupero los elementos de A
//    while (!aux.vacio()) {
//        int r = aux.muestrea();
//        aux.suprime(r);
//		a->inserta(r);
//	}
//}

void punto_minimo(PoliP* fx, float a, float b)
{
    double minY = fx->evalua(a);
    double minX = a;
    double x = a;
    while (x <= b) {
        double evalua = fx->evalua(x);
        if (evalua < minY) {
            minY = evalua;
            minX = x;
        }
        cout << x << " , " << evalua << endl;
        x = x + 0.001;
    }
    if (fabs(minX) < 1e-6) {
        cout << "Punto m�nimo: (0," << minY << ")" << endl;
    } else {
        cout << "Punto m�nimo: (" << fixed << setprecision(5) << minX << ","
             << minY << ")" << endl;
    }
}

float area(PoliP fx, float a, float b)
{
	float evaluaA = fx.evalua(a);
	float evaluaB = fx.evalua(b);
	return abs(evaluaB) + abs(evaluaA);

}
void menuPoliPun()
{
    PoliP* fx;
    int opcion;
    do {
        cout << "1.Crear Polinomio\n";
        cout << "2.Poner Termino\n";
        cout << "3.Mostrar Polinomio\n";
        cout << "4.Derivar\n";
        cout << "5.Evaluar\n";
        cout << "6. Punto minimo\n";
        cout << "7.Salir\n";
        cout << "Opcion: ";
        cin >> opcion;
        switch (opcion) {
            case 1: {
                fx = new PoliP();
            } break;
            case 2: {
                int coef, exp;
                cout << "Coef: ";
                cin >> coef;
                cout << "Exp: ";
                cin >> exp;
                fx->poner_termino(coef, exp);
            } break;
            case 3: {
                cout << fx->to_str() << endl;
            } break;
            case 4: {
                fx->derivar();
            } break;
            case 5: {
                int n;
                cout << "Ingrese Dato para evaluar" << endl;
                cin >> n;
                cout << "Resultado al reemplazar x" << endl;
                cout << fx->evalua(n) << endl;
            } break;
            case 6: {
                float a;
                float b;
                cout << "Ingrese a" << endl;
                cin >> a;
                cout << "Ingrese b" << endl;
                cin >> b;
                punto_minimo(fx, a, b);
            } break;
        }
        system("pause");
        system("cls");
    } while (opcion != 7);
}
void menuPoliSM()
{
    CsMemoria* mem;
    PoliS* p;
    int opcion;
    do {
        cout << "1.Crear Memoria\n";
        cout << "2.Pedir espacio\n";
        cout << "3.Liberar espacio\n";
        cout << "4.Crear Polinomio\n";
        cout << "5.Poner Termino\n";
        cout << "6.Mostrar Polinomio\n";
        cout << "7.Derivar\n";
        cout << "8.Mostrar Memoria\n";
        cout << "9.Evalua\n";
        cout << "10.Salir\n";
        cout << "Opcion: ";
        cin >> opcion;
        switch (opcion) {
            case 1: {
                mem = new CsMemoria();
            } break;
            case 2: {
                string id;
                cin.ignore();
                cout << "IDs: ";
                getline(cin, id);
                mem->new_espacio(id);
            } break;
            case 3: {
                int dir;
                cout << "Direccion a liberar: ";
                cin >> dir;
                mem->delete_espacio(dir);
            } break;
            case 4: {
                p = new PoliS(mem);
            } break;
            case 5: {
                int coef, exp;
                cout << "Coef: ";
                cin >> coef;
                cout << "Exp: ";
                cin >> exp;
                p->poner_termino(coef, exp);
            } break;
            case 6: {
                cout << p->to_str() << endl;
            } break;
            case 7: {
                //p->mostrar_integral();
                p->derivar();

                ///derivar tambien
            } break;
            case 8: {
                mem->mostrar();
            } break;
            case 9: {
                int n;
                cout << "Ingrese Dato para evaluar" << endl;
                cin >> n;
                cout << "Resultado al reemplazar x" << endl;
                cout << p->evalua(n) << endl;
            } break;
        }
        system("pause");
        system("cls");
    } while (opcion != 10);
}
void menuPoliVec()
{
    PoliV* p;
    int opcion;
    do {
        cout << "1.Crear Polinomio\n";
        cout << "2.Poner Termino\n";
        cout << "3.Mostrar Polinomio\n";
        cout << "4.Derivar\n";
        cout << "5.Evaluar\n";
        cout << "6.Salir\n";
        cout << "Opcion: ";
        cin >> opcion;
        switch (opcion) {
            case 1: {
                p = new PoliV();
            } break;
            case 2: {
                int coef, exp;
                cout << "Coef: ";
                cin >> coef;
                cout << "Exp: ";
                cin >> exp;
                p->poner_termino(coef, exp);
            } break;
            case 3: {
                cout << p->to_str() << endl;
            } break;
            case 4: {
                p->derivar();
            } break;
            case 5: {
                int n;
                cout << "Ingrese Dato para evaluar" << endl;
                cin >> n;
                cout << "Resultado al reemplazar x" << endl;
                cout << p->evalua(n) << endl;
            } break;
        }
        system("pause");
        system("cls");
    } while (opcion != 6);
}

void menuListas()
{
    PoliL* p; // PoliLP* p;
    int opcion;
    do {
        cout << "1.Crear Polinomio\n";
        cout << "2.Poner Termino\n";
        cout << "3.Mostrar Polinomio\n";
        cout << "4.Derivar\n";
        cout << "5.Evaluar\n";
        cout << "6.Salir\n";
        cout << "Opcion: ";
        cin >> opcion;
        switch (opcion) {
            case 1: {
                p = new PoliL(); // p = new PoliLP();
            } break;
            case 2: {
                int coef, exp;
                cout << "Coef: ";
                cin >> coef;
                cout << "Exp: ";
                cin >> exp;
                p->poner_termino(coef, exp);
            } break;
            case 3: {
                cout << p->to_str() << endl;
            } break;
            case 4: {
                p->derivar();
            } break;
            case 5: {
                int n;
                cout << "Ingrese Dato para evaluar" << endl;
                cin >> n;
                cout << "Resultado al reemplazar x" << endl;
                cout << p->evalua(n) << endl;
            } break;
        }
        system("pause");
        system("cls");
    } while (opcion != 6);
}

void menuLS()
{
    ListaS* list;
    CsMemoria* mem;
    int opcion;
    do {
        cout << "1.Crear Memoria\n";
        cout << "2.Pedir espacio\n";
        cout << "3.Liberar espacio\n";
        cout << "4.Crear Lista\n";
        cout << "5.Insertar inicio\n";
        cout << "6.Insertar final\n";
        cout << "7.Mostrar memoria\n";
        cout << "8.Mostrar lista\n";
        cout << "9.Salir\n";
        cout << "Opcion: ";
        cin >> opcion;
        switch (opcion) {
            case 1: {
                mem = new CsMemoria();
            } break;
            case 2: {
                string ids;
                cin.ignore();
                cout << "IDS a guardar: ";
                getline(cin, ids);
                mem->new_espacio(ids);
            } break;
            case 3: {
                int dir;
                cout << "Direccion a liberar\n";
                cin >> dir;
                mem->delete_espacio(dir);
            } break;
            case 4: {
                list = new ListaS(mem);
            } break;
            case 5: {
                int e;
                cout << "Dato: ";
                cin >> e;
                list->inserta_primero(e);
            } break;
            case 6: {
                int e;
                cout << "Dato: ";
                cin >> e;
                list->inserta_ultimo(e);
            } break;
            case 7: {
                mem->mostrar();
            } break;
            case 8: {
                cout << list->to_str() << endl;
            } break;
        }
        system("pause");
        system("cls");
    } while (opcion != 9);
}

int evalua(float op1, char op, float op2)
{
    if (op == '^')
        return (int)pow(op1, op2);
    else if (op == '*')
        return op1 * op2;
    else if (op == '/')
        return op1 * 1.0 / op2;
    else if (op == '+')
        return op1 + op2;
    else if (op == '-')
        return op1 - op2;
    else
        return 0;
}

int evaluarPostfija(string cadena)
{
    PilaP p;
    int n = cadena.length();
    for (int i = 0; i < n; i++) {
        char letra = cadena[i];
        if (digito(letra)) {
            string num = "";
            while (!operador(letra) && letra != ' ') {
                num += letra;
                i++;
                letra = cadena[i];
                if (i == n)
                    break;
            }
            int n = atoi((char*)num.c_str());
            p.meter(n);
        } else if (letra != ' ') {
            int op1, op2;
            p.sacar(op2);
            p.sacar(op1);
            // char op = letra;
            int z = evalua(op1, letra, op2);
            p.meter(z);
        }
    }
    int res;
    p.sacar(res);
    return res;
}

string infijaToPostfija(string cadena)
{
    PilaP p;
    string exp = "";
    int aux;
    int n = cadena.length();
    for (int i = 0; i < n; i++) {
        char letra = cadena[i];
        if (digito(letra)) {
            string num = "";
            while (!operador(letra) && letra != ')' && i < n) {
                num += letra;
                i++;
                letra = cadena[i];
            }
            exp += num + " ";
            i--;
        } else if (letra == '(')
            p.meter(letra);
        else {
            if (operador(letra)) {
                while (true) {
                    aux = p.cima();
                    if (p.vacia() ||
                        (prioridadInfija(letra) > prioridadPila(aux))) {
                        p.meter(letra);
                        break; // por aqui sale
                    } else {
                        p.sacar(aux);
                        exp += aux;
                    }
                }
            } else {
                if (letra == ')') {
                    while (true) {
                        p.sacar(aux);
                        if (((char)aux) != '(')
                            exp += (char)aux;
                        else
                            break;
                    }
                }
            }
        }
    }
    while (!p.vacia()) {
        p.sacar(aux);
        exp += aux;
    }
    return exp;
}

int prioridadInfija(char c)
{
    if (c == '^')
        return 4;
    else if (c == '*')
        return 2;
    else if (c == '/')
        return 2;
    else if (c == '+')
        return 1;
    else if (c == '-')
        return 1;
    else if (c == '(')
        return 5;
    else
        return 0;
}

int prioridadPila(char c)
{
    if (c == '^')
        return 3;
    else if (c == '*')
        return 2;
    else if (c == '/')
        return 2;
    else if (c == '+')
        return 1;
    else if (c == '-')
        return 1;
    else if (c == '(')
        return 0;
    else
        return -1;
}

bool digito(char c)
{
    return c == '0' || c == '1' || c == '2' || c == '3' || c == '4' ||
           c == '5' || c == '6' || c == '7' || c == '8' || c == '9';
}

bool operador(char c)
{
    return c == '^' || c == '*' || c == '/' || c == '+' || c == '-';
}

