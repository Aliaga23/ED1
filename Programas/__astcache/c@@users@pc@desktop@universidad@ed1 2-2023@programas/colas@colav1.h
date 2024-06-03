//---------------------------------------------------------------------------

#ifndef ColaV1H
#define ColaV1H
//---------------------------------------------------------------------------
#include <iostream>
#include <string>

using namespace std;

const int MAXVC1 = 12;

class ColaV1{
	private:
		int* v;
        int ini, fin;
	public:
		ColaV1();
		bool vacia();
		void poner(int e);
		void sacar(int &e);
		int primero();
		string to_str();
};

#endif
