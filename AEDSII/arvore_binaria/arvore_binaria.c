#include <stdio.h>
#include <stdlib.h>
#include "arvore_binaria.h"

// Função para criar um novo nó na árvore.
struct tree *novo_no(int item){
    struct tree* tmp = (struct tree*)malloc(sizeof(struct tree));
    tmp->valor = item;
    tmp->esq = tmp->dir = NULL;
    return tmp;
}

struct tree *inserir(struct tree *tree, int valor){
    // Se a árvore é vazia, cria um novo nó.
    if(tree == NULL){
        return novo_no(valor);
    }

    // Se o valor a inserir for menor que o valor do nó atual, chamamos a função recursivamente para inserir à esquerda; caso contrário, inserimos à direita.
    if(valor < tree->valor){
        tree->esq = inserir(tree->esq, valor);
    }else if(valor > tree->valor){
        tree->dir = inserir(tree->dir, valor);
    }

    // Retornamos um ponteiro para o nó que foi inserido.
    return tree;
}

struct tree *buscar(struct tree *root, int valor){
    // Se a árvore é vazia ou o valor está na raiz, retorna a raiz da árvore.
    if(root == NULL || root->valor == valor){
        return root;
    }

    // Caso o valor desejado seja maior do que a raiz, chama recursivamente a função de busca, tomando a direita do nó como ponto de partida.
    if(valor > root->valor){
        return buscar(root->dir, valor);
    }

    // Já se o valor desejado for menor do que a raiz, chama recursivamente a função de busca, tomando a esquerda do nó como ponto de partida.
    if(valor < root->valor){
        return buscar(root->esq, valor);
    }
}