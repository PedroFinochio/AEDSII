#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int tam = 200;

int pai(int i){
    return (i-1) / 2;
}

int filho_esq(int i){
    return (2*i)+1;
}

int filho_dir(int i){
    return (2*i)+2;
}

void swap(int *filho, int *pai){
    int tmp = *filho;
    *filho = *pai;
    *pai = tmp;
}

void insere(int *n, int h[tam], int k){

    if (*n == tam){
        return;
    }

    (*n)++;
    int i = (*n) - 1;
    h[i] = k;

    while (i != 0 && h[pai(i)] < h[i]){
        swap(&h[i],&h[pai(i)]);
        i = pai(i);
    }
}

void maximizar(int i, int n, int h[tam]){

    int e = filho_esq(i);
    int d = filho_dir(i);
    int max = i;

    if (e < n && h[e] > h[max]){
        max = e;
    }
    if (d < n && h[d] > h[max]){
        max = d;
    }
    if (max != i){
        swap(&h[i],&h[max]);
        maximizar(max,n,h);
    }
}
