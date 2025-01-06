#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
    int chave;
    int valor;
} no;

int topo = 9;  // indica o último elemento válido da pilha
int p[12] = {0, 5, 7, 9, 10, 14, 60, 90, 100, 120};
int tam_pilha = 12;

int insere(int valor)
{
    if (topo < tam_pilha - 1)  // Verifica se ainda há espaço na pilha
    {
        topo++;
        p[topo] = valor;
        return topo;
    }
    return -1;  // Retorna -1 se a pilha estiver cheia
}

int remover()
{
    if (topo >= 0)  // Verifica se há elementos na pilha para remover
    {
        int removido = p[topo];
        topo--;
        return removido;
    }
    return -1;  // Retorna -1 se a pilha estiver vazia
}

int main()
{
    int valor, retorno, retorno2, opcao;

    printf("\n======Pilha atual======\n");
    for (int i = 0; i <= topo; i++)
    {
        printf("-");
        printf("|%d|", p[i]);
        printf("-");
    }
    printf ("\n");

    do
    {
        printf("\nMenu de opções:\n");
        printf("1. Inserir um valor na pilha\n");
        printf("2. Remover um valor da pilha\n");
        printf("0. Sair\n");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            printf("Digite um valor para inserir na pilha: ");
            scanf("%d", &valor);
            retorno = insere(valor);

            if (retorno == -1)
            {
                printf("Pilha cheia\n");
            }
            else
            {
                printf("Elemento inserido na pilha\n");
                printf("\n======Pilha atualizada======\n");
                for (int i = 0; i <= topo; i++)
                {
                    printf("-");
                    printf("|%d|", p[i]);
                    printf("-");
                }
            }
            break;

        case 2:
            retorno2 = remover();

            if (retorno2 == -1)
            {
                printf("Não foi possível remover o último elemento\n");
            }
            else
            {
                printf("Elemento removido com sucesso\n");
                printf("\n======Pilha atualizada======\n");
                for (int i = 0; i <= topo; i++)
                {
                    printf("-");
                    printf("|%d|", p[i]);
                    printf("-");
                }
            }
            break;

        case 0:
            printf("Programa encerrado\n");
            break;

        default:
            printf("Opção inválida\n");
            break;
        }

    } while (opcao != 0);

    return 0;
}
