﻿//---------------------------------------------------------------------------

#pragma hdrstop

#include "EjemplosCod.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
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
// menuPoliPun();
/*PoliP* fx;
	   fx = new PoliP();
	   fx->poner_termino(5, 2);

	   fx->poner_termino(4, 3);

	   fx->poner_termino(3, 1);
	   cout << fx->to_str() << endl;

	system("pause");
	*/
//menuS();
/*
	ConjuntoPtr A;
	ConjuntoPtr B;
	ConjuntoPtr C;

	int opcion;

	do {
		cout << "1. Insertar valor en A\n";
		cout << "2. Insertar valor en B\n";
		cout << "3. Realizar intersección y mostrar C\n";
		cout << "4. Mostrar C\n";
		cout << "Salir\n";

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
				//intersectarConjuntos(&A, &B, C);
				A.inserta(1);
				A.inserta(2);
				A.inserta(3);
				A.inserta(4);
				B.inserta(1);
				B.inserta(5);
				B.inserta(3);
				B.inserta(85);

				complementoInterseccion(&A, &B, C);
				cout << C.to_str() << endl;
			} break;
		}
		system("pause");
		system("cls");
	} while (opcion != 4);
	*/

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
//    CsMemoria* memoria;
//	MatrizSM* matriz;
//	memoria = new CsMemoria();
//	matriz = new MatrizSM(memoria);
//	////	// Definir el valor repetido
//	matriz->definir_valor_repetido(15);
//	////
//	////	// Dimensionar la matriz 3x3
//	matriz->dimensionar(3, 3);
//	matriz->poner(1, 2, 500);
//	if (esSimetrica(*matriz)) {
//		cout << "La matriz es simetrica." << endl;
//	} else {
//		cout << "La matriz no es simetrica." << endl;
//	}
//	matriz->dimensionar(4, 3);
////
////	// Llenar la matriz con datos
//	matriz->poner(2, 2, 500);
////	//matriz->poner(1, 2, 1500);
////
////
//	cout << "Matriz:\n" << matriz->to_str() << endl;
//	matriz->transponer();
//	//matriz->definir_valor_repetido(15);
////	// Mostrar la matriz
//	cout << "Matriz:\n" << matriz->to_str() << endl;
//
//
//	//cout << "Matriz:\n" << matriz->to_str() << endl;
//	// Mostrar la memoria
//   //	memoria->mostrar();
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
//    ListaP lista;
//
//    // Agregar elementos a la lista
//   //lista.inserta_primero(15);
//  //	lista.inserta_primero(15);
//	lista.inserta_primero(10);
//	lista.inserta_primero(15);
//	lista.inserta_ultimo(2);
//    lista.inserta_ultimo(2);
//	lista.inserta_ultimo(15);
//    lista.inserta_ultimo(15);
//	lista.ordenarAscendente();
//	cout << "Lista original: " << lista.to_str() <<endl;
//	lista.eliminarRepetidos();
//	// Llamar al método para eliminar el elemento más grande
//   // lista.eliminarMayor();
//    cout << "Lista original: " << lista.to_str() <<endl;

//std::cout << "Lista después de eliminar el elemento más grande: "
//        << lista.to_str() << std::endl;

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

