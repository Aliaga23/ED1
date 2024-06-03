//---------------------------------------------------------------------------

#ifndef PoliJAAVH
#define PoliJAAVH
//---------------------------------------------------------------------------
#include <iostream>
#include <string>

using namespace std;

const int MAXp = 10;

class PoliJAAV
{
  private:
	int VJAAV[MAXp];
    int nt;
  public:
    PoliJAAV();
    bool es_cero();
    int grado();
    int coeficiente(int exp);
    void asignar_coeficiente(int coef, int exp);
    void poner_termino(int coef, int exp);
    int numero_terminos();
    int exponente(int nro);
    void sumar(PoliJAAV* p1, PoliJAAV* p2, PoliJAAV*&pr);
    void restar(PoliJAAV* p1, PoliJAAV* p2, PoliJAAV*&pr);
    void multiplicar(PoliJAAV* p1, PoliJAAV* p2, PoliJAAV*&pr);
    void derivar();
    void to_str();
    void generar();
    double evalua(double x);
    string to_str2();
    void mostrar_integral();
    PoliJAAV* integral();
	double area(int a, int b);
	double area2(double a, double b);
	void punto_minimo(double a, double b);
	void punto_maximo(double a, double b);
};

#endif

