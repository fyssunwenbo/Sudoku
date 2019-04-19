#pragma once
#include "juego.h"
#include<iomanip>

const int MAX_SUDOKUS = 20;

typedef tSudoku tSudokus[MAX_SUDOKUS];

typedef struct {
	tSudokus array; // array de sudokus
	int cont;
} tListaSudokus; // lista de longitud variable de sudokus

void creaListaVacia(tListaSudokus &lista);
/* inicializa lista a una lista vac¨ªa. */

bool cargar(tListaSudokus &lista); /* guarda en lista el contenido del
archivo listaSudokus.txt; devuelve un booleano que indica si la carga
se ha podido realizar. */

void mostrar(const tListaSudokus &lista); /* visualiza por pantalla la
lista de sudokus dada.*/

int menuListaSudokus(const tListaSudokus &lista); /* muestra la lista
de sudokus, lee la selecci¨®n del jugador e invoca a la funci¨®n
jugarUnSudoku con el sudoku correspondiente(del array de sudokus).*/