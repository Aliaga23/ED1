//---------------------------------------------------------------------------

#ifndef Menu_ConjuntoH
#define Menu_ConjuntoH
//---------------------------------------------------------------------------

#include "Conjunto_Lis.h"
#include "Conjunto_Pun.h"
#include "Conjunto_Vec.h"
#include "Conjunto_SM.h"
#include <iostream>

void MenuSm(CsMemoria* mem, ConjuntoSm* a, ConjuntoSm* b, ConjuntoSm* c);
void MenuVector(ConjuntoV* a, ConjuntoV* b, ConjuntoV* c);
void MenuListaPtr(ConjuntoListaPtr *a, ConjuntoListaPtr *b,
	ConjuntoListaPtr *c);
void MenuPtr(ConjuntoPtr* a, ConjuntoPtr* b, ConjuntoPtr* c);
#endif

