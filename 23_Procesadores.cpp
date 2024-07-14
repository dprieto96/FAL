/*
NOMBRE Y APELLIDOS:

IMPORTANTE: Si no se a�ade el nombre y apellidos,
el ejercicio no se corregir� (puntuar� como 0).

*/
#include <iostream>

using namespace std;


const int MAX_PROCESOS = 100;

// Tipo para codificar los datos de entrada
// al problema
typedef struct {
	int t_procesamiento;  // Tiempo de procesamiento 'T' de los procesadores.
	// Cada procesador permite utizar, como m�ximo,
	// 'T' unidades de tiempo.
	int t_procesos[MAX_PROCESOS];  // Unidades de tiempo requeridas por cada proceso. 
	int b_procesos[MAX_PROCESOS];  // Beneficio reportado por cada proceso.
	int n;                         // N�mero de procesos 'N' (n <= MAX_PROCESOS).
} tEntrada;


/*
IMPORTANTE: Para superar este ejercicio es necesario desarrollar
correctamente los distintos pasos del dise�o del algoritmo. No
se tendr� en cuenta la codificaci�n del algoritmo, a menos que
est� acompa�ada del dise�o sistem�tico del mismo.
*/


/*
(1) En caso de utilizar una generalizaci�n, indicar su par�metros, y explicar para que
sirven cada uno de ellos

(2) �C�mo son las soluciones parciales de este problema?

(3) �Cu�ndo una soluci�n parcial es viable?

(4) �Cu�ndo una soluci�n parcial es una soluci�n final al problema?

(5) Dada una soluci�n parcial, �c�mo se generan las siguientes soluciones
parciales viables?

(6) Si est�s utilizando alg�n criterio de poda adicional, explica detalladamente
	el criterio utilizado

(7) An�lisis de casos

(7.1) Caso(s) base


(7.2) Caso(s) recursivos

(8) En caso de utilizar una generalizaci�n, explicar c�mo se define el algoritmo final
a partir de la misma, por inmersi�n.



*/
struct tAsignacion {
	int tiempoDisponibleP1;
	int tiempoDisponibleP2;
	int sumBeneficios;
};


void solve(const tEntrada& entrada, tAsignacion& asigActual, int nProceso, int& mejorSuma);

void montaAsignacion(const tEntrada& entrada, tAsignacion& asig) {
	asig.tiempoDisponibleP1 = entrada.t_procesamiento;
	asig.tiempoDisponibleP2 = entrada.t_procesamiento;
	asig.sumBeneficios = 0;
}

void procesar(tAsignacion& asigActual, const tEntrada& entrada, int nProceso, int& mejorSuma, bool enP1) {
	int& tiempoDisponible = enP1 ? asigActual.tiempoDisponibleP1 : asigActual.tiempoDisponibleP2;

	if (tiempoDisponible >= entrada.t_procesos[nProceso]) {
		tiempoDisponible -= entrada.t_procesos[nProceso];
		asigActual.sumBeneficios += entrada.b_procesos[nProceso];
		solve(entrada, asigActual, nProceso + 1, mejorSuma);
		asigActual.sumBeneficios -= entrada.b_procesos[nProceso];
		tiempoDisponible += entrada.t_procesos[nProceso];
	}
}

void solve(const tEntrada& entrada, tAsignacion& asigActual, int nProceso, int& mejorSuma) {
	if (nProceso == entrada.n) {
		if (asigActual.sumBeneficios > mejorSuma) {
			mejorSuma = asigActual.sumBeneficios;
		}
		return;
	}

	procesar(asigActual, entrada, nProceso, mejorSuma, true);  // Procesar en P1
	procesar(asigActual, entrada, nProceso, mejorSuma, false); // Procesar en P2
}

int max_beneficio(const tEntrada& entrada) {
	tAsignacion asigActual;
	montaAsignacion(entrada, asigActual);
	int mejorSuma = 0;
	solve(entrada, asigActual, 0, mejorSuma);
	return mejorSuma;
}



/************************************************************/
// Programa de prueba: NO MODIFICAR. Aquellas soluciones que
// modifiquen el c�digo que sigue no se corregir�n (puntuar�n 0).

bool ejecuta_caso() {
	int t_procesamiento;
	int n_procesos;
	cin >> t_procesamiento >> n_procesos;
	if (t_procesamiento == 0 && n_procesos == 0) {
		return false;
	}
	else {
		tEntrada entrada;
		entrada.n = n_procesos;
		entrada.t_procesamiento = t_procesamiento;
		for (int p = 0; p < n_procesos; p++) {
			cin >> entrada.t_procesos[p];
		}
		for (int p = 0; p < n_procesos; p++) {
			cin >> entrada.b_procesos[p];
		}
		cout << max_beneficio(entrada) << endl;
		return true;
	}
}

int main() {
	while (ejecuta_caso());
	return 0;
}


