#include "jugador.h"

string toString(tJugador jugador) {
	return jugador.identificador + " " + to_string(jugador.puntos);
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
