#include "tree.h"

int lc, rc;
int find_height(Tree_t *root)
{
    if(root == NULL)
    {
        return 0;
    }
    lc = find_height(root->left);
    rc = find_height(root->right);
    
    if(lc > rc)
    {
        return lc + 1;
    }
    else
    {
        return rc + 1;
    }
}
