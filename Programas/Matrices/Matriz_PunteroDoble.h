//---------------------------------------------------------------------------

#ifndef Matriz_PunteroDobleH
#define Matriz_PunteroDobleH
//---------------------------------------------------------------------------
#include <iostream>
#include <string>


using namespace std;

struct NodoMc {
	int col;
	int dato;
	NodoMc* sigC;
};

struct NodoMf {
	int fil;
	NodoMf* antF;
	NodoMf* sigF;
	NodoMc* ptrCol;
};

class MatrizPD {
private:
	NodoMf* ptrFil;
	int repe, df, dc;
	int nt;

	NodoMc* buscar(int f, int c);
	NodoMf* buscar(int f);
	NodoMf* posicionIns(int f);
	void insertar(int f, int c, int v);
	void suprimir(NodoMf* dirFil, NodoMc* dirCol);
	void suprimir(NodoMf* dir);

public:
	MatrizPD();
	void dimensionar(int f, int c);
	int dimension_fila();
	int dimension_columna();
	void poner(int f, int c, int valor);
	int elemento(int f, int c);
	void definir_valor_repetido(int valor);
	string to_str();

};
#endif
