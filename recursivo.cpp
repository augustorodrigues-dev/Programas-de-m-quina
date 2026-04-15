#ifndef RECURSIVO_H
#define RECURSIVO_H

#include <iostream>
using namespace std;
inline long long soma_recursiva(long long n) {
    if (n == 0) {
        return 0;
    }
    return n + soma_recursiva(n - 1);
}

inline void rodar_recursivo() {
    long long n;

    cout << "\n=== Programa Recursivo — Soma dos N Primeiros Naturais ===" << endl;
    cout << "Digite n: ";
    cin >> n;

    if (n < 0) {
        cout << "Entrada invalida: n deve ser >= 0." << endl;
        return;
    }

    cout << "Resultado: soma dos " << n << " primeiros naturais = "
              << soma_recursiva(n) << endl;
}

#endif 