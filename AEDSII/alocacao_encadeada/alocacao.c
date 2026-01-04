#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node
{
    int valor;
    int chave;
    struct node *next;
} *p, *tmp, *tmp1;

void add_inicio(int elemento)
{

    tmp = p;

    tmp1 = (struct node *)malloc(sizeof(struct node));

    tmp1->valor = elemento;

    tmp1->next = p;

    p = tmp1;
}

void add_fim(int elemento)
{

    tmp = p;

    tmp1 = (struct node *)malloc(sizeof(struct node));

    tmp1->valor = elemento;

    tmp1->next = NULL;

    if (p == NULL)
    {

        p = tmp1;
    }
    else
    {

        while (tmp->next != NULL)
        {

            tmp = tmp->next;
        }
        tmp->next = tmp1;
    }
}

void remover(int elemento){

    tmp = p;

    struct node *retaguarda = tmp;

    if (p != NULL){

        if (tmp->valor == elemento){
            if (tmp == p){
                p = tmp->next;
                free(tmp);
                return;
            }else{
                retaguarda->next = tmp->next;
                free(tmp);
                return;
            }
        }else {
            tmp = tmp->next;
            retaguarda = tmp;
        }
    }
    printf ("Elemento não encontrado");
}

void imprimir (){

    tmp = p;

    while (tmp != NULL){
        printf ("%d ", tmp->valor);
        tmp = tmp->next;
    }
}

void main(){
    p = NULL;
    int val, opcao = 0;

    do{
        printf("\n**********MENU**********");
        printf("\n1. Adicionar no Início");
        printf("\n2. Adicionar no Fim");
        printf("\n3. Imprimir Lista");
        printf("\n4. Apagar Elemento\n");
        printf("\n5. Sair\n");
        printf("\nEscolha a Opção desejada: ");
        scanf("%d", &opcao);

        switch(opcao){
            case 1:
                printf("\nInsira o elemento que você deseja adicionar a lista: ");
                scanf("%d", &val);
                add_inicio(val);
                break;
            case 2:
                printf("\nInsira o elemento que você deseja adicionar a lista: ");
                scanf("%d", &val);
                add_fim(val);
                break;
            case 3:
                imprimir();
                break;
            case 4:
                printf("\nInsira o elemento que você deseja remover da lista: ");
                scanf("%d", &val);
                remover(val);
                break;
            case 5:
                break;
            default:
                printf("\nOpção Inválida! Insira novamente: ");
                scanf("%d", &opcao);
        }

    }while(opcao != 5);
}