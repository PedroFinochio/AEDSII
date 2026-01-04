#include <stdio.h>
#include <stdlib.h>

typedef struct no_{
    int chave;
    int valor;
    struct no_ * prox;
    struct no_ * ant;
}no;

no * busca(int x, no *ptlista){

    no * ultimo = ptlista->ant;

    if (x <= ultimo->chave && ultimo != ptlista){

        no * pont = ptlista->prox;

        if (pont->chave < x){
            pont = pont->prox;
        }
        return pont;
    }
    return ptlista;
} 