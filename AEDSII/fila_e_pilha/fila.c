#include <stdio.h>
#include <stdlib.h>

typedef struct Fila{
    int chave;
    int valor;
}fila;

int insere_fila(int x, fila F[],int M, int *f, int *r){
    int insere = -1, prov = (*r + 1) % M;
    if(prov != *f){
        *r = prov;
        F[*r].chave = x;
        F[*r].valor = x;
        insere = *r;
        if(*f == -1){
            (*f)++;
        }
    }
    return insere;
}

fila *remover(fila F[], int M, int *f, int *r){
    fila *removido = NULL;
    if(*f != -1){
        if(*f == *r){
            *f = *r = -1;
        }else{
            *f = (*f + 1) % M;
        }
        removido = &F[*f];
    }
    return removido;
}

void imprimir(fila F[], int *f, int *r){
    int i = *f;
    while(i <= *r){
        printf("\nChave: %d | Valor: %d ,",F[i].chave, F[i].valor);
        i++;
    }
    printf("\n\n");
}

int main(){
    int M = 10;
    fila F[M];
    int f = -1, r = -1;

    insere_fila(1,F,M,&f,&r);
    insere_fila(2,F,M,&f,&r);
    insere_fila(3,F,M,&f,&r);
    insere_fila(4,F,M,&f,&r);
    insere_fila(5,F,M,&f,&r);

    imprimir(F, &f, &r);

    remover(F,M,&f,&r);

    imprimir(F, &f, &r);

    remover(F,M,&f,&r);

    imprimir(F, &f, &r);


    return 0;
}