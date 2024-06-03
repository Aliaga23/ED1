//---------------------------------------------------------------------------

#ifndef ListasPtrH
#define ListasPtrH
//---------------------------------------------------------------------------
#include <iostream>
#include <string>

using namespace std;

struct NodoLP
{
    int elemento;
    NodoLP* sig;
};

class ListaPtr
{
  private:
    NodoLP* ptrElementos;
    int longi;

    void intercambio(NodoLP*, NodoLP*);
  public:
    ListaPtr();
    // Funciones de direccion
    NodoLP* fin();
    NodoLP* primero();
    NodoLP* siguiente(NodoLP*);
    NodoLP* anterior(NodoLP*);
    // Selector
    int recupera(NodoLP*);
    // modificadores
    void inserta(NodoLP*, int);
    void inserta_inicio(int);
    void inserta_fin(int);
    void suprime(NodoLP*);
    void modifica(NodoLP*, int);
    //
    bool vacia();
    int longitud();
    string toStr();
    //
    NodoLP* localiza(int);
    void elimina_dato(int);
    void anula();
    void muestra_nodos();
    // Ejercicios tipo examen
    bool es_palindroma();
    void inserta(int, int);
    void elimina_nodo_con_mayor_dato();
    ListaPtr* sin_repetidos_ptr();
    ListaPtr sin_repetidos();
    void ordenamiento();
    NodoLP* nodoEnPosicion(int k);
};
#endif

