#include "tree.h"

int findmin(Tree_t * root)
{
    if(root == NULL)
    {
        return FAILURE;
    }
    if(root -> left == NULL)
    {
        return root->data;
    }
    Tree_t *temp = root;
    Tree_t *prev;
    while(temp != NULL)
    {
        prev = temp;
        temp = temp -> left;
    }
    return prev -> data;
}
