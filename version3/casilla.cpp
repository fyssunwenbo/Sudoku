#include "casilla.h"


void iniciaCasilla(tCasilla &casilla) {
	casilla.numero = 0;
	cjto_vacio(casilla.posibles);
	cjto_lleno(casilla.posibles);
}

void rellenaCasilla(tCasilla &casilla, char c, bool fija) {
	switch (c) {
		case ' ': {
			casilla.estado = VACIO;
			casilla.numero = 0;
			break;
		}
		case '1': {
			if (fija) 
				casilla.estado = RELLENO;
			else {
				casilla.estado = FIJA;
			}
				casilla.numero = 1;
			

			break;
		}
		case '2': {
			if (fija)casilla.estado = RELLENO;
			else {
				casilla.estado = FIJA;
			}
				casilla.numero = 2;
			
			break;
		}
		case '3': {
			if (fija)casilla.estado = RELLENO;
			else {
				casilla.estado = FIJA;
			}
				casilla.numero = 3;
			
			break;
		}
		case '4': {
			if (fija)casilla.estado = RELLENO;
			else {
				casilla.estado = FIJA;
			}
				casilla.numero = 4;
			
			break;
		}
		case '5': {
			if (fija)casilla.estado = RELLENO;
			else {
				casilla.estado = FIJA;
			}
				casilla.numero = 5;
			
			break;
		}
		case '6': {
			if (fija)casilla.estado = RELLENO;
			else {
				casilla.estado = FIJA;
			}
				casilla.numero = 6;
			
			break;
		}
		case '7': {
			if (fija)casilla.estado = RELLENO;
			else {
				casilla.estado = FIJA;
			}
				casilla.numero = 7;
			
			break;
		}
		case '8': {
			if (fija)casilla.estado = RELLENO;
			else {
				casilla.estado = FIJA;
			}
				casilla.numero = 8;
			
			break;
		}
		case '9': {
			if (fija)casilla.estado = RELLENO;
			else {
				casilla.estado = FIJA;
			}
				casilla.numero = 9;
			
			break;
		}
		default: {
			casilla.estado = VACIO;
			break;
		}
	}
}

void colorFondo(int color) {
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(handle, 15 | (color << 4));
}

void dibujaCasilla(const tCasilla & casilla) {
	colorFondo(PALETA[casilla.estado]);
	//Si la casilla esta vacia
	if (casilla.estado == VACIO) {
		cout << " ";

	}
	else {
		cout << casilla.numero;
	}
	//restablecer negro
	colorFondo(0);
}

bool esSimple(const tCasilla & casilla, int & numero) {
	bool simple = true;

	if (casilla.estado == FIJA || casilla.estado == RELLENO) {
		simple = false;
	}
	else {
		if (casilla.posibles.nElems != 1) {
			simple = false;
		}
		else {
			numero = casilla.posibles.elementos[casilla.posibles.nElems-1];
		}
	}
	return simple;
}