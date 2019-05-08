#include "listaJugadores.h"

void ampliar(tListaJugadores &lista) {
	tListaJugadores aux = lista;
	lista.capacidad *= 2;
	lista.jugadores = new tJugadorPtr[lista.capacidad];
	for (int i = 0; i < aux.cont; i++) {
		lista.jugadores[i] = aux.jugadores[i];
	}
	delete[] aux.jugadores;
}

void borrarListaJugadores(tListaJugadores &lista) {	
	borrarJugadores(lista);
	liberarArray(lista);
}

void borrarJugadores(tListaJugadores &lista) {
	for (int i = 0; i < lista.cont; i++) {
		delete lista.jugadores[i];
	}
}

void liberarArray(tListaJugadores &lista) {
	delete[] lista.jugadores;
	lista.jugadores = nullptr;
	lista.cont = 0;
}

void creaListaVacia(tListaJugadores &lista) {
	lista.capacidad = JUGADORES;
	lista.jugadores = new tJugadorPtr[lista.capacidad];
	lista.cont = 0;
}

bool cargar(tListaJugadores &lista) {
	bool ok = false; string name; int puntos;
	tJugador jugador;
	ifstream inputFile;
	inputFile.open(BD);
	if (!inputFile.is_open()) {
		cout << "ERROR:No se ha podido abrir la lista de Jugador: " << BD << endl;
	}
	else {
		creaListaVacia(lista);
		int i = 0;
		while ((!inputFile.eof())) {
			if (lista.cont == lista.capacidad) {
				ampliar(lista);
			}
			inputFile >> name >> puntos;
			if (!inputFile.fail()) {
				jugador.identificador = name;
				jugador.puntos = puntos;
				lista.jugadores[lista.cont] = new tJugador(jugador);
				lista.cont++;
			}
		}
		ok = true;
	}
	inputFile.close();
	return ok;
}

void mostrar(const tListaJugadores &lista) {
	cout << "-----------------------------------------------" << endl;
	cout << " NOMBRE        PUNTO" << endl;
	for (int i = 0; i < lista.cont; ++i) {
		cout << i + 1 << "." << toString(*lista.jugadores[i]) << endl;
	}
	cout << "-----------------------------------------------" << endl;
}

bool guardar(const tListaJugadores &lista) {
	ofstream archivo;
	bool ok = false;
	archivo.open("listaJugadores.txt");
	if (!archivo.is_open()) {
		cout << "ERROR:No puede guardar el archivo: " << endl;
	}
	else {
		for (int i = 0; i < lista.cont; i++) {
			archivo << left << setw(16) << lista.jugadores[i]->identificador;
			archivo << right << setw(2) << lista.jugadores[i]->puntos << endl;
		}
		ok = true;
	}
	archivo.close();
	return ok;

}

void puntuarJugador(tListaJugadores &lista, int puntos) {
	string nombre; bool ok = true;
	cout << "Enter player: ";
	cin >> nombre;
	cout << endl;
	system("cls");
	insertar(lista, nombre, puntos, ok);
	if (ok) {
		cout << "Player information has been updated." << endl;
		cout << "-----------------------------------------------" << endl;
	}
	else {
		cout << "Player information has been updated failed." << endl;
		cout << "-----------------------------------------------" << endl;
	}
}

void insertar(tListaJugadores & lista, const string &id, int puntos, bool & ok) {
	int pos; 
	bool encontrado = buscar(lista, id, pos,0,lista.cont-1);
	if (!encontrado) {
		if (lista.cont == lista.capacidad) {
		ampliar(lista);
		}
		tJugador jugador;
		
		for (int i = lista.cont - 1; i >= pos; i--) {
			lista.jugadores[i + 1] = lista.jugadores[i];
		}

		jugador.identificador = id;
		jugador.puntos = puntos;		
		lista.jugadores[pos] = new tJugador(jugador);

		lista.cont++;
		
	}
	else {
		modificarJugador(*lista.jugadores[pos], puntos);
		cout << "--------------------Sudoku---------------------" << endl;
		cout << "NOMBRE        PUNTO" << endl;
		cout << toString(*lista.jugadores[pos]) << endl;
	}
	
}

bool buscar(const tListaJugadores &lista, string id, int &pos,int ini,int fin) {//recusiva
	bool encontrado = false;

	if (ini <= fin) {
		int mitad = (ini + fin) / 2;
		if (id == lista.jugadores[mitad]->identificador) {
			pos = mitad;
			encontrado = true;
		}
		else if (id < lista.jugadores[mitad]->identificador) {
			encontrado = buscar(lista, id, pos , ini, mitad - 1);
		}
		else {
			encontrado = buscar(lista, id, pos, mitad + 1, fin);
		}
	}
	else {
		encontrado = false;
		pos = ini;
	}
	
	return encontrado;
}

tListaJugadores copia(const tListaJugadores &lista) {
	tListaJugadores copialista;
	copialista.jugadores = new tJugadorPtr[lista.cont];
	copialista.capacidad = lista.capacidad;
	copialista.cont = lista.cont;
	for (int i = 0; i < lista.cont; i++) {
		copialista.jugadores[i] = lista.jugadores[i];
	}
	return copialista;
}

tListaJugadores ordenarPorRanking(const tListaJugadores &lista) {
	tListaJugadores ranking; tJugadorPtr t;
	ranking = copia(lista);
	for (int i = 0; i < ranking.cont-1; i++) {
		for (int j = 0; j < ranking.cont-i-1; j++) {
			if (ranking.jugadores[j]->puntos < ranking.jugadores[j + 1]->puntos) {
				t = ranking.jugadores[j];
				ranking.jugadores[j] = ranking.jugadores[j+1];
				ranking.jugadores[j+1] = t;
			}
		}
		
	}
	for (int i = 0; i < ranking.cont-1; i++) {
		if ((menor(*ranking.jugadores[i], *ranking.jugadores[i + 1]))) {
			t = ranking.jugadores[i];
			ranking.jugadores[i] = ranking.jugadores[i+1];
			ranking.jugadores[i+1] = t;
		}
	}
	
	return ranking;
}
