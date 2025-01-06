/*
função busca(x)
L[n+1].chave := x; i := 1;
enquanto L[i].chave ≠ x faça
i := i + 1
se i ≠ n + 1 então
busca := i
senão busca := 0
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct no //criando uma struct que tem o conteúdo de uma chave que é referenciada por cada elemento dentro do vetor (cada elemento possui a sua chave)
{
    int chave;
} no;

int busca(no lista[], int x, int tam){

    lista[tam].chave = x;
    int i = 0;

    while (lista[i].chave != x){
        i++;
    }

    if (i < tam){
        return i;
    }else {
        return -1;
    }
}

int main()
{

    no lista[7] = {{1}, {2}, {5}, {7}, {6}, {4}, {9}};
    int valor, retorno;

    printf("Digite um valor a ser buscado no vetor: ");
    scanf("%d", &valor);

    retorno = busca(lista, valor, 7);

    if(retorno != -1){
    printf("%d encontrado no vetor na posição %d.\n", valor, retorno);
    }else {
        printf ("Esse elemento nã esta presente no vetor.\n");
    }

    return 0;
}