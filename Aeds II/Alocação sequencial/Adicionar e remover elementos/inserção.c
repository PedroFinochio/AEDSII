/*
função insere(no)
se n < m então
se busca(no.chave) = 0 então
L[n + 1] := no
n := n + 1
insere := n
senão insere := 0
senão insere := -1
*/

#include <stdio.h> 
#include <stdlib.h>

typedef struct no {
    int chave;
}no;

int busca_bin(no lista[], int x, int tam){

    int inf = 0, sup = tam - 1;

    while (inf <= sup){

        int meio = (inf + sup) / 2;

        if (lista[meio].chave == x){
            return meio;
        }else if (lista[meio].chave < x){
            inf = meio + 1;
        }else {
            sup = meio - 1;
        }
    }
    return - 1;
}

int insercao(no lista[], int tam, int tam_disp, no no_inserir){

    while (tam < tam_disp){
        if (busca_bin(lista, no_inserir.chave, tam) == -1){
            lista[tam].chave = no_inserir.chave;
            tam++;
            return tam;
        }else{
            return 0;
        }
    }
    return - 1;
}

int main (){

    no lista[7] = {{-2}, {0}, {1}, {2}, {5}, {9}}, valor_inserido;
    int valor, retorno, inserir, tam_vet = 6;;

    printf ("Digite um valor a ser buscado no vetor: ");
    scanf ("%d", &valor);

    retorno = busca_bin (lista, valor, tam_vet);

    if (retorno != -1){
        printf ("%d encontrado na posição %d.\n", valor, retorno);
    } else {
        printf ("Esse elemento não está presente no vetor.\n");
    }

    printf ("Digite um valor para ser inserido no vetor: ");
    scanf ("%d", &valor_inserido.chave);

    inserir = insercao (lista, tam_vet, 8, valor_inserido);

    if (inserir == 0){
        printf ("O elemento já está no vetor.\n");
    } else if (inserir == -1){
        printf ("O vetor está cheio.\n");
    } else {
        tam_vet = inserir;
        printf ("Elemento inserido no vetor.\n");
    }

    printf ("------Lista atualizada------\n");
    for (int i = 0; i < tam_vet; i++){
        printf ("%d ", lista[i].chave);
    }
    printf ("\n");

    return 0;

}