/*
função busca-ord(x)
L[n+1].chave := x; i := 1;
enquanto L[i].chave < x faça
i := i + 1
se i = n + 1 ou L[i].chave ≠ x então
busca-ord := 0
senão busca-ord := i
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int chave;
}no;

int busca_ordenada(no lista[], int x, int tam){

    lista[tam].chave = x;
    int i = 0;

    while (lista[i].chave < x){
        i++;
    }

    if (i == tam || lista[i].chave != x){
        return -1;
    }
    else{
        return i;
    }
}

int main (){

    no lista[7] = {{1}, {6}, {8}, {17}, {22}, {40}, {89}};
    int valor, retorno;

    printf ("Digite um valor para buscar no vetor: ");
    scanf ("%d", &valor);

    retorno = busca_ordenada (lista, valor, 7);

    if (retorno != -1){
        printf ("%d encontrado na posição %d.\n", valor, retorno);
    }else {
        printf ("Esse elemento não está presente no vetor.\n");
    }

    return 0;
}