//Wenbo Sun
//Wenhui Lin

#include "listaSudokus.h"
#include "listaJugadores.h"

int menu() {
	cout << "--------------------Sudoku---------------------" << endl;
	int op;

	cout << " 1 - Jugar" << endl;
	cout << " 2.- Ver jugadores ordenados por identificador" << endl;
	cout << " 3.- Ver jugadores ordenados por puntos" << endl;
	cout << " 4.- Incorporar sudoku" << endl;
	cout << " 0 - Salir" << endl;
	cout << "-----------------------------------------------" << endl;
	cout << "Opcion: ";
	cin >> op;
	while (op > 4 || op < 0) {
		cout << "Opcion: ";
		cin >> op;
	}

	return op;
}

int main() {
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
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
				int point=menuListaSudokus(listaS);
				puntuarJugador(listaJ, point);
				ok2 = guardar(listaJ);
				if (!ok2) {
					cout << "ERROR guardar lista de Player." << endl;
				}				
				break;
			}
			case 2: {
				mostrar(listaJ);
				break;
			}
			case 3: {	
				tListaJugadores copia = ordenarPorRanking(listaJ);
				mostrar(copia);
				liberarArray(copia);				
				break;
			}
			case 4: {
				registrarSudoku(listaS);
				ok1 = guardar(listaS);
				if (!ok1) {
					cout << "ERROR guardar lista de Sudoku." << endl;
				}
				break;
			}

			default: break;
			}
			opcion = menu();		
		}
		
		borrarListaJugadores(listaJ);
	
	}
	system("pause");
	return 0;
}