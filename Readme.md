# Programas, Máquinas e Equivalência — Teoria da Computabilidade

**Disciplina:** Teoria da Computabilidade  
**Professor:** Daniel Leal Souza  
**Turmas:** CC5MA / CC5NA  
**Semestre:** 01/2026  
**Instituição:** Escola de Negócios, Tecnologia e Inovação — CESUPA

---

## Integrantes da equipe

| Nome | Matrícula |
|------|-----------|
|Augusto Rodrigues      |24070005           |
|Cauê Jadão      |24070033           |
|César Ribeiro     |24070011           |

---

## Função implementada

**Soma dos N primeiros naturais**

```
soma(n) = 1 + 2 + 3 + ... + n
```

| Entrada | Saída esperada |
|---------|----------------|
| n = 0   | 0              |
| n = 1   | 1              |
| n = 3   | 6              |
| n = 5   | 15             |
| n = 10  | 55             |

A função recebe um inteiro não-negativo `n` e retorna a soma de todos os naturais de 1 até `n`. Para `n = 0`, o resultado é 0 (caso-base).

---

## Linguagens utilizadas

- **C++** (padrão C++11 ou superior) — todos os programas

---

## Organização dos arquivos

```
.
├── main.cpp                # Menu principal — ponto de entrada do programa
├── monolitico.cpp          # Programa monolítico (uso de goto)
├── iterativo.cpp           # Programa iterativo (while)
├── recursivo.cpp           # Programa recursivo (chamada recursiva)
├── maquina_de_tracos.cpp   # Máquina de Traços + análise de equivalência
└── README.md               # Este arquivo
```

> **Importante:** `main.cpp` inclui os demais arquivos diretamente. Todos os arquivos devem estar na mesma pasta na hora de compilar.

---

## Instruções de compilação e execução

### Pré-requisitos

- Compilador `g++` instalado (GCC 7+ recomendado)
- Terminal Linux, macOS ou Windows com MinGW/WSL

### Compilar

Basta compilar apenas o `main.cpp` — ele já inclui os demais automaticamente:

```bash
g++ main.cpp -o programa
```

### Executar

```bash
./programa
```

No Windows:

```bash
programa.exe
```

---

## Como usar o programa

Ao executar, um menu interativo é exibido:

```
============================================================
   SOMA DOS N PRIMEIROS NATURAIS — Teoria da Computabilidade
============================================================
  1. Programa Monolitico  (uso de goto)
  2. Programa Recursivo   (chamada recursiva)
  3. Programa Iterativo   (laco while)
  4. Maquina de Tracos    (analise de equivalencia)
  5. Encerrar o programa
------------------------------------------------------------
Escolha uma opcao:
```

As opções **1, 2 e 3** pedem um valor de `n` e exibem o resultado da soma junto com métricas de execução. A opção **4** abre um submenu da Máquina de Traços. A opção **5** encerra o programa.

### Exemplo de saída — opção 1 (Monolítico), n = 5

```
=== Programa Monolitico — Soma dos N Primeiros Naturais ===
Digite n: 5
------------------------------------------------------------
Resultado : soma dos 5 primeiros naturais = 15
Passos    : 13 passos executados
           (1 INICIO + 6 TESTES + 5 CORPOS + 1 FIM)
Tempo     : 172 ns  (0.172 us)
------------------------------------------------------------
```

### Submenu — opção 4 (Máquina de Traços)

```
============================================================
   MAQUINA DE TRACOS — Soma dos N Primeiros Naturais
============================================================
  1. Caso de equivalencia forte
  2. Caso de nao-equivalencia
  3. Voltar ao menu principal
------------------------------------------------------------
Escolha uma opcao:
```

---

## Descrição dos programas

### `monolitico.cpp` — Programa Monolítico

Implementa a função usando exclusivamente instruções `goto` e rótulos nomeados, sem estruturas de repetição (`while`, `for`) e sem funções auxiliares. O fluxo de controle é explicitamente definido pelos rótulos:

```
INICIO → TESTE → CORPO → TESTE → ... → FIM
```

