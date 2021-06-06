
{Programa de exemplo nalinguagem TINY - computa o fatorial}

read x;{entrada de um inteiro}
if 0 < x then{ n~ao calcula se x <= 0}
    fact := 1;
    repeat
        fact := fact * x;
        x := x - 1;until x = 0;write fact{sa ́ıda do fatorial de x}end