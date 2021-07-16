# Atividade09 da disciplina de Compiladores
# Semestre 2021.1


## Aluno:     Alysson Alexandre de Oliveira Araújo
## Matrícula: 474084
## Professor: João Marcelo

#



## Questão 01 - 1,0 Ponto
Considere a gramática a seguir:

~~~~
E -> (L) | a
L -> L,E | E
~~~~

1. Construa o DFA de itens LR(0) para essa gramática.
2. Mostre a pilha de análise sintática e as ações de um analisador LR(0) para a cadeia de entrada ((a),a,(a,a)). Se você encontrar algum conflito, indique sua natureza para explicar porque a derivação não prossegue.

> Não foi feita a 1.1

> O que fiz foi apenas a 1.2 -> pilha de análise sintática


<br>
<br>
<br>

pilha de análise sintática de ((a),a,(a,a)) usando a gramática:


<br>

~~~~
E -> (L) | a
L -> L,E | E
~~~~

<br>

<table style="width:100%">
  <tr>
    <th></th>
    <th>Pilha de Análise Sintática</th>
    <th>Entrada</th>
    <th>Ação</th>
  </tr>
  <tr>
    <td>1</td>
    <td>$</td>
    <td>((a),a,(a,a))$</td>
    <td>carrega</td>
  </tr>
  <tr>
    <td>2</td>
    <td>$(</td>
    <td>(a),a,(a,a))$</td>
    <td>carrega</td>
  </tr>
  <tr>
    <td>3</td>
    <td>$((</td>
    <td>a),a,(a,a))$</td>
    <td>carrega</td>
  </tr>
  <tr>
    <td>4</td>
    <td>$((a</td>
    <td>),a,(a,a))$</td>
    <td>reduz E -> a</td>
  </tr>
  <tr>
    <td>5</td>
    <td>$((E</td>
    <td>),a,(a,a))$</td>
    <td>reduz L -> E</td>
  </tr>
  <tr>
    <td>6</td>
    <td>$((L</td>
    <td>),a,(a,a))$</td>
    <td>carrega</td>
  </tr>
  <tr>
    <td>7</td>
    <td>$((L)</td>
    <td>,a,(a,a))$</td>
    <td>reduz E -> (L)</td>
  </tr>
  <tr>
    <td>8</td>
    <td>$(E</td>
    <td>,a,(a,a))$</td>
    <td>reduz L -> E</td>
  </tr>
  <tr>
    <td>9</td>
    <td>$(L</td>
    <td>,a,(a,a))$</td>
    <td>carrega</td>
  </tr>
    <td>10</td>
    <td>$(L,</td>
    <td>a,(a,a))$</td>
    <td>carrega</td>
  </tr>
  </tr>
    <td>11</td>
    <td>$(L,a</td>
    <td>,(a,a))$</td>
    <td>reduz E -> a</td>
  </tr>
  </tr>
    <td>12</td>
    <td>$(L,E</td>
    <td>,(a,a))$</td>
    <td>reduz L -> L,E</td>
  </tr>
  </tr>
    <td>13</td>
    <td>$(L</td>
    <td>,(a,a))$</td>
    <td>carrega</td>
  </tr>
  </tr>
    <td>14</td>
    <td>$(L,</td>
    <td>(a,a))$</td>
    <td>carrega</td>
  </tr>
  </tr>
    <td>15</td>
    <td>$(L,(</td>
    <td>a,a))$</td>
    <td>carrega</td>
  </tr>
  </tr>
    <td>16</td>
    <td>$(L,(a</td>
    <td>,a))$</td>
    <td>reduz E -> a</td>
  </tr>
  </tr>
    <td>17</td>
    <td>$(L,(E</td>
    <td>,a))$</td>
    <td>reduz L -> E</td>
  </tr>
  </tr>
    <td>18</td>
    <td>$(L,(L</td>
    <td>,a))$</td>
    <td>carrega</td>
  </tr>
  </tr>
    <td>19</td>
    <td>$(L,(L,</td>
    <td>a))$</td>
    <td>carregar</td>
  </tr>
  </tr>
    <td>20</td>
    <td>$(L,(L,a</td>
    <td>))$</td>
    <td>reduz E -> a</td>
  </tr>
  </tr>
    <td>21</td>
    <td>$(L,(L,E</td>
    <td>))$</td>
    <td>reduz L -> L,E</td>
  </tr>
  </tr>
    <td>22</td>
    <td>$(L,(L</td>
    <td>))$</td>
    <td>carrega</td>
  </tr>
  </tr>
    <td>23</td>
    <td>$(L,(L)</td>
    <td>)$</td>
    <td>reduz E -> (L)</td>
  </tr>
  </tr>
    <td>24</td>
    <td>$(L,E</td>
    <td>)$</td>
    <td>reduz L -> L,E</td>
  </tr>
  </tr>
    <td>25</td>
    <td>$(L</td>
    <td>)$</td>
    <td>carrega</td>
  </tr>
  </tr>
    <td>26</td>
    <td>$(L)</td>
    <td>$</td>
    <td>reduz E -> (L)</td>
  </tr>
  </tr>
    <td>27</td>
    <td>$E</td>
    <td>$</td>
    <td>aceita</td>
  </tr>
  

</table>
