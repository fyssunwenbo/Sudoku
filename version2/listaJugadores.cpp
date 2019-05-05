#include "listaJugadores.h"

void creaListaVacia(tListaJugadores &lista) {
	for (int i = 0; i < MAX_JUGADORES; i++) {
		lista.jugadores[i].identificador = " ";
		lista.jugadores[i].puntos = 0;
	}
	lista.cont = 0;
}

bool cargar(tListaJugadores &lista) {
	bool ok = false;
	ifstream inputFile;
	inputFile.open(BD);
	if (!inputFile.is_open()) {
		cout << "ERROR:No se ha podido abrir la lista de Jugador: " << BD << endl;
	}
	else {
		creaListaVacia(lista);
		int i = 0;
		while ((!inputFile.eof()) && i < MAX_JUGADORES) {
			inputFile >> lista.jugadores[i].identificador >> lista.jugadores[i].puntos;
			if ((lista.jugadores[i].identificador != "") && (lista.jugadores[i].puntos > 0)) {
				lista.cont++;
			}
			i++;
		}
		ok = true;
	}
	return ok;
}

void mostrar(const tListaJugadores &lista) {
	cout << "     NOMBRE        PUNTO" << endl;
	for (int i = 0; i < lista.cont; ++i) {
		cout << i + 1 << "." << left << setw(12) << lista.jugadores[i].identificador;
		cout << right << setw(8) << lista.jugadores[i].puntos << endl;
	}
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
			archivo << left << setw(16) << lista.jugadores[i].identificador;
			archivo << right << setw(2) << lista.jugadores[i].puntos << endl;
		}
		ok = true;
	}
	archivo.close();
	return ok;

	return ok;
}

void puntuarJugador(tListaJugadores &lista, int puntos) {
	string nombre; bool ok = true;
	cout << "Enter player: ";
	cin >> nombre;
	insertar(lista, nombre, puntos, ok);
	if (ok) {
		cout << "Player information has been updated" << endl;
	}
	else {
		cout << "Player information has been updated failed" << endl;
	}
}

void insertar(tListaJugadores & lista, const string &id, int puntos, bool & ok) {
	int pos; 
	bool encontrado = buscar(lista, id, pos);
	if (!encontrado) {
		if (lista.cont == MAX_JUGADORES) {
		ok = false;
		}
		else {
			for (int i = lista.cont - 1; i > pos; i--) {
			lista.jugadores[i + 1] = lista.jugadores[i];
			}
			if (lista.jugadores[pos].identificador < id) {
				lista.jugadores[pos + 1].identificador = id;
			}
			else {
				lista.jugadores[pos + 1] = lista.jugadores[pos];
				lista.jugadores[pos].identificador = id;
			}
		lista.cont++;
		}
	}
	else {
		modificarJugador(lista.jugadores[pos], puntos);
	}
}

bool buscar(const tListaJugadores &lista, string id, int &pos) {
	bool ok = false; int i = 0;
	while (ok == false && i < lista.cont) {
		if (lista.jugadores[i].identificador == id) {
			ok = true;
			pos = i;
		}
		i++;
	}
	if (ok == false) {
		int pos = -1, ini = 0, fin = lista.cont - 1, mitad;
		bool encontrado = false;
		while ((ini < fin) && encontrado != true) {
			mitad = (ini + fin) / 2;
			if (id == lista.jugadores[mitad].identificador) {
				encontrado = true;
			}
			else if (id < lista.jugadores[mitad].identificador) {
				fin = mitad - 1;
			}
			else {
				ini = mitad + 1;
			}
		}
		if (encontrado) {
			pos = mitad;
		}
		else {
			pos = ini;
		}
	}

	return ok;
}

tListaJugadores copia(const tListaJugadores &lista) {
	tListaJugadores copialista;
	copialista = lista;
	return copialista;
}

tListaJugadores ordenarPorRanking(const tListaJugadores &lista) {
	tListaJugadores ranking; tJugador t;
	ranking = copia(lista);
	for (int i = 0; i < ranking.cont-1; i++) {
		for (int j = i; j < ranking.cont-i-1; j++) {
			if (ranking.jugadores[j].puntos < ranking.jugadores[j + 1].puntos) {
				t = ranking.jugadores[j];
				ranking.jugadores[j] = ranking.jugadores[j+1];
				ranking.jugadores[j+1] = t;
			}
		}
		
	}
	for (int i = 0; i < ranking.cont-1; i++) {
		if ((menor(ranking.jugadores[i], ranking.jugadores[i + 1]))) {
			t = ranking.jugadores[i];
			ranking.jugadores[i] = ranking.jugadores[i+1];
			ranking.jugadores[i+1] = t;
		}
	}
	
	return ranking;
}