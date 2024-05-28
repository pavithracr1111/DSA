#include "tree.h"

int findmax(Tree_t * root)
{
    if(root == NULL)
    {
        return FAILURE;
    }
    if(root -> right == NULL)
    {
        return root->data;
    }
    Tree_t *temp = root;
    Tree_t *prev;
    while(temp != NULL)
    {
        prev = temp;
        temp = temp -> right;
    }
    return prev -> data;
}
