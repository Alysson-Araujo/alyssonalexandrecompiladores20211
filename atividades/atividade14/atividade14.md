# Atividade14 da disciplina de Compiladores
# Semestre 2021.1


## Aluno:     Alysson Alexandre de Oliveira Araújo
## Matrícula: 474084
## Professor: João Marcelo

#

<br>

Questão 01 - 1,5 Pontos
Considere a gramática a seguir para declarações simples em Pascal:

~~~~
decl -> var-lista : tipo
var-lista -> var-lista, id | id
tipo -> integer | real
~~~~


Reescreva a gramática para que o tipo de uma variável possa ser definido como um atributo puramente sintetizado ou apenas herdado entre irmãos (nunca entre pai e filhos) e apresente uma nova gramática de atributos que tenha essa propriedade.   

<br>
<br>
<br>

Resposta :

<br>
<br>

A princípio, irei construir uma gramática de atributos para colocar um tipo em varivável.

O atriburo que irei usar chama-se declTipo, que vai guardar o tipo da decl.

<br>

Segue agora a gramática de atributos:




<table style="width:100%">
  <tr>
    <th>Regra Gramatical</th>
    <th>Regra Semântica</th>
  </tr>
 
 <tr>
    <th>decl -> var-lista : tipo</th>
    <th>var.declTipo = tipo.declTipo</th>
  </tr>

  <tr>
    <th>var-lista1 -> var-lista2, id</th>
    <th>var-lista2.declTipo = var-lista1.declTipo</th>
  </tr>
  <tr>
    <th>var-lista-> id</th>
    <th>id.declTipo = var-lista.declTipo</th>
  </tr>
  <tr>
    <th>tipo -> integer</th>
    <th>tipo.declTipo = integer</th>
  </tr>
  <tr>
    <th>tipo -> real</th>
    <th>tipo.declTipo = real</th>
  </tr>

</table>


<br>
<br>
<br>
<br>

Fiz essa construção para ter uma noção do que devo fazer na gramática, no caso de algumas modificações.

Agora, precisamos fazer uma pequena mudança na gramática para que seja definido um atributo puramente sintetizado. Para isso, eu fiz modificações na Regra gramatical para que isso seja possível. Podemos ver que na regra **var-lista -> var-lista, id | id** temos duas alternativas, onde não possui caminhos para ter um atributo puramente sintetizado. Com essa regra + o tipo presente na gramática, vou modificar a var-lista e decl. Em decl colocarei um id na regra e vou chamar uma nova regra de **new-varlista** e o **: tipo** irei passar como sendo uma alternativa para **new-varlista** ficando com a regra gramatical da seguinte forma:

~~~~
decl -> id new-varlista 
new-varlista1 ->  , id new-varlista2 | : tipo
tipo -> integer | real 
~~~~

<br>
<br>
<br>

Coloquei o new-varlist2 após o *, id* na regra **new-varlista1 ->  , id new-varlista2** pois eu coloquei um id como sendo um filho de decl. Se eu não fizesse isso, poderia ocorrer problemas na gramática para determinados números. Para concluir, segue abaixo a regra semântica dessa gramática:

<table style="width:100%">
  <tr>
    <th>Regra Gramatical</th>
    <th>Regra Semântica</th>
  </tr>
 <tr>
    <th>decl -> id new-varlista</th>
    <th>id.declTipo = new-varlista</th>
  </tr>
  <tr>
    <th>new-varlista1 ->  , id new-varlista2</th>
    <th>new-varlista1.declTipo = rest2.declTipo
        <br>
        id.declTipo = rest2.declTipo
    </th>
  </tr>
  <tr>
    <th>new-varlista -> : tipo</th>
    <th>new-varlista.declTipo = tipo.declTipo</th>
  </tr>
  <tr>
    <th>tipo -> integer</th>
    <th>tipo.declTipo = integer</th>
  </tr>
  <tr>
    <th>tipo -> real</th>
    <th>tipo.declTipo = real</th>
  </tr>

</table>

<br>
<br>
<br>

**As duas últimas regras ocorrem sintetização**
