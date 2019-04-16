#include "juego.h"

int mostrarMenuJugada() {
	int menu;

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
	if (cargarTablero(juego.sudoku.fichero, juego.tablero)) {
		ok = true;
	}
	return ok;
}

void mostrarJuego(const tJuego &juego) {

	dibujarTablero(juego.tablero);

}

int jugarUnSudoku(const tSudoku &sudoku,tJuego &juego) {
	int puntos;
	iniciaJuego(juego, sudoku);
	bool ok = cargaJuego(juego, sudoku);
	if (ok) {
		mostrarJuego(juego);
		int opcion = mostrarMenuJugada();
		while ((opcion != 0) && !juego.terminado) {
			switch (opcion) {
			case 1: {

				break;
			}
			case 2: {

				break;
			}
			case 3: {

				break;
			}
			case 4: {

				break;
			}
			case 5: {

				break;
			}
			default: {
				break;
			}

			}
			system("cls");
			mostrarJuego(juego);
			if (tableroLleno(juego.tablero)) {
				juego.terminado = true;
				puntos = juego.sudoku.nivel;
			}
			else {
				opcion = mostrarMenuJugada();
			}
			
		}
	}
	return puntos;
}
