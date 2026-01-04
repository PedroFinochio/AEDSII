// Se biblioteca indefinida
#ifndef BSTREE_H

// Defina
#define BSTREE_H

// Struct para representar a árvore
struct tree{
    int valor;
    struct tree *esq, *dir;
};

// Chamada de todas as funções definidas
struct tree *novo_no(int item);
struct tree *inserir(struct tree *tree, int valor);
struct tree *buscar(struct tree *root, int valor);

// Fim da Definição
#endif