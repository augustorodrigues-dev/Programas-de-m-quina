#include <iostream>
using namespace std;

long long soma_recursiva(long long n) {
    if (n == 0) {
        return 0;
    }
    return n + soma_recursiva(n - 1);
}

int main() {
    long long n;

    cout << "=== Programa Recursivo — Soma dos N Primeiros Naturais ===" << endl;
    cout << "Digite n: ";
    cin >> n;

    if (n < 0) {
        cout << "Entrada invalida: n deve ser >= 0." << endl;
        return 1;
    }

    cout << "Soma dos " << n << " primeiros naturais = " << soma_recursiva(n) << endl;
    return 0;
}