#include "listaSudokus.h"


void creaListaVacia(tListaSudokus &lista) {
	for (int i = 0; i < MAX_SUDOKUS; i++) {
		lista.array[i].fichero = " ";
	}
	lista.cont = 0;
}

bool cargar(tListaSudokus &lista) {
	bool ok = false;
	ifstream inputFile;
	string  listaSudokus = "listaSudokus.txt";
	inputFile.open(listaSudokus);
	if (!inputFile.is_open()) {
		cout << "ERROR:No se ha podido abrir el archivo: " << listaSudokus << endl;
	}
	else {
		int i = 0;
		while ((!inputFile.eof())&&i<MAX_SUDOKUS) {
				inputFile >> lista.array[i].fichero >> lista.array[i].nivel;
				lista.cont++;
				i++;	
		}
		ok = true;
	}
	return ok;
}

void mostrar(const tListaSudokus &lista) {
	cout << "     NOMBRE       NIVEL" << endl;
	for (int i = 0; i < lista.cont; i++) {
		cout << i + 1 << ".---" << lista.array[i].fichero << right << setw(4) << lista.array[i].nivel << endl;
	}
}

int menuListaSudokus(const tListaSudokus &lista, tJuego &juego) {
	int op; float points;
	mostrar(lista);
	cout << "Choose a Sudoku Game: " << endl;
	cin >> op;
	while (op > lista.cont||op<0) {
		cout << "Choose a Sudoku Game: " << endl;
		cin >> op;
	}
	if (op <= lista.cont||points==lista.array[op-1].nivel) {
		points=jugarUnSudoku(lista.array[op-1], juego);
	}
	
	return points;

}