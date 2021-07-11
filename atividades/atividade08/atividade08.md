# Atividade08 da disciplina de Compiladores
# Semestre 2021.1


## Aluno:     Alysson Alexandre de Oliveira Araújo
## Matrícula: 474084
## Professor: João Marcelo

#


<table style="width:100%">
  <tr>
    <th>Firstname</th>
    <th>Lastname</th>
    <th>Age</th>
  </tr>
  <tr>
    <td>Jill</td>
    <td>Smith</td>
    <td>50</td>
  </tr>
  <tr>
    <td>Eve</td>
    <td>Jackson</td>
    <td>94</td>
  </tr>
</table>



<br>
<br>
<br>
<br>


## Questão 01 - 1,5 Pontos
Considere a gramática a seguir de declarações simplificadas em C:

~~~~
declaração -> tipo var-lista
tipo -> int | float
var-lista -> identificador, var-lista | identificador
~~~~

1. Fatore essa gramática à esquerda
 
2. Construa os conjuntos Primeiro e de Sequência para os não-terminais da gramática resultante.

3. Mostre que a gramática resultante é LL(1).

4. Construa a tabela de análise sintática LL(1) para a gramática resultante.

5. Mostre as ações do analisador sintático LL(1) correspondente, para a cadeia de entrada int x, y, z

<br>
<br>
<br>
<br>

Reposta 1.1 - Fatore essa gramática à esquerda: 

Dando uma breve análise na gramática da questão, vimos que a transição **var-lista** possui o mesmo prefixo entre as suas alternativas, no caso seria o prefixo *identificador*, que impossibilitando a escolha da produção correta. Para fazer a fatoração dessa gramática, vamos considerar o seguinte:

A -> αβ|αγ

Onde:

* A = var-lista 
* α = identificador
* β = , var-lista
* γ = ε

(Vale ressaltar que o ',' precisa estar presente em β para que a fatoração ocorra com sucesso)

A solução para isso é transformar em:
* A -> αA'
* A' -> β|γ

Onde A' = var-lista'

Aplicando os valores nessas transformações, teremos no final:

* var-lista -> identificador A'
* var-lista' -> , var-lista | ε



#

Reposta 1.2 - Construa os conjuntos Primeiro e de Sequência para os não-terminais da gramática resultante.

Conjuntos Primeiro em tabela:

início:
- P(declaração) = Ø
- P(tipo) = Ø
- P(var-lista) = Ø
- P(var-lista') = Ø
- P(int) = {int}
- P(float) = {float}
- P(identificador) = {identificador}
- P(ε) = {ε}
- P(,) = {,}


~~~~
declaração -> tipo var-lista
tipo -> int | float
var-lista -> identificador var-lista'
var-lista' -> , var-lista | ε
~~~~

<table style="width:100%">
  <tr>
    <th>Regras</th>
    <th>1º</th>
    <th>2º</th>
    <th>3º</th>
  </tr>
  <tr>
    <td>declaração->tipo var-lista</td>
    <td></td>
    <td>P(declaração) = {+, -}
    </td>
    <td></td>
  </tr>
  <tr>
    <td>tipo -> int</td>
    <td>P(tipo)={int}</td>
    <td></td>
    <td></td>
  </tr>
  <tr>
    <td>tipo -> float</td>
    <td>P(tipo)={int, float}</td>
    <td></td>
    <td></td>
    
  </tr>
  <tr>
    <td>var-lista -> identificador var-lista'</td>
    <td>P(var-lista) = {identificador}</td>
    <td></td>
    <td></td>
  </tr>
  <tr>
    <td>var-lista' -> , var-lista</td>
    <td>P( var-lista' ) = { , }</td>
    <td></td>
    <td></td>
  </tr> <tr>
    <td>var-lista' -> ε</td>
    <td>P ( var-lista' ) = { , ,ε }</td>
    <td></td>
    <td></td>
  </tr>
</table>

<br>
<br>
<br>

Conjuntos Sequências em tabela:

<table style="width:100%">
  <tr>
    <th>Regras</th>
    <th>1º</th>
    <th>2º</th>
    <th>3º</th>
  </tr>
  <tr>
    <td>declaração->tipo var-lista</td>
    <td>S(declaração) = {$, int, float, identificador} <br> S(var-lista) = {$, identificador}</td>
    <td>S(var-lista) = {$, identificador, , , ε }</td>
    <td></td>
  </tr>
  <tr>
    <td>tipo -> int</td>
    <td></td>
    <td></td>
    <td></td>
  </tr>
  <tr>
    <td>tipo -> float</td>
    <td></td>
    <td></td>
    <td></td>
    
  </tr>
  <tr>
    <td>var-lista -> identificador var-lista'</td>
    <td>S(var-lista) = { , ,ε }</td>
    <td></td>
    <td></td>
  </tr>
  <tr>
    <td>var-lista' -> , var-lista</td>
    <td></td>
    <td></td>
    <td></td>
  </tr> <tr>
    <td>var-lista' -> ε</td>
    <td></td>
    <td></td>
    <td></td>
  </tr>
</table>


<br>
<br>
<br>
<br>

Resposta 1.3: Mostre que a gramática resultante é LL(1).


...