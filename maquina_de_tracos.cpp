#ifndef MAQUINA_DE_TRACOS_H
#define MAQUINA_DE_TRACOS_H

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

struct Estado {
    string rotulo;    
    long long i;         
    long long soma;      
    string operacao;  
};

inline vector<Estado> mt_monolitico(long long n) {
    vector<Estado> traco;
    long long soma = 0;
    long long i = 1;

    traco.push_back({"INICIO", i, soma, "soma=0, i=1"});

    while (true) {
        if (i <= n) {
            traco.push_back({"TESTE", i, soma,
                to_string(i) + "<=" + to_string(n) + " ? sim -> goto CORPO"});
            soma = soma + i;
            long long i_antes = i;
            i++;
            traco.push_back({"CORPO", i, soma,
                "soma=" + to_string(soma) +
                ", i=" + to_string(i_antes) + "+1=" + to_string(i) +
                " -> goto TESTE"});
        } else {
            traco.push_back({"TESTE", i, soma,
                to_string(i) + "<=" + to_string(n) + " ? nao -> goto FIM"});
            break;
        }
    }

    traco.push_back({"FIM", i, soma, "retorna soma=" + to_string(soma)});
    return traco;
}

inline vector<Estado> mt_iterativo(long long n) {
    vector<Estado> traco;
    long long soma = 0;
    long long i = 1;

    traco.push_back({"INICIO", i, soma, "soma=0, i=1"});

    while (true) {
        if (i <= n) {
            traco.push_back({"TESTE", i, soma,
                to_string(i) + "<=" + to_string(n) + " ? sim -> entra no laco"});
            soma = soma + i;
            long long i_antes = i;
            i++;
            traco.push_back({"CORPO", i, soma,
                "soma=" + to_string(soma) +
                ", i=" + to_string(i_antes) + "+1=" + to_string(i) +
                " -> volta ao TESTE"});
        } else {
            traco.push_back({"TESTE", i, soma,
                to_string(i) + "<=" + to_string(n) + " ? nao -> sai do laco"});
            break;
        }
    }

    traco.push_back({"FIM", i, soma, "retorna soma=" + to_string(soma)});
    return traco;
}

inline vector<Estado> mt_variante(long long n) {
    vector<Estado> traco;
    long long soma = 0;
    long long i = 1;

    traco.push_back({"INICIO", i, soma, "soma=0, i=1  [VARIANTE: incrementa i antes de somar]"});

    while (true) {
        if (i <= n) {
            traco.push_back({"TESTE", i, soma,
                to_string(i) + "<=" + to_string(n) + " ? sim"});
            i++;   
            soma = soma + i;
            traco.push_back({"CORPO", i, soma,
                "i incrementado para " + to_string(i) +
                " antes de somar -> soma=" + to_string(soma)});
        } else {
            traco.push_back({"TESTE", i, soma,
                to_string(i) + "<=" + to_string(n) + " ? nao -> FIM"});
            break;
        }
    }

    traco.push_back({"FIM", i, soma,
        "retorna soma=" + to_string(soma) + "  (DIVERGE do programa original)"});
    return traco;
}

inline void exibir_traco(const string& nome, const vector<Estado>& traco, long long n) {
    cout << "\n";
    cout << "+==========================================================+" << endl;
    cout << "  TRACO — " << nome << "  (entrada: n=" << n << ")" << endl;
    cout << "+==========================================================+" << endl;
    cout << left
              << setw(6)  << "Passo"
              << setw(10) << "Rotulo"
              << setw(6)  << "i"
              << setw(10) << "soma"
              << "Operacao" << endl;
    cout << "----------------------------------------------------------" << endl;
    for (int p = 0; p < (int)traco.size(); p++) {
        cout << left
                  << setw(6)  << p
                  << setw(10) << traco[p].rotulo
                  << setw(6)  << traco[p].i
                  << setw(10) << traco[p].soma
                  << traco[p].operacao
                  << endl;
    }
    cout << "+==========================================================+" << endl;
}

