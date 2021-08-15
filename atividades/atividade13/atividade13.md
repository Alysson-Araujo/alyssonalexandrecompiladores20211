# Atividade13 da disciplina de Compiladores
# Semestre 2021.1


## Aluno:     Alysson Alexandre de Oliveira Araújo
## Matrícula: 474084
## Professor: João Marcelo

#

Questão 01 - 1,0 Ponto
Considere a gramática a seguir para árvores binárias de inteiros (em forma linearizada):

<br>

~~~~

bárvore -> (número bárvore bárvore) | nil

~~~~

<br>

Escreva uma gramática de atributos para verificar se uma árvore binária está ordenada, ou seja, se os valores dos números da primeira subárvore são menor ou igual ao valor do número corrente e os valores dos números da segunda árvore são maiores ou iguais ao valor do número corrente. Por exemplo, (2 (1 nil nil) (3 nil nil)) está ordenada, mas (1 (2 nil nil) (3 nil nil)) não está.


<br>
<br>
<br>

Resposta:



Minha ideia é criar duas funções:

- _menorQueNode_ 
- _maiorQueNode_

<br>

**O atributo val é o valor que o nó atual possui.** 

<br>

A função _menorQueNode_ recebe dois parâmetros (o número1 e a número2) e retorna o número2 se o seu val for menor que o val do número1, no caso o número corrente. Se ele não retornar o número2, então a árvore em si está desbalanceada.


A função _maiorQueNode_ recebe dois parâmetros (o número1 e o número2) e retorna o número2 se  o seu val  for maior que o  val do número1, no caso o número corrente. Se ele não retornar o número2, então a árvore em si está desbalanceada.

<br>
<br>
<br>

Vamos construir a gramática de atributos da gramática mostrada no enunciado.


~~~~

bárvore1.val = (número1.val bárvore2.val bárvore3.val )


bárvore1.val = (número1.val  (menorQueNode(número1.val número2.val) bárvore2.val bárvore3.val ) maiorQueNode(número1.val número3.val) bárvore4.val bárvore5.val )


bárvore.val = nil

~~~~

<br>
<br>
<br>


Por exemplo temos a seguinte árvore:

(2 (1 nil nil) (3 nil nil))

<br>
<br>

Usamos a gramática de atributos vamos ter o seguinte:

Vamos começar chamando o bárvore -> (número bárvore bárvore) e depois desenvolvemos ela usando as derivações necessárias e as funções em si:

~~~~

bárvore1.val -> (número1.val=2 bárvore2.val bárvore3.val)


bárvore1.val -> (número1.val=2 (número2.val=1 bárvore4.val bárvore5.val) bárvore3.val


bárvore1.val -> (número1.val=2 (número2.val=1 bárvore4.val bárvore5.val) (número3.val=3 bárvore6.val bárvore7.val)


bárvore1.val -> (número1.val=2 ( (menorQueNode(número1.val=2 número2.val=1) bárvore4.val bárvore5.val) ( maiorQueNode(número1.val=2 número3.val=3) bárvore6.val bárvore7.val)))


bárvore1.val -> (número1.val=2 ( número2.val=1 bárvore4.val bárvore5.val) ( maiorQueNode(número1.val=2 número3.val=3) bárvore6.val bárvore7.val))


bárvore1.val -> (número1.val=2 ( número2.val=1 bárvore4.val=nil bárvore5.val) ( maiorQueNode(número1.val=2 número3.val=3) bárvore6.val bárvore7.val))


bárvore1.val -> (número1.val=2 ( número2.val=1 bárvore4.val=nil bárvore5.val=nil) ( maiorQueNode(número1.val=2 número3.val=3) bárvore6.val bárvore7.val))


bárvore1.val -> (número1.val=2 ( número2.val=1 bárvore4.val=nil bárvore5.val=nil) (número3.val bárvore6.val bárvore7.val))


bárvore1.val -> (número1.val=2 ( número2.val=1 bárvore4.val=nil bárvore5.val=nil) (número3.val bárvore6.val=nil bárvore7.val))


bárvore1.val -> (número1.val=2 ( número2.val=1 bárvore4.val=nil bárvore5.val=nil) (número3.val bárvore6.val=nil bárvore7.val=nil))

~~~~

<br>
<br>


Como podemos observar o resultado final, vemos que as regras as funções retornaram o números corretos, logo essa árvore é balanceada.







