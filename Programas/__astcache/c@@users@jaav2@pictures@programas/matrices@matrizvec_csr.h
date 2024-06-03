//---------------------------------------------------------------------------

#ifndef MatrizVec_CSRH
#define MatrizVec_CSRH
//---------------------------------------------------------------------------
     #include <iostream>
#include <string>


using namespace std;

class MatrizVC {
private:
	int* vf;
	int* vc;
	int* vd;
	int df, dc;
	int repe;
	int nt;

    int fila(int indiceVC);
	int existe_elemento(int f,int c);
	// busca en vd,vc y vf si existe el elemento
	int donde_insertar(int f,int c);
	// determina donde insertar en vd,vc y vf

public:
	MatrizVC();
	void dimensionar(int f, int c);
	int dimension_fila();
	int dimension_columna();
	void poner(int f, int c, int valor);
	int elemento(int f, int c);
	void definir_valor_repetido(int valor);
	string to_str();
};
#endif
