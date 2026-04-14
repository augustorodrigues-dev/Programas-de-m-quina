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
├── monolitico.cpp          # Programa monolítico (uso de goto)
├── iterativo.cpp           # Programa iterativo (while)
├── recursivo.cpp           # Programa recursivo (chamada recursiva)
├── maquina_de_tracos.cpp   # Simulador da Máquina de Traços + análise de equivalência
└── README.md               # Este arquivo
```

---

## Instruções de compilação e execução

### Pré-requisitos

- Compilador `g++` instalado (GCC 7+ recomendado)
- Terminal Linux, macOS ou Windows com MinGW/WSL

### Compilar todos os programas

```bash
g++ monolitico.cpp        -o monolitico
g++ iterativo.cpp         -o iterativo
g++ recursivo.cpp         -o recursivo
g++ maquina_de_tracos.cpp -o maquina_de_tracos
```

### Executar

```bash
./monolitico
./iterativo
./recursivo
./maquina_de_tracos
```

Cada programa solicita um valor de `n` via entrada padrão. Exemplo:

```
Digite n: 5
Soma dos 5 primeiros naturais = 15
```

---

## Descrição dos programas

### `monolitico.cpp` — Programa Monolítico

Implementa a função usando exclusivamente instruções `goto` e rótulos nomeados, sem estruturas de repetição (`while`, `for`) e sem funções auxiliares. O fluxo de controle é explicitamente definido pelos rótulos:

```
INICIO → TESTE → CORPO → TESTE → ... → FIM
```

Rótulos utilizados:

| Rótulo | Descrição |
|--------|-----------|
| `INICIO` | Inicializa `soma = 0` e `i = 1` |
| `TESTE`  | Avalia a condição `i <= n` |
| `CORPO`  | Executa `soma = soma + i` e `i = i + 1` |
| `FIM`    | Exibe o resultado |

### `iterativo.cpp` — Programa Iterativo

Implementa a função com estrutura de repetição `while` explícita dentro de uma função separada `soma_iterativa(n)`. A condição de parada é `i > n`.

### `recursivo.cpp` — Programa Recursivo

Implementa a função com chamada recursiva e condição-base explícita:

```
soma_recursiva(0) = 0                          ← condição-base
soma_recursiva(n) = n + soma_recursiva(n - 1)  ← chamada recursiva
```

### `maquina_de_tracos.cpp` — Máquina de Traços

Simula a execução passo-a-passo dos programas monolítico e iterativo, gerando a sequência de estados `(rótulo, i, soma)` para cada passo da computação. Realiza duas análises:

- **Caso 1 — Equivalência forte:** compara monolítico e iterativo, demonstrando que os traços são idênticos passo a passo para qualquer `n`.
- **Caso 2 — Não-equivalência:** compara o monolítico com uma variante que inverte a ordem das operações no CORPO (`i` é incrementado *antes* de ser somado), evidenciando divergência a partir do passo 2.

---

## Conceitos aplicados

**Programa monolítico:** programa sem estruturas de controle de alto nível; o fluxo é controlado por rótulos e saltos (`goto`), correspondendo diretamente à definição formal de programa monolítico da disciplina.

**Programa iterativo:** programa que expressa repetição por meio de estruturas de laço (`while`, `for`), com estado atualizado a cada iteração.

**Programa recursivo:** programa que se define em termos de si mesmo, com uma condição-base que garante a terminação.

**Equivalência forte:** dois programas são fortemente equivalentes se, para toda entrada, produzem a mesma sequência de estados internos — não apenas o mesmo resultado final. A verificação é feita pela Máquina de Traços.

**Máquina de Traços:** método formal que, dado um programa e uma entrada, produz a cadeia/rastro de execução. A comparação dos rastros permite verificar equivalência forte ou identificar exatamente o ponto de divergência.

---

## Uso de Inteligência Artificial

| Ferramenta | Finalidade | Trechos utilizados | Revisão da equipe |
|------------|------------|-------------------|-------------------|
| Claude (Anthropic) | Estrutura do README | `README.md` | Revisão de lógica, verificação dos traços, conferência dos comentários formais e adequação ao conteúdo da disciplina |

Todos os trechos gerados foram revisados e validados pela equipe antes da submissão. A responsabilidade sobre o conteúdo entregue e apresentado é integralmente da equipe.