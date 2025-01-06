#include <stdbool.h>
#include <stdio.h>

int comparacoes = 0, trocas = 0;

// Função para trocar dois elementos
void swap(int *xp, int *yp) {
    int tmp = *xp;
    *xp = *yp;
    *yp = tmp;
}

// Implementação do Bubble Sort
void bubbleSort(int arr[], int n) {
    int i, j;
    bool swapped;
    for (i = 0; i < n - 1; i++) {
        swapped = false; // Flag para verificar se houve trocas nesta passagem
        for (j = 0; j < n - i - 1; j++) {
            comparacoes++; // Incrementa o número de comparações
            printf("Comparando arr[%d] = %d e arr[%d] = %d\n", j, arr[j], j + 1, arr[j + 1]);
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
                printf("Trocando arr[%d] e arr[%d]\n", j, j + 1);
                trocas++; // Incrementa o número de trocas
                swapped = true; // Marca que houve troca
            }
        }
        if (swapped == false) { // Se nenhuma troca foi feita, interrompe o laço
            break;
        }
    }
}

// Função para imprimir o array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Função principal
int main() {
    int arr[] = {8, 3, 7, 1, 5, 9, 2, 6, 10, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    bubbleSort(arr, 10);
    printf("Vetor ordenado: \n");
    printArray(arr, n);
    printf("Número de comparações necessárias: %d \n", comparacoes);
    printf("Número de trocas realizadas: %d \n", trocas);
    return 0;
}
