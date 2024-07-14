/*
NOMBRE Y APELLIDOS:

*/


#include <iostream>

using namespace std;

static const int MAX_MONEDAS = 100;

/* Tipo para representar los datos de entrada */
typedef struct {
	int num_monedas;     /* Número de monedas a repartir */
	int min_monedas;     /* Mínimo de monedas que debe recibir cada pirata -los dos deben
							recibir este mínimo número de monedas */
	int valor_monedas[MAX_MONEDAS];  /* Valor de las distintas monedas a repartir */
} tEntrada;


/*
(1) ¿Cómo son las soluciones parciales viables de este problema?

(2) ¿Cuándo una solución es final?

(3) Dada una solución viable, ¿cómo se generan nuevas soluciones viables a partir de ella?

(4) ¿Cómo se representarán las soluciones en este problema? Describe los distintos elementos
	de información que las componen, indicando si se representan como parámetros de entrada,
	de entrada/salida (estado global), si se representan implícitamente...

(5) ¿Qué marcadores utiliza el algoritmo? Describe claramente su propósito, los elementos
	de información que los componen, así como si dichos elementos se representan como parámetros
	de entrada, de entrada/salida (estado global)...

(6) Si el algoritmo utiliza generalización, indica como es la misma, describiendo claramente
	el propósito de cada parámetro.

(7) Análisis de casos: casos base, casos recursivos

(8) Si el algoritmo utiliza una generalización, describe cómo se implementa el algoritmo
	en términos de la misma (inmersión)

*/


/* - En min_dif debe devolverse la mínima diferencia que puede conseguirse.
   - En num_formas debe devolverse el número de soluciones que presentan dicha diferencia mínima.
 */

typedef struct {
	int n_monedas [3];//1- Monedas pirata 1 / 2- Monedas pirata 2
	int monedas[MAX_MONEDAS];
	int total_n;

}tPirata;

int diferencia(tPirata& pirata, const tEntrada& entrada) {//Calcula la diferencia de valor de las monedas de los dos piratas

	int monedasPirata1 = 0, monedasPirata2 = 0;

	for (int i = 0; i < pirata.total_n; i++) {
		if (pirata.monedas[i] == 1) {//Monedas pirata 1
			monedasPirata1+=entrada.valor_monedas[i];
		}
		else if (pirata.monedas[i] == 2) {
			monedasPirata2+=entrada.valor_monedas[i];
		}
	}
	int diferencia = monedasPirata1 - monedasPirata2;
	if (diferencia >= 0)return diferencia;
	else return diferencia * -1;

}

void reparto_monedas(const tEntrada& entrada,int &etapa, int& min_dif, int& num_formas,  tPirata& pirata) {
	if (pirata.total_n == entrada.num_monedas) {
		int diff_actual = diferencia(pirata, entrada);
		if (min_dif > diff_actual) {
			min_dif = diff_actual;
			num_formas = 1;
			
		}
		else if (min_dif == diff_actual) {
			num_formas++;
		}
		
	}

	else {
		for (int i = etapa; i < 3; i++) {//Recorro las posibles opciones (1-Pirata1 y 2- Pirata2)

			if (i==1 && pirata.n_monedas[1] < entrada.min_monedas) {//Si etapa=1 coloco un 1 al comienzo del array solucion
				pirata.monedas[pirata.total_n] = 1;
				pirata.total_n++;
				pirata.n_monedas[1]++;
				etapa = 1;
				reparto_monedas(entrada, etapa, min_dif, num_formas,pirata);//Sigo bajando
			}
			
			else if ( pirata.n_monedas[2] < entrada.min_monedas) {
				pirata.monedas[pirata.total_n] = 2;
				pirata.total_n++;
				pirata.n_monedas[2]++;
				etapa = 1;
				reparto_monedas(entrada, etapa, min_dif, num_formas, pirata);
			}
			//Backtraking
				pirata.monedas[pirata.total_n] = 0;
				pirata.total_n--;
				etapa = 2;
				reparto_monedas(entrada, etapa, min_dif, num_formas, pirata);
			


			
			
		}
		
	}
}



void reparte(const tEntrada& entrada, int& min_dif, int& num_formas) {
	// A IMPLEMENTAR
	
	tPirata pirata;
	pirata.total_n = 0;
	pirata.n_monedas[0] = 0;
	pirata.n_monedas[1] = 0;
	pirata.n_monedas[2] = 0;
	min_dif = entrada.valor_monedas[0];
	num_formas = 0;
	int etapa = 1;
	for (int i = 0; i < entrada.num_monedas; i++) {
		pirata.monedas[i] = 0;
	}
	reparto_monedas(entrada, etapa,min_dif, num_formas, pirata);
}

/**** PROGRAMA DE PRUEBA: NO MODIFICAR ****/

bool ejecuta_caso() {
	int num_monedas;
	cin >> num_monedas;
	if (num_monedas == -1) return false;
	else {
		tEntrada entrada;
		entrada.num_monedas = num_monedas;
		cin >> entrada.min_monedas;
		for (int m = 0; m < num_monedas; m++) {
			cin >> entrada.valor_monedas[m];
		}
		int min_dif;
		int num_formas;
		reparte(entrada, min_dif, num_formas);
		cout << min_dif << " " << num_formas << endl;
		return true;
	}
}

int main() {
	while (ejecuta_caso());
	return 0;
}