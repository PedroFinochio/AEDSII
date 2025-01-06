#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
    int chave;
    int valor;
} no;

int insere_fila(no d, int *r, int *f, int tam, no F[]){

    int prov = (*r + 1) % tam;

    if (prov != *f){
        *r = prov;
        F[*r].chave = d.chave;
        F[*r].valor = d.valor;

        if (*f == - 1){
            *f = *r;
        }
        return 1;
    }  
    return -1;
}   

int remove_fila(int *r, int *f, int tam, no F[]){

    if (*f == -1){
        return - 1;
    }

    int removido = F[*f].chave;

    if (*f == *r){
        *f = *r = -1;
    }else {
        *f = (*f + 1) % tam;
    }
    return removido;
}

void imprime_fila(int r, int f, int tam, no F[])
{
    if (f == -1)
    {
        printf("Fila vazia.\n");
        return;
    }

    printf("Elementos da fila: ");
    int i = f;
    do
    {
        printf("[Chave: %d, Valor: %d] ", F[i].chave, F[i].valor);
        i = (i + 1) % tam;
    } while (i != (r + 1) % tam);

    printf("\n");
}

int main()
{
    int tam = 10;
    no fila[tam], valor;
    int opcao, r = -1, f = -1, retorno, valor_remover;

    do
    {
        printf("\n======Menu de opções======\n");
        printf("1. Imprimir a fila\n");
        printf("2. Inserir um valor na fila\n");
        printf("3. Remover um elemento da fila\n");
        printf("0. Sair\n");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            imprime_fila(r, f, tam, fila);
            break;

        case 2:
            printf("Digite a chave e o valor para inserir na fila: ");
            scanf("%d %d", &valor.chave, &valor.valor);
            retorno = insere_fila(valor, &r, &f, tam, fila);
            if (retorno == -1)
            {
                printf("Fila cheia\n");
            }
            else
            {
                printf("Elemento inserido\n");
            }
            break;

        case 3:
            valor_remover = remove_fila(&r, &f, tam, fila);
            if (valor_remover != -1)
            {
                printf("Elemento removido: %d\n", valor_remover);
            }
            else
            {
                printf("Fila vazia\n");
            }
            break;

        case 0:
            printf("Saindo...\n");
            break;

        default:
            printf("Opção inválida\n");
            break;
        }

    } while (opcao != 0);

    return 0;
}
