#pragma once
#include<iostream>
#include<string>

using namespace std;
const int DIMENSION = 9;
typedef int tElementos[DIMENSION]; //Tipo de datos que representa
//un subconjunto del conjunto de elementos{ 1,2,3,4,5,6,7,8,9 }

typedef struct {
	int nElems; //cardinal del conjunto
	tElementos elementos; //elementos contenidos en el conjunto
} tConjunto;

void cjto_vacio(tConjunto &c);   // inicializa el conjunto c al conjunto vacío.
void cjto_lleno(tConjunto &c); // inicializa el conjunto c al conjunto formado por todos los valores del intervalo[1, 9].
bool pertenece(const tConjunto &c, int e);  // devuelve un booleano que indica si el elemento e(nº entero [1, 9]) se encuentra en el conjunto c.
void annadeElemento(tConjunto &c, int e);  // mete el elemento e (nº entero [1, 9]) en el conjunto c.
void borraElemento(tConjunto &c, int e);  // saca el elemento e (nº entero [1, 9]) del conjunto c.
int numElems(const tConjunto &c);   // devuelve el nº de elementos que hay en el conjunto c.
bool esUnitario(const tConjunto &c, int &e);   // devuelve un booleano que indica si c tiene un único elemento y, de ser así, lo devuelve.
void mostrar(const tConjunto &c); // visualiza por pantalla los elementos del conjunto c.