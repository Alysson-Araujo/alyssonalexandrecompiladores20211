# Atividade15 da disciplina de Compiladores
# Semestre 2021.1
> Correção: 2,0
> 
> O problema da sua solução, que é comum em boa parte das atividades que estou corrigindo, é que você tem um atributo cujo tipo é mutante.
> val às vezes é valor, às vezes é booleano. Daria para implementar como união nas linguanges de programação, mas do jeito que está apresentado, fica incompleto.

## Aluno:     Alysson Alexandre de Oliveira Araújo
## Matrícula: 474084
## Professor: João Marcelo

#



Questão 01 - 3,0 Pontos
Considere a seguinte gramática da seção 6.3.5:

~~~~
S -> exp
exp -> (exp) | exp + exp | id | num | let dec-lista in exp
dec-lista -> dec-lista, decl | decl
decl -> id = exp
~~~~



Escreva uma gramática de atributos para computar o valor de cada expressão dessa gramática.

<br>
<br>
<br>
<br>

Resposta:

<br>
<br>
<br>

Antes de apresentar a tabela, vou colocar Objetivos da Tabela de Símbolos, para ter uma noção do que irei fazer para computar cada expressão. Não necessariamente usarei todos.

<br>
<br>


- atributo booleano sintetizado err(true expressão errada,false caso contrário);

- atributo herdado simtab para representar a tabela;

-atributo herdado nivelaninh, para identificar o nível do bloco;

-inserir(s,n,l) retorna uma nova tabela de s ́ımbolos que contém todas as informações de s, mas com o nome n associado ao nível _I_ ;

- estaem(s,n) verdadeiro ou falso se n está em s ou não;

- verificar(s,n) retorna o aninhamento denems

<br>

**Eu me fundamentei na tabela 6.9 do livro para fazer essa questão e exemplos vistos em outros documentos encontrados na Internet**

<br>
<br>
<br>

<table style="width:100%">
  <tr>
    <th>Regra Gramatical</th>
    <th>Regra Semântica</th>
  
  </tr>
  <tr>
    <th>S -> exp</th>
    <th>S.val = 
            if(exp.err = true) then error
            else exp.val
    </th>

  </tr>
  <tr>  
    <th>exp1 -> (exp2)</th>
    <th>exp1.val = exp2.val</th>
  
  </tr>
  <tr>  
    <th>exp1 -> exp2 + exp3</th>
    <th>exp1.val = <br>
        if((exp1.err = true) or (exp2.err = true)) then error <br>
        else exp2.val + exp3.val
    </th>
  
  </tr>
  <tr>  
    <th>exp -> id</th>
    <th>
    exp.val = not estaem (exp.simtab, id.nome)
    </th>
  </tr>
  <tr>  
    <th>exp -> num</th>
    <th>exp.val = num.val</th>
  
  </tr>
  <tr>  
    <th>exp1 -> let dec-lista in exp2</th>
    <th>exp1.val = <br>
        if(decl.intab = errtab) then error <br>
        else exp2.val
    </th>
  
  </tr>
  <tr>  
    <th>dec-lista1 -> dec-lista2, decl</th>
    <th>dec-lista2.val = if (dec-lista1.val = error) then error else dec-lista1.val</th>
  
  <tr>  
    <th>dec-lista -> decl</th>
    <th>decl.val = if (dec-lista.val = error) then error else dec-lista.val</th>
  
  </tr>
  <tr>  
    <th>decl -> id = exp</th>
    <th>decl.out = <br>
    if((decl.intab = errtab)) then errtab<br>
    else insert(decl.intab,id.name,decl.nextlevel,exp.val)
    </th>
  </tr>

</table>
