#include <iostream>
#include <algorithm>
using namespace std;


/*
(1) Precondición

(2) Postcondición

(3) Si vas a utilizar una generalización, especificación
	pre-pos de la generalización

(4) Casos no recursivos

(5) Casos recursivos

(6) Terminación (expresión de cota)

(7) Si has usado una generalización, definición por
	inmersión de es_paracurioso

(8) Determinación de la complejidad (recurrencias y su resolución)


*/

bool parcurious(int v[], int a, int b,
    int& numEven, int& numOdd, int& sumEven, int& sumOdd) {
    int r;
    if (a == b) {
        // only one element: even or odd
        if (v[a] % 2 == 0) {
            numEven = 1;
            sumEven = v[a];
            numOdd = sumOdd = 0;
        }
        else {
            numOdd = 1;
            sumOdd = v[a];
            numEven = sumEven = 0;
        }
        r = true;
    }
    else {
        // more than one element
        // recursive call on each half
        int m = (a + b) / 2;
        int numEven1, numOdd1, sumEven1, sumOdd1;
        bool r1 = parcurious(v, a, m, numEven1, numOdd1, sumEven1, sumOdd1);
        int numEven2, numOdd2, sumEven2, sumOdd2;
        bool r2 = parcurious(v, m + 1, b, numEven2, numOdd2, sumEven2, sumOdd2);

        // output parameters
        r = numEven1 <= numOdd2 && sumEven1 <= sumOdd2 && (r1 || r2);
        numEven = numEven1 + numEven2;
        numOdd = numOdd1 + numOdd2;
        sumEven = sumEven1 + sumEven2;
        sumOdd = sumOdd1 + sumOdd2;
    }
    return r;
}


// NO MODIFICAR

const static int MAX_ELEMENTS = 100000;

void ejecuta_caso() {
	static int v[MAX_ELEMENTS];
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
    int numEven, numOdd, sumEven, sumOdd;
	if (parcurious(v, 0, n - 1, numEven, numOdd, sumEven, sumOdd)) {
		cout << "SI" << endl;;
	}
	else {
		cout << "NO" << endl;
	}
}


int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		ejecuta_caso();
	return 0;
}