#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int tam = 1000;

// Funções auxiliares
int pai(int i) {
    return (i - 1) / 2;
}

int filho_esq(int i) {
    return (2 * i) + 1;
}

int filho_dir(int i) {
    return (2 * i) + 2;
}

void swap(int *filho, int *pai) {
    int tmp = *filho;
    *filho = *pai;
    *pai = tmp;
}

// Função para inserir um elemento no heap
void insere(int *n, int h[tam], int k) {
    if (*n == tam) {
        printf("Overflow, não foi possível inserir o valor.\n");
        return;
    }

    (*n)++;
    int i = (*n) - 1;
    h[i] = k;

    while (i != 0 && h[pai(i)] > h[i]) {
        swap(&h[i], &h[pai(i)]);
        i = pai(i);
    }
}

// Função para garantir que a raiz seja o valor mínimo
void minimizar(int i, int n, int h[tam]) {
    int e = filho_esq(i);
    int d = filho_dir(i);
    int min = i;

    if (e < n && h[e] < h[min]) {
        min = e;
    }
    if (d < n && h[d] < h[min]) {
        min = d;
    }
    if (min != i) {
        swap(&h[i], &h[min]);
        minimizar(min, n, h);
    }
}

// Função para remover a raiz
int remove_raiz(int *n, int h[tam]) {
    if (*n <= 0) {
        return INT_MAX;
    }

    if (*n == 1) {
        (*n)--;
        return h[0];
    }

    int raiz = h[0];
    h[0] = h[(*n) - 1];
    (*n)--;
    minimizar(0, *n, h);
    return raiz;
}

// Função para imprimir o heap
void imprimeheap(int n, int h[tam]) {
    if (n == 0) {
        printf("Heap está vazio.\n");
        return;
    }

    printf("Heap atual: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", h[i]);
    }
    printf("\n");
}

// Função para limpar o heap
void limpar_heap(int *n) {
    *n = 0;
    printf("Heap foi limpo.\n");
}

int main() {
    int h[tam];
    int n = 0; // Tamanho atual do heap
    int opcao, valor;

    while (1) {
        printf("\nEscolha uma opcao:\n");
        printf("1 - Adicionar elemento\n");
        printf("2 - Remover elemento minimo\n");
        printf("3 - Exibir heap\n");
        printf("4 - Limpar heap\n");
        printf("5 - Sair\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite o valor a ser inserido: ");
                scanf("%d", &valor);
                insere(&n, h, valor);
                break;
            case 2:
                valor = remove_raiz(&n, h);
                if (valor == INT_MAX) {
                    printf("Heap está vazio.\n");
                } else {
                    printf("Elemento removido: %d\n", valor);
                }
                break;
            case 3:
                imprimeheap(n, h);
                break;
            case 4:
                limpar_heap(&n);
                break;
            case 5:
                printf("Saindo...\n");
                return 0;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    }
    return 0;
}
