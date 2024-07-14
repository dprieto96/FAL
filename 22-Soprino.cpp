/*
NOMBRE Y APELLIDOS:

N� USUARIO DOMJUDGE:

*/

#include <iostream>

using namespace std;

const int MAX_PERSONAS = 20;
const int MAX_VEHICULOS = 10;


// Datos de entrada
typedef struct {
	bool ha_bebido[MAX_PERSONAS];   // ha_bebido[i]: La persona i ha bebido
	int capacidad[MAX_VEHICULOS];   // capacidad[v]: N� de personas que caben en el veh�culo v 
	int n_personas;                 // N� total de personas en el clan
	int n_vehiculos;                // N� total de veh�culos
} tDatos;

typedef struct {
    int sobrios[MAX_VEHICULOS];
    int ebrios[MAX_VEHICULOS];
} tSol;



/*

(1) En caso de utilizar una generalizaci�n, indicar su par�metros, y explicar para que
sirven cada uno de ellos

(2) �C�mo son las soluciones parciales de este problema?

(3) �Cu�ndo una soluci�n parcial es viable?

(4) �Cu�ndo una soluci�n parcial es una soluci�n final al problema?

(5) Dada una soluci�n parcial, �c�mo se generan las siguientes soluciones
parciales viables?

(6) An�lisis de casos

(6.1) Caso(s) base


(6.2) Caso(s) recursivos

(7) En caso de utilizar una generalizaci�n, explicar c�mo se define el algoritmo final
a partir de la misma, por inmersi�n.



*/

bool esViable(const tDatos& datos, const tSol& solucion) {
    for (int vehiculo = 0; vehiculo < datos.n_vehiculos; vehiculo++) {
        if (solucion.sobrios[vehiculo] <= 0 || (solucion.ebrios[vehiculo] + solucion.sobrios[vehiculo]) <= 0) {
            return false;
        }
    }
    return true;
}

void solve(const tDatos& datos, tSol& solucion, int posPersona, int& soluciones) {
    if (posPersona == datos.n_personas) {
        if (esViable(datos, solucion)) {
            soluciones++;
        }
    }
    else {
        for (int posVehiculo = 0; posVehiculo < datos.n_vehiculos; posVehiculo++) {
            int puestosOcupados = solucion.sobrios[posVehiculo] + solucion.ebrios[posVehiculo];
            if (puestosOcupados < datos.capacidad[posVehiculo]) {
                if (datos.ha_bebido[posPersona] && solucion.ebrios[posVehiculo] + 1 <= (datos.capacidad[posVehiculo] / 2)) {
                    solucion.ebrios[posVehiculo]++;
                    solve(datos, solucion, posPersona + 1, soluciones);
                    solucion.ebrios[posVehiculo]--;
                }
                else if (!datos.ha_bebido[posPersona]) {
                    solucion.sobrios[posVehiculo]++;
                    solve(datos, solucion, posPersona + 1, soluciones);
                    solucion.sobrios[posVehiculo]--;
                }
            }
        }
    }
}

int num_asignaciones(const tDatos& datos) {
    int soluciones = 0;
    tSol solucion = {};
    solve(datos, solucion, 0, soluciones);
    return soluciones;
}



bool ejecuta() {
	tDatos datos;
	cin >> datos.n_vehiculos;
	if (datos.n_vehiculos == -1) return false;
	cin >> datos.n_personas;
	for (int v = 0; v < datos.n_vehiculos; v++) {
		int bebe;
		cin >> datos.capacidad[v];
	}
	for (int p = 0; p < datos.n_personas; p++) {
		int bebe;
		cin >> bebe;
		if (bebe == 0) {
			datos.ha_bebido[p] = false;
		}
		else {
			datos.ha_bebido[p] = true;
		}
	}
	cout << num_asignaciones(datos) << endl;
	return true;

}


int main() {
	while (ejecuta());
}