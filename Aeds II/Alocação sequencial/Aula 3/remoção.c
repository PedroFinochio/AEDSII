#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int chave;
} elemento;

int busca_binaria(elemento lista[], int chave, int tam) {
    int inicio = 0, meio, fim = tam - 1;

    while (inicio <= fim) {
        meio = (inicio + fim) / 2;

        if (lista[meio].chave == chave) {
            return meio;
        } else if (lista[meio].chave < chave) {
            inicio = meio + 1;
        } else {
            fim = meio - 1;
        }
    }

    return -1;
}

int remover(elemento lista[], int tam, int posicao){

    if (posicao >= 0 && posicao < tam){
        for (int i = posicao; i < tam - 1; i++){
            lista[i] = lista[i + 1];
        }
        return tam - 1;
    }
    return tam;
}

int main() {
    elemento lista[10] = {{-2}, {2}, {4}, {6}, {11}, {12}, {14}, {16}, {20}, {50}};
    int valor, posicao_remover;

    printf("-----Lista-----\n");
    for (int i = 0; i < 10; i++) {
        printf("%d ", lista[i].chave);
    }
    printf("\n");

    printf("Digite um valor para buscar no vetor: ");
    scanf("%d", &valor);

    int retorno = busca_binaria(lista, valor, 10);

    if (retorno != -1) {
        printf("%d encontrado na posição %d\n", valor, retorno);
    } else {
        printf("Esse elemento não está presente no vetor\n");
    }

    printf("Digite a posição do valor que deseja remover: ");
    scanf("%d", &posicao_remover);

    int novo_tamanho = remover(lista, 10, posicao_remover);

    printf("-----Lista Atualizada-----\n");
    for (int i = 0; i < novo_tamanho; i++) {
        printf("%d ", lista[i].chave);
    }
    printf("\n");

    return 0;
}
