# Atividade06 da disciplina de Compiladores
# Semestre 2021.1


## Aluno:     Alysson Alexandre de Oliveira Araújo
## Matrícula: 474084
## Professor: João Marcelo

#



<br>
<br>
<br>

<br>
<br>
<br>
<br>
<br>
<br>

### Questão 01 - 1,0 Ponto

Dada a gramática:


~~~~
declaração -> atribuição-decl | ativação-decl | outra
atribuição-decl -> identificador := exp
ativação-decl -> identificador ( exp-lista )
~~~~

<br>


Os símbolos outra, identificador, : e = são terminais, os outros são não terminais.

Escreva o pseudocódigo para analisar essa gramática de forma descendente recursiva. Você pode usar C ou a linguagem baseada em Pascal que o autor utiliza. Considere que já existem procedimentos para tratar exp e exp-lista.



<br>
<br>
<br>

Resposta:

Eu iria reescrever a gramática para escrever o pseudocódigo, porém como não estou seguro para fazer isso, preferi não fazer isso para evitar um possível erro no pseudocódigo. Até porquê o senhor comentou que não era algo necessário. Estou aberto para receber comentários do senhor caso eu esteja certo ou errado.

> Correção: 0,5
>
> O problema é que no procedimento declaração, você considera atribuição-decl como uma marca. Mas é óbvio pela gramática que atribuição-decl não pode ser uma marca, visto
> que aparece do lado esquerdo de uma regra. Daí sugiro uma revisão dos conceitos básicos de gramáticas livres de contexto.
> A saída era ler adiante alguns símbolos para decidir qual caminho tomar, depois retornando os símbolos para a entrada permitindo aos outros procedimentos processarem.

```
procedure declaração;
begin
    case marca of
    atribuição-decl:
        atribuição-decl;
    ativação-decl:
        ativação-decl;
    outra:
        casamento(outra);
    else:
        erro;
    end case;
end feclaração;

procedure atribuição-decl;
begin
    casamento(identificador);
    casamento(:);
    casamento(=);
    exp;
end atribuição-decl;

procedure ativação-decl;
begin
    casamento(identificador);
    casamento(();
    exp-lista;
    casamento());
end ativação-decl;
```


