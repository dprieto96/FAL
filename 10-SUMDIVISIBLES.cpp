
#include <iostream>
#include <string>

using namespace std;


/*
DISE�O DEL ALGORITMO:
-- Describe con claridad, justificando las decisiones de dise�o realizadas,
-- el funcionamiento de tu algoritmo. Especifica claramente el cometido de cada
-- par�metro (en caso de que utilices una generalizaci�n), los casos base, y los
-- casos recursivos

ANALISIS DE LA COMPLEJIDAD:
-- Determina justificadamente el orden de complejidad del algoritmo dise�ado.
-- Escribe y resuelve las ecuaciones de recurrencia.

*/

int longitud(int n){
	if (n == 0) return 0;//Caso base
	return 1 + longitud(n / 10); //Caso recursivo
}

int suma(int n) {
	if (n == 0) return 0;//Caso base
	return (n % 10) + suma(n / 10);
}



bool sumdivisible(int n) {
	/* IMPLEMENTACION:
	   Esta funci�n ser� el punto de entrada a tu algoritmo.
	   Puedes implementar, adem�s, las funciones auxiliares
	   que consideres oportuno.
	   -- n: El n�mero cuya sumdivisibilidad debes determinar.
	   -- La funci�n deber� devolver 'true' si n es sumdivisible,
	   -- y 'false' en otro caso
	*/
	if (n < 10) return true;//Caso base, 1 digito es divisble por 1
	if (suma(n) % longitud(n) != 0)return false; //No cumple la condici�n de sumdivisble
	return sumdivisible(n/10);

}


/* CODIGO DE LECTURA Y EJECUCION DE CASOS DE PRUEBA:
   NO MODIFICAR */

int main() {
	int n;
	do {
		cin >> n;
		if (n > 0) {
			if (sumdivisible(n))
				cout << "SI" << endl;
			else
				cout << "NO" << endl;
		}
	} while (n > 0);
}

