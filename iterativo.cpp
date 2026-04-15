#ifndef ITERATIVO_H
#define ITERATIVO_H

#include <iostream>
using namespace std;

inline long long soma_iterativa(long long n) {
    long long soma = 0;
    long long i = 1;

    while (i <= n) {
        soma = soma + i;
        i++;
    }

    return soma;
}

inline void rodar_iterativo() {
    long long n;

    cout << "\n=== Programa Iterativo — Soma dos N Primeiros Naturais ===" << endl;
    cout << "Digite n: ";
    cin >> n;

    if (n < 0) {
        cout << "Entrada invalida: n deve ser >= 0." << endl;
        return;
    }

    cout << "Resultado: soma dos " << n << " primeiros naturais = "
              << soma_iterativa(n) << endl;
}

#endif