#include <stdio.h>
#include <stdlib.h>

struct Node{
    int key;
    struct Node *left, *right;
}*root;

struct Node *newNode(int key){
    struct Node *tmp = (struct Node*)malloc(sizeof(struct Node));
    tmp->key = key;
    tmp->left = tmp->right = NULL;

    return tmp;
}

struct Node *insert(struct Node *node, int key){
    if(node == NULL) return newNode(key);

    if(node->key == key) return node;

    if(node->key < key){
        node->right = insert(node->right, key);
    }else{
        node->left = insert(node->left, key);
    }

    return node;
}

struct Node *search(struct Node *root, int key){
    if(root == NULL || root->key == key) return root;

    if(root->key < key){
        return search(root->right, key);
    }

    return search(root->left, key);
}

struct Node *searchDad(struct Node *node, struct Node *n){
    if(node == NULL||node == n) return NULL;
    
    if(node->right == n|| node->left == n){
        return node;
    }

    if(node->key < n->key){
        return searchDad(node->right, n);
    }else{
        return searchDad(node->left, n);
    }
}

struct Node *get_Predecessor(struct Node *node){
    node = node->left;
    while(node->right != NULL){
        node = node->right;
    }

    return node;
}

struct Node *removeRaiz(struct Node *raiz)
{
    struct Node *p, *q;

    if (raiz->left == NULL)
    {
        q = raiz->right;
        free(raiz);
        return (q);
    }

    p = raiz;
    q = raiz->left;

    while (q->right != NULL)
    {
        p = q;
        q = q->right;
    }
    // repare que q Ã© o nÃ³ anterior a r
    // na ordem e-r-d
    // enquanto que p Ã© o pai de q
    if (p != raiz)
    {
        p->right = q->left;
        q->left = raiz->left;
    }
    q->right = raiz->right;
    free(raiz);
    return;
}

struct Node *removeNo(struct Node *raiz, int valor)
{
    struct Node *n = busca(raiz, valor);

    if (n != NULL)
    {
        struct Node *pai = buscaPai(raiz, n);
        if (pai != NULL)
        {
            if (pai->right == n)
            {
                pai->right = removeRaiz(n);
            }
            else
            {
                pai->left = removeRaiz(n);
            }
        }
        else
        {
            raiz = removeRaiz(n);
        }
    }
    return raiz;
}

struct Node *in_order(struct Node *tmp){
    if(tmp == NULL){
        return;
    }

    // "Esquerda"
    in_order(tmp->left);

    // "Leia"
    printf("%d", tmp->key);
    
    // "Direita"
    in_order(tmp->right);
}

struct Node *pre_order(struct Node *tmp){
    if(tmp == NULL){
        return;
    }

    // "Leia"
    printf("%d", tmp->key);

    // "Esquerda"
    in_order(tmp->left);

    // "Direita"
    in_order(tmp->right);
}

struct Node *after_order(struct Node *tmp){
    if(tmp == NULL){
        return;
    }

    // "Esquerda"
    in_order(tmp->left);

    // "Direita"
    in_order(tmp->right);

    // "Leia"
    printf("%d", tmp->key);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////INTERATIVAS//////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
struct Node *busca(struct Node *raiz, int k){
    if(raiz == NULL || raiz->key == k) return raiz;

    while(raiz != NULL && raiz->key != k){
        if(raiz->key < k){
            raiz = raiz->right;
        }else{
            raiz = raiz->left;
        }
    }

    return raiz;
}

struct Node *buscaPai(struct Node *raiz, struct Node *n){
    while(raiz != NULL){
        if(raiz->left == n || raiz->right == n) return raiz;

        if(raiz->key < n->key){
            raiz = raiz->right;
        }else{
            raiz = raiz->left;
        }
    }

    return NULL;
}

void main(){

}