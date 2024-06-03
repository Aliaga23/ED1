//---------------------------------------------------------------------------

#ifndef DicolaV2H
#define DicolaV2H
//---------------------------------------------------------------------------
#include <iostream>
#include <string>
using namespace std;

const int MAXVD2 = 20;

class DicolaV2 {
private:
	int* v;
	int ini, fin;

public:
	DicolaV2();
	bool vacia();
	void poner(int e);
	void sacar(int &e);
	int primero();
	int ultimo();
	void poner_frente(int e);
	void sacar_final(int &e);
	string to_str();
};
#endif
