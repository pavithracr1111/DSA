#include "dll.h"

int dl_insert_before(Dlist **head, Dlist **tail, int gdata, int ndata) // function to insert before in DLL
{
    // checking if list is empty or not
    if (*head == NULL) // if list is empty
    {
        return FAILURE;
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

                new->prev = temp->prev; // update new node data, next link and prev link
                new->data = ndata;
                new->next = temp;

                if (temp->prev == NULL) // if temp is last node
                {
                    *head = new; // point head to new node
                }
                else
                {
                    temp->prev->next = new;
                }
                temp->prev = new;
                return SUCCESS;
            }
        }
        return FAILURE;
    }
}
