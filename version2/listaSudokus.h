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
/* inicializa lista a una lista vac赤a. */

bool cargar(tListaSudokus &lista); /* guarda en lista el contenido del
archivo listaSudokus.txt; devuelve un booleano que indica si la carga
se ha podido realizar. */

void mostrar(const tListaSudokus &lista); /* visualiza por pantalla la
lista de sudokus dada.*/

int menuListaSudokus(const tListaSudokus &lista); /* muestra la lista
de sudokus, lee la selecci車n del jugador e invoca a la funci車n
jugarUnSudoku con el sudoku correspondiente(del array de sudokus).*/

bool guardar(const tListaSudokus &lista); /* almacena en el archivo
listaSudokus.txt el contenido de la lista y devuelve un valor
booleano indicando si la acci車n fue posible.Debe respetar el
formato indicado para el archivo.*/

bool registrarSudoku(tListaSudokus &lista); /* solicita los datos de
un nuevo sudoku(nombre del fichero y puntos que permite conseguir)
y si no existe un sudoku en lista con igual nombre de fichero lo
inserta en la posici車n adecuada respetando el orden existente.Se
devuelve un booleano que indica si se pudo registrar un nuevo
sudoku, para lo cual tambi谷n hay que tener en cuenta si la lista
est芍 o no llena.*/

void insertar(tListaSudokus &lista, const tSudoku &sudoku, bool &lleno, bool &encontrado);
/* inserta un sudoku sudoku en la lista
	de sudokus y devuelve dos booleanos indicando si la lista est芍
	llena y si ha encontrado el sudoku en la lista*/

bool buscarFichero(const tListaSudokus &lista, string nombreFich);
/* devuelve un boleano que indica si existe o no un sudoku en lista
con nombre de fichero igual a nombreFich.*/

bool operator<(const tSudoku &opIzq, const tSudoku &opDer); /*
	sobrecarga del operador < para los sudokus.Devuelve true si el
	nivel del sudoku opIzq es menor que el nivel del sudoku opDer y, a
	igual nivel, devuelve true si el fichero del Sudoku opIzq es menor
	que el fichero del Sudoku opDer.*/

int buscarPos(const tListaSudokus &lista, const tSudoku &sudoku); /*
devuelve la posici車n de lista en la que deber赤a insertarse sudoku
para respetar el orden existente en la lista.Debe implementar una
b迆squeda binaria.*/