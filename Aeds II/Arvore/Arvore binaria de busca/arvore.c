#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} node;

node *insert(node *root, int data)
{
    node *temp = (node *)malloc(sizeof(node));

    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;

    if (root == NULL)
    {
        root = temp;
    }
    else
    {
        node *current = root;
        node *parent = NULL;

        while (1)
        {
            parent = current;
            if (data < parent->data)
            {
                current = current->left;

                if (current == NULL)
                {
                    parent->left = temp;
                    return root;
                }
            }
            else
            {
                current = current->right;

                if (current == NULL)
                {
                    parent->right = temp;
                    return root;
                }
            }
        }
    }
    return root;
}

void inorder_traversal(node *root)
{
    if (root)
    {
        inorder_traversal(root->left);
        printf("%d ", root->data);
        inorder_traversal(root->right);
    }
}

node *search(node *root, int data)
{
    node *current = root;
    printf("Visiting elements: ");

    while (current)
    {
        printf("%d ", current->data);

        if (data < current->data)
        {
            current = current->left;
        }
        else if (data > current->data)
        {
            current = current->right;
        }
        else
        {
            return current;
        }
    }

    return NULL;
}

node *searchParent(node *root, node *n)
{

    if (root == NULL || root == n)
    {
        return NULL;
    }

    if (root->left == n || root->right == n)
    {
        return root;
    }

    if (n->data > root->data)
    {
        return searchParent(root->right, n);
    }
    else
    {
        return searchParent(root->left, n);
    }
}

node *removeRoot(node *root)
{
    node *p, *q;

    if (root->left == NULL)
    {
        q = root->right;
        free(root);
        return q;
    }

    p = root;
    q = root->left;

    while (q->right != NULL)
    {
        p = q;
        q = q->right;
    }

    if (p != root)
    {
        p->right = q->left;
        q->left = root->left;
    }

    q->right = root->right;
    free(root);
    return q;
}

node *remove_function(node *root, int data)
{

    node *n = search(root, data);

    if (n == NULL)
    {
        printf("\n[x] (%d) Not found.\n", data);
        return root;
    }

    node *parent = searchParent(root, n);

    if (parent)
    {
        if (parent->right == n)
        {
            parent->right = removeRoot(n);
        }
        else
        {
            parent->left = removeRoot(n);
        }
    }
    else
    {
        root = removeRoot(n);
    }

    printf("\n[%d] Removed.\n", data);
    return root;
}

int main()
{
    int i;
    int array[14] = {34, 84, 15, 0, 2, 99, 79, 9, 88, 89, 18, 31, 39, 100};

    node *root = NULL;

    for (i = 0; i < 14; i++)
    {
        root = insert(root, array[i]);
        printf("Inserted: %d\n", array[i]);
    }

    printf("\nInorder traversal: ");
    inorder_traversal(root);
    printf("\n");

    int search_value = 88;
    node *temp = search(root, search_value);
    if (temp)
    {
        printf("\n[%d] Found.\n", temp->data);
    }
    else
    {
        printf("\n[x] (%d) Not found.\n", search_value);
    }

    int remove_value = 99;
    root = remove_function(root, remove_value);
    printf("\n[%d] Removed.\n", remove_value);

    remove_value = 77;
    root = remove_function(root, remove_value);

    printf("\nInorder traversal after removal: ");
    inorder_traversal(root);
    printf("\n");

    return 0;
}
