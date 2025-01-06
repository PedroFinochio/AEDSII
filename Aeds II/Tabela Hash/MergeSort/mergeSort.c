/*

É um algoritmo de classificação que segue a abordagem de dividir e conquistar. Ele funciona dividindo recursivamente a matriz de entrada 
em subarrays menores e classificando esses subarrays e, em seguida, fundindo-os de volta para obter a matriz ordenada.

Em termos simples, podemos dizer que o processo de mesclagem é dividir a matriz em duas metades, classificar cada metade e, em seguida, 
mesclar as metades ordenadas novamente. Este processo é repetido até que todo o array seja classificado. 

1.Divida: Divida a lista ou matriz recursivamente em duas metades até que ela não possa mais ser dividida.
2.Conquista: Cada subarray é classificado individualmente usando o algoritmo de classificação de mesclagem.
3.Mesclar: Os subarrays classificados são fundidos de volta em ordem ordenada. O processo continua até que todos os elementos de ambos 
os subarranjos tenham sido fundidos. 

*/

#include <stdio.h>
#include <stdlib.h>

int comparacoes = 0;

void merge(int arr[], int l, int m, int r) { // função para unir 2 listas ordenadas; l = limite esquerda, m = meio e r = limite direita
    int i, j, k;
    int n1 = m - l + 1; // n1 = número de elementos na sublista esquerda
    int n2 = r - m; // n2 = número de elementos na sublista direita
    int L[n1], R[n2]; // L e R =  vetores temporários que armazenam temporariamente elementos da sublista esquerda e direita respectivamente
    
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i]; // copia os elementos da sublista esquerda do vetor original para o vetor L
    for (j = 0; j < n2; j++) // copia os elementos da sublista direita do vetor original para o vetor R 
        R[j] = arr[m + 1 + j];
    
    i = 0; // índice do vetor temporário L 
    j = 0; // índice do vetor temporário R
    k = l; // índice do vetor original 
    
    while (i < n1 && j < n2) { // compara os elementos de L e R  
        comparacoes++;
        if (L[i] <= R[j]) {
            arr[k] = L[i]; // menor elemento é colocado na posição atual de arr[k]
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    
    while (i < n1) { // insere os elementos remanescentes de L para o vetor original 
        arr[k] = L[i];
        i++;
        k++;
    }
    
    while (j < n2) { // insere os elementos remanescentes de R para o vetor original  
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) { // verifica se a sublista contém mais de 1 elemento 
        int m = l + (r - l) / 2; // calcula o meio para dividir o vetor 
        mergeSort(arr, l, m); // repartição da lista 
        mergeSort(arr, m + 1, r); // repartição da lista 
        merge(arr, l, m, r); // união da lista 
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {58, 7, 93, 24, 15, 81, 42, 36, 12, 69};
    int arr_size = sizeof(arr) / sizeof(arr[0]);
    
    mergeSort(arr, 0, arr_size - 1);
    
    printf("Vetor ordenado: \n");
    printArray(arr, arr_size);
    
    printf("Número de comparações: %d\n", comparacoes);
        
    return 0;
}