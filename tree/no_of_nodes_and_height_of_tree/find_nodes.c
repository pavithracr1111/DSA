#include "tree.h"

int count = 0;
int total_nodes(Tree_t *root)
{
    if(root != NULL)
    {
        total_nodes(root->left);
        count++;
        total_nodes(root->right);
    }
    return count;
}
