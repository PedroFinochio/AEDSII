#include <stdio.h>
#include <stdlib.h>
#include "arvore_binaria.h"

int main(){
    // Iniciando a raiz da árvore.
    struct tree *root = NULL;

    // Variáveis para utilização durante as operações na árvore.
    int op = 0, valor = 0;
    struct tree *res = NULL;
    printf("\n----------Árvore Binária de Busca----------");
    do{
        printf("\n1. Inserir");
        printf("\n2. Buscar");
        printf("\n3. Sair\n");
        printf("\nEscolha a opção desejada: ");
        scanf("%d", &op);

        switch(op){
            case 1:
            {
                printf("\nInsira o valor que você deseja inserir na árvore: ");
                scanf("%d", &valor);
                res = inserir(root,valor);
                if(res != NULL){
                    printf("\nValor inserido com sucesso!\n");
                }else{
                    printf("\nNão foi possível inserir o valor na árvore.\n");
                }
                root = inserir(root, valor);
                break;
            }
            case 2:
            {
                printf("\nInsira o valor que você deseja buscar na árvore: ");
                scanf("%d", &valor);
                res = buscar(root, valor);
                if(res != NULL){
                    printf("\nO valor encontrado é: %d\n", res->valor);
                }else if(res == NULL){
                    printf("\nO valor buscado não está presente na árvore.\n");
                }
                break;
            }
            case 3:
            {
                break;
            }
            default:
                printf("\nA opção escolhida não existe! Insira novamente: ");
                scanf("%d", &op);
                break;
        }
    }while(op != 3);

    return 0;
}