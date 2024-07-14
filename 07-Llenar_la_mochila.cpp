#include <iostream>

using namespace std;

const int TMAX = 2000000;  // No habr� vectores de m�s de dos millones de elementos


/*

PRECONDICION DE LA FUNCION:
  ---Escribe aqu� la precondici�n de la funci�n.

*/

int llena_mochila(const int a[], int n, int k);

/*
POSTCONDICION DE LA FUNCION:
  -- Escribe aqu� la postcondici�n de la funci�n. Para referirte
  -- al resultado puedes usar la pseudovariable 'resul'



 */


 /*
 DISE�O DEL ALGORITMO:

 Paso 1. Variables


 Paso 2. Invariante


 Paso 3. Inicializaci�n

 Paso 4. Condici�n del bucle, y c�digo tras el bucle.


 Paso 5. Cuerpo del bucle

 Paso 6. Justificaci�n de que el algoritmo siempre termina.


 Paso 7. Complejidad:


 */

int llena_mochila(const int a[], int n, int k) {
	// A IMPLEMENTAR
	int i = 0;
	int j = 0;
	int posibleCarga = 0;
	int cargaMax = 0;

	while (j < n) {
		posibleCarga += a[j];
		while (posibleCarga > k && (j - i != 0)) {
			posibleCarga = posibleCarga - a[i];
			i++;
		}
		if (posibleCarga <= k) {
			if (cargaMax < (j - i)) {
				cargaMax = j - i ;
			}
		}
		j++;
	}
	return cargaMax;
}


/* CODIGO PARA LEER Y EJECUTAR LOS CASOS DE PRUEBA */

void lee_vector(int a[], int& n) {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
}

int main() {
	static int a[TMAX];
	int n;
	do {
		lee_vector(a, n);
		if (n >= 0) {
			int k;
			cin >> k;
			cout << llena_mochila(a, n, k) << endl;
		}
	} while (n != -1);
}