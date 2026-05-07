#include <iostream>
#include <vector>

using namespace std;

long long merge(vector<int>& v, int inicio, int meio, int fim) {

    vector<int> esquerda(v.begin() + inicio, v.begin() + meio + 1);
    vector<int> direita(v.begin() + meio + 1, v.begin() + fim + 1);

    int i = 0;
    int j = 0;
    int k = inicio;

    long long inversoes = 0;

    while(i < esquerda.size() && j < direita.size()) {

        if(esquerda[i] <= direita[j]) {
            v[k] = esquerda[i];
            i++;
        }
        else {
            v[k] = direita[j];
            inversoes += esquerda.size() - i;
            j++;
        }

        k++;
    }

    while(i < esquerda.size()) {
        v[k] = esquerda[i];
        i++;
        k++;
    }

    while(j < direita.size()) {
        v[k] = direita[j];
        j++;
        k++;
    }

    return inversoes;
}

long long mergeSort(vector<int>& v, int inicio, int fim) {

    long long inversoes = 0;

    if(inicio < fim) {

        int meio = (inicio + fim) / 2;

        inversoes += mergeSort(v, inicio, meio);

        inversoes += mergeSort(v, meio + 1, fim);

        inversoes += merge(v, inicio, meio, fim);
    }

    return inversoes;
}

int main() {

    int n;

    cout << "Quantidade de elementos: ";
    cin >> n;

    vector<int> v(n);

    for(int i = 0; i < n; i++) {
        cout << "Elemento " << i << ": ";
        cin >> v[i];
    }

    long long resultado = mergeSort(v, 0, n - 1);

    cout << "Numero de inversoes: " << resultado << endl;

    return 0;
}
