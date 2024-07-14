/*
NOMBRES Y APELLIDOS DE LOS MIEMBROS DEL GRUPO QUE HAN REALIZADO LA PRACTICA:
DANIEL PRIETO REMAHCA

Si alguno de los miembros del grupo no ha realizado
la pr�ctica, indicarlo aqu�, junto con el motivo:
SOLO, NO TENGO CONTACTO CON MI COMPAÑERO.

*/

#include <iostream>
using namespace std;



/*
(1) �C�mo son las soluciones parciales viables de este problema?
	if (minimo != v[i] && suma + v[i] <= umbral)
	El mínimo no se ha repetido ni excedido el umbral

(2) �Cu�ndo una soluci�n es final?
	suma + v[i] <= umbral
	Cuando he considerado todos los elementos.

(3) Dada una soluci�n viable, �c�mo se generan nuevas soluciones viables a partir de ella?
	Dada una solución viable, se aumenta el contador y se añade un nuevo elemento de la lista con el for

(4) �C�mo se representar�n las soluciones en este problema? Describe los distintos elementos
	de informaci�n que las componen, indicando si se representan como par�metros de entrada,
	de entrada/salida (estado global), si se representan impl�citamente...
	salida -> int minimalista : devuelve un contador con el numero de minimalistas
	entrada ->(int v[],int n, int umbral, int suma, int minimo, int &contador)
		v[] :array donde esta contenido el conjunto
		n: elementos del array
		umbral: valor umbral
		suma: suma actual
		minimo: minimo actual
		&contador: contador como referencia para que pueda ir modificando el valor

(5) �Qu� marcadores utiliza el algoritmo? Describe claramente su prop�sito, los elementos
	de informaci�n que los componen, as� como si dichos elementos se representan como par�metros
	de entrada, de entrada/salida (estado global)...
	suma:lleva la cuenta de la suma actual
	minimo: guarda el valor minimo en ese momento
	contdor: cuenta los casos de éxito

(6) Si el algoritmo utiliza generalizaci�n, indica como es la misma, describiendo claramente
	el prop�sito de cada par�metro.
	v[]: elementos
	n: número de elementos
	umbral: valor umbral

(7) An�lisis de casos: casos base, casos recursivos
	caso base: if (minimo != v[i] && suma + v[i] <= umbral) ->  cuadno se excede el umbral
	caso recursivo: minimalista(v,n,umbral,suma + v[i],min,contador);


(8) Si el algoritmo utiliza una generalizaci�n, describe c�mo se implementa el algoritmo
	en t�rminos de la misma (inmersi�n)
	int num_minimalistas(int c[], int n, int u) llama a -> int minimalista(int v[],int n, int umbral, int suma, int minimo, int &contador)
	pasándole los valores de referencia con un contador inicializado a 0.

*/


// En los 'n' (n>0) primeros elementos de 'c' se encuentran almacenados
// los elementos del conjunto 'C'.
// En 'u' est� el umbral 'U' (U >= 0). 

int minimalista(int v[],int n, int umbral, int suma, int minimo, int &contador) {
	
	for (int i = 0; i < n; i++) {
		
		if (minimo != v[i] && suma + v[i] <= umbral) { //Compruebo si la solución es válida, si suma excede el umbral he recorrido todos los elementos
			contador++;

			int min; //Valor minimo sigue siento el mismo ?
			if (minimo < v[i]) min = minimo;
			else min = v[i];
			//Caso recursivo VA
			minimalista(v,n,umbral,suma + v[i],min,contador); //Caso recursico
		}
	}
	return contador;
}

int num_minimalistas(int c[], int n, int u) {
	// A IMPLEMENTAR
	int contador = 0;
	return minimalista(c,n,u,0,10000,contador);// 0: valor minimo de la secuencia, 10000 valor mínimo de la secuancia (uno muy alto que no afecte)
	
}

/**** PROGRAMA DE PRUEBA: NO MODIFICAR ****/

const int MAX_VALS = 100;

bool ejecuta_caso() {
	int n;
	cin >> n;
	if (n == -1) return false;
	else {
		int v[MAX_VALS];
		for (int i = 0; i < n; i++) {
			cin >> v[i];
		}
		int u;
		cin >> u;
		cout << num_minimalistas(v, n, u) << endl;
		return true;
	}
}

int main() {
	while (ejecuta_caso());
	return 0;
}