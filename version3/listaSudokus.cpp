#include "listaSudokus.h"


void creaListaVacia(tListaSudokus &lista) {
	for (int i = 0; i < MAX_SUDOKUS; i++) {
		lista.array[i].fichero = " ";
		lista.array[i].nivel = 0;
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
		creaListaVacia(lista);
		int i = 0;
		while ((!inputFile.eof())&&i<MAX_SUDOKUS) {
				inputFile >> lista.array[i].fichero >> lista.array[i].nivel;
				if ((lista.array[i].fichero != "") && (lista.array[i].nivel > 0)) {
					lista.cont++;
				}
				i++;	
		}
		ok = true;
	}
	inputFile.close();
	return ok;
}

void mostrar(const tListaSudokus &lista) {
	cout << "-----------------------------------------------" << endl;
	cout << "     NOMBRE        NIVEL" << endl;
	for (int i = 0; i < lista.cont; ++i) {
		cout << i + 1 << "." << left<<setw(12)<<lista.array[i].fichero;
		cout<<right << setw(8) << lista.array[i].nivel << endl;
	}
	cout << "-----------------------------------------------" << endl;
}

int menuListaSudokus(const tListaSudokus &lista) {
	int op; int points;
	mostrar(lista);
	cout << "Choose a Sudoku Game: " << endl;
	cin >> op;
	while (op > lista.cont||op<0) {
		cout << "Choose a Sudoku Game: " << endl;
		cin >> op;
	}
	if (op <= lista.cont ) {
		system("cls");
		points=jugarUnSudoku(lista.array[op-1]);
		
	}

	return points;
}

bool buscarFichero(const tListaSudokus &lista, string nombreFich) {
	bool ok = false; int i = 0;
	while (ok==false && i<lista.cont) {
		if (lista.array[i].fichero == nombreFich) {
			ok = true;
		}
		i++;
	}
	return ok;
}

int buscarPos(const tListaSudokus &lista, const tSudoku &sudoku) {
	int pos = -1, ini = 0, fin = lista.cont - 1, mitad;
	bool encontrado = false;
	while ((ini < fin) && encontrado != true) {
		mitad = (ini + fin) / 2;
		if (sudoku.nivel == lista.array[mitad].nivel) {
			encontrado = true;
		}
		else if (sudoku < lista.array[mitad]) {
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
	return pos;
}

bool operator<(const tSudoku &opIzq, const tSudoku &opDer) {
	if (opIzq.nivel < opDer.nivel) {
		return true;
	}
	return false;
}

void insertar(tListaSudokus &lista, const tSudoku &sudoku, bool &lleno, bool &encontrado) {
	int pos;
	if (lista.cont == MAX_SUDOKUS) {
		lleno = true;
	}
	encontrado = buscarFichero(lista, sudoku.fichero);
	if (!encontrado && !lleno) {
		pos = buscarPos(lista, sudoku);
		for (int i = lista.cont-1; i >pos ; i--) {			
			lista.array[i + 1] = lista.array[i];
		}	
		if ((lista.array[pos].nivel < sudoku.nivel)||((lista.array[pos].fichero<sudoku.fichero)&&lista.array[pos].nivel==sudoku.nivel)) {
			lista.array[pos + 1] = sudoku;
		}
		else {
			lista.array[pos+1] = lista.array[pos];
			lista.array[pos] = sudoku;
		}
		lista.cont++;
	}
}

bool registrarSudoku(tListaSudokus &lista){
	bool lleno=false,repetido=false;
	tSudoku sudoku;
	mostrar(lista);
	cout << "Nombre de archivo: ";
	cin >> sudoku.fichero;
	cout << "Nivel de sudoku: ";
	cin >> sudoku.nivel;
	
	insertar(lista, sudoku, lleno, repetido);
	if (lleno == true) {
		cout << "La lista est¨¢ llena." << endl;
	}
	if (repetido == true) {
		cout << "El sudoku ya est¨¢ registrado." << endl;
	}
	return  (!lleno) && (!repetido);
}

bool guardar(const tListaSudokus &lista) {
	ofstream archivo;
	bool ok = false;
	archivo.open("listaSudokus.txt");
	if (!archivo.is_open()) {
		cout << "ERROR:No puede guardar el archivo: " << endl;
	}
	else {
		cout << "Now the list of file: " << endl;
		mostrar(lista);
		for (int i = 0; i < lista.cont; i++) {
			archivo <<left<<setw(11)<< lista.array[i].fichero<<" ";
			archivo<<right<<setw(1)<< lista.array[i].nivel << endl;
		}
		ok = true;
	}
	archivo.close();
	return ok;
}