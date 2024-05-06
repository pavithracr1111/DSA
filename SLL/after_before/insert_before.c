#include "sll.h"

int sl_insert_before(Slist **head, data_t g_data, data_t ndata) // function to insert before a given node
{
    if (head == NULL) // if list is empty
    {
        return LIST_EMPTY;
    }
    else
    {
        Slist *temp = *head; // create a local reference pointer
        Slist *prev = NULL;  // create a another local pointer to store previous address

        while (temp != NULL)
        {
            if (temp->data != g_data) // checking the given data is present in the node or not
            {
                prev = temp;       // store temp address before traversing in prev pointer
                temp = temp->link; // if the given data not present in the list, traverse the temp
            }

            else
            {
                Slist *new = malloc(sizeof(Slist)); // allocate memory for new node
                if (new == NULL)                    // do error check for memory allocated or not for new node
                {
                    return FAILURE;
                }

                new->data = ndata;      // update new data with the given data to add
                new->link = prev->link; // establish the link b/w new node and previous node(update new link with the prev link to insert before)
                prev->link = new;       // establish the link b/w prev and new (update prev link with the new add)
                return SUCCESS;
            }
        }
        return DATA_NOT_FOUND; // if the given data not present in the list, return failure mess
    }
}