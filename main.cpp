#include "listaSudokus.h"

int menu() {
	int op;

	cout << " 1 - Jugar" << endl;
	cout << " 0 - Salir" << endl;
	cout << "Opcion: ";
	cin >> op;
	while (op > 1 || op < 0) {
		cout << "Opcion: ";
		cin >> op;
	}

	return op;
}

int main() {

	tListaSudokus lista;
	tJuego juego;
	bool ok = cargar(lista);
	if (!ok) {
		cout << "ERROR" << endl;
	}
	else {
		int opcion = menu();
		while (opcion != 0) {
			menuListaSudokus(lista,juego);
			opcion = menu();

		}


	}
	system("pause");
	return 0;
}