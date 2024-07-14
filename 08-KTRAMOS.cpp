
#include <iostream>

using namespace std;


/*

PRECONDICION DE LA FUNCION:
  ---Escribe aqu� la precondici�n de la funci�n.

*/

int tramo_mas_corto(bool a[], int n, int k);

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



int tramo_mas_corto(bool a[], int n, int k) {
	// A IMPLEMENTAR	
	int i = 0;
	int j = 0;
	int tamMaximo = 1000;
	int tam = 0;
	bool ok = false;

	while (j<n) {
		if (a[j] == true) {
			tam++;
			if (tam == k) {
				while (a[i] == false) {
					i++;
				}
					if (j - i +1<= tamMaximo) {
						tamMaximo = j - i + 1;
						ok = true;
					}
					i++;
					tam--;
				}
			}
			j++;
	}
	if (ok == false) tamMaximo = n + 1;
	return tamMaximo;
}

/* CODIGO DE LECTURA Y EJECUCION DE CASOS DE PRUEBA:
   NO MODIFICAR */


void lee_caso(int& n, bool a[], int& k) {
	cin >> n;
	if (n != -1) {
		for (int i = 0; i < n; i++) {
			int elem;
			cin >> elem;
			a[i] = bool(elem);
		}
		cin >> k;
	}
}

const int MAX_TAM = 100;
int main() {
	int n;
	bool a[MAX_TAM];
	int k;
	do {
		lee_caso(n, a, k);
		if (n != -1) {
			cout << tramo_mas_corto(a, n, k) << endl;
		}
	} while (n != -1);
}

