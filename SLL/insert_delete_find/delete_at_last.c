#include "sll.h"

// function to delete at last
int delete_at_last(Slist **head, data_t data)
{
    // checking if list is empty or not
    if (*head == NULL) // if list is empty
    {
        return FAILURE;
    }
    else if ((*head)->link == NULL)
    {
        free(head);   // after deallocating also head has first node address
        *head = NULL; // so make head to null
        return SUCCESS;
    }
    else
    {
        Slist *temp = *head; // create a local reference pointer to traverse through the list till end
        Slist *prev = NULL;  // create a previous pointer so that we can store previous node/ before node address
        while (temp->link != NULL)
        {
            prev = temp; // before traversing store temp address to prev
            temp = temp->link;
        }
        prev->link = NULL;
        free(temp);
        return SUCCESS;
    }
}