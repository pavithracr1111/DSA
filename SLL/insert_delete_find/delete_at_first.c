#include "sll.h"

// function to delete at last
int delete_at_first(Slist **head, data_t data)
{
    // checking if list is empty or not
    if (*head == NULL) // if list is empty
    {
        return FAILURE;
    }
    else
    {
        Slist *temp = *head; // create a local reference pointer 
        *head=temp->link;
        free(temp);
        return SUCCESS;
    }
}