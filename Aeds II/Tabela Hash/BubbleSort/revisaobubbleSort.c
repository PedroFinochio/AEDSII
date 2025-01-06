#include <stdio.h>
#include <stdbool.h>

void swap (int *x, int *y){
    int tmp = *x;
    *x = *y;
    *y = tmp;
}

void bubbleSort(int arr[], int n){
    
   bool swapped;
   for(int i = 0; i < n - 1; i++){
    swapped = false;
    for(int j = 0; j < n - i - 1; j++){
        if (arr[j] > arr[j + 1]){
            swap(&arr[j],&arr[j + 1]);
            swapped = true;
        }
    }
    if (swapped == false){
        break;
    }
   }
}

void printArray(int arr[], int size){
    for (int i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }
}

int main(){
    int arr[] = {8,3,7,1,5,9,2,6,10,4};
    int n = sizeof(arr) / sizeof(arr[0]);
    bubbleSort(arr, n);
    printf("Vetor ordenado: \n");
    printArray(arr, n);
    printf("\n");
    return 0;
}