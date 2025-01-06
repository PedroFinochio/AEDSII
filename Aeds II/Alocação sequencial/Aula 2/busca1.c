#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
    int chave;
} no;

int busca1(no lista[], int x, int tam)
{
    int i = 0;

    while (i < tam){
        if(lista[i].chave == x){
            return i;
        }
        i++;
    }
    return -1;
}

int main()
{
    no lista[5] = {{2}, {5}, {7}, {11}, {12}};
    int valor, retorno;

    printf("Digite um valor a ser buscado no vetor: ");
    scanf("%d", &valor);

    retorno = busca1(lista, valor, 5);

    if (retorno == -1)
    {
        printf("Esse elemento não está presente no vetor.\n");
    }
    else
    {
        printf("%d encontrado na posição %d\n", valor, retorno);
    }

    return 0;
}
