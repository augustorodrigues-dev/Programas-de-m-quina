#include <iostream>
using namespace std;

int main() {
    long long n, soma, i;

    std::cout << "=== Programa Monolitico — Soma dos N Primeiros Naturais ===" << endl;
    cout << "Digite n: ";
    cin >> n;

    if (n < 0) {
        cout << "Entrada invalida: n deve ser >= 0." << endl;
        return 1;
    }

    
INICIO:
    soma = 0;
    i    = 1;
    goto TESTE;

TESTE:
    if (i <= n) goto CORPO;
    else        goto FIM;

CORPO:
    soma = soma + i;
    i    = i + 1;
    goto TESTE;

FIM:
    cout << "Soma dos " << n << " primeiros naturais = " << soma << endl;
    return 0;
}