//
//	   //
//       void elimina(int k, PilaSm *p) {
//	PilaSm* aux = new PilaSm();
//	while (!p->vacia()) {
//		int e;
//		p->sacar(e);
//		aux->meter(e);
//	}
//	while (!aux->vacia()) {
//		int e;
//		aux->sacar(e);
//		if (e != k)
//			p->meter(e);
//	}
//}
//
//void invierte(PilaSm* p) {
//	PilaSm* aux1 = new PilaSm();
//	PilaSm* aux2 = new PilaSm();
//	while (!p->vacia()) {
//		int e;
//
//		aux1->meter(e);
//	}
//	while (!aux1->vacia()) {
//		int e;
//		aux1->sacar(e);
//		aux2->meter(e);
//	}
//	while (!aux2->vacia()) {
//		int e;
//		aux2->sacar(e);
//		p->meter(e);
//	}
//}
//
//void invierteLista(PilaSm *p) {
//	ListaPtr* l = new ListaPtr();
//	while (!p->vacia()) {
//		int e;
//		p->sacar(e);
//		l->inserta(l->primero(), e);
//	}
//	while (!l->vacia()) {
//		int e = l->recupera(l->fin());
//		l->suprime(l->fin());
//		p->meter(e);
//	}
//
//}
//
//int segundoMayor(PilaVector& P);
//
//void CambiarExtremos(PilaPtr& P) {
//	if (!P.vacia()) {
//		PilaPtr aux;
//		int prim;
//		P.sacar(prim);
//		while (!P.vacia()) {
//			int s;
//			P.sacar(s);
//			aux.meter(s);
//		}
//		int ult;
//		bool v = aux.vacia(); // Verifica q no este vacia para asi no sacar
//		if (!v)
//			aux.sacar(ult);
//		P.meter(prim);
//		while (!aux.vacia()) {
//			int s;
//			aux.sacar(s);
//			P.meter(s);
//		}
//		if (!v)
//			P.meter(ult);
//	}
//}
//
//void cambiarExtremos(PilaPtr& P) {
//	ListaPtr l;
//	while (!P.vacia()) {
//		int ele;
//		P.sacar(ele);
//		l.inserta(l.primero(), ele);
//	}
//	NodoL* ult = l.fin();
//	int dato = l.recupera(ult);
//	l.suprime(ult);
//	P.meter(dato);
//	int prim = l.recupera(l.primero());
//	l.suprime(l.primero());
//	while (!l.vacia()) {
//		NodoL* pp = l.primero();
//		int d = l.recupera(pp);
//		l.suprime(pp);
//		P.meter(d);
//	}
//	P.meter(prim);
//} //int segundoMayor(PilaVector& P) { //	bool encontro = false;
//	PilaVector aux;
//	int mayor = P.cima();
//	int sdoMayor;
//	while (!P.vacia()) {
//		int s;
//		P.sacar(s);
//		aux.meter(s);
//		if (s > mayor)
//			mayor = s;
//	}
//	bool cambio = false;
//	while (!aux.vacia()) {
//		int s;
//		aux.sacar(s);
//		P.meter(s);
//		if (!cambio) {
//			if (s < mayor) {
//				sdoMayor = s;
//				cambio = true;
//				encontro = true;
//			}
//		}
//		else {
//			if (s < mayor && s > sdoMayor)
//				sdoMayor = s;
//			encontro = true;
//		}
//	}
//	if (encontro)
//		return sdoMayor;
//	else
//		cout << "No hay 2do mayor en la pila" << endl;
//}

