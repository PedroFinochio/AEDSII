#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int tam = 200;

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

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

// Função para inserir um elemento no heap
void insere(int *n, int h[tam], int k) {
    if (*n == tam) {
        printf("Heap cheio! Não é possível inserir o elemento.\n");
        return;
    }

    (*n)++;
    int i = (*n) - 1;
    h[i] = k;

    while (i != 0 && h[pai(i)] < h[i]) {
        swap(&h[i], &h[pai(i)]);
        i = pai(i);
    }
}

// Função para maximizar o heap
void maximizar(int i, int n, int h[tam]) {
    int e = filho_esq(i);
    int d = filho_dir(i);
    int max = i;

    if (e < n && h[e] > h[max]) {
        max = e;
    }
    if (d < n && h[d] > h[max]) {
        max = d;
    }
    if (max != i) {
        swap(&h[i], &h[max]);
        maximizar(max, n, h);
    }
}

// Função para remover o maior elemento (raiz) do heap
int remove_raiz(int *n, int h[tam]) {
    if (*n <= 0) {
        printf("Heap vazio! Não há elementos para remover.\n");
        return INT_MIN;
    }

    if (*n == 1) {
        (*n)--;
        return h[0];
    }

    int raiz = h[0];
    h[0] = h[(*n) - 1];
    (*n)--;

    maximizar(0, *n, h);
    return raiz;
}

// Função para construir um heap a partir de um array desordenado
void construir_heap(int *n, int h[tam]) {
    for (int i = (*n) / 2 - 1; i >= 0; i--) {
        maximizar(i, *n, h);
    }
}

// Função para exibir o conteúdo do heap
void exibir_heap(int n, int h[tam]) {
    printf("Heap: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", h[i]);
    }
    printf("\n");
}

// Função principal para testar o código
int main() {
    int heap[tam];
    int n = 0; // Número atual de elementos no heap

    // Inserindo elementos
    insere(&n, heap, 10);
    insere(&n, heap, 20);
    insere(&n, heap, 15);
    insere(&n, heap, 30);
    insere(&n, heap, 25);
    exibir_heap(n, heap);

    // Removendo o maior elemento (raiz)
    printf("Elemento removido: %d\n", remove_raiz(&n, heap));
    exibir_heap(n, heap);

    // Construindo um heap a partir de um array
    int arr[] = {3, 1, 6, 5, 2, 4};
    n = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < n; i++) {
        heap[i] = arr[i];
    }
    construir_heap(&n, heap);
    exibir_heap(n, heap);

    return 0;
}
