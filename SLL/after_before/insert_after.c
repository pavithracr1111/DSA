#include "sll.h"

int sl_insert_after(Slist **head, data_t g_data, data_t ndata) // function to insert after a given node
{

    if (head == NULL) // if list is empty
    {
        return LIST_EMPTY;
    }
    else //if list is non empty
    {
        Slist *temp = *head; // create a local reference pointer

        while (temp != NULL) //check for temp address
        {
            if (temp->data != g_data) //checking the given data is present in the node or not
            {
                temp = temp->link; // if the given data not present in the list, traverse the temp
            }
            else
            {
                Slist *new = malloc(sizeof(Slist)); // allocate memory for new node
                if (new == NULL) //do error check for memory allocated or not for new node
                {
                    return FAILURE; 
                }

                new->data = ndata; // update new data with the given data to add
                new->link = temp->link; //establish the link b/w new node and last node(update new link with the temp link to insert after)
                temp->link = new; // establish the link b/w prev and new (update temp link with the new add)
                return SUCCESS; //return success mess
            }
        }
        return DATA_NOT_FOUND; // if the given data not present in the list, return failure mess
    }
}
