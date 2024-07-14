/*
NOMBRE Y APELLIDOS:

*/

#include <iostream>
using namespace std;


/*

PRECONDICION DE LA FUNCION:
---Escribe aqu� la precondici�n de la funci�n.


*/

bool /* resul */ hay_c_tramo(int a[], int n, int c);

/*
	   POSTCONDICION DE LA FUNCION:
	   ---Escribe aqu� la poscondici�n de la funci�n. Para refirte
	   ---al valor devuelto por la funci�n, utiliza la pseudo-variable
	   ---'resul'
	(1) Definiciones auxiliares (si procede):


	(2) Postcondici�n



 */



 /* DISE�O DEL ALGORITMO:
	 --- Detalla aqu� el proceso seguido para dise�ar el
	 --- algoritmo

	 PASO 1. Variables adicionales (aparte de los par�metros y el resultado)

	 PASO 2. Invariante
		(2.1) Definiciones auxiliares (si procede)



		(2.2) Invariante


	 PASO 3. C�digo de inicializaci�n, justificando que, tras
			 dicho c�digo, se cumple el invariante


	 PASO 4. Condici�n del bucle, c�digo tras el bucle (si procede),
			 y justificaci�n de que, una vez finalizado el algoritmo,
			 se cumple la postcondici�n


	 PASO 5. Dise�o del cuerpo del bucle, justificando que dicho c�digo
			 preserva el invariante


	 PASO 6: Expresi�n de cota y justificaci�n de que el algoritmo siempre
			 termina


	 PASO 7: Determinaci�n justificada de la complejidad del algoritmo

 */

bool /* resul */ hay_c_tramo(int a[], int n, int c) {
	/* IMPLEMENTACION */
	bool ok = false;
	int i = 0, j = 1,sumatorio=a[0];

	
	if (a[0] == c)return true;
	if (n == 1)return false;
	sumatorio = a[0] + a[1];
	
	while (i<n) {
		
		if (sumatorio == c)return true;//He encontrado tramo

		if (j == n - 1) {
			if (c > sumatorio)return false;
			else {
				sumatorio -= a[i];
				i++;
			}
		}

		if (i == j && j < n) {
			j++;
			sumatorio += a[j];
		}

		else if (sumatorio > c) {
			sumatorio -= a[i];
			i++;
		}
		
		else if (sumatorio < c) {
			j++;
			sumatorio += a[j];
		}

		
		
	}

	return ok;
}


/**** PROGRAMA DE PRUEBA: NO MODIFICAR ****/


const static int MAX_ELEMS = 1000000;
bool ejecuta_caso() {
	static int a[MAX_ELEMS];
	int n;
	cin >> n;
	if (n == -1) return false;
	else {
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		int c;
		cin >> c;
		if (hay_c_tramo(a, n, c)) {
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
}
