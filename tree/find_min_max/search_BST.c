#include "tree.h"

int search_BST(Tree_t *root, int data) 
{
    if (root == NULL) 
    {
        return FAILURE;
    }

    Tree_t *temp = root;

    while (temp != NULL)
    {
        if (temp->data == data)
        {
            return SUCCESS; // Element found
        }
        else if (temp->data > data)
        {
            temp = temp->left; // Search in the left subtree
        } 
        else
        {
            temp = temp->right; // Search in the right subtree
        }
    }

    return NOELEMENT; // Element not found
}
