#include <iostream>
using namespace std;

int main() {

    int n;
    double x;

    cout << "Quantidade de coeficientes: ";
    cin >> n;

    double a[n];

    for(int i = 0; i < n; i++) {
        cout << "Coeficiente a[" << i << "]: ";
        cin >> a[i];
    }

    cout << "Valor de x: ";
    cin >> x;

    double resultado = a[n - 1];

    for(int i = n - 2; i >= 0; i--) {
        resultado = resultado * x + a[i];
    }

    cout << "Resultado do polinomio: " << resultado << endl;

    return 0;
}