inline void comparar_tracosFormais(
    const string& nome1, const vector<Estado>& t1,
    const string& nome2, const vector<Estado>& t2)
{
    cout << "\n";
    cout << "##########################################################" << endl;
    cout << "  ANALISE DE EQUIVALENCIA FORTE" << endl;
    cout << "  Comparando: [" << nome1 << "] vs [" << nome2 << "]" << endl;
    cout << "##########################################################" << endl;

    bool equivalentes = true;

    if (t1.size() != t2.size()) {
        cout << "\n  [!] Tracos com tamanhos diferentes:" << endl;
        cout << "      " << nome1 << ": " << t1.size() << " passos" << endl;
        cout << "      " << nome2 << ": " << t2.size() << " passos" << endl;
        equivalentes = false;
    }

    int min_passos = (int)min(t1.size(), t2.size());
    for (int p = 0; p < min_passos; p++) {
        bool rotulo_igual = (t1[p].rotulo == t2[p].rotulo);
        bool i_igual      = (t1[p].i      == t2[p].i);
        bool soma_igual   = (t1[p].soma   == t2[p].soma);

        if (!rotulo_igual || !i_igual || !soma_igual) {
            cout << "\n  [DIVERGENCIA] Passo " << p << ":" << endl;
            cout << "    " << nome1 << ": rotulo=" << t1[p].rotulo
                      << "  i=" << t1[p].i
                      << "  soma=" << t1[p].soma << endl;
            cout << "    " << nome2 << ": rotulo=" << t2[p].rotulo
                      << "  i=" << t2[p].i
                      << "  soma=" << t2[p].soma << endl;
            if (!rotulo_igual) cout << "    -> Rotulos diferentes!" << endl;
            if (!i_igual)      cout << "    -> Valor de i diferente!" << endl;
            if (!soma_igual)   cout << "    -> Valor de soma diferente!" << endl;
            equivalentes = false;
        }
    }

    cout << endl;
    if (equivalentes) {
        cout << "  RESULTADO: FORTEMENTE EQUIVALENTES" << endl;
        cout << "  Todos os " << t1.size() << " passos do traco coincidem." << endl;
        cout << "  Mesmos rotulos, mesmos valores de i e soma em cada passo." << endl;
    } else {
        cout << "  RESULTADO: NAO SAO FORTEMENTE EQUIVALENTES" << endl;
        cout << "  Os tracos divergem nos pontos indicados acima." << endl;
    }
    cout << "##########################################################" << endl;
}

inline void menu_maquina_de_tracos() {
    string opcao;

    while (true) {
        cout << "\n============================================================" << endl;
        cout << "   MAQUINA DE TRACOS — Soma dos N Primeiros Naturais" << endl;
        cout << "============================================================" << endl;
        cout << "  1. Caso de equivalencia forte" << endl;
        cout << "  2. Caso de nao-equivalencia" << endl;
        cout << "  3. Voltar ao menu principal" << endl;
        cout << "------------------------------------------------------------" << endl;
        cout << "Escolha uma opcao: ";
        cin >> opcao;

        if (opcao == "1") {
            long long n;
            cout << "\nDigite n para analise: ";
            cin >> n;
            if (n < 0) {
                cout << "Entrada invalida: n deve ser >= 0." << endl;
                continue;
            }

            auto traco_mono = mt_monolitico(n);
            auto traco_iter = mt_iterativo(n);

            cout << "\n====  CASO 1: EQUIVALENCIA FORTE  ====" << endl;
            cout << "Comparando: Monolitico vs Iterativo" << endl;

            exibir_traco("Monolitico", traco_mono, n);
            exibir_traco("Iterativo",  traco_iter, n);
            comparar_tracosFormais("Monolitico", traco_mono, "Iterativo", traco_iter);

        } else if (opcao == "2") {
            long long n;
            cout << "\nDigite n para analise: ";
            cin >> n;
            if (n < 0) {
                cout << "Entrada invalida: n deve ser >= 0." << endl;
                continue;
            }

            auto traco_mono = mt_monolitico(n);
            auto traco_var  = mt_variante(n);

            cout << "\n====  CASO 2: NAO-EQUIVALENCIA  ====" << endl;
            cout << "Comparando: Monolitico original vs Variante (i++ antes da soma)" << endl;
            cout << "A variante troca a ordem no CORPO: incrementa i ANTES de somar," << endl;
            cout << "computando 2+3+...+(n+1) em vez de 1+2+...+n." << endl;

            exibir_traco("Monolitico",traco_mono, n);
            exibir_traco("Variante (i++ antes soma)", traco_var, n);
            comparar_tracosFormais("Monolitico", traco_mono, "Variante", traco_var);

        } else if (opcao == "3") {
            break;

        } else {
            cout << "Opcao invalida. Digite 1, 2 ou 3." << endl;
        }
    }
}

#endif 