| Rótulo   | Descrição |
|----------|-----------|
| `INICIO` | Inicializa `soma = 0` e `i = 1` |
| `TESTE`  | Avalia a condição `i <= n` |
| `CORPO`  | Executa `soma = soma + i` e `i = i + 1` |
| `FIM`    | Exibe o resultado |

### `iterativo.cpp` — Programa Iterativo

Implementa a função com estrutura de repetição `while` explícita dentro da função `soma_iterativa(n)`. A condição de parada é `i > n`.

### `recursivo.cpp` — Programa Recursivo

Implementa a função com chamada recursiva e condição-base explícita:

```
soma_recursiva(0) = 0                          ← condição-base
soma_recursiva(n) = n + soma_recursiva(n - 1)  ← chamada recursiva
```

### `maquina_de_tracos.cpp` — Máquina de Traços

Simula a execução passo-a-passo dos programas, gerando a sequência de estados `(rótulo, i, soma)` para cada passo da computação. Oferece duas análises:

- **Caso 1 — Equivalência forte:** compara monolítico e iterativo, demonstrando que os traços são idênticos passo a passo para qualquer `n`.
- **Caso 2 — Não-equivalência:** compara o monolítico com uma variante que inverte a ordem das operações no CORPO (`i` é incrementado *antes* de ser somado), evidenciando divergência a partir do passo 2.

### `main.cpp` — Menu Principal

Ponto de entrada do programa. Inclui os demais arquivos e chama as funções `rodar_monolitico()`, `rodar_iterativo()`, `rodar_recursivo()` e `menu_maquina_de_tracos()` conforme a opção escolhida pelo usuário.

---

## Métricas de execução

Cada programa (monolítico, iterativo e recursivo) exibe ao final da execução:

- **Número de passos:** quantidade de instruções/rótulos executados durante a computação, contados individualmente (INICIO, TESTE, CORPO, FIM para o monolítico; iterações do laço para o iterativo; chamadas recursivas para o recursivo).
- **Tempo de execução:** medido em nanossegundos (ns) com `std::chrono::high_resolution_clock`, cobrindo apenas o trecho de computação, sem entrada/saída.

### Comparativo de passos para n = 5

| Estilo      | Passos | Detalhamento |
|-------------|--------|--------------|
| Monolítico  | 13     | 1 INICIO + 6 TESTES + 5 CORPOS + 1 FIM |
| Iterativo   | 12     | 1 init + 5 testes verdadeiros + 5 corpos + 1 teste falso |
| Recursivo   | 6      | 6 chamadas: soma(5) até soma(0) |

> O recursivo apresenta menos passos contáveis porque cada chamada engloba o teste da condição-base e a operação em uma única unidade. Na prática, ele consome mais memória por manter uma pilha de `n + 1` chamadas ativas simultaneamente.

---

## Conceitos aplicados

**Programa monolítico:** programa sem estruturas de controle de alto nível; o fluxo é controlado por rótulos e saltos (`goto`), correspondendo diretamente à definição formal da disciplina.

**Programa iterativo:** programa que expressa repetição por meio de estruturas de laço (`while`, `for`), com estado atualizado a cada iteração.

**Programa recursivo:** programa que se define em termos de si mesmo, com uma condição-base que garante a terminação.

**Equivalência forte:** dois programas são fortemente equivalentes se, para toda entrada, produzem a mesma sequência de estados internos — não apenas o mesmo resultado final. A verificação é feita pela Máquina de Traços.

**Máquina de Traços:** método formal que, dado um programa e uma entrada, produz a cadeia/rastro de execução. A comparação dos rastros permite verificar equivalência forte ou identificar exatamente o ponto de divergência.

---

## Uso de Inteligência Artificial

| Ferramenta | Finalidade | Trechos utilizados | Revisão da equipe |
|------------|------------|-------------------|-------------------|
| Claude (Anthropic) |Estrutura do README |`README.md` | Revisão de lógica, verificação dos traços, conferência dos comentários formais e adequação ao conteúdo da disciplina |

Todos os trechos gerados foram revisados e validados pela equipe antes da submissão. A responsabilidade sobre o conteúdo entregue e apresentado é integralmente da equipe.