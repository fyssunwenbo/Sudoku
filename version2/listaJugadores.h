#pragma once
#include<fstream>
#include <iostream>
#include<iomanip>
#include "jugador.h"

const int MAX_JUGADORES = 10;

const string BD = "listaJugadores.txt";

typedef tJugador tArrayJugadores[ MAX_JUGADORES ];

typedef struct {
	tArrayJugadores jugadores;
	int cont;
} tListaJugadores;

void creaListaVacia(tListaJugadores &lista); // inicializa lista a una lista vac赤a.

bool cargar(tListaJugadores &lista); /* guarda en lista el contenido
del archivo listaJugadores.txt; devuelve un booleano que indica si
la carga se ha podido realizar.*/

void mostrar(const tListaJugadores &lista); /* visualiza por
pantalla la lista de jugadores dada.*/

bool guardar(const tListaJugadores &lista); /* almacena en el
archivo listaJugadores.txt el contenido de lista y devuelve un
valor booleano indicando si la acci車n fue posible.Debe respetar el
formato indicado para el archivo.*/

void puntuarJugador(tListaJugadores &lista, int puntos); /* solicita
que se introduzca el identificador de un jugador por teclado y se
actualiza su informaci車n en lista.La actualizaci車n puede consistir
en aumentar su puntuaci車n con los nuevos puntos obtenidos(si el
jugador se encontraba ya en la lista) o en incorporarlo a la lista
con la puntuaci車n obtenida(si no est芍 llena).*/

void insertar(tListaJugadores & lista, const string &id, int puntos, bool & ok);
/* busca el jugador con id en la lista, sino lo
encuentra lo inserta en la posici車n adecuada(si la lista no est芍
llena) y si lo encuentra modifica sus puntos sumando puntos.*/

bool buscar(const tListaJugadores &lista, string id, int &pos); /*
busca al jugador con identificador id en lista; devuelve true y la
posici車n(pos) en la que se encuentra si el jugador est芍 en la
lista; devuelve false y la posici車n(pos) en la que deber赤a estar
si el jugador no est芍 en la lista.Debe implementar una b迆squeda
binaria.*/

tListaJugadores ordenarPorRanking(const tListaJugadores &lista); /*
devuelve una copia de la lista dada ordenada por ranking
(decrecientemente por puntos, y a igualdad de puntos crecientemente
	por identificador).*/

tListaJugadores copia(const tListaJugadores &lista); /* devuelve una
copia de la lista lista.*/