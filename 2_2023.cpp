/*
NOMBRE Y APELLIDOS:

*/

#include <iostream>
using namespace std;


/*
Nota: NO es necesario que especifiques el algoritmo, ni las
funciones auxiliares utilizadas. Pero, en caso de utilizar
una generalizaci�n, s� debes describir sus par�metros,
su resultado, y el pr�posito de los mismos

(1) SI UTILIZAS UNA GENERALIZACION, DETALLA AQU� SUS PAR�METROS,
	SU RESULTADO, Y EL PROP�SITO DE LOS MISMOS


(2) DISE�O (CASOS)


(3) JUSTIFICACION DE LA TERMINACION DEL ALGORITMO


(4) IMPLEMENTACION POR INMERSION DEL ALGORITMO, SI PROCEDE


(5) DETERMINACION DEL COSTE DEL ALGORITMO EN EL PEOR CASO


*/

/**** PROGRAMA DE PRUEBA: NO MODIFICAR ****/

int numero_elementos(int a[],int n, int ini,int fin) {
	
	if (a[ini] == a[fin]) {
		return 1;
	}
	else {
		int mitad = (ini + fin) / 2;
		
		int izq= numero_elementos(a,n,ini,mitad);
		int der= numero_elementos(a, n, mitad + 1,fin);

		if (a[mitad] == a[mitad + 1]) {
			return izq + der - 1;
		}
		else {
			return izq + der;
		}
		
	}
	
}

bool hay_nifunifa(int a[], int n) {
	// A IMPLEMENTAR

	if (numero_elementos(a, n, 0, n - 1) > 2)return true;
	else return false;

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
		if (hay_nifunifa(a, n)) {
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
