/*
NOMBRES Y APELLIDOS DE LOS MIEMBROS DEL GRUPO QUE HAN REALIZADO LA PRACTICA:
Daniel Prieto Remacha
SIN COMPAÑERO

Si alguno de los miembros del grupo no ha realizado
la pr�ctica, indicarlo aqu�, junto con el motivo:

No he tenido contacto con el otro compañero desde la segunda práctica.

*/

#include<iostream>

using namespace std;
const int MAX_TAM2 = 1000000;

/* Representacion de los personajes */
typedef enum { PRINCESA, CABALLERO, DRAGON } tPersonaje;

typedef struct {
	bool es_divertido;
	int numeroPrincesas;
	int numeroCaballeros;
	int numeroDragones;
}tInfoPersonajes;

/*
(1) GENERALIZACION (EN CASO DE QUE PROCEDA): Entradas y salidas
ENTRADAS:
tPersonaje personajes[]
int n -> De aqui se sacará incio y fin

SALIDA:
tInfoPersonajes.es_divertido -> bool de salida

(2) DISE�O

CASO BASE: //Hay un personaje o ninguno
	if (inicio > fin) return { true,0,0,0 }; //CASO BASE

	if (inicio == fin) {
		int esPrincesa = personajes[inicio] == PRINCESA;
		int esCaballero = personajes[inicio] == CABALLERO;
		int esDragon = personajes[inicio] == DRAGON;
		return { true, esPrincesa, esCaballero, esDragon };
	}

CASO RECURSIVO: //Voy dividiendo el problema en mitades para consultar si es Divertido

	int elemento_central = (inicio + fin) / 2;
	tInfoPersonajes mitad_inferior = comprobacion_es_divertida(personajes, inicio, elemento_central - 1);
	tInfoPersonajes mitad_superior = comprobacion_es_divertida(personajes, elemento_central + 1, fin);
	bool esDivertido = mitad_inferior.es_divertido && mitad_superior.es_divertido;
	if (mitad_inferior.numeroDragones > mitad_superior.numeroCaballeros) {
		esDivertido &= (personajes[elemento_central] == CABALLERO);
	}
	else if (mitad_inferior.numeroDragones == mitad_superior.numeroCaballeros) {
		esDivertido &= (personajes[elemento_central] == PRINCESA);
	}
	else {
		if (mitad_inferior.numeroPrincesas + mitad_superior.numeroPrincesas > 0) {
			esDivertido &= (personajes[elemento_central] == DRAGON);
		}
		else {
			esDivertido &= (personajes[elemento_central] == PRINCESA);
		}
	}

	int numPrincesas = mitad_inferior.numeroPrincesas + mitad_superior.numeroPrincesas + (personajes[elemento_central] == PRINCESA);
	int numCaballeros = mitad_inferior.numeroCaballeros + mitad_superior.numeroCaballeros + (personajes[elemento_central] == CABALLERO);
	int numDragones = mitad_inferior.numeroDragones + mitad_superior.numeroDragones + (personajes[elemento_central] == DRAGON);

	return { esDivertido, numPrincesas, numCaballeros, numDragones };


(3) TERMINACI�N:
	inicio > fin o fin = inicio significa que he recorrido ya todos los elementos

(4) IMPLEMENTACION POR INMERSION DEL ALGORITMO, SI PROCEDE:

(5) DETERMINACION DEL COSTE DEL ALGORITMO EN EL PEOR CASO:
	O(n) -> recorro una única vez todos los elementos.
	T(0) = C0, (inicio >= fin)
	T(n) = C1 + 2T(n/2)
*/

/*
	PRINCESA=0
	CABALLERO=1
	DRAGON=2
*/

tInfoPersonajes comprobacion_es_divertida(tPersonaje personajes[], int inicio, int fin) {
	
	if (inicio > fin) return { true,0,0,0 }; //CASO BASE

	if (inicio == fin) { 
		int esPrincesa = personajes[inicio] == PRINCESA;
		int esCaballero = personajes[inicio] == CABALLERO;
		int esDragon = personajes[inicio] == DRAGON;
		return { true, esPrincesa, esCaballero, esDragon };
	}

	int elemento_central = (inicio + fin) / 2;
	tInfoPersonajes mitad_inferior = comprobacion_es_divertida(personajes, inicio, elemento_central - 1);
	tInfoPersonajes mitad_superior = comprobacion_es_divertida(personajes, elemento_central + 1, fin);
	bool esDivertido = mitad_inferior.es_divertido && mitad_superior.es_divertido;
	if (mitad_inferior.numeroDragones > mitad_superior.numeroCaballeros) {
		esDivertido &= (personajes[elemento_central] == CABALLERO);
	}
	else if (mitad_inferior.numeroDragones == mitad_superior.numeroCaballeros) {
		esDivertido &= (personajes[elemento_central] == PRINCESA);
	}
	else {
		if (mitad_inferior.numeroPrincesas + mitad_superior.numeroPrincesas > 0) {
			esDivertido &= (personajes[elemento_central] == DRAGON);
		}
		else {
			esDivertido &= (personajes[elemento_central] == PRINCESA);
		}
	}

	int numPrincesas = mitad_inferior.numeroPrincesas + mitad_superior.numeroPrincesas + (personajes[elemento_central] == PRINCESA);
	int numCaballeros = mitad_inferior.numeroCaballeros + mitad_superior.numeroCaballeros + (personajes[elemento_central] == CABALLERO);
	int numDragones = mitad_inferior.numeroDragones + mitad_superior.numeroDragones + (personajes[elemento_central] == DRAGON);

	return { esDivertido, numPrincesas, numCaballeros, numDragones };

}


bool es_divertida(tPersonaje personajes[], int n) {
	// A IMPLEMENTAR
	return comprobacion_es_divertida(personajes, 0, n - 1).es_divertido;
}

// NO MODIFICAR NADA A PARTIR DE AQUI

const int MAX_TAM = 1000000;
const int REPS = 500;

bool ejecuta_caso() {
	int n;
	cin >> n;
	if (n == -1) {
		return false;
	}
	else {
		static tPersonaje personajes[MAX_TAM];
		for (int i = 0; i < n; i++) {
			int p;
			cin >> p;
			personajes[i] = tPersonaje(p);
		}

		if (n == MAX_TAM) {
			for (int i = 0; i < REPS; i++) {
				es_divertida(personajes, n);
			}
		}
		if (es_divertida(personajes, n)) {
			cout << "SI" << endl;
		}
		else {
			cout << "NO" << endl;
		}
		return true;
	}
}

int main() {
	while (ejecuta_caso());
	return 0;
}