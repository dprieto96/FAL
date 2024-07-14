
#include <iostream>
using namespace std;

const int MAX_OBJS = 20;

// Lista con los objetos a portar 
typedef struct {
	int tamanios[MAX_OBJS];  // Array en cuyas primeras posiciones se guardan
							// los tama�os de los objetos
	int n_objetos;         // Numero de objetos
} tObjetos;

typedef struct {
	int objs[MAX_OBJS];
	int capacidad;
	int n;
} tMochila;


/*

(1) En caso de utilizar una generalizaci�n, indicar su par�metros, y explicar para que
sirven cada uno de ellos

(2) �C�mo son las soluciones parciales de este problema?

(3) �Cu�ndo una soluci�n parcial es viable?

(4) �Cu�ndo una soluci�n parcial es una soluci�n final al problema?

(5) Dada una soluci�n parcial, �c�mo se generan las siguientes soluciones
parciales viables?

(6) An�lisis de casos

(6.1) Caso(s) base


(6.2) Caso(s) recursivos

(7) En caso de utilizar una generalizaci�n, explicar c�mo se define el algoritmo final
a partir de la misma, por inmersi�n.



*/

void solve(const tObjetos& objetos, int capacidad_caja, int objetoActual, tMochila datos, int& minCajas) {
	if (objetoActual == objetos.n_objetos) {
		if (datos.n < minCajas) {
			minCajas = datos.n;
		}
	}
	else if (minCajas > datos.n) {
		for (int objeto = 0; objeto < datos.n; objeto++) {
			int capacidadNueva = datos.objs[objeto] + objetos.tamanios[objetoActual];
			if (capacidadNueva <= capacidad_caja) {
				datos.objs[objeto] += objetos.tamanios[objetoActual];
				solve(objetos, capacidad_caja, objetoActual + 1, datos, minCajas);
				datos.objs[objeto] -= objetos.tamanios[objetoActual];
			}
		}
		datos.n++;
		datos.objs[datos.n - 1] += objetos.tamanios[objetoActual];
		solve(objetos, capacidad_caja, objetoActual + 1, datos, minCajas);
		datos.objs[datos.n - 1] -= objetos.tamanios[objetoActual];
		datos.n--;
	}
}

int min_numero_de_cajas(const tObjetos& objetos, int capacidad_caja) {
	tMochila datos;
	int minCajas = objetos.n_objetos;
	datos.capacidad = capacidad_caja;
	datos.n = 0;
	for (int i = 0; i < objetos.n_objetos; i++) {
		datos.objs[i] = 0;
	}
	solve(objetos, capacidad_caja, 0, datos, minCajas);
	return minCajas;
}
/* CODIGO PARA LEER Y EJECUTAR LOS CASOS DE PRUEBA */

bool ejecuta_caso() {
	int capacidad;
	cin >> capacidad;
	if (capacidad != -1) {
		tObjetos objetos;
		cin >> objetos.n_objetos;
		for (int i = 0; i < objetos.n_objetos; i++) {
			cin >> objetos.tamanios[i];
		}
		cout << min_numero_de_cajas(objetos, capacidad) << endl;
		return true;
	}
	else {
		return false;
	}
}

int main() {
	while (ejecuta_caso());
}