/*
             void PilaLista::meter1(int e) {
	if (vacia() == true) {
		l->inserta(l->fin(), e);
	}
	else {
		int ul = l->recupera(l->fin());
		l->inserta(l->fin(), ul);
		l->inserta(l->fin(), e);
		l->suprime(l->fin());
	}
}

void PilaLista::sacar1(int &e) {
	if (vacia() == false) {
		e = l->recupera(l->fin());
		l->suprime(l->fin());
	}
	else {
		cout << "ERROR,PILA VACIA" << endl;
	}
    void PilaPtr::meter1(int e) {
	if (ptrPila == NULL) { // vacia()
		NodoPila* nuevo = new NodoPila;
		nuevo->elemento = e;
		nuevo->sig = NULL;
		ptrPila = nuevo;
	}
	else {
		NodoPila* nuevo = new NodoPila;
		nuevo->elemento = e;
		nuevo->sig = NULL;
		NodoPila* aux = ptrPila;
		while (aux->sig != NULL) {
			aux = aux->sig;
		}
		aux->sig = nuevo;
	}
}

void PilaPtr::sacar1(int &e) {
	if (ptrPila != NULL) {
		if (ptrPila->sig == NULL) {
			e = ptrPila->elemento;
			delete(ptrPila);
			ptrPila = NULL;
		}
		else {
			NodoPila* aux = ptrPila;
			NodoPila* ant;
			while (aux->sig != NULL) {
				ant = aux;
				aux = aux->sig;
			}
			e = aux->elemento;
			ant->sig = NULL;
			delete(aux);
		}
	}
}
void PilaVector::meter1(int e) {
	if (c == 0) {
		elementos[0] = e;
		c++; // en realidad tope es un contador
	}
	else {
		for (int i = c; i > 0; i--) {
			elementos[i] = elementos[i - 1];
		}
		elementos[0] = e;
		c++;
	}
}

void PilaVector::sacar1(int &e) {
	if (c > 0) {
		e = elementos[0];
		for (int i = 0; i < c - 1; i++) {
			elementos[i] = elementos[i + 1];
		}
		c--;
	}
}
}
int PrioridadInfija(char c) {
    switch (c) {
        case '^':
            return 4;
        case '*':
        case '/':
            return 2;
        case '+':
        case '-':
            return 1;
        case '(':
            return 5;
        default:
            return 0;  // Valor predeterminado para otros caracteres
    }
}

int PrioridadPila(char c) {
    switch (c) {
        case '^':
            return 3;
        case '*':
        case '/':
            return 2;
        case '+':
        case '-':
            return 1;
        case '(':
            return 0;
        default:
            return -1;  // Valor predeterminado para otros caracteres
    }
}

double Evalua(double Op1, char Operador, double Op2) {
    switch (Operador) {
        case '^':
            return exp(Op2 * log(Op1));
        case '*':
            return Op1 * Op2;
        case '/':
            return Op1 / Op2;
        case '+':
            return Op1 + Op2;
        case '-':
            return Op1 - Op2;
        default:
            return 0.0;  // Valor predeterminado para otros operadores
    }
}

double EvaluarPostfija(const string &ExpPostfija) {
    Pila p;
    for (size_t i = 0; i < ExpPostfija.length(); ++i) {
        if (isdigit(ExpPostfija[i])) {
            p.meter(ExpPostfija[i]);
        } else {
            char Op2, Op1;
            p.sacar(Op2);
            p.sacar(Op1);

            double resultado = Evalua(Op1 - '0', ExpPostfija[i], Op2 - '0');
            p.meter(resultado + '0');
        }
    }
    return p.cima() - '0';
}

string InfijaToPostfija(const string &Infija) {
    Pila p;
    string Postfija = "";

    for (size_t i = 0; i < Infija.length(); ++i) {
        if (isdigit(Infija[i])) {
            Postfija += Infija[i];
        } else {
            if (Infija[i] == '(') {
                p.meter(Infija[i]);
            } else if (Infija[i] == ')') {
                while (!p.vacia() && p.cima() != '(') {
                    char aux;
                    p.sacar(aux);
                    Postfija += aux;
                }
                char aux;
                p.sacar(aux);  // Sacar '(' de la pila
            } else {
                while (!p.vacia() && PrioridadInfija(Infija[i]) <= PrioridadPila(p.cima())) {
                    char aux;
                    p.sacar(aux);
                    Postfija += aux;
                }
                p.meter(Infija[i]);
            }
        }
    }

    while (!p.vacia()) {
        char aux;
        p.sacar(aux);
        Postfija += aux;
    }

    return Postfija;
}

bool ParentesisOk(const string &expresion) {
    Pila p;
    for (size_t i = 0; i < expresion.length(); ++i) {
        if (expresion[i] == '(') {
            p.meter(expresion[i]);
        } else if (expresion[i] == ')') {
            char aux;
            if (!p.vacia()) {
                p.sacar(aux);
            } else {
                return false;  // Hay un ')' sin un '(' correspondiente
            }
        }
    }
    return p.vacia();  // Si la pila está vacía, los paréntesis están bien colocados
}




*/

