#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int key;
    struct Node *left, *right;
}node;

node *NewNode(int key){
    node *tmp = (node*)malloc(sizeof(node));
    tmp->key = key;
    tmp->left = tmp->right = NULL;

    return tmp;
}

node *search(node *root, int key){
    if(root == NULL || root-> key == key) return root;

    if(root->key < key){
        return search(root->right, key);
    }

    return search(root->left, key);
}

node *searchDad(node *root, node *n){
    if(root == NULL || root == n) return NULL;

    if(root->left == n || root->right == n){
        return root;
    }

    if(root->key < n->key){
        return searchDad(root->right, n);
    }else{
        return searchDad(root->left, n);
    }
}

node *busca(node *root, int key){
    if(root == NULL || root->key == key) return root;

    while(root != NULL){
        if(root->key == key) return root;

        if(root->key < key){
            root = root->right;
        }else{
            root = root->left;
        }
    }

    return NULL;
}

node *buscaPai(node *root, node *n){
    if(root == NULL || root == n) return NULL;

    while(root != NULL){
        if(root->left == n || root->right == n){
            return root;
        }
        
        if(root->key < n->key){
            root = root->right;
        }else{
            root = root->left;
        }
    }

    return NULL;
}

node *insertion(node *node, int key){
    if(node == NULL) return NewNode(key);

    if(node->key == key) return node;

    if(node->key < key){
        node->right = insertion(node->right, key);
    }else{
        node->left = insertion(node->left, key);
    }

    return node;
}

node *inserir(node *root, int key){
    node *newnode = NewNode(key);
    
    if(root == NULL) return newnode;

    node *current = root;
    node *parent = NULL;

    while(current != NULL){
        parent = current;

        if(current->key == key){
            free(NewNode);
            return root;
        }

        if(current->key < key){
            current = current->right;
        }else{
            current = current->left;
        }
    }

    if(parent->key < key){
        parent->right = newnode;;
    }else{
        parent->left = newnode;
    }

    return root;
}