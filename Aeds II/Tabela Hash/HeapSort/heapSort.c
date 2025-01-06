#include <stdio.h>

void heapify (int arr[], int n, int i){

    int largest = i;

    int l = 2 * i + 1; // operação para encontrar o filho esquerdo

    int r = 2 * i + 2; // operação para encontrar  filho direito

    if (l < n && arr[l] > arr[largest]){
        largest = l;
    }

    if (r < n && arr[r] > arr[largest]){
        largest = r;
    }

    if (largest != i){
        int tmp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = tmp;

        heapify (arr, n, largest);
    }
}

void heapSort (int arr[], int n){

    for (int i = n / 2 - 1; i >= 0; i--){
        heapify(arr, n, i);
    }

    for (int i = n - 1; i > 0; i--){
        int tmp = arr[0];
        arr[0] = arr[i];
        arr[i] = tmp;

        heapify (arr, i, 0);
    }
}

void printArray (int arr[], int n){
    for (int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main (){

    int arr[] =  {88, 15, 47, 92, 6, 31, 70, 53, 24, 81};
    int n = sizeof(arr) / sizeof(arr[0]);

    heapSort(arr, n);

    printf("Vetor ordenado: \n");
    printArray(arr, n);

    return 0;
}