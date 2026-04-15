#ifndef MONOLITICO_H
#define MONOLITICO_H

#include <iostream>
using namespace std;

inline void rodar_monolitico() {
    long long n, soma, i;

    cout << "\n=== Programa Monolitico — Soma dos N Primeiros Naturais ===" << endl;
    cout << "Digite n: ";
    cin >> n;

    if (n < 0) {
        cout << "Entrada invalida: n deve ser >= 0." << endl;
        return;
    }


INICIO:
    soma = 0;
    i    = 1;
    goto TESTE;

TESTE:
    if (i <= n) goto CORPO;
    else goto FIM;

CORPO:
    soma = soma + i;
    i++;
    goto TESTE;

FIM:
    cout << "Resultado: soma dos " << n << " primeiros naturais = " << soma << endl;
}

#endif 