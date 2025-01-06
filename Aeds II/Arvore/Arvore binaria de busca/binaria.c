#include <stdio.h>
#include <stdlib.h>

typedef struct noArvore_ {
    int valor;
    struct noArvore_ *esq;
    struct noArvore_ *dir;
}noArvore; 

noArvore *busca(noArvore *raiz, int k){

    if (raiz == NULL || raiz->valor == k){
        return raiz;
    }

    if (raiz->valor > k){
        return busca(raiz->dir,k);
    }else{
        return busca(raiz->esq,k);
    }
}

noArvore *buscaPai(noArvore *raiz, noArvore *n){

    if (raiz == NULL || raiz == n){
        return NULL;
    }

    if (raiz->esq == n || raiz->dir == n){
        return raiz;
    }
    if (raiz->valor > n->valor){
        return buscaPai(raiz->esq,n);
    }else{
        return buscaPai(raiz->dir,n);
    }
}

noArvore *insere(noArvore *raiz, noArvore *n){

    if (raiz == NULL){
        return n;
    }

    if (raiz->valor > n->valor){
        raiz->esq = insere(raiz->esq,n);
    }else{
        raiz->dir = insere(raiz->dir,n);
    }
    return raiz;
}

noArvore *removeRaiz(noArvore *raiz){

    noArvore *p,*q;

    if (raiz->esq == NULL){
        q = raiz->dir;
        free(raiz);
        return q;
    }

    p = raiz;
    q = raiz->esq;

    while (q->dir != NULL){
        p = q;
        q = q->dir;
    }

    if (p != raiz){
        p->dir = q->esq;
        q->esq = raiz->esq;
    }

    q->dir = raiz->dir;
    free(raiz);
    return q;
}

noArvore *remove_no(noArvore *raiz, int valor){

    noArvore *n = busca(raiz, valor);

    if (n != NULL){
        noArvore *pai = buscaPai(raiz,n);
        if (pai != NULL){
            if (pai->esq == n){
                pai->esq = removeRaiz(n);
            }else{
                pai->dir = removeRaiz(n);
            }
        }else{
            raiz = removeRaiz(n);
        }
    }
    return raiz;
}


//////////////////////////INTERATIVAS/////////////////////////

noArvore *busca_interativa(noArvore *raiz, int k){

    while (raiz != NULL && raiz->valor != k){
        if (raiz->valor > k){
            raiz = raiz->esq;
        }else{
            raiz = raiz->dir;
        }
    }
    return raiz;
}

noArvore *buscaPai_interativa(noArvore *raiz, noArvore *n){

    while (raiz != NULL){
        if (raiz->esq == n || raiz->dir == n){
            return raiz;
        }
        if (raiz->valor > n->valor){
            raiz = raiz->esq;
        }else{
            raiz = raiz->dir;
        }
    }
    return NULL;
}

noArvore *insere_interativa(noArvore *raiz, noArvore *n){

    noArvore *atual = raiz, *anterior = NULL;

    while (atual != NULL){
        anterior = atual;
        if (n->valor > atual->valor){
            atual = atual->dir;
        }else{
            atual = atual->esq;
        }
    }

    if (anterior == NULL){
        raiz = n;
    }else if (n->valor > anterior->valor){
        anterior->dir = n;
    }else{
        anterior->esq = n;
    }
    return raiz;
}



