//---------------------------------------------------------------------------

#pragma hdrstop

#include "Menu_Conjunto.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
void MenuSm(CsMemoria* m, ConjuntoSm* a, ConjuntoSm* b, ConjuntoSm* c)
{
    cout << "1.Crear Memoria\n";
    cout << "2.Pedir espacio memoria\n";
    cout << "3.Crear Conjunto A\n";
    cout << "4.Crear Conjunto B\n";
    cout << "5.Crear Conjunto C\n";
    cout << "6.Insertar Elemento\n";
    cout << "7.Mostrar Conjunto\n";
    cout << "8.Unir y poner en C\n";
    cout << "9.Intersectar y poner C\n";
    cout << "10.Mostrar\n";

    cout << "11.Salir\n";
    int opcion;
    cout << "Escoja una opcion :";
    cin >> opcion;
    switch (opcion) {
        case 1: {
            m = new CsMemoria();
        } break;
        case 2: {
		string id;
				cin.ignore();
                cout << "IDs: ";
				getline(cin, id);
				m->new_espacio(id);
        } break;
        case 3: {
			a = new ConjuntoSm(m);
		} break;
		case 4: {
			b = new ConjuntoSm(m);
		} break;
		case 5: {
            c = new ConjuntoSm(m);
        } break;
        case 6: {
            int e;
            cout << "Elemento a insertar: ";
            cin >> e;
            int conj;
            cout << "Escriba 1 para conjunto A\n";
            cout << "Escriba 2 para conjunto B\n";
            cout << "Escriba 3 para conjunto C\n";
            cin >> conj;
            if (conj == 1)
                a->inserta(e);
            else if (conj == 2)
                b->inserta(e);
            else if (conj == 3)
                c->inserta(e);
        } break;
        case 7: {
            int conj;
            cout << "Escriba 1 para conjunto A\n";
            cout << "Escriba 2 para conjunto B\n";
            cout << "Escriba 3 para conjunto C\n";
            cin >> conj;
            if (conj == 1)
                cout << a->to_str() << endl;
            else if (conj == 2)
                cout << b->to_str() << endl;
            else if (conj == 3)
                cout << c->to_str() << endl;
        } break;
        case 8: {
            a->unir(b, c);
        } break;
		case 9: {
			//a->intersectar(b, c);
            a->ordenarConjunto();
		} break;
		case 10: {
			  m->mostrar();
		} break;
	}
	if (opcion != 11) {
        system("pause");
        system("cls");
        MenuSm(m, a, b, c);
    }
}

void MenuVector(ConjuntoV* a, ConjuntoV* b, ConjuntoV* c)
{
    cout << "1.Crear Conjunto A\n";
    cout << "2.Crear Conjunto B\n";
    cout << "3.Crear Conjunto C\n";
    cout << "4.Insertar Elemento\n";
    cout << "5.Mostrar Conjunto\n";
    cout << "6.Unir y poner en C\n";
    cout << "7.Intersectar y poner C\n";
    cout << "8.Salir\n";
    int opcion;
    cout << "Escoja una opcion :";
    cin >> opcion;
    switch (opcion) {
        case 1: {
            a = new ConjuntoV();
        } break;
        case 2: {
            b = new ConjuntoV();
        } break;
        case 3: {
            c = new ConjuntoV();
        } break;
        case 4: {
            int e;
            cout << "Elemento a insertar: ";
            cin >> e;
            int conj;
            cout << "Escriba 1 para conjunto A\n";
            cout << "Escriba 2 para conjunto B\n";
            cout << "Escriba 3 para conjunto C\n";
            cin >> conj;
            if (conj == 1)
                a->inserta(e);
            else if (conj == 2)
                b->inserta(e);
            else if (conj == 3)
                c->inserta(e);
        } break;
        case 5: {
            int conj;
            cout << "Escriba 1 para conjunto A\n";
            cout << "Escriba 2 para conjunto B\n";
            cout << "Escriba 3 para conjunto C\n";
            cin >> conj;
            if (conj == 1)
                cout << a->to_str() << endl;
            else if (conj == 2)
                cout << b->to_str() << endl;
            else if (conj == 3)
                cout << c->to_str() << endl;
        } break;
        case 6: {
            a->unir(b, c);
        } break;
        case 7: {
            a->intersectar(b, c);
        } break;
    }
    if (opcion != 8) {
        system("pause");
        system("cls");
        MenuVector(a, b, c);
    }
}

