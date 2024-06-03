//---------------------------------------------------------------------------

#ifndef DicolaV3H
#define DicolaV3H
//---------------------------------------------------------------------------
#include <iostream>
#include <string>


using namespace std;

const int MAXVD3 = 9;

class DicolaV3 {
private:
	int* v;
	int ini, fin;

	int siguiente(int dir);
	int anterior(int dir);

public:
	DicolaV3();
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
