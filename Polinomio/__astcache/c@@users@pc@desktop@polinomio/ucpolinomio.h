//---------------------------------------------------------------------------

#ifndef UCPolinomioH
#define UCPolinomioH
//---------------------------------------------------------------------------
#include <iostream>
#include <string>

using namespace std;

struct NodoPo {
	int coef;
	int exp;
	NodoPo* sig;
};

class Cpolinomio {
private:
	NodoPo* ptr_poli;
	int nt;

	NodoPo* buscar_exponente(int exp);
	NodoPo* buscar_termino_n(int i);
	NodoPo* anterior(NodoPo* dir);
	void suprime(NodoPo* dir);

public:
	Cpolinomio();
	bool es_cero();
	int grado();
	int coeficiente(int exp);
	void asignar_coeficiente(int coef, int exp);
	void poner_termino(int coef, int exp);
	int numero_terminos();
	int exponente(int nro_ter);
	float evaluar(float x);
	void derivada(Cpolinomio *p);
	void mostrar_integral();
	Cpolinomio* suma(Cpolinomio* a, Cpolinomio* b);
	Cpolinomio* resta(Cpolinomio* a, Cpolinomio* b);
	Cpolinomio* producto(Cpolinomio* a, Cpolinomio* b);
	string to_str();

};

#endif
