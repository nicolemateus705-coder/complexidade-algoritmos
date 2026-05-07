#include <iostream>
using namespace std;

int main() {
    int n;
    double x, resultado = 0;

    cout << "Quantidade de coeficientes: ";
    cin >> n;

    double a[n];

    for(int i = 0; i < n; i++) {
        cout << "Coeficiente a[" << i << "]: ";
        cin >> a[i];
    }

    cout << "Valor de x: ";
    cin >> x;

    for(int i = 0; i < n; i++) {

        double potencia = 1;

        for(int j = 0; j < i; j++) {
            potencia *= x;
        }

        resultado += a[i] * potencia;
    }

    cout << "Resultado do polinomio: " << resultado << endl;

    return 0;
}
