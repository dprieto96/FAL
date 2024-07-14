#include <iostream>

using namespace std;

const int TMAX = 2000000;  // No habr� vectores de m�s de dos millones de elementos


/*

PRECONDICION DE LA FUNCION:
  ---Escribe aqu� la precondici�n de la funci�n.

  P:int a[] & int n tq 0<n<lenght(a[])

*/
int num_chupiguays(const int a[], int n);

/*
POSTCONDICION DE LA FUNCION:
  -- Escribe aqu� la postcondici�n de la funci�n. Para referirte
  -- al resultado puedes usar la pseudovariable 'resul'

  Q:#resul:0<i<n(sumatorio:a[]desde 0 a i || a[i]%sum(a[i-1]=0) )


 */


 /*
 DISE�O DEL ALGORITMO:
 -- Especifica cada paso del dise�o en cada apartado indicado

 Paso 1. Variables
	int contadorChupiGuay  -> Lleva la cuenta de los elementos que son chupiguays del array
	int sumaPredecesores -> A medida que se recorre el bucle, va almacenando la suma de estos

 Paso 2. Invariante
	i=1: i<n,i++

 Paso 3. Inicializaci�n
	Contadores y sumas a 0.
	Si el array comienza por 0, se suma uno ya que el enunciado dice que lo que precede es 0.
	Si no comienza por 0, el valor del sumatorio sera la primera posición

 Paso 4. Condici�n del bucle, y c�digo tras el bucle
	Condición que recorra el vector desde la posición 1
	Distinguir el caso especial del 0, ya que solo es múltiplo de si mismo

 Paso 5. Cuerpo del bucle
	Condicionantes


 Paso 6. Justificaci�n de que el algoritmo siempre termina
	Termina al llegar a n-1, y en cada iteración este va aumentado


 Paso 7. Complejidad
	O(n) -> Unicamente recorre el array una vez

 */


int num_chupiguays(const int a[], int n) {
	/* IMPLEMENTACION: COMPLETA EL CUERPO DE LA FUNCION
	   CON EL CODIGO QUE IMPLEMENTA EL ALGORITMO */
	int contadorChupiGuay = 0;
	int sumaPredecesores = 0;
	
	if (a[0] != 0)sumaPredecesores = a[0];
	else contadorChupiGuay++;
	for (int i = 1; i < n;i++) {

		if (a[i] == 0 &&sumaPredecesores==0) {
			contadorChupiGuay++;
		}
		else if (sumaPredecesores == 0 && a[i] != 0) sumaPredecesores = a[i];
		else {
		 if (int(a[i] % sumaPredecesores) == 0 ) contadorChupiGuay++;
		 sumaPredecesores += a[i];
		}
	}
	return contadorChupiGuay;
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
			cout << num_chupiguays(a, n) << endl;
		}
	} while (n != -1);
}