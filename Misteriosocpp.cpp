#include <iostream>

using namespace std;

const int TMAX = 1000000;  // No habr� vectores de m�s de un mill�n de elementos


/*

PRECONDICION DE LA FUNCION:

P={ 0<=n<tam(a) ^ (a[i] < a[a+1]: i<=0<n -1) }

*/

int misterio(const int a[], int n);

// Q ={ resul = min i: 0<=i<n ^((# j: 0<=j<n: a[i]=a[j]) = (max j: 0<=j<n: (# k: 0<=k<n: a[j]=a[k]))): a[i] }
//Primer elemento que mas veces se repite

int misterio(const int a[], int n) {
	/* IMPLEMENTACION: COMPLETA EL CUERPO DE LA FUNCION
	   CON EL CODIGO QUE IMPLEMENTA EL ALGORITMO */
	int elementoActual = a[0];
	int elementoMasRepetido = a[0];
	int contadorMaxRepetido = 1;
	int cont = 1;

	for (int i = 1; i < n; i++) {
		if (elementoActual==a[i]) {
			cont++;
		}
		else {
			if (cont > contadorMaxRepetido) {
				contadorMaxRepetido = cont;
				elementoMasRepetido = elementoActual;
			}
			cont = 1;
			elementoActual = a[i];
		}
	}

	if (cont > contadorMaxRepetido) {
		elementoMasRepetido = elementoActual;
	}


	return elementoMasRepetido;
}

/* COMPLEJIDAD:
   -- Determina justificadamente el orden de complejidad en el peor caso
   -- de este algoritmo, indicando claramente cu�l es el tama�o del problema

   O(n) -> En el peor de los casos recorre una vez el vector 

*/


/* CODIGO PARA LEER Y EJECUTAR LOS CASOS DE PRUEBA. NO MODIFICAR */

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
			cout << misterio(a, n) << endl;
		}
	} while (n != -1);
}