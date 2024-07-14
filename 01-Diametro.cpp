/*
N� GRUPO:B21
NOMBRES Y APELLIDOS: Danie Prieto Remacha


*/


#include <iostream>
#include <cmath>

using namespace std;


//n siempre ser� positivo (es decir, pod�is asumir n >= 1)
int diametro(int a[], int n) {//No es necesario comparar 2 a dos como dice el enunciado
	//debemos obtener el mayor y menor de la lista, y luego compararlos.

	if (n <= 1) {//Caso especial de 1 elemento
		return 0;
	}

	//Asignamos los valores max y min a la primera variable
	int minVal = a[0];
	int maxVal = a[0];

	for (int i = 1; i < n; i++) {//Saco el mayor y menor valor, ya que todos los elementos se comparan entre sí
		if (a[i] < minVal)minVal = a[i];
		if (a[i] > maxVal)maxVal = a[i];
	}

	return maxVal - minVal;
}


/* CODIGO PARA LEER Y EJECUTAR LOS CASOS DE PRUEBA */

const int TMAX = 1000000;  // No se podr�n leer vectores de m�s de un mill�n de elementos

bool ejecuta_caso() {
	static int a[TMAX];
	int n;
	cin >> n;
	if (n == -1 || n > TMAX) {
		return false;
	}
	else {
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		cout << diametro(a, n) << endl;
		return true;
	}
}

int main() {
	while (ejecuta_caso());
}