#include "tablero.h"

void iniciaTablero(tTablero tablero) {
	for (int i = 0; i < DIMENSION;i++) {
		for (int j = 0; j < DIMENSION; j++) {
			iniciaCasilla(tablero[i][j]);
		}
	}
}

bool cargarTablero(string nombreFichero, tTablero tablero) {
	bool ok = false;
	ifstream inputFile;
	char casilla;

	inputFile.open(nombreFichero);
	if (!inputFile.is_open()) {
		cout<< "ERROR:No se ha podido abrir el archivo: " << nombreFichero + ".txt";
	}
	else {
		for (int i = 0; i < DIMENSION; i++) {
			for (int j = 0; j < DIMENSION; j++) {
				if (inputFile.eof()) {
					ok = false;
				}
				else {
					inputFile.get(casilla);
					rellenaCasilla(tablero[i][j], casilla, ok);
					/*if (pertenece(tablero[i][j].posibles, tablero[i][j].numero) &&tablero[i][j].estado != FIJA) {
						borraElemento(tablero[i][j].posibles, tablero[i][j].numero);
					}*/
					if (tablero[i][j].estado != VACIO) {
						quitarPosibles(tablero, i, j);
					}
				}
			}
			inputFile.get(casilla);
		}
		inputFile.close();

		
	}
	return true;
}

void dibujarTablero(const tTablero tablero) {
	for (int i = 0; i < DIMENSION; i++) {
		if (i % 3 == 0) {
			for (int k = 0; k < DIMENSION * 3 + 3; k++) {
				cout << "-";
			}cout << endl;
		}
		for (int j = 0; j < DIMENSION; j++) {
			if (j % 3 == 0) {
				cout << "|";
			}
			cout << " ";
			dibujaCasilla(tablero[i][j]);
			cout << " ";
		}
		cout << "|";
		cout << endl;
	}
	for (int k = 0; k < DIMENSION*3+3; k++) {
		cout << "-";
	}
	cout << endl;
}

void quitarPosibles(tTablero tablero, int x, int y) {
	int num = tablero[x][y].numero;
	if (tablero[x][y].estado == FIJA) {
		cjto_vacio(tablero[x][y].posibles);
		annadeElemento(tablero[x][y].posibles, num);
	}
		for (int i = 0; i < DIMENSION; i++) {
			if (tablero[x][i].estado != FIJA && pertenece(tablero[x][i].posibles, num)) {
				borraElemento(tablero[x][i].posibles, num);
			}
		}

		for (int i = 0; i < DIMENSION; i++) {
			if (tablero[i][y].estado != FIJA && pertenece(tablero[i][y].posibles, num)) {
				borraElemento(tablero[i][y].posibles, num);
			}
		}


		int dimCaja = DIMENSION / 3;

		for (int rfila = (x / 3)*dimCaja; rfila < (x / 3)*dimCaja + dimCaja; rfila++) {
			for (int rcol = (y / 3)*dimCaja; rcol < (y / 3)*dimCaja + dimCaja; rcol++) {
				if (tablero[rfila][rcol].estado != FIJA && pertenece(tablero[rfila][rcol].posibles, num)) {
					borraElemento(tablero[rfila][rcol].posibles, num);
				}
			}
		}
	
}


bool ponerNum(tTablero tablero, int fila, int col, int c) {
	bool ok = false;
	if (tablero[fila - 1][col - 1].estado != VACIO || !pertenece(tablero[fila - 1][col - 1].posibles, c)) {
		ok = false;
	}
	else {
		rellenaCasilla(tablero[fila - 1][col - 1], '0' + c,true);
		quitarPosibles(tablero, fila - 1, col - 1);
		ok = true;
	}
	return ok;
}

bool borrarNum(tTablero tablero, int fila, int col) {
	bool ok = false;
	int f = fila - 1; int c = col - 1;
	int borrado = tablero[f][c].numero;
	if (tablero[f][c].estado == RELLENO) {
		int borrado = tablero[f][c].numero;
		rellenaCasilla(tablero[f][c], ' ', ok);

		for (int i = 0; i < DIMENSION; i++) {
			if (tablero[f][i].estado != FIJA && !pertenece(tablero[f][i].posibles, borrado)) {
				annadeElemento(tablero[f][i].posibles, borrado);
			}
		}

		for (int i = 0; i < DIMENSION; i++) {
			if (tablero[i][c].estado != FIJA && !pertenece(tablero[i][c].posibles, borrado)) {
				annadeElemento(tablero[i][c].posibles, borrado);
			}
		}

		//Restablecer la caja sumando borrado como valor posible
		int dimCaja = DIMENSION / 3;

		for (int rfila = (fila / 3)*dimCaja; rfila < (fila / 3)*dimCaja + dimCaja; rfila++) {
			for (int rcol = (col / 3)*dimCaja; rcol < (col / 3)*dimCaja + dimCaja; rcol++) {
				if (!pertenece(tablero[rfila][rcol].posibles, borrado)&&tablero[rfila][rcol].estado != FIJA) {
					annadeElemento(tablero[rfila][rcol].posibles, borrado);
				}
			}
		}

		ok = true;
	}
	return ok;
}	

bool tableroLleno(const tTablero tablero) {
	bool ok;
	for (int i = 0; i < DIMENSION; i++) {
		for (int j = 0; j < DIMENSION; j++) {
			if (tablero[i][j].estado == RELLENO && tablero[i][j].posibles.nElems==1) {
				ok = true;
			}
		}
	}
	return ok;
}

void mostrarPosibles(const tTablero tablero, int fila, int col) {
	for (int i = 0; i <tablero[fila-1][col-1].posibles.nElems; i++) {
		cout << tablero[fila-1][col-1].posibles.elementos[i] << endl;
	}
}

void rellenarSimples(tTablero tablero) {
	for (int i = 0; i < DIMENSION; i++) {
		for (int j = 0; j < DIMENSION; j++) {
			if (esSimple(tablero[i][j], tablero[i][j].numero)) {
				rellenaCasilla(tablero[i][j], '0' + tablero[i][j].numero,true);
				quitarPosibles(tablero, i, j);
			}
		}
	}
}