void MenuListaPtr(ConjuntoListaPtr *a, ConjuntoListaPtr *b, ConjuntoListaPtr *c)
{
	cout << "1.Crear Conjunto A\n";
	cout << "2.Crear Conjunto B\n";
	cout << "3.Crear Conjunto C\n";
	cout << "4.Insertar Elemento\n";
	cout << "5.Mostrar Conjunto\n";
	cout << "6.Unir y poner en C\n";
	cout << "7.Intersectar y poner C\n";
	cout << "8.Salir\n";
	int opcion;
	cout << "Escoja una opcion :";
	cin >> opcion;
	switch (opcion) {
	case 1: {
			a = new ConjuntoListaPtr();
		} break;
	case 2: {
			b = new ConjuntoListaPtr();
		} break;
	case 3: {
			c = new ConjuntoListaPtr();
		} break;
	case 4: {
			int e;
			cout << "Elemento a insertar: ";
			cin >> e;
			int conj;
			cout << "Escriba 1 para conjunto A\n";
			cout << "Escriba 2 para conjunto B\n";
			cout << "Escriba 3 para conjunto C\n";
			cin >> conj;
			if (conj == 1)
				a->inserta(e);
			else if (conj == 2)
				b->inserta(e);
			else if (conj == 3)
				c->inserta(e);
		} break;
	case 5: {
			int conj;
			cout << "Escriba 1 para conjunto A\n";
			cout << "Escriba 2 para conjunto B\n";
			cout << "Escriba 3 para conjunto C\n";
			cin >> conj;
			if (conj == 1)
				cout << a->toStr() << endl;
			else if (conj == 2)
				cout << b->toStr() << endl;
			else if (conj == 3)
				cout << c->toStr() << endl;
		} break;
	case 6: {
			a->unir(b, c);
		} break;
	case 7: {
			a->intersectar(b, c);
		} break;
	}
	if (opcion != 8) {
		system("pause");
		system("cls");
		MenuListaPtr(a, b, c);
	}
}

void MenuPtr(ConjuntoPtr *a, ConjuntoPtr *b, ConjuntoPtr *c) {
	cout << "1.Crear Conjunto A\n";
	cout << "2.Crear Conjunto B\n";
	cout << "3.Crear Conjunto C\n";
	cout << "4.Insertar Elemento\n";
	cout << "5.Mostrar Conjunto\n";
	cout << "6.Unir y poner en C\n";
	cout << "7.Intersectar y poner C\n";
	cout << "8.Salir\n";
	int opcion;
	cout << "Escoja una opcion :";
	cin >> opcion;
	switch (opcion) {
	case 1: {
			a = new ConjuntoPtr();
		} break;
	case 2: {
			b = new ConjuntoPtr();
		} break;
	case 3: {
			c = new ConjuntoPtr();
		} break;
	case 4: {
			int e;
			cout << "Elemento a insertar: ";
			cin >> e;
			int conj;
			cout << "Escriba 1 para conjunto A\n";
			cout << "Escriba 2 para conjunto B\n";
			cout << "Escriba 3 para conjunto C\n";
			cin >> conj;
			if (conj == 1)
				a->inserta(e);
			else if (conj == 2)
				b->inserta(e);
			else if (conj == 3)
				c->inserta(e);
		} break;
	case 5: {
			int conj;
			cout << "Escriba 1 para conjunto A\n";
			cout << "Escriba 2 para conjunto B\n";
			cout << "Escriba 3 para conjunto C\n";
			cin >> conj;
			if (conj == 1)
				cout << a->to_str() << endl;
			else if (conj == 2)
				cout << b->to_str() << endl;
			else if (conj == 3)
				cout << c->to_str() << endl;
		} break;
	case 6: {
			a->unir(b, c);
		} break;
	case 7: {
			a->intersectar(b, c);
		} break;
	}
	if (opcion != 8) {
		system("pause");
		system("cls");
		MenuPtr(a, b, c);
	}
}
