#include <iostream>
using namespace std;
long long soma_iterativa(long long n) {
    long long soma = 0;
    long long i    = 1;

    while (i <= n) {
        soma = soma + i;
        i    = i + 1;
    }

    return soma;
}

int main() {
    long long n;

    cout << "=== Programa Iterativo — Soma dos N Primeiros Naturais ===" << endl;
    cout << "Digite n: ";
    cin >> n;

    if (n < 0) {
        cout << "Entrada invalida: n deve ser >= 0." << endl;
        return 1;
    }

    cout << "Soma dos " << n << " primeiros naturais = " << soma_iterativa(n) << endl;
    return 0;
}