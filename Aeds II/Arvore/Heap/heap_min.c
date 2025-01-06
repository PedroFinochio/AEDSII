/*
Árvore heap é uma árvore binária, mas não é uma árvore binária de busca
A raiz será sempre o menor ou o maior valor da árvore
Inserções são sempre feitas no final da árvore
Se um novo nó for menor do que seu pai, troca-se pai e filho de lugar
Remoções são sempre feitas na raiz (último elemento inserido vai temporariamente para o lugar da raiz)
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int tam = 1000;

int pai(int i)
{
    return (i - 1) / 2; // posição do pai do nó = i-1 / 2
}

int filho_esq(int i)
{
    return (2 * i) + 1; // posição do filho esquerdo do nó = 2*i+ 1
}

int filho_dir(int i)
{
    return (2 * i) + 2; // posição do filho direito do nó = 2*i + 2
}

// troca filho e pai de lugar
void swap(int *filho, int *pai)
{
    int tmp = *filho;
    *filho = *pai;
    *pai = tmp;
}

void insere(int *n, int h[tam], int k)// n = ponteiro que aponta para a última posição ocupada da árvore, h = heap e k = valor
{ 

    if (*n == tam)
    { // verifica se há espaço na árvore, h[n] é uma posição inválida
        printf("Overflow, não foi possível inserir o valor.\n");
        return;
    }

    (*n)++; // acrescenta uma posição para a inserção
    int i = (*n) - 1; // i = posição onde ocorre a inserção, que é a última
    h[i] = k; // novo nó vai para a última posição da árvore

    while (i != 0 && h[pai(i)] > h[i])// enquanto não chegar na raiz e o pai do nó for maior que um de seus filhos
    {                            
        swap(&h[i], &h[pai(i)]); // troca pai e filho de lugar
        i = pai(i);              // pai vai para a última posição da árvore
    }
}

// função para garantir que a raiz seja o valor mínimo da heap
void minimizar(int i, int n, int h[tam])
{
    int e = filho_esq(i); // guarda posição do filho esquerdo de i.
    int d = filho_dir(i); // guarda posição do filho direito de i.
    int min = i;          // o valor minimo é iniciado como i, ele será comparado com seus filhos.

    if (e < n && h[e] < h[min])
        min = e; // o minimo é o esquerdo.
    if (d < n && h[d] < h[min])
        min = d;  // o minimo é o direito.
    if (min != i) // se algum filho tiver sido menor que o pai(quebrando a propiedade de min-heap).
    {
        swap(&h[i], &h[min]); // troca o pai com minimo.
        minimizar(min, n, h); // chama a função de minimização com o pai(agora filho).
    }
}

int remove_raiz(int *n, int h[tam])
{

    if (*n <= 0)// se a heap estiver vazia, retorna o valor máximo de int 
    {
        return INT_MAX;

        if (*n == 1)// se a heap tiver só um elemento, a última posição é decrementada e retorna o único elemento
        {
            (*n)--;
            return h[0];
        }
    }

    int raiz = h[0];
    h[0] = h[(*n) - 1];//o último elemento do vetor irá para a raiz 
    (*n)--;// diminui 1 posição do vetor 
    minimizar(0, *n, h);
    return raiz;
}

void imprimeheap(int n, int h[tam])
{
    printf("Heap atual: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", h[i]);
    }
    printf("\n");
}

int main()
{
    int h[tam];
    int n = 0; // Tamanho atual do heap
    int opcao, valor;

    while (1)
    {
        printf("\nEscolha uma opcao:\n");
        printf("1 - Adicionar elemento\n");
        printf("2 - Remover elemento minimo\n");
        printf("3 - Sair e mostrar a arvore heap\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            printf("Digite o valor a ser inserido: ");
            scanf("%d", &valor);
            insere(&n, h, valor);
            break;
        case 2:
            valor = remove_raiz(&n, h);
            if (valor == INT_MAX)
            {
                printf("Heap esta vazio.\n");
            }
            else
            {
                printf("Elemento removido: %d\n", valor);
            }
            break;
        case 3:
            printf("Saindo...\n");
            imprimeheap(n, h);
            return 0;
        default:
            printf("Opção invalida. Tente novamente.\n");
        }
    }
    return 0;
}

// i -> índice do valor, n -> último índice de valores, h-> vetor completo.
int minimizer(int i, int n, int h[tam]){

    int e = filho_esq(i);
    int d = filho_dir(i);

    int min = i;

    if(e < n && h[e] < h[min]){
        min = e;
    }

    if(d < n && h[d] < h[min]){
        min = d;
    }

    if(min != i){
        swap(&h[min], &h[i]);
        minimizer(h[min], n, h[tam]);
    }    
}