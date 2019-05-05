#include "listaSudokus.h"
#include "listaJugadores.h"

int menu() {
	int op;

	cout << " 1 - Jugar" << endl;
	cout << " 2.- Ver jugadores ordenados por identificador" << endl;
	cout << " 3.- Ver jugadores ordenados por puntos" << endl;
	cout << " 4.- Incorporar sudoku" << endl;
	cout << " 0 - Salir" << endl;
	cout << "Opcion: ";
	cin >> op;
	while (op > 4 || op < 0) {
		cout << "Opcion: ";
		cin >> op;
	}

	return op;
}

int main() {

	tListaSudokus listaS;
	tListaJugadores listaJ;
	bool ok1 = cargar(listaS);
	bool ok2 = cargar(listaJ);

	if (!ok1) {
		cout << "ERROR en lista de Sudoku." << endl;
	}
	if (!ok2) {
		cout << "ERROR en lista de Jugador." << endl;
	}
	if(ok1 && ok2) {
		int opcion = menu();
		while (opcion != 0) {
			switch (opcion) {
			case 1: {
				menuListaSudokus(listaS);
				break;
			}
			case 2: {
				mostrar(listaJ);
				break;
			}
			case 3: {				
				mostrar(ordenarPorRanking(listaJ));
				break;
			}
			case 4: {
				registrarSudoku(listaS);
				break;
			}

			default: break;
			}
			opcion = menu();		
		}
		ok1 = guardar(listaS);
		if (!ok1) {
			cout << "ERROR guardar lista de Sudoku." << endl;
			}

		ok2 = guardar(listaJ);
		if (!ok2) {
			cout << "ERROR guardar lista de Player." << endl;
			}
			
	}
	system("pause");
	return 0;
}