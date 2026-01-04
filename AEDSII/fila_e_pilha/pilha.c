#include <stdio.h>
#include <stdlib.h>

typedef struct Pilha{
    int chave;
    int valor;
}pilha;

void inserir(int x, int *topo, int TAM, pilha P[] ){
    if(*topo <= TAM - 1){
        (*topo)++;
        P[*topo].chave = x;
        P[*topo].valor = x;
    }
}

pilha *remover(pilha P[], int *topo, int TAM){
    pilha *removido = NULL;
    if(*topo > -1){
        removido = &P[*topo];
        (*topo)--;
    }
    return removido;
}

int busca_bin(int x, pilha P[], int TAM, int *topo){
    int inf = 0, sup = *topo;
    while(inf <= sup){
        int meio = (int)(inf + sup) / 2;
        if(P[meio].chave == x){
            return meio;
        }else if(P[meio].chave > x){
            inf = meio -1;
        }else{
            sup = meio + 1;
        }
    }
    return -1;
}

void imprimir(int *topo, int TAM, pilha P[]){
    int i = *topo;
    while(i > -1){
        printf("\n Chave: %d | Valor: %d", P[i].chave, P[i].valor);
        i--;
    }
}

int main(){
    int TAM = 10;
    pilha P[TAM];
    int topo = -1;

    int op = 0, x = 0;
    do{
        printf("\n**************MENU**************\n");
        printf("\n1. Inserir na Pilha");
        printf("\n2. Remover da Pilha");
        printf("\n3. Buscar na Pilha");
        printf("\n4. Imprimir Pilha");
        printf("\n5. Sair\n");
        printf("\nEscolha a opção desejada: ");
        scanf("%d", &op);

        switch(op){
            case 1:
                printf("\nDigite o número que você deseja adicionar na pilha: ");
                scanf("%d", &x);
                inserir(x, &topo, TAM, P);
                break;
            case 2:
                remover(P,&topo,TAM);
                break;
            case 3:
                printf("\nDigite o número que você deseja buscar na pilha: ");
                scanf("%d", &x);
                int res = busca_bin(x,P,TAM,&topo);
                printf("\nO número encontrado foi-> Chave: %d | Valor: %d\n", P[res].chave, P[res].valor);
                break;
            case 4:
                imprimir(&topo,TAM,P);
                break;
            case 5:
                break;
            default:
                printf("\nOpção Inválida! Digite novamente: ");
                scanf("%d", &op);
        }
    }while (op != 5);
    

    return 0;
}