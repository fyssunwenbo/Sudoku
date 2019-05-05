#pragma once
#include "casilla.h"
#include<fstream>

typedef tCasilla tTablero[DIMENSION][DIMENSION];

void iniciaTablero(tTablero tablero); /* inicializa el tablero tablero
de forma que todas las casillas sean vacías y tengan como valores
posibles todos los del intervalo[1, 9].*/

bool cargarTablero(string nombreFichero, tTablero tablero); /* recibe
el tablero tablero inicializado como hace el subprograma anterior, lo
actualiza con la información almacenada en el archivo de nombre
nombreFichero que contiene el tablero del sudoku a jugar y devuelve un
booleano que indica si la carga se ha podido realizar.Los valores
posibles de las casillas deberán quedar convenientemente actualizados.*/

void dibujarTablero(const tTablero tablero);
/* muestra por pantalla el tablero dado.*/

void quitarPosibles(tTablero tablero, int x, int y); 
/* Procesa los valores posibles de las casillas según el valor de(x, y) 
(con x e y en el intervalo[0, 8]).*/

bool ponerNum(tTablero tablero, int fila, int col, int c); 
/*coloca el nº c en la casilla de coordenadas (fila,col) (fila y col estarán en el
intervalo [1,9]) del tablero tablero; el booleano que devuelve indica
si la acción ha sido posible (para ello la casilla debe ser vacía y c
debe ser uno de los valores posibles de la misma). Si es posible
colocar el número dado en la casilla indicada deberán actualizarse
convenientemente los valores posibles de las casillas que puedan verse
afectadas (las de la misma fila, columna y submatriz que la casilla
dada).*/

bool borrarNum(tTablero tablero, int fila, int col);
/* borra el número que haya colocado en la casilla de
coordenadas (fila,col) (fila y col estarán en el intervalo [1,9]) del
tablero tablero y la casilla volverá a estar en estado vacío; el booleano
que devuelve indica si la
acción ha sido posible (debe ser una casilla que haya sido previamente
rellenada). Si es posible borrar el número de la casilla indicada
deberán actualizarse convenientemente los valores posibles de las
casillas que puedan verse afectadas (las de la misma fila, columna y
submatriz que la casilla dada).*/

bool tableroLleno(const tTablero tablero); /* devuelve un valor
booleano que indica si el tablero dado está relleno por completo.*/

void mostrarPosibles(const tTablero tablero, int fila, int col); 
/*muestra los valores posibles de la casilla del tablero dado que tiene
coordenadas(fila, col) (fila y col estarán en el intervalo[1, 9])*/

void rellenarSimples(tTablero tablero);
/* en cada casilla que tiene un
único valor posible se pone dicho valor y se actualizan
convenientemente los valores posibles de las casillas que puedan verse
afectadas.*/
