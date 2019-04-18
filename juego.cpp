#include "juego.h"

int mostrarMenuJugada() {

	int op;

	cout << " 1.- Ver posibles valores de una casilla vacia" << endl;
	cout << " 2.- Colocar valor en una casilla" << endl;
	cout << " 3.- Borrar valor de una casilla" << endl;
	cout << " 4.- Reiniciar el tablero" << endl;
	cout << " 5.- Autocompletar celdas simples" << endl;
	cout << " 0.- Abortar la resolucion y volver al menu principal" << endl;

	cout << "Opcion: ";
	cin >> op;
	while (op > 5 || op < 0) {
		cout << "Opcion: ";
		cin >> op;
	}
	return op;
}

void iniciaJuego(tJuego &juego, const tSudoku &sudoku) {
	
	iniciaTablero(juego.tablero);

}

bool cargaJuego(tJuego &juego, const tSudoku &sudoku) {
	bool ok = false;
	if (cargarTablero(sudoku.fichero, juego.tablero)) {
		ok = true;
	}
	return ok;
}

void mostrarJuego(const tJuego &juego) {

	dibujarTablero(juego.tablero);

}

int jugarUnSudoku(const tSudoku &sudoku) {
	int puntos=0;
	tJuego juego;
	iniciaJuego(juego, sudoku);
	bool ok = cargaJuego(juego, sudoku);
	if (ok) {
		mostrarJuego(juego);
		int opcion = mostrarMenuJugada();
		while ((opcion != 0) && !juego.terminado) {
			switch (opcion) {
			case 1: {
				int f, c;
				cout << "Escribe las filas y columnas de la caja." << endl;
				cout << "Fila: "; cin >> f; 
				cout << "Columna: "; cin >> c; 
				mostrarPosibles(juego.tablero, f, c);
				break;
			}
			case 2: {
				int f,c,valor;
				cout << "Escribe las filas y columnas de la caja." << endl;
				cout << "Fila: "; cin >> f; 
				cout << "Columna: "; cin >> c; 
				cout << "Escribe una valor." << endl;
				cout << "Valor: "; cin >> valor;
				ponerNum(juego.tablero, f, c, valor);
				break;
			}
			case 3: {
				int f, c;
				cout << "Escribe las filas y columnas de la caja." << endl;
				cout << "Fila: "; cin >> f; 
				cout << "Columna: "; cin >> c; 
				borrarNum(juego.tablero, f, c);
				break;
			}
			case 4: {
				iniciaJuego(juego, sudoku);
				cargaJuego(juego, sudoku);
				break;
			}
			case 5: {
				rellenarSimples(juego.tablero);
				break;
			}
			default: {
				opcion = mostrarMenuJugada();
				break;
			}

			}
			system("cls");
			mostrarJuego(juego);
			if (tableroLleno(juego.tablero)) {
				juego.terminado = true;
				puntos = sudoku.nivel;
			}
			else {
				opcion = mostrarMenuJugada();
			}
			
		}
	}
	return puntos;
}
