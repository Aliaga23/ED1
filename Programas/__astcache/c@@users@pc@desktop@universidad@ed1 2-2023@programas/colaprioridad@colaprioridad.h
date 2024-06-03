//---------------------------------------------------------------------------

#ifndef ColaPrioridadH
#define ColaPrioridadH
//---------------------------------------------------------------------------
       #include <iostream>
#include <string>
//#include "Funciones.h"
#include "ColaLista.h"
#include "ColaPun.h"
#include "ColaV3.h"

using namespace std;

const int MAX_CL = 3;

class ColaPrioridad {
private:
	ColaV3* vc;
	int* vf;
	int cola_act;
	int cant;

public:
	ColaPrioridad();
	bool vacia();
	int primero();
	void poner(int e, int prior);
	void sacar(int &e);
	void asignar_frec_prioridad(int frec, int prior);
	string to_str();
};
#endif
