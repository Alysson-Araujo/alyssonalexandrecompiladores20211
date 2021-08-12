# Atividade 12 da disciplina de Compiladores
# Semestre 2021.1
> Correção: 1,0
> 
> Toda regra semântica é associada a uma regra gramatical. Mas do jeito que você colocou, não dá para percebe qual regra semântica está associada a qual regra
> gramatical. Além do mais, as produção que geram épsilon deve criar no atributo valor o elemento neutro das operações.

## Aluno:     Alysson Alexandre de Oliveira Araújo
## Matrícula: 474084
## Professor: João Marcelo

#



Questão 01 - 1,5 Pontos

Considere uma gramática de expressões preparada para um analisador preditivo com a recursão à esquerda removida:

~~~~

exp' -> + termo exp' | - termo exp' | e
termo -> fator termo'
termo'-> * fator termo' | e
fator -> (exp) | número

~~~~

Escreva a gramática de atributos para o valor de uma expressão dada por essa gramática.

<br>
<br>
<br>
<br>

#### Resposta:

Vamos considerar que o atributo **val** represente o valor numérico que atribuímos na expressão. 

Para ter uma visão melhor da gramática eu irei fazer uma pequena organização na gramática ou seja uma mudança apenas visual.

~~~~

exp'   -> + termo exp'
exp'   -> - termo exp' 
exp'   -> e
termo  -> fator termo'
termo' -> * fator termo'
termo' -> e
fator  -> (exp) 
fator  -> número

~~~~

<br>

Feito essa pequena mudança, vamos começar a construção da gramática de atributos a partir dessa gramatática mostrada no enunciado da questão:

~~~~

exp'1.val    = + termo.val exp'2.val 
exp'1.val    = - termo.val exp'2.val 
exp'         = e
termo.val    = fator.val termo'.val
termo'.1.val = * fator.val termo'2.val 
termo'       = e 
fator.val    = exp.val 
fator.val    = número.val

~~~~

