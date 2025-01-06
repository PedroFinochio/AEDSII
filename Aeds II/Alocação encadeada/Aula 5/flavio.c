#include<stdio.h>
#include<stdlib.h>

typedef struct no_{
    int chave;
    int valor;
    struct no_ * prox;

} no;

void busca_enc(int x, no **ant, no **pont, no *ptlista){

    *ant = ptlista;
    *pont = NULL;
    no * ptr = ptlista->prox;

    while (ptr != NULL){
        if (ptr->chave < x){
        *ant = ptr;
        ptr = ptr->prox;
    }else if (ptr->chave == x){
        *pont = ptr;
    }
    ptr = NULL;
    }
}

int insere_enc (no * no_inserir, no *ptlista){

    no *ant;
    no *pont;
    busca_enc(no_inserir, &ant, &pont, ptlista);

    if (pont == NULL){
        no_inserir->prox = ant->prox;
        ant->prox = no_inserir;
        return 0;
    }
    return -1;
}

no * remove_enc(int x, no *ptlista){

    no *ant;
    no *pont;
    busca_enc(x, &ant, &pont, ptlista);

    if (pont != NULL){
        ant->prox = pont->prox;
        return pont;
    }

    return NULL;
}

int main(){
    // ptlista == p
    no * ptlista;
    ptlista = malloc(sizeof(no));
    ptlista->prox = NULL;

    // inserir == tmp1
    no * inserir = malloc(sizeof(no));
    inserir->chave = 1;
    inserir->valor = 1;
    inserir->prox = NULL;

    if(insere_enc(inserir, ptlista) == -1){
        printf("erro ao inserir\n");
    }else{
        printf("insercao realizada\n");
    }

    no* removido = remove_enc(2, ptlista);
    if(removido == NULL){
        printf("elemento nao encontrado\n");
    }else{
        printf("chave: %d | valor: %d\n",
        (*removido).chave, (*removido).valor );
    }


    removido = remove_enc(1, ptlista);
    if(removido == NULL){
        printf("elemento nao encontrado\n");
    }else{
        printf("chave: %d | valor: %d\n",
        (*removido).chave, (*removido).valor );
    }
    return 0;
}
