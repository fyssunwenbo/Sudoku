#pragma once
#include "tablero.h"

typedef struct {
	string fichero; // nombre del archivo donde est芍 el tablero
	int nivel; // numero de puntos que permite conseguir
} tSudoku;

typedef struct {
	tSudoku sudoku;
	tTablero tablero;
	bool terminado; // indica si el tablero est芍 relleno
} tJuego;

int mostrarMenuJugada(); /* muestra el men迆 de opciones del juego y
devuelve una opci車n valida introducida por el jugador.*/

int jugarUnSudoku(const tSudoku &sudoku, tJuego &juego); /* dada la informaci車n del
sudoku elegido lleva a cabo todas las acciones correspondientes a
haber elegido la opci車n 1 de esta versi車n y devuelve la puntuaci車n
obtenida por el jugador (0 si aborta la resoluci車n antes de rellenar
el tablero o los puntos asociados al sudoku elegido en caso de
resolverlo).*/

void iniciaJuego(tJuego &juego, const tSudoku &sudoku); /* recibe en
sudoku la informaci車n del sudoku elegido para jugar e inicializa el
par芍metro juego a un juego no acabado con dicha informaci車n como
registro del sudoku a jugar y con un tablero inicializado seg迆n se ha
indicado en el m車dulo anterior.*/

bool cargaJuego(tJuego &juego, const tSudoku &sudoku); /* actualiza el
tablero del par芍metro juego con el contenido del archivo cuyo nombre
figura en el par芍metro de tipo tSudoku recibido.*/

void mostrarJuego(const tJuego &juego); /* muestra por pantalla la
informaci車n del sudoku que se va a jugar as赤 como el tablero del
mismo.*/
