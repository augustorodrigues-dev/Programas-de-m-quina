#ifndef RECURSIVO_H
#define RECURSIVO_H

#include <iostream>
#include <chrono>
using namespace std;

inline long long soma_recursiva(long long n, long long& passos) {
    passos++; 

    if (n == 0) {
        return 0;
    }
    return n + soma_recursiva(n - 1, passos);
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

    long long passos = 0;

    auto inicio = chrono::high_resolution_clock::now();
    long long resultado = soma_recursiva(n, passos);
    auto fim = chrono::high_resolution_clock::now();
    auto duracao = chrono::duration_cast<chrono::nanoseconds>(fim - inicio);

    cout << "------------------------------------------------------------" << endl;
    cout << "Resultado : soma dos " << n << " primeiros naturais = " << resultado << endl;
    cout << "Passos    : " << passos << " passos executados" << endl;
    cout << "           (" << (n + 1) << " chamadas recursivas: soma(" << n
              << ") ate soma(0))" << endl;
    cout << "Tempo     : " << duracao.count() << " ns  ("
              << duracao.count() / 1000.0 << " us)" << endl;
    cout << "------------------------------------------------------------" << endl;
}

#endif 