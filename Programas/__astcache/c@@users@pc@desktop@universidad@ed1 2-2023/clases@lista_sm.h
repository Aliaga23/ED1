//---------------------------------------------------------------------------

#ifndef Lista_SMH
#define Lista_SMH
//---------------------------------------------------------------------------
#include <iostream>
#include <string>
#include "CsMemoria.h"
using namespace std;

const string datoNL = "elemento,sig";
const string elemNL = "->elemento";
const string sigNL = "->sig";

class ListaS
{
  private:
	int ptr_elementos;
	int longit;
	CsMemoria* mem;
  public:
	ListaS();
	ListaS(CsMemoria* m);
	int fin();
	int primero();
	int siguiente(int d);
	int anterior(int d);
	bool vacia();
	int recupera(int d);
	int longitud();
	void inserta(int d, int e);
	void inserta_primero(int e);
	void inserta_ultimo(int e);
	void suprime(int d);
	void modifica(int d, int e);
	string to_str();
	int localiza(int e);
	void elimina_dato(int e);
	void anula();
    void EliminarAlInicio();
};
#endif

