#ifndef ITERATIVO_H
#define ITERATIVO_H

#include <iostream>
#include <chrono>
using namespace std;
inline long long soma_iterativa(long long n, long long& passos) {
    long long soma = 0;
    long long i = 1;

    passos++; 

    while (i <= n) {
        passos++; 
        soma = soma + i;
        i++;
        passos++; 
    }
    passos++; 

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

    long long passos = 0;

    auto inicio = chrono::high_resolution_clock::now();
    long long resultado = soma_iterativa(n, passos);
    auto fim = chrono::high_resolution_clock::now();
    auto duracao = chrono::duration_cast<chrono::nanoseconds>(fim - inicio);

    cout << "------------------------------------------------------------" << endl;
    cout << "Resultado : soma dos " << n << " primeiros naturais = " << resultado << endl;
    cout << "Passos    : " << passos << " passos executados" << endl;
    cout << "           (1 init + " << n << " testes verdadeiros + "
              << n << " corpos + 1 teste falso)" << endl;
    cout << "Tempo     : " << duracao.count() << " ns  ("
              << duracao.count() / 1000.0 << " us)" << endl;
    cout << "------------------------------------------------------------" << endl;
}

#endif 