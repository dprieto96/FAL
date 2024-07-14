

#include <iostream>

using namespace std;

typedef unsigned long long t_num;


/*

(1) En caso de utilizar una generalización, indicar su parámetros, y explicar para que
sirven cada uno de ellos

(2) ¿Cómo son las soluciones parciales de este problema?

(3) ¿Cuándo una solución parcial es viable?

(4) ¿Cuándo una solución parcial es una solución final al problema?

(5) Dada una solución parcial, ¿cómo se generan las siguientes soluciones
parciales viables?

(6) Análisis de casos

(6.1) Caso(s) base


(6.2) Caso(s) recursivos

(7) En caso de utilizar una generalización, explicar cómo se define el algoritmo final
a partir de la misma, por inmersión.



*/


void solve(unsigned short d, unsigned short alpha, t_num n, unsigned int s, t_num nextNum, unsigned int sumaActual, unsigned int cantidad, int& soluciones) {
    if (sumaActual == s && nextNum != 0) {
        soluciones++;
        return;
    }

    for (unsigned int nextDigit = 1; nextDigit <= 9; ++nextDigit) {
        if ((sumaActual + nextDigit) > s || ((nextNum * 10) + nextDigit) >= n) {
            break;
        }

        if (nextDigit != d) {
            solve(d, alpha, n, s, (nextNum * 10) + nextDigit, sumaActual + nextDigit, cantidad, soluciones);
        }
        else if (cantidad < alpha) {
            solve(d, alpha, n, s, (nextNum * 10) + nextDigit, sumaActual + nextDigit, cantidad + 1, soluciones);
        }
    }
}

int num_limpios(unsigned short d, unsigned short alpha, t_num n, unsigned int s) {
    int soluciones = 0;
    solve(d, alpha, n, s, 0, 0, 0, soluciones);
    return soluciones;
}




bool ejecuta_caso() {
	int d;
	cin >> d;
	if (d == -1) {
		return false;
	}
	else {
		unsigned short alpha;
		unsigned int s;
		t_num n;
		cin >> alpha >> s >> n;
		cout << num_limpios(d, alpha, n, s) << endl;
		return true;
	}
}


int main() {
	while (ejecuta_caso());
}