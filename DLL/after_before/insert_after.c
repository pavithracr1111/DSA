#include "dll.h"

int dl_insert_after(Dlist **head, Dlist **tail, int gdata, int ndata) // function to insert after in DLL
{
    // checking if list is empty or not
    if (*head == NULL) // if list is empty
    {
        return LIST_EMPTY;
    }
    else // if list is non empty
    {
        Dlist *temp = *head; // create a local reference pointer to traverse through the list to find given data
        
        while (temp != NULL) // run a loop till temp points to NULL
        {
            if (temp->data != gdata) // condition to check if the given data is not equal to temp data
            {
                temp = temp->next; // if not equal traverse to next node
            }
            else // if we found given data in the list, insert the new node after that node
            {
                Dlist *new = malloc(sizeof(Dlist)); // create a node
                if (new == NULL)                    // error checking (memory allocated or not)
                {
                    return FAILURE;
                }

                new->prev = temp; // update new node data and prev link
                new->data = ndata;
                
                if (temp->next == NULL) // if temp is last node
                {
                    new->next = NULL;
                    *tail = new;
                }
                else
                {
                    new->next = temp->next;
                    temp->next->prev = new;
                }
                temp->next = new;
                return SUCCESS;
            }
        }
        return DATA_NOT_FOUND;
    }
}