/*
NOMBRES Y APELLIDOS DE LOS MIEMBROS DEL GRUPO QUE HAN REALIZADO LA PRACTICA:

DANIEL PRIETO REMCHA

Si alguno de los miembros del grupo no ha realizado
la práctica, indicarlo aquí, junto con el motivo:

SIN COMPAÑERO - NO CONSIGO CONTACTAR CON ÉL

*/

#include <iostream>

using namespace std;


/*
(1) GENERALIZACION (EN CASO DE QUE PROCEDA): Entradas y salidas
    ENTRADAS:
    int etapas[]
    int n -> LUEGO SE DESGLOSA EN ini y fin
    int repostajes_permitidos

    SALIDAS:
    int min_deposito() -> entero con el volumen 

(2) DISEÑO
    Busqueda binaria cpara encontrar la capacidad minima, es decir Algoritmo divide y venceras
    CASO BASE: if (ini + 1 == fin) -> Solo una etapa

    RECURSIVIDAD: (Divide y venceras), se va diviendo el problema con el pivote mitad=int mitad = (ini + fin - 1) / 2;
    if (n_repostajes <= repostajes) return min_deposito(etapas, n, repostajes, ini, mitad + 1);
    else return min_deposito(etapas, n, repostajes, mitad + 1, fin);

(3) TERMINACIÓN:
    CASO BASE: if (ini + 1 == fin), nos aseguramos que siempre termine

(4) IMPLEMENTACION POR INMERSION DEL ALGORITMO, SI PROCEDE:
    int min_capacidad(int etapas[], int n, int repostajes_permitidos) {
	// A IMPLEMENTAR
    return min_deposito(etapas, n, repostajes_permitidos + 1, max_array(etapas, n), suma(etapas, n) + 1);
}

(5) DETERMINACION DEL COSTE DEL ALGORITMO EN EL PEOR CASO:
    O(log n) que es el coste de la busqueda binaria
    O(n) en las funciones auxiliares de ;
    int suma_array(int a[], int n, int repostaje)
    int suma(int a[], int n)
    int max_array(int a[], int n)

    O(log n) + 3 x O(n) = O(n)
*/

int suma_array(int a[], int n, int repostaje) {
    int suma = 0, cont = 1;
    for (int i = 0; i < n; i++) {
        suma += a[i];
        if (suma > repostaje) {
            cont++;
            suma = a[i];
        }
    }
    return cont;
}

int suma(int a[], int n) {
    int suma = 0;
    for (int i = 0; i < n; i++) {
        suma += a[i];
    }
    return suma;
}

int max_array(int a[], int n) {
    int max = a[0];
    for (int i = 1; i < n; i++) {
        if (max < a[i]) max = a[i];
    }
    return max;
}

int min_deposito(int etapas[], int n, int repostajes, int ini, int fin) {
    if (ini + 1 == fin) {
        return ini;
    }
    int mitad = (ini + fin - 1) / 2;
    int n_repostajes = suma_array(etapas, n, mitad);

    if (n_repostajes <= repostajes) return min_deposito(etapas, n, repostajes, ini, mitad + 1);
    else return min_deposito(etapas, n, repostajes, mitad + 1, fin);
}

int min_capacidad(int etapas[], int n, int repostajes_permitidos) {
	// A IMPLEMENTAR
    return min_deposito(etapas, n, repostajes_permitidos + 1, max_array(etapas, n), suma(etapas, n) + 1);
}



const int MAX_ETAPAS = 100000;


bool ejecuta_caso() {
	static int v[MAX_ETAPAS];
	int n, c;
	cin >> n;
	if (n == -1) return false;
	else {
		cin >> c;
		for (int i = 0; i < n; ++i)
			cin >> v[i];
		cout << min_capacidad(v, n, c) << endl;
		return true;
	}
}

int main() {
	while (ejecuta_caso());
	return 0;
}
