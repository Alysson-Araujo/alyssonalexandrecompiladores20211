# Atividade10 da disciplina de Compiladores
# Semestre 2021.1


## Aluno:     Alysson Alexandre de Oliveira Araújo
## Matrícula: 474084
## Professor: João Marcelo

#



## Questão 01 - 2,0 Ponto

Questão 01 - 2,0 Pontos
Considere a gramática de sequências de declarações simplificadas a seguir:

~~~~
decl-sequência -> decl-sequência; decl | decl
decl -> s
~~~~

1. Construa o DFA de itens LR(0) para essa gramática.

2. Construa a tabela de análise sintática SLR(1).

3. Escreva a pilha de análise sintática e as ações para um analisador SLR(1) para a cadeia de entrada s;s;s.

4. Essa gramática é LR(0)? Se não for, identifique o conflito LR(0). Se for, construa a tabela de análise sintática LR(0), e explique como uma análise sintática pode diferir de uma análise SLR(1). Em outras palavras, explique como a análise SLR(1) pode funcionar para uma gramática mesmo que a LR(0) não funcione. Pode fornecer exemplos de gramáticas se desejar.

**Resposta 1.1**

Antes de construir a DFA, precisamos pegar a gramática mostrada no enunciado e aplicar o LR(0) que resulta na seguinte gramática:

<br>

~~~~
decl-sequência' -> .decl-sequência 
decl-sequência' -> decl-sequência. 
decl-sequência -> .decl-sequência; decl
decl-sequência -> decl-sequência.; decl 
decl-sequência -> decl-sequência;. decl 
decl-sequência -> decl-sequência; decl. 
decl-sequência -> .decl 
decl-sequência -> decl. 
decl -> .s 
decl -> s. 
~~~~

<br>

Agora que temos a gramática com LR(0), vamos fazer a construção da DFA:

![DFA](DFA_1_1.png)

<br>
<br>
<br>
<br>

**Resposta 1.2**

<br>
<br>
<br>

Os conjuntos de sequência para os não-terminais são:
- **Sequência(decl-sequência')={$}** e 

- **Sequência(decl-sequência)={$,;}**

A letra c indica uma ação de carregar e a letra r indica uma ação de redução.

Usamos a palavra "aceita" para (decl-sequência' -> decl-sequência) com entrada $.

![tabela1](tabela_1_2.png)

<br>
<br>
<br>

**Resposta 1.3:**