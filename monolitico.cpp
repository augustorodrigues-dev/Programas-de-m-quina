#ifndef MONOLITICO_H
#define MONOLITICO_H

#include <iostream>
#include <chrono>
using namespace std;
inline void rodar_monolitico() {
    long long n, soma, i;
    long long passos = 0; 

    cout << "\n=== Programa Monolitico — Soma dos N Primeiros Naturais ===" << endl;
    cout << "Digite n: ";
    cin >> n;

    if (n < 0) {
        cout << "Entrada invalida: n deve ser >= 0." << endl;
        return;
    }

    
    auto inicio = chrono::high_resolution_clock::now();
INICIO:
    soma = 0;
    i = 1;
    passos++; 
    goto TESTE;

TESTE:
    passos++; 
    if (i <= n) goto CORPO;
    else goto FIM;

CORPO:
    soma = soma + i;
    i++;
    passos++; 
    goto TESTE;

FIM:
    passos++; 

    auto fim = chrono::high_resolution_clock::now();
    auto duracao = chrono::duration_cast<chrono::nanoseconds>(fim - inicio);

    cout << "------------------------------------------------------------" << endl;
    cout << "Resultado : soma dos " << n << " primeiros naturais = " << soma << endl;
    cout << "Passos    : " << passos << " passos executados" << endl;
    cout << "           (1 INICIO + " << (n + 1) << " TESTES + "
              << n << " CORPOS + 1 FIM)" << endl;
    cout << "Tempo     : " << duracao.count() << " ns  ("
              << duracao.count() / 1000.0 << " us)" << endl;
    cout << "------------------------------------------------------------" << endl;
}

#endif 