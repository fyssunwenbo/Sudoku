

#include "conjunto.h"

void cjto_vacio(tConjunto &c) {
	for (int i = 0; i < DIMENSION; i++) {
		c.elementos[i] = 0;
	}
	c.nElems = 0;
}// inicializa el conjunto c al conjunto vacío.


void cjto_lleno(tConjunto &c) {
	for (int i = 0; i < DIMENSION; i++) {
		c.elementos[i] = i + 1;
		c.nElems++;
	}
} // inicializa el conjunto c al conjunto formado por todos los valores del intervalo[1, 9].


bool pertenece(const tConjunto &c, int e){
	bool ok = false;
	int i = 0;
	while (!ok&&i < c.nElems) {
		if (e == c.elementos[i]) {
			ok = true;
		}
		i++;
	}
	return ok;
}  // devuelve un booleano que indica si el elemento e(nº entero [1, 9]) se encuentra en el conjunto c.

void annadeElemento(tConjunto &c, int e) {
	c.elementos[c.nElems] = e;
	c.nElems++;
} // mete el elemento e (nº entero [1, 9]) en el conjunto c.

void borraElemento(tConjunto &c, int e) {
	bool ok = false;
	int i = 0;
	while (!ok && i < c.nElems) {
		if (e == c.elementos[i]) {
			ok = true;
			for (int j = i; j < c.nElems; ++j) {
				c.elementos[j] = c.elementos[j + 1];
			}
			c.nElems--;
		}
		i++;
	}
} // saca el elemento e (nº entero [1, 9]) del conjunto c.

int numElems(const tConjunto &c) {
	int num = 0;
	num=c.nElems;
	return num;
}  // devuelve el nº de elementos que hay en el conjunto c.

bool esUnitario(const tConjunto &c, int &e) {
	bool unitario = false;

	int i = 0;
	while (unitario&&i < c.nElems) {
		if (c.elementos[i] != e) {
			unitario = true;
		}
		i++;
	}
	return unitario;
} // devuelve un booleano que indica si c tiene un único elemento y, de ser así, lo devuelve.

void mostrar(const tConjunto &c) {
	cout << "--------------------------------------------------" << endl <<
		"Hay " << c.nElems << " elementos en la lista." << endl;
	for (int i = 0; i < c.nElems; i++) {
		cout << "Elemento:" << i << "->" << c.elementos[i] << "." << endl;
	}
} // visualiza por pantalla los elementos del conjunto c.