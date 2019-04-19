#pragma once
#include "conjunto.h"
#include<Windows.h>


const int PALETA[3] = { 0,1,4 }; // colores asociados a los estados

typedef enum { VACIO, FIJA, RELLENO } tEstadoCasilla;

typedef struct {
	int numero;
	tEstadoCasilla estado;
	tConjunto posibles; //valores posibles de una casilla
} tCasilla;


void iniciaCasilla(tCasilla &casilla); /* inicializa el estado de la
casilla dada a vacío y su conjunto de valores posibles al conjunto
{
	1, 2, 3, 4, 5, 6, 7, 8, 9
}.*/

void rellenaCasilla(tCasilla &casilla, char c, bool fija);
/*rellena el estado y el nº de casilla de acuerdo con los valores de
fija y c.Si c es el carácter espacio en blanco se tratará de una
casilla vacía; si c ['0', '9'] el nº que almacena esa casilla será
el entero equivalente(c – '0') y fija indicará si se trata de una
casilla fija(valor true para fija) o rellenada(valor por defecto
false).*/

void dibujaCasilla(const tCasilla & casilla); /* pinta en pantalla la
casilla dada.Se mostrarán sobre fondo azul las casillas fijas y sobre
fondo rojo las casillas rellenadas.El resto, sobre el fondo negro por
defecto.*/

bool esSimple(const tCasilla & casilla, int & numero); /* devuelve un
valor que indica si una casilla vacía tiene un único valor posible y,
en caso afirmativo, también lo devuelve; devuelve false para casillas
fijas o rellenadas.*/

void colorFondo(int color);