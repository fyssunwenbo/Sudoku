#include "jugador.h"

string toString(tJugador jugador) {
	stringstream ss1;
	stringstream ss2;
	ss1 << left << setw(16) << jugador.identificador;
	ss2 << right << setw(2) << to_string(jugador.puntos);
	return ss1.str() + ss2.str();
}

void modificarJugador(tJugador &jugador, int puntos) {
	jugador.puntos += puntos;
}

bool operator<(const tJugador &opIzq, const tJugador &opDer) {
	if (opIzq.identificador < opDer.identificador) {
		return true;
	}
	return false;
}

bool menor(const tJugador &j1, const tJugador &j2) {
	bool ok = false;
	if ((j1.puntos < j2.puntos)||((j1.puntos==j2.puntos)&&(j2<j1))) {
		ok = true;
	}
	else {
		ok = false;
	}
	return ok;
}
