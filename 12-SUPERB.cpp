/*
NOMBRE Y APELLIDOS:

IMPORTANTE: Si no se a�ade el nombre y apellidos,
el ejercicio no se corregir� (puntuar� como 0).

*/

#include <iostream>
using namespace std;


/*
IMPORTANTE: Para superar este ejercicio es necesario desarrollar
correctamente los distintos pasos del dise�o del algoritmo. No
se tendr� en cuenta la codificaci�n del algoritmo, a menos que
est� acompa�ada del dise�o sistem�tico del mismo.
*/


/*
(1) En caso de utilizar una generalizacion,
determinaci�n de los par�metros de la generalizaci�n.
Determina los par�metros de la generalizaci�n. Para cada par�metro
indica: (i) su tipo; (ii) su nombre; (iii) si es un par�metro
de entrada, de salida, o de entrada / salida; (iv) su prop�sito,
descrito de manera clara y concisa.


(2) An�lisis de casos:

(2.1) Casos base


(2.2) Casos recursivos

(3) En caso de utilizar una generalizacion, definici�n por inmersi�n
del algoritmo. Describe de manera clara y concisa c�mo se lleva a
cabo el algoritmo, en qu� punto o puntos se invoca a la generalizaci�n,
con qu� par�metros reales, y c�mo se genera el resultado
a partir de los devueltos por la generalizaci�n.



(4)Determina justificadamente la complejidad del algoritmo

(4.1) Determinaci�n de las ecuaciones de recurrencia para la generalizaci�n

(4.2) Resoluci�n utilizando los patrones vistos en clase

(4.3) Determinaci�n justificada de la complejidad del algoritmo final.



*/


bool es_superb(int v[], int n) {
	// A IMPLEMENTAR: Devolver true si el vector v[n] es superb,
	// y false si no lo es.
	int elementoCentral = (n-1 )/ 2; // +1 porque empiezo en 0
	
	if (n < 3)return true; //CASO BASE
	else {
		int maxAnterior = v[0];
		int minSigueinte = v[elementoCentral + 1];
		for (int i = 0; i < elementoCentral; ++i) {
			if (v[i] > maxAnterior) {
				maxAnterior = v[i];
			}
		}

		// Encontrar el mínimo en el subvector que sucede al elemento central
		for (int i = elementoCentral + 1; i < n; ++i) {
			if (v[i] < minSigueinte) {
				minSigueinte = v[i];
			}
		}

		if (v[elementoCentral] != abs(maxAnterior - minSigueinte)) {
			return false;
		}
	}

	if (es_superb(v, elementoCentral) && es_superb(v + elementoCentral + 1, n - elementoCentral - 1)) return true;

	return false;

}


/************************************************************/
// Programa de prueba: NO MODIFICAR. Aquellas soluciones que
// modifiquen el c�digo que sigue no se corregir�n (puntuar�n 0).


const static int MAX_ELEMENTS = 10000;

bool ejecuta_caso() {
	int n;
	cin >> n;
	if (n == -1) return false;
	else {
		int v[MAX_ELEMENTS];
		for (int i = 0; i < n; i++) {
			cin >> v[i];
		}
		if (es_superb(v, n)) {
			cout << "SUPERB" << endl;;
		}
		else {
			cout << "NO SUPERB" << endl;
		}
		return true;
	}
}


int main() {
	while (ejecuta_caso());
	return 0;
}