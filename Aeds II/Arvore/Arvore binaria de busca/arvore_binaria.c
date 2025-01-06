#include <stdio.h>
#include <stdlib.h>

typedef struct noArvore_{
    int valor;
    struct noArvore_ *esq;
    struct noArvore_ *dir;
}noArvore;

noArvore *busca (noArvore *raiz, int k){// ponteiro raiz e valor buscado
    
    if (raiz == NULL || raiz->valor == k){
        return raiz;
    }

    if (k > raiz->valor){
        return busca (raiz->dir, k);
    }else {
        return busca (raiz->esq, k);
    }
}

/*
Versão interativa da busca:

noArvore *busca(noArvore *raiz, int k){

    while (raiz != NULL && raiz->valor != k){
        if(k > raiz->valor){
            raiz = raiz->dir;
        }else {
            raiz = raiz->esq;
        }
    }
    return raiz;
}
*/

noArvore *buscaPai(noArvore *raiz, noArvore *n){
    if (raiz == NULL || raiz == n){// caso o nó seja a raiz
        return NULL;
    }

    if (raiz->esq == n || raiz->dir == n){// caso o nó seja filho de algum outro nó
        return raiz;
    }if (n->valor > raiz->valor){
        return buscaPai(raiz->dir, n);
    }else {
        return buscaPai(raiz->esq, n);
    }
}

/*
Versão interativa da buscaPai:

noArvore *buscaPai(noArvore *raiz, noArvore *n){

    while (raiz != NULL){
        if (raiz->esq == n || raiz->dir == n){
            return raiz;
        }
        if (n->valor > raiz->valor){
            raiz = raiz->dir;
        }else {
            raiz = raiz->esq;
        }
    }
    return NULL;
}
*/

noArvore *insere(noArvore *raiz, noArvore *n){// ponteiro raiz da árvore ou subárvore e ponteiro que contém o endereço do nó inserido

    if (raiz == NULL){
        return n;
    }

    if (n->valor > raiz->valor){
        raiz->dir = insere(raiz->dir, n);
    }else{
        raiz->esq = insere(raiz->esq, n);
    }
    return raiz;
}

/*
Versão interativa da inserção:

noArvore *insere(noArvore *raiz, noArvore *n){

    noArvore *atual = raiz;
    noArvore *anterior = NULL;

    while (atual != NULL){
        anterior = atual;
        if (n->valor > atual->valor){
            atual = atual->dir;
        }else {
            atual = atual->esq;
        }
    }

    if (anterior == NULL){
        raiz = n;
    }else if (n->valor > anterior->valor){
        anterior->dir = n;
    }else {
        anterior->esq = n;
    }
    return raiz;
    
}
*/

noArvore *removeRaiz(noArvore *raiz){

    noArvore *p, *q;

    if (raiz->esq == NULL){// se a raiz não possui subárvore na esquerda
        q = raiz->dir;// subárvore direita sera a nova raiz
        free(raiz);
        return q;
    }

    p = raiz;
    q = raiz->esq;

    while (q->dir != NULL){//loop para encontrar o nó mais a direita da subárvore esquerda 
        p = q;
        q = q->dir;
    }

    if (p != raiz){// se p não for a raiz, q não é filho direito da raiz 
        p->dir = q->esq;
        q->esq = raiz->esq;
    }

    q->dir = raiz->dir;
    free(raiz);
    return q;
}

noArvore *removeNo(noArvore *raiz, int valor)
{
    noArvore *n = busca(raiz, valor);

    if (n != NULL)
    {
        noArvore *pai = buscaPai(raiz, n);
        if (pai != NULL)
        {
            if (pai->dir == n)
            {
                pai->dir = removeRaiz(n);
            }
            else
            {
                pai->esq = removeRaiz(n);
            }
        }
        else
        {
            raiz = removeRaiz(n);
        }
    }
    return raiz;
}

void em_ordem(noArvore *n){
    if (n == NULL){// caso n == NULL, este é o fim da árvore/subárvore 
        return;
    }

    em_ordem(n->esq);// percorre a subárvore esquerda

    printf ("%d ", n->valor);// visita o nó

    em_ordem(n->dir);// percorre a subárvore direita
}

void pre_ordem(noArvore *n){
    if (n == NULL){// caso n == NULL, este é o fim da árvore/subárvore 
        return;
    }
    printf ("%d ", n->valor);// visita o nó

    pre_ordem(n->esq);// perocorre a subárvore esquerda 

    pre_ordem(n->dir);// percorre a subárvore direita
}

void pos_ordem(noArvore *n){
    if (n == NULL){// caso n == NULL, este é o fim da árvore/subárvore 
        return;
    }

        pos_ordem(n->esq);// perocorre a subárvore esquerda 
        
        pos_ordem(n->dir);// percorre a subárvore direita

        printf ("%d ", n->valor);// visita o nó 
}

int main() {
    noArvore *raiz = NULL;
    noArvore *novo;

    int valores[] = {16, 1, 92, 36, 69, 0, 66, 59, 5, 63, 61, 21, 49, 7, 33, 23};
    for (int i = 0; i < 16; i++) {
        novo = (noArvore *)malloc(sizeof(noArvore));
        novo->valor = valores[i];
        novo->esq = NULL;
        novo->dir = NULL;
        raiz = insere(raiz, novo);
    }

    printf("Árvore em ordem: ");
    em_ordem(raiz);
    printf("\n");

    printf ("Árvore em pré-ordem: ");
    pre_ordem(raiz);
    printf("\n");

    printf ("Árvore em pós-ordem: ");
    pos_ordem(raiz);
    printf("\n");

    int valorBusca = 40;
    noArvore *resultadoBusca = busca(raiz, valorBusca);
    if (resultadoBusca != NULL) {
        printf("Valor %d encontrado na árvore.\n", valorBusca);
    } else {
        printf("Valor %d não encontrado na árvore.\n", valorBusca);
    }

    int valorRemover = 70;
    raiz = removeNo(raiz, valorRemover);
    printf("Árvore após remover o valor %d: ", valorRemover);
    em_ordem(raiz);
    printf("\n");

    while (raiz != NULL) {
        raiz = removeNo(raiz, raiz->valor);
    }

    return 0;
}






