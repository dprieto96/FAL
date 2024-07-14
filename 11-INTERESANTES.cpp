
#include <iostream>
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



bool es_interesante(unsigned int n) {
	// A IMPLEMENTAR
	int numDigitos = 0;
	unsigned int tmp=n;
	if (n == 0)return false;
	do {
		numDigitos++;
		tmp=tmp/ 10;
	} while (tmp > 0);


	int digitos[1000000];
	tmp = n;
	for (int i = numDigitos - 1; i >= 0; i--) {
		digitos[i] = tmp % 10;
		tmp =tmp/ 10;
	}
	
	for (int i = 0; i < numDigitos; i++) {
		if (digitos[i] == 0) return false; 
		int sumaMasSignificativos = 0, sumaMenosSignificativos = 0;
		for (int j = 0; j < i; j++) {
			sumaMasSignificativos += digitos[j];
		}
		for (int j = i + 1; j < numDigitos; j++) {
			sumaMenosSignificativos += digitos[j];
		}
		if ((sumaMasSignificativos % digitos[i] != 0) || (i != numDigitos - 1 && sumaMenosSignificativos % digitos[i] != 0)) {
			return false;
		}
	}

	return true;
}

void ejecuta_caso() {
	unsigned int n;
	cin >> n;
	if (es_interesante(n)) {
		cout << "SI" << endl;
	}
	else {
		cout << "NO" << endl;
	}
}

int main() {
	unsigned int num_casos;
	cin >> num_casos;
	for (int i = 0; i < num_casos; i++) {
		ejecuta_caso();
	}
}