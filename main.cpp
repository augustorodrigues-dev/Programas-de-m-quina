#include "monolitico.cpp"
#include "iterativo.cpp"
#include "recursivo.cpp"
#include "maquina_de_tracos.cpp"

#include <iostream>
#include <string>
using namespace std;

void exibir_menu_principal() {
    cout << "\n============================================================" << endl;
    cout << "   SOMA DOS N PRIMEIROS NATURAIS — Teoria da Computabilidade" << endl;
    cout << "============================================================" << endl;
    cout << "  1. Programa Monolitico  (uso de goto)" << endl;
    cout << "  2. Programa Recursivo   (chamada recursiva)" << endl;
    cout << "  3. Programa Iterativo   (laco while)" << endl;
    cout << "  4. Maquina de Tracos    (analise de equivalencia)" << endl;
    cout << "  5. Encerrar o programa" << endl;
    cout << "------------------------------------------------------------" << endl;
    cout << "Escolha uma opcao: ";
}

int main() {
    string opcao;

    while (true) {
        exibir_menu_principal();
        cin >> opcao;

        if (opcao == "1") {
            rodar_monolitico();

        } else if (opcao == "2") {
            rodar_recursivo();

        } else if (opcao == "3") {
            rodar_iterativo();

        } else if (opcao == "4") {
            menu_maquina_de_tracos();

        } else if (opcao == "5") {
            cout << "\nPrograma encerrado. Até mais!" << endl;
            break;

        } else {
            cout << "\nOpcao invalida. Digite um numero de 1 a 5." << endl;
        }
    }

    return 0;
}