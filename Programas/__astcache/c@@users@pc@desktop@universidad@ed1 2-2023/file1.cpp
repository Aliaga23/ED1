#include <iostream>
#include <string>
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

			#include "iomanip"
using namespace std;

void menuPoliSM();
void menuPoliVec();
void menuListas();
void menuPoliPun();
void menuLS();
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

float area(PoliP fx, float a, float b);
void punto_minimo(PoliP* fx, float a, float b);

int main()
{
   //	menuLS();
   /*cout << "1.Conjunto Sm\n";
	 cout << "2.Conjunto Ptr\n";
	 cout << "3.Conjunto Vector\n";
	 cout << "4.Conjunto Listas\n";

	 cout << "Opcion : ";
	 int op;
	 cin >> op;
	 if (op == 1) {
	 CsMemoria *m;
	 ConjuntoSm* a;
	 ConjuntoSm* b;
	 ConjuntoSm* c;
	 MenuSm(m, a, b, c);
	 }
	  if (op == 2) {
	 ConjuntoPtr* a;
	 ConjuntoPtr* b;
	 ConjuntoPtr* c;
	 MenuPtr(a, b, c);
	 }
 if (op == 3) {
	 ConjuntoV* a;
	 ConjuntoV* b;
	 ConjuntoV* c;
	 MenuVector(a, b, c);
	 }
	  if (op == 4) {
	ConjuntoListaPtr* a;
	 ConjuntoListaPtr* b;
	 ConjuntoListaPtr* c;
	 MenuListaPtr(a, b, c);
	 }
      */
	 menuPoliPun();
	 /*PoliP* fx;
	   fx = new PoliP();
	   fx->poner_termino(5, 2);

	   fx->poner_termino(4, 3);

	   fx->poner_termino(3, 1);
	   cout << fx->to_str() << endl;

	system("pause");
	*/return 0;
}
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
		   x=x+0.001;
	}
if (fabs(minX) < 1e-6) {
        cout << "Punto mínimo: (0," << minY << ")" << endl;
    } else {
        cout << "Punto mínimo: (" << fixed << setprecision(5) << minX << "," << minY << ")" << endl;
    }}

float area(PoliP fx, float a, float b)
{
    float evaluaA = fx.evalua(a);
    float evaluaB = fx.evalua(b);
	return abs(evaluaB) + abs(evaluaA);
    /*
	 formula de la integral -> abs(evaluaB - evaluaA)
	 pero asi no saldria el segundo ejemplo
	 */
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
		cout<<"6. Punto minimo\n";
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
								  cin>>a;
				cout << "Ingrese b" << endl;
								  cin>>b;
				punto_minimo(fx,a,b);
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

/*
void menu()
{
	CsMemoria* mem;
	int opcion;
	do {
		cout << "1.Crear" << endl;
		cout << "2.Pedir espacio" << endl;
		cout << "3.Liberar espacio" << endl;
		cout << "4.Poner dato" << endl;
		cout << "5.Mostrar Memoria" << endl;
		cout << "6.Salir" << endl;
		cout << "Opcion: ";
		cin >> opcion;
		switch (opcion) {
			case 1: {
				mem = new CsMemoria();
				cout << "Memoria Creada\n";
			} break;
			case 2: {
				string ids;
				cout << "Ids: ";
				cin.ignore();
				getline(cin, ids);
				mem->new_espacio(ids);
			} break;
			case 3: {
				int dir_delete;
				cout << "Direccion a liberar: ";
				cin >> dir_delete;
				mem->delete_espacio(dir_delete);
			} break;
			case 4: {
				int dir, valor;
				string id;
				cout << "Direccion: " << endl;
				cin >> dir;
				cout << "Id: " << endl;
				cin.ignore();
				getline(cin, id);
				cout << "Valor: " << endl;
				cin >> valor;
				mem->poner_dato(dir, id, valor);
			} break;
			case 5: {
				mem->mostrar();
			} break;
		}
		system("pause");
		system("cls");
	} while (opcion != 6);
}
		*/

void menuLS() {
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
	}
	while (opcion != 9);
}
