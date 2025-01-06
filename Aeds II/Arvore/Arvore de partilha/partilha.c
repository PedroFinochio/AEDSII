#include<stdio.h>
#include<stdlib.h>
#define TAM 15

//nó do vetor, possui campos para valor e frequência
typedef struct nov_{
    int valor;
    int freq;
}nov;

//nó da árvore, possui campos para valor, partilha e os dois ponteiros
typedef struct noa_{
    int valor;
    int partilha;
    struct noa_ *esq, *dir;
}noa;

//constroi a árvore a partir de um vetor ordenado com campos de valor e frequência
noa* construcao(nov v[], int inf, int sup){
    
    noa* raiz = malloc(sizeof(noa)); //espaço é reservado para a raiz da árvore/subárvore 

    if(inf != sup){
        int max = inf;

        for(int i = inf; i <= sup; i++){
            if(v[max].freq < v[i].freq){
                max = i;
            }
        }

        raiz->valor = v[max].valor;

        for(int i = max; i < sup; i++){
            v[i] =  v[i+1];
        }
        sup--;

        int meio = (inf + sup) % 2;

        raiz->partilha = v[meio].valor;

        raiz->esq = construcao(v,inf,meio);
        raiz->dir = construcao(v,meio, sup);

    }else{ // inserir somente um número.
        raiz->valor = v[inf].valor;
        raiz->partilha = -1;
        raiz->esq = raiz->dir = NULL;
    }

    return raiz;
}

//printa a árvore com "formato" de árvore, usado para debugar
void printa(noa *raiz, int altura) {
    if (!raiz)
        return;

    printa(raiz->dir, altura + 1);

    for (int i = 0; i < altura; i++)
        printf("   ");

    printf( "%d|%d\n", raiz->valor, raiz->partilha);

    printa(raiz->esq, altura + 1);
}

int main(){

    // nov vet[TAM] = {
    //     {32,12},{33,4},{34,10},{36,11},{38,7},{40,9},{55,8},{60,15},{61,14},{65,1},{68,5},{72,6},{74,2},{91,3},{97,13}
    // };
    
    nov vet[TAM] = {
        {33,11},{38,15},{42,8},{45,10},{48,7},{49,14},{50,6},{57,12},{60,5},{64,1},{73,13},{83,3},{84,4},{85,9},{95,2}
    };

    noa *raiz = construcao(vet, 0, TAM-1);

    printa(raiz, 0);

    return 0;
}