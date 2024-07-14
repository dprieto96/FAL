
#include <iostream>
using namespace std;

const unsigned int MAX_CLIENTES = 10; // maximo numero de clientes
// Representaci�n de la matriz de afinidades
typedef struct {
	unsigned int n_clientes;                              // numero de clientes. 
	unsigned int afinidades[MAX_CLIENTES][MAX_CLIENTES];  // la matriz se almacena en las 'n_clientes' primeras filas,
	// 'n_clientes' primeras columnas	                                                      
} tMatrizAfinidad;


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

#include <algorithm> // Para std::copy

bool contiene(const int parejas[], unsigned int n, int cliente) {
    for (unsigned int c = 0; c < n; ++c) {
        if (parejas[c] == cliente) {
            return true;
        }
    }
    return false;
}

void actualiza_parejas(const int parejas[], int mejor_parejas[], int total_clientes) {
    copy(parejas, parejas + total_clientes, mejor_parejas);
}

int afinidad(const unsigned int afinidades[MAX_CLIENTES][MAX_CLIENTES], const int parejas[], unsigned int total_clientes) {
    int k = 0;
    for (unsigned int i = 1; i < total_clientes; i += 2) {
        if (afinidades[parejas[i]][parejas[i - 1]] == 0 || afinidades[parejas[i - 1]][parejas[i]] == 0) {
            return 0;
        }
        k += afinidades[parejas[i]][parejas[i - 1]] + afinidades[parejas[i - 1]][parejas[i]];
    }
    return k;
}

void encuentra_pareja(const unsigned int afinidades[MAX_CLIENTES][MAX_CLIENTES], unsigned int num_cliente, int parejas[], bool& hay_pareja, int mejor_pareja[], unsigned int total_clientes) {
    if (num_cliente == total_clientes) {
        int actual_afinidad = afinidad(afinidades, parejas, total_clientes);
        if (!hay_pareja || actual_afinidad > afinidad(afinidades, mejor_pareja, total_clientes)) {
            actualiza_parejas(parejas, mejor_pareja, total_clientes);
            hay_pareja = true;
        }
    }
    else {
        for (unsigned int cliente = 0; cliente < total_clientes; cliente++) {
            if (!contiene(parejas, num_cliente, cliente)) {
                parejas[num_cliente] = cliente;
                encuentra_pareja(afinidades, num_cliente + 1, parejas, hay_pareja, mejor_pareja, total_clientes);
            }
        }
    }
}

int maxima_afinidad(const tMatrizAfinidad& as)
{
    // Punto de entrada al algoritmo: as representa la matriz de afinidades
    // (ver definicion de tMatrizAfinidad). Una vez finalizado el algoritmo,
    // debera devolverse el valor pedido. Pueden definirse todas las
    // funciones auxiliares que se considere oportuno.
    if (as.n_clientes <= 0 || as.n_clientes % 2 != 0) {
        return 0;
    }
    int mejor_pareja[MAX_CLIENTES];
    int total_parejas[MAX_CLIENTES];
    bool hay_pareja = false;
    total_parejas[0] = 0;
    encuentra_pareja(as.afinidades, 1, total_parejas, hay_pareja, mejor_pareja, as.n_clientes);
    return afinidad(as.afinidades, mejor_pareja, as.n_clientes);
}



void ejecuta_caso() {
	tMatrizAfinidad as;
	cin >> as.n_clientes;
	for (unsigned int i = 0; i < as.n_clientes; i++) {
		for (unsigned int j = 0; j < as.n_clientes; j++) {
			cin >> as.afinidades[i][j];
		}
	}
	cout << maxima_afinidad(as) << endl;
}


int main() {
	unsigned int num_casos;
	cin >> num_casos;
	for (unsigned int i = 0; i < num_casos; i++) {
		ejecuta_caso();
